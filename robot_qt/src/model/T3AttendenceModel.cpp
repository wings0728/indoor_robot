#include "T3AttendenceModel.hpp"


namespace model
{
T3AttendenceModel::T3AttendenceModel()
{

}

void T3AttendenceModel::setId(int id)
{
  _id = id;
}

int T3AttendenceModel::getId()
{
  return _id;
}

void T3AttendenceModel::setUserInfo(T3UserInfo& userInfo)
{
  _userInfo = userInfo;
}

T3UserInfo& T3AttendenceModel::getUserInfo()
{
  return _userInfo;
}

void T3AttendenceModel::setTime(QDateTime time)
{
  _time = time;
}

QDateTime T3AttendenceModel::getTime()
{
  return _time;
}

void T3AttendenceModel::setState(eAttendenceState state)
{
  _state = state;
}

eAttendenceState T3AttendenceModel::getState()
{
  return _state;
}
}

