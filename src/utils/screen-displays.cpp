#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"

void batteryDisplay(int& i) {
	int batteryPercentage = pros::battery::get_capacity();
	// pros::screen::set_pen(batteryPercentage < 50   ? pros::Color::red
	// 					  : batteryPercentage < 75 ? pros::Color::yellow
	// 											   : pros::Color::green);
	pros::lcd::print(i++, "Battery: %3d%%", batteryPercentage);
	int controllerBatteryPercentage = Devices::controller.get_battery_capacity();
	// pros::screen::set_pen(controllerBatteryPercentage < 50 ? pros::Color::red
	// 					  : controllerBatteryPercentage < 75
	// 						  ? pros::Color::yellow
	// 						  : pros::Color::green);
	pros::lcd::print(i++, "Controller Battery: %3d%%", controllerBatteryPercentage);
}

void chassisPositionDisplay(int& i) {
	pros::lcd::print(i++, "Drivetrain X: %5.2f", Devices::chassis.getPose().x);
	pros::lcd::print(i++, "Drivetrain Y: %5.2f", Devices::chassis.getPose().y);
	pros::lcd::print(i++, "Drivetrain Theta: %5.2f", Devices::chassis.getPose().theta);
}
