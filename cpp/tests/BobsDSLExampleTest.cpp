#include "EnvironmentController.h"
#include "catch.hpp"
#include "HardwareStub.h"

TEST_CASE("EnvironmentalController tests with a DSL designed by Bob Martin")
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
        REQUIRE("HBchL" == hw->getState());
    }

    SECTION("Turn on cooler and blower if hot") {
        hw->setTemp(HOT);
        controller.tic();
        REQUIRE("hBChl" == hw->getState());
    }

    SECTION("Turn on heater and blower if cold") {
        hw->setTemp(COLD);
        controller.tic();
        REQUIRE("HBchl" == hw->getState());
    }

    SECTION("Turn on HiTempAlarm at threshold") {
        hw->setTemp(VERY_HOT);
        controller.tic();
        REQUIRE("hBCHl" == hw->getState());
    }
}


