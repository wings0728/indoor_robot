#include "T3VideoCallController.hpp"



T3VideoCallController::T3VideoCallController(T3BaseController* parent):
T3UserController(kBackGround_vc, true, parent)
{
  setGoBackBtn();
  setVideoIcon();
}
T3VideoCallController::~T3VideoCallController()
{

}

void T3VideoCallController::setGoBackBtn()
{
  _battaryIcon->hide();
  this->_backBtn->setGeometry(kHBackX_vc,
                              kHBackY_vc,
                              kHBackW_vc,
                              kHBackH_vc);
  //connect(this->_backBtn, SIGNAL(clicked(bool)), SLOT(backToParent()));

}

void T3VideoCallController::setVideoIcon()
{
    _microphoneIcon = new T3View::T3Label(_window,
                                          kHmicrophoneIconX_vc,
                                          kHmicrophoneIconY_vc,
                                          kHmicrophoneIconW_vc,
                                          kHmicrophoneIconH_vc,
                                          kMicrophoneIcon_vc);
    _progressBarIcon = new T3View::T3Label(_window,
                                          kHprogressBarIconX_vc,
                                          kHprogressBarIconY_vc,
                                          kHprogressBarIconW_vc,
                                          kHprogressBarIconH_vc,
                                          kProgressBarIcon_vc);
    _hintIcon = new T3View::T3Label(_window,
                                          kHhintIconX_vc,
                                          kHhintIconY_vc,
                                          kHhintIconW_vc,
                                          kHhintIconH_vc,
                                          khintIcon_vc);

}

int T3VideoCallController::initCommucation()
{
  _camera = interface::T3Camera::getInstance();
  _audio = interface::T3Audio::getInstance();
  _audioPlayer = interface::T3AudioPlayer::getInstance();
  _avNetwork = interface::T3AVNetwork::getInstance();
  _videoEncoder = tool::T3VideoEncoder::getInstace();
  _videoDecoder = tool::T3VideoDecoder::getInstance();


}


