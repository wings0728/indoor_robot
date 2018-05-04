#include "T3AVNetwork.h"


namespace interface
{

T3AVNetwork::T3AVNetwork()
{
    _udpSocket = new QUdpSocket(this);
    _sign = 0;
    _udpSocket->bind(8888,QUdpSocket::ShareAddress);
    connect(_udpSocket,
            &QUdpSocket::readyRead,
            this,
            &T3AVNetwork::readDataByUDP);
}

T3AVNetwork* T3AVNetwork::_avNetwork = new T3AVNetwork();

T3AVNetwork* T3AVNetwork::getInstance()
{

  return _avNetwork;
}

T3AVNetwork::~T3AVNetwork()
{

}
int T3AVNetwork::sentDataByUDP(QByteArray data,
                             frameType type)
{

    switch (type) {
    case T3VideoNet:
        _sign = 1;
        break;
    case T3AudioNet:
        _sign = 2;
        break;
    default:
        _sign = 0;
        break;
    }

    QByteArray block_;
    QDataStream stream_(&block_,QIODevice::WriteOnly);
    stream_.setVersion(QDataStream::Qt_5_5);

    stream_ << (int) 0;
    stream_ << (int) _sign;
    stream_ << data;
    stream_.device()->seek(0);
    stream_ << (int) block_.size();

    int ret_ = _udpSocket->writeDatagram(block_.data(),
                              block_.size(),
                              QHostAddress("192.168.0.192"),
                              8888);
     T3LOG << "send the udp data" << _sign << block_.size();
    return ret_;
}


void T3AVNetwork::readDataByUDP()
{
    T3LOG << "data";
    while(_udpSocket->hasPendingDatagrams())
    {
        QByteArray data;
        data.resize(_udpSocket->pendingDatagramSize());
        _udpSocket->readDatagram(data.data(),data.size());
        readTheUDPData(data);
    }
}

int T3AVNetwork::readTheUDPData(QByteArray data)
{
    QDataStream stream_(&data,QIODevice::ReadOnly);
    int size_ = 0;
    stream_ >> size_;
    stream_ >> _sign;
    stream_ >> _frameData;
    T3LOG << "get the udp data" << size_ << _sign ;
    switch (_sign) {
    case 1:
        emit sendVideoData(_frameData);
        break;
    case 2:
        emit sendAudioData(_frameData);
        break;
    default:
        break;
    }
}
}

