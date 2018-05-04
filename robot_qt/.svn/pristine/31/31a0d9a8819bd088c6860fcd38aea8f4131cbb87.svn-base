#include "T3SixMicrophone.hpp"

namespace interface {


T3SixMicrophone::T3SixMicrophone()
{
  _serialportIsOpen = false;
}

T3SixMicrophone* T3SixMicrophone::_sixMicrophone = NULL;
QMutex T3SixMicrophone::_mutex;

T3SixMicrophone* T3SixMicrophone::getInstance()
{
  if(NULL == _sixMicrophone)
  {
    QMutexLocker locker(&_mutex);
    if(NULL == _sixMicrophone)
    {
      _sixMicrophone = new T3SixMicrophone();
    }
  }
  return _sixMicrophone;
}
T3SixMicrophone::~T3SixMicrophone()
{
  if(NULL != _sixMicrophone)
  {
    delete _sixMicrophone;
    _sixMicrophone = NULL;
  }
}

void T3SixMicrophone::initSeriport()
{
  _serialport.setBaudRate(kSerialportBaudRateSixMic);
  _serialport.setDataBits(QSerialPort::Data8);
  _serialport.setFlowControl(QSerialPort::NoFlowControl);

  QSerialPortInfo info_;
  QList<QSerialPortInfo> infos_ = QSerialPortInfo::availablePorts();
  foreach (info_, infos_)
  {
    T3LOG << info_.portName();
  }
  _connectSerialportTimer.start(4000);
  connect(&_connectSerialportTimer,
          &QTimer::timeout,
          this,
          &T3SixMicrophone::openSerialport);
}

void T3SixMicrophone::openSerialport()
{
  _serialport.setPortName(kSerialportNameSixMic);
  if(_serialport.open(QIODevice::ReadWrite))
  {
    T3LOG << "sixMicrophone serialport open success";
    _connectSerialportTimer.stop();
    connect(&_serialport,
            &QSerialPort::readyRead,
            this,
            &T3SixMicrophone::serialportRead);
    _serialportIsOpen = true;
  }else
  {
    _serialport.close();
    T3LOG << "sixMicrophone serialport not open";
  }
}

void T3SixMicrophone::serialportRead()
{
    QString message_ = _serialport.readAll();
}

 void T3SixMicrophone::openCall()
 {

 }

 void T3SixMicrophone::closeCall()
 {

 }
}
