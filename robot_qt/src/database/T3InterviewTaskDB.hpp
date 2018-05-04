#ifndef T3INTERVIEWTASKDB_HPP
#define T3INTERVIEWTASKDB_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3InterviewTaskDB.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.25
  * 说明    面试任务数据库操作
  ******************************************************************************
*/
#include "T3Database.hpp"
#include "T3GuideTaskDB.hpp"
#include "../model/T3TaskModel.hpp"

namespace interface
{
class T3InterviewTaskDB
{
public:
  T3InterviewTaskDB();

  /**
   * @brief addNewInterviewTask  添加一个新的面试任务
   * @param interviewTask        [in]面试任务数据
   * @return                     返回值为正值时表示添加的记录的Id,为负值时表示添加失败
   */
  int addNewInterviewTask(model::T3InterviewTask &interviewTask);

  int getInterViewTaskByTask(model::T3TaskModel &task,
                             model::T3InterviewTask &interviewTask);


private:
  T3TaskDatabase      *_taskDB;
};
}


#endif // T3INTERVIEWTASKDB_HPP
