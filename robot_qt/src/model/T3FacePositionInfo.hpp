#ifndef robot_qt_T3FACEPOSITIONINFO_HPP
#define robot_qt_T3FACEPOSITIONINFO_HPP

/**
  ******************************************************************************
  * @file
  * @author     HXP
  * @version    V1.0.0
  * @date       2018/02/27
  * @brief      人脸识别之后确定人脸位置的框的相关坐标信息
  ******************************************************************************
*/


namespace model
{


class T3FacePositionInfo
{
public:
  T3FacePositionInfo();
  ~T3FacePositionInfo();

  void setLeft(int left);
  void setRight(int right);
  void setTop(int top);
  void setbottom(int bottom);

  int getLeft();
  int getRight();
  int getTop();
  int getBottom();



private:
  int _left ;      //左边界的X轴坐标
  int _right;      //右边界的X轴坐标
  int _top;        //上边界的Y轴坐标
  int _bottom;     //下边界的Y轴坐标
};
}
#endif
