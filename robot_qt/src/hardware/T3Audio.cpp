#include "T3Audio.h"



namespace interface
{


T3Audio::T3Audio()
{
    _audioIndex = -1;
    _ret  = -1;
    _isCanRun = false;
    _audioInitSuccess = false;
}


T3Audio::~T3Audio()
{

}

T3Audio* T3Audio::_audio = new T3Audio();

T3Audio* T3Audio::getInstance()
{
  _audio->startAudio();
  return _audio;
}

int T3Audio::initAudio()
{

    //av_log_set_level(AV_LOG_DEBUG);


    if(_audioInitSuccess)
    {
        return 0;
    }
    //注册编解码器及音频设备
    avdevice_register_all();
    av_register_all();

    //为formatContext分配内存空间
    _formatCtx = avformat_alloc_context();

    //根据短名查找到数据输入格式相关信息
    AVInputFormat *ifmt_ = av_find_input_format("alsa");

    //打开音频输入流
    if(0 != avformat_open_input(&_formatCtx,
                                "hw:0,0",
                                ifmt_,
                                NULL))
    {
        T3LOG << "Couldn't open input stream.（无法打开输入流)";
        return -1;
    }
    //查找流信息
    if(avformat_find_stream_info(_formatCtx,NULL)<0)
       {
           T3LOG << "Couldn't find stream information.";
           return -1;
       }
    //查找音频输入流数
    for(int i = 0;
        i < (int)_formatCtx->nb_streams;
        i++)
    {
        if(AVMEDIA_TYPE_AUDIO == _formatCtx->streams[i]->codec->codec_type)
        {
            _audioIndex = i;
            break;
        }
    }
    if(-1 == _audioIndex)
    {
        T3LOG << "Didn't find a video stream.（没有找到音频流)";
        return -1;
    }
    //根据音频输入流确定相应音频编解码信息
    _codecCtx = _formatCtx->streams[_audioIndex]->codec;
    _codecCtx->sample_fmt = AV_SAMPLE_FMT_S16P;

    //根据解码信息查找编解码器
    _codec = avcodec_find_decoder(_codecCtx->codec_id);
    if(_codec == NULL)
    {
        T3LOG << "audio Codec not found.";
        return -1;
    }
    //打开解码器
    if(avcodec_open2(_codecCtx,
                     _codec,
                     NULL)<0)
    {
        T3LOG << "Could not open audio codec.";
        return -1;
    }

    //为音频存储数据初始化内存
    _frame = av_frame_alloc();
    _packet=(AVPacket *)av_malloc(sizeof(AVPacket));
    _audioInitSuccess = true;
    return 0;


}

int T3Audio::startAudio()
{
    initAudio();
    _isCanRun = true;

    T3LOG <<"audio info:"<<_codecCtx->sample_fmt<<_codecCtx->bit_rate<<_codecCtx->sample_rate<<_codecCtx->channels;

    T3LOG << AV_SAMPLE_FMT_S16;

    start();
    return 0;
}

int T3Audio::stopAudio()
{
    QMutexLocker locker_(&_lock);
    _isCanRun = false;
    return 0;
}
void T3Audio::closeAudio()
{
    if(_frame != NULL)
    {
        av_free(_frame);
        _frame = NULL;
    }
    if(_codecCtx != NULL)
    {
        avcodec_close(_codecCtx);
        _codecCtx = NULL;
    }
    if(_formatCtx != NULL)
    {
        avformat_close_input(&_formatCtx);
        avformat_free_context(_formatCtx);
        _formatCtx = NULL;
    }
    _audioInitSuccess = false;

}

void T3Audio::run()
{
    int gotFrame_ = 0;
    while(true)
    {
        //读取下一帧数据
        _ret = av_read_frame(_formatCtx,
                            _packet);
        if(_ret < 0)
        {
            T3LOG << "no have next stream ";
            break;
        }
        if(_audioIndex == _packet->stream_index)
        {
            //对音频数据进行解码
            _ret =  avcodec_decode_audio4(_codecCtx,
                                         _frame,
                                         &gotFrame_,
                                          _packet);
            if(_ret < 0)
            {
                T3LOG << "audio error" ;
                return;
            }
            if(gotFrame_)
            {
                int pcmSize_ = av_samples_get_buffer_size(NULL,
                                                          _codecCtx->channels,
                                                          _frame->nb_samples,
                                                          _codecCtx->sample_fmt,
                                                          1);
                uint8_t * pcmBuffer_ = _frame->data[0];
                _audioFrame_.resize(pcmSize_);
                memcpy(_audioFrame_.data(),
                       pcmBuffer_,
                       pcmSize_);
                T3LOG << pcmSize_;
                emit newAudioFrame(_audioFrame_.data(),
                                   _audioFrame_.size());
                emit newAudioAVFrame(*_frame,
                                     pcmSize_);
            }
        }
        av_free_packet(_packet);
        QMutexLocker locker_(&_lock);
        if(!_isCanRun)
        {
            closeAudio();
            return ;
        };
    }
}
}
