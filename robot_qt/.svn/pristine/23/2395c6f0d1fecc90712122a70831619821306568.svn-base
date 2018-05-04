#ifndef T3AVNETWORK_H
#define T3AVNETWORK_H


#include <QUdpSocket>
#include <QHostAddress>
#include <QByteArray>
#include <QDataStream>
#include <QObject>
#include "../T3base/T3IOBase.hpp"

/**
  ******************************************************************************
  * @file
  * @author  HXP
  * @version  V1.0.0
  * @date    2018/04/04
  * @brief   视频传输网络接口
  ******************************************************************************
*/

namespace interface
{

enum frameType
{
    T3VideoNet,
    T3AudioNet
};
class T3AVNetwork : public QObject
{
    Q_OBJECT
public:
    static T3AVNetwork* getInstance();

    ~T3AVNetwork();
    /**
     * @brief sentDataByUDP 通过UDP协议传输音视频数据
     * @param data          音视频二进制数据 视频采用H264,音频采用PCM
     * @param type          数据类型,音频或者视频.
     * @return
     */
    int sentDataByUDP(QByteArray data,
                      frameType type);


signals:
    /**
     * @brief sendVideoData 获得视频数据
     * @param videoData     视频数据,格式为H264
     */
    void sendVideoData(QByteArray videoData);

    /**
     * @brief sendAudioData 获得音频数据
     * @param audioData     音频数据,格式为PCM,
     */
    void sendAudioData(QByteArray audioData);

private:

    static T3AVNetwork    *_avNetwork;
    QUdpSocket            *_udpSocket;
    int                   _sign;
    QByteArray            _frameData;

    T3AVNetwork();

    void readDataByUDP();

    int readTheUDPData(QByteArray data);
};

}

#endif // T3AVNETWORK_H
