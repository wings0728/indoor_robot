#ifndef T3TASKDATABASE_HPP
#define T3TASKDATABASE_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3TaskDatabase.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.19
  * 说明    任务列表数据库操作
  ******************************************************************************
*/

#include <QThread>
#include <QMutex>
#include <QMetaType>
#include "ros/ros.h"
#include "T3Database.hpp"
#include "T3UserInfoDatabase.h"
#include "../model/T3TaskModel.hpp"
namespace interface
{


class T3TaskDatabase : public QThread
{
  Q_OBJECT
public:
  static T3TaskDatabase* getInstance();

  ~T3TaskDatabase();
  /**
   * @brief startTaskSearch 开启任务查看线程
   */
  void startTaskSearch();
  /**
   * @brief addNewTask    向数据库中添加一条任务数据
   * @param task          [in]需要添加得任务
   * @return              返回值为0时表示添加成功,为负值时表示添加失败
   */
  int addNewTask(model::T3TaskModel &task);
  /**
   * @brief getTaskList   得到数据库里面所有得任务
   * @param taskList      [out]数据库中所有得任务数据
   * @return              返回值为0表示查询成功,返回负值表示查询失败.
   */
  int getTaskList(QList<model::T3TaskModel> &taskList);

  /**
   * @brief getTaskById  通过Id查询任务
   * @param id           [in]需要查询的任务id
   * @param task         [out]查询得到的任务
   * @return             返回值为0表示查询成功,返回负值表示查询失败.
   */
  int getTaskById(int id,
                  model::T3TaskModel& task);
  /**
   * @brief updateTask 更新任务数据,不更新id,其他数据都会更新为当前任务数据
   * @param task       需要更新的任务数据
   * @return           返回值为0时更新成功,返回负值时更新失败.
   */
  int updateTask(model::T3TaskModel task);
  /**
   * @brief finishTask  将任务状态更新为完成状态
   * @param task        需要更新的任务
   * @return            返回值为0时表示更新成功
   */
  int finishTask(model::T3TaskModel task);


signals:
  void newTask(model::T3TaskModel task);


private:
  void run();

  static T3TaskDatabase* _taskDB;
  explicit T3TaskDatabase();
  QMutex        _lock;
  bool          _isCanRun;
  int           _maxId;
  T3UserInfoDatabase _userinfoDB;

};
}

#endif // T3TASKDATABASE_HPP
