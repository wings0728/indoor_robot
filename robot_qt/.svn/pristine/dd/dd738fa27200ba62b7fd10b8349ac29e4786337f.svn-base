#include "T3VideoEncoder.h"
namespace tool
{
T3VideoEncoder::T3VideoEncoder()
{
    _videoEncoderInitSuccess = false;
    _codecID = AV_CODEC_ID_H264;
    _width = 640;
    _height = 480;
}

T3VideoEncoder* T3VideoEncoder::_videoEncoder = new T3VideoEncoder();

T3VideoEncoder* T3VideoEncoder::getInstace()
{
  _videoEncoder->initEncoder();
  return _videoEncoder;
}

T3VideoEncoder::~T3VideoEncoder()
{

}
int T3VideoEncoder::initEncoder()
{
    if(_videoEncoderInitSuccess)
    {
        return 0;
    }
    avcodec_register_all();

    _codec = avcodec_find_encoder(_codecID);

    if(_codec == NULL)
    {
        T3LOG << "codec not found!";
        return -1;
    }
    _codecCtx = avcodec_alloc_context3(_codec);
    if(_codecCtx == NULL)
    {
        T3LOG << "could not allocate video context";
        return -1;
    }

    //配置编码器的相关参数
    _codecCtx->bit_rate = 400000;
    _codecCtx->width = _width;
    _codecCtx->height = _height;
    _codecCtx->time_base.num=1;
    _codecCtx->time_base.den=25;
    _codecCtx->gop_size = 10;
    _codecCtx->max_b_frames = 1;
    _codecCtx->pix_fmt = AV_PIX_FMT_YUV420P;

    AVDictionary *param_ = NULL;
    av_dict_set(&param_,
                "preset",
                "superfast",
                0);
    av_dict_set(&param_,
                "tune",
                "zerolatency",
                0);
    T3LOG << "avcodec_open2";
    if(avcodec_open2(_codecCtx,
                     _codec,
                     &param_) <0 )
    {
        T3LOG << "could not open codec";
        return -1;
    }
    T3LOG << "avcodec_open2";
    _frame = av_frame_alloc();
    if(_frame == NULL)
    {
        T3LOG << "could not allocate video frame";
        return -1;
    }
    _frame->format = _codecCtx->pix_fmt;
    _frame->width = _codecCtx->width;
    _frame->height = _codecCtx->height;

    int ret_ = av_image_alloc(_frame->data,
                             _frame->linesize,
                             _codecCtx->width,
                             _codecCtx->height,
                             _codecCtx->pix_fmt,
                             16);
    if(ret_ < 0)
    {
        T3LOG << "could not allocate raw picture buffer";
        return -1;
    }
    _packet=(AVPacket *)av_malloc(sizeof(AVPacket));
    _videoEncoderInitSuccess = true;


    return 0;
}
int T3VideoEncoder::encoderVideoFrame(AVFrame &srcFrame,
                                      AVPacket &dstFrame)
{
    av_init_packet(_packet);
    _packet->data = NULL;
    _packet->size = 0;

    _frame->data[0] = srcFrame.data[0];
    _frame->data[1] = srcFrame.data[1];
    _frame->data[2] = srcFrame.data[2];

    int gotFrame_ = 0;
    int ret_ = avcodec_encode_video2(_codecCtx,
                                     _packet,
                                     _frame,
                                     &gotFrame_);
    if(ret_ < 0)
    {
        T3LOG << "error encoding frame";
        return -1;
    }
    if(gotFrame_)
    {
        dstFrame = *_packet;
        QByteArray h264Frame_;
        h264Frame_.resize(_packet->size);
        memcpy(h264Frame_.data(),
               _packet->data,
               _packet->size);
        //emit newH264Frame(h264Frame_);
    }
    return 0;
}
int T3VideoEncoder::closeEncoder()
{
    if(_codec != NULL)
    {
        _codec = NULL;
    }

    if(_codecCtx != NULL)
    {
        avcodec_close(_codecCtx);
        av_free(_codecCtx);
        _codecCtx = NULL;
    }

    if(_frame != NULL)
    {
        av_frame_free(&_frame);
        _frame = NULL;
    }
    if(_packet != NULL)
    {
        av_free_packet(_packet);
        _packet = NULL;
    }
    return 0;
}
}
