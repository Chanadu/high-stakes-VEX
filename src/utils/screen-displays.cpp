#include "screen-displays.hpp"
#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"

void batteryDisplay(short& lineNumber) {
	const double batteryPercentage = pros::battery::get_capacity();
	pros::lcd::print(lineNumber++, "Battery: %3d%%", static_cast<int>(batteryPercentage));
	Config::controllerStrings[0] = fmt::format("Battery: {}%", static_cast<int>(batteryPercentage));

	const int controllerBatteryPercentage = Devices::controller.get_battery_capacity();
	pros::lcd::print(lineNumber++, "Controller Battery: %3d%%", controllerBatteryPercentage);
}

void chassisPositionDisplay(short& lineNumber) {
	pros::lcd::print(lineNumber++, "DT (X, Y, A): (%5.2f, %5.2f, %5.2f)",
					 Devices::chassis.getPose().x, Devices::chassis.getPose().y,
					 Devices::chassis.getPose().theta);
}

void drivetrainTorqueDisplay(short& lineNumber) {
	pros::lcd::print(
		lineNumber++, "L: %4.2f %4.2f %4.2f R: %4.2f %4.2f %4.2f",
		Devices::leftMotorGroup.get_torque_all()[0], Devices::leftMotorGroup.get_torque_all()[1],
		Devices::leftMotorGroup.get_torque_all()[2], Devices::rightMotorGroup.get_torque_all()[0],
		Devices::rightMotorGroup.get_torque_all()[1], Devices::rightMotorGroup.get_torque_all()[2]);
}

void clearScreen() {
	for (short i = 0; i < 12; i++) {
		pros::lcd::clear_line(i);
	}
}
