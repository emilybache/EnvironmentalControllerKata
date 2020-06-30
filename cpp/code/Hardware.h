#ifndef ENVIRONMENTCONTROLLERKATA_HARDWARE_H
#define ENVIRONMENTCONTROLLERKATA_HARDWARE_H


class Hardware {

public:
    virtual int getTemp() = 0;
    virtual void setLoTempAlarmOn() = 0;
    virtual void turnBlowerOn() = 0;
    virtual void turnHeaterOn() = 0;
    virtual void turnCoolerOn() = 0;
    virtual void setHiTempAlarmOn() = 0;
};


#endif //ENVIRONMENTCONTROLLERKATA_HARDWARE_H
