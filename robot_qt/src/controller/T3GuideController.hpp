/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3GuideController.hpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#ifndef robot_qt_GUIDECONTROLLER_HPP_
#define robot_qt_GUIDECONTROLLER_HPP_

#include "baseController/T3BaseController.hpp"
#include "../view/T3Button.hpp"
#include "../model/T3PositionModel.hpp"
#include <vector>
#include "../ros/qnode.hpp"

class T3GuideController: public T3BaseController
{
  Q_OBJECT
public:
  explicit T3GuideController(T3BaseController *parent=0);
  //~T3GuideController();

private slots:
  void guideBtnSlot(int btnTag);

private:
  interface::QNode *_qnode;
  std::vector<T3View::T3Button *> _guideBtnList;

  void setupBtnList();
};

#endif
