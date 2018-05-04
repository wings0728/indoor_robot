#ifndef T3AIRCONTROLLER_HPP
#define T3AIRCONTROLLER_HPP
#include "T3HardwareStartController.hpp"
#include "baseController/T3SwitchController.hpp"
#include "../view/T3Label.hpp"

class T3AirController:public T3SwitchController
{
    Q_OBJECT
public:
    explicit T3AirController(T3HardwareStartController *parent=0,
                             bool showBackBtn = true);

private:
    T3View::T3Label *_airLabel;
    T3View::T3Label *_line;

private:
    void setAirLabel();
    void setLine();

    void turnOnEvent();
    void turnOffEvent();
};

#endif // T3AIRCONTROLLER_HPP
