#ifndef robot_qt_T3POSE_HPP_
#define robot_qt_T3POSE_HPP_

#include "T3BaseModel.hpp"

class T3Pose
{
public:
  explicit T3Pose(double x, double y, double z);
  explicit T3Pose();
  ~T3Pose();

  void setX(double x);
  void setY(double Y);
  void setZ(double Z);

  double getX();
  double getY();
  double getZ();
private:
  double _x;
  double _y;
  double _z;//方向
};

#endif
