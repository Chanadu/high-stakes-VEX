#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"

void tankControl() {
	const int leftY =
		Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	const int rightY = Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
	Devices::chassis.tank(leftY, rightY);
}
void singleStickArcadeControl() {
	const int leftY =
		Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	const int leftX = Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
	Devices::chassis.arcade(leftY, leftX);
}
void doubleStickArcadeControl() {
	const int leftY =
		Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	const int rightX = Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	Devices::chassis.arcade(leftY, rightX);
}
void singleStickCurvatureControl() {
	const int leftY =
		Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	const int leftX = Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
	Devices::chassis.curvature(leftY, leftX);
}
void doubleStickCurvatureControl() {
	const int leftY =
		Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	const int rightX = Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	Devices::chassis.curvature(leftY, rightX);
}

void drivetrainMovementController(short& i) {
	pros::lcd::clear_line(i);

	switch (Config::drivetrainMovement) {
		case Config::DrivetrainMovement::Tank:
			pros::lcd::print(i, "Tank Movement");
			tankControl();
			break;

		case Config::DrivetrainMovement::SingleStickArcade:
			pros::lcd::print(i, "Single Stick Arcade Movement");
			singleStickArcadeControl();
			break;

		case Config::DrivetrainMovement::DoubleStickArcade:
			pros::lcd::print(i, "Double Stick Arcade Movement");
			doubleStickArcadeControl();
			break;

		case Config::DrivetrainMovement::SingleStickCurvature:
			pros::lcd::print(i, "Single Stick Curvature Movement");
			singleStickCurvatureControl();
			break;

		case Config::DrivetrainMovement::DoubleStickCurvature:
			pros::lcd::print(i, "Double Stick Curvature Movement");
			doubleStickCurvatureControl();
			break;
	}

	++i;
}
