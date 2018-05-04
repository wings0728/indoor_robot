#include "T3SignWelcomeController.hpp"
#include "../config/config.hpp"
#include <qdatetime.h>
#include <QTimer>

#define kTitle_swc "签到成功"
#define kContent_swc "祝您工作愉快"

T3SignWelcomeController::T3SignWelcomeController(T3BaseController *parent):
    T3BaseController(0,0,kScreenW, kScreenH, kSignInBackground, true,parent)
{
    setTitleLabel();
    setContentLabel();
    updateTimeStr();
    setTimeLabel();
    setupQTime();
}

void T3SignWelcomeController::setTitleLabel()
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
}
void T3SignWelcomeController::setContentLabel()
{
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
}

void T3SignWelcomeController::updateTimeStr()
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

void T3SignWelcomeController::setTimeLabel()
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
}

void T3SignWelcomeController::setupQTime()
{
  QTimer *timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
  timer->start(1000);
}

/******** slot **********/
void T3SignWelcomeController::updateTime()
{
  updateTimeStr();
  _timeLabel->setText(_timeStr);
}

