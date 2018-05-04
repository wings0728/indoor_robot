#include "T3ExpressTaskDB.hpp"


namespace interface
{
T3ExpressTaskDB::T3ExpressTaskDB()
{
    _taskDB = T3TaskDatabase::getInstance();
}
int T3ExpressTaskDB::addNewExpressTask(model::T3ExpressTask &expressTask)
{

  QString id_ = QUuid::createUuid().toString();
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  expressTask.setId(id_);

  query_.prepare("insert into T3ExpressTask values(?,?,?,?,?,?)");


  query_.bindValue(0,id_);
  query_.bindValue(1,-1);
  query_.bindValue(2,expressTask.getReceiver().getID());
  query_.bindValue(3,"");
  query_.bindValue(4,-1);
  query_.bindValue(5,-1);
  int ret_ = query_.exec();
  T3DBConnectionPool::closeConnection(db_);
  _taskDB->addNewTask(expressTask);
  if(ret_)
  {

    return 0;

  }else
  {
    T3LOG << "insert ExpressTask failed";
    return -1;
  }

}

int T3ExpressTaskDB::getExpressTaskByTask(model::T3TaskModel &task,
                                          model::T3ExpressTask expressTask)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.prepare("select * from T3ExpressTask where id = ?");
  query_.bindValue(0,task.getId());
  bool ret_ = query_.exec();
  if(!ret_)
  {
    T3LOG << "search expressTask failed";
    return -1;
  }
  query_.next();
  int receiverId_ = query_.value(3).toInt();
  T3DBConnectionPool::closeConnection(db_);
  model::T3UserInfo receiver_;
  _userInfoDB.getUserInfoById(receiverId_,
                              receiver_);
  expressTask.setId(task.getId());
  expressTask.setType(task.getType());
  expressTask.setSender(task.getSender());
  expressTask.setPriority(task.getPriority());
  expressTask.setState(task.getState());
  expressTask.setReceiver(receiver_);

  return 0;
}
}

