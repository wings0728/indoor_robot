#ifndef robot_qt_POSITIONMODEL_HPP_
#define robot_qt_POSITIONMODEL_HPP_

#include "T3BaseModel.hpp"
#include "T3Pose.hpp"

class T3PositionModel : public T3BaseModel
{
public:
  T3PositionModel();
  T3PositionModel(QString name,
                  T3Pose &pose);

  void setId(int id);
  void setPoseName(QString poseName);
  void setPose(T3Pose& pose);

  int getId();
  QString getPoseName();
  T3Pose& getPose();

private:
  int _id;
  QString _poseName;
  T3Pose _pose;
};

#endif
