#include "main.h"
#include "utils/screen-displays.hpp"

// https://lemlib.readthedocs.io/en/stable/tutorials/4_pid_tuning.html
void tuneAngularPID(lemlib::Chassis& chassis) {
	chassis.setPose(0, 0, 0);
	chassis.turnToHeading(90, 100000);
}

void tuneLateralPID(lemlib::Chassis& chassis) {
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, 48, 100000);
}

void autonomousRunner(pros::Controller& controller, lemlib::Chassis& chassis) {
	int i = 0;
	pros::lcd::print(i++, "AUTON RUNNING");
	++i;
	batteryDisplay(controller, i);

	tuneAngularPID(chassis);
	// tuneLateralPID(&chassis);
}
