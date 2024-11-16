#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"
#include "opcontrol/change-drivetrain-movement-button.hpp"
#include "opcontrol/device-controller.hpp"
#include "opcontrol/drivetrain-movement.hpp"
#include "opcontrol/gui.hpp"
#include "screen-displays.hpp"

[[noreturn]] void controllerLinePrinting(void* param) {
	while (true) {
		for (int i = 0; i < 3; i++) {
			Devices::controller.set_text(i, 0, std::format("{:<15}", Config::controllerStrings[i]));
			pros::delay(50);
		}
		if (!Config::controllerRumblePattern.empty()) {
			Devices::controller.rumble(Config::controllerRumblePattern.c_str());
			Config::controllerRumblePattern = "";
		}
		pros::delay(50);
	}
}

[[noreturn]] void opcontrolRunner() {
	pros::lcd::register_btn1_cb(incrementDrivetrainMovement);
	pros::Task controllerLinePrintingTask(controllerLinePrinting, nullptr, TASK_PRIORITY_DEFAULT,
										  TASK_STACK_DEPTH_DEFAULT, "Controller Line Task");

	while (true) {
		short lineNumber = 0;

		batteryDisplay(lineNumber);
		lineNumber++;
		drivetrainMovementController(lineNumber);
		if (Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
			incrementDrivetrainMovement(lineNumber);
		}
		if (Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			Config::controllerRumblePattern = ".-.-..";
		};
		intakeMotorControl();
		armMotorControl();
		holderPistonControl();

		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
		// gui();
		pros::delay(20);
	}
}
