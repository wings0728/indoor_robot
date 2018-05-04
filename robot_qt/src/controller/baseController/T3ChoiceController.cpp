/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3ChoiceController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#include "T3ChoiceController.hpp"
#include "../../config/config.hpp"

#define kChoiceBGPath ":/images/choiceDialog/choiceBackground.png"


T3ChoiceController::T3ChoiceController(const QString &titleText,
                                       const QString &leftImage,
                                       const QString &leftPressImage,
                                       const QString &rightImage,
                                       const QString &rightPressImage,
                                       T3BaseController *parent):
  T3BaseController(0, 0, kScreenW, kScreenH, kChoiceBGPath,false, parent)
{
  setTitle(titleText);
  setBtn(leftImage, leftPressImage, rightImage, rightPressImage);
}

void T3ChoiceController::setBtn(const QString &leftImage,
                                const QString &leftPressImage,
                                const QString &rightImage,
                                const QString &rightPressImage)
{
  _leftBtn = new T3View::T3Button(_window,
                          kLeftBtnX_bc,
                          kLeftBtnY_bc,
                          kLeftBtnW_bc,
                          kLeftBtnH_bc,
                          leftImage,
                          leftPressImage);

  _rightBtn = new T3View::T3Button(_window,
                          kRightBtnX_bc,
                          kRightBtnY_bc,
                          kRightBtnW_bc,
                          kRightBtnH_bc,
                          rightImage,
                          rightPressImage);

  connect(_leftBtn, SIGNAL(clicked(bool)),this, SLOT(leftClick()));
  connect(_rightBtn, SIGNAL(clicked(bool)),this, SLOT(rightClick()));
}

void T3ChoiceController::setTitle(const QString &text)
{
  _title = new T3View::T3Label(_window,
                               kTitleX_bc,
                               kTitleY_bc,
                               kTitleW_bc,
                               kTitleH_bc,
                               text,
                               kTitleFontSize,
                               kTitleFontStyle,
                               kMainRGB,
                               QFont::DemiBold,
                               kTitleFontSpace
                               );
}

/********** slot ***********/
void T3ChoiceController::leftClick()
{
  leftBtnEvent();
}

void T3ChoiceController::rightClick()
{
  rightBtnEvent();
  backToParent();
}
