#include "T3BeginController.hpp"
#include "../config/config.hpp"

T3BeginController::T3BeginController():
    T3BaseController(0,
                     0,
                     kScreenW,
                     kScreenH,
                     kBackgroundPath,
                     false)
{
    setBootCoinLabel();
}

void T3BeginController::setBootCoinLabel()
{
    _bootCoinLabel = new T3View::T3Label(this->_window,
                                           kBootCoinX_bgc,
                                           kBootCoinY_bgc,
                                           kBootCoinW_bgc,
                                           kBootCoinH_bgc,
                                           kBootCoinPath
                                           );

}
