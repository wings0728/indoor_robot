/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3GuestLoginController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#include "T3GuestLoginController.hpp"
#include "../config/config.hpp"

#define kBGPath "://images/guestLogin/background_gl.png"

#define kVideoImage_normal "://images/guestLogin/videoBtn_normal.png"
#define kVideoImage_pressed "://images/guestLogin/videoBtn_pressed.png"

#define kInterviewImage_normal "://images/guestLogin/interviewBtn_normal.png"
#define kInterviewImage_pressed "://images/guestLogin/interviewBtn_pressed.png"

#define kGuideImage_normal "://images/guestLogin/guideBtn_normal.png"
#define kGuideImage_pressed "://images/guestLogin/guideBtn_pressed.png"

T3GuestLoginController::T3GuestLoginController():
T3UserController(kBGPath,false)
{
  setupLeftBtn();
  setupCenterBtn();
  setupRightBtn();
}

T3GuestLoginController::~T3GuestLoginController()
{
  if(_videoCallController != NULL)
  {
    delete _videoCallController;
    _videoCallController = NULL;
  }
  if(_faceSignInCtl != NULL)
  {
    delete _faceSignInCtl;
    _faceSignInCtl = NULL;
  }
  if(_videoBtn != NULL)
  {
    delete _videoBtn;
    _videoBtn = NULL;
  }
  if(_interviewBtn != NULL)
  {
    delete _interviewBtn;
    _interviewBtn = NULL;
  }
  if(_guideBtn != NULL)
  {
    delete _guideBtn;
    _guideBtn = NULL;
  }
}


void T3GuestLoginController::setupLeftBtn()
{
  this->_videoBtn = new T3View::T3Button(this->_window,
                                  kLeftBtnX_glc,
                                  kLeftBtnY_glc,
                                  kLeftBtnW_glc,
                                  kLeftBtnH_glc,
                                  kVideoImage_normal,
                                  kVideoImage_pressed);
  connect(this->_videoBtn, SIGNAL(clicked(bool)), this, SLOT(videoBtnClick()));
}

void T3GuestLoginController::setupCenterBtn()
{
  this->_interviewBtn = new T3View::T3Button(this->_window,
                                  kCenterBtnX_glc,
                                  kCenterBtnY_glc,
                                  kCenterBtnW_glc,
                                  kCenterBtnH_glc,
                                  kInterviewImage_normal,
                                  kInterviewImage_pressed);
  connect(this->_interviewBtn, SIGNAL(clicked(bool)), this, SLOT(interviewBtnClick()));
}

void T3GuestLoginController::setupRightBtn()
{
  this->_guideBtn = new T3View::T3Button(this->_window,
                                  kRightBtnX_glc,
                                  kRightBtnY_glc,
                                  kRightBtnW_glc,
                                  kRightBtnH_glc,
                                  kGuideImage_normal,
                                  kGuideImage_pressed);
  connect(this->_guideBtn, SIGNAL(clicked(bool)), this, SLOT(guideBtnClick()));
}

/******** slot ********/
void T3GuestLoginController::videoBtnClick()
{
  _videoCallController = new T3VideoCallController(this);
  _videoCallController->showUI();
  //_faceSignInCtl = new T3FaceSignInController(this);
  //_faceSignInCtl->showUI();
  this->hideUI();

}

void T3GuestLoginController::interviewBtnClick()
{
  qDebug() << "interviewBtnClick";

}

void T3GuestLoginController::guideBtnClick()
{
  qDebug() << "guideBtnClick";

}
