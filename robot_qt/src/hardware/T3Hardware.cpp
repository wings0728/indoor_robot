#include "T3Hardware.hpp"

namespace interface
{
static T3Hardware* _hw = new T3Hardware();

T3Hardware::T3Hardware()
{
  _isInit = true;
}
T3Hardware* T3Hardware::getInstance()
{
  _hw->init();
  return _hw;
}

void T3Hardware::init()
{
  if(_isInit)
  {
    _qnode = QNode::getInstance();
    _isInit = false;
  }
}

T3Hardware::~T3Hardware()
{

}

void T3Hardware::oprationSweeper(eHardwareState state)
{

}

void T3Hardware::oprationProjector(eHardwareState state)
{

}

void T3Hardware::oprationHumidifier(eHardwareState state)
{

}

void T3Hardware::oprationLED()
{

}
void T3Hardware::oprationVoice(QString str)
{

}

void T3Hardware::openSixMicrophone()
{

}

void T3Hardware::openExpressGate()
{

}

void T3Hardware::oprationHead(int angle)
{

}

/******* slots ********/
void T3Hardware::getMicrophoneFB(int angle)
{
 emit sixMicrophoneWakeup(angle);
}


}
