#include "utils/devices.hpp"
#include "main.h"
#include "utils/configuration.hpp"

namespace Devices {
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// RESERVED PORTS:
// 6, 7 -> Inconsistent
// 21 -> Controller Receiver

pros::MotorGroup leftMotorGroup({1, -12, 3}, pros::MotorGears::blue);
pros::MotorGroup rightMotorGroup({-4, 5, -8}, pros::MotorGears::blue);

pros::MotorGroup intakeMotorGroup({9, -10}, pros::MotorGears::red);
pros::controller_digital_e_t intakeInButton = pros::E_CONTROLLER_DIGITAL_L2;
pros::controller_digital_e_t intakeOutButton = pros::E_CONTROLLER_DIGITAL_L1;
pros::Motor armMotor(12, pros::MotorGears::green);
pros::controller_digital_e_t armInButton = pros::E_CONTROLLER_DIGITAL_R2;
pros::controller_digital_e_t armOutButton = pros::E_CONTROLLER_DIGITAL_R1;

pros::Imu imu(11);

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
	Devices::chassis.calibrate();  // Set
	Devices::leftMotorGroup.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	Devices::rightMotorGroup.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	Config::controllerStrings[0] =
		fmt::format("Battery: {:>3}%", static_cast<int>(pros::battery::get_capacity()));
	Config::controllerStrings[1] = "";
	Config::controllerStrings[2] = "";

	Devices::intakeMotorGroup.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	// Config::controllerStrings[2] =
	// 	"DV MV: " + Config::drivetrainMovementToAbbr.at(Config::drivetrainMovement);
}
