
#ifndef SCREEN_DISPLAYS_HPP
#define SCREEN_DISPLAYS_HPP

#include "../main.h"

extern void initializeDevices();

extern void batteryDisplay(pros::Controller& controller, short& i);
extern void chassisPositionDisplay(lemlib::Chassis& chassis, short& i);

#endif	// SCREEN_DISPLAYS_HPP
