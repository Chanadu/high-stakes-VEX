#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"

void batteryDisplay(short& lineNumber) {
	const double batteryPercentage = pros::battery::get_capacity();
	// pros::screen::set_pen(batteryPercentage < 50   ? pros::Color::red
	// 					  : batteryPercentage < 75 ? pros::Color::yellow
	// 											   : pros::Color::green);
	pros::lcd::print(lineNumber++, "Battery: %3d%%", static_cast<int>(batteryPercentage));
	const int controllerBatteryPercentage = Devices::controller.get_battery_capacity();
	Config::controllerStrings[0] =
		std::format("Battery:{:>3}%", static_cast<int>(batteryPercentage));
	// pros::screen::set_pen(controllerBatteryPercentage < 50 ? pros::Color::red
	// 					  : controllerBatteryPercentage < 75
	// 						  ? pros::Color::yellow
	// 						  : pros::Color::green);
	pros::lcd::print(lineNumber++, "Controller Battery: %3d%%", controllerBatteryPercentage);
}

void chassisPositionDisplay(short& lineNumber) {
	pros::lcd::print(lineNumber++, "Drivetrain X: %5.2f", Devices::chassis.getPose().x);
	pros::lcd::print(lineNumber++, "Drivetrain Y: %5.2f", Devices::chassis.getPose().y);
	pros::lcd::print(lineNumber++, "Drivetrain Theta: %5.2f", Devices::chassis.getPose().theta);
}
