#ifndef T3LABEL_H
#define T3LABEL_H
#include <QLabel>
namespace T3View {
class T3Label : public QLabel {
  Q_OBJECT

public:
  //set text label
  explicit T3Label(QWidget *parent,
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
                              );
//set text label with RGB
  explicit T3Label(QWidget *parent,
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
                              );
  //set image label
  explicit T3Label(QWidget *parent,
                              int x,
                              int y,
                              int w,
                              int h,
                              const QString &imagePath
                              );

  explicit T3Label(QWidget *parent,
                              int x,
                              int y,
                              int w,
                              int h);

  explicit T3Label(QWidget *parent = 0);
~T3Label();
//  void paintEvent(QPaintEvent *event);

protected:
  ///
  /// \brief set label background image
  /// \param image path
  ///
  void setLabelImage(const QString &imageName);

  ///
  /// \brief set label text
  /// \param set text
  /// \param set font size
  /// \param set text color
  ///
  void setLabelText(const QString &text, int fontSize, Qt::GlobalColor textColor, const QString &fontFamily, int fontSpace, QFont::Weight fontWeight);
  void setLabelTextWithRGB(const QString &text, int fontSize, const QString &rgb, const QString &fontFamily, int fontSpace, QFont::Weight fontWeight);


//signals:
//  void labelUpdate();

}; //class
} //namespace
#endif // T3LABEL_H
