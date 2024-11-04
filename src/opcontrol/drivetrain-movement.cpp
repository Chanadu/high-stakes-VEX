#include "lemlib/api.hpp"
#include "main.h"

void drivetrainMovement(lemlib::Chassis* chassis) {}

void tankControl(pros::Controller* controller, lemlib::Chassis* chassis) {
	int leftY = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightY = controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
	chassis->tank(leftY, rightY);
}
void singleStickArcadeControl(pros::Controller* controller,
							  lemlib::Chassis* chassis) {
	int leftY = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int leftX = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
	chassis->arcade(leftY, leftX);
}
void doubleStickArcadeControl(pros::Controller* controller,
							  lemlib::Chassis* chassis) {
	int leftY = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightX = controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	chassis->arcade(leftY, rightX);
}
void singleStickCurvatureControl(pros::Controller* controller,
								 lemlib::Chassis* chassis) {
	int leftY = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int leftX = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
	chassis->curvature(leftY, leftX);
}
void doubleStickCurvatureControl(pros::Controller* controller,
								 lemlib::Chassis* chassis) {
	int leftY = controller->get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightX = controller->get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	chassis->curvature(leftY, rightX);
}

int chassisPositionDisplay(lemlib::Chassis* chassis, int i) {
	pros::screen::print(TEXT_MEDIUM, i++, "Drivetrain X: %5.2f",
						chassis->getPose().x);
	pros::screen::print(TEXT_MEDIUM, i++, "Drivetrain Y: %5.2f",
						chassis->getPose().y);
	pros::screen::print(TEXT_MEDIUM, i++, "Drivetrain Theta: %5.2f",
						chassis->getPose().theta);
	return i;
}

int drivetrainMovementButton(DrivetrainMovement* drivetrainMovementType,
							 int i) {
	pros::lcd::register_btn1_cb([]() {
		// int movementType = drivetrainMovementType;
		// movementType++;
		// drivetrainMovementType =
		// 	static_cast<DrivetrainMovementType>(movementType % 5);
		return;
	});
	// pros::screen::print(TEXT_MEDIUM, i++, "DrivetrainMovementType: %d",
	// 					drivetrainMovementType);
	pros::screen::print(TEXT_MEDIUM, i, "%100s", "");
	switch (*drivetrainMovementType) {
		case DrivetrainMovement::TANK_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++, "Tank Movement");
			break;
		case DrivetrainMovement::SINGLE_STICK_ARCADE_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++,
								"Single Stick Arcade Movement");
			break;
		case DrivetrainMovement::DOUBLE_STICK_ARCADE_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++,
								"Double Stick Arcade Movement");
			break;
		case DrivetrainMovement::SINGLE_STICK_CURVATURE_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++,
								"Single Stick Curvature Movement");
			break;
		case DrivetrainMovement::DOUBLE_STICK_CURVATURE_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++,
								"Double Stick Curvature Movement");
			break;
	}
	return i;
}
