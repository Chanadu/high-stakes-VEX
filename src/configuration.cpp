#include "configuration.hpp"

#include <cstdint>
#include <vector>

int movementVelocity = 1;
int turningVecoity = 1;

int intakeVelocity = 1;

std::unordered_map<PortType, std::vector<std::int8_t>> motorPorts = {
	{PortType::LEFT_MOTORS, {1, -2, 3}}, {PortType::RIGHT_MOTORS, {-4, 5, -6}},
	{PortType::INTAKE_MOTOR, {8}},		 {PortType::INERTIAL_SENSOR, {7}},
	{PortType::RECIEVER, {20}},
};