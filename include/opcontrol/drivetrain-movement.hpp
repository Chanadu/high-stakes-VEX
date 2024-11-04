#ifndef _DRIVE_TRAIN_MOVEMENT_HPP_
#define _DRIVE_TRAIN_MOVEMENT_HPP_

#include "../lemlib/api.hpp"
#include "../main.h"

extern void tankControl(pros::Controller* controller, lemlib::Chassis* chassis);

extern void singleStickArcadeControl(pros::Controller* controller,
									 lemlib::Chasssis* chassis);

#endif	// _DRIVE_TRAIN_MOVEMENT_HPP_
