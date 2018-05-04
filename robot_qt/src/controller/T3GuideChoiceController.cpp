/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3GuideChoiceController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.18
  * 说明
  ******************************************************************************
*/
#include "T3GuideChoiceController.hpp"
#include "../config/config.hpp"
#include <typeinfo>

#define kTitle "是否需要引导？"//标题显示的文字
#define kLeftImage ":images/choiceDialog/choiceYesBtn_normal.png"//左边按钮普通状态图标
#define kLeftPressImage ":images/choiceDialog/choiceYesBtn_pressed.png"//左边按钮点击状态图标
#define kRightImage ":images/choiceDialog/choiceNoBtn_normal.png"//右边按钮普通状态图标
#define kRightPressImage ":images/choiceDialog/choiceNoBtn_pressed.png"//右边按钮点击状态图标

T3GuideChoiceController::T3GuideChoiceController(T3PositionModel *goal, T3Pose *currentPose, T3BaseController *parent):
  _currentPose(currentPose),
  _goal(goal),
  T3ChoiceController(kTitle,kLeftImage,kLeftPressImage,kRightImage,kRightPressImage, parent)
{
//  setBackGround();
  _qnode = interface::QNode::getInstance();
}




//T3GuideChoiceController* T3GuideChoiceController::_gcc = NULL;
//QMutex T3GuideChoiceController::_mutex ;

/*T3GuideChoiceController& T3GuideChoiceController::getInstance(T3PositionModel *goal,
                                                              T3Pose *currentPose,
                                                              T3BaseController *parent)
{
  if(NULL == _gcc)
  {
    QMutexLocker locker(&_mutex);
    if(NULL == _gcc)
    {
      _gcc = new T3GuideChoiceController(goal,currentPose,parent);
    }
  }

  return *_gcc;
}

T3GuideChoiceController::~T3GuideChoiceController()
{
  QMutexLocker locker(&_mutex);
  delete _gcc;
  _gcc = NULL;
}*/
void T3GuideChoiceController::leftBtnEvent()
{
  T3LOG << _goal->getPose().getX();
  T3LOG << _goal->getPose().getY();
  T3LOG << _goal->getPose().getZ();
  model::T3GuideTask guideTask_;
  interface::T3UserInfoDatabase userInfoDB_;
  model::T3UserInfo robotSelf_;
  userInfoDB_.getRobotSelf(robotSelf_);
  guideTask_.setType(model::eTGuide);
  guideTask_.setPosition(*_goal);
  guideTask_.setSender(robotSelf_);
  guideTask_.setPriority(1);
  guideTask_.setState(model::eTNotStart);
  interface::T3GuideTaskDB guideDB_;
  guideDB_.addNewGuideTask(guideTask_);
  emit guideTaskInsert();
  task::T3TaskScheduling* taskScheduing_ = task::T3TaskScheduling::getInstance();
  taskScheduing_->stopNowTask();


  //T3Pose goal_ = _goal->getPose();
//  qDebug() << "开始引导: " << goal_->_x << " | " << goal_->_y << " | " << goal_->_z;
 // _qnode->goalUpdate(goal_.getX(), goal_.getY(), goal_.getZ());
}

void T3GuideChoiceController::rightBtnEvent()
{
//  qDebug() << "放弃引导";
}
