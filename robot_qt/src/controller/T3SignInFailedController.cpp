#include "T3SignInFailedController.hpp"
#include "../config/config.hpp"

#define kTitle_sfc "签到失败"
#define kContent_sfc "请重新签到"
#define kFailedDelayTime 3000

T3SignInFailedController::T3SignInFailedController(T3BaseController *parent):
    T3BaseController(0,
                     0,
                     kScreenW,
                     kScreenH,
                     kSignInBackground,
                     true,
                     parent)
{
    setSignInFailedLabel();
}

void T3SignInFailedController::setSignInFailedLabel()
{
    this->_signInFailedLabel = new T3View::T3Label(this->_window,
                                                      kSignInFailedLabelX_sic,
                                                      kSignInFailedLabelY_sic,
                                                      kSignInFailedLabelW_sic,
                                                      kSignInFailedLabelH_sic,
                                                      kFailedLabel);
QTimer::singleShot(kFailedDelayTime, this, SLOT(setFailedMessage()));
}

void T3SignInFailedController::setFailedMessage()
{
    this->_signInFailedLabel->hide();
    setTitleLabel();
    setContentLabel();
    setBack();
    //this->showUI();
}

void T3SignInFailedController::setTitleLabel()
{
    this->_titleLabel = new T3View::T3Label(this->_window,
                                            kTitleLabelFailedX_sic,
                                            kTitleLabelFailedY_sic,
                                            kTitleLabelFailedW_sic,
                                            kTitleLabelFailedH_sic,
                                            kTitle_sfc,
                                            kTitleFontSize_sic,
                                            kTitleFontStyle_sic,
                                            kSignInFailRGB,
                                            QFont::DemiBold,
                                            kTitleFontSpace_sic
                                            );
     this->_titleLabel->show();
}
void T3SignInFailedController::setContentLabel()
{
    this->_contentLabel = new T3View::T3Label(this->_window,
                                              kContentLabelFailedX_sic,
                                              kContentLabelFailedY_sic,
                                              kContentLabelFailedW_sic,
                                              kContentLabelFailedH_sic,
                                              kContent_sfc,
                                              kContentFontSize_sic,
                                              kContentFontStyle_sic,
                                              kSignInFailRGB,
                                              QFont::DemiBold,
                                              kContentFontSpace_sic);
   this->_contentLabel->show();
}

void T3SignInFailedController::setBack()
{
    //后续跳转功能
}
