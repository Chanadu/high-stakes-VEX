#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
inline pros::MotorGroup intakeMotors({9, -10}, pros::MotorGears::red);
inline pros::MotorGroup armMotor({13}, pros::MotorGears::green);

inline pros::adi::Pneumatics holderPiston('H', false, false);
// inline ez::Piston holderPiston('H');

// inline pros::adi::DigitalIn limit_switch('A');
