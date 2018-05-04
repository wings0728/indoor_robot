#ifndef T3VIDEOCALLCONTROLLER_HPP
#define T3VIDEOCALLCONTROLLER_HPP
#include "baseController/T3UserController.hpp"
#include "../T3base/T3IOBase.hpp"
#include "../hardware/T3Camera.hpp"
#include "../hardware/T3Audio.h"
#include "../hardware/T3AudioPlayer.h"
#include "../tool/T3VideoEncoder.h"
#include "../tool/T3VideoDecoder.h"
#include "../network/T3AVNetwork.h"


/**
  ******************************************************************************
  * @file
  * @author  HXP
  * @version  V1.0.0
  * @date    2018/04/04
  * @brief    视频通讯窗口
  ******************************************************************************
*/
class T3VideoCallController : public T3UserController
{
  Q_OBJECT
public:
  explicit T3VideoCallController(T3BaseController* parent = 0);
  ~T3VideoCallController();

private:

  void setGoBackBtn();

  void setVideoIcon();

  int initCommucation();
  interface::T3Camera   *_camera;
  interface::T3Audio    *_audio;
  interface::T3AudioPlayer  *_audioPlayer;
  interface::T3AVNetwork    *_avNetwork;
  tool::T3VideoDecoder  *_videoDecoder;
  tool::T3VideoEncoder  *_videoEncoder;


  T3View::T3Label *_microphoneIcon;
  T3View::T3Label *_progressBarIcon;
  T3View::T3Label *_hintIcon;

};

#endif // T3VIDEOCALLCONTROLLER_HPP
