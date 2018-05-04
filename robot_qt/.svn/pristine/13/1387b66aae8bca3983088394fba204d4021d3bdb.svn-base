#include "T3PoseDB.hpp"


namespace interface
{


T3PoseDB::T3PoseDB()
{

}

T3PoseDB::~T3PoseDB()
{

}

int T3PoseDB::addNewPose(T3Pose &pose)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.prepare("insert into T3Pose values(NULL,?,?,?)");
  query_.bindValue(0,pose.getX());
  query_.bindValue(1,pose.getY());
  query_.bindValue(2,pose.getZ());
  int ret_ = query_.exec();
  if(ret_)
  {

    query_.exec("select max(id) from T3Pose");
    query_.next();
    int ret_ = query_.value(0).toInt();
    T3DBConnectionPool::closeConnection(db_);
    return ret_;

  }else
  {
    T3LOG << "insert pose failed";
    return -1;
  }


}

int T3PoseDB::getPoseById(int id,
                          T3Pose &pose)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.prepare("select * from T3Pose where id = ?");
  query_.bindValue(0,id);
  bool ret_ = query_.exec();
  if(!ret_)
  {
    T3LOG << "search Pose failed";
    return -1;
  }
  query_.next();
  T3DBConnectionPool::closeConnection(db_);
  double x_ = query_.value(1).toDouble();
  double y_ = query_.value(2).toDouble();
  double z_ = query_.value(3).toDouble();

  pose.setX(x_);
  pose.setY(y_);
  pose.setZ(z_);

  return 0;

}
}
