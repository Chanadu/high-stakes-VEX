#include "main.h"
#include "autonomous/autonomous.hpp"
#include "configuration.hpp"
#include "lemlib/api.hpp"  // IWYU pragma: keep
#include "opcontrol/opcontrol.hpp"
#include "setup-devices.hpp"
#include "utils/global-data.hpp"

void initialize(void) {
	// initializeDevices(Devices::chassis);
}

void autonomous(void) {
	// autonomousRunner(Devices::controller, Devices::chassis);
}

void opcontrol(void) {
	// opcontrolRunner(Devices::controller, Devices::chassis, drivetrainMovement);
}

void competition_initialize(void) {}

void disabled(void) {}
