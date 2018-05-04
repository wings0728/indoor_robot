/**
  ******************************************************************************
  * @file
  * @author   孔志伟
  * @version  V1.0.0
  * @date    2018-04-16
  * @brief
  ******************************************************************************
*/
#ifndef robot_qt_BEGINCONTROLLER_HPP_
#define robot_qt_BEGINCONTROLLER_HPP_

#include "baseController/T3BaseController.hpp"
#include "../view/T3Label.hpp"

class T3BeginController :public T3BaseController
{
    Q_OBJECT
public:
    explicit T3BeginController();

private:
    T3View::T3Label * _bootCoinLabel;

    void setBootCoinLabel();//设置开机界面
};

#endif
