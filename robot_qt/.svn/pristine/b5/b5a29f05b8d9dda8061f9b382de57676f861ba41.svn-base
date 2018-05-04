#ifndef T3AUDIO_H
#define T3AUDIO_H


#include <stdio.h>
#include <QThread>
#include <QMutex>
extern "C"
{
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavdevice/avdevice.h"
#include "libavutil/log.h"
}

/**
  ******************************************************************************
  * @file
  * @author     HXP
  * @version    V1.0.0
  * @date       2018/03/21
  * @brief      获得音频数据
  ******************************************************************************
*/

#include "../T3base/T3IOBase.hpp"
namespace interface
{


class T3Audio :public QThread, public T3IOBase
{
    Q_OBJECT
public:

    ~T3Audio();
    /**
     * @brief getInstance 获得单例对象指针
     * @return
     */
    static T3Audio* getInstance();

    /**
     * @brief stopAudio 停止发送音频数据
     * @return  0表示成功,-1表示失败
     */
    int stopAudio();

    /**
     * @brief _audioFrame_ 音频数据
     */
    QByteArray _audioFrame_;

signals:
    /**
     * @brief newAudioFrame 发送采集到的音频数据
     * @param audioFrameData    数据指针
     * @param audioFrameSize    数据大小
     */
    void newAudioFrame(char const* audioFrameData,
                       int audioFrameSize);

    void newAudioAVFrame(AVFrame Frame,
                         int frameSize);

private:
    /**
     * @brief initAudio 初始化音频接口,在获得单例之后都需要调用此函数进初始化
     * @return  0表示初始化成功,-1表示初始化失败
     */
    int initAudio();
    /**
     * @brief startAudio    开始发送音频数据
     * @return 0表示成功,-1表示失败
     */
    int startAudio();

    static T3Audio*     _audio;
    int                 _ret;
    int                 _audioIndex;
    bool                _isCanRun;
    bool                _audioInitSuccess;

    AVFormatContext     *_formatCtx;
    AVCodecContext      *_codecCtx;
    AVCodec             *_codec;
    AVFrame             *_frame;
    AVPacket            *_packet;
    QMutex              _lock;



    explicit T3Audio();
    void closeAudio();
    void run();



};
}
#endif // T3AUDIO_H
