#ifndef _CONFIGURATION_HPP_
#define _CONFIGURATION_HPP_

#include <cstdint>
#include <unordered_map>
#include <vector>
#include "lemlib/api.hpp"
#include "main.h"
#include "utils/config-enums.hpp"

namespace Config {
// Drivetrain Measurements
extern double drivetrainTrackWidth;
extern double drivetrainWheelbaseWidth;
extern double drivetrainWheelRPM;
extern double drivetrainHorizontalDrift;

// Drivetrain Types
extern float drivetrainWheelType;
extern std::unordered_map<Port, std::vector<std::int8_t>> portNumbers;
extern std::unordered_map<Port, pros::MotorGears> portGearsets;

extern std::unordered_map<ADIPort, std::vector<char>> adiPortNumbers;

// Drivetrain Movement Controller Settings
extern std::unordered_map<MovementControllerSettings, float> lateralControllerSettings;
extern std::unordered_map<MovementControllerSettings, float> angularControllerSettings;

// Drivetrain Movement
extern double maxControllerValue;

extern double movementVelocityPercentage;  // 0 - 1
extern double turningVelocityPercentage;   // 0 - 1

extern double joystickThresholdPercentage;		  // 0 - 1
extern double outputMovementThresholdPercentage;  // 0 - 1

extern double driveExpoDriveCurveGain;
extern double turnExpoDriveCurveGain;

// Drivetrain Expo Drive Curves
extern std::unordered_map<ExpoDriveCurveSettings, float> driveExpoDriveCurveSettings;
extern std::unordered_map<ExpoDriveCurveSettings, float> turnExpoDriveCurveSettings;

// Intake
extern double intakeVelocity;  // 0 - 1
}  // namespace Config

#endif	// _CONFIGURATION_HPP_
