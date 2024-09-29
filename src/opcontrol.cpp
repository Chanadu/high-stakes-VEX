#include <map>
#include <vector>
#include "configuration.hpp"
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

std::map<std::string, int> arcadeControl(void) {
	int direction =
		controller.get_analog(ANALOG_LEFT_Y) * movementVelocityPercentage;
	int turn =
		controller.get_analog(ANALOG_RIGHT_X) * turningVelocityPercentage;

	int joystickThreshold = joystickThresholdPercentage * 127;

	if (controller.get_analog(ANALOG_LEFT_Y) < joystickThreshold &&
		controller.get_analog(ANALOG_LEFT_Y) > -joystickThreshold)
		direction = 0;

	if (controller.get_analog(ANALOG_RIGHT_X) < joystickThreshold &&
		controller.get_analog(ANALOG_RIGHT_X) > -joystickThreshold)
		turn = 0;

	leftMotorGroup.move(direction - turn);
	rightMotorGroup.move(direction + turn);
	return std::map<std::string, int>{{"direction", direction},
									  {"turn", turn},
									  {"leftMotorGroup", direction - turn},
									  {"rightMotorGroup", direction + turn},
									  {"joystickThreshold", joystickThreshold}};
}

int batteryDisplay(int i) {
	int batteryPercentage = pros::battery::get_capacity();
	pros::screen::set_pen(batteryPercentage < 50   ? pros::Color::red
						  : batteryPercentage < 75 ? pros::Color::yellow
												   : pros::Color::green);
	pros::screen::print(TEXT_LARGE_CENTER, i++, "Battery: %3d%%",
						batteryPercentage);
	i++;

	int controllerBatteryPercentage = controller.get_battery_capacity();
	pros::screen::set_pen(controllerBatteryPercentage < 50 ? pros::Color::red
						  : controllerBatteryPercentage < 75
							  ? pros::Color::yellow
							  : pros::Color::green);
	pros::screen::print(TEXT_MEDIUM_CENTER, i++, "Controller Battery: %3d%%",
						controllerBatteryPercentage);
	return i;
}

void opcontrol() {
	while (true) {
		// Prints status of the emulated screen LCDs
		// pros::lcd::print(0, "%d %d %d",
		// 				 (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		// 				 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		// 				 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		//
		// pros::lcd::print(2, "Testing Testing");
		// pros::screen::print(TEXT_MEDIUM, 1, "Hello, PROS User!");
		// pros::screen::print(TEXT_MEDIUM, 2, "Hello, PROS User!");
		// pros::screen::print(TEXT_MEDIUM, 3, "Hello, PROS User!");

		int i = 0;
		i = batteryDisplay(i);
		i++;

		std::map<std::string, int> values = arcadeControl();
		pros::screen::set_pen(pros::Color::white);
		for (auto const& [name, val] : values) {
			pros::screen::print(TEXT_MEDIUM, i, "%s: %4d", name.c_str(), val);
			i++;
		}

		// Run for 20 ms then update
		pros::delay(20);
	}
}
