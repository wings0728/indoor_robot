/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3BaseController.hpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#ifndef robot_qt_BASECONTROLLER_HPP_
#define robot_qt_BASECONTROLLER_HPP_
#include <QObject>
#include "../../view/T3Dialog.hpp"
#include "../../view/T3Button.hpp"

class T3BaseController : public QObject {
  Q_OBJECT
public:
  /**
   * @brief T3BaseController
   * @x 背景图片的x
   * @y 背景图片的y
   * @w 背景图片的宽度
   * @h 背景图片的高度
   * @bgPath 背景图片的路径
   * @showBackIcon 是否显示返回按钮
   * @parent 此控制器的父控制器
   */
  explicit T3BaseController(int x,
                            int y,
                            int w,
                            int h,
                            const QString &bgPath,
                            bool showBackIcon = true,
                            T3BaseController *parent = 0);
  ~T3BaseController();
  /**
   * @brief 显示此控制器对应的UI界面
   */
  void showUI();
  /**
   * @brief 隐藏此控制器对应的UI界面
   */
  void hideUI();

protected:
  T3BaseController *_parent;//父控制器
  T3View::T3Dialog *_window;//底层背景
  T3View::T3Button *_backBtn;//返回按钮

  /**
   * @brief showUIdo  展示页面的时候需要调用得操作.
   */
  virtual void showUIdo();

protected slots:
  void backToParent();//返回按钮的槽

  void backToStandBy();//返回待机界面

private:
  void setBackground(int x, int y, int w, int h, const QString &bgPath);
  void setBackBtn(bool showBackIcon);
};

#endif
