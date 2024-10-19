#include <map>
#include <vector>
#include "configuration.hpp"
#include "lemlib/api.hpp"
#include "main.h"
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

int batteryDisplay(int i) {
	int batteryPercentage = pros::battery::get_capacity();
	pros::screen::set_pen(batteryPercentage < 50   ? pros::Color::red
						  : batteryPercentage < 75 ? pros::Color::yellow
												   : pros::Color::green);
	pros::screen::print(TEXT_LARGE_CENTER, i++, "Battery: %3d%%",
						batteryPercentage);
	++i;

	int controllerBatteryPercentage = controller.get_battery_capacity();
	pros::screen::set_pen(controllerBatteryPercentage < 50 ? pros::Color::red
						  : controllerBatteryPercentage < 75
							  ? pros::Color::yellow
							  : pros::Color::green);
	pros::screen::print(TEXT_MEDIUM_CENTER, i++, "Controller Battery: %3d%%",
						controllerBatteryPercentage);
	return i;
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

void opcontrol() {
	while (true) {
		int i = 0;
		i = batteryDisplay(i);
		++i;

		// std::map<std::string, int> values = arcadeControl();
		// pros::screen::set_pen(pros::Color::white);
		// for (auto const& [name, val] : values) {
		// 	pros::screen::print(TEXT_MEDIUM, i++, "%s: %4d", name.c_str(), val);
		// }

		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
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

		pros::delay(20);
	}
}
