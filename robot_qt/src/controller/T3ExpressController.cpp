/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3ExpressController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#include "T3ExpressController.hpp"
#include "../config/config.hpp"
#include "T3ExpressFinishController.hpp"

#define kTitle "你有一份快递 是否取件？"//标题显示的文字
#define kLeftImage ":images/choiceDialog/choiceYesBtn_normal.png"//左边按钮普通状态图标
#define kLeftPressImage ":images/choiceDialog/choiceYesBtn_pressed.png"//左边按钮点击状态图标
#define kRightImage ":images/choiceDialog/choiceNoBtn_normal.png"//右边按钮普通状态图标
#define kRightPressImage ":images/choiceDialog/choiceNoBtn_pressed.png"//右边按钮点击状态图标

T3ExpressController::T3ExpressController(T3ChoiceController *parent):
  T3ChoiceController(kTitle,kLeftImage,kLeftPressImage,kRightImage,kRightPressImage, parent)
{
//  setBackGround();
}

void T3ExpressController::leftBtnEvent()
{
  qDebug() << "打开物流仓";
  qDebug() << "从数据库中删除任务";
  qDebug() << "跳转到取件完成页面";
//  emit leftSignal();
  T3ExpressFinishController *efc = new T3ExpressFinishController(this);
  efc->showUI();
  this->hideUI();
}

void T3ExpressController::rightBtnEvent()
{
  qDebug() << "继续寻找";
//  emit rightSignal();
}
