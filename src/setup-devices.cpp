#include "setup-devices.hpp"
#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup leftMotorGroup({1, -2, 3});
pros::MotorGroup rightMotorGroup({-4, 5, -6});
