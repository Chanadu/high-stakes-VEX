#include <devices.hpp>

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
	short i = 0;
	pros::lcd::print(i++, "AUTON RUNNING");
	++i;
	batteryDisplay(Devices::controller, i);

	tuneAngularPID();
	// tuneLateralPID(&chassis);
}
