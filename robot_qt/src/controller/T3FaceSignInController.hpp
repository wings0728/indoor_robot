#ifndef T3FACESIGNINCONTROLLER_HPP
#define T3FACESIGNINCONTROLLER_HPP

#include <QMovie>
#include "baseController/T3BaseController.hpp"
#include "../T3base/T3IOBase.hpp"
#include "../hardware/T3Camera.hpp"
#include "../tool/T3VideoDecoder.h"
#include "../face/T3FaceScan.h"
#include "../view/T3Label.hpp"
#include "T3SignInSuccessedController.hpp"
#include "T3SignInFailedController.hpp"



/**
  ******************************************************************************
  * @file
  * @author  HXP
  * @version  V1.0.0
  * @date    2018/04/09
  * @brief   人脸签到界面
  ******************************************************************************
*/
class T3FaceSignInController : public T3BaseController
{
public:
  explicit T3FaceSignInController(T3BaseController* parnet = 0);
  ~T3FaceSignInController();

private:

  void setUI();

  interface::T3Camera       *_camera;
  tool::T3VideoDecoder      *_videoDecoder;
  interface::T3FaceScan     *_faceScan;
  T3View::T3Label           *_videoLabel;
  T3View::T3Label           *_faceFrameLabel;
  T3SignInSuccessedController *_SISCtl;
  T3SignInFailedController    *_SIFCtl;

  QTimer                    *_faceScanTimer;
  QMovie                    *_faceScanMovie;

private slots:
  void printVideo(QImage image);

  void decodeFrame(char const* cameraFrameData,
                   int cameraFrameSize);

  void initFaceScan();

  void faceSignInSuccess(int id);

  void faceSignInFailed();

protected:
  void showUIdo();







};

#endif // T3FACESIGNINCONTROLLER_HPP
