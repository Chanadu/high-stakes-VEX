#include "lemlib/api.hpp"
#include "main.h"
#include "utils/config-enums.hpp"
#include "utils/screen-displays.hpp"
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
// vnoremap
// 	leftMotorGroup.move(direction - turn);
// 	rightMotorGroup.move(direction + turn);
// 	return std::map<std::string, int>{{"direction", direction},
// 									  {"turn", turn},
// 									  {"leftMotorGroup", direction - turn},
// 									  {"rightMotorGroup", direction + turn},
// 									  {"joystickThreshold", joystickThreshold}};
// }
void opcontrolRunner(pros::Controller* controller,
					 lemlib::Chassis* chassis,
					 DrivetrainMovement* drivetrainMovementType) {
	while (true) {
		int i = 0;
		i = batteryDisplay(controller, i++);
		i = drivetrainMovementButton(drivetrainMovementType, i);

		switch (*drivetrainMovementType) {
			case DrivetrainMovement::TANK_MOVEMENT:
				tankControl(controller, chassis);
				break;
			case DrivetrainMovement::SINGLE_STICK_ARCADE_MOVEMENT:
				singleStickArcadeControl(controller, chassis);
				break;
			case DrivetrainMovement::DOUBLE_STICK_ARCADE_MOVEMENT:
				doubleStickArcadeControl(controller, chassis);
				break;
			case DrivetrainMovement::SINGLE_STICK_CURVATURE_MOVEMENT:
				singleStickCurvatureControl(controller, chassis);
				break;
			case DrivetrainMovement::DOUBLE_STICK_CURVATURE_MOVEMENT:
				doubleStickCurvatureControl(controller, chassis);
				break;
		}

		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
		pros::delay(20);
	}
}
