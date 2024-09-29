#include "setup-devices.hpp"
#include "configuration.hpp"
#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftMotorGroup(portNumbers[PortType::LEFT_MOTORS]);
pros::MotorGroup rightMotorGroup(portNumbers[PortType::RIGHT_MOTORS]);
