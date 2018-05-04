/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3ExpressFinishController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#include "T3ExpressFinishController.hpp"
#include "../config/config.hpp"
#define kExpressFinishBGPath ":images/mainBackground.png"
#define kTitleText "取件完成请关闭储物仓\r\n非常感谢\r\n祝你工作愉快"

T3ExpressFinishController::T3ExpressFinishController(T3BaseController *parent):
  T3BaseController(0, 0, kScreenW, kScreenH, kExpressFinishBGPath, parent)
{
  setTitle();
}


void T3ExpressFinishController::setTitle()
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
