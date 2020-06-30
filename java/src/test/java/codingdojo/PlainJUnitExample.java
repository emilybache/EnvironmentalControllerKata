package codingdojo;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertFalse;

public class PlainJUnitExample {
    private HardwareStub hw = new HardwareStub();
    private int VERY_COLD = 5;
    private int COLD = 15;
    private int HOT = 25;
    private int VERY_HOT = 30;
    private EnvironmentController controller = new EnvironmentController(hw);

    @Test
    void turnOnLoTempAlarmAtThreshold() {
        hw.setTemp(VERY_COLD);
        controller.tic();
        assertTrue(hw.heaterState());
        assertTrue(hw.blowerstate());
        assertFalse(hw.coolerState());
        assertFalse(hw.hiTempAlarm());
        assertTrue(hw.loTempAlarm());
    }

    @Test
    void turnOnCoolerAndBlowerIfHot() {
        hw.setTemp(HOT);
        controller.tic();
        assertFalse(hw.heaterState());
        assertTrue(hw.blowerstate());
        assertTrue(hw.coolerState());
        assertFalse(hw.hiTempAlarm());
        assertFalse(hw.loTempAlarm());
    }

    @Test
    void turnOnHeaterAndBlowerIfCold() {
        hw.setTemp(COLD);
        controller.tic();
        assertTrue(hw.heaterState());
        assertTrue(hw.blowerstate());
        assertFalse(hw.coolerState());
        assertFalse(hw.hiTempAlarm());
        assertFalse(hw.loTempAlarm());
    }

    @Test
    void turnOnHiTempAlarmAtThreshold() {
        hw.setTemp(VERY_HOT);
        controller.tic();
        assertFalse(hw.heaterState());
        assertTrue(hw.blowerstate());
        assertTrue(hw.coolerState());
        assertTrue(hw.hiTempAlarm());
        assertFalse(hw.loTempAlarm());
    }
}
