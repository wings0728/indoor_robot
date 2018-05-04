#ifndef robot_qt_T3FACERECOGNINFO_HPP
#define robot_qt_T3FACERECOGNINFO_HPP
#include <QList>
#include "T3FacePositionInfo.hpp"
#include "T3UserInfo.hpp"

/**
  ******************************************************************************
  * @file
  * @author     HXP
  * @version    V1.0.0
  * @date       2018/02/27
  * @brief      通过视频帧数据识别到的得相关信息
  ******************************************************************************
*/
namespace model
{


class T3FaceRecognInfo
{
public:
    T3FaceRecognInfo();
    ~T3FaceRecognInfo();

    void setFaceNum(int faceNum);
    void setFacePositionList(QList<T3FacePositionInfo> &facePositionList);
    void setUserInfoList(QList<T3UserInfo> &userInfoList);

    int getFaceNum();
    QList<T3FacePositionInfo>& getFacePositionList();
    QList<T3UserInfo> &getUserInfoList();

private:
    int _faceNum ;     //一帧视频中出现的人脸数
    QList<T3FacePositionInfo> _facePositionList ;  //人脸位置列表
    QList<T3UserInfo> _userInfoList ;  //识别到的用户信息

};
}
#endif
