#ifndef T3ATTENDENCEMODEL_HPP
#define T3ATTENDENCEMODEL_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3AttendenceModel.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.23
  * 说明    考勤数据模型
  ******************************************************************************
*/

#include <QDateTime>
#include "T3UserInfo.hpp"

namespace model
{

enum eAttendenceState
{
  eANormal,
  eALate,
  eALeaveEarly,
  eAabsent
};


class T3AttendenceModel
{
public:
  T3AttendenceModel();

  void setId(int id);
  void setUserInfo(T3UserInfo& userInfo);
  void setTime(QDateTime time);
  void setState(eAttendenceState state);

  int getId();
  T3UserInfo& getUserInfo();
  QDateTime getTime();
  eAttendenceState getState();

private:
  int _id;
  T3UserInfo _userInfo;
  QDateTime _time;
  eAttendenceState _state;

};

}


#endif // T3ATTENDENCEMODEL_HPP
