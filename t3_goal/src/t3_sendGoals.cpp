#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>
#include <sstream>
#include <vector>
#include <string>
//signal
#include <signal.h>
//geometry
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseArray.h"
#include "geometry_msgs/Pose.h"

#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"
#include "nav_msgs/Path.h"

#include <math.h>

#include "t3_description/goal.h"
#include "t3_description/GuideState.h"

#define kCancelMissionTimes 3//当机器人在引导过程中出现异常中断时，中断次数超过此数值，将停止
#define kDeltTime_s 5//单位秒

using namespace t3_description;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class GoalsNode
{
public:
	GoalsNode();
	~GoalsNode();

//  enum eMissionState
//  {
//    eMission_NewGoal,
//    eMission_Resend,
//    eMission_Running,
//    eMission_Cancel,
//    eMission_Free
//  };

	void process();

private:
  MoveBaseClient _ac;//movebase客户端对象
  ros::NodeHandle _nh;//node
  ros::NodeHandle _privateNh;//获取参数node
//  int _countOfGoals;//目标点数量
//  int _currentIdxOfGoal;//目前目标点在数组内的下标
  move_base_msgs::MoveBaseGoal _currentGoal;//当前目标点

  GuideState _guideState;//引导状态
//  eMissionState _missionSate;//当前任务状态
  int _abortTimes;//出现异常中断的次数
//  std::vector<goal> _goals;

  ros::Subscriber _goalSub;
  ros::Publisher _guideStatePub;
  //用来计算上一次进入feedback和本次feedback时间差，来判断是否需要累加_abortTimes
  ros::Time _currentTime;
  ros::Time _lastTime;
  /**
   * @brief 更新引导状态
   */
  void updateGuideState();
  bool setGoal(goal& currentgoal);
  double getYaw(tf::Pose& t);
  /**
   * @brief 清除目标点数组方法
   */
  void clearGoals();
  /**
   * @brief 发送目标点
   */
  void sendGoal();
  /**
   * @brief 取消目标点
   */
  void cancelGoal();
  /**
   * @brief 到达目标点后，需要做的操作
   */
  void reachGoal();
  /**
   * @brief 获取目标点回调方法
   * @param msg
   */
  void getGoalCallback(const goal& msg);
  /**
   * @brief actionlib 回调
   */
  void acDoneCb(const actionlib::SimpleClientGoalState& state);
  void acActiveCb();
  void acFeedbackCb();
};

void sigintHandler(int sig)
{
  ros::shutdown();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "navigation_goals");
	signal(SIGINT, sigintHandler);
	GoalsNode *gn = new GoalsNode();
  gn->process();
	return 0;
}

std::string intToString (int v)  
{  
	std::ostringstream oss;
	oss << v;
	return oss.str();
} 

GoalsNode::GoalsNode() :
  _ac("move_base", true),
  _abortTimes(0)
{
  _currentTime = ros::Time::now();
  _lastTime = _currentTime;

  _guideState.state = GuideState::eGuide_Free;
  //set sub 获取新目标点的回调函数
  _goalSub = _nh.subscribe("robotGoal",100, &GoalsNode::getGoalCallback, this);
  //set pub 发布引导状态
  _guideStatePub = _nh.advertise<GuideState>("actionState", 10);
}

GoalsNode::~GoalsNode()
{
  if(ros::isStarted())
  {
    ros::shutdown();
    ros::waitForShutdown();
  }
  wait();
}

void GoalsNode::sendGoal()
{
  _ac.sendGoal(_currentGoal,
              boost::bind(&GoalsNode::acDoneCb, this, _1),
              boost::bind(&GoalsNode::acActiveCb, this),
              boost::bind(&GoalsNode::acFeedbackCb, this));
}
/**
 * @brief 更新引导状态
 */
void GoalsNode::updateGuideState()
{

}

void GoalsNode::process()
{
  while((!_ac.waitForServer(ros::Duration(5.0))))
	{
		ROS_WARN("Waiting for the move_base action server");
	}
  ros::Rate loop_rate(1);
	while(ros::ok())
  {
    if((_guideState.state == GuideState::eGuide_NewGoal) || (_guideState.state == GuideState::eGuide_Resend))
    {
      sendGoal();
      _guideState.state = GuideState::eGuide_Running;
    }else if(_guideState.state == GuideState::eGuide_Cancel)
    {
      cancelGoal();
    }else if(_guideState.state == GuideState::eGUide_Success)
    {
      reachGoal();
    }
    _guideStatePub.publish(_guideState);
    ros::spinOnce();
		loop_rate.sleep();		
	}
}

void GoalsNode::cancelGoal()
{
  ROS_INFO("cancel");
  _abortTimes = 0;
  _ac.cancelAllGoals();
}

void GoalsNode::reachGoal()
{
  ROS_INFO("reach");
  _abortTimes = 0;
}

/********************callback********************/
void GoalsNode::getGoalCallback(const goal& msg)
{
//  clearGoals();
//  goal goal_ = msg;
  cancelGoal();
  _guideState.state = GuideState::eGuide_NewGoal;
  double x = msg.x;
  double y = msg.y;
  double z = sin(msg.z/2);
  double w = cos(msg.z/2);
  _currentGoal.target_pose.header.stamp = ros::Time::now();
  _currentGoal.target_pose.header.frame_id = "map";
  _currentGoal.target_pose.pose.position.x = x;
  _currentGoal.target_pose.pose.position.y = y;
  _currentGoal.target_pose.pose.orientation.z = z;
  _currentGoal.target_pose.pose.orientation.w = w;
//  _goals.push_back(goal_);
//  _countOfGoals++;
}

void GoalsNode::acDoneCb(const actionlib::SimpleClientGoalState& state)
{
  ROS_INFO("Done [%s] | times: %d",_ac.getState().toString().c_str(), _abortTimes);

  if(_ac.getState() == actionlib::SimpleClientGoalState::ABORTED)
  {
    double delTime = 0.0;
    double ct_ = 0.0;
    double lt_ = _lastTime.toSec();
    //相等时，代表是首次进入此状态
    if(ct_ != lt_)
    {
      _currentTime = ros::Time::now();
      ct_ = _currentTime.toSec();
      delTime = ct_ - lt_;
    }else
    {
      _currentTime = ros::Time::now();
    }
    ROS_INFO("CT: %f | LT: %f | delTime: %f", ct_, lt_, delTime);
    //间隔小于一定时间，放弃次数累加，否则就置0
    if(delTime < kDeltTime_s)
    {
      _abortTimes++;
    }else
    {
      _abortTimes = 0;
    }

    if(_abortTimes >= kCancelMissionTimes)
    {
      _guideState.state = GuideState::eGuide_Cancel;
    }else
    {
      _guideState.state = GuideState::eGuide_Resend;
    }
    _lastTime = _currentTime;
  }else if(_ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    _guideState.state = GuideState::eGUide_Success;
  }

//  if(_ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
//  {
//    _missionSate = eMission_None;
//  }
}

void GoalsNode::acActiveCb()
{
//  move_base_msgs::MoveBaseGoal cg = _ac.getResult();

  ROS_INFO("Active [%s]",_ac.getState().toString().c_str());
//  if(_ac.getState() == actionlib::SimpleClientGoalState::ACTIVE)
//  {
//    _state = Active;
//  }
//  GoalHandleT goal = _ac.Goal;


  _guideState.state = GuideState::eGuide_Running;
  _currentTime = ros::Time::now();
  _lastTime = _currentTime;
}

void GoalsNode::acFeedbackCb()
{
  ROS_INFO("Feedback [%s] | times: %d",_ac.getState().toString().c_str(), _abortTimes);

}
