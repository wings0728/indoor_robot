#include "T3Voice.hpp"
#include <QDateTime>
#include <QFile>
#include <QTimer>
#include "../config/config.hpp"
#include "stdio.h"

T3Voice::T3Voice()
{
    /* 默认wav音频头部数据 */
     _defaultWavHdr =
    {
        { 'R', 'I', 'F', 'F' },
        0,
        {'W', 'A', 'V', 'E'},
        {'f', 'm', 't', ' '},
        16,
        1,
        1,
        16000,
        32000,
        2,
        16,
        {'d', 'a', 't', 'a'},
        0
    };
    ret = MSP_SUCCESS;
    _isPlayVoice = false;
    _textListIndex = 0;

    _playTimer = new QTimer(this);
    connect(_playTimer,&QTimer::timeout,this,&T3Voice::stopPlay);
    initTTS();
}

int T3Voice::initTTS()
{
    const char* login_params         = "appid = 5a5ef3cf, work_dir = .";
    const char* login_name           = "31011315@qq.com";
    const char* login_pwd            = "a000000A";
    ret = MSPLogin(login_name, login_pwd, login_params); //第一个参数是用户名，第二个参数是密码，第三个参数是登录参数，用户名和密码可在http://www.xfyun.cn注册获取
        if (MSP_SUCCESS != ret)
        {
            T3LOG <<"MSPLogin failed, error code: %d.\n";
            return 0 ;//登录失败，退出登录
        }
    _sessionBeginParams = "engine_type = local,voice_name=xiaoyan, text_encoding = UTF8, tts_res_path = fo|res/tts/xiaoyan.jet;fo|res/tts/common.jet, sample_rate = 16000, speed = 50, volume = 50, pitch = 50, rdn = 2";
}

int T3Voice::textToSpeech(const char *srcText)
{
    _fileName = "a"+QDateTime::currentDateTime().toString("hhmmss")+".wav";
    std::string str_ = _fileName.toStdString();
    const char* text_= str_.c_str();
    const char* fileName_ = text_; //合成的语音文件名称
    const char* filePath_ = "";

    int ret_ =-1;
    FILE * fp_ =NULL;
    const char * sessionID_ = NULL;
    unsigned int audioLen_ = 0;
    WavePcmHdr wavHdr_ = _defaultWavHdr;
    int synthStatus_ =MSP_TTS_FLAG_STILL_HAVE_DATA;

    if (NULL == srcText || NULL == fileName_)
    {
        T3LOG << "params is error!\n";
        return ret_;
    }

    char buff_[500];
    getcwd(buff_,sizeof(buff_));

    T3LOG<<buff_;
    fp_ = fopen(fileName_,"wb");
    if (NULL == fp_)
    {
        T3LOG <<"open %s error.\n";
        return ret_;
    }
    /* 开始合成 */
    sessionID_ = QTTSSessionBegin(_sessionBeginParams, &ret_);
    T3LOG <<sessionID_;
    if (MSP_SUCCESS != ret_)
    {
        T3LOG <<"QTTSSessionBegin failed, error code: %d.\n";
        fclose(fp_);
        return ret_;
    }
    ret_ = QTTSTextPut(sessionID_, srcText, (unsigned int)strlen(srcText), NULL);

    if (MSP_SUCCESS != ret_)
    {
       T3LOG <<"QTTSTextPut failed, error code: %d.\n";
        QTTSSessionEnd(sessionID_, "TextPutError");
        fclose(fp_);
        return ret_;
    }
    T3LOG << "正在合成 ...\n";
    fwrite(&wavHdr_, sizeof(wavHdr_) ,1, fp_); //添加wav音频头，使用采样率为16000
    while (1)
    {
        /* 获取合成音频 */
        const void* data_ = QTTSAudioGet(sessionID_, &audioLen_, &synthStatus_, &ret_);
        T3LOG << data_;
        if (MSP_SUCCESS != ret_)
            break;
        if (NULL != data_)
        {
            fwrite(data_, audioLen_, 1, fp_);

            wavHdr_.data_size += audioLen_; //计算data_size大小
        }
        if (MSP_TTS_FLAG_DATA_END == synthStatus_)
            break;
    }

    if (MSP_SUCCESS != ret_)
    {
       T3LOG << "QTTSAudioGet failed, error code: %d.\n" << ret_;
        QTTSSessionEnd(sessionID_, "AudioGetError");
        fclose(fp_);
        return ret_;
    }

    /* 修正wav文件头数据的大小 */
    wavHdr_.size_8 += wavHdr_.data_size + (sizeof(wavHdr_) - 8);

    /* 将修正过的数据写回文件头部,音频文件为wav格式 */
    fseek(fp_, 4, 0);
    fwrite(&wavHdr_.size_8,sizeof(wavHdr_.size_8), 1, fp_); //写入size_8的值
    fseek(fp_, 40, 0); //将文件指针偏移到存储data_size值的位置
    fwrite(&wavHdr_.data_size,sizeof(wavHdr_.data_size), 1, fp_); //写入data_size的值
    fclose(fp_);
    fp_ = NULL;

    /* 合成完毕 */
    ret_ = QTTSSessionEnd(sessionID_, "Normal");
    if (MSP_SUCCESS != ret_)
    {
        T3LOG <<"QTTSSessionEnd failed, error code: %d.\n";
    }
    T3LOG << "合成完毕";
    int playTime_ = wavHdr_.data_size/32000;
    QSoundEffect *soundEffect_ = new QSoundEffect();
    soundEffect_->setSource(QUrl::fromLocalFile(fileName_));
    soundEffect_->setVolume(1);
    soundEffect_->play();

    _playTimer->start(playTime_*1000);
    //connect(soundEffect_,SIGNAL());
    _isPlayVoice = true;
    return ret_;
}

int T3Voice::inputToText(QString role, int gender, QString name)
{
    T3LOG << role << gender << name;
    if(role == "")
    {
        role = "未注册";
    }
    QSqlQuery query_;
    query_.prepare("select voice from T3FaceUserType where UserType = ?");
    query_.bindValue(0,role);
    query_.exec();
    query_.next();
    QString text_ = query_.value(0).toString();
    text_.replace("（姓名）",name);
    switch (gender) {
    case 0:
        text_.replace("（性别）","先生");
        break;
    case 1:
        text_.replace("（性别）","女士");
        break;
    default:
        text_.replace("（性别）","同学");
        break;
    }
    T3LOG << text_;

    if( -1 == _textList.indexOf(text_))
    _textList.append(text_);

    if(!_isPlayVoice)
    {
        textListToSpeech();
    }
}
int T3Voice::textListToSpeech()
{
    //_textListIndex = 0;
    T3LOG << _textListIndex;
    T3LOG << _textList.size();

    if(_textListIndex < _textList.size())
    {
        T3LOG << _textList[_textListIndex];
        std::string str = _textList[_textListIndex].toStdString();
        //QByteArray temp_ = _textList[_textListIndex].toLatin1();
        const char * text_= str.c_str();
        textToSpeech(text_);
        _textListIndex++;
    }else
    {
        _textListIndex = 0 ;
        _textList.clear();
        T3LOG << "sound play end";
    }
}

void T3Voice::playingChange()
{
    if(!_isPlayVoice)
    {
        T3LOG << "播放开始";
        _isPlayVoice = true;
    }else
    {
        T3LOG << "播放完毕";
        _isPlayVoice = false;
        textListToSpeech();
    }
}
void T3Voice::stopPlay()
{
    T3LOG << "stopPlay";
    _playTimer->stop();
    _isPlayVoice = false;

    QFile file(_fileName);
    if(file.exists())
    {
        T3LOG << "removeFile";
        //file.remove();
    }

    textListToSpeech();
}

void T3Voice::lowPower()
{
    QString lowPowerString_ = "电池电量低,机器人开始返航.";
    _textList.append(lowPowerString_);
    if(!_isPlayVoice)
    {
        textListToSpeech();
    }
}

T3Voice::~T3Voice()
{}

