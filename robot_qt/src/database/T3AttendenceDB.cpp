#include "T3AttendenceDB.hpp"


namespace interface
{
T3AttendenceDB::T3AttendenceDB()
{

}
int T3AttendenceDB::addNewAttendence(model::T3AttendenceModel &attendence)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.prepare("insert into T3Attendence values(NULL,?,?,?)");
  query_.bindValue(0,attendence.getUserInfo().getID());
  query_.bindValue(1,attendence.getTime());
  query_.bindValue(2,attendence.getState());
  int ret_ = query_.exec();
  if(ret_)
  {

    query_.exec("select max(id) from T3Attendence");
    query_.next();
    int ret_ = query_.value(0).toInt();
    T3DBConnectionPool::closeConnection(db_);
    return ret_;

  }else
  {
    T3LOG << "insert attendence failed";
    return -1;
  }

}
bool T3AttendenceDB::selectSignIn(model::T3UserInfo userInfo)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.prepare("select * from T3Attendence where date(Time) = curdate() and UserInfoId = ?");
  query_.bindValue(0,userInfo.getID());
  query_.exec();
  bool ret_ = query_.next();
  T3DBConnectionPool::closeConnection(db_);
  return ret_;
}
}

