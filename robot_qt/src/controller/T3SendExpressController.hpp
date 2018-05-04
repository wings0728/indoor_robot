#ifndef robot_qt_SENDEXPRESSCONTROLLER_HPP_
#define robot_qt_SENDEXPRESSCONTROLLER_HPP_
#include "baseController/T3ChoiceController.hpp"



class T3SendExpressController : public T3ChoiceController {
  Q_OBJECT
public:
  explicit T3SendExpressController(T3BaseController *parent = 0);
  ~T3SendExpressController();
  void leftBtnEvent();
  void rightBtnEvent();


};

#endif
