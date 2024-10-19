#include <map>
#include <vector>
#include "configuration.hpp"
#include "lemlib/api.hpp"
#include "main.h"
#include "screen-displays.hpp"
#include "setup-devices.hpp"
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

// std::map<std::string, int> arcadeControl(void) {
// 	int direction =
// 		controller.get_analog(ANALOG_LEFT_Y) * movementVelocityPercentage;
// 	int turn =
// 		controller.get_analog(ANALOG_RIGHT_X) * turningVelocityPercentage;
//
// 	int joystickThreshold = joystickThresholdPercentage * 127;
//
// 	if (controller.get_analog(ANALOG_LEFT_Y) < joystickThreshold &&
// 		controller.get_analog(ANALOG_LEFT_Y) > -joystickThreshold)
// 		direction = 0;
//
// 	if (controller.get_analog(ANALOG_RIGHT_X) < joystickThreshold &&
// 		controller.get_analog(ANALOG_RIGHT_X) > -joystickThreshold)
// 		turn = 0;
//
// 	leftMotorGroup.move(direction - turn);
// 	rightMotorGroup.move(direction + turn);
// 	return std::map<std::string, int>{{"direction", direction},
// 									  {"turn", turn},
// 									  {"leftMotorGroup", direction - turn},
// 									  {"rightMotorGroup", direction + turn},
// 									  {"joystickThreshold", joystickThreshold}};
// }
void tankControl(void) {
	int leftY = controller.get_analog(ANALOG_LEFT_Y);
	int rightY = controller.get_analog(ANALOG_RIGHT_Y);
	chassis.tank(leftY, rightY);
}
void singleStickArcadeControl(void) {
	int leftY = controller.get_analog(ANALOG_LEFT_Y);
	int leftX = controller.get_analog(ANALOG_LEFT_X);
	chassis.arcade(leftY, leftX);
}
void doubleStickArcadeControl(void) {
	int leftY = controller.get_analog(ANALOG_LEFT_Y);
	int rightX = controller.get_analog(ANALOG_RIGHT_X);
	chassis.arcade(leftY, rightX);
}
void singleStickCurvatureControl(void) {
	int leftY = controller.get_analog(ANALOG_LEFT_Y);
	int leftX = controller.get_analog(ANALOG_LEFT_X);
	chassis.curvature(leftY, leftX);
}
void doubleStickCurvatureControl(void) {
	int leftY = controller.get_analog(ANALOG_LEFT_Y);
	int rightX = controller.get_analog(ANALOG_RIGHT_X);
	chassis.curvature(leftY, rightX);
}

int chassisPositionDisplay(int i) {
	pros::screen::print(TEXT_MEDIUM, i++, "Drivetrain X: %5.2f",
						chassis.getPose().x);
	pros::screen::print(TEXT_MEDIUM, i++, "Drivetrain Y: %5.2f",
						chassis.getPose().y);
	pros::screen::print(TEXT_MEDIUM, i++, "Drivetrain Theta: %5.2f",
						chassis.getPose().theta);
	return i;
}

int drivetrainMovementTypeButton(int i) {
	pros::lcd::register_btn1_cb([]() {
		int movementType = drivetrainMovementType;
		movementType++;
		drivetrainMovementType =
			static_cast<DrivetrainMovementType>(movementType % 5);
		return;
	});
	// pros::screen::print(TEXT_MEDIUM, i++, "DrivetrainMovementType: %d",
	// 					drivetrainMovementType);
	pros::screen::print(TEXT_MEDIUM, i, "%100s", "");
	switch (drivetrainMovementType) {
		case TANK_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++, "Tank Movement");
			break;
		case SINGLE_STICK_ARCADE_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++,
								"Single Stick Arcade Movement");
			break;
		case DOUBLE_STICK_ARCADE_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++,
								"Double Stick Arcade Movement");
			break;
		case SINGLE_STICK_CURVATURE_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++,
								"Single Stick Curvature Movement");
			break;
		case DOUBLE_STICK_CURVATURE_MOVEMENT:
			pros::screen::print(TEXT_MEDIUM_CENTER, i++,
								"Double Stick Curvature Movement");
			break;
	}
	return i;
}

void opcontrol() {
	while (true) {
		int i = 0;
		i = batteryDisplay(i++);
		i = drivetrainMovementTypeButton(i);

		switch (drivetrainMovementType) {
			case TANK_MOVEMENT:
				tankControl();
				break;
			case SINGLE_STICK_ARCADE_MOVEMENT:
				singleStickArcadeControl();
				break;
			case DOUBLE_STICK_ARCADE_MOVEMENT:
				doubleStickArcadeControl();
				break;
			case SINGLE_STICK_CURVATURE_MOVEMENT:
				singleStickCurvatureControl();
				break;
			case DOUBLE_STICK_CURVATURE_MOVEMENT:
				doubleStickCurvatureControl();
				break;
		}

		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
		pros::delay(20);
	}
}
