#include "HardwareStub.h"

void HardwareStub::setTemp(int temp) {
    _temp = temp;
}

int HardwareStub::getTemp() {
    return _temp;
}

void HardwareStub::setLoTempAlarmOn() {
    loTempAlarm = true;
}

void HardwareStub::turnBlowerOn() {
    blowerState = true;
}

void HardwareStub::turnHeaterOn() {
    heaterState = true;
}

void HardwareStub::turnCoolerOn() {
    coolerState = true;
}

void HardwareStub::setHiTempAlarmOn() {
    hiTempAlarm = true;
}

std::string HardwareStub::getState() {
    std::string state = "";
    state += heaterState ? "H" : "h";
    state += blowerState ? "B" : "b";
    state += coolerState ? "C" : "c";
    state += hiTempAlarm ? "H" : "h";
    state += loTempAlarm ? "L" : "l";
    return state;
}
