#include "setup-devices.hpp"
#include "configuration.hpp"
#include "lemlib/api.hpp"
#include "main.h"

namespace Devices {
pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftMotorGroup(portNumbers[Port::LEFT_MOTORS],
								portGearsets[Port::LEFT_MOTORS]);
pros::MotorGroup rightMotorGroup(portNumbers[Port::RIGHT_MOTORS],
								 portGearsets[Port::RIGHT_MOTORS]);

lemlib::Drivetrain drivetrain(&leftMotorGroup,
							  &rightMotorGroup,
							  drivetrainTrackWidth,
							  drivetrainWheelType,
							  drivetrainWheelRPM,
							  drivetrainHorizontalDrift);

pros::Imu imu(portNumbers[Port::INERTIAL_SENSOR][0]);
// Could add more tracking items here
//
// pros::Rotation horizontalEncoder(20);
// // vertical tracking wheel encoder
// pros::adi::Encoder verticalEncoder('C', 'D', true);
// // horizontal tracking wheel
// lemlib::TrackingWheel horizontalTrackingWheel(&horizontal_encoder,
// 												lemlib::Omniwheel::NEW_275,
// 												-5.75);
// // vertical tracking wheel
// lemlib::TrackingWheel verticalTrackingWheel(&vertical_encoder,
// 											  lemlib::Omniwheel::NEW_275,
// 											  -2.5);

lemlib::OdomSensors odomSensors(
	nullptr,  // vertical tracking wheel 1, set to nullptr
	nullptr,  // vertical tracking wheel 2, set to nullptr
	nullptr,  // horizontal tracking wheel 1, set to nullptr
	nullptr,  // horizontal tracking wheel 2, set to nullptr
	&imu	  // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateralMovementController(
	lateralControllerSettings[MovementControllerSettings::PROPORTIONAL_GAIN],
	lateralControllerSettings[MovementControllerSettings::INTEGRAL_GAIN],
	lateralControllerSettings[MovementControllerSettings::DERIVATIVE_GAIN],
	lateralControllerSettings[MovementControllerSettings::ANTI_WINDUP],
	lateralControllerSettings[MovementControllerSettings::SMALL_ERROR_RANGE],
	lateralControllerSettings
		[MovementControllerSettings::SMALL_ERROR_RANGE_TIMEOUT],
	lateralControllerSettings[MovementControllerSettings::LARGE_ERROR_RANGE],
	lateralControllerSettings
		[MovementControllerSettings::LARGE_ERROR_RANGE_TIMEOUT],
	lateralControllerSettings
		[MovementControllerSettings::MAXIMUM_ACCELERATION]	//
);

// angular PID controller
lemlib::ControllerSettings angularMovementController(
	angularControllerSettings[MovementControllerSettings::PROPORTIONAL_GAIN],
	angularControllerSettings[MovementControllerSettings::INTEGRAL_GAIN],
	angularControllerSettings[MovementControllerSettings::DERIVATIVE_GAIN],
	angularControllerSettings[MovementControllerSettings::ANTI_WINDUP],
	angularControllerSettings[MovementControllerSettings::SMALL_ERROR_RANGE],
	angularControllerSettings
		[MovementControllerSettings::SMALL_ERROR_RANGE_TIMEOUT],
	angularControllerSettings[MovementControllerSettings::LARGE_ERROR_RANGE],
	angularControllerSettings
		[MovementControllerSettings::LARGE_ERROR_RANGE_TIMEOUT],
	angularControllerSettings
		[MovementControllerSettings::MAXIMUM_ACCELERATION]	//
);

lemlib::ExpoDriveCurve driveCurve(
	driveExpoDriveCurveSettings[ExpoDriveCurveSettings::DEADBAND],
	driveExpoDriveCurveSettings[ExpoDriveCurveSettings::MIN_OUTPUT],
	driveExpoDriveCurveSettings[ExpoDriveCurveSettings::CURVE]);

lemlib::ExpoDriveCurve turnCurve(
	turnExpoDriveCurveSettings[ExpoDriveCurveSettings::DEADBAND],
	turnExpoDriveCurveSettings[ExpoDriveCurveSettings::MIN_OUTPUT],
	turnExpoDriveCurveSettings[ExpoDriveCurveSettings::CURVE]);

// create the chassis
lemlib::Chassis chassis(drivetrain,					// drivetrain settings
						lateralMovementController,	// lateral PID settings
						angularMovementController,	// angular PID settings
						odomSensors,				// odometry sensors
						&driveCurve,				// throttle curve
						&turnCurve					// steering curve
);

pros::adi::DigitalOut mogoHolderPiston(
	adiPortNumbers[ADIPort::MOGO_HOLDER_PISTON][0]);

}  // namespace Devices
