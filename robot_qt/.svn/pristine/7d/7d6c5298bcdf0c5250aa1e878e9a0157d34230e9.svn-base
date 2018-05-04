#ifndef T3POSITIONDB_HPP
#define T3POSITIONDB_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3PositionDB.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.23
  * 说明    地点数据库操作类
  ******************************************************************************
*/

#include "T3Database.hpp"
#include "T3PoseDB.hpp"
#include "../model/T3PositionModel.hpp"


namespace interface
{

class T3PositionDB
{
public:
  explicit T3PositionDB();
  ~T3PositionDB();
  /**
   * @brief addNewPosition 添加一个新的地点
   * @param position       [int]地点
   * @return               返回值为正值时表示添加的记录的Id,为负值时表示添加失败
   */
  int addNewPosition(T3PositionModel& position);
  /**
   * @brief selectPositionById   通过Id查找position
   * @param id                   [in] 需要查找的地点的Id
   * @param position             [out] 通过Id查找的position
   * @return                      返回值为0时表示查询成功,为负值时表示查询失败
   */
  int getPositionById(int id,
                         T3PositionModel& position);


private:
    T3PoseDB _poseDB;
};
}


#endif // T3POSITIONDB_HPP
