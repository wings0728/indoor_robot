/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3ChoiceController.hpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#ifndef robot_qt_CHOICECONTROLLER_HPP_
#define robot_qt_CHOICECONTROLLER_HPP_
#include "T3BaseController.hpp"
#include "../../view/T3Label.hpp"
#include "../../view/T3Button.hpp"

class T3ChoiceController :public T3BaseController {
  Q_OBJECT
public:
  /**
   * @brief T3ChoiceController
   * @titleText 标题名称
   * @leftImage 左边按钮图标路径
   * @leftPressImage 左边按钮图标被点击后的路径
   * @rightImage 右边按钮图标路径
   * @rightPressImage 右边按钮图标被点击后的路径
   * @parent 父控制器
   */
  explicit T3ChoiceController(const QString &titleText,
                              const QString &leftImage,
                              const QString &leftPressImage,
                              const QString &rightImage,
                              const QString &rightPressImage,
                              T3BaseController *parent = 0);
//用于给子类重写左右按钮点击事件
  virtual void leftBtnEvent(){}
  virtual void rightBtnEvent(){}



private slots:
  void leftClick();
  void rightClick();

private:
  T3View::T3Label *_title;
  T3View::T3Button *_leftBtn;
  T3View::T3Button *_rightBtn;

  void setBackground();
  void setTitle(const QString &text);
  void setBtn(const QString &leftImage,
              const QString &leftPressImage,
              const QString &rightImage,
              const QString &rightPressImage);

};

#endif
