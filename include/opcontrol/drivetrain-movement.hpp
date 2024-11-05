#ifndef _DRIVE_TRAIN_MOVEMENT_HPP_
#define _DRIVE_TRAIN_MOVEMENT_HPP_

#include "../main.h"
#include "../utils/config-enums.hpp"

extern void drivetrainMovementController(pros::Controller* controller,
										 lemlib::Chassis* chassis,
										 DrivetrainMovement* drivetrainMovement,
										 int* i);

extern void tankControl(pros::Controller* controller, lemlib::Chassis* chassis);

extern void singleStickArcadeControl(pros::Controller* controller,
									 lemlib::Chassis* chassis);

extern void doubleStickArcadeControl(pros::Controller* controller,
									 lemlib::Chassis* chassis);

extern void singleStickCurvatureControl(pros::Controller* controller,
										lemlib::Chassis* chassis);

extern void doubleStickCurvatureControl(pros::Controller* controller,
										lemlib::Chassis* chassis);

#endif	// _DRIVE_TRAIN_MOVEMENT_HPP_
