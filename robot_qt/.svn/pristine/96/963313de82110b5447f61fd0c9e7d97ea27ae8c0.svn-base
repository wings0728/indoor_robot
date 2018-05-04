#ifndef T3WIFIBUTTON_HPP
#define T3WIFIBUTTON_HPP
#include "T3Button.hpp"
#include "T3Label.hpp"

/**
  ******************************************************************************
  * @file
  * @author  孔志伟
  * @version  V1.0.0
  * @date    2018/04/24
  * @brief   wifi
  ******************************************************************************
*/
namespace T3View {

class T3WifiButton:public T3Button
{
  Q_OBJECT
public:
  explicit T3WifiButton(QWidget *parent,
                        int n,
                        const QString &normalImage,
                        const QString &pressedImage,
                        QString wifiSSID,
                        bool encryptStatus,
                        int signalValue);

  T3Label *_wifiSSID;
  T3Label *_encryptStatus;
  T3Label *_signalValue;

  void setWifiSSID(QString wifiSSID);
  void setEncryptStatus(bool encryptStatus);
  void setSignal(int signalValue);
};
}
#endif // T3WIFIBUTTON_HPP
