#ifndef _OPCONTROL_HPP_
#define _OPCONTROL_HPP_

#include "../main.h"
#include "../utils/config-enums.hpp"

extern void opcontrolRunner(pros::Controller& controller,
							lemlib::Chassis& chassis,
							DrivetrainMovement& drivetrainMovementType);

#endif	// _OPCONTROL_HPP_
