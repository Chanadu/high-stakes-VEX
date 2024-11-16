#include "opcontrol/change-drivetrain-movement-button.hpp"
#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"

void changeDrivetrainMovement() {
	short i = 0;
	changeDrivetrainMovement(i);
}
void changeDrivetrainMovement(short& lineNumber) {
	std::string drivetrainMovementString;
	switch (Config::drivetrainMovement) {
		case Config::DrivetrainMovement::Tank:
			Config::drivetrainMovement = Config::DrivetrainMovement::SingleStickArcade;
			drivetrainMovementString = "SSA";
			break;

		case Config::DrivetrainMovement::SingleStickArcade:
			Config::drivetrainMovement = Config::DrivetrainMovement::DoubleStickArcade;
			drivetrainMovementString = "DSA";
			break;

		case Config::DrivetrainMovement::DoubleStickArcade:
			Config::drivetrainMovement = Config::DrivetrainMovement::SingleStickCurvature;
			drivetrainMovementString = "SSC";
			break;

		case Config::DrivetrainMovement::SingleStickCurvature:
			Config::drivetrainMovement = Config::DrivetrainMovement::DoubleStickCurvature;
			drivetrainMovementString = "DSC";
			break;

		case Config::DrivetrainMovement::DoubleStickCurvature:
			Config::drivetrainMovement = Config::DrivetrainMovement::Tank;
			drivetrainMovementString = "TAN";
			break;
	}
	pros::lcd::print(lineNumber++, "Changed Drivetrain Movement to %s",
					 drivetrainMovementString.c_str());
	Config::controllerStrings[2] = "DV MV: " + drivetrainMovementString;
}
