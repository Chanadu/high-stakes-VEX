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
void opcontrol() {
	while (true) {
		// Prints status of the emulated screen LCDs
		// pros::lcd::print(0, "%d %d %d",
		// 				 (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		// 				 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		// 				 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		//
		// pros::lcd::print(2, "Testing Testing");
		pros::screen::print(TEXT_MEDIUM, 1, "Hello, PROS User!");
		pros::screen::print(TEXT_MEDIUM, 2, "Hello, PROS User!");
		pros::screen::print(TEXT_MEDIUM, 3, "Hello, PROS User!");

		// Arcade control scheme
		int direction = controller.get_analog(ANALOG_LEFT_Y);
		int turn = controller.get_analog(ANALOG_RIGHT_X);
		leftMotorGroup.move(direction - turn);
		rightMotorGroup.move(direction + turn);

		// Run for 20 ms then update
		pros::delay(20);
	}
}
