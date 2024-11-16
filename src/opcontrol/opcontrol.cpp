#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"
#include "opcontrol/change-drivetrain-movement-button.hpp"
#include "opcontrol/drivetrain-movement.hpp"
#include "opcontrol/gui.hpp"
#include "screen-displays.hpp"

void intakeMotorControl() {
	if (Devices::controller.get_digital(Devices::intakeInButton) ||
		Devices::controller.get_digital(Devices::intakeOutButton)) {
		const int motorPower = Devices::controller.get_digital(Devices::intakeInButton) * 127 -
							   Devices::controller.get_digital(Devices::intakeOutButton) * 127;
		// ReSharper disable once CppExpressionWithoutSideEffects
		Devices::intakeMotorGroup.move(motorPower);
	}
}

void armMotorControl() {
	if (Devices::controller.get_digital(Devices::armInButton) ||
		Devices::controller.get_digital(Devices::armOutButton)) {
		const int motorPower = Devices::controller.get_digital(Devices::armInButton) * 127 -
							   Devices::controller.get_digital(Devices::armOutButton) * 127;
		// ReSharper disable once CppExpressionWithoutSideEffects
		Devices::intakeMotorGroup.move(motorPower);
	}
}

void holderPistonControl() {
	if (Devices::controller.get_digital_new_press(Devices::holderPistonButton)) {
		Devices::holderPiston.toggle();
	}
}

[[noreturn]] void opcontrolRunner() {
	pros::lcd::register_btn1_cb(changeDrivetrainMovement);
	while (true) {
		short lineNumber = 0;

		batteryDisplay(lineNumber);
		lineNumber++;
		drivetrainMovementController(lineNumber);
		if (Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
			changeDrivetrainMovement();
		}
		intakeMotorControl();

		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
		// gui();
		pros::delay(20);
	}
}
