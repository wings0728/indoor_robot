#include "T3Camera.hpp"



namespace interface
{


T3Camera::T3Camera()
{
    _cameraIndex = -1;
    _ret  = -1;
    _isCanRun = false;
    _cameraInitSuccess = false;
    _options = NULL;
    _index = 0;

}


T3Camera::~T3Camera()
{

}

T3Camera* T3Camera::_camera = new T3Camera();

T3Camera* T3Camera::getInstance()
{
  _camera->startCamera();

  return _camera;

}

int T3Camera::initCamera()
{
    if(_cameraInitSuccess)
    {
        return 0;
    }
    //注册编解码器及视频设备
    avdevice_register_all();
    av_register_all();

    //为formatContext分配内存空间
    _formatCtx = avformat_alloc_context();

    //根据短名查找到数据输入格式相关信息
    AVInputFormat *ifmt_ = av_find_input_format("v4l2");

    //设置分辨率
    av_dict_set(&_options,
                "video_size",
                kFrameSize,
                0);
    //设置帧率
    av_dict_set(&_options,
                "framerate",
                kFramerate,
                0);

    //打开视频输入流
    if(0 != avformat_open_input(&_formatCtx,
                                kCameraPath,
                                ifmt_,
                                &_options))
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
    //查找视频输入流数
    for(int i = 0;
        i < (int)_formatCtx->nb_streams;
        i++)
    {
        if(AVMEDIA_TYPE_VIDEO == _formatCtx->streams[i]->codec->codec_type)
        {
            _cameraIndex = i;
            break;
        }
    }
    if(-1 == _cameraIndex)
    {
        T3LOG << "Didn't find a video stream.（没有找到视频流)";
        return -1;
    }
    //根据视频输入流确定相应视频编解码信息
    _codecCtx = _formatCtx->streams[_cameraIndex]->codec;
    //根据解码信息查找编解码器
    _codec = avcodec_find_decoder(_codecCtx->codec_id);
    if(NULL == _codec)
    {
        T3LOG << "camera Codec not found.";
        return -1;
    }
    //打开解码器
    if(avcodec_open2(_codecCtx,
                     _codec,
                     NULL)<0)
    {
        T3LOG << "Could not open camera codec.";
        return -1;
    }

    //为视频存储数据初始化内存
    _frame = av_frame_alloc();
    _frameYUYV = av_frame_alloc();
    uint8_t *outBuffer_ = (uint8_t *)av_malloc(avpicture_get_size(AV_PIX_FMT_YUYV422,
                                                                _codecCtx->width,
                                                                _codecCtx->height));
    avpicture_fill((AVPicture *)_frameYUYV,
                   outBuffer_,
                   AV_PIX_FMT_YUYV422,
                   _codecCtx->width,
                   _codecCtx->height);
    _packet=(AVPacket *)av_malloc(sizeof(AVPacket));
    _imgConvertCtx = sws_getContext(_codecCtx->width,
                                    _codecCtx->height,
                                    _codecCtx->pix_fmt,
                                    _codecCtx->width,
                                    _codecCtx->height,
                                    AV_PIX_FMT_YUYV422,
                                    SWS_BICUBIC,
                                    NULL,
                                    NULL,
                                    NULL);
    _cameraInitSuccess = true;
    return 0;


}

int T3Camera::startCamera()
{
    int ret_ = initCamera();
    if(-1 == ret_)
    {
      emit cameraInitFailed();
      return -1;
    }
    _isCanRun = true;
    T3LOG <<"camera info:"<<"w=" <<_codecCtx->width <<"h="<<_codecCtx->height;
    start();
    return 0;
}

int T3Camera::stopCamera()
{
      QMutexLocker locker_(&_lock);
      _isCanRun = false;
    return 0;
}
void T3Camera::closeCamera()
{
    T3LOG << "closeCamera";
    if(_frame != NULL)
    {
        av_free(_frame);
        _frame = NULL;
    }
    if(_frameYUYV != NULL)
    {
        av_free(_frameYUYV);
        _frameYUYV = NULL;
    }
    if(_codecCtx != NULL)
    {
        avcodec_close(_codecCtx);
        _codecCtx = NULL;
    }
    if(_formatCtx != NULL)
    {
        T3LOG << "close input";
        avformat_close_input(&_formatCtx);
        avformat_free_context(_formatCtx);
        _formatCtx = NULL;
    }
    if(_imgConvertCtx != NULL)
    {
        sws_freeContext(_imgConvertCtx);
        _imgConvertCtx = NULL;
    }
    _cameraInitSuccess = false;
}
void T3Camera::run()
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
        if(_cameraIndex == _packet->stream_index)
        {
            //对视频数据进行解码
            _ret = avcodec_decode_video2(_codecCtx,
                                         _frame,
                                         &gotFrame_,
                                         _packet);
            if(_ret < 0)
            {
                T3LOG << "camera error" ;
                return;
            }
            if(gotFrame_)
            {
                sws_scale(_imgConvertCtx,
                          (const uint8_t* const*)_frame->data,
                          _frame->linesize,
                          0, _codecCtx->height,
                          _frameYUYV->data,
                          _frameYUYV->linesize);
                int frameSize_ = _codecCtx->height * _codecCtx->width;

                _cameraFrame.resize(frameSize_* 2 );
                memcpy(_cameraFrame.data(),
                       _frameYUYV->data[0],
                    frameSize_ * 2);

                emit newCameraFrame(_cameraFrame.data(),
                                   _cameraFrame.size());
                emit newCameraAVFrame(*_frameYUYV);
            }
        }
        av_free_packet(_packet);
        QMutexLocker locker_(&_lock);
        if(!_isCanRun)
        {
            closeCamera();
            return ;
        }
    }
}

int T3Camera::getFrame(QByteArray &frameData)
{

      frameData.resize(_cameraFrame.size());
      memcpy(frameData.data(),
             _cameraFrame.data(),
             _cameraFrame.size());
      return 0 ;
}
}
