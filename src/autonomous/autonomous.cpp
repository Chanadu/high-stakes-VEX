#include "autonomous/autonomous.hpp"
#include "autonomous/comp-auton.hpp"
#include "configuration.hpp"
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
	clearScreen();
	enum AutonTypes {
		TA,
		TL,
		RA,
	};

	AutonTypes autonType = TL;
	bool flip = true;

	short lineNumber = 0;

	std::string autonTypeString = (const char*[]){
		"TA",
		"TL",
		"RA",
	}[autonType];
	pros::lcd::print(lineNumber++, "AUTON RUNNING %s %d", autonTypeString, flip);
	Config::controllerStrings[1] = fmt::format("AUTON {} {}", autonTypeString, flip);

	batteryDisplay(lineNumber);
	chassisPositionDisplay(lineNumber);

	switch (autonType) {
		case TA:
			tuneAngularPID();
			break;
		case TL:
			tuneLateralPID();
			break;
		case RA:
			runAuton(flip);
			break;
	}
}
