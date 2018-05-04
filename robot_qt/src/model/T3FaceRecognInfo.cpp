#include "T3FaceRecognInfo.hpp"
namespace model
{


T3FaceRecognInfo::T3FaceRecognInfo()
{
  _faceNum = -1;

}

T3FaceRecognInfo::~T3FaceRecognInfo()
{

}

void T3FaceRecognInfo::setFaceNum(int faceNum)
{
  _faceNum = faceNum;
}

void T3FaceRecognInfo::setFacePositionList(QList<T3FacePositionInfo>& facePositionList)
{
  _facePositionList = facePositionList;
}

void T3FaceRecognInfo::setUserInfoList(QList<T3UserInfo>& userInfoList)
{
  _userInfoList = userInfoList;
}

int T3FaceRecognInfo::getFaceNum()
{
  return _faceNum;
}

QList<T3FacePositionInfo>& T3FaceRecognInfo::getFacePositionList()
{
  return _facePositionList;
}
QList<T3UserInfo>& T3FaceRecognInfo::getUserInfoList()
{
  return _userInfoList;
}
}
