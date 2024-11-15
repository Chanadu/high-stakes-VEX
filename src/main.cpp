#include "main.h"

#include <configuration.hpp>

#include "autonomous/autonomous.hpp"
#include "devices.hpp"
#include "opcontrol/opcontrol.hpp"

void initialize(void) {
	initializeDevices(Devices::chassis);
}

void autonomous(void) {
	autonomousRunner(Devices::controller, Devices::chassis);
}

void opcontrol(void) {
	opcontrolRunner(Devices::controller, Devices::chassis, Config::drivetrainMovement);
}

void competition_initialize(void) {}

void disabled(void) {}
