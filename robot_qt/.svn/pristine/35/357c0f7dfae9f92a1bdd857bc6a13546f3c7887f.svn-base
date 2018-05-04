/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3SwitchController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#include "T3SwitchController.hpp"
#include "../../config/config.hpp"

T3SwitchController::T3SwitchController(T3BaseController *parent,
                                       bool showBackBtn
                                       ):
    T3BaseController(0,
                     0,
                     kScreenW,
                     kScreenH,
                     kMainBackground,
                     showBackBtn,
                     parent)
{
    setSwitch();
    turnOff();
    turnOn();
}

void T3SwitchController::setSwitch()
{
    this->_switch = new T3View::T3Button(this->_window,
                                      kSwitchBtnX_ac,
                                      kSwitchBtnY_ac,
                                      kSwitchBtnW_ac,
                                      kSwitchBtnH_ac,
                                      kOffBtn,
                                      kOffBtn
                                      );

    connect(this->_switch,SIGNAL(clicked(bool)),this,SLOT(turnOn()));
}

void T3SwitchController::turnOn()
{
    this->_switch->setButtonImage(kOnBtn,kOnBtn);
    this->_switch->update();
    turnOnEvent();
    connect(this->_switch,SIGNAL(clicked(bool)),this,SLOT(turnOff()));
}

void T3SwitchController::turnOff()
{
    this->_switch->setButtonImage(kOffBtn,kOffBtn);
    this->_switch->update();
    turnOffEvent();
    connect(this->_switch,SIGNAL(clicked(bool)),this,SLOT(turnOn()));
}

