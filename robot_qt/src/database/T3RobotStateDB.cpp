#include "T3RobotStateDB.hpp"

namespace interface
{
T3RobotStateDB::T3RobotStateDB()
{

}

int T3RobotStateDB::updateRobotState()

{

}


int T3RobotStateDB::addRobotState()
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.exec("select max(Id) from T3RobotState");
  query_.next();
  if(1 == query_.value(0).toInt())
  {
    return 1;
  }

  int id_ = 1;
  T3Pose pose_(0,0,0);
  T3PositionModel nowPoint_;
  nowPoint_.setPoseName("当前点");
  nowPoint_.setPose(pose_);
  T3PositionModel chargePoint_;
  chargePoint_.setPoseName("充电点");
  chargePoint_.setPose(pose_);
  T3PositionModel originPoint_;
  originPoint_.setPoseName("原点");
  originPoint_.setPose(pose_);

  int nowPointId_ = _positionDB.addNewPosition(nowPoint_);
  int chargePointId_ = _positionDB.addNewPosition(chargePoint_);
  int originPointId_ = _positionDB.addNewPosition(originPoint_);
  int robotSelfId_ = _userInfoDB.insertRobotSelf();

  query_.prepare("insert into T3RobotState values(?,?,?,?,?,?,?,?,?)");
  query_.bindValue(0,id_);
  query_.bindValue(1,nowPointId_);
  query_.bindValue(2,0.0);
  query_.bindValue(3,0);
  query_.bindValue(4,"");
  query_.bindValue(5,chargePointId_);
  query_.bindValue(6,originPointId_);
  query_.bindValue(7,0);
  query_.bindValue(8,robotSelfId_);
  int ret_ = query_.exec();
  if(ret_)
  {

    query_.exec("select max(id) from T3RobotState");
    query_.next();
    int ret_ = query_.value(0).toInt();
    T3DBConnectionPool::closeConnection(db_);
    return ret_;

  }else
  {
    T3LOG << "insert robotState failed";
    return -1;
  }


}

int T3RobotStateDB::getRobotState(model::T3RobotStateModel &robotState)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.exec("select * from T3RobotState where id = 1");
  query_.next();
  int nowPoseId_ = query_.value(1).toInt();
  float velocity_ = query_.value(2).toFloat();
  int batteryLife_ = query_.value(3).toInt();
  QString ip_ = query_.value(4).toString();
  int chargePointId_ = query_.value(5).toInt();
  int originPointId_ = query_.value(6).toInt();
  int state_ = query_.value(7).toInt();
  T3DBConnectionPool::closeConnection(db_);

  T3PositionModel chargePoint_;
  T3PositionDB positionDB_;
  positionDB_.getPositionById(chargePointId_,
                              chargePoint_);
  T3PositionModel originPoint_;
  positionDB_.getPositionById(originPointId_,
                              originPoint_);

  robotState.setVelocity(velocity_);
  robotState.setBatteryLife(batteryLife_);
  robotState.setIP(ip_);
  robotState.setChargePoint(chargePoint_);
  robotState.setOriginPoint(originPoint_);
  robotState.setState(static_cast<model::eRobotState>(state_));
}
}


