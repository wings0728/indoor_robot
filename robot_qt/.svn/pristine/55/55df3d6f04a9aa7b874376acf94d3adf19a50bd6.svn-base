#ifndef robot_qt_T3WIDGET_HPP_
#define robot_qt_T3WIDGET_HPP_
#include <QDialog>
namespace T3View {
class T3Dialog : public QDialog {
  Q_OBJECT

public:
  explicit T3Dialog(QWidget *parent = 0);

  //set dialog with background Image
  explicit T3Dialog(int x,
                    int y,
                    int w,
                    int h,
                    const QString &bgImagePath,
                    QWidget *parent = 0);

  explicit T3Dialog(int x,
                    int y,
                    int w,
                    int h,
                    Qt::GlobalColor color,
                    QWidget *parent = 0);

  ///
  /// \brief set dialog background
  /// \param image Path
  ///
  void setBackgroundWithImage(QString imagePath);
  void setBackgroundWithColor(Qt::GlobalColor color);
  ~T3Dialog();

private:
  void initT3Dialog();

}; //class
} //namespace

#endif
