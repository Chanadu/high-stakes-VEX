#include "opcontrol/device-controller.hpp"
#include "devices.hpp"

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
