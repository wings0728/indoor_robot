#ifndef T3SIGNWELCOMECONTROLLER_HPP
#define T3SIGNWELCOMECONTROLLER_HPP
#include "baseController/T3BaseController.hpp"
#include "../view/T3Label.hpp"

class T3SignWelcomeController : public T3BaseController
{
    Q_OBJECT
public:
    T3SignWelcomeController(T3BaseController *parent = 0);

private slots:
    void updateTime();

private:
    T3View::T3Label *_titleLabel;
    T3View::T3Label *_contentLabel;
    T3View::T3Label *_timeLabel;
    QString _timeStr;

    void setTitleLabel();
    void setContentLabel();
    void updateTimeStr();
    void setTimeLabel();
    void setupQTime();
};

#endif // T3SIGNWELCOMECONTROLLER_HPP
