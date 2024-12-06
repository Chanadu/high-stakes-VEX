#include "opcontrol/device-controller.hpp"
#include "configuration.hpp"
#include "devices.hpp"

void intakeMotorControl() {
	const int motorPower =
		static_cast<int>((Devices::controller.get_digital(Devices::intakeInButton) -
						  Devices::controller.get_digital(Devices::intakeOutButton)) *
						 127 * Config::intakeVelocity);

	// ReSharper disable once CppExpressionWithoutSideEffects
	Devices::intakeMotorGroup.move(motorPower);
	Config::controllerStrings[2] =
		fmt::format("IT: {:.2} {:.2}", Devices::intakeMotorGroup.get_torque_all()[0],
					Devices::intakeMotorGroup.get_torque_all()[1]);
}

void armMotorControl() {
	const int motorPower = (Devices::controller.get_digital(Devices::armInButton) -
							Devices::controller.get_digital(Devices::armOutButton)) *
						   127;
	// ReSharper disable once CppExpressionWithoutSideEffects
	Devices::intakeMotorGroup.move(motorPower);
}

void holderPistonControl() {
	if (Devices::controller.get_digital_new_press(Devices::holderPistonButton)) {
		Devices::holderPiston.toggle();
	}
}
