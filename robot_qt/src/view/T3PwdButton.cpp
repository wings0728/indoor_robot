#include "T3PwdButton.hpp"

namespace T3View {
T3PwdButton::T3PwdButton(QWidget *parent,
                  int x,
                  int y,
                  int w,
                  int h,
                  const QString &normalImage,
                  const QString &pressedImage,
                  eT3Pwd pwdCode):
  T3Button(parent,
           x,
           y,
           w,
           h,
           normalImage,
           pressedImage)
{
  _pwdCode = pwdCode;
  connect(this,SIGNAL(clicked()),this,SLOT(pwdClicked()));
}

void T3PwdButton::pwdClicked()
{
  emit clickedWithPwd(this->_pwdCode);
}

/********* get set **********/
  eT3Pwd T3PwdButton::getPwdCode()
  {
    return this->_pwdCode;
  }

  T3PwdButton::~T3PwdButton()
  {}
}
