#ifndef T3STAFFCONTROLLER_HPP
#define T3STAFFCONTROLLER_HPP
#include "baseController/T3UserController.hpp"
#include "../config/config.hpp"
#include "T3HardwareStartController.hpp"
#include "T3VideoCallController.hpp"
#include "T3SendExpressController.hpp"
#include "T3FaceSignInController.hpp"
#include "T3GuideController.hpp"
#include "../view/T3Button.hpp"

class T3StaffController:public T3UserController{
    Q_OBJECT
public:
    explicit T3StaffController();
    ~T3StaffController();
private slots:
    void logisticBtnClick();
    void hardwareBtnClick();
    void videoBtnClick();
    void attendanceBtnClick();
    void guideBtnClick();

private:
    T3View::T3Button *_logisticsBtn_normal;
    T3View::T3Button *_hardwareBtn_normal;
    T3View::T3Button *_videoBtn_normal;
    T3View::T3Button *_attendanceBtn_normal;
    T3View::T3Button *_guideBtn_normal;




    void setHardwareBtn();
    void setVideoBtn();
    void setGuideBtn();
};


#endif // T3STAFFCONTROLLER_HPP
