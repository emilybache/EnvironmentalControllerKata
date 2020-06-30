package codingdojo;

public class HardwareStub implements Hardware {
    private int temp;
    private boolean heaterState = false;
    private boolean coolerState = false;
    private boolean blowerState = false;
    private boolean hiTempAlarm = false;
    private boolean loTempAlarm = false;

    public void setTemp(int temp) {
        this.temp = temp;
    }

    @Override
    public boolean heaterState() {
        return heaterState;
    }

    @Override
    public boolean coolerState() {
        return coolerState;
    }

    public boolean blowerstate() {
        return blowerState;
    }

    @Override
    public boolean hiTempAlarm() {
        return hiTempAlarm;
    }

    @Override
    public boolean loTempAlarm() {
        return loTempAlarm;
    }

    @Override
    public int getTemp() {
        return temp;
    }

    @Override
    public void setLoTempAlarmOn() {
        this.loTempAlarm = true;
    }

    @Override
    public void setHiTempAlarmOn() {
        this.hiTempAlarm = true;
    }

    @Override
    public void turnBlowerOn() {
        this.blowerState = true;
    }

    @Override
    public void turnHeaterOn() {
        this.heaterState = true;
    }

    @Override
    public void turnCoolerOn() {
        this.coolerState = true;
    }

    public String getState() {
        String state = "";
        state += heaterState ? "H" : "h";
        state += blowerState ? "B" : "b";
        state += coolerState ? "C" : "c";
        state += hiTempAlarm ? "H" : "h";
        state += loTempAlarm ? "L" : "l";
        return state;
    }
}
