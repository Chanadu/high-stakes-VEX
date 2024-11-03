#ifndef _OPCONTROL_HPP_
#define _OPCONTROL_HPP_

#include "../lemlib/api.hpp"
#include "../main.h"
#include "../utils/config-enums.hpp"

void opcontrolRunner(pros::Controller* controller,
					 lemlib::Chassis* chassis,
					 DrivetrainMovement* drivetrainMovementType);

#endif	// _OPCONTROL_HPP_
