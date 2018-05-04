#ifndef T3SWITCHCONTROLLER_H
#define T3SWITCHCONTROLLER_H
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3SwitchController.hpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#include "T3BaseController.hpp"
#include "../../view/T3Button.hpp"
#include "../../view/T3Label.hpp"

class T3SwitchController:public T3BaseController
{
    Q_OBJECT
public:
    /**
     * @brief T3SwitchController
     * @parent 此控制器的父控制器
     * @showBackBtn 是否显示返回按钮
     */
    explicit T3SwitchController(T3BaseController *parent=0,
                                bool showBackBtn = true);
    /**
     * @brief 开关后续功能
     */
    virtual void turnOffEvent(){}
    virtual void turnOnEvent(){}

public slots:
     void setSwitch();
     void turnOn();
     void turnOff();


protected:
    T3View::T3Button *_switch;

};

#endif // T3SWITCHCONTROLLER_H
