#include "autonomous/autonomous.hpp"
#include "autonomous/comp-auton.hpp"
#include "main.h"
#include "utils/configuration.hpp"
#include "utils/devices.hpp"
#include "utils/screen-displays.hpp"

// https://lemlib.readthedocs.io/en/stable/tutorials/4_pid_tuning.html
void tuneAngularPID() {
	Devices::chassis.turnToHeading(90, 100000);
}

void tuneLateralPID() {
	Devices::chassis.moveToPoint(0, 48, 100000);
}

void autonomousRunner() {
	clearScreen();

	constexpr AutonTypes autonType = BP;

	short lineNumber = 0;

	pros::lcd::print(lineNumber++, "AUTON RUNNING %s", autonTypeString.at(autonType));
	Config::controllerStrings[1] = fmt::format("AUTON {}", autonTypeString.at(autonType));

	batteryDisplay(lineNumber);
	chassisPositionDisplay(lineNumber);

	runAuton(autonType);
}
