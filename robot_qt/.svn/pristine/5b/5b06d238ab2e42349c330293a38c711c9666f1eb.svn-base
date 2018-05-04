
#include "T3GifLabel.hpp"

namespace T3View {
T3GifLabel::T3GifLabel(QWidget *parent,
                 int x,
                 int y,
                 int w,
                 int h,
                 QString gif):
  T3Label(parent,
          x,
          y,
          w,
          h)
{
  this->hide();
  this->_gifObj = new QMovie(gif);
  this->setMovie(_gifObj);
}

void T3GifLabel::startGIF()
{
  this->_gifObj->start();
}

void T3GifLabel::startGIFWithShow()
{
  this->show();
  this->_gifObj->start();
}

void T3GifLabel::stopGIF()
{
  this->_gifObj->stop();
}

void T3GifLabel::stopGIFWithHide()
{
  this->hide();
  this->_gifObj->stop();
}

  T3GifLabel::~T3GifLabel()
  {
    delete _gifObj;
  }
}
