#include "T3TaskModel.hpp"


namespace model
{
//  T3UserInfo _defaultUser;
/****** 基类 ******/
  T3TaskModel::T3TaskModel()
  {

  }
  T3TaskModel::T3TaskModel(eTaskType type):
    _type(type)
  {

  }

  T3TaskModel::T3TaskModel(eTaskType type, T3UserInfo &sender):
    _type(type),
    _sender(sender)
  {

  }

  void T3TaskModel::setType(eTaskType type)
  {
    _type = type;
  }

  eTaskType T3TaskModel::getType()
  {
    return _type;
  }

  void T3TaskModel::setId(QString id)
  {
    _id = id;
  }
  QString T3TaskModel::getId()
  {
    return _id;
  }

  void T3TaskModel::setSender(T3UserInfo& sender)
  {
    _sender = sender;
  }
  T3UserInfo& T3TaskModel::getSender()
  {
    return _sender;
  }

  void T3TaskModel::setPriority(int priority)
  {
    _priority = priority;
  }
  int T3TaskModel::getPriority()
  {
    return _priority;
  }

  void T3TaskModel::setState(eTaskState state)
  {
    _state = state;
  }
  eTaskState T3TaskModel::getState()
  {
    return _state;
  }

  T3TaskModel::~T3TaskModel()
  {

  }

/****** 签到 ******/
  T3SignTask::T3SignTask():
    T3TaskModel(eTSign)
  {

  }

  T3SignTask::~T3SignTask()
  {

  }

/****** 唤醒 ******/
  T3WakeupTask::T3WakeupTask():
    T3TaskModel(eTWakeup)
  {

  }

  T3WakeupTask::~T3WakeupTask()
  {

  }

/****** 语音 ******/
  T3VoiceTask::T3VoiceTask(eTaskType type, eTaskState state):
    T3TaskModel(eTVoice),
    _drvierTaskType(type),
    _drvierTaskState(state)
  {

  }

  T3VoiceTask::~T3VoiceTask()
  {

  }

/****** LED ******/
  T3LEDTask::T3LEDTask(eTaskType type, eTaskState state):
    T3TaskModel(eTLED),
    _drvierTaskType(type),
    _drvierTaskState(state)
  {

  }

  T3LEDTask::~T3LEDTask()
  {

  }

/****** 硬件开关 ******/
  T3HardwareTask::T3HardwareTask(T3UserInfo &sendUser, interface::eHardwareType type, interface::eHardwareState state):
    T3TaskModel(eTHardware, sendUser),
    _hwType(type),
    _hwState(state)
  {

  }

  T3HardwareTask::~T3HardwareTask()
  {

  }

  interface::eHardwareType T3HardwareTask::getHwType()
  {
    return _hwType;
  }

  void T3HardwareTask::setHwType(interface::eHardwareType hwType)
  {
    _hwType = hwType;
  }

  interface::eHardwareState T3HardwareTask::getHwState()
  {
    return _hwState;
  }
  void T3HardwareTask::setHwState(interface::eHardwareState hwState)
  {
    _hwState = hwState;
  }


/****** 引导 ******/
  T3GuideTask::T3GuideTask()
  {

  }
  T3GuideTask::T3GuideTask(eTaskType type, T3UserInfo &sendUser, T3PositionModel &model):
    T3TaskModel(type, sendUser),
    _position(model)
  {

  }

  T3GuideTask::T3GuideTask(T3UserInfo &sendUser,T3PositionModel &model):
    T3TaskModel(eTGuide, sendUser),
    _position(model)
  {

  }

  void T3GuideTask::setPlan(QList<std::pair<double, double> >& plan)
  {
    _plan = plan;
  }
  QList<std::pair<double, double> >& T3GuideTask::getPlan()
  {
    return _plan;
  }

  void T3GuideTask::setGuideState(int guideState)
  {
    _guideState.state = guideState;
  }
  int T3GuideTask::getGuideState()
  {
    return _guideState.state;
  }

  void T3GuideTask::setPosition(T3PositionModel &position)
  {
    _position = position;
  }
  T3PositionModel& T3GuideTask::getPosition()
  {
    return _position;
  }

  T3GuideTask::~T3GuideTask()
  {

  }

/****** 快递 ******/
  T3ExpressTask::T3ExpressTask(){}
  T3ExpressTask::T3ExpressTask(T3UserInfo &sendUser, T3UserInfo &receiveUser):
    T3GuideTask(eTExpress, sendUser, receiveUser.getPosition()),
    _receiver(receiveUser)
  {

  }

  T3ExpressTask::~T3ExpressTask()
  {

  }

  T3UserInfo& T3ExpressTask::getReceiver()
  {
    return _receiver;
  }
  void T3ExpressTask::setReceiver(T3UserInfo &receiver)
  {
    _receiver = receiver;
  }

/****** 回充 ******/
  T3ChargeTask::T3ChargeTask():
    T3TaskModel(eTCharge)
  {

  }

  T3ChargeTask::~T3ChargeTask()
  {

  }

/****** 模式切换 ******/
  T3ModeChangeTask::T3ModeChangeTask(T3UserInfo &sendUser,interface::QNode::OprationMode mode):
    T3TaskModel(eTModeChange, sendUser),
    _mode(mode)
  {

  }

  T3ModeChangeTask::~T3ModeChangeTask()
  {

  }

  interface::QNode::OprationMode T3ModeChangeTask::getMode()
  {
    return _mode;
  }
/****** 面试 ******/
  T3InterviewTask::T3InterviewTask(T3UserInfo &sendUser,
                                   T3UserInfo &interviewer,
                                   int post,
                                   T3PositionModel &_position):
    T3GuideTask(eTInterview, sendUser, _position)
  {

  }

  void T3InterviewTask::setInterviewDate(QDateTime interviewDate)
  {
    _interviewDate = interviewDate;
  }

  QDateTime T3InterviewTask::getInterviewDate()
  {
    return _interviewDate;
  }

  T3InterviewTask::~T3InterviewTask()
  {

  }

/****** 本体界面显示 ******/
  T3ShowUITask::T3ShowUITask(T3UserInfo &sendUser):
    T3TaskModel(eTShowUI, sendUser)
  {

  }

  T3ShowUITask::~T3ShowUITask()
  {

  }

/****** 待机界面显示 ******/
  T3StandbyTask::T3StandbyTask():
    T3TaskModel(eTStandby)
  {

  }

  T3StandbyTask::~T3StandbyTask()
  {

  }

/****** 回原点 ******/
  T3OriginTask::T3OriginTask():
    T3TaskModel(eTOrigin)
  {

  }

  T3OriginTask::~T3OriginTask()
  {

  }


}
