#ifndef T3EXPRESSTASKDB_HPP
#define T3EXPRESSTASKDB_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3ExpressTaskDB.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.25
  * 说明    快递任务数据库操作类
  ******************************************************************************
*/
#include "../model/T3TaskModel.hpp"
#include "T3Database.hpp"
#include "T3TaskDatabase.hpp"
#include "T3UserInfoDatabase.h"

namespace interface
{
class T3ExpressTaskDB
{
public:
  T3ExpressTaskDB();

  /**
   * @brief addNewExpressTask  添加一个快递任务
   * @param expressTask        [in]快递任务数据
   * @return                    返回值为正值时表示添加的记录的Id,为负值时表示添加失败
   */
  int addNewExpressTask(model::T3ExpressTask &expressTask);

  /**
   * @brief getExpressTaskByTask  得到一个快递任务
   * @param task                  [in]任务信息
   * @param expressTask           [out]快递任务信息
   * @return                      返回值为0时表示查询成功,为负值时表示查询失败
   */
  int getExpressTaskByTask(model::T3TaskModel &task,
                           model::T3ExpressTask expressTask);


private:
  T3TaskDatabase          *_taskDB;
  T3UserInfoDatabase      _userInfoDB;
};
}


#endif // T3EXPRESSTASKDB_HPP
