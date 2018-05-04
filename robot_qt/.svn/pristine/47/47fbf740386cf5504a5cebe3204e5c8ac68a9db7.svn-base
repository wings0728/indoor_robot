#ifndef T3AUDIOPLAYER_H
#define T3AUDIOPLAYER_H

#include <QByteArray>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioOutput>
#include <QIODevice>
#include <QList>
#include <QTimer>
#include <QObject>
#include <unistd.h>
#include <sys/types.h>
#include "../T3base/T3IOBase.hpp"


namespace interface
{
class T3AudioPlayer : public QObject
{
    Q_OBJECT
public:
    static T3AudioPlayer* getInstance();
    /**
     * @brief playTheAudio  播放音频数据
     * @param audioData     PCM音频数据
     * @return
     */
    int playTheAudio(QByteArray audioData);



private:
    static T3AudioPlayer* _player;

    int                 _audioListIndex;
    int                 _audioListReadIndex;
    bool                _isTimerStart;
    int                 _fileLength;


    FILE                *_file;
    QAudioFormat        *_audioFormat;
    QAudioOutput        *_audioOutput;
    QIODevice           *_audioOutputStream;
    QList<QByteArray>   *_audioDataList;
    QTimer              *_audioTimer;
    QByteArray          *_fileBuffer;

    T3AudioPlayer();
    ~T3AudioPlayer();

signals:
    void audio(QByteArray audio);
private slots:
    /**
     * @brief initAudioPlayer  初始化音频播放器
     * @return
     */
    int initAudioPlayer();
    /**
     * @brief writeToSpeacker  向喇叭写入数据
     * @return
     */
    int writeToSpeacker();
};

}

#endif // T3AUDIOPLAYER_H
