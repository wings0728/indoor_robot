#ifndef T3STANDBYCONTROLLER_HPP
#define T3STANDBYCONTROLLER_HPP

#include <QTimer>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

#include "baseController/T3BaseController.hpp"
#include "../T3base/T3IOBase.hpp"
#include "../view/T3Label.hpp"
#include "../face/T3FaceScan.h"
/**
  ******************************************************************************
  * @fileloadNewFace();
  * @author  HXP
  * @version  V1.0.0
  * @date    2018/04/11
  * @brief   待机轮播图界面
  ******************************************************************************
*/
class T3StandbyController : public T3BaseController
{
  Q_OBJECT
public:
  explicit T3StandbyController();
  ~T3StandbyController();


  void showUI();

private:
  void setUI();//设置UI
  void setFaceInterface();//人脸识别接口实现
  void wigShow(QWidget *wig, int direct);

  interface::T3FaceScan  *_faceScan;//人脸识别单例
  T3View::T3Dialog    *_bootCoinDia;
  T3View::T3Dialog    *_waitDia;
  T3View::T3Label     *_bootCoinLabel;
  T3View::T3Label     *_mainTitle;
  T3View::T3Label     *_mainText;
  T3View::T3Label     *_cnTips;

  QTimer      *_effectTimer;
  bool        _widgetNum;

signals:
  void exitStandby(model::T3UserInfo &userInfo);//发出退出待机界面信号

private slots:
    void interfaceChange();
    void getNewFace(model::T3UserInfo &userInfo);

};

#endif // T3STANDBYCONTROLLER_HPP
