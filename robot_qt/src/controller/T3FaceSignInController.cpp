#include "T3FaceSignInController.hpp"



T3FaceSignInController::T3FaceSignInController(T3BaseController* parent):
  T3BaseController(0,0,kScreenW,kScreenH,"",true,parent)
{
  _camera       = NULL;
  _videoDecoder = NULL;
  _faceScan     = NULL;
  _faceScanMovie = new QMovie(kFaceFramePath);


  setUI();

  initFaceScan();


}

void T3FaceSignInController::initFaceScan()
{
  _camera = interface::T3Camera::getInstance();
  connect(_camera,
          &interface::T3Camera::newCameraFrame,
          this,
          &T3FaceSignInController::decodeFrame);
  _videoDecoder = tool::T3VideoDecoder::getInstance();
  connect(_videoDecoder,
          &tool::T3VideoDecoder::newFrame,
          this,
          &T3FaceSignInController::printVideo);
  _faceScan = interface::T3FaceScan::getInstance();
  /*connect(_faceScan,
          &interface::T3FaceScan::getNewFace,
          this,
          &T3FaceSignInController::faceSignInSuccess);*/

  _faceScanTimer = new QTimer();
  _faceScanTimer->start(3000);
  connect(_faceScanTimer,
          &QTimer::timeout,
          this,
          &T3FaceSignInController::faceSignInFailed);

}



void T3FaceSignInController::decodeFrame(char const* cameraFrameData,
                                        int cameraFrameSize)
{

  _videoDecoder->YUV2RGB((char *)cameraFrameData);
}


void T3FaceSignInController::printVideo(QImage iamge)
{

  iamge = iamge.scaled(kScreenW,kScreenH,Qt::KeepAspectRatio);
  _videoLabel->setPixmap(QPixmap::fromImage(iamge));
}

void T3FaceSignInController::faceSignInSuccess(int id)
{
  if(-1 == id)
  {
    return ;
  }
  _faceScanTimer->stop();

  _SISCtl = new T3SignInSuccessedController(_parent);
  backToParent();
  _parent->hideUI();
  _SISCtl->showUI();

  T3LOG << "face sign in success ,id = " << id;
}

void T3FaceSignInController::faceSignInFailed()
{
  _faceScanTimer->stop();
  _faceScan->stopFaceScan();
  _SIFCtl = new T3SignInFailedController(this);
  _SIFCtl->showUI();
  this->hideUI();
  T3LOG << "face sign in failed";
}
void T3FaceSignInController::setUI()
{
  _videoLabel = new T3View::T3Label(_window,
                                   0,
                                   0,
                                   kScreenW,
                                   kScreenH);

  _faceFrameLabel = new T3View::T3Label(_window,
                                          kHFaceFrameX_vc,
                                          kHFaceFrameY_vc,
                                          kHFaceFrameW_vc,
                                          kHFaceFrameH_vc,
                                          ""
                                          );
  _faceScanMovie->setScaledSize(QSize(kHFaceFrameW_vc,
                                      kHFaceFrameH_vc));
  _faceFrameLabel->setMovie(_faceScanMovie);
  _faceScanMovie->start();

  _backBtn->raise();
}

void T3FaceSignInController::showUIdo()
{
  T3LOG << "face show ui do";
  _faceScan = interface::T3FaceScan::getInstance();
}

T3FaceSignInController::~T3FaceSignInController()
{
  if(NULL != _camera)
  {
    _camera->stopCamera();
    _camera = NULL;
  }
  if(NULL != _videoDecoder)
  {
    _videoDecoder->closeDecoder();
    _videoDecoder = NULL;
  }
  if(NULL != _faceScan)
  {
    _faceScan->stopFaceScan();
    _faceScan = NULL;
  }

}
