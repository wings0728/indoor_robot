#include "T3StaffController.hpp"


T3StaffController::T3StaffController():
    T3UserController(kSIBackground)
{
    setHardwareBtn();
    setVideoBtn();
    setGuideBtn();
}

T3StaffController::~T3StaffController()
{
  if(_logisticsBtn_normal != NULL)
  {
    delete _logisticsBtn_normal;
    _logisticsBtn_normal = NULL;
  }
  if(_hardwareBtn_normal != NULL)
  {
    delete _hardwareBtn_normal;
    _hardwareBtn_normal = NULL;
  }
  if(_videoBtn_normal != NULL)
  {
    delete _videoBtn_normal;
    _videoBtn_normal = NULL;
  }
  if(_attendanceBtn_normal != NULL)
  {
    delete _attendanceBtn_normal;
    _attendanceBtn_normal = NULL;
  }
  if(_guideBtn_normal != NULL)
  {
    delete _guideBtn_normal;
    _guideBtn_normal = NULL;
  }
}


void T3StaffController::setHardwareBtn()
{
    this->_hardwareBtn_normal = new T3View::T3Button(this->_window,
                                                      kHardwareBtnX_sc,
                                                      kHardwareBtnY_sc,
                                                      kHardwareBtnW_sc,
                                                      kHardwareBtnH_sc,
                                                      kHardwareImage_sc_normal,
                                                      kHardwareImage_sc_pressed
                                                      );
    connect(this->_hardwareBtn_normal,SIGNAL(clicked(bool)),this,SLOT(hardwareBtnClick()));
}
void T3StaffController::setVideoBtn()
{
    this->_videoBtn_normal = new T3View::T3Button(this->_window,
                                                kVideoBtnX_sc,
                                                kVideoBtnY_sc,
                                                kVideoBtnW_sc,
                                                kVideoBtnH_sc,
                                                kVideoImage_sc_normal,
                                                kVideoImage_sc_pressed
                                                );
    connect(this->_videoBtn_normal,SIGNAL(clicked(bool)),this,SLOT(videoBtnClick()));
}

void T3StaffController::setGuideBtn()
{
    this->_guideBtn_normal = new T3View::T3Button(this->_window,
                                                kGuideBtnX_sc,
                                                kGuideBtnY_sc,
                                                kGuideBtnW_sc,
                                                kGuideBtnH_sc,
                                                kGuideImage_sc_normal,
                                                kGuideImage_sc_pressed
                                                );
     connect(this->_guideBtn_normal,SIGNAL(clicked(bool)),this,SLOT(guideBtnClick()));
}

void T3StaffController::logisticBtnClick()
{

    T3SendExpressController *seCtl_ = new T3SendExpressController(this);
    this->hideUI();
    seCtl_->showUI();
}
void T3StaffController::hardwareBtnClick()
{
    qDebug()<<"hardwareBtnClick";

    T3HardwareStartController *hsc = new T3HardwareStartController(this);
    this->hideUI();
    hsc->showUI();

}
void T3StaffController::videoBtnClick()
{
    qDebug()<<"videoBtnClick";
    T3VideoCallController *vcCtl_ = new T3VideoCallController(this);
    this->hideUI();
    vcCtl_->showUI();
}
void T3StaffController::attendanceBtnClick()
{
    qDebug()<<"attendanceBtnClick";

    //T3FaceSignInController *fsCtl_ = new T3FaceSignInController(this);
    this->hideUI();
    //fsCtl_->showUI();
}
void T3StaffController::guideBtnClick()
{
    T3GuideController *gc_ = new T3GuideController(this);
    gc_->showUI();
    this->hideUI();
  qDebug()<<"guideBtnClick";
}
