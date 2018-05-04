#ifndef T3ROBOTSTATEDB_HPP
#define T3ROBOTSTATEDB_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3RobotStateDB.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.26
  * 说明    机器人状态数据库操作
  ******************************************************************************
*/
#include "T3Database.hpp"
#include "T3PositionDB.hpp"
#include "T3UserInfoDatabase.h"
#include "../model/T3RobotStateModel.hpp"
#include "T3PositionDB.hpp"
#include "../ros/qnode.hpp"
namespace interface
{
class T3RobotStateDB
{
public:
  T3RobotStateDB();
  /**
   * @brief addRobotState 添加机器人状态
   * @return
   */
  int updateRobotState();

  int addRobotState();

  int getRobotState(model::T3RobotStateModel& robotState);



  T3PositionDB _positionDB;
  T3UserInfoDatabase _userInfoDB;
};
}



#endif // T3ROBOTSTATEDB_HPP
