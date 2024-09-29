#ifndef _CONFIGURATION_HPP_
#define _CONFIGURATION_HPP_

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

// Drivetrain
extern double movementVelocityPercentage;  // 0 - 1
extern double turningVelocityPercentage;   // 0 - 1

extern double joystickThresholdPercentage;	// 0 - 1

// Intake
extern double intakeVelocity;  // 0 - 1

// Port Numbers
typedef enum {
	LEFT_MOTORS,
	RIGHT_MOTORS,
	INTAKE_MOTOR,
	RECIEVER,
	INERTIAL_SENSOR,
} PortType;

extern std::unordered_map<PortType, std::vector<std::int8_t>> portNumbers;

#endif	// _CONFIGURATION_HPP_
