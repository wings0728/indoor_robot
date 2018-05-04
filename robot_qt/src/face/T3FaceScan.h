#ifndef T3FACESCAN_H
#define T3FACESCAN_H
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3FaceScan.h
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.24
  * 说明    人脸扫描类
  ******************************************************************************
*/

#include <QThread>
#include <QMutex>
#include <QTimer>
#include <QMap>
#include <QMetaType>
#include "../T3base/T3IOBase.hpp"
#include "T3Face.hpp"
#include "../hardware/T3Camera.hpp"
#include "../model/T3FaceRecognInfo.hpp"
#include "../tool/T3VideoDecoder.h"
#include "../config/config.hpp"
#include "../database/T3UserInfoDatabase.h"

namespace interface
{

class T3FaceScan :public QThread
{
  Q_OBJECT
public:
    static T3FaceScan* getInstance();

    ~T3FaceScan();
    /**
     * @brief stopFaceScan 停止人脸识别扫描
     */
    void stopFaceScan();

    /**
     * @brief startMatchPeople 开始匹配某个特定的人员
     * @param user             需要匹配的人员信息
     * @return                 返回值为0的时候表示设置成功
     */
    int startMatchPeople(model::T3UserInfo &user);
    /**
     * @briintef stopMatchPeople   停止匹配指定人员
     * @return                     返回值为0时表示停止成功
     */
     int stopMatchPeople();

signals:
    /**
   * @brief getNewFace  当检测到人脸出现的时候,发出次信号,当画面中出现多张人脸的时候,发出的人脸信息时面积最大得一个
   * @param userInfo    探测到得人脸信息
   */
  void getNewFace(model::T3UserInfo& userInfo);

  /**
   * @brief noFace  当画面中没有人一定时间之后发出此信号
   */
  void noFace();

  /**
   * @brief matchPeople 当匹配到指定人员的时候发出此信号
   */
  void matchPeople();


  void detechFaceSign();

private:
    static T3FaceScan* _faceScan;

    /**
     * @brief startFaceScan 开始进行人脸识别扫描
     * @return
     */
    bool startFaceScan();

    /**
     * @brief selectMaxFace   在识别到得人脸位置信息中选择最大的一个
     * @param recognInfo      [in]识别的人脸位置信息
     * @param positionInfo    [out]最大的那个人脸位置
     */
    void selectMaxFace(model::T3FaceRecognInfo& recognInfo,
                       model::T3FaceRecognInfo& maxRecognInfo);


    bool checkFaceBeChange(model::T3FaceRecognInfo &oldFaceRecognInfo,
                           model::T3FaceRecognInfo &newFaceRecognInfo);




    T3Face                        *_face;
    T3Camera                      *_camera;
    QByteArray                    _YUYVFrameData;
    tool::T3VideoDecoder          *_videoDecoder;
    model::T3FaceRecognInfo       _faceRecognInfo;
    model::T3FaceRecognInfo       _oldFaceRecognInfo;
    bool                          _faceScanBeReady;
    QMutex                        _lock;
    bool                          _isCanRun;
    int                           _frameIndex;
    int                           _guideIndex;
    bool                          _faceChange;
    QList<model::T3UserInfo>      _userInfoList;
    QTimer                        *_noFaceTimer;
    QMap<int,int>                 _faceInfoMap;
    model::T3UserInfo             _guideModel;
    T3UserInfoDatabase            _userInfoDB;

    void run();

    T3FaceScan();


    void initInstance();



    int computeOverlapArea(int leftA,
                       int bottomA,
                       int rightA,
                       int topA,
                       int leftB,
                       int bottomB,
                       int rightB,
                       int topB);

private slots:
    void emitNoFace();

    void detechFaceSlot();


};
}
#endif // T3FACESCAN_H
