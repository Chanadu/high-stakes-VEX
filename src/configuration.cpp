#include "configuration.hpp"
#include "main.h"

#include <cstdint>
#include <vector>

namespace Config {

double drivetrainTrackWidth = 14.975;
double drivetrainWheelbaseWidth = 9.0;
double drivetrainWheelRPM = 200.0;
double drivetrainHorizontalDrift = 2.0;

double intakeVelocity = 1.0;

float drivetrainWheelType = lemlib::Omniwheel::NEW_275;
std::unordered_map<Port, std::vector<std::int8_t>> portNumbers = {
	{Port::LeftMotors, {1, -2, 3}},	   //
	{Port::RightMotors, {-4, 5, -6}},  //
	{Port::IntakeMotor, {8}},		   //
	{Port::InertialSensor, {7}},	   //
	{Port::Reciever, {20}},			   //
};
std::unordered_map<Port, pros::MotorGears> portGearsets = {
	{Port::LeftMotors, pros::MotorGears::blue},
	{Port::RightMotors, pros::MotorGears::blue},
	{Port::IntakeMotor, pros::MotorGears::green},
};
std::unordered_map<ADIPort, std::vector<char>> adiPortNumbers = {
	{ADIPort::MogoHolderPiston, {'A'}},
};

std::unordered_map<MovementControllerSettings, float> lateralControllerSettings = {
	{MovementControllerSettings::ProportionalGain, 10},
	{MovementControllerSettings::IntegralGain, 0},
	{MovementControllerSettings::DerivativeGain, 3},
	{MovementControllerSettings::AntiWindup, 3},
	{MovementControllerSettings::SmallErrorRange, 1},
	{MovementControllerSettings::SmallErrorRangeTimeout, 100},
	{MovementControllerSettings::LargeErrorRange, 3},
	{MovementControllerSettings::LargeErrorRangeTimeout, 500},
	{MovementControllerSettings::MaximumAcceleration, 20},
};
std::unordered_map<MovementControllerSettings, float> angularControllerSettings = {
	{MovementControllerSettings::ProportionalGain, 2},
	{MovementControllerSettings::IntegralGain, 0},
	{MovementControllerSettings::DerivativeGain, 10},
	{MovementControllerSettings::AntiWindup, 3},
	{MovementControllerSettings::SmallErrorRange, 1},
	{MovementControllerSettings::SmallErrorRangeTimeout, 100},
	{MovementControllerSettings::LargeErrorRange, 3},
	{MovementControllerSettings::LargeErrorRangeTimeout, 500},
	{MovementControllerSettings::MaximumAcceleration, 0},
};
double maxControllerValue = 127.0;

double movementVelocityPercentage = 1.0;
double turningVelocityPercentage = 1.0;

double joystickThresholdPercentage = 3.0 / maxControllerValue;
double outputMovementThresholdPercentage = 10.0 / maxControllerValue;

double driveExpoDriveCurveGain = 1.019;
double turnExpoDriveCurveGain = 1.019;

std::unordered_map<ExpoDriveCurveSettings, float> driveExpoDriveCurveSettings = {
	{ExpoDriveCurveSettings::Deadband, joystickThresholdPercentage* maxControllerValue},
	{ExpoDriveCurveSettings::MinOutput, outputMovementThresholdPercentage* maxControllerValue},
	{ExpoDriveCurveSettings::Curve, driveExpoDriveCurveGain},
};

std::unordered_map<ExpoDriveCurveSettings, float> turnExpoDriveCurveSettings = {
	{ExpoDriveCurveSettings::Deadband, joystickThresholdPercentage* maxControllerValue},
	{ExpoDriveCurveSettings::MinOutput, outputMovementThresholdPercentage* maxControllerValue},
	{ExpoDriveCurveSettings::Curve, turnExpoDriveCurveGain},
};

}  // namespace Config
