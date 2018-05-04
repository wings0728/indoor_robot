#ifndef T3SIXMICROPHONE_HPP
#define T3SIXMICROPHONE_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3SixMicrophone.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.05.03
  * 说明    六麦克风阵列相关操作
  ******************************************************************************
*/
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMutex>
#include <QMutexLocker>
#include <QObject>
#include <QTimer>

#include "../config/config.hpp"

namespace interface {


class T3SixMicrophone : public QObject
{
  Q_OBJECT
public:
  /**
   * @brief getInstance 单例
   * @return
   */
  static T3SixMicrophone* getInstance();

  ~T3SixMicrophone();
  /**
   * @brief openCall 开启通话模式
   */
  void openCall();
  /**
   * @brief closeCall 关闭通话模式
   */
  void closeCall();


private:
  /**
   * @brief initSeriport 初始化串口
   */
  void initSeriport();


  explicit T3SixMicrophone();

  bool _serialportIsOpen;
  static T3SixMicrophone* _sixMicrophone;
  static QMutex _mutex;
  QSerialPort _serialport;
  QTimer _connectSerialportTimer;


private slots:
  /**
   * @brief openSerialport  周期调用,直到打开串口停止.
   */
  void openSerialport();
  /**
   * @brief serialportRead 接收串口上发的信号
   */
  void serialportRead();
};
}
#endif // T3SIXMICROPHONE_HPP
