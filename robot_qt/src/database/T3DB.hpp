/**
  ******************************************************************************
  * 公司    T3
  * 文件    T3DB.hpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.24
  * 说明
  ******************************************************************************
*/
#ifndef T3DB_HPP
#define T3DB_HPP

#include "../T3base/T3IOBase.hpp"
#include "../model/T3UserInfo.hpp"
#include "T3Database.hpp"
#include "T3RobotStateDB.hpp"
#include "T3AttendenceDB.hpp"

namespace interface
{
using namespace model;
  class T3DB : public T3IOBase
  {
  public:
    static T3DB * getInstance();
    bool userIsSign(T3UserInfo &user);//获取是否签到
    bool robotIsFree();//判断机器人是否处于空闲

  private:
    void init();
  };
}

#endif
