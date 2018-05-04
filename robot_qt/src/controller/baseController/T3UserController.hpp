/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3UserController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#ifndef robot_qt_USERCONTROLLER_HPP_
#define robot_qt_USERCONTROLLER_HPP_
#include "T3BaseController.hpp"
#include "../../view/T3Label.hpp"

class T3UserController :public T3BaseController {
  Q_OBJECT
public:

  explicit T3UserController(const QString &bgPath, bool showBackIcon = false, T3BaseController *parent = 0);
  ~T3UserController();
  /**
   * @brief 如果不是按钮，只需要不填写pressed图片的路径即可
   * @param firstPath_normal
   * @param firstPath_pressed
   * @param secondPath_normal
   * @param secondPath_pressed
   * @param thirdPath_normal
   * @param secondPath_pressed
   */
//  void setIcon(const QString &firstPath_normal, const QString &firstPath_pressed,
//               const QString &secondPath_normal, const QString &secondPath_pressed,
//               const QString &thirdPath_normal, const QString &secondPath_pressed);

protected:
  T3View::T3Label *_battaryIcon;
  T3View::T3Label *_bluetoothIcon;
  T3View::T3Label *_wifiIcon;


private slots:
  void updateTime();

private:
  T3View::T3Label *_timeLabel;
  QString _timeStr;

  void updateTimeStr();
  void setTimeLabel();
  void setStateLabel();
  void setupQTime();
};

#endif
