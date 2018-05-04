/**
  ******************************************************************************
  * 公司    T3
  * 文件名  T3GuideController.cpp
  * 作者    Jincheng
  * 版本    V1.0.0
  * 日期    2018.04.16
  * 说明
  ******************************************************************************
*/
#include "T3GuideController.hpp"
#include "../config/config.hpp"
#include "../model/T3PositionModel.hpp"

#include "T3MapController.hpp"

#define kGuideGBPath "://images/guideList/background_gl.png"
#define kGuideBtnNormalPath "://images/guideList/guideBtn_normal.png"
#define kGuideBtnPressedPath "://images/guideList/guideBtn_pressed.png"

#define kRowCount 2
#define kColumnCount 4

T3GuideController::T3GuideController(T3BaseController *parent):
  T3BaseController(0, 0, kScreenW, kScreenH, kGuideGBPath, true, parent)
{
  _qnode = interface::QNode::getInstance();
  setupBtnList();
}

void T3GuideController::setupBtnList()
{
  int count = _qnode->_positionList.size();
  for(int idx = 0; idx < count; idx++)
  {
    T3PositionModel *model = _qnode->_positionList[idx];
    int x = kFirstBtnX_gc + (kBtnW_gc + kHSpace_gc)*(idx%kColumnCount);
    int y = kFirstBtnY_gc + (kBtnH_gc + kVSpace_gc)*(idx/kColumnCount);
    int w = kBtnW_gc;
    int h = kBtnH_gc;
    T3View::T3Button *btn = new T3View::T3Button(this->_window,
                                                 x,
                                                 y,
                                                 w,
                                                 h,
                                                 kGuideBtnNormalPath,
                                                 kGuideBtnPressedPath,
                                                 model->getPoseName(),
                                                 kTimeFontSize,
                                                 kTimeFontStyle,
                                                 kMainRGB,
                                                 QFont::Normal,
                                                 kTimeFontSpace);
    btn->setTag(idx);
    connect(btn, SIGNAL(t3BtnSignal(int)), SLOT(guideBtnSlot(int)));
  }
}

void T3GuideController::guideBtnSlot(int btnTag)
{
  //qDebug() << "btnTag: " << btnTag;
  T3PositionModel *model = _qnode->_positionList[btnTag];
   std::vector<double> tempPose(_qnode->getRobotPose());
   T3Pose *currentPose = new T3Pose(tempPose[0], tempPose[1], tempPose[2]);
  T3MapController *map = new T3MapController(model, currentPose, this);
  this->hideUI();
  map->showUI();
}
