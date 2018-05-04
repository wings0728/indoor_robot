#include "T3MainController.hpp"
#include "../config/config.hpp"

T3MainController::T3MainController()
{


  _camera = NULL;
  _face = NULL;
  _faceScan = NULL;
  _network = NULL;
  _taskDB = NULL;
  _taskSchedu = NULL;
  _rosNode = NULL;
  showUnderground();
  initInstance();
  //loadNewFace();
}

T3MainController::~T3MainController()
{

  if(NULL != _faceScan)
  {
    _faceScan->stopFaceScan();
    delete _faceScan;
    _faceScan = NULL;
  }
  if(NULL != _camera)
  {
    delete _camera;
    _camera = NULL;
  }

  if(NULL != _face)
  {
    delete _face;
    _face = NULL;
  }

  if(NULL != _network)
  {
    delete _network;
    _network = NULL;
  }
  if(NULL != _taskSchedu)
  {
    delete _taskSchedu;
    _taskSchedu = NULL;
  }
  if(NULL != _taskDB)
  {
    delete _taskDB;
    _taskDB = NULL;
  }
}

/**
 * 初始化所有单例
 */
void T3MainController::initInstance()
{

    //_camera = interface::T3Camera::getInstance();
    //_face = interface::T3Face::getInstance();
    _faceScan = interface::T3FaceScan::getInstance();
    _network = interface::T3Network::getInstance();
    _taskDB = interface::T3TaskDatabase::getInstance();
    _taskSchedu = task::T3TaskScheduling::getInstance();
    _rosNode = interface::QNode::getInstance();

    interface::T3RobotStateDB robotStateDB_;
    //robotStateDB_.addRobotState();
    //_taskDB->startTaskSearch();
}

/**
 * 底层界面
 */
void T3MainController::showUnderground()
{
  T3View::T3Dialog* underground_ = new T3View::T3Dialog(kScreenX,
                                            kScreenY,
                                            kScreenW,
                                            kScreenH,
                                            Qt::black);
  underground_->show();
}

/****** 构建所有界面跳转逻辑 *******/
void T3MainController::run()
{
  //_wifi = new T3Wifi();
  //_wifi->showUI();
//  _hsc = new T3WaitController();
//  _hsc->showUI();
  //T3BaseController *_bc = new T3BaseController(0,0,1280,720,kMainBackground);
  //_wifiBtn = new T3View::T3WifiButton(_bc->_window,0,kMainBackground,kMainBackground,"1",true,1);
  //_bc->showUI();
}



int T3MainController::loadNewFace()
{
  _face = interface::T3Face::getInstance();
  T3LOG << "face";
  model::T3UserInfo userInfo_;
  T3Pose pose_;
  pose_.setX(0);
  pose_.setY(0);
  pose_.setZ(0);
  T3PositionModel position_;
  position_.setPose(pose_);
  position_.setPoseName("工位2");
  QImage faceImage_;
  //_faceImage.load("/home/kzw/face/陈健俊.jpg");
  //faceImage_.load("/home/t3hxp/face/陈健俊.jpg");
  faceImage_.load("/home/jason/face/金城.jpg");
  userInfo_.setName("金城");
  userInfo_.setPosition(position_);
  userInfo_.setType(model::eUser);
  userInfo_.setGender(model::eMale);
  _face->addNewUserInfo(faceImage_,userInfo_);
}




