#include "T3Button.hpp"

namespace T3View {
  void T3Button::init()
  {
    _textColorRGB = "";
    _imagePathPressed = "";
    _imagePathNormal = "";
    this->setFocusPolicy(Qt::NoFocus);
    connect(this, SIGNAL(clicked(bool)), SLOT(t3BtnSlot()));
  }

  T3Button::T3Button(QWidget *parent,
                     int x,
                     int y,
                     int w,
                     int h,
                     const QString &normalImage,
                     const QString &pressedImage,
                     const QString &text,
                     int fontSize,
                     const QString &fontType,
                     const QString &color,
                     QFont::Weight weight,
                     int space):
    QPushButton(parent)
  {

    init();
    this->setGeometry(x, y, w, h);
    this->setButtonImage(normalImage,
                         pressedImage);
    this->setButtonTextWithRGB(text, fontSize, color, fontType, space, weight);
    this->setBtnStyle();

  }

  T3Button::T3Button(QWidget *parent,
                     int x,
                     int y,
                     int w,
                     int h,
                     const QString &normalImage,
                     const QString &pressedImage):
    QPushButton(parent)
  {
    init();
    this->setGeometry(x, y, w, h);
    this->setButtonImage(normalImage,
                         pressedImage);
    this->setBtnStyle();
  }
  T3Button::T3Button(QWidget* parent):
    QPushButton(parent)
  {

  }

  void T3Button::setButtonImage(const QString &normalImagePath, const QString &pressedImagePath)
  {
    _imagePathNormal = normalImagePath;
    _imagePathPressed = pressedImagePath;
//    QString styleStr;
//    _style += "QPushButton{border-image: url("+normalImagePath+");color: rgb(40, 220, 160);}QPushButton:pressed{border-image: url("+pressedImagePath+");color: rgb(40, 220, 160);}";
//    this->setStyleSheet(styleStr);
    if(_textColorRGB != "")
    {
      _style = "QPushButton{border-image: url("+normalImagePath+");color: rgb("+ _textColorRGB +");}QPushButton:pressed{border-image: url("+pressedImagePath+");color: rgb("+ _textColorRGB +");}";
    }else
    {
      _style = "QPushButton{border-image: url("+normalImagePath+");}QPushButton:pressed{border-image: url("+pressedImagePath+");}";
    }
    setBtnStyle();
  }

  void T3Button::setButtonText(const QString &text, int fontSize, Qt::GlobalColor textColor, const QString &fontFamily, int fontSpace, QFont::Weight fontWeight)
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
  }

  void T3Button::setButtonTextWithRGB(const QString &text, int fontSize, const QString &color, const QString &fontFamily, int fontSpace, QFont::Weight fontWeight)
  {
    this->setText(text);
    QFont ft;
    ft.setPointSize(fontSize);
    ft.setFamily(fontFamily);
    ft.setLetterSpacing(QFont::PercentageSpacing, fontSpace);
    ft.setWeight(fontWeight);
    this->setFont(ft);
    _textColorRGB = color;
    _style = "QPushButton{border-image: url("+_imagePathNormal+");color: rgb("+ _textColorRGB +");}QPushButton:pressed{border-image: url("+_imagePathPressed+");color: rgb("+ _textColorRGB +");}";
    setBtnStyle();
  }

  void T3Button::setBtnStyle()
  {
//    _style += "QPushButton{border-image: url("+_imagePathNormal+");color: rgb("+ _textColorRGB +");}QPushButton:pressed{border-image: url("+_imagePathPressed+");color: rgb("+ _textColorRGB +");}";
    this->setStyleSheet(_style);
  }

  /******** slot **********/
  void T3Button::t3BtnSlot()
  {
    emit t3BtnSignal(this->_btnTag);
  }

  /******** get set **********/
  void T3Button::setTag(int tag)
  {
    _btnTag = tag;
  }
  int T3Button::getTag()
  {
    return _btnTag;
  }

  T3Button::~T3Button()
  {}
}
