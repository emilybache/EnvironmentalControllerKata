package codingdojo;

public interface Hardware {
    boolean heaterState();
    boolean coolerState();
    boolean blowerstate();
    boolean hiTempAlarm();
    boolean loTempAlarm();

    int getTemp();

    void setLoTempAlarmOn();
    void setHiTempAlarmOn();
    void turnBlowerOn();
    void turnHeaterOn();
    void turnCoolerOn();
}
