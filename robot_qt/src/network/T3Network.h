#ifndef T3NETWORK_H
#define T3NETWORK_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QUdpSocket>
#include <QDataStream>


#include "../T3base/T3IOBase.hpp"

/**
  ******************************************************************************
  * @file
  * @author  HXP
  * @version  V1.0.0
  * @date    2018/04/11
  * @brief   网络连接接口
  ******************************************************************************
*/

namespace interface
{
class T3Network : public QObject
{
  Q_OBJECT
public:
  static T3Network* getInstance();
  ~T3Network();

signals:
  void emitIP(QString ip);

private:
  T3Network();

  static T3Network* _network;
  QTcpServer        *_server;
  QTcpSocket        *_socket;
  QUdpSocket        *_udpSocket;
  QString           _IP;
  int               _type;

  void initNetwork();

  QString getHostIPAddress();

  void sendTheIPToClient();

private slots:
  void getNewConnected();

  void getTheUDPMessage();

  void heartBeat();
};
}



#endif // T3NETWORK_H
