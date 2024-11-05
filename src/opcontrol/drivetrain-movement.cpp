#include "main.h"
#include "utils/config-enums.hpp"

void tankControl(pros::Controller& controller, lemlib::Chassis& chassis) {
	int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
	chassis.tank(leftY, rightY);
}
void singleStickArcadeControl(pros::Controller& controller, lemlib::Chassis& chassis) {
	int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
	chassis.arcade(leftY, leftX);
}
void doubleStickArcadeControl(pros::Controller& controller, lemlib::Chassis& chassis) {
	int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	chassis.arcade(leftY, rightX);
}
void singleStickCurvatureControl(pros::Controller& controller, lemlib::Chassis& chassis) {
	int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
	chassis.curvature(leftY, leftX);
}
void doubleStickCurvatureControl(pros::Controller& controller, lemlib::Chassis& chassis) {
	int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	chassis.curvature(leftY, rightX);
}

void drivetrainMovementController(pros::Controller& controller,
								  lemlib::Chassis& chassis,
								  DrivetrainMovement& drivetrainMovement,
								  int& i) {
	pros::lcd::clear_line(i);

	switch (drivetrainMovement) {
		case DrivetrainMovement::TankMovement:
			pros::lcd::print(i, "Tank Movement");
			tankControl(controller, chassis);
			break;

		case DrivetrainMovement::SingleStickArcadeMovement:
			pros::lcd::print(i, "Single Stick Arcade Movement");
			singleStickArcadeControl(controller, chassis);
			break;

		case DrivetrainMovement::DoubleStickArcadeMovement:
			pros::lcd::print(i, "Double Stick Arcade Movement");
			doubleStickArcadeControl(controller, chassis);
			break;

		case DrivetrainMovement::SingleStickCurvatureMovement:
			pros::lcd::print(i, "Single Stick Curvature Movement");
			singleStickCurvatureControl(controller, chassis);
			break;

		case DrivetrainMovement::DoubleStickCurvatureMovement:
			pros::lcd::print(i, "Double Stick Curvature Movement");
			doubleStickCurvatureControl(controller, chassis);
			break;
	}

	++i;
}
