#include "configuration.hpp"
#include "lemlib/api.hpp"
#include "main.h"
#include "setup-devices.hpp"

int batteryDisplay(pros::Controller* controller, int i) {
	int batteryPercentage = pros::battery::get_capacity();
	pros::screen::set_pen(batteryPercentage < 50   ? pros::Color::red
						  : batteryPercentage < 75 ? pros::Color::yellow
												   : pros::Color::green);
	pros::screen::print(pros::E_TEXT_LARGE_CENTER, i++, "Battery: %3d%%",
						batteryPercentage);
	++i;

	int controllerBatteryPercentage = controller->get_battery_capacity();
	pros::screen::set_pen(controllerBatteryPercentage < 50 ? pros::Color::red
						  : controllerBatteryPercentage < 75
							  ? pros::Color::yellow
							  : pros::Color::green);
	pros::screen::print(pros::E_TEXT_MEDIUM_CENTER, i++,
						"Controller Battery: %3d%%",
						controllerBatteryPercentage);
	return i;
}
