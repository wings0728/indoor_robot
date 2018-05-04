#ifndef robot_qt_MAINCONTROLLER_HPP_
#define robot_qt_MAINCONTROLLER_HPP_

#include <QObject>
#include "../view/T3Dialog.hpp"
#include "../face/T3FaceScan.h"
#include "T3WaitController.hpp"
#include "../network/T3Network.h"
#include "../task/T3TaskScheduling.hpp"
#include "../database/T3TaskDatabase.hpp"
#include "../network/T3Wifi.hpp"
#include "../database/T3RobotStateDB.hpp"
#include <QUuid>

class T3MainController : public QObject
{
  Q_OBJECT
public:
  explicit T3MainController();
  ~T3MainController();
  /**
   * 运行
   */
  void run();

private:
  /**
   * 初始化所有单例
   */
  void initInstance();

  /**
   * 所有底层界面
   */
  void showUnderground();

  /**
   * @brief loadNewFace  测试人脸识别添加人脸数据
   * @return
   */
  int loadNewFace();

  T3WaitController *_hsc;

  //单例
  interface::T3FaceScan       *_faceScan;
  interface::T3Camera         *_camera;
  interface::T3Face           *_face;
  interface::T3Database       *_database;
  interface::T3Network        *_network;
  task::T3TaskScheduling      *_taskSchedu;
  interface::T3TaskDatabase   *_taskDB;
  interface::QNode            *_rosNode;

  //T3BaseController *_bc;
  //T3View::T3WifiButton *_wifiBtn;
  T3Wifi *_wifi;
};

#endif
