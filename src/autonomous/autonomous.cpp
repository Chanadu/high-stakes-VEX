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
	using Devices::chassis;
	using Devices::holderPiston;
	using Devices::intakeMotorGroup;
	// path file name is "example.txt".
	// "." is replaced with "_" to overcome c++ limitations
	// ASSET(example_txt);
	// // ASSET(example2_txt)
	// Devices::chassis->setPose(0, 0, 0);
	// // lookahead distance: 15 inches
	// // timeout: 2000 ms
	// Devices::chassis->follow(example_txt, 15, 2000);
	// follow the next path, but with the robot going backwards
	// Devices::chassis->follow(example2_txt, 15, 2000, false);
	// Devices::holderPiston.extend();
	// Devices::intakeMotorGroup.move(127);
	// Devices::intakeMotorGroup.move(0);
	//
	intakeMotorGroup.move(0);
	holderPiston.extend();
	// -90 - start, do nothing, but go backwards to next point
	chassis->moveToPose(0, 0, 90, 5000);
	// -20 - clamp BEFORE turning
	chassis->moveToPoint(-19.331, 21.605, 5000, {.forwards = false});
	holderPiston.retract();
	chassis->turnToHeading(20, 5000);
	// -270 - turn on intake
	chassis->moveToPose(0, 12.698, 270, 5000);
	intakeMotorGroup.move(127);
	// -270 - turn off intake
	chassis->moveToPose(0, 39.23, 270, 5000);
	intakeMotorGroup.move(0);
	// -270 - nothing
	chassis->moveToPose(-15.161, 28.806, 270, 5000);
	// -0 - turn on intake
	chassis->moveToPose(-14.593, 41.694, 0, 5000);
	intakeMotorGroup.move(127);
	// -80 - turn off intake
	chassis->moveToPose(11.56, 41.883, 80, 5000);
	intakeMotorGroup.move(0);
	// -90 - turn on intake
	chassis->moveToPose(12.887, 12.887, 90, 5000);
	intakeMotorGroup.move(127);
	// -90 - go backwards to next point
	chassis->moveToPose(12.887, -5.685, 90, 5000);
	// -170 - turn off intake and unclamp
	chassis->moveToPose(10.044, 6.633, 170, 5000, {.forwards = false});
	intakeMotorGroup.move(0);
	holderPiston.extend();
	// -270 - nothing
	chassis->moveToPose(-48.137, 1.137, 270, 5000);
	// -270 turn on intake(try to point ring on wall stake), wait a bit then turn off intake
	chassis->moveToPose(-48.137, -7.96, 270, 5000);
	intakeMotorGroup.move(127);
	pros::delay(500);
	intakeMotorGroup.move(0);
	// -340 - nothing
	chassis->moveToPose(-47.948, 11.75, 340, 5000);
	// 230 - nothing
	chassis.moveToPose(21.984, -21.605, 230, 5000);
	// -230 - nothing
	chassis->moveToPose(-31.46, 33.355, 230, 5000);
}
