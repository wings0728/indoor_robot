/**
  ******************************************************************************
  * 公司    T3
  * 文件    T3DB.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.24
  * 说明
  ******************************************************************************
*/
#include "T3DB.hpp"

namespace interface
{
  T3DB * T3DB::getInstance()
  {
    static T3DB db;
    db.init();
    return &db;
  }

  void T3DB::init()
  {

  }

  bool T3DB::userIsSign(T3UserInfo &user)
  {
    T3AttendenceDB attendenceDB_;
    return attendenceDB_.selectSignIn(user);
  }

  bool T3DB::robotIsFree()
  {
      T3RobotStateDB robotStateDB_;
      model::T3RobotStateModel robotState_;
      robotStateDB_.getRobotState(robotState_);
      if(model::eRfree == robotState_.getState())
      {
        return true;
      }else
      {
        return false;
      }
  }
}
