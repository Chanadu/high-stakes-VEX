#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include "main.h"

namespace Config {
extern const float drivetrainTrackWidth;
extern const float drivetrainWheelbaseWidth;
extern const float drivetrainWheelRPM;
extern const float drivetrainHorizontalDrift;

extern double intakeVelocity;  // 0 - 1

extern const float drivetrainWheelType;

extern const float maxControllerValue;

extern double movementVelocityPercentage;  // 0 - 1
extern double turningVelocityPercentage;   // 0 - 1

extern float joystickThresholdPercentage;		 // 0 - 1
extern float outputMovementThresholdPercentage;	 // 0 - 1

extern float lateralCurveGain;
extern float angularCurveGain;

extern lemlib::ControllerSettings lateralMovementController;
extern lemlib::ControllerSettings angularMovementController;

enum class DrivetrainMovement {
	Tank,
	SingleStickArcade,
	DoubleStickArcade,
	SingleStickCurvature,
	DoubleStickCurvature
};

inline const std::vector drivetrainMovements{
	DrivetrainMovement::Tank,
	DrivetrainMovement::SingleStickArcade,
	DrivetrainMovement::DoubleStickArcade,
	DrivetrainMovement::SingleStickCurvature,
	DrivetrainMovement::DoubleStickCurvature,
};

inline const std::unordered_map<DrivetrainMovement, std::string> drivetrainMovementToAbbr{
	{DrivetrainMovement::Tank, "TAN"},
	{DrivetrainMovement::SingleStickArcade, "SSA"},
	{DrivetrainMovement::DoubleStickArcade, "DSA"},
	{DrivetrainMovement::SingleStickCurvature, "SSC"},
	{DrivetrainMovement::DoubleStickCurvature, "DSC"},
};

extern DrivetrainMovement drivetrainMovement;
extern std::string controllerStrings[3];
}  // namespace Config

#endif	// CONFIGURATION_HPP
