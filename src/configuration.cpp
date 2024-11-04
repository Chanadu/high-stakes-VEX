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
std::unordered_map<Port, std::vector<std::int8_t>> portNumbers = {
	{
		Port::LEFT_MOTORS,
		{1, -2, 3},
	},
	{
		Port::RIGHT_MOTORS,
		{-4, 5, -6},
	},
	{
		Port::INTAKE_MOTOR,
		{8},
	},
	{
		Port::INERTIAL_SENSOR,
		{7},
	},
	{
		Port::RECIEVER,
		{20},
	},
};
std::unordered_map<Port, pros::MotorGears> portGearsets = {
	{Port::LEFT_MOTORS, pros::MotorGears::blue},
	{Port::RIGHT_MOTORS, pros::MotorGears::blue},
	{Port::INTAKE_MOTOR, pros::MotorGears::green},
};
std::unordered_map<ADIPort, std::vector<char>> adiPortNumbers = {
	{ADIPort::MOGO_HOLDER_PISTON, {'A'}},
};

std::unordered_map<MovementControllerSettings, float>
	lateralControllerSettings = {
		{
			MovementControllerSettings::PROPORTIONAL_GAIN,
			10,
		},
		{
			MovementControllerSettings::INTEGRAL_GAIN,
			0,
		},
		{
			MovementControllerSettings::DERIVATIVE_GAIN,
			3,
		},
		{
			MovementControllerSettings::ANTI_WINDUP,
			3,
		},
		{
			MovementControllerSettings::SMALL_ERROR_RANGE,
			1,
		},
		{
			MovementControllerSettings::SMALL_ERROR_RANGE_TIMEOUT,
			100,
		},
		{
			MovementControllerSettings::LARGE_ERROR_RANGE,
			3,
		},
		{

			MovementControllerSettings::LARGE_ERROR_RANGE_TIMEOUT,
			500,
		},
		{
			MovementControllerSettings::MAXIMUM_ACCELERATION,
			20,
		},
};
std::unordered_map<MovementControllerSettings, float>
	angularControllerSettings = {
		{
			MovementControllerSettings::PROPORTIONAL_GAIN,
			2,
		},
		{
			MovementControllerSettings::INTEGRAL_GAIN,
			0,
		},
		{
			MovementControllerSettings::DERIVATIVE_GAIN,
			10,
		},
		{
			MovementControllerSettings::ANTI_WINDUP,
			3,
		},
		{
			MovementControllerSettings::SMALL_ERROR_RANGE,
			1,
		},
		{
			MovementControllerSettings::SMALL_ERROR_RANGE_TIMEOUT,
			100,
		},
		{
			MovementControllerSettings::LARGE_ERROR_RANGE,
			3,
		},
		{
			MovementControllerSettings::LARGE_ERROR_RANGE_TIMEOUT,
			500,
		},
		{
			MovementControllerSettings::MAXIMUM_ACCELERATION,
			0,
		},
};
double maxControllerValue = 127.0;

double movementVelocityPercentage = 1.0;
double turningVelocityPercentage = 1.0;

double joystickThresholdPercentage = 3.0 / maxControllerValue;
double outputMovementThresholdPercentage = 10.0 / maxControllerValue;

double driveExpoDriveCurveGain = 1.019;
double turnExpoDriveCurveGain = 1.019;

std::unordered_map<ExpoDriveCurveSettings, float> driveExpoDriveCurveSettings =
	{
		{
			ExpoDriveCurveSettings::DEADBAND,
			joystickThresholdPercentage* maxControllerValue,
		},
		{
			ExpoDriveCurveSettings::MIN_OUTPUT,
			outputMovementThresholdPercentage* maxControllerValue,
		},
		{
			ExpoDriveCurveSettings::CURVE,
			driveExpoDriveCurveGain,
		},
};

std::unordered_map<ExpoDriveCurveSettings, float> turnExpoDriveCurveSettings = {
	{
		ExpoDriveCurveSettings::DEADBAND,
		joystickThresholdPercentage* maxControllerValue,
	},
	{
		ExpoDriveCurveSettings::MIN_OUTPUT,
		outputMovementThresholdPercentage* maxControllerValue,
	},
	{
		ExpoDriveCurveSettings::CURVE,
		turnExpoDriveCurveGain,
	},
};
