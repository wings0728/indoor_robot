/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3ExpressFinishController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#ifndef robot_qt_EXPRESSFINISHCONTROLLER_HPP_
#define robot_qt_EXPRESSFINISHCONTROLLER_HPP_
#include "baseController/T3BaseController.hpp"
#include "../view/T3Label.hpp"

class T3ExpressFinishController : public T3BaseController {
  Q_OBJECT
public:
  explicit T3ExpressFinishController(T3BaseController *parent = 0);

private:
  T3View::T3Label *_title;

  void setTitle();
};

#endif
