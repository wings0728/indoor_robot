/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3MapController.hpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#ifndef robot_qt_MAPCONTROLLER_HPP_
#define robot_qt_MAPCONTROLLER_HPP_

#include "baseController/T3BaseController.hpp"
//#include "../view/T3Button.hpp"
#include "../model/T3PositionModel.hpp"
#include "../model/T3Pose.hpp"
//#include <vector>
//#include "../ros/qnode.hpp"

class T3MapController: public T3BaseController
{
  Q_OBJECT
public:
  explicit T3MapController(T3PositionModel *goal, T3Pose *currentPose, T3BaseController *parent=0);
  ~T3MapController();

private slots:
  void showGuideChoice();

private:
  QTimer *_mapTimer;
  T3Pose *_currentPose;
  T3PositionModel *_goal;

  void showUIdo();

};

#endif
