#ifndef ENVIRONMENTCONTROLLERKATA_ENVIRONMENTCONTROLLER_H
#define ENVIRONMENTCONTROLLERKATA_ENVIRONMENTCONTROLLER_H


#include "../tests/HardwareStub.h"
#include "Hardware.h"

class EnvironmentController {

public:
    explicit EnvironmentController(Hardware *hw) : _hw(hw) {};

    void tic();


private:
    Hardware* _hw;
};


#endif //ENVIRONMENTCONTROLLERKATA_ENVIRONMENTCONTROLLER_H
