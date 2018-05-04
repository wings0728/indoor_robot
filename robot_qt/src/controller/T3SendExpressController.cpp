#include "T3SendExpressController.hpp"
#include "../config/config.hpp"
#include "T3SendExpressFinishController.hpp"

#define kTitle "是否开启储物仓？"//标题显示的文字
#define kLeftImage ":images/choiceDialog/choiceYesBtn_normal.png"//左边按钮普通状态图标
#define kLeftPressImage ":images/choiceDialog/choiceYesBtn_pressed.png"//左边按钮点击状态图标
#define kRightImage ":images/choiceDialog/choiceNoBtn_normal.png"//右边按钮普通状态图标
#define kRightPressImage ":images/choiceDialog/choiceNoBtn_pressed.png"//右边按钮点击状态图标

T3SendExpressController::T3SendExpressController(T3BaseController *parent):
  T3ChoiceController(kTitle,kLeftImage,kLeftPressImage,kRightImage,kRightPressImage, parent)
{
//  setBackGround();

}
T3SendExpressController::~T3SendExpressController()
{

}

void T3SendExpressController::leftBtnEvent()
{
  qDebug() << "打开物流仓";
  qDebug() << "添加快递任务";
  qDebug() << "跳转到放件完成页面";
//  emit leftSignal();
  T3SendExpressFinishController *efc = new T3SendExpressFinishController(_parent);
  efc->showUI();
  this->hideUI();
}

void T3SendExpressController::rightBtnEvent()
{
  qDebug() << "继续寻找";
//  emit rightSignal();
}
