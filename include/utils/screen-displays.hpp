
#ifndef _SCREEN_DISPLAYS_HPP_
#define _SCREEN_DISPLAYS_HPP_

#include "../main.h"

extern void initializeDevices(void);

extern void batteryDisplay(pros::Controller& controller, int& i);
extern void chassisPositionDisplay(lemlib::Chassis& chassis, int& i);

#endif	// _SCREEN_DISPLAYS_HPP_
