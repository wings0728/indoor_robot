#include "T3HardwareStartController.hpp"
//#include "T3AirController.hpp"
#include "T3HardwareSwitchController.hpp"
#include "../config/config.hpp"

T3HardwareStartController::T3HardwareStartController(T3BaseController *parent):
    T3BaseController(0,
                     0,
                     kScreenW,
                     kScreenH,
                     kHSBackgroundPath,
                     true,
                     parent)
{
    setAirBtn();
    setHumidifierBtn();
    setProjectionBtn();
    setSweeperBtn();
   // _parent = parent;
}

void T3HardwareStartController::setAirBtn()
{
    this->_airBtn_normal = new T3View::T3Button(this->_window,
                                                kAirBtnX_hsc,
                                                kAirBtnY_hsc,
                                                kAirBtnW_hsc,
                                                kAirBtnH_hsc,
                                                kAirBtn_hsc_normal,
                                                kAirBtn_hsc_pressed
                                                );
    connect(this->_airBtn_normal,SIGNAL(clicked(bool)),this,SLOT(airBtnClick()));
}
void T3HardwareStartController::setHumidifierBtn()
{
    this->_humidifierBtn_normal = new T3View::T3Button(this->_window,
                                                       kHumidifierBtnX_hsc,
                                                       kHumidifierBtnY_hsc,
                                                       kHumidifierBtnW_hsc,
                                                       kHumidifierBtnH_hsc,
                                                       kHumidifierBtn_hsc_normal,
                                                       kHumidifierBtn_hsc_pressed);
    connect(this->_humidifierBtn_normal,SIGNAL(clicked(bool)),this,SLOT(humidifierBtnClick()));
}
void T3HardwareStartController::setProjectionBtn()
{
    this->_projectionBtn_normal = new T3View::T3Button(this->_window,
                                                       kProjectionBtnX_hsc,
                                                       kProjectionBtnY_hsc,
                                                       kProjectionBtnW_hsc,
                                                       kProjectionBtnH_hsc,
                                                       kProjectionBtn_hsc_normal,
                                                       kProjectionBtn_hsc_pressed
                                                       );
    connect(this->_projectionBtn_normal,SIGNAL(clicked(bool)),this,SLOT(projectionBtnClick()));
}
void T3HardwareStartController::setSweeperBtn()
{
    this->_sweeperBtn_normal = new T3View::T3Button(this->_window,
                                                    kSweeperBtnX_hsc,
                                                    kSweeperBtnY_hsc,
                                                    kSweeperBtnW_hsc,
                                                    kSweeperBtnH_hsc,
                                                    kSweeperBtn_hsc_normal,
                                                    kSweeperBtn_hsc_pressed
                                                    );
    connect(this->_sweeperBtn_normal,SIGNAL(clicked(bool)),this,SLOT(sweeperBtnClick()));
}

void T3HardwareStartController::airBtnClick()
{
    qDebug()<<"airBtnClick";

    //T3AirController *_ac = new T3AirController(this);
    T3HardwareSwitchController *_hsc = new T3HardwareSwitchController(this,true,kAirLabel);
    this->hideUI();
    _hsc->showUI();
}
void T3HardwareStartController::humidifierBtnClick()
{
    qDebug()<<"humidifierBtnClick";
    T3HardwareSwitchController *_hsc = new T3HardwareSwitchController(this,true,kHumidifierLabel);
    this->hideUI();
    _hsc->showUI();
}
void T3HardwareStartController::projectionBtnClick()
{
    qDebug()<<"projectionBtnClick";
    T3HardwareSwitchController *_hsc = new T3HardwareSwitchController(this,true,kProjectionLabel);
    this->hideUI();
    _hsc->showUI();
}
void T3HardwareStartController::sweeperBtnClick()
{
    qDebug()<<"sweeperBtnClick";
    T3HardwareSwitchController *_hsc = new T3HardwareSwitchController(this,true,kSweeperLabel);
    this->hideUI();
    _hsc->showUI();
}
