#include "T3TaskDatabase.hpp"


namespace interface
{


T3TaskDatabase::T3TaskDatabase()
{
  _maxId = 0 ;
  _isCanRun = true;
  qRegisterMetaType<model::T3TaskModel> ("model::T3TaskModel");
}
T3TaskDatabase* T3TaskDatabase::_taskDB = new T3TaskDatabase();

T3TaskDatabase* T3TaskDatabase::getInstance()
{
  return _taskDB;
}

void T3TaskDatabase::startTaskSearch()
{
  _taskDB->start();
}

T3TaskDatabase::~T3TaskDatabase()
{

}

int T3TaskDatabase::addNewTask(model::T3TaskModel &task)
{


    QSqlDatabase db_ = T3DBConnectionPool::openConnection();
    QSqlQuery query_(db_);
    query_.prepare("insert into T3Robot.T3Task values(?,?,?,?,?,NULL)");
    query_.bindValue(0,task.getId());
    query_.bindValue(1,task.getType());
    query_.bindValue(2,task.getSender().getID());
    query_.bindValue(3,task.getPriority());
    query_.bindValue(4,task.getState());
    int ret_ = query_.exec();
    T3DBConnectionPool::closeConnection(db_);
    if(ret_)
    { 
      return 0;
    }else
    {
      T3LOG << "insert task failed";
      return -1;
    }
}

int T3TaskDatabase::getTaskList(QList<model::T3TaskModel> &taskList)
{

}

int T3TaskDatabase::getTaskById(int id,
                                model::T3TaskModel &task)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.prepare("select * from T3Task where taskId = ?");
  query_.bindValue(0,id);
  bool ret_ = query_.exec();
  if(!ret_)
  {
    T3LOG << "search task failed";
    return -1;
  }
  query_.next();
  QString id_ = query_.value(0).toString();
  model::eTaskType type_ =static_cast<model::eTaskType>(query_.value(1).toInt());
  int senderId_ = query_.value(2).toInt();
  model::T3UserInfo userInfo_;
  _userinfoDB.getUserInfoById(senderId_,
                              userInfo_);
  int priority_ = query_.value(3).toInt();
  model::eTaskState state_ = static_cast<model::eTaskState>(query_.value(4).toInt());
  T3DBConnectionPool::closeConnection(db_);
  task.setId(id_);
  task.setPriority(priority_);
  task.setState(state_);
  task.setType(type_);
  task.setSender(userInfo_);


}

void T3TaskDatabase::run()
{
  ros::Rate loop_rate(1);
  while(true)
  {
    T3LOG << "run";
    QSqlDatabase db_ = T3DBConnectionPool::openConnection();
    QSqlQuery query_(db_);
    model::T3TaskModel task_;
    query_.exec("select min(taskId), max(taskId) from T3Task where State = 2");
    //query_.prepare("select * from T3Task where State = 2");
    //query_.bindValue(0,static_cast<int>(model::eTNotStart));
    query_.next();

    int minId_ = query_.value(0).toInt();
    int maxId_ = query_.value(1).toInt();
    T3DBConnectionPool::closeConnection(db_);
     T3LOG << minId_;
     T3LOG << maxId_;
    if(_maxId < maxId_)
    {
      for(int i = minId_;i<=maxId_;i++)
      {
        _maxId = i;
        getTaskById(minId_,
                    task_);
        emit newTask(task_);

      }


    }
    QMutexLocker locker_(&_lock);
    if(!_isCanRun)
    {
      return ;
    }
    loop_rate.sleep();
  }

}

int T3TaskDatabase::finishTask(model::T3TaskModel task)
{
  QSqlDatabase db_ = T3DBConnectionPool::openConnection();
  QSqlQuery query_(db_);
  query_.prepare("update T3Task set State = ? where Id = ?");
  query_.bindValue(0,model::eTFinish);
  query_.bindValue(1,task.getId());
  T3LOG << task.getId();
  bool ret_ = query_.exec();
  T3DBConnectionPool::closeConnection(db_);
  if(ret_)
  {

    return 0;
  }else {
    T3LOG << "update task database failed";
    return -1;
  }
}

int T3TaskDatabase::updateTask(model::T3TaskModel task)
{

}

}

