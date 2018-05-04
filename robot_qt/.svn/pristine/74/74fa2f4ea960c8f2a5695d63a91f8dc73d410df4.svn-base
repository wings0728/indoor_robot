#include "T3WifiButton.hpp"
#include "../config/config.hpp"
namespace T3View {

T3WifiButton::T3WifiButton(QWidget *parent,
                           int n,
                           const QString &normalImage,
                           const QString &pressedImage,
                           QString wifiSSID,
                           bool encryptStatus,
                           int signalValue):
  T3Button(parent,
           kWifiBtn_X,
           kWifiBtn_Y+n*(kWifiBtn_H+13),
           kWifiBtn_W,
           kWifiBtn_H,
           normalImage,
           pressedImage)
{
  setWifiSSID(wifiSSID);
  setEncryptStatus(encryptStatus);
  setSignal(signalValue);
}

void T3WifiButton::setWifiSSID(QString wifiSSID)
{
  _wifiSSID = new T3View::T3Label(this,
                                  kWifiSSID_X,
                                  kWifiSSID_Y,
                                  kWifiSSID_W,
                                  kWifiSSID_H,
                                  wifiSSID,
                                  kTimeFontSize,
                                  kTimeFontStyle,
                                  kMainRGB,
                                  QFont::Normal,
                                  kMainTextFontSpace
                                  );
}
void T3WifiButton::setEncryptStatus(bool encryptStatus)
{
//  if(encryptStatus)
//  {

//  }
  _encryptStatus = new T3View::T3Label(this,
                                       kEncryptStatus_X,
                                       kEncryptStatus_Y,
                                       kEncryptStatus_W,
                                       kEncryptStatus_H,
                                       kEncryptStatusOn);
}
void T3WifiButton::setSignal(int signalValue)
{
//  switch (signalValue) {
//  case 0:

//    break;
//  case 1:

//    break;
//  case 2:

//    break;
//  case 3:

//    break;
//  default:
//    break;
//  }
  _signalValue = new T3View::T3Label(this,
                                     kSignalValue_X,
                                     kSignalValue_Y,
                                     kSignalValue_W,
                                     kSignalValue_H,
                                     kSignalValue3Path);
}
}
