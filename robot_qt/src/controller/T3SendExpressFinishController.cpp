#include "T3SendExpressFinishController.hpp"
#include "../config/config.hpp"
#define kExpressFinishBGPath ":images/mainBackground.png"
#define kTitleText "放件完成请关闭储物仓\r\n不要催我\r\n我会尽快赶去目的地"

T3SendExpressFinishController::T3SendExpressFinishController(T3BaseController *parent):
  T3BaseController(0, 0, kScreenW, kScreenH, kExpressFinishBGPath,true, parent)
{
  setTitle();
}


void T3SendExpressFinishController::setTitle()
{
  _title = new T3View::T3Label(this->_window,
                               kTitleX_ef,
                               kTitleY_ef,
                               kTitleW_ef,
                               kTitleH_ef,
                               kTitleText,
                               kTitleFontSize,
                               kTitleFontStyle,
                               kMainRGB,
                               QFont::DemiBold,
                               kTitleFontSpace
                               );
}
