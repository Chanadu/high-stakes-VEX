#include "main.h"
#include "utils/config-enums.hpp"
#include "utils/global-data.hpp"

void on_center_button() {
	switch (drivetrainMovement) {
		case DrivetrainMovement::TankMovement:
			drivetrainMovement = DrivetrainMovement::SingleStickArcadeMovement;
			break;

		case DrivetrainMovement::SingleStickArcadeMovement:
			drivetrainMovement = DrivetrainMovement::DoubleStickArcadeMovement;
			break;

		case DrivetrainMovement::DoubleStickArcadeMovement:
			drivetrainMovement = DrivetrainMovement::SingleStickCurvatureMovement;
			break;

		case DrivetrainMovement::SingleStickCurvatureMovement:
			drivetrainMovement = DrivetrainMovement::DoubleStickCurvatureMovement;
			break;

		case DrivetrainMovement::DoubleStickCurvatureMovement:
			drivetrainMovement = DrivetrainMovement::TankMovement;
			break;
	}
}
