#include "main.h"
#include "utils/config-enums.hpp"
#include "utils/global-data.hpp"

void on_center_button() {
	switch (drivetrainMovement) {
		case DrivetrainMovement::TANK_MOVEMENT:
			drivetrainMovement = DrivetrainMovement::SINGLE_STICK_ARCADE_MOVEMENT;
			break;

		case DrivetrainMovement::SINGLE_STICK_ARCADE_MOVEMENT:
			drivetrainMovement = DrivetrainMovement::DOUBLE_STICK_ARCADE_MOVEMENT;
			break;

		case DrivetrainMovement::DOUBLE_STICK_ARCADE_MOVEMENT:
			drivetrainMovement = DrivetrainMovement::SINGLE_STICK_CURVATURE_MOVEMENT;
			break;

		case DrivetrainMovement::SINGLE_STICK_CURVATURE_MOVEMENT:
			drivetrainMovement = DrivetrainMovement::DOUBLE_STICK_CURVATURE_MOVEMENT;
			break;

		case DrivetrainMovement::DOUBLE_STICK_CURVATURE_MOVEMENT:
			drivetrainMovement = DrivetrainMovement::TANK_MOVEMENT;
			break;
	}
}
