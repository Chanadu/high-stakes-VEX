#include "setup-devices.hpp"
#include "configuration.hpp"
#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftMotorGroup(motorPorts[PortType::LEFT_MOTORS]);
pros::MotorGroup rightMotorGroup(motorPorts[PortType::RIGHT_MOTORS]);
