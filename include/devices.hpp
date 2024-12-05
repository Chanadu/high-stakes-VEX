#ifndef SETUP_DEVICES_HPP
#define SETUP_DEVICES_HPP

#include "main.h"

namespace Devices {
extern pros::Controller controller;
extern pros::MotorGroup leftMotorGroup;
extern pros::MotorGroup rightMotorGroup;

extern lemlib::Drivetrain drivetrain;

extern pros::MotorGroup intakeMotorGroup;
extern pros::controller_digital_e_t intakeInButton;
extern pros::controller_digital_e_t intakeOutButton;

extern pros::Motor armMotor;
extern pros::controller_digital_e_t armInButton;
extern pros::controller_digital_e_t armOutButton;

extern pros::Imu imu;

extern pros::adi::Pneumatics holderPiston;
extern pros::controller_digital_e_t holderPistonButton;
// extern pros::Rotation horizontalEncoder;
// extern pros::adi::Encoder verticalEncoder;
// extern lemlib::TrackingWheel horizontalTrackingWheel;
// extern lemlib::TrackingWheel verticalTrackingWheel;

extern lemlib::OdomSensors odomSensors;

extern lemlib::ControllerSettings lateralMovementController;
extern lemlib::ControllerSettings angularMovementController;

extern lemlib::ExpoDriveCurve driveCurve;
extern lemlib::ExpoDriveCurve turnCurve;

extern lemlib::Chassis* chassis;

extern void setChassis(lemlib::Chassis* chassis);
}  // namespace Devices

extern void initializeDevices();

#endif	// SETUP_DEVICES_HPP
