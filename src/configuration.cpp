#include "configuration.hpp"

#include <cstdint>
#include <vector>

double movementVelocityPercentage = 1;
double turningVelocityPercentage = 1;
double joystickThresholdPercentage = 0.1;

double intakeVelocity = 1;

std::unordered_map<PortType, std::vector<std::int8_t>> portNumbers = {
	{PortType::LEFT_MOTORS, {1, -2, 3}}, {PortType::RIGHT_MOTORS, {-4, 5, -6}},
	{PortType::INTAKE_MOTOR, {8}},		 {PortType::INERTIAL_SENSOR, {7}},
	{PortType::RECIEVER, {20}},
};

std::unordered_map<PortType, pros::v5::MotorGears> portGearsets = {
	{PortType::LEFT_MOTORS, pros::v5::MotorGears::blue},
	{PortType::RIGHT_MOTORS, pros::v5::MotorGears::blue},
	{PortType::INTAKE_MOTOR, pros::v5::MotorGears::green},
};
