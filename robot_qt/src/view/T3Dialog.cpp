#include "T3Dialog.hpp"
#include "../config/config.hpp"

namespace T3View {

  T3Dialog::T3Dialog(QWidget *parent):
    QDialog(parent)
  {
    initT3Dialog();
  }

  T3Dialog::T3Dialog(int x,
                    int y,
                    int w,
                    int h,
                    const QString &bgImagePath,
                    QWidget *parent):
    QDialog(parent)
  {
    initT3Dialog();
    this->setWindowTitle(QObject::tr(kAppTitle));
    //background
    this->setBackgroundWithImage(bgImagePath);
    //size
    this->setGeometry(x, y, w, h);
  }

  T3Dialog::T3Dialog(int x,
                    int y,
                    int w,
                    int h,
                    Qt::GlobalColor color,
                    QWidget *parent):
    QDialog(parent)
  {
    initT3Dialog();
    this->setWindowTitle(QObject::tr(kAppTitle));
    //background
    this->setBackgroundWithColor(color);
    //size
    this->setGeometry(x, y, w, h);
  }



  /**
   * @brief 设置dialog为对应背景色
   * @param color
   */
  void T3Dialog::setBackgroundWithColor(Qt::GlobalColor color)
  {
    QPalette pal(this->palette());
    //设置背景黑色
    pal.setColor(QPalette::Background, color);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
  }


  void T3Dialog::initT3Dialog()
  {
    //set dialog type
    this->setWindowFlags(Qt::FramelessWindowHint);
  }

  void T3Dialog::setBackgroundWithImage(QString imagePath)
  {
    QPalette palette;
    QPixmap pixmap(imagePath);
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setAutoFillBackground(true);
    this->setPalette(palette);
  }

  T3Dialog::~T3Dialog()
  {}
}
