#include "T3Network.h"


namespace interface
{
T3Network::T3Network()
{
  _socket = NULL;
  _server = NULL;
  _udpSocket = NULL;

}

T3Network::~T3Network()
{

}
T3Network* T3Network::_network = new T3Network();

T3Network* T3Network::getInstance()
{
  _network->initNetwork();
  return _network;
}

void T3Network::initNetwork()
{

  _udpSocket = new QUdpSocket();
  _udpSocket->bind(QHostAddress::Any,kUDPIPPort);
  connect(_udpSocket,
          &QUdpSocket::readyRead,
          this,
          &T3Network::getTheUDPMessage);

  _server = new QTcpServer();
  _server->listen(QHostAddress::Any,kNetworkPort);
  connect(_server,
          &QTcpServer::newConnection,
          this,
          &T3Network::getNewConnected);
  T3LOG << "init network success";
}

void T3Network::getNewConnected()
{
  if(_socket != NULL)
  {
    _socket->abort();
  }
  _socket = _server->nextPendingConnection();


}

QString T3Network::getHostIPAddress()
{
  QString strIPAddress_;
  QList<QHostAddress> ipAddressList_ = QNetworkInterface::allAddresses();
  int nListSize = ipAddressList_.size();
  for (int i = 0; i < nListSize; ++i)
  {
         if (ipAddressList_.at(i) != QHostAddress::LocalHost &&
             ipAddressList_.at(i).toIPv4Address()) {
             strIPAddress_ = ipAddressList_.at(i).toString();
             break;
         }
   }
   // 如果没有找到，则以本地IP地址为IP
   if (strIPAddress_.isEmpty())
      strIPAddress_ = QHostAddress(QHostAddress::LocalHost).toString();
   return strIPAddress_;
}

void T3Network::getTheUDPMessage()
{
  T3LOG << "get the udp data";
  while(_udpSocket->hasPendingDatagrams())
  {
      QByteArray data;
      data.resize(_udpSocket->pendingDatagramSize());
      _udpSocket->readDatagram(data.data(),data.size());
      QDataStream stream_(&data,QIODevice::ReadOnly);
      int size_ = 0;
      stream_ >> size_;
      stream_ >> _IP;
      stream_ >> _type;
      T3LOG << "get the udp data" << size_ << _IP  << _type ;
      if(1 == _type)
      {
        emit emitIP(_IP);
      }
      sendTheIPToClient();

  }
}

void T3Network::sendTheIPToClient()
{

  QString ip_ = getHostIPAddress();
  QByteArray block_;
  QDataStream stream_(&block_,QIODevice::WriteOnly);
  stream_.setVersion(QDataStream::Qt_5_5);

  stream_ << (int) 0;
  stream_ << ip_;
  stream_.device()->seek(0);
  stream_ << (int) block_.size();

  int ret_ = _udpSocket->writeDatagram(block_.data(),
                            block_.size(),
                            QHostAddress(_IP),
                            8888);
}

void T3Network::heartBeat()
{
    QByteArray block_ ;
    QDataStream stream_(&block_,QIODevice::WriteOnly);
    stream_.setVersion(QDataStream::Qt_5_5);
    stream_ << (quint32)sizeof(quint32);
    stream_ << (quint32) 1 ;
    _socket->write(block_);
    T3LOG << "hearBeat";
}

}

