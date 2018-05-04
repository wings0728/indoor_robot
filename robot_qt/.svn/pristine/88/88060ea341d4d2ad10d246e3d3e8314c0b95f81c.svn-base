#include "T3WaitController.hpp"
#include "../config/config.hpp"

#define kMainTitle "THE SHARE ROBOTS"
#define kMainText "WORKING NEGO"
#define kCnTips "你的私人助理 你的个人媒体中心 你的私人机器人\r\n共享内戈机器人"

T3WaitController::T3WaitController():
    T3BaseController(0,
                     0,
                     kScreenW,
                     kScreenH,
                     kWaitBackground,
                     false)
{
    setMainTitle();
    setMainText();
    setCnTips();
}

void T3WaitController::setMainTitle()
{
   _mainTitle =new T3View::T3Label (this->_window,
                                 0,
                                 kMainTitleY_wc,
                                 kScreenW,
                                 kMainTitleH_wc,
                                 kMainTitle,
                                 kMainTitleFontSize,
                                 kMainTitleFontStyle,
                                 kMainRGB,
                                 QFont::DemiBold,
                                 kMainTitleFontSpace
                                 );
}
void T3WaitController::setMainText()
{
    _mainText =new T3View::T3Label(this->_window,
                                0,
                                kMainTextY_wc,
                                kScreenW,
                                kMainTextH_wc,
                                kMainText,
                                kMainTextFontSize,
                                kMainTextFontStyle,
                                kMainRGB,
                                QFont::Bold,
                                kMainTextFontSpace
                                );
}
void T3WaitController::setCnTips()
{
    _cnTips =new T3View::T3Label(this->_window,
                              0,
                              kCnTipsY_wc,
                              kScreenW,
                              kCnTipsH_wc,
                              kCnTips,
                              kCnTipsFontSize,
                              kCnTipsFontStyle,
                              kCnTipsRGB,
                              QFont::Medium,
                              kCnTipsFontSpace
                              );
}

