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
pros::controller_digital_e_t intakeInButton = pros::E_CONTROLLER_DIGITAL_L2;
pros::controller_digital_e_t intakeOutButton = pros::E_CONTROLLER_DIGITAL_L1;
pros::Motor armMotor(8, pros::MotorGears::green);
pros::controller_digital_e_t armInButton = pros::E_CONTROLLER_DIGITAL_R2;
pros::controller_digital_e_t armOutButton = pros::E_CONTROLLER_DIGITAL_R1;

pros::Imu imu(9);

pros::adi::Pneumatics holderPiston('H', false, false);
pros::controller_digital_e_t holderPistonButton = pros::E_CONTROLLER_DIGITAL_Y;

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

lemlib::ExpoDriveCurve driveCurve(													  //
	Config::joystickThresholdPercentage / 100.0f * Config::maxControllerValue,		  // deadband
	Config::outputMovementThresholdPercentage / 100.0f * Config::maxControllerValue,  // minOutput
	Config::lateralCurveGain														  // curve
);

lemlib::ExpoDriveCurve turnCurve(													  //
	Config::joystickThresholdPercentage / 100.0f * Config::maxControllerValue,		  // deadband
	Config::outputMovementThresholdPercentage / 100.0f * Config::maxControllerValue,  // minOutput
	Config::angularCurveGain														  // curve
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

void initializeDevices() {
	pros::lcd::initialize();
	// pros::screen::set_pen(pros::Color::white);
	Devices::chassis.calibrate();  // Setup Sensors

	Config::controllerStrings[0] =
		std::format("Battery:{:>3}%", static_cast<int>(pros::battery::get_capacity()));
	Config::controllerStrings[1] = "input?";
	Config::controllerStrings[2] =
		"DV MV: " + Config::drivetrainMovementToAbbr.at(Config::drivetrainMovement);
}
