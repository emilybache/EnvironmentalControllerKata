package codingdojo;

public class EnvironmentController {
    private Hardware hw;

    public EnvironmentController(Hardware hw) {
        this.hw = hw;
    }

    public void tic() {
        if (hw.getTemp() < 16) {
            if (hw.getTemp() < 6) {
                hw.setLoTempAlarmOn();
            }
            hw.turnBlowerOn();
            hw.turnHeaterOn();
        }
        if (hw.getTemp() > 24) {
            hw.turnBlowerOn();
            hw.turnCoolerOn();
            if (hw.getTemp() > 29) {
                hw.setHiTempAlarmOn();
            }
        }
    }
}
