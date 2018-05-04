/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3GUideChoiceController.hpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.18
  * 说明
  ******************************************************************************
*/
#ifndef robot_qt_GUIDECHOICECONTROLLER_HPP_
#define robot_qt_GUIDECHOICECONTROLLER_HPP_
#include "baseController/T3ChoiceController.hpp"
#include "../ros/qnode.hpp"
#include "../model/T3TaskModel.hpp"
#include "../database/T3UserInfoDatabase.h"
#include "../database/T3GuideTaskDB.hpp"
#include "../task/T3Task.hpp"
#include "../task/T3TaskScheduling.hpp"

class T3GuideChoiceController : public T3ChoiceController {
  Q_OBJECT
public:
  explicit T3GuideChoiceController();
  explicit T3GuideChoiceController(T3PositionModel *goal, T3Pose *currentPose, T3BaseController *parent = 0);
  void leftBtnEvent();
  void rightBtnEvent();

signals:
  void guideTaskInsert();

private:
  interface::QNode *_qnode;
  T3Pose *_currentPose;
  T3PositionModel *_goal;
};

#endif
