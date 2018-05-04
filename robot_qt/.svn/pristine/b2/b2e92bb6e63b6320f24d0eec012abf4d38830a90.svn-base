#ifndef T3POSEDB_HPP
#define T3POSEDB_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3PoseDB.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.23
  * 说明    位置数据库操作
  ******************************************************************************
*/

#include "../model/T3Pose.hpp"
#include "../database/T3Database.hpp"

namespace interface
{


class T3PoseDB
{
public:
  explicit T3PoseDB();
  ~T3PoseDB();

  /**
   * @brief addNewPose 添加一个新的位置
   * @param pose       位置信息
   * @return           返回值为正值时表示添加的记录的Id,为负值时表示添加失败
   */
  int addNewPose(T3Pose &pose);

  /**
   * @brief getPoseById  根据Id查询Pose
   * @param id           [in] id
   * @param pose         [out] 查询到得位置信息
   * @return             返回值为0时表示查询成功,为负值时表示查询失败
   */
  int getPoseById(int id,
                  T3Pose &pose);



};
}

#endif // T3POSEDB_HPP
