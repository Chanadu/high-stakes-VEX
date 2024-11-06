#include "main.h"
#include "opcontrol/change-drivetrain-movement-button.hpp"
#include "opcontrol/drivetrain-movement.hpp"
#include "opcontrol/gui.hpp"
#include "utils/config-enums.hpp"
#include "utils/global-data.hpp"
#include "utils/screen-displays.hpp"

void opcontrolRunner(pros::Controller& controller,
					 lemlib::Chassis& chassis,
					 DrivetrainMovement& drivetrainMovement) {
	pros::lcd::register_btn1_cb(on_center_button);
	while (true) {
		int i = 0;

		batteryDisplay(controller, i);
		i++;
		drivetrainMovementController(controller, chassis, drivetrainMovement, i);

		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
		// gui();
		pros::delay(20);
	}
}
