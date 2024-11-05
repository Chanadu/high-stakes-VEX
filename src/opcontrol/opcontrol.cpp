#include "main.h"
#include "opcontrol/drivetrain-movement.hpp"
#include "utils/config-enums.hpp"
#include "utils/global-data.hpp"
#include "utils/screen-displays.hpp"

void on_center_button() {
	switch (drivetrainMovement) {
		case DrivetrainMovement::TANK_MOVEMENT:
			drivetrainMovement =
				DrivetrainMovement::SINGLE_STICK_ARCADE_MOVEMENT;
			break;

		case DrivetrainMovement::SINGLE_STICK_ARCADE_MOVEMENT:
			drivetrainMovement =
				DrivetrainMovement::DOUBLE_STICK_ARCADE_MOVEMENT;
			break;

		case DrivetrainMovement::DOUBLE_STICK_ARCADE_MOVEMENT:
			drivetrainMovement =
				DrivetrainMovement::SINGLE_STICK_CURVATURE_MOVEMENT;
			break;

		case DrivetrainMovement::SINGLE_STICK_CURVATURE_MOVEMENT:
			drivetrainMovement =
				DrivetrainMovement::DOUBLE_STICK_CURVATURE_MOVEMENT;
			break;

		case DrivetrainMovement::DOUBLE_STICK_CURVATURE_MOVEMENT:
			drivetrainMovement = DrivetrainMovement::TANK_MOVEMENT;
			break;
	}
}

void opcontrolRunner(pros::Controller* controller,
					 lemlib::Chassis* chassis,
					 DrivetrainMovement* drivetrainMovement) {
	pros::lcd::register_btn1_cb(on_center_button);
	while (true) {
		int i = 0;
		batteryDisplay(controller, &i);
		i++;
		drivetrainMovementController(controller, chassis, drivetrainMovement,
									 &i);

		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
		pros::delay(20);
	}
}
