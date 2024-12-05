#include "autonomous/autonomous.hpp"
#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"
#include "screen-displays.hpp"

// https://lemlib.readthedocs.io/en/stable/tutorials/4_pid_tuning.html
void tuneAngularPID() {
	Devices::chassis->setPose(0, 0, 0);
	Devices::chassis->turnToHeading(90, 100000);
}

void tuneLateralPID() {
	Devices::chassis->setPose(0, 0, 0);
	Devices::chassis->moveToPoint(0, 48, 100000);
}

void autonomousRunner() {
	short lineNumber = 0;
	pros::lcd::print(lineNumber++, "AUTON RUNNING");
	++lineNumber;
	batteryDisplay(lineNumber);

	tuneAngularPID();
	// tuneLateralPID(&chassis);
}

void runAuton() {
	// path file name is "example.txt".
	// "." is replaced with "_" to overcome c++ limitations
	ASSET(example_txt);
	// ASSET(example2_txt)
	Devices::chassis->setPose(0, 0, 0);
	// lookahead distance: 15 inches
	// timeout: 2000 ms
	Devices::chassis->follow(example_txt, 15, 2000);
	// follow the next path, but with the robot going backwards
	// Devices::chassis->follow(example2_txt, 15, 2000, false);
}
