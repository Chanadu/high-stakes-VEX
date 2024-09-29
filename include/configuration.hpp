#ifndef _CONFIGURATION_HPP_
#define _CONFIGURATION_HPP_

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

// Drivetrain
extern int movementVelocity;  // 0 - 1
extern int turningVelocity;	  // 0 - 1

// Intake
extern int intakeVelocity;	// 0 - 1

// Port Numbers
typedef enum {
	LEFT_MOTORS,
	RIGHT_MOTORS,
	INTAKE_MOTOR,
	RECIEVER,
	INERTIAL_SENSOR,
} PortType;

extern std::unordered_map<PortType, std::vector<std::int8_t>> motorPorts;

#endif	// _CONFIGURATION_HPP_
