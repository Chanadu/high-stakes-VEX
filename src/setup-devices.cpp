#include "setup-devices.hpp"
#include "configuration.hpp"
#include "main.h"

namespace Devices {
pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftMotorGroup(Config::portNumbers[Port::LEFT_MOTORS],
								Config::portGearsets[Port::LEFT_MOTORS]);
pros::MotorGroup rightMotorGroup(Config::portNumbers[Port::RIGHT_MOTORS],
								 Config::portGearsets[Port::RIGHT_MOTORS]);

lemlib::Drivetrain drivetrain(&leftMotorGroup,
							  &rightMotorGroup,
							  Config::drivetrainTrackWidth,
							  Config::drivetrainWheelType,
							  Config::drivetrainWheelRPM,
							  Config::drivetrainHorizontalDrift);

pros::Imu imu(Config::portNumbers[Port::INERTIAL_SENSOR][0]);
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

lemlib::OdomSensors odomSensors(nullptr,  // vertical tracking wheel 1, set to nullptr
								nullptr,  // vertical tracking wheel 2, set to nullptr
								nullptr,  // horizontal tracking wheel 1, set to nullptr
								nullptr,  // horizontal tracking wheel 2, set to nullptr
								&imu	  // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateralMovementController(
	Config::lateralControllerSettings[MovementControllerSettings::PROPORTIONAL_GAIN],
	Config::lateralControllerSettings[MovementControllerSettings::INTEGRAL_GAIN],
	Config::lateralControllerSettings[MovementControllerSettings::DERIVATIVE_GAIN],
	Config::lateralControllerSettings[MovementControllerSettings::ANTI_WINDUP],
	Config::lateralControllerSettings[MovementControllerSettings::SMALL_ERROR_RANGE],
	Config::lateralControllerSettings[MovementControllerSettings::SMALL_ERROR_RANGE_TIMEOUT],
	Config::lateralControllerSettings[MovementControllerSettings::LARGE_ERROR_RANGE],
	Config::lateralControllerSettings[MovementControllerSettings::LARGE_ERROR_RANGE_TIMEOUT],
	Config::lateralControllerSettings[MovementControllerSettings::MAXIMUM_ACCELERATION]	 //
);

// angular PID controller
lemlib::ControllerSettings angularMovementController(
	Config::angularControllerSettings[MovementControllerSettings::PROPORTIONAL_GAIN],
	Config::angularControllerSettings[MovementControllerSettings::INTEGRAL_GAIN],
	Config::angularControllerSettings[MovementControllerSettings::DERIVATIVE_GAIN],
	Config::angularControllerSettings[MovementControllerSettings::ANTI_WINDUP],
	Config::angularControllerSettings[MovementControllerSettings::SMALL_ERROR_RANGE],
	Config::angularControllerSettings[MovementControllerSettings::SMALL_ERROR_RANGE_TIMEOUT],
	Config::angularControllerSettings[MovementControllerSettings::LARGE_ERROR_RANGE],
	Config::angularControllerSettings[MovementControllerSettings::LARGE_ERROR_RANGE_TIMEOUT],
	Config::angularControllerSettings[MovementControllerSettings::MAXIMUM_ACCELERATION]	 //
);

lemlib::ExpoDriveCurve driveCurve(
	Config::driveExpoDriveCurveSettings[ExpoDriveCurveSettings::DEADBAND],
	Config::driveExpoDriveCurveSettings[ExpoDriveCurveSettings::MIN_OUTPUT],
	Config::driveExpoDriveCurveSettings[ExpoDriveCurveSettings::CURVE]);

lemlib::ExpoDriveCurve turnCurve(
	Config::turnExpoDriveCurveSettings[ExpoDriveCurveSettings::DEADBAND],
	Config::turnExpoDriveCurveSettings[ExpoDriveCurveSettings::MIN_OUTPUT],
	Config::turnExpoDriveCurveSettings[ExpoDriveCurveSettings::CURVE]);

// create the chassis
lemlib::Chassis chassis(drivetrain,					// drivetrain settings
						lateralMovementController,	// lateral PID settings
						angularMovementController,	// angular PID settings
						odomSensors,				// odometry sensors
						&driveCurve,				// throttle curve
						&turnCurve					// steering curve
);

pros::adi::DigitalOut mogoHolderPiston(Config::adiPortNumbers[ADIPort::MOGO_HOLDER_PISTON][0]);

}  // namespace Devices

void initializeDevices(lemlib::Chassis& chassis) {
	pros::lcd::initialize();
	// pros::screen::set_pen(pros::Color::white);
	chassis.calibrate();  // Setup Sensors
						  // pros::lcd::initialize();
						  // pros::lcd::set_text(1, "Hello PROS User!");
						  // pros::lcd::register_btn1_cb(on_center_button);
}
