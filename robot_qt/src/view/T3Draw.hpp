#ifndef T3DRAW_HPP
#define T3DRAW_HPP

#include <QWidget>

namespace T3View {

class T3Draw : public QWidget{
    Q_OBJECT
public:
    explicit T3Draw(QWidget *parent = 0);

private:
    void paintEvent(QPaintEvent *event);
    //void paintEvent(QPaintEvent *event);

};
}
#endif // T3DRAW_HPP
