#include "T3VideoWidget.hpp"
#include "../config/config.hpp"

namespace T3View {

  T3VideoWidget::T3VideoWidget(QWidget *parent):
    QVideoWidget(parent)
  {

  }

  T3VideoWidget::T3VideoWidget(QWidget *parent,
                    int x,
                    int y,
                    int w,
                    int h
                    ):
    QVideoWidget(parent)
  {

    //size
    this->setGeometry(x, y, w, h);
  }





  T3VideoWidget::~T3VideoWidget()
  {}
}
