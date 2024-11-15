#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"
#include "opcontrol/change-drivetrain-movement-button.hpp"
#include "opcontrol/drivetrain-movement.hpp"
#include "opcontrol/gui.hpp"
#include "screen-displays.hpp"

[[noreturn]]void opcontrolRunner() {
	pros::lcd::register_btn1_cb(on_center_button);
	while (true) {
		int i = 0;

		batteryDisplay(Devices::controller, i);
		i++;
		drivetrainMovementController(i);

		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
		// gui();
		pros::delay(20);
	}
}
