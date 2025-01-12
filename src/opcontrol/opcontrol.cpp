#include "opcontrol/opcontrol.hpp"
#include "main.h"
#include "opcontrol/device-controller.hpp"
#include "opcontrol/drivetrain-movement.hpp"
#include "utils/configuration.hpp"
#include "utils/screen-displays.hpp"

void opcontrolRunner() {
	// pros::lcd::clear();
	Config::controllerStrings[1] = "OP RUNNING";
	while (true) {
		short lineNumber = 0;
		batteryDisplay(lineNumber);
		chassisPositionDisplay(lineNumber);
		drivetrainTorqueDisplay(lineNumber);

		drivetrainMovementController();
		intakeMotorControl();
		armMotorControl();
		holderPistonControl();

		pros::delay(10);
	}
}
