#include "T3AirController.hpp"
#include "../config/config.hpp"

T3AirController::T3AirController(T3HardwareStartController *parent,
                                 bool showBackBtn):
    T3SwitchController(parent,
                       showBackBtn)
{
    setAirLabel();
}

void T3AirController::setAirLabel()
{
    this->_airLabel = new T3View::T3Label(this->_window,
                                          kAirLabelX_ac,
                                          kAirLabelY_ac,
                                          kAirLabelW_ac,
                                          kAirLabelH_ac,
                                          kAirLabel
                                          );
}

void T3AirController::setLine()
{

}

void T3AirController::turnOnEvent()
{
    //打开开关的触发事件
}

void T3AirController::turnOffEvent()
{
    //关闭开关的触发事件
}
