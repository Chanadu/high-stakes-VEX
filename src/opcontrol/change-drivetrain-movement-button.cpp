#include "opcontrol/change-drivetrain-movement-button.hpp"
#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"

void incrementDrivetrainMovement() {
	short i = 0;
	incrementDrivetrainMovement(i);
}
void incrementDrivetrainMovement(short& lineNumber) {
	const unsigned int indexOfDrivetrainMovement =
		std::ranges::find(Config::drivetrainMovements, Config::drivetrainMovement) -
		Config::drivetrainMovements.begin();

	const unsigned int newIndex =
		(indexOfDrivetrainMovement + 1) % Config::drivetrainMovements.size();

	Config::drivetrainMovement = Config::drivetrainMovements.at(newIndex);

	const std::string& drivetrainMovementString =
		Config::drivetrainMovementToAbbr.at(Config::drivetrainMovement);

	pros::lcd::print(lineNumber++, "Changed Drivetrain Movement to %s",
					 drivetrainMovementString.c_str());
	Config::controllerStrings[2] = "DV MV: " + drivetrainMovementString;
}
