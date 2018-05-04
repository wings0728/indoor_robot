#ifndef T3SIGNINFAILEDCONTROLLER_HPP
#define T3SIGNINFAILEDCONTROLLER_HPP
#include "baseController/T3BaseController.hpp"
#include "../view/T3Label.hpp"
#include <QTimer>

class T3SignInFailedController : public T3BaseController
{
    Q_OBJECT
public:
    T3SignInFailedController(T3BaseController *parent = 0);

private slots:
    void setFailedMessage();

private:
    T3View::T3Label *_signInFailedLabel;

    T3View::T3Label *_titleLabel;
    T3View::T3Label *_contentLabel;

    void setSignInFailedLabel();

    void setTitleLabel();
    void setContentLabel();
    void setBack();
};

#endif // T3SIGNINFAILEDCONTROLLER_HPP
