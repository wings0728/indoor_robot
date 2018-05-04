/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3BaseController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#include "T3BaseController.hpp"
#include "../../config/config.hpp"

#define kBackBtnNormalImage "://images/mainBackBtn_normal.png"
#define kBackBtnPressedImage "://images/mainBackBtn_pressed.png"

T3BaseController::T3BaseController(int x,
                                   int y,
                                   int w,
                                   int h,
                                   const QString &bgPath,
                                   bool showBackIcon,
                                   T3BaseController *parent):
  _parent(parent)
{
  _backBtn = NULL;
  setBackground(x, y, w, h, bgPath);
  setBackBtn(showBackIcon);
}

T3BaseController::~T3BaseController()
{
  if(_backBtn != NULL)
  {
    delete _backBtn;//返回按钮
    _backBtn = NULL;
  }
  if(_window != NULL)
  {
    delete _window;//底层背景
    _window = NULL;
  }
}

void T3BaseController::setBackground(int x, int y, int w, int h, const QString &bgPath)
{
  _window = new T3View::T3Dialog(x,
                                 y,
                                 w,
                                 h,
                                 bgPath);
}

void T3BaseController::setBackBtn(bool showBackIcon)
{
  if(true == showBackIcon)
  {
    this->_backBtn = new T3View::T3Button(_window,
                                    kBackBtnX_bc,
                                    kBackBtnY_bc,
                                    kBackBtnW_bc,
                                    kBackBtnH_bc,
                                    kBackBtnNormalImage,
                                    kBackBtnPressedImage);
    connect(this->_backBtn, SIGNAL(clicked(bool)), SLOT(backToParent()));

  }

}

void T3BaseController::showUI()
{
  if((this->_window->isHidden()))
  {
    this->_window->show();
    showUIdo();
  }
}

void T3BaseController::showUIdo()
{

}

void T3BaseController::hideUI()
{
  if(!(this->_window->isHidden()))
  {
    this->_window->hide();
  }
}

/******* slots *********/
void T3BaseController::backToParent()
{
  this->hideUI();
  _parent->showUI();
  delete this;
}
void T3BaseController::backToStandBy()
{

}
