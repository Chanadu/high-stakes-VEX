
#ifndef _SCREEN_DISPLAYS_HPP_
#define _SCREEN_DISPLAYS_HPP_

#include "../lemlib/api.hpp"
#include "../main.h"

extern void initializeDevices(void);

extern int batteryDisplay(pros::Controller* controller, int i);
extern int chassisPositionDisplay(lemlib::Chassis* chassis, int i);

#endif	// _SCREEN_DISPLAYS_HPP_
