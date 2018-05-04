#ifndef T3WIFI_HPP
#define T3WIFI_HPP
/**
  ******************************************************************************
  * @file
  * @author  孔志伟
  * @version  V1.0.0
  * @date    2018/04/24
  * @brief   wifi
  ******************************************************************************
*/

#include "../controller/baseController/T3UserController.hpp"
#include <QProcess>
#include "../view/T3WifiButton.hpp"
class T3Wifi:public T3UserController
{
  Q_OBJECT
public:
  T3Wifi();

private:
//  struct sT3Wifi
//  {
//    QString wifi[50];
//    QString wifiSSID[50];
//    int signalValue[50];
//    bool encryptStatus[50];
//    int length;
//  };

  void init();
  void setWifiButton();
  void saveWifiList();
  QString inputPassword();
  //void saveWifi();//将已连接的wifi保存
  //void closeWifi();

  QProcess *_process;
  T3View::T3Label *_label;
  T3View::T3WifiButton *_wifiButton[5];
  T3View::T3Label *_wifiBox;
  T3View::T3Button *_upBtn;
  T3View::T3Button *_downBtn;

  int _index;//第一个wifi位置的wifi序号

  QStringList _wifiList;
  QString _wifi[50];
  QString _wifiSSID[50];
  int _signalValue[50];
  bool _encryptStatus[50];
  int _length;

private slots:
  void clickUpBtn();
  void clickDownBtn();

  void readOut();
  void searchWifi();
  void connectWifi();
  void connecting();
  void connectStatus();


};

#endif // T3WIFI_HPP
