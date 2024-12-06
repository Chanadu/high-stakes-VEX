#include "autonomous/autonomous.hpp"
#include "autonomous/comp-auton.hpp"
#include "devices.hpp"
#include "main.h"
#include "screen-displays.hpp"

// https://lemlib.readthedocs.io/en/stable/tutorials/4_pid_tuning.html
void tuneAngularPID() {
	Devices::chassis.setPose(0, 0, 0);
	Devices::chassis.turnToHeading(90, 100000);
}

void tuneLateralPID() {
	Devices::chassis.setPose(0, 0, 0);
	Devices::chassis.moveToPoint(0, 48, 100000);
}

void autonomousRunner() {
	// pros::lcd::clear();
	clearScreen();
	short lineNumber = 0;
	pros::lcd::print(lineNumber++, "AUTON RUNNING");
	batteryDisplay(lineNumber);
	chassisPositionDisplay(lineNumber);

	enum AutonTypes {
		TA,
		LA,
		RA,
	};

	AutonTypes autonType = TA;

	switch (autonType) {
		case TA:
			tuneAngularPID();
			break;
		case LA:
			tuneLateralPID();
			break;
		case RA:
			runAuton();
			break;
	}
}
