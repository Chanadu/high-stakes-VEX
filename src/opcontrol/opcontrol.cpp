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
		Devices::controller.set_text(0, 0, Config::controllerStrings[0]);
		pros::delay(50);
		Devices::controller.set_text(1, 0, Config::controllerStrings[1]);
		pros::delay(50);
		Devices::controller.set_text(2, 0, Config::controllerStrings[2]);
		pros::delay(50);
	}
}

[[noreturn]] void opcontrolRunner() {
	pros::lcd::register_btn1_cb(changeDrivetrainMovement);
	pros::Task controllerLinePrintingTask(controllerLinePrinting, nullptr, TASK_PRIORITY_DEFAULT,
										  TASK_STACK_DEPTH_DEFAULT, "Controller Line Task");

	while (true) {
		short lineNumber = 0;

		batteryDisplay(lineNumber);
		lineNumber++;
		drivetrainMovementController(lineNumber);
		if (Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
			changeDrivetrainMovement(lineNumber);
		}

		intakeMotorControl();
		armMotorControl();
		holderPistonControl();
		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
		// gui();
		pros::delay(20);
	}
}
