#include "drivetrain-movement.hpp"
#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"

void doubleStickArcadeControl() {
	int leftY = Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	int rightX = Devices::controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
	leftY = static_cast<int>(leftY * Config::movementVelocityPercentage);
	rightX = static_cast<int>(rightX * Config::turningVelocityPercentage);
	Devices::chassis.arcade(leftY, rightX);
}

void drivetrainMovementController() {
	doubleStickArcadeControl();
}
