#include "autonomous/autonomous.hpp"
#include "configuration.hpp"
#include "devices.hpp"
#include "main.h"
#include "opcontrol/device-controller.hpp"
#include "opcontrol/drivetrain-movement.hpp"
#include "screen-displays.hpp"

[[noreturn]] void controllerLinePrinting(void* param) {
	while (true) {
		for (int i = 0; i < 3; i++) {
			Devices::controller.set_text(i, 0, fmt::format("{:<15}", Config::controllerStrings[i]));
			pros::delay(50);
		}
		if (!Config::controllerRumblePattern.empty()) {
			Devices::controller.rumble(Config::controllerRumblePattern.c_str());
			Config::controllerRumblePattern = "";
		}
		pros::delay(50);
	}
}
enum class AutonVars {
	PROPORTIONAL_GAIN,
	INTEGRAL_GAIN,
	DERIVATIVE_GAIN,
	ANTI_WINDUP,
	SLEW,
};

float proportionalGain = 2;
float proportionalGainChange = 0.5;
float integralGain = 0;
float integralGainChange = 0.5;
float derivativeGain = 10;
float derivativeGainChange = 0.5;
float antiWindup = 3;
float antiWindupChange = 1;
float slew = 0;
float slewChange = 1;
int counter = 0;

void tuningAuton(AutonVars& currentlyChangingVar, short& lineNumber) {
	if (Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
		switch (currentlyChangingVar) {
			case AutonVars::PROPORTIONAL_GAIN:
				currentlyChangingVar = AutonVars::SLEW;
				break;
			case AutonVars::SLEW:
				currentlyChangingVar = AutonVars::ANTI_WINDUP;
				break;
			case AutonVars::ANTI_WINDUP:
				currentlyChangingVar = AutonVars::DERIVATIVE_GAIN;
				break;
			case AutonVars::DERIVATIVE_GAIN:
				currentlyChangingVar = AutonVars::INTEGRAL_GAIN;
				break;
			case AutonVars::INTEGRAL_GAIN:
				currentlyChangingVar = AutonVars::PROPORTIONAL_GAIN;
				break;
		}
	} else if (Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
		switch (currentlyChangingVar) {
			case AutonVars::PROPORTIONAL_GAIN:
				currentlyChangingVar = AutonVars::INTEGRAL_GAIN;
				break;
			case AutonVars::INTEGRAL_GAIN:
				currentlyChangingVar = AutonVars::DERIVATIVE_GAIN;
				break;
			case AutonVars::DERIVATIVE_GAIN:
				currentlyChangingVar = AutonVars::ANTI_WINDUP;
				break;
			case AutonVars::ANTI_WINDUP:
				currentlyChangingVar = AutonVars::SLEW;
				break;
			case AutonVars::SLEW:
				currentlyChangingVar = AutonVars::PROPORTIONAL_GAIN;
				break;
		}
	}

	int i = Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP) -
			Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN);
	pros::lcd::print(lineNumber, "i PRESSED (%d)", i);
	bool changed = false;
	if (i != 0) {
		changed = true;
	}
	switch (currentlyChangingVar) {
		case AutonVars::PROPORTIONAL_GAIN:
			proportionalGain += i * proportionalGainChange;
			break;
		case AutonVars::INTEGRAL_GAIN:
			integralGain += i * integralGainChange;
			break;
		case AutonVars::DERIVATIVE_GAIN:
			derivativeGain += i * derivativeGainChange;
			break;
		case AutonVars::ANTI_WINDUP:
			antiWindup += i * antiWindupChange;
			break;
		case AutonVars::SLEW:
			slew += i * slewChange;
			break;
	}

	if (changed) {
		const lemlib::ControllerSettings tempController(proportionalGain,  // ProportionalGain
														integralGain,	   // IntegralGain
														derivativeGain,	   // DerivativeGain
														antiWindup,		   // AntiWindup
														1,				   // SmallErrorRange
														100,			   // SmallErrorRangeTimeout
														3,				   // LargeErrorRange
														500,			   // LargeErrorRangeTimeout
														slew			   // MaximumAcceleration
		);
		Devices::setChassis(new lemlib::Chassis(  //
			Devices::drivetrain,				  // drivetrain settings
			Config::lateralMovementController,	  // lateral PID settings
			tempController,						  // angular PID settings
			Devices::odomSensors,				  // odometry sensors
			&Devices::driveCurve,				  // throttle curve
			&Devices::turnCurve					  // steering curve
			));
	}
	if (Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
		// pros::lcd::print(lineNumber, "A PRESSED");
		Config::controllerStrings[2] = fmt::format("APID: {}", counter);
		counter++;
		Devices::chassis->calibrate();
		tuneAngularPID();
	}
	std::string name;
	float value;

	switch (currentlyChangingVar) {
		case AutonVars::PROPORTIONAL_GAIN:
			name = "PG";
			value = proportionalGain;
			break;
		case AutonVars::INTEGRAL_GAIN:
			name = "IG";
			value = integralGain;
			break;
		case AutonVars::DERIVATIVE_GAIN:
			name = "DG";
			value = derivativeGain;
			break;
		case AutonVars::ANTI_WINDUP:
			name = "AW";
			value = antiWindup;
			break;
		case AutonVars::SLEW:
			name = "S";
			value = slew;
			break;
	}
	Config::controllerStrings[1] = fmt::format("{}: {}", name, value);
}

void opcontrolRunner() {
	pros::Task _(controllerLinePrinting, nullptr, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT,
				 "Controller Line Task");

	bool isTuningAuton = true;
	AutonVars currentlyChangingVar = AutonVars::PROPORTIONAL_GAIN;

	while (true) {
		short lineNumber = 0;

		batteryDisplay(lineNumber);
		lineNumber++;
		chassisPositionDisplay(lineNumber);

		if (isTuningAuton) {
			tuningAuton(currentlyChangingVar, lineNumber);
			pros::delay(20);
			continue;
		}

		drivetrainMovementController(lineNumber);

		if (Devices::controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			Config::controllerRumblePattern = ".-.-..";
		}

		intakeMotorControl();
		armMotorControl();
		holderPistonControl();
		// pros::screen::print(TEXT_MEDIUM, i++, "Testing");
		// gui();
		pros::delay(20);
	}
}
