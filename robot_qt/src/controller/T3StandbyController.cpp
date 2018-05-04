#include "T3StandbyController.hpp"


#define kMainTitle "THE SHARE ROBOTS"
#define kMainText "WORKING NEGO"
#define kCnTips "你的私人助理 你的个人媒体中心 你的私人机器人\r\n共享内戈机器人"
#define ANIMATION_COVER

T3StandbyController::T3StandbyController():
  T3BaseController(0, 0, kScreenW, kScreenH, "", false)
{
  setUI();
  setFaceInterface();//把人脸识别接口定义在这里，当检测到人脸时，返回一个信号
  _bootCoinDia->raise();

}
//把人脸识别接口定义在这里，当检测到人脸时，返回一个信号
void T3StandbyController::setFaceInterface()
{
  _faceScan = interface::T3FaceScan::getInstance();
  connect(_faceScan,
          &interface::T3FaceScan::getNewFace,
          this,
          &T3StandbyController::getNewFace);
}


void T3StandbyController::setUI()
{

  _bootCoinDia = new T3View::T3Dialog(0,
                                      0,
                                      kScreenW,
                                      kScreenH,
                                      kMainBackground,
                                      this->_window);

  _waitDia = new T3View::T3Dialog(0,
                                  0,
                                  kScreenW,
                                  kScreenH,
                                  kMainBackground,
                                  this->_window);

  _bootCoinLabel = new T3View::T3Label(_bootCoinDia,
                                         kBootCoinX_bgc,
                                         kBootCoinY_bgc,
                                         kBootCoinW_bgc,
                                         kBootCoinH_bgc,
                                         kBootCoinPath
                                         );

  _mainTitle =new T3View::T3Label (_waitDia,
                                0,
                                kMainTitleY_wc,
                                kScreenW,
                                kMainTitleH_wc,
                                kMainTitle,
                                kMainTitleFontSize,
                                kMainTitleFontStyle,
                                kMainRGB,
                                QFont::DemiBold,
                                kMainTitleFontSpace
                                );


  _mainText =new T3View::T3Label(_waitDia,
                              0,
                              kMainTextY_wc,
                              kScreenW,
                              kMainTextH_wc,
                              kMainText,
                              kMainTextFontSize,
                              kMainTextFontStyle,
                              kMainRGB,
                              QFont::Bold,
                              kMainTextFontSpace
                              );


  _cnTips =new T3View::T3Label(_waitDia,
                            0,
                            kCnTipsY_wc,
                            kScreenW,
                            kCnTipsH_wc,
                            kCnTips,
                            kCnTipsFontSize,
                            kCnTipsFontStyle,
                            kCnTipsRGB,
                            QFont::Medium,
                            kCnTipsFontSpace
                            );


}

void T3StandbyController::showUI()
{
  _window->show();
  interfaceChange();
  _widgetNum = false;
  _effectTimer = new QTimer();
  _effectTimer->start(11000);
  connect(_effectTimer,
          &QTimer::timeout,
          this,
          &T3StandbyController::interfaceChange);

}

/****** slots & signals ********/
void T3StandbyController::interfaceChange()
{
  if(_widgetNum)
  {
      wigShow(_waitDia,1);
      _widgetNum = false;
  }else
  {
      wigShow(_bootCoinDia,1);
      _widgetNum = true;
  }

}

void T3StandbyController::getNewFace(model::T3UserInfo &userInfo)
{
  T3LOG << "get new face";
  this->hideUI();
  emit exitStandby(userInfo);
//  delete this;
}

void T3StandbyController::wigShow(QWidget *wig, int direct)
{
#ifdef ANIMATION_COVER //覆盖效果
    int startx = (direct > 0)? kScreenW : kScreenW;
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"pos");
    animal1->setDuration(5000);
    animal1->setStartValue(QPoint(startx,0));
    animal1->setEndValue(QPoint(0,0));
    animal1->setEasingCurve(QEasingCurve::OutCubic);
    wig->raise();
    animal1->start();
#endif
#ifdef ANIMATION_SLIDE //两个界面同时平推
    int startx = (direct > 0)? -kScreenW : kScreenW;

    //tmpWig = content->childAt(0,0);
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"pos");
    animal1->setDuration(10000);
    animal1->setStartValue(QPoint(startx,0));
    animal1->setEndValue(QPoint(0,0));
    animal1->setEasingCurve(QEasingCurve::OutCubic);

    QPropertyAnimation *animal2= new QPropertyAnimation(_bootCoinDia,"pos");
    animal2->setDuration(10000);
    animal2->setStartValue(QPoint(0,0));
    animal2->setEndValue(QPoint(-startx,0));
    animal2->setEasingCurve(QEasingCurve::OutCubic);

    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(animal1);
    group->addAnimation(animal2);
    group->start();
    wig->raise();
#endif
#ifdef ANIMATION_ZUO1
    if(direct > 0){//从左上角慢慢变大出现
        QPropertyAnimation *animal1= new QPropertyAnimation(wig,"size");
        animal1->setDuration(10000);
        animal1->setStartValue(QSize(0,0));
        animal1->setEndValue(QSize(kScreenW,kScreenH));
        animal1->setEasingCurve(QEasingCurve::OutCubic);
        wig->raise();
        animal1->start();
    }else{  //右下角慢慢变大出现
        QPropertyAnimation *animal1= new QPropertyAnimation(wig,"geometry");
        animal1->setDuration(10000);
        animal1->setStartValue(QRect(kScreenW,kScreenH, 0, 0));
        animal1->setEndValue(QRect(0,0, kScreenW, kScreenH));
        animal1->setEasingCurve(QEasingCurve::OutCubic);
        wig->raise();
        animal1->start();
    }
#endif
#ifdef ANIMATION_ZUO2
    if(direct > 0){//从左上角慢慢变大出现
        QPropertyAnimation *animal1= new QPropertyAnimation(wig,"size");
        animal1->setDuration(timeVal);
        animal1->setStartValue(QSize(0,0));
        animal1->setEndValue(QSize(w,h));
        animal1->setEasingCurve(QEasingCurve::OutCubic);
        wig->raise();
        animal1->start();
    }else{  //覆盖层从右下角开始慢慢消失显示出要显示的界面
        QWidget *tmp = content->childAt(w-1, h-1);//这个地方必须等到上个动画完毕,否则偶尔会出现混乱
        if(tmp == NULL){
            qDebug()<<"no wig";
            return;
        }
        wig->stackUnder(tmp);  //把要显示的wig放到当前显示的下面
        QPropertyAnimation *animal1= new QPropertyAnimation(tmp,"size");
        animal1->setDuration(timeVal);
        animal1->setStartValue(QSize(w,h));
        animal1->setEndValue(QSize(0,0));
        animal1->setEasingCurve(QEasingCurve::OutCubic);
        animal1->start();
    }
#endif
#ifdef ANIMATION_CENTER
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"geometry");
    animal1->setDuration(1000);
    animal1->setStartValue(QRect(kScreenW/2,kScreenH/2, 0, 0));
    animal1->setEndValue(QRect(0,0, kScreenW, kScreenH));
    wig->raise();
    animal1->start();
#endif
#ifdef ANIMATION_CENTER2
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"geometry");
    animal1->setDuration(timeVal);
    animal1->setStartValue(QRect(w/2,h/2, 0, 0));
    animal1->setEndValue(QRect(0,0, w, h));
    animal1->setEasingCurve(QEasingCurve::OutCubic);
    wig->raise();
    animal1->start();
#endif
#ifdef ANIMATION_DUIJIAO //对角变化
    tmpWig = content->childAt(0,0);
    QPropertyAnimation *animal1= new QPropertyAnimation(wig,"geometry");
    animal1->setDuration(timeVal);
    (direct > 0)? animal1->setStartValue(QRect(0,0, 0, 0)):animal1->setStartValue(QRect(w,h, 0, 0));
    (direct > 0)? animal1->setEndValue(QRect(0,0, w, h)):animal1->setEndValue(QRect(0,0, w, h));

    QPropertyAnimation *animal2= new QPropertyAnimation(tmpWig,"geometry");
    animal2->setDuration(timeVal);
    (direct > 0)? animal2->setStartValue(QRect(0,0, w, h)):animal2->setStartValue(QRect(0,0, w, h));
    (direct > 0)? animal2->setEndValue(QRect(w,h, 0, 0)):animal2->setEndValue(QRect(0,0, 0, 0));

    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(animal1);
    group->addAnimation(animal2);
    group->start();
    wig->raise();
#endif
}

T3StandbyController::~T3StandbyController()
{
  _faceScan = NULL;
}
