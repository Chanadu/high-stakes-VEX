#include "configuration.hpp"
#include "main.h"

namespace Config {
const float drivetrainTrackWidth = 14.975;
const float drivetrainWheelbaseWidth = 9.0;
const float drivetrainWheelRPM = 600;
const float drivetrainHorizontalDrift = 2.0;

double intakeVelocity = 1.0;

const float drivetrainWheelType = lemlib::Omniwheel::NEW_275;

const float maxControllerValue = 127.0;

double movementVelocityPercentage = 1.0;
double turningVelocityPercentage = 1.0;

// https://www.desmos.com/calculator/umicbymbnl
float joystickThresholdPercentage = 3.0;
float outputMovementThresholdPercentage = 10.0;

float lateralCurveGain = 1.019;
float angularCurveGain = 1.019;

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
DrivetrainMovement drivetrainMovement = DrivetrainMovement::DoubleStickArcade;
std::string controllerStrings[3] = {
	"Line 1",
	"Line 2",
	"Line 3",
};
std::string controllerRumblePattern;
};	// namespace Config
