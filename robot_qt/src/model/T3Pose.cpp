#include "T3Pose.hpp"

T3Pose::T3Pose(double x, double y, double z)
{
  _x = x;
  _y = y;
  _z = z;
}

T3Pose::T3Pose()
{
  _x = 0;
  _y = 0;
  _z = 0;
}

T3Pose::~T3Pose()
{

}

void T3Pose::setX(double  x)
{
  _x = x;
}

double  T3Pose::getX()
{
  return _x;
}

void T3Pose::setY(double  y)
{
  _y = y;
}

double  T3Pose::getY()
{
  return _y;
}

void T3Pose::setZ(double z)
{
  _z = z;
}

double T3Pose::getZ()
{
  return _z;
}
