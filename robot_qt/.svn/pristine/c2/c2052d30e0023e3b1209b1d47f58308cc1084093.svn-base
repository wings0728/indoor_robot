#ifndef T3VIDEOENCODER_H
#define T3VIDEOENCODER_H

#include <QByteArray>
extern "C"
{
#include "libavutil/opt.h"
#include "libavcodec/avcodec.h"
#include "libavutil/imgutils.h"
#include <libswscale/swscale.h>
}
#include "../T3base/T3IOBase.hpp"
/**    bool _videoEncoderInitSuccess;
  ******************************************************************************
  * @file
  * @author     HXP
  * @version    V1.0.0
  * @date       2018/03/21
  * @brief      视频编码器
  ******************************************************************************
*/

namespace tool
{
class T3VideoEncoder : public T3IOBase
{
public:
    static T3VideoEncoder* getInstace();
    ~T3VideoEncoder();

    int encoderVideoFrame(AVFrame &srcFrame,
                          AVPacket &dstFrame);
    int closeEncoder();


signals:
    void newH264Frame(QByteArray h264Frame);

private:

    T3VideoEncoder();

    int initEncoder();

    bool _videoEncoderInitSuccess;
    AVCodecID _codecID ;
    int _height ;
    int _width;
    static T3VideoEncoder* _videoEncoder;

    AVCodec         *_codec;
    AVCodecContext  *_codecCtx;
    AVFrame         *_frame;
    AVPacket        *_packet;

};
}


#endif // T3VIDEOENCODER_H
