#ifndef T3BUTTON_H
#define T3BUTTON_H
#include <QPushButton>
namespace T3View {
class T3Button : public QPushButton {
  Q_OBJECT

public:
  //set text button with image
  explicit T3Button(QWidget *parent,
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
                    int space);

  explicit T3Button(QWidget *parent,
                    int x,
                    int y,
                    int w,
                    int h,
                    const QString &normalImage,
                    const QString &pressedImage);


  explicit T3Button(QWidget *parent);


  ///
  /// \brief set button background image
  /// \param image path
  ///
  void setButtonImage(const QString &normalImagePath, const QString &pressedImagePath);

  ///
  /// \brief set button text
  /// \param set text
  /// \param set font size
  /// \param set text color
  ///
  void setButtonText(const QString &text, int fontSize, Qt::GlobalColor textColor, const QString &fontFamily, int fontSpace, QFont::Weight fontWeight);
  void setButtonTextWithRGB(const QString &text, int fontSize, const QString &color, const QString &fontFamily, int fontSpace, QFont::Weight fontWeight);
  ~T3Button();

//唯一标识的get set方法
  void setTag(int tag);
  int getTag();

signals:
  void t3BtnSignal(int tag);

private slots:
  void t3BtnSlot();

private:
  QString _imagePathNormal;
  QString _imagePathPressed;
  QString _textColorRGB;
  QString _style;
  //每个按钮的唯一标识
  int _btnTag;

  void init();
  void setBtnStyle();



}; //class
} //namespace
#endif // T3LABEL_H
