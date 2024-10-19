#include "setup-devices.hpp"
#include "configuration.hpp"
#include "lemlib/api.hpp"
#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftMotorGroup(portNumbers[PortType::LEFT_MOTORS],
								portGearsets[PortType::LEFT_MOTORS]);
pros::MotorGroup rightMotorGroup(portNumbers[PortType::RIGHT_MOTORS],
								 portGearsets[PortType::RIGHT_MOTORS]);

lemlib::Drivetrain drivetrain(&leftMotorGroup,
							  &rightMotorGroup,
							  drivetrainTrackWidth,
							  drivetrainWheelType,
							  drivetrainWheelRPM,
							  drivetrainHorizontalDrift);

pros::Imu imu(portNumbers[PortType::INERTIAL_SENSOR][0]);
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
	lateralControllerSettings[PROPORTIONAL_GAIN],
	lateralControllerSettings[INTEGRAL_GAIN],
	lateralControllerSettings[DERIVATIVE_GAIN],
	lateralControllerSettings[ANTI_WINDUP],
	lateralControllerSettings[SMALL_ERROR_RANGE],
	lateralControllerSettings[SMALL_ERROR_RANGE_TIMEOUT],
	lateralControllerSettings[LARGE_ERROR_RANGE],
	lateralControllerSettings[LARGE_ERROR_RANGE_TIMEOUT],
	lateralControllerSettings[MAXIMUM_ACCELERATION]	 //
);

// angular PID controller
lemlib::ControllerSettings angularMovementController(
	angularControllerSettings[PROPORTIONAL_GAIN],
	angularControllerSettings[INTEGRAL_GAIN],
	angularControllerSettings[DERIVATIVE_GAIN],
	angularControllerSettings[ANTI_WINDUP],
	angularControllerSettings[SMALL_ERROR_RANGE],
	angularControllerSettings[SMALL_ERROR_RANGE_TIMEOUT],
	angularControllerSettings[LARGE_ERROR_RANGE],
	angularControllerSettings[LARGE_ERROR_RANGE_TIMEOUT],
	angularControllerSettings[MAXIMUM_ACCELERATION]	 //
);

lemlib::ExpoDriveCurve driveCurve(driveExpoDriveCurveSettings[DEADBAND],
								  driveExpoDriveCurveSettings[MIN_OUTPUT],
								  driveExpoDriveCurveSettings[CURVE]);

lemlib::ExpoDriveCurve turnCurve(turnExpoDriveCurveSettings[DEADBAND],
								 turnExpoDriveCurveSettings[MIN_OUTPUT],
								 turnExpoDriveCurveSettings[CURVE]);

// create the chassis
lemlib::Chassis chassis(drivetrain,					// drivetrain settings
						lateralMovementController,	// lateral PID settings
						angularMovementController,	// angular PID settings
						odomSensors,				// odometry sensors
						&driveCurve,				// throttle curve
						&turnCurve					// steering curve
);

void initializeDevices(void) {
	pros::screen::set_pen(pros::Color::white);
	chassis.calibrate();  // Setup Sensors
						  // pros::lcd::initialize();
						  // pros::lcd::set_text(1, "Hello PROS User!");
						  // pros::lcd::register_btn1_cb(on_center_button);
}
