#include "opcontrol/change-drivetrain-movement-button.hpp"
#include "configuration.hpp"
#include "main.h"

void changeDrivetrainMovement() {
	switch (Config::drivetrainMovement) {
		case Config::DrivetrainMovement::Tank:
			Config::drivetrainMovement =
				Config::DrivetrainMovement::SingleStickArcade;
			break;

		case Config::DrivetrainMovement::SingleStickArcade:
			Config::drivetrainMovement =
				Config::DrivetrainMovement::DoubleStickArcade;
			break;

		case Config::DrivetrainMovement::DoubleStickArcade:
			Config::drivetrainMovement =
				Config::DrivetrainMovement::SingleStickCurvature;
			break;

		case Config::DrivetrainMovement::SingleStickCurvature:
			Config::drivetrainMovement =
				Config::DrivetrainMovement::DoubleStickCurvature;
			break;

		case Config::DrivetrainMovement::DoubleStickCurvature:
			Config::drivetrainMovement = Config::DrivetrainMovement::Tank;
			break;
	}
}
