#ifndef _CONFIGURATION_HPP_
#define _CONFIGURATION_HPP_

#include "main.h"
#include "utils/config-enums.hpp"

namespace Config {
extern double drivetrainTrackWidth;
extern double drivetrainWheelbaseWidth;
extern double drivetrainWheelRPM;
extern double drivetrainHorizontalDrift;

extern double intakeVelocity;  // 0 - 1

extern float drivetrainWheelType;

extern double maxControllerValue;

extern double movementVelocityPercentage;  // 0 - 1
extern double turningVelocityPercentage;   // 0 - 1

extern double joystickThresholdPercentage;		  // 0 - 1
extern double outputMovementThresholdPercentage;  // 0 - 1

extern double lateralCurveGain;
extern double angularCurveGain;

extern lemlib::ControllerSettings lateralMovementController;
extern lemlib::ControllerSettings angularMovementController;

enum class DrivetrainMovement {
	Tank,
	SingleStickArcade,
	DoubleStickArcade,
	SingleStickCurvature,
	DoubleStickCurvature
};

extern DrivetrainMovement drivetrainMovement;
}  // namespace Config

#endif	// _CONFIGURATION_HPP_
