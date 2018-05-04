#ifndef robot_qt_WAITCONTROLLER_HPP
#define robot_qt_WAITCONTROLLER_HPP

#include "baseController/T3BaseController.hpp"
#include "../view/T3Label.hpp"

class T3WaitController:public T3BaseController
{
    Q_OBJECT
public:
    explicit T3WaitController();

private:
    T3View::T3Label *_mainTitle;
    T3View::T3Label *_mainText;
    T3View::T3Label *_cnTips;

    void setMainTitle();//设置主标题
    void setMainText();//设置主要内容
    void setCnTips();//设置中文提示
};

#endif // T3WAITCONTROLLER_HPP
