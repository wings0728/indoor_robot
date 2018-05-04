#ifndef T3VIDEODECODER_H
#define T3VIDEODECODER_H

#include <QImage>
#include <QObject>
#include "../T3base/T3IOBase.hpp"
extern "C"
{
#include "libavutil/opt.h"
#include "libavcodec/avcodec.h"
#include "libavutil/imgutils.h"
#include <libswscale/swscale.h>

}

/**
  ******************************************************************************
  * @file
  * @author  HXP
  * @version  V1.0.0
  * @date    2018/04/08
  * @brief   视频解码器
  ******************************************************************************
*/
namespace tool
{
class T3VideoDecoder : public QObject
{
    Q_OBJECT
public:

    ~T3VideoDecoder();
  /**
     * @brief getInstance 获得单例对象
     * @return
     */
    static T3VideoDecoder* getInstance();
    /**
     * @brief decoderFrame  解码H264视频数据
     * @param data          h264视频帧数据指针
     * @param dataSize      264视频帧数据大小
     * @return
     */
    int decoderFrame(char * data,int dataSize);
    /**
     * @brief closeDecoder  关闭编码器,在你调用完成之后必须调用次函数关闭编码器.
     * @return
     */
    int closeDecoder();
    /**
     * @brief YUV2RGB   将YUV数据转换为RGB数据,便于使用QT进行显示.
     * @param data      YUV视频数据指针
     * @return
     */
    int YUV2RGB(char *data);

signals:
    void newFrame(QImage image);

private:
    T3VideoDecoder();
    int initDecoder();


    static T3VideoDecoder* _videoDecoder;
    int                     _srcBpp;
    int                     _dstBpp;
    int                     _height;
    int                     _width;
    uint8_t                 *_tempBuffer;
    int                     _ret;
    int                     _gotPicture;
    uint8_t                 *_srcData[4];
    int                     _srcLinesize[4];
    uint8_t                 *_dstData[4];
    int                     _dstLinesize[4];
    uint8_t                 *_outBuffer;
    uint8_t                 *_curPtr;
    int                     _curSize;
    int                     _videoDecoderNum;
    bool                    _videoDecoderIsOpen;



    AVCodec                 *_codec;
    AVCodecContext          *_codecCtx;
    AVCodecParserContext    *_codecParserCtx;
    AVCodecID               _codecId;
    AVFrame                 *_frame;
    AVFrame                 *_frameRGB;
    AVPacket                *_packet;


    AVPixelFormat           _srcPixFmt;
    AVPixelFormat           _dstPixFmt;
    struct SwsContext       *_imgConvertCtx;

};

}


#endif // T3VIDEODECODER_H
