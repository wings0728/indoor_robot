#include "T3SignInSuccessedController.hpp"
#include "../config/config.hpp"
#include <qdatetime.h>
#include <QTimer>

#define kTitle_swc "签到成功"
//#define kContent_swc "祝工作愉快"
#define kWelcomeDelayTime 3000
#define kClockDelayTime 1000

T3SignInSuccessedController::T3SignInSuccessedController(T3BaseController *parent,
                                                         QString name):
    T3BaseController(0,
                     0,
                     kScreenW,
                     kScreenH,
                     kSignInBackground,
                     true,
                     parent)
{
    setSignInSuccessedLabel();
    _name = name;
}

void T3SignInSuccessedController::setSignInSuccessedLabel()
{
    this->_signInSuccessedLabel = new T3View::T3Label(this->_window,
                                                      kSignInSuccessedLabelX_sic,
                                                      kSignInSuccessedLabelY_sic,
                                                      kSignInSuccessedLabelW_sic,
                                                      kSignInSuccessedLabelH_sic,
                                                      kSuccessedLabel);
    QTimer::singleShot(kWelcomeDelayTime, this, SLOT(setWelcome()));
}

void T3SignInSuccessedController::setWelcome()
{
    this->_signInSuccessedLabel->hide();
    setTitleLabel();
    setContentLabel();
    updateTimeStr();
    setTimeLabel();
    setupQTime();
    setBack();
    //this->showUI();
}

void T3SignInSuccessedController::setTitleLabel()
{

    this->_titleLabel = new T3View::T3Label(this->_window,
                                            kTitleLabelX_sic,
                                            kTitleLabelY_sic,
                                            kTitleLabelW_sic,
                                            kTitleLabelH_sic,
                                            kTitle_swc,
                                            kTitleFontSize_sic,
                                            kTitleFontStyle_sic,
                                            kMainRGB,
                                            QFont::DemiBold,
                                            kTitleFontSpace_sic
                                            );
   this->_titleLabel->show();

}
void T3SignInSuccessedController::setContentLabel()
{
    QString kContent_swc = "祝"+_name+" 工作愉快";
    //T3LOG<<kContent_swc;
    this->_contentLabel = new T3View::T3Label(this->_window,
                                            kContentLabelX_sic,
                                            kContentLabelY_sic,
                                            kContentLabelW_sic,
                                            kContentLabelH_sic,
                                            kContent_swc,
                                            kContentFontSize_sic,
                                            kContentFontStyle_sic,
                                            kMainRGB,
                                            QFont::DemiBold,
                                            kContentFontSpace_sic
                                            );
    this->_contentLabel->show();
}

void T3SignInSuccessedController::updateTimeStr()
{
    QDateTime date =QDateTime::currentDateTime();
    QString year = date.toString("yyyy");
    QString month = date.toString("MM");
    QString day = date.toString("dd");
    QString hour = date.toString("hh");
    QString min = date.toString("mm");
    _timeStr = year + "." + month + "." + day;
    if(hour.toInt() > 12)
    {
      hour = QString::number(hour.toInt() - 12, 10);
      _timeStr += " PM " + hour + ":" + min;
    }else
    {
      _timeStr += " AM " + hour + ":" + min;
    }
}

void T3SignInSuccessedController::setTimeLabel()
{
    this->_timeLabel = new T3View::T3Label(this->_window,
                                           kTimeLabelX_sic,
                                           kTimeLabelY_sic,
                                           kTimeLabelW_sic,
                                           kTimeLabelH_sic,
                                           _timeStr,
                                           kTimeFontSize,
                                           kTimeFontStyle,
                                           kMainRGB,
                                           QFont::Normal,
                                           kTimeFontSpace
                                           );
    this->_timeLabel->show();
}
void T3SignInSuccessedController::setupQTime()
{
  QTimer *timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
  timer->start(kClockDelayTime);
}

void T3SignInSuccessedController::updateTime()
{
  updateTimeStr();
  _timeLabel->setText(_timeStr);
}

void T3SignInSuccessedController::setBack()
{
    //后续跳转功能
}
