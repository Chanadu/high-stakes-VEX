#include "main.h"

#include "autonomous/autonomous.hpp"
#include "configuration.hpp"
#include "devices.hpp"
#include "opcontrol/opcontrol.hpp"

[[noreturn]] void controllerLinePrinting(void* param) {
	while (true) {
		for (int i = 0; i < 3; i++) {
			Devices::controller.set_text(i, 0, fmt::format("{:<15}", Config::controllerStrings[i]));
			pros::delay(50);
		}
		if (!Config::controllerRumblePattern.empty()) {
			Devices::controller.rumble(Config::controllerRumblePattern.c_str());
			Config::controllerRumblePattern = "";
			pros::delay(50);
		}
	}
}
void initialize() {
	initializeDevices();
	pros::Task(controllerLinePrinting, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT,
			   "Controller Line Task");
}

void autonomous() {
	autonomousRunner();
}

void opcontrol() {
	opcontrolRunner();
}

void competition_initialize() {}

void disabled() {}
