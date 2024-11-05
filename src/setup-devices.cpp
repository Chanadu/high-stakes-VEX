#include "setup-devices.hpp"
#include "configuration.hpp"
#include "main.h"

namespace Devices {
pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftMotorGroup(Config::portNumbers[Port::LeftMotors],
								Config::portGearsets[Port::LeftMotors]);
pros::MotorGroup rightMotorGroup(Config::portNumbers[Port::RightMotors],
								 Config::portGearsets[Port::RightMotors]);

lemlib::Drivetrain drivetrain(&leftMotorGroup,
							  &rightMotorGroup,
							  Config::drivetrainTrackWidth,
							  Config::drivetrainWheelType,
							  Config::drivetrainWheelRPM,
							  Config::drivetrainHorizontalDrift	 //
);

pros::Imu imu(Config::portNumbers[Port::InertialSensor][0]);
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
	Config::lateralControllerSettings[MovementControllerSettings::ProportionalGain],
	Config::lateralControllerSettings[MovementControllerSettings::IntegralGain],
	Config::lateralControllerSettings[MovementControllerSettings::DerivativeGain],
	Config::lateralControllerSettings[MovementControllerSettings::AntiWindup],
	Config::lateralControllerSettings[MovementControllerSettings::SmallErrorRange],
	Config::lateralControllerSettings[MovementControllerSettings::SmallErrorRangeTimeout],
	Config::lateralControllerSettings[MovementControllerSettings::LargeErrorRange],
	Config::lateralControllerSettings[MovementControllerSettings::LargeErrorRangeTimeout],
	Config::lateralControllerSettings[MovementControllerSettings::MaximumAcceleration]	//
);

// angular PID controller
lemlib::ControllerSettings angularMovementController(
	Config::angularControllerSettings[MovementControllerSettings::ProportionalGain],
	Config::angularControllerSettings[MovementControllerSettings::IntegralGain],
	Config::angularControllerSettings[MovementControllerSettings::DerivativeGain],
	Config::angularControllerSettings[MovementControllerSettings::AntiWindup],
	Config::angularControllerSettings[MovementControllerSettings::SmallErrorRange],
	Config::angularControllerSettings[MovementControllerSettings::SmallErrorRangeTimeout],
	Config::angularControllerSettings[MovementControllerSettings::LargeErrorRange],
	Config::angularControllerSettings[MovementControllerSettings::LargeErrorRangeTimeout],
	Config::angularControllerSettings[MovementControllerSettings::MaximumAcceleration]	//
);

lemlib::ExpoDriveCurve driveCurve(
	Config::driveExpoDriveCurveSettings[ExpoDriveCurveSettings::Deadband],
	Config::driveExpoDriveCurveSettings[ExpoDriveCurveSettings::MinOutput],
	Config::driveExpoDriveCurveSettings[ExpoDriveCurveSettings::Curve]	//
);

lemlib::ExpoDriveCurve turnCurve(
	Config::turnExpoDriveCurveSettings[ExpoDriveCurveSettings::Deadband],
	Config::turnExpoDriveCurveSettings[ExpoDriveCurveSettings::MinOutput],
	Config::turnExpoDriveCurveSettings[ExpoDriveCurveSettings::Curve]  //
);

// create the chassis
lemlib::Chassis chassis(drivetrain,					// drivetrain settings
						lateralMovementController,	// lateral PID settings
						angularMovementController,	// angular PID settings
						odomSensors,				// odometry sensors
						&driveCurve,				// throttle curve
						&turnCurve					// steering curve
);

pros::adi::DigitalOut mogoHolderPiston(Config::adiPortNumbers[ADIPort::MogoHolderPiston][0]);

}  // namespace Devices

void initializeDevices(lemlib::Chassis& chassis) {
	pros::lcd::initialize();
	// pros::screen::set_pen(pros::Color::white);
	chassis.calibrate();  // Setup Sensors
}
