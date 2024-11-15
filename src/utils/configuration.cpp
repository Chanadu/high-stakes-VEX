#include "configuration.hpp"
#include "main.h"

namespace Config {
double drivetrainTrackWidth = 14.975;
double drivetrainWheelbaseWidth = 9.0;
double drivetrainWheelRPM = 600;
double drivetrainHorizontalDrift = 2.0;

double intakeVelocity = 1.0;

float drivetrainWheelType = lemlib::Omniwheel::NEW_275;

double maxControllerValue = 127.0;

double movementVelocityPercentage = 1.0;
double turningVelocityPercentage = 1.0;

// https://www.desmos.com/calculator/umicbymbnl
double joystickThresholdPercentage = 3.0;
double outputMovementThresholdPercentage = 10.0;

double lateralCurveGain = 1.019;
double angularCurveGain = 1.019;

// lateral PID controller
lemlib::ControllerSettings lateralMovementController(10,   // ProportionalGain
													 0,	   // IntegralGain
													 3,	   // DerivativeGain
													 3,	   // AntiWindup
													 1,	   // SmallErrorRange
													 100,  // SmallErrorRangeTimeout
													 3,	   // LargeErrorRange
													 500,  // LargeErrorRangeTimeout
													 20	   // MaximumAcceleration
);

// angular PID controller
lemlib::ControllerSettings angularMovementController(2,	   // ProportionalGain
													 0,	   // IntegralGain
													 10,   // DerivativeGain
													 3,	   // AntiWindup
													 1,	   // SmallErrorRange
													 100,  // SmallErrorRangeTimeout
													 3,	   // LargeErrorRange
													 500,  // LargeErrorRangeTimeout
													 0	   // MaximumAcceleration
);
Config::DrivetrainMovement drivetrainMovement =
	Config::DrivetrainMovement::DoubleStickArcadeMovement;
}  // namespace Config
