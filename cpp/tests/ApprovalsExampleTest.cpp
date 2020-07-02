#include "ApprovalTests.hpp"
#include "EnvironmentController.h"
#include "catch.hpp"
#include "HardwareStub.h"

std::ostream& operator<<(std::ostream& os, const HardwareStub& obj)
{
    return os
            << "heater on: " << obj.heaterState << "\n"
            << "blower on: " << obj.blowerState << "\n"
            << "cooler on: " << obj.coolerState << "\n"
            << "hi temp alarm: " << obj.hiTempAlarm << "\n"
            << "lo temp alarm: " << obj.loTempAlarm << "\n";
}


TEST_CASE("EnvironmentController with Approvals")
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
        ApprovalTests::Approvals::verify(*hw);
    }

    SECTION("Turn on cooler and blower if hot") {
        hw->setTemp(HOT);
        controller.tic();
        ApprovalTests::Approvals::verify(*hw);
    }

    SECTION("Turn on heater and blower if cold") {
        hw->setTemp(COLD);
        controller.tic();
        ApprovalTests::Approvals::verify(*hw);
    }

    SECTION("Turn on HiTempAlarm at threshold") {
        hw->setTemp(VERY_HOT);
        controller.tic();
        ApprovalTests::Approvals::verify(*hw);
    }
}

