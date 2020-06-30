
#include "EnvironmentController.h"

void EnvironmentController::tic() {
    if (_hw->getTemp() < 16) {
        if (_hw->getTemp() < 6) {
            _hw->setLoTempAlarmOn();
        }
        _hw->turnBlowerOn();
        _hw->turnHeaterOn();
    }
    if (_hw->getTemp() > 24) {
        _hw->turnBlowerOn();
        _hw->turnCoolerOn();
        if (_hw->getTemp() > 29) {
            _hw->setHiTempAlarmOn();
        }
    }
}
