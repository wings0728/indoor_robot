/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3ExpressController.hpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#ifndef robot_qt_EXPRESSCONTROLLER_HPP_
#define robot_qt_EXPRESSCONTROLLER_HPP_
#include "baseController/T3ChoiceController.hpp"

class T3ExpressController : public T3ChoiceController {
  Q_OBJECT
public:
  explicit T3ExpressController(T3ChoiceController *parent = 0);
  void leftBtnEvent();
  void rightBtnEvent();

private:

};

#endif
