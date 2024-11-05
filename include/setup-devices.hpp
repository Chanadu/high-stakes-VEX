#ifndef _SETUP_DEVICES_HPP_
#define _SETUP_DEVICES_HPP_

#include "main.h"

namespace Devices {
extern pros::Controller controller;
extern pros::MotorGroup leftMotorGroup;
extern pros::MotorGroup rightMotorGroup;

extern lemlib::Drivetrain drivetrain;
extern pros::Imu imu;
// extern pros::Rotation horizontalEncoder;
// extern pros::adi::Encoder verticalEncoder;
// extern lemlib::TrackingWheel horizontalTrackingWheel;
// extern lemlib::TrackingWheel verticalTrackingWheel;

extern lemlib::OdomSensors odomSensors;

extern lemlib::ControllerSettings lateralMovementController;
extern lemlib::ControllerSettings angularMovementController;

extern lemlib::Chassis chassis;

extern pros::adi::DigitalOut mogoHolderPiston;
}  // namespace Devices

extern void initializeDevices(lemlib::Chassis* chassis);

#endif	// _SETUP_DEVICES_HPP
