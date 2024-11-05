#ifndef _CONFIG_ENUMS_HPP_
#define _CONFIG_ENUMS_HPP_

enum class DrivetrainMovement {
	TankMovement,
	SingleStickArcadeMovement,
	DoubleStickArcadeMovement,
	SingleStickCurvatureMovement,
	DoubleStickCurvatureMovement,
};

// Port Numbers
enum class Port {
	LeftMotors,
	RightMotors,
	IntakeMotor,
	Reciever,
	InertialSensor,
};

enum class ADIPort {
	MogoHolderPiston,
};

// Movement Controller Settings Numbers
enum class MovementControllerSettings {
	ProportionalGain,		 // kP
	IntegralGain,			 // kI
	DerivativeGain,			 // kD
	AntiWindup,				 //
	SmallErrorRange,		 // in inches
	SmallErrorRangeTimeout,	 // in milliseconds
	LargeErrorRange,		 // in inches
	LargeErrorRangeTimeout,	 // in milliseconds
	MaximumAcceleration,	 // Slew
};

enum class ExpoDriveCurveSettings {
	Deadband,	// Range where input is considered input
	MinOutput,	// minimum output that can be returned
	Curve,		// how "curved" the graph is
};

#endif	// _CONFIG_ENUMS_HPP
