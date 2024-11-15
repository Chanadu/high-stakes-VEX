#include "main.h"
#include "autonomous/autonomous.hpp"
#include "devices.hpp"
#include "opcontrol/opcontrol.hpp"

void initialize() {
	initializeDevices();
}

void autonomous() {
	autonomousRunner();
}

void opcontrol() {
	opcontrolRunner();
}

void competition_initialize() {}

void disabled() {}
