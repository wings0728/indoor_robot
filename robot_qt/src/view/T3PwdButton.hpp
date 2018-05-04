#ifndef T3PWDBUTTON_H
#define T3PWDBUTTON_H
#include "T3Button.hpp"
namespace T3View {
  enum eT3Pwd {
    pwd_0 = 0,
    pwd_1,
    pwd_2,
    pwd_3,
    pwd_4,
    pwd_5,
    pwd_6,
    pwd_7,
    pwd_8,
    pwd_9,
    pwd_back,
    pwd_enter
  };

class T3PwdButton : public T3Button {
  Q_OBJECT

public:



  explicit T3PwdButton(QWidget *parent,
                    int x,
                    int y,
                    int w,
                    int h,
                    const QString &normalImage,
                    const QString &pressedImage,
                    eT3Pwd pwdCode);

  ~T3PwdButton();

  /**
   * @brief 获取密码框所代表的内容
   * @return
   */
  eT3Pwd getPwdCode();

private:
  eT3Pwd _pwdCode;

signals:
  void clickedWithPwd(T3View::eT3Pwd pwd);

private slots:
  void pwdClicked();

}; //class
} //namespace
#endif // T3PwdButton
