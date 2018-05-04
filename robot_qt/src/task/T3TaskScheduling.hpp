#ifndef T3TASKSCHEDULING_HPP
#define T3TASKSCHEDULING_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3TaskScheduling.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.19
  * 说明    任务调度类
  ******************************************************************************
*/

#include "T3Task.hpp"
#include "../T3base/T3IOBase.hpp"
#include "../model/T3TaskModel.hpp"
#include "../database/T3TaskDatabase.hpp"
#include "../database/T3GuideTaskDB.hpp"
#include "../database/T3ExpressTaskDB.hpp"
#include "../database/T3UserInfoDatabase.h"
namespace task
{

class T3TaskScheduling : public QObject
{
  Q_OBJECT
public:
  static T3TaskScheduling* getInstance();

  /**
   * @brief stopNowTask 外部调用方法直接将当前任务停止掉
   */
  void stopNowTask();

  ~T3TaskScheduling();

private:

  explicit T3TaskScheduling();
  /**
   * @brief initTaskScheduing 监听信号,并执行开始任务
   * @return
   */
  int initTaskScheduing();
  /**
   * @brief startTaskScheduling  开机之后需要执行的任务
   * @return
   */
  int startTaskScheduling();



  int runStak(model::T3TaskModel taskModel);

  static T3TaskScheduling       *_taskScheduling;
  interface::T3TaskDatabase     *_taskDB;
  T3Task                        *_task;

  QList<model::T3TaskModel>     _taskListZero;
  QList<model::T3TaskModel>     _taskListFirst;
  QList<model::T3TaskModel>     _taskListSecond;
  QList<model::T3TaskModel>     _taskListThird;
  bool                          _beTasking;
  model::T3TaskModel            _nowTask;


private slots:
  void getNewTask(model::T3TaskModel task);
  void taskFinish();
  void taskError(T3Task::eTaskErrorType taskError);
  void stanbyOver();
};

}


#endif // T3TASKSCHEDULING_HPP
