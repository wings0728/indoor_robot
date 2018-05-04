#include "T3TaskScheduling.hpp"


namespace task
{
T3TaskScheduling::T3TaskScheduling()
{
    _beTasking = false;
}

T3TaskScheduling* T3TaskScheduling::_taskScheduling = new T3TaskScheduling();

T3TaskScheduling* T3TaskScheduling::getInstance()
{

  _taskScheduling->initTaskScheduing();
  return _taskScheduling;
}

T3TaskScheduling::~T3TaskScheduling()
{

}
//停止当前任务,现在主要用于机器人本机界面任务的停止.
void T3TaskScheduling::stopNowTask()
{

  T3LOG << "taskscheduing stop nowtask";

  model::T3TaskModel taskModel(model::eTShowUI);
  _nowTask = taskModel;
  _beTasking = false;
  taskFinish();

}

int T3TaskScheduling::initTaskScheduing()
{
  _taskDB = interface::T3TaskDatabase::getInstance();
  //监听任务数据库,当有新的任务插入的时候,读取到任务队列里面
  connect(_taskDB,
          &interface::T3TaskDatabase::newTask,
          this,
          &T3TaskScheduling::getNewTask);
  _task = T3Task::getInstance();
  //任务完成信号
  connect(_task,
          &T3Task::taskFinish,
          this,
          &T3TaskScheduling::taskFinish);
  //任务出错信号
  connect(_task,
          &T3Task::taskError,
          this,
          &T3TaskScheduling::taskError);
  //待机结束信号
  connect(_task,
          &T3Task::stanbyOver,
          this,
          &T3TaskScheduling::stanbyOver);
    startTaskScheduling();

}

int T3TaskScheduling::startTaskScheduling()
{

    model::T3SignTask sign_;
    _task->runTask(sign_);
    model::T3StandbyTask standby_;
    _task->runTask(standby_);
    _nowTask = standby_;

}


void T3TaskScheduling::getNewTask(model::T3TaskModel task)
{
  T3LOG << "get new Task";
  if(task.getType() > model::eTHardware && task.getType() <= model::eTShowUI)
  {
    switch (task.getPriority())
    {
    case 0:
       _taskListZero.append(task);
      break;
    case 1:
      _taskListFirst.append(task);
      break;
    case 2:
      _taskListSecond.append(task);
      break;
    case 3:
      _taskListThird.append(task);
      break;
    default:
      T3LOG << "not support the task priority";
      break;
    }
    if(!_beTasking)
    {
      taskFinish();
    }
    return ;
  }
  if(task.getType() < model::eTHardware)
  {
    _task->runTask(task);
  }
}

int T3TaskScheduling::runStak(T3TaskModel taskModel)
{

  //当前任务为空闲任务并且将要执行的任务为堵塞式任务时,执行别的任务之前,先将当前空闲任务结束掉.
  if(_nowTask.getType() >= eTStandby && taskModel.getType() > model::eTHardware)
  {
    _task->stopTask(_nowTask);
  }
  _nowTask = taskModel;
  model::eTaskType state_ = taskModel.getType();
  T3GuideTaskDB taskDB_;
  model::T3GuideTask guideTask_;
  T3ExpressTaskDB expressDB_;
  model::T3ExpressTask expressTask_;
  switch (state_) {
  case eTGuide:

      taskDB_.getGuideTaskModelByTask(taskModel,
                                   guideTask_);
      T3LOG << (int)guideTask_.getType();
      _task->runTask(guideTask_);
    break;
  case eTExpress:
      expressDB_.getExpressTaskByTask(taskModel,
                                      expressTask_);
      _task->runTask(expressTask_);
    break;
  default:
    break;
  }
}


void T3TaskScheduling::taskFinish()
{

    _beTasking = true;
    _taskDB->finishTask(_nowTask);
    if(_taskListZero.length() > 0)
    {
      runStak(_taskListZero.at(0));
      _taskListZero.removeFirst();
      return ;
    }
    if(_taskListFirst.length() > 0)
    {
      runStak(_taskListFirst.at(0));
      _taskListFirst.removeFirst();
      return ;
    }
    if(_taskListSecond.length() > 0)
    {
      runStak(_taskListSecond.at(0));
      _taskListSecond.removeFirst();
      return ;
    }
    if(_taskListThird.length() > 0)
    {
      runStak(_taskListThird.at(0));
      _taskListThird.removeFirst();
      return ;
    }

    _beTasking = false;
    model::T3TaskModel standby_(eTStandby);
    _task->runTask(standby_);
    model::T3TaskModel origin_(eTOrigin);
    _task->runTask(origin_);
}

void T3TaskScheduling::taskError(T3Task::eTaskErrorType taskError)
{
  interface::T3UserInfoDatabase userInfoDB_;
  model::T3UserInfo robotSelf_;
  userInfoDB_.getRobotSelf(robotSelf_);
  model::T3ModeChangeTask modeChangeTask_(robotSelf_,interface::QNode::Manual);
  switch (taskError) {
  case T3Task::eGuide_Error:

        _task->runTask(modeChangeTask_);
    break;
  default:
    break;
  }
}

void T3TaskScheduling::stanbyOver()
{
  T3LOG << "standby over slot";
  model::T3TaskModel taskModel(model::eTShowUI);
  _nowTask = taskModel;
  _beTasking = true;
}

}

