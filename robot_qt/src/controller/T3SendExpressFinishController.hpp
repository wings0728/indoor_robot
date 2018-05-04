#ifndef robot_qt_SENDEXPRESSFINISHCONTROLLER_HPP_
#define robot_qt_SENDEXPRESSFINISHCONTROLLER_HPP_
#include "baseController/T3BaseController.hpp"
#include "../view/T3Label.hpp"

class T3SendExpressFinishController : public T3BaseController {
  Q_OBJECT
public:
  explicit T3SendExpressFinishController(T3BaseController *parent = 0);

private:
  T3View::T3Label *_title;

  void setTitle();
};

#endif
