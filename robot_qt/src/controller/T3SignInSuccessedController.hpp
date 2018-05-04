#ifndef T3SIGNINSUCCESSEDCONTROLLER_HPP
#define T3SIGNINSUCCESSEDCONTROLLER_HPP
#include "baseController/T3BaseController.hpp"
#include "../view/T3Label.hpp"

class T3SignInSuccessedController:public T3BaseController
{
    Q_OBJECT
public:
    T3SignInSuccessedController(T3BaseController *parent = 0,
                                QString name ="");

private slots:
    void updateTime();

    void setWelcome();

private:
    T3View::T3Label *_signInSuccessedLabel;

    T3View::T3Label *_titleLabel;
    T3View::T3Label *_contentLabel;
    T3View::T3Label *_timeLabel;
    QString _timeStr;
    QString _name;

    void setSignInSuccessedLabel();

    void setTitleLabel();
    void setContentLabel();
    void updateTimeStr();
    void setTimeLabel();
    void setupQTime();
    void setBack();

};

#endif // T3SIGNINSUCCESSEDCONTROLLER_HPP
