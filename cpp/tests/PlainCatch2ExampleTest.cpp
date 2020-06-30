#include "EnvironmentController.h"
#include "catch.hpp"
#include "HardwareStub.h"


TEST_CASE("EnvironmentController")
{
    int VERY_COLD = 5;
    int COLD = 15;
    int HOT = 25;
    int VERY_HOT = 30;

    auto* hw = new HardwareStub();
    EnvironmentController controller(hw);

    SECTION("Turn on LoTempalarm at threshold") {
        hw->setTemp(VERY_COLD);
        controller.tic();
        CHECK(hw->heaterState);
        CHECK(hw->blowerState);
        CHECK_FALSE(hw->coolerState);
        CHECK_FALSE(hw->hiTempAlarm);
        CHECK(hw->loTempAlarm);
    }

    SECTION("Turn on cooler and blower if hot") {
        hw->setTemp(HOT);
        controller.tic();
        CHECK_FALSE(hw->heaterState);
        CHECK(hw->blowerState);
        CHECK(hw->coolerState);
        CHECK_FALSE(hw->hiTempAlarm);
        CHECK_FALSE(hw->loTempAlarm);
    }

    SECTION("Turn on heater and blower if cold") {
        hw->setTemp(COLD);
        controller.tic();
        CHECK(hw->heaterState);
        CHECK(hw->blowerState);
        CHECK_FALSE(hw->coolerState);
        CHECK_FALSE(hw->hiTempAlarm);
        CHECK_FALSE(hw->loTempAlarm);
    }

    SECTION("Turn on HiTempAlarm at threshold") {
        hw->setTemp(VERY_HOT);
        controller.tic();
        CHECK_FALSE(hw->heaterState);
        CHECK(hw->blowerState);
        CHECK(hw->coolerState);
        CHECK(hw->hiTempAlarm);
        CHECK_FALSE(hw->loTempAlarm);
    }
}
