#include "T3AudioPlayer.h"


namespace interface
{
T3AudioPlayer::T3AudioPlayer()
{
    _audioFormat = new QAudioFormat();
    _audioDataList = new QList<QByteArray>;
    _audioListIndex = 0;
    _audioListReadIndex = -1;
    _audioTimer = new QTimer();
    connect(_audioTimer,
            &QTimer::timeout,
            this,
            &T3AudioPlayer::writeToSpeacker);
    _isTimerStart = false;

}

T3AudioPlayer* T3AudioPlayer::_player = new T3AudioPlayer();

T3AudioPlayer* T3AudioPlayer::getInstance()
{
  _player->initAudioPlayer();
  return _player;
}
T3AudioPlayer::~T3AudioPlayer()
{

}

int T3AudioPlayer::initAudioPlayer()
{
    _audioFormat->setSampleRate(48000);
    _audioFormat->setChannelCount(2);
    _audioFormat->setSampleSize(16);
    _audioFormat->setCodec("audio/pcm");
    _audioFormat->setByteOrder(QAudioFormat::LittleEndian);
    _audioFormat->setSampleType(QAudioFormat::UnSignedInt);
    QAudioDeviceInfo info_ = QAudioDeviceInfo::defaultOutputDevice();
    if(!info_.isFormatSupported(*_audioFormat))
    {
        T3LOG << "default format not supported try to use nearest";
        QAudioFormat audioFormat_;
        audioFormat_ = info_.nearestFormat(*_audioFormat);
        _audioFormat = &audioFormat_;
    }
    _audioOutput = new QAudioOutput(*_audioFormat);
    _audioOutputStream = _audioOutput->start();
    QByteArray array;
    for(int i = 0 ; i<= kAudioListLenght ; i++)
    {
        _audioDataList->append(array);
    }
    _audioTimer = new QTimer();
    connect(_audioTimer,
            &QTimer::timeout,
            this,
            &T3AudioPlayer::writeToSpeacker);


    return 0;

}

int T3AudioPlayer::playTheAudio(QByteArray audioData)
{

    T3LOG << "play the audio";
    _audioOutputStream->write(audioData);
/*    if(_audioOutput)
    {
        int chuncks = _audioOutput->bytesFree() / _audioOutput->periodSize();
        while(chuncks)
        {
            T3LOG << chuncks;
            if(audioData.length() >= _audioOutput->periodSize())
            {
                _audioOutputStream->write(audioData,
                                          _audioOutput->periodSize());
                audioData.mid(_audioOutput->periodSize());

            }else
            {
                _audioOutputStream->write(audioData);
                audioData.clear();
                break;
            }
        }
    }

*/
    /*if(!_isTimerStart)
    {
       _audioTimer->start(kAudioPlayTimer);
        _isTimerStart = true;
    }
    if(_audioListIndex < kAudioListLenght)
    {
        _audioDataList->replace(_audioListIndex,
                                audioData);
        _audioListIndex++;
    }else
    {
        _audioDataList->replace(_audioListIndex,
                                audioData);
        _audioListIndex = 0;
    }*/
    return 0;

}

int T3AudioPlayer::writeToSpeacker()
{
    T3LOG << "audio speaker" ;
    _audioListReadIndex ++;
    QByteArray  audioData = _audioDataList->at(_audioListReadIndex);
    if(_audioOutput)
    {
        int chuncks = _audioOutput->bytesFree() / _audioOutput->periodSize();
        while(chuncks)
        {
            T3LOG << chuncks;
            if(audioData.length() >= _audioOutput->periodSize())
            {
                _audioOutputStream->write(audioData,
                                          _audioOutput->periodSize());
                audioData.mid(_audioOutput->periodSize());

            }else
            {
                _audioOutputStream->write(audioData);
                audioData.clear();
                break;
            }
        }
    }

    if(kAudioListLenght == _audioListReadIndex)
    {
        _audioListReadIndex = 0;
    }
    return 0;
}

}
