#include "autonomous/comp-auton.hpp"
#include "devices.hpp"

void runAuton(bool flip) {
	using Devices::chassis;
	using Devices::holderPiston;
	using Devices::intakeMotorGroup;
	float f = flip ? -1 : 1;

	intakeMotorGroup.move(0);
	holderPiston.extend();
	// -90 - start, do nothing, but go backwards to next point
	chassis.moveToPose(0, 0 * f, 90, 5000);
	// -20 - clamp BEFORE turning
	chassis.moveToPoint(-19.331, 21.605 * f, 5000, {.forwards = false});
	holderPiston.retract();
	chassis.turnToHeading(20, 5000);
	// -270 - turn on intake
	chassis.moveToPose(0, 12.698 * f, 270, 5000);
	intakeMotorGroup.move(127);
	// -270 - turn off intake
	chassis.moveToPose(0, 39.23 * f, 270, 5000, {.forwards = false});
	intakeMotorGroup.move(0);
	// -270 - nothing
	chassis.moveToPose(-15.161, 28.806 * f, 270, 5000);

	// -0 - turn on intake
	chassis.moveToPose(-14.593, 41.694 * f, 0, 5000);
	intakeMotorGroup.move(127);
	// -80 - turn off intake
	chassis.moveToPose(11.56, 41.883 * f, 80, 5000);
	intakeMotorGroup.move(0);
	// -90 - turn on intake
	chassis.moveToPose(12.887, 12.887 * f, 90, 5000);
	intakeMotorGroup.move(127);
	// -90 - go backwards to next point
	chassis.moveToPose(12.887, -5.685 * f, 90, 5000);
	// -170 - turn off intake and unclamp
	chassis.moveToPose(10.044, 6.633 * f, 170, 5000, {.forwards = false});
	intakeMotorGroup.move(0);
	holderPiston.extend();
	// -270 - nothing
	chassis.moveToPose(-48.137, 1.137 * f, 270, 5000);
	// -270 turn on intake(try to point ring on wall stake), wait a bit then turn off intake
	chassis.moveToPose(-48.137, -7.96 * f, 270, 5000);

	intakeMotorGroup.move(127);
	pros::delay(500);
	intakeMotorGroup.move(0);
	// -340 - nothing
	chassis.moveToPose(-47.948, 11.75 * f, 340, 5000);
	// 230 - nothing
	chassis.moveToPose(21.984, -21.605 * f, 230, 5000);
	// -230 - nothing
	chassis.moveToPose(-31.46, 33.355 * f, 230, 5000);
}
