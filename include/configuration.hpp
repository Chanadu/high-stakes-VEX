#ifndef _CONFIGURATION_HPP_
#define _CONFIGURATION_HPP_

#include <cstdint>
#include <unordered_map>
#include <vector>
#include "main.h"

// User Controller Drivetrain Schemes
typedef enum {
	TANK_MOVEMENT,
	SINGLE_STICK_ARCADE_MOVEMENT,
	DOUBLE_STICK_ARCADE_MOVEMENT,
	SINGLE_STICK_CURVATURE_MOVEMENT,
	DOUBLE_STICK_CURVATURE_MOVEMENT,
} DrivetrainMovementType;

// Port Numbers
typedef enum {
	LEFT_MOTORS,
	RIGHT_MOTORS,
	INTAKE_MOTOR,
	RECIEVER,
	INERTIAL_SENSOR,
} PortType;

// Movement Controller Settings Numbers
typedef enum {
	PROPORTIONAL_GAIN,			// kP
	INTEGRAL_GAIN,				// kI
	DERIVATIVE_GAIN,			// kD
	ANTI_WINDUP,				//
	SMALL_ERROR_RANGE,			// in inches
	SMALL_ERROR_RANGE_TIMEOUT,	// in milliseconds
	LARGE_ERROR_RANGE,			// in inches
	LARGE_ERROR_RANGE_TIMEOUT,	// in milliseconds
	MAXIMUM_ACCELERATION,		// Slew
} MovementControllerSettingsType;

// Drivetrain Measurements
extern double drivetrainTrackWidth;
extern double drivetrainWheelbaseWidth;
extern double drivetrainWheelRPM;
extern double drivetrainHorizontalDrift;

// Drivetrain Types
extern float drivetrainWheelType;
extern std::unordered_map<PortType, std::vector<std::int8_t>> portNumbers;
extern std::unordered_map<PortType, pros::v5::MotorGears> portGearsets;

// Drivetrain Movement Controller Settings
extern std::unordered_map<MovementControllerSettingsType, float>
	lateralControllerSettings;
extern std::unordered_map<MovementControllerSettingsType, float>
	angularControllerSettings;

// Drivetrain Movement
extern double movementVelocityPercentage;  // 0 - 1
extern double turningVelocityPercentage;   // 0 - 1

extern double joystickThresholdPercentage;	// 0 - 1

extern DrivetrainMovementType drivetrainMovementType;

// Intake
extern double intakeVelocity;  // 0 - 1

#endif	// _CONFIGURATION_HPP_
