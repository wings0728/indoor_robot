#ifndef T3HARDWARESTARTCONTROLLER_HPP
#define T3HARDWARESTARTCONTROLLER_HPP
#include "baseController/T3BaseController.hpp"
#include "../view/T3Button.hpp"

class T3HardwareStartController:public T3BaseController{
    Q_OBJECT
public:
    explicit T3HardwareStartController(T3BaseController *parent = 0);

private slots:
    void airBtnClick();
    void humidifierBtnClick();
    void projectionBtnClick();
    void sweeperBtnClick();

private:
    T3View::T3Button *_airBtn_normal;
    T3View::T3Button *_humidifierBtn_normal;
    T3View::T3Button *_projectionBtn_normal;
    T3View::T3Button *_sweeperBtn_normal;
    //T3StaffController * _parent;

    void setAirBtn();
    void setHumidifierBtn();
    void setProjectionBtn();
    void setSweeperBtn();
};

#endif // T3HARDWARESTARTCONTROLLER_HPP
