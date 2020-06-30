#ifndef ENVIRONMENTCONTROLLERKATA_HARDWARESTUB_H
#define ENVIRONMENTCONTROLLERKATA_HARDWARESTUB_H

#include <string>

#include "../code/Hardware.h"

class HardwareStub : public Hardware {

public:
    void setTemp(int temp);
    int getTemp() override;
    void setLoTempAlarmOn() override;
    void turnBlowerOn() override;
    void turnHeaterOn() override;
    void turnCoolerOn() override;
    void setHiTempAlarmOn() override;

    std::string getState();

    bool heaterState = false;
    bool coolerState = false;
    bool blowerState = false;
    bool hiTempAlarm = false;
    bool loTempAlarm = false;

private:
    int _temp{};

};


#endif //ENVIRONMENTCONTROLLERKATA_HARDWARESTUB_H
