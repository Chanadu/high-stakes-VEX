#include "configuration.hpp"

#include <cstdint>
#include <vector>
#include "lemlib/api.hpp"

double drivetrainTrackWidth = 14.975;
double drivetrainWheelbaseWidth = 9.0;
double drivetrainWheelRPM = 200.0;
double drivetrainHorizontalDrift = 2.0;

double intakeVelocity = 1.0;

float drivetrainWheelType = lemlib::Omniwheel::NEW_275;
std::unordered_map<PortType, std::vector<std::int8_t>> portNumbers = {
	{PortType::LEFT_MOTORS, {1, -2, 3}}, {PortType::RIGHT_MOTORS, {-4, 5, -6}},
	{PortType::INTAKE_MOTOR, {8}},		 {PortType::INERTIAL_SENSOR, {7}},
	{PortType::RECIEVER, {20}},
};
std::unordered_map<PortType, pros::v5::MotorGears> portGearsets = {
	{PortType::LEFT_MOTORS, pros::v5::MotorGears::blue},
	{PortType::RIGHT_MOTORS, pros::v5::MotorGears::blue},
	{PortType::INTAKE_MOTOR, pros::v5::MotorGears::green},
};

std::unordered_map<MovementControllerSettingsType, float>
	lateralControllerSettings = {
		{PROPORTIONAL_GAIN, 10},	{INTEGRAL_GAIN, 0},
		{DERIVATIVE_GAIN, 3},		{ANTI_WINDUP, 3},
		{SMALL_ERROR_RANGE, 1},		{SMALL_ERROR_RANGE_TIMEOUT, 100},
		{LARGE_ERROR_RANGE, 3},		{LARGE_ERROR_RANGE_TIMEOUT, 500},
		{MAXIMUM_ACCELERATION, 20},
};
std::unordered_map<MovementControllerSettingsType, float>
	angularControllerSettings = {
		{PROPORTIONAL_GAIN, 2},	   {INTEGRAL_GAIN, 0},
		{DERIVATIVE_GAIN, 10},	   {ANTI_WINDUP, 3},
		{SMALL_ERROR_RANGE, 1},	   {SMALL_ERROR_RANGE_TIMEOUT, 100},
		{LARGE_ERROR_RANGE, 3},	   {LARGE_ERROR_RANGE_TIMEOUT, 500},
		{MAXIMUM_ACCELERATION, 0},
};
double maxControllerValue = 127.0;

double movementVelocityPercentage = 1.0;
double turningVelocityPercentage = 1.0;

double joystickThresholdPercentage = 3.0 / maxControllerValue;
double outputMovementThresholdPercentage = 10.0 / maxControllerValue;

double driveExpoDriveCurveGain = 1.019;
double turnExpoDriveCurveGain = 1.019;

std::unordered_map<ExpoDriveCurveType, float> driveExpoDriveCurveSettings = {
	{DEADBAND, joystickThresholdPercentage* maxControllerValue},
	{MIN_OUTPUT, outputMovementThresholdPercentage* maxControllerValue},
	{CURVE, driveExpoDriveCurveGain}};

std::unordered_map<ExpoDriveCurveType, float> turnExpoDriveCurveSettings = {
	{DEADBAND, joystickThresholdPercentage* maxControllerValue},
	{MIN_OUTPUT, outputMovementThresholdPercentage* maxControllerValue},
	{CURVE, turnExpoDriveCurveGain},
};

DrivetrainMovementType drivetrainMovementType = DOUBLE_STICK_ARCADE_MOVEMENT;
