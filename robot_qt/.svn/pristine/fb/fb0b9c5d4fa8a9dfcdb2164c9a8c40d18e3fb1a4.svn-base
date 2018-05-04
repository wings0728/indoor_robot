#ifndef T3GIFLABEL_H
#define T3GIFLABEL_H
#include "T3Label.hpp"
#include <QMovie>
namespace T3View {
class T3GifLabel : public T3Label {
  Q_OBJECT

public:
  //设置带GIF的label
  explicit T3GifLabel(QWidget *parent,
                   int x,
                   int y,
                   int w,
                   int h,
                   QString gif);
 /**
   * @brief 开始播放gif
   */
  void startGIF();
  /**
    * @brief 开始播放gif同时显示label
    */
  void startGIFWithShow();

  void stopGIF();
  void stopGIFWithHide();

  ~T3GifLabel();

private:
  QMovie *_gifObj;

}; //class
} //namespace
#endif // T3GIFLABEL_H
