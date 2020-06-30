package codingdojo;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class BobsDSLExample {
    private HardwareStub hw = new HardwareStub();
    private int VERY_COLD = 5;
    private int COLD = 15;
    private int HOT = 25;
    private int VERY_HOT = 30;
    private EnvironmentController controller = new EnvironmentController(hw);

    @Test
    public void turnOnCoolerAndBlowerIfTooHot() throws Exception {
        tooHot();
        assertEquals("hBChl", hw.getState());
    }

    @Test
    public void turnOnHeaterAndBlowerIfTooCold() throws Exception {
        tooCold();
        assertEquals("HBchl", hw.getState());
    }

    @Test
    public void turnOnHiTempAlarmAtThreshold() throws Exception {
        wayTooHot();
        assertEquals("hBCHl", hw.getState());
    }

    @Test
    public void turnOnLoTempAlarmAtThreshold() throws Exception {
        wayTooCold();
        assertEquals("HBchL", hw.getState());
    }

    private void wayTooCold() {
        hw.setTemp(VERY_COLD);
        controller.tic();
    }

    private void wayTooHot() {
        hw.setTemp(VERY_HOT);
        controller.tic();
    }

    private void tooCold() {
        hw.setTemp(COLD);
        controller.tic();
    }

    private void tooHot() {
        hw.setTemp(HOT);
        controller.tic();
    }
}
