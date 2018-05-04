#ifndef robot_qt_T3HARDWARE_HPP_
#define robot_qt_T3HARDWARE_HPP_

#include "../T3base/T3IOBase.hpp"
#include "../ros/qnode.hpp"
#include <QObject>
/**
  ******************************************************************************
  * @file
  * @author     Jincheng
  * @version    V1.0.0
  * @date       2018/04/24
  * @brief      硬件操作接口
  ******************************************************************************
*/

namespace interface
{
enum eHardwareType
{
    eSweeper,          //扫地机
    ePrinter,          //打印机
    eProjector,        //投影仪
    eHumidifier,       //加湿器
    eSixMicrophone,    //六麦克风
    eExpressGate       //快递门
};
enum eHardwareState
{
    eOpen,
    eClose
};
class T3Hardware : public QObject
{
  Q_OBJECT
public:

  T3Hardware();
  static T3Hardware* getInstance();
  ~T3Hardware();

  void oprationSweeper(eHardwareState state);//扫地机
  void oprationProjector(eHardwareState state);//投影仪
  void oprationHumidifier(eHardwareState state);//加湿器
  void oprationHead(int angle);//云台
  void oprationLED();//led
  void oprationVoice(QString str);//语音

  void openSixMicrophone();//打开六麦克风
  void openExpressGate();//打开仓门

signals:
  void expressGateClosed();//快递仓门关闭信号
  void sixMicrophoneWakeup(int angle);//6麦克风被唤醒信号

private slots:
  void getMicrophoneFB(int angle);

private:
  QNode* _qnode;

  bool _isInit;

  void init();

};
}

#endif
