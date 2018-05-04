#include "T3HardwareSwitchController.hpp"
#include "../config/config.hpp"

T3HardwareSwitchController::T3HardwareSwitchController(T3BaseController *parent,
                                                       bool showBackBtn,
                                                       QString labelPath):
    T3SwitchController(parent,
                       showBackBtn)
{
    _labelPath = labelPath;
    setLabel();
}

void T3HardwareSwitchController::setLabel()
{
    if(0 != this->_labelPath)
    {
        this->_label = new T3View::T3Label(this->_window,
                                              kAirLabelX_ac,
                                              kAirLabelY_ac,
                                              kAirLabelW_ac,
                                              kAirLabelH_ac,
                                              _labelPath
                                              );
    }
}

void T3HardwareSwitchController::turnOnEvent()
{
    if(kAirLabel == _labelPath)
    {
        airTurnOn();
    }
    if(kHumidifierLabel == _labelPath)
    {
        humidiferTurnOn();
    }
    if(kProjectionLabel == _labelPath)
    {
        projectionTurnOn();
    }
    if(kSweeperLabel == _labelPath)
    {
        sweeperTurnOn();
    }

}

void T3HardwareSwitchController::turnOffEvent()
{
    if(kAirLabel == _labelPath)
    {
        airTurnOff();
    }
    if(kHumidifierLabel == _labelPath)
    {
        humidiferTurnOff();
    }
    if(kProjectionLabel == _labelPath)
    {
        projectionTurnOff();
    }
    if(kSweeperLabel == _labelPath)
    {
        sweeperTurnOff();
    }
}

void T3HardwareSwitchController::airTurnOn()
{

}
void T3HardwareSwitchController::airTurnOff()
{

}
void T3HardwareSwitchController::humidiferTurnOn()
{

}

void T3HardwareSwitchController::humidiferTurnOff()
{

}

void T3HardwareSwitchController::projectionTurnOn()
{

}

void T3HardwareSwitchController::projectionTurnOff()
{

}

void T3HardwareSwitchController::sweeperTurnOn()
{

}

void T3HardwareSwitchController::sweeperTurnOff()
{

}
