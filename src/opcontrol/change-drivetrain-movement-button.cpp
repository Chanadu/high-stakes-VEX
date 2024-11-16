#include "opcontrol/change-drivetrain-movement-button.hpp"
#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"

void changeDrivetrainMovement() {
	switch (Config::drivetrainMovement) {
		case Config::DrivetrainMovement::Tank:
			Config::drivetrainMovement = Config::DrivetrainMovement::SingleStickArcade;
			Devices::controller.print(0, 0, "Changed Drivetrain Movement to SSA");
			break;

		case Config::DrivetrainMovement::SingleStickArcade:
			Config::drivetrainMovement = Config::DrivetrainMovement::DoubleStickArcade;
			Devices::controller.print(0, 0, "Changed Drivetrain Movement to DSA");
			break;

		case Config::DrivetrainMovement::DoubleStickArcade:
			Config::drivetrainMovement = Config::DrivetrainMovement::SingleStickCurvature;
			Devices::controller.print(0, 0, "Changed Drivetrain Movement to SSC");
			break;

		case Config::DrivetrainMovement::SingleStickCurvature:
			Config::drivetrainMovement = Config::DrivetrainMovement::DoubleStickCurvature;
			Devices::controller.print(0, 0, "Changed Drivetrain Movement to DSC");
			break;

		case Config::DrivetrainMovement::DoubleStickCurvature:
			Config::drivetrainMovement = Config::DrivetrainMovement::Tank;
			Devices::controller.print(0, 0, "Changed Drivetrain Movement to Tank");
			break;
	}
	Devices::controller.print(1, 0, "Changed Drivetrain Movement to Tank");
}
