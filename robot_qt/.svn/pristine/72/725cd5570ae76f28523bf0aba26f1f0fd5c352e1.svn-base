/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3GuestLoginController.hpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#ifndef robot_qt_GUESTLOGINCONTROLLER_HPP_
#define robot_qt_GUESTLOGINCONTROLLER_HPP_
#include "T3VideoCallController.hpp"
#include "baseController/T3UserController.hpp"
#include "T3FaceSignInController.hpp"




class T3GuestLoginController : public T3UserController {
  Q_OBJECT
public:
  explicit T3GuestLoginController();
  ~T3GuestLoginController();

private slots:
  void videoBtnClick();
  void interviewBtnClick();
  void guideBtnClick();

private:
  T3VideoCallController *_videoCallController;
  T3FaceSignInController *_faceSignInCtl;
  T3View::T3Button *_videoBtn;
  T3View::T3Button *_interviewBtn;
  T3View::T3Button *_guideBtn;


  void setupLeftBtn();
  void setupCenterBtn();
  void setupRightBtn();

};

#endif
