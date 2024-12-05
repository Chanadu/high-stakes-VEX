#include "opcontrol/device-controller.hpp"
#include "configuration.hpp"
#include "devices.hpp"

void intakeMotorControl() {
	if (Devices::controller.get_digital(Devices::intakeInButton) ||
		Devices::controller.get_digital(Devices::intakeOutButton)) {
		const int motorPower =
			static_cast<int>((Devices::controller.get_digital(Devices::intakeInButton) -
							  Devices::controller.get_digital(Devices::intakeOutButton)) *
							 127 * Config::intakeVelocity);
		Devices::intakeMotorGroup.move(motorPower);
		Config::controllerStrings[2] =
			fmt::format("IT: {}, {}", static_cast<int>(Devices::intakeMotorGroup.get_torque(0)),
						static_cast<int>(Devices::intakeMotorGroup.get_torque(1)));
	}
}

void armMotorControl() {
	if (Devices::controller.get_digital(Devices::armInButton) ||
		Devices::controller.get_digital(Devices::armOutButton)) {
		const int motorPower = (Devices::controller.get_digital(Devices::armInButton) -
								Devices::controller.get_digital(Devices::armOutButton)) *
							   127;
		Devices::intakeMotorGroup.move(motorPower);
		// Config::controllerStrings[2] = "Arm: " + fmt::format("{}", motorPower);
	}
}

void holderPistonControl() {
	if (Devices::controller.get_digital_new_press(Devices::holderPistonButton)) {
		Devices::holderPiston.toggle();
		// Config::controllerStrings[2] =
		// 	fmt::format("Piston: {}", Devices::holderPiston.is_extended());
	}
}
