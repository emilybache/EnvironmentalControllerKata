package codingdojo;

import org.junit.jupiter.api.Test;

import static org.approvaltests.Approvals.verify;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class ApprovalsExample {
    private HardwareStub hw = new HardwareStub();
    private int VERY_COLD = 5;
    private int COLD = 15;
    private int HOT = 25;
    private int VERY_HOT = 30;
    private EnvironmentController controller = new EnvironmentController(hw);

    public static String print(HardwareStub hw) {
        String result = "";
        result += "Heater on: " + hw.heaterState() + "\n";
        result += "Blower on: " + hw.blowerstate() + "\n";
        result += "Cooler on: " + hw.coolerState() + "\n";
        result += "Hi temp alarm on: " + hw.hiTempAlarm() + "\n";
        result += "Lo temp alarm on: " + hw.loTempAlarm() + "\n";
        return result;
    }

    @Test
    void turnOnLoTempAlarmAtThreshold() {
        hw.setTemp(VERY_COLD);
        controller.tic();
        verify(print(hw));
    }

    @Test
    void turnOnCoolerAndBlowerIfHot() {
        hw.setTemp(HOT);
        controller.tic();
        verify(print(hw));
    }

    @Test
    void turnOnHeaterAndBlowerIfCold() {
        hw.setTemp(COLD);
        controller.tic();
        verify(print(hw));
    }

    @Test
    void turnOnHiTempAlarmAtThreshold() {
        hw.setTemp(VERY_HOT);
        controller.tic();
        verify(print(hw));
    }
}
