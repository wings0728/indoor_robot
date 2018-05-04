#ifndef robot_qt_T3TOOL_HPP_
#define robot_qt_T3TOOL_HPP_

#include <QObject>


namespace interface {
class T3Tool: public QObject
{
public:
  explicit T3Tool();
  ~T3Tool();

  QString md5(QString str);
};
}

#endif
