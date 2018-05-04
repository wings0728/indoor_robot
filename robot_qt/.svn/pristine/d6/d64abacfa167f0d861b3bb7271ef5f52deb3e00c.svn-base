
#include "T3Label.hpp"

namespace T3View {

T3Label::T3Label(QWidget *parent,
                            int x,
                            int y,
                            int w,
                            int h,
                            const QString &text,
                            int fontSize,
                            const QString &fontType,
                            const QString &color,
                            QFont::Weight weight,
                            int space
                            ):
  QLabel(parent)
{
  this->setGeometry(x, y, w, h);
  setLabelTextWithRGB(text, fontSize, color, fontType, space, weight);
}

  T3Label::T3Label(QWidget *parent,
                   int x,
                   int y,
                   int w,
                   int h,
                   const QString &text,
                   int fontSize,
                   const QString &fontType,
                   Qt::GlobalColor color,
                   QFont::Weight weight,
                   int space
                   ):
    QLabel(parent)
  {
    this->setGeometry(x, y, w, h);
    this->setLabelText(text, fontSize, color, fontType, space, weight);
  }

  T3Label::T3Label(QWidget *parent,
                   int x,
                   int y,
                   int w,
                   int h,
                   const QString &imagePath
                   ):
    QLabel(parent)
  {
    this->setGeometry(x, y, w, h);
    this->setLabelImage(imagePath);
  }

  T3Label::T3Label(QWidget *parent,
                              int x,
                              int y,
                              int w,
                              int h):
    QLabel(parent)
  {
    this->setGeometry(x, y, w, h);

  }

  T3Label::T3Label(QWidget *parent):
    QLabel(parent)
  {}

  void T3Label::setLabelImage(const QString &imageName)
  {

     QString _path = "border-image:url(" + imageName + ")";
     this->setStyleSheet(_path);
  }

  void T3Label::setLabelText(const QString &text, int fontSize, Qt::GlobalColor textColor, const QString &fontFamily, int fontSpace, QFont::Weight fontWeight)
  {
    this->setText(text);
    QFont ft;
    ft.setPointSize(fontSize);
    ft.setFamily(fontFamily);
    ft.setLetterSpacing(QFont::PercentageSpacing, fontSpace);
    ft.setWeight(fontWeight);
    this->setFont(ft);
    QPalette pa;
    pa.setColor(QPalette::WindowText, textColor);
    this->setPalette(pa);
    this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  }

  void T3Label::setLabelTextWithRGB(const QString &text, int fontSize, const QString &rgb, const QString &fontFamily, int fontSpace, QFont::Weight fontWeight)
  {
    this->setText(text);
    QFont ft;
    ft.setPointSize(fontSize);
    ft.setFamily(fontFamily);
    ft.setLetterSpacing(QFont::PercentageSpacing, fontSpace);
    ft.setWeight(fontWeight);
    this->setFont(ft);
//    QPalette pa;
//    pa.setColor(QPalette::WindowText, textColor);
//    this->setPalette(pa);
    QString style = "color: rgb(" + rgb +");";
//    color: rgb(241, 70, 62);
    setStyleSheet(style);
    this->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
  }

//  void T3Label::paintEvent(QPaintEvent *event)
//  {
//    emit labelUpdate();
//  }

  T3Label::~T3Label()
  {}
}
