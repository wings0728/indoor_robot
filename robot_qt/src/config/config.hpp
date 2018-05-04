#ifndef robot_qt_CONFIG_HPP_
#define robot_qt_CONFIG_HPP_

#include <QDebug>
#include "config_ui.hpp"
#include "config_uih.h"
#include "config_image.hpp"

#define kAppTitle "T3"

#define T3LOG   qDebug() << "["  << __FILE__ << ":" << __LINE__ << ":"<< __TIME__ "]"


#define kLowPowerLimit 20
#define kMainRGB "40, 220, 160" // 主色调
#define kSignInFailRGB "247,147,30" //签到失败字体颜色

/********* database **********/
#define kDatabaseName "T3Robot"
#define kDatabaseUserName "T3Robot"
#define kDatabasePassword "T3Robot"
#define kDatabaseEngine "QMYSQL"
//#define kDatabaseURL "192.168.0.192"
#define kDatabaseURL "localhost"

/********* face **********/
/*#define kAPPID "GftPTk199Uat2fp2X9svyMbChTUhyabJsKxn9FYUy621"
#define kFT_SDKKEY "A6BRrouepWFkXYhdEeqnHi7nQhgscCC9GUWDGzuYmDi3"
#define kFR_SDKKEY "A6BRrouepWFkXYhdEeqnHi8QDhzkuAxfHhFrPVNwQ57C"*/
#define kAPPID "GftPTk199Uat2fp2X9svyMbT2G1741vhnyyEs8XX8Trd"
#define kFT_SDKKEY "FSzaRH4UQJfrczGPV1syvnuZNz199qhZrtNUvwC8xcQn"
#define kFR_SDKKEY "FSzaRH4UQJfrczGPV1syvnvBBzK18DLYyGy4thoNMPKm"
#define kFG_SDKKEY "FSzaRH4UQJfrczGPV1syvnvYgC6UB9CuJWs7Z12Nu63L"
#define kFA_SDKKEY "FSzaRH4UQJfrczGPV1syvnvRWnqJPdGNjx9ouHrp8zWG"
#define kFaceLoginTime 3  //单位秒  人脸识别界面等待时间
#define kMaxFTFace 50
#define kThreshold 0.55f
#define kNoFaceTime     5 //单位秒  判定无人时间


/********* video audio**********/
#define kAudioListLenght 5
#define kAudioPlayTimer 10  //毫秒
#define kFrameHeight 720
#define kFrameWidth 1280
#define kFrameSize "1280x720" //分辨率
#define kFramerate "25"       //帧率
#define kCameraPath "/dev/video0" //摄像头路径


/********* network **********/
#define kNetworkPort  8888
#define kUDPIPPort    6667
#define kUDPPort    6666
#endif

/********* task **********/
#define kSignSuccess_Voice "成功签到"
#define kWakeup_Free_Voice "你有什么事吗"
#define kWakeup_Busy_Voice "我有点忙"

/********* serialport **********/
#define kSerialportBaudRateSixMic 115200
#define kSerialportNameSixMic "ttyUSBSixMic"

