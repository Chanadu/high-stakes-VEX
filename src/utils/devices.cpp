#include "devices.hpp"
#include "configuration.hpp"
#include "main.h"

namespace Devices {
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// RESERVED PORTS:
// 21 -> Controller Receiver

pros::MotorGroup leftMotorGroup({1, -2, 3}, pros::MotorGears::blue);
pros::MotorGroup rightMotorGroup({-4, 5, -6}, pros::MotorGears::blue);

pros::MotorGroup intakeMotorGroup({7}, pros::MotorGears::red);
pros::Motor armMotor(8, pros::MotorGears::green);

pros::Imu imu(9);

pros::adi::Pneumatics holderPiston('H', false);

lemlib::Drivetrain drivetrain(&leftMotorGroup,					 // leftMotorGroup
							  &rightMotorGroup,					 // rightMotorGroup
							  Config::drivetrainTrackWidth,		 // trackWidth
							  Config::drivetrainWheelType,		 // wheelType
							  Config::drivetrainWheelRPM,		 // wheelRPM
							  Config::drivetrainHorizontalDrift	 // // horizontalDrift
);
lemlib::OdomSensors odomSensors(nullptr,  // vertical tracking wheel 1
								nullptr,  // vertical tracking wheel 2
								nullptr,  // horizontal tracking wheel 1
								nullptr,  // horizontal tracking wheel 2
								&imu	  // inertial sensor
);

lemlib::ExpoDriveCurve driveCurve(													 //
	Config::joystickThresholdPercentage / 100.0 * Config::maxControllerValue,		 // deadband
	Config::outputMovementThresholdPercentage / 100.0 * Config::maxControllerValue,	 // minOutput
	Config::lateralCurveGain														 // curve
);

lemlib::ExpoDriveCurve turnCurve(													 //
	Config::joystickThresholdPercentage / 100.0 * Config::maxControllerValue,		 // deadband
	Config::outputMovementThresholdPercentage / 100.0 * Config::maxControllerValue,	 // minOutput
	Config::angularCurveGain														 // curve
);

// create the chassis
lemlib::Chassis chassis(				//
	drivetrain,							// drivetrain settings
	Config::lateralMovementController,	// lateral PID settings
	Config::angularMovementController,	// angular PID settings
	odomSensors,						// odometry sensors
	&driveCurve,						// throttle curve
	&turnCurve							// steering curve
);

}  // namespace Devices

void initializeDevices(lemlib::Chassis& chassis) {
	pros::lcd::initialize();
	// pros::screen::set_pen(pros::Color::white);
	chassis.calibrate();  // Setup Sensors
}
