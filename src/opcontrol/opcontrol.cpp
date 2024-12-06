#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"
#include "opcontrol/device-controller.hpp"
#include "opcontrol/drivetrain-movement.hpp"
#include "screen-displays.hpp"

[[noreturn]] void opcontrolRunner() {
	// pros::lcd::clear();
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
