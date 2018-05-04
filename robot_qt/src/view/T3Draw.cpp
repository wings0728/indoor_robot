#include "T3Draw.hpp"
#include <QPainter>

namespace T3View {

T3Draw::T3Draw(QWidget *parent) :
    QWidget(parent)
{

}
 void T3Draw::paintEvent(QPaintEvent * event)
 {
     QPainter painter(this);
     //painter.drawLine(QPoint(0,0),QPoint(100,100));
     QImage *pimage = new QImage ("/home/kzw/catkin_ws/src/robot_qt/resources/室内机器人UI界面/5/ditu2.png") ;
     //painter.drawImage(pimage->rect(),*pimage);

 }
}
