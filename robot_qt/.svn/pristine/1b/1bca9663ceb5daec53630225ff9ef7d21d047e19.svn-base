#include "T3InterviewTaskDB.hpp"


namespace interface
{
T3InterviewTaskDB::T3InterviewTaskDB()
{
  _taskDB = T3TaskDatabase::getInstance();
}

int T3InterviewTaskDB::addNewInterviewTask(model::T3InterviewTask &interviewTask)
{

  QString id_ = QUuid::createUuid().toString();
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  interviewTask.setId(id_);

  query_.prepare("insert into T3InterviewTask values(?,?,?,?,?,?)");


  query_.bindValue(0,id_);
  query_.bindValue(1,-1);
  query_.bindValue(2,-1);
  query_.bindValue(3,interviewTask.getInterviewDate());
  query_.bindValue(4,-1);
  query_.bindValue(5,-1);
  int ret_ = query_.exec();
  T3DBConnectionPool::closeConnection(db_);
  _taskDB->addNewTask(interviewTask);
  if(ret_)
  {

    return 0;

  }else
  {
    T3LOG << "insert InterviewTask failed";
    return -1;
  }
}


int T3InterviewTaskDB::getInterViewTaskByTask(model::T3TaskModel &task,
                                              model::T3InterviewTask &interviewTask)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.prepare("select * from T3InterviewTask where id = ?");
  query_.bindValue(0,task.getId());
  bool ret_ = query_.exec();
  if(!ret_)
  {
    T3LOG << "search expressTask failed";
    return -1;
  }
  query_.next();
  QDateTime interviewDate_ = query_.value(4).toDateTime();
  T3DBConnectionPool::closeConnection(db_);
  interviewTask.setId(task.getId());
  interviewTask.setType(task.getType());
  interviewTask.setSender(task.getSender());
  interviewTask.setPriority(task.getPriority());
  interviewTask.setState(task.getState());
  interviewTask.setInterviewDate(interviewDate_);

  return 0;
}
}

