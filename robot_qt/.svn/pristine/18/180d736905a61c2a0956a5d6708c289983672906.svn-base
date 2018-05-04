#ifndef T3HARDWARESWITCHCONTROLLER_HPP
#define T3HARDWARESWITCHCONTROLLER_HPP
#include "baseController/T3SwitchController.hpp"
#include "../view/T3Label.hpp"

class T3HardwareSwitchController:public T3SwitchController
{
    Q_OBJECT

public:
    explicit T3HardwareSwitchController(T3BaseController *parent=0,
                                        bool showBackBtn = true,
                                        QString labelPath = 0);

private:
        QString _labelPath;
        T3View::T3Label *_label;

        void setLabel();

        void turnOnEvent();
        void turnOffEvent();

        void airTurnOn();
        void airTurnOff();
        void humidiferTurnOn();
        void humidiferTurnOff();
        void projectionTurnOn();
        void projectionTurnOff();
        void sweeperTurnOn();
        void sweeperTurnOff();

};


#endif // T3HARDWARESWITCHCONTROLLER_HPP
