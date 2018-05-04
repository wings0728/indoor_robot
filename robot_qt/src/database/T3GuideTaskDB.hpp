#ifndef T3GUIDETASKDB_HPP
#define T3GUIDETASKDB_HPP
/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3GuideTaskDB.hpp
  * 作者    HXP
  * 版本    V1.0.0
  * 日期    2018.04.25
  * 说明    引导任务数据库操作类
  ******************************************************************************
*/

#include <QDataStream>
#include <QIODevice>
#include <QList>
#include "T3Database.hpp"
#include "T3PositionDB.hpp"
#include "T3TaskDatabase.hpp"
#include "../model/T3TaskModel.hpp"

namespace interface
{


class T3GuideTaskDB
{
public:
  T3GuideTaskDB();

  /**
   * @brief addNewGuideTask 添加一个引导任务
   * @param guideTask       [in]引导任务数据
   * @return                返回值为0时表示添加成功,为负值时表示添加失败
   */
  int addNewGuideTask(model::T3GuideTask guideTask);

  /**
   * @brief getGuideTaskModelByTask   根据任务查询相应任务
   * @param task                      [in] 主任务模型
   * @param guideTask                 [out] 查询到的引导任务
   * @return                          返回值为0时表示查询成功,为负值时表示查询失败
   */
  int getGuideTaskModelByTask(model::T3TaskModel& task,
                                model::T3GuideTask& guideTask);


private:
  /**
   * @brief QListToByteArray    将路径数组转换为QByteArray便于数据库存储
   * @param plan                [in]路径数据
   * @param planByteArray       [out]二进制数组
   * @return                    返回值为0时表示转换成功.
   */
  int QListToByteArray(QList<std::pair<double,double> >& plan,
                       QByteArray& planByteArray);
  /**
   * @brief QByteArrayToQList  将二进制数据转换为QList
   * @param planBytaArray      [in] 需要转换的路径数据
   * @param plan               [out]转换的到得数据
   * @return                   返回值为0时表示转换成功.
   */
  int QByteArrayToQList(QByteArray planBytaArray,
                        QList<std::pair<double,double> >& plan);


  T3PositionDB        _positionDB ;
  T3TaskDatabase      *_taskDB;
};
}
#endif // T3GUIDETASKDB_HPP
