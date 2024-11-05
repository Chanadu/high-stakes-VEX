#ifndef _CONFIG_ENUMS_HPP_
#define _CONFIG_ENUMS_HPP_

enum class DrivetrainMovement {
	TANK_MOVEMENT,
	SINGLE_STICK_ARCADE_MOVEMENT,
	DOUBLE_STICK_ARCADE_MOVEMENT,
	SINGLE_STICK_CURVATURE_MOVEMENT,
	DOUBLE_STICK_CURVATURE_MOVEMENT,
};

// Port Numbers
enum class Port {
	LEFT_MOTORS,
	RIGHT_MOTORS,
	INTAKE_MOTOR,
	RECIEVER,
	INERTIAL_SENSOR,
};

enum class ADIPort {
	MOGO_HOLDER_PISTON,
};

// Movement Controller Settings Numbers
enum class MovementControllerSettings {
	PROPORTIONAL_GAIN,			// kP
	INTEGRAL_GAIN,				// kI
	DERIVATIVE_GAIN,			// kD
	ANTI_WINDUP,				//
	SMALL_ERROR_RANGE,			// in inches
	SMALL_ERROR_RANGE_TIMEOUT,	// in milliseconds
	LARGE_ERROR_RANGE,			// in inches
	LARGE_ERROR_RANGE_TIMEOUT,	// in milliseconds
	MAXIMUM_ACCELERATION,		// Slew
};

enum class ExpoDriveCurveSettings {
	DEADBAND,	 // Range where input is considered input
	MIN_OUTPUT,	 // minimum output that can be returned
	CURVE,		 // how "curved" the graph is
};

#endif	// _CONFIG_ENUMS_HPP
