#include "T3VideoDecoder.h"


namespace tool
{
T3VideoDecoder::T3VideoDecoder()
{
    _codecId = AV_CODEC_ID_H264;
    _height = kFrameHeight;
    _width  = kFrameWidth;
    _srcPixFmt = AV_PIX_FMT_YUYV422;
    _dstPixFmt = AV_PIX_FMT_RGB32;
    _videoDecoderNum = 0;
    _videoDecoderIsOpen = false;
}

T3VideoDecoder* T3VideoDecoder::_videoDecoder = new T3VideoDecoder();

T3VideoDecoder* T3VideoDecoder::getInstance()
{
  _videoDecoder->initDecoder();

  return _videoDecoder;
}

T3VideoDecoder::~T3VideoDecoder()
{

}

int T3VideoDecoder::initDecoder()
{

    _videoDecoderNum ++;
    if(_videoDecoderIsOpen)
    {
      return 0;
    }
    _videoDecoderIsOpen = true;
    avcodec_register_all();
    _codec = avcodec_find_decoder(_codecId);
    _codecCtx = avcodec_alloc_context3(_codec);
    _codecParserCtx = av_parser_init(_codecId);
    _packet=(AVPacket *)av_malloc(sizeof(AVPacket));

    if (avcodec_open2(_codecCtx, _codec, NULL) < 0)
    {
        printf("Could not open codec\n");
        return -1;
    }


    _frame = av_frame_alloc();
    _frameRGB = av_frame_alloc();
    av_init_packet(_packet);


    _srcBpp = av_get_bits_per_pixel(av_pix_fmt_desc_get(_srcPixFmt));
    _dstBpp = av_get_bits_per_pixel(av_pix_fmt_desc_get(_dstPixFmt));
    _tempBuffer = (uint8_t *)malloc(_height * _width / 8);
    _ret = av_image_alloc(_srcData,
                          _srcLinesize,
                          _width,
                          _height,
                          _srcPixFmt,
                          1);

    if(_ret < 0)
    {
        T3LOG << "could not allocate source image";
        return -1;
    }
    _ret = av_image_alloc(_dstData,
                          _dstLinesize,
                          _width,
                          _height,
                          _dstPixFmt,
                          1);
    if(_ret < 0)
    {
        T3LOG << "could not allocate destination image";
        return -1;
    }

    _imgConvertCtx = sws_alloc_context();


    av_opt_set_int(_imgConvertCtx,"sws_flags",SWS_BICUBIC|SWS_PRINT_INFO,0);
    av_opt_set_int(_imgConvertCtx,"srcw",_width,0);
    av_opt_set_int(_imgConvertCtx,"srch",_height,0);
    av_opt_set_int(_imgConvertCtx,"src_format",_srcPixFmt,0);
    av_opt_set_int(_imgConvertCtx,"src_range",1,0);
    av_opt_set_int(_imgConvertCtx,"dstw",_width,0);
    av_opt_set_int(_imgConvertCtx,"dsth",_height,0);
    av_opt_set_int(_imgConvertCtx,"dst_format",_dstPixFmt,0);
    av_opt_set_int(_imgConvertCtx,"dst_range",1,0);
    sws_init_context(_imgConvertCtx,NULL,NULL);


    int numBytes_ = avpicture_get_size(AV_PIX_FMT_RGB32,
                                       _width,
                                       _height);

    _outBuffer = (uint8_t *)av_malloc(numBytes_ *sizeof(uint8_t));

    int ret_ = avpicture_fill((AVPicture *)_frameRGB,
                   _outBuffer,
                   AV_PIX_FMT_RGB32,
                   _width,
                   _height);
        T3LOG << ret_;


}

int T3VideoDecoder::decoderFrame(char *data, int dataSize)
{
    _curPtr = (uint8_t *)data;
    _curSize = dataSize;
    while(_curSize > 0)
    {
        int len_ = av_parser_parse2(_codecParserCtx,
                                   _codecCtx,
                                   &_packet->data,
                                   &_packet->size,
                                   _curPtr,
                                   _curSize,
                                   AV_NOPTS_VALUE,
                                   AV_NOPTS_VALUE,
                                   AV_NOPTS_VALUE);

        _curPtr += len_;
        _curSize -= len_;
        if(0 == _packet->size)
        {
            continue;
        }

        switch(_codecParserCtx->pict_type){
            case AV_PICTURE_TYPE_I: T3LOG <<"Type:I\t";break;
            case AV_PICTURE_TYPE_P: T3LOG <<"Type:P\t";break;
            case AV_PICTURE_TYPE_B: T3LOG <<"Type:B\t";break;
            default: T3LOG << "Type:Other\t";break;
        }


        _ret = avcodec_decode_video2(_codecCtx,
                                     _frame,
                                     &_gotPicture,
                                     _packet);
        if(_ret < 0)
        {
            T3LOG << "decode error";
            return _ret;
        }
        if(_gotPicture)
        {
            sws_scale(_imgConvertCtx,
                      (uint8_t const * const *)_frame->data,
                      _frame->linesize,
                      0,
                      _height,
                      _frameRGB->data,
                      _frameRGB->linesize);
            QImage image((unsigned char *)_outBuffer,
                         _width,
                         _height,
                         QImage::Format_RGB32);

            emit newFrame(image);
        }
    }
    return 0;
}

int T3VideoDecoder::YUV2RGB(char *data)
{

  memcpy(_srcData[0] ,data, _width * _height * 2);
  sws_scale(_imgConvertCtx,
            _srcData,
            _srcLinesize,
            0,
            _height,
            _frameRGB->data,
            _frameRGB->linesize);
  QImage image((unsigned char *)_outBuffer,
               _width,
               _height,
               QImage::Format_RGB32);

  emit newFrame(image);
}



int T3VideoDecoder::closeDecoder()
{

    _videoDecoderNum --;
    if(0 == _videoDecoderNum)
    {
      _videoDecoderIsOpen = false;
      _packet->data = NULL;
      _packet->size = 0;
      av_parser_close(_codecParserCtx);
      av_frame_free(&_frame);
      avcodec_close(_codecCtx);
      av_free(_codecCtx);
    }

    return 0;
}
}

