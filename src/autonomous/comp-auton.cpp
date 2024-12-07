#include "autonomous/comp-auton.hpp"
#include "autonomous/autonomous.hpp"

#include "configuration.hpp"
#include "devices.hpp"

// ASSET(example_txt)
// ASSET(example2_txt)

ASSET(BP_txt)
ASSET(BN_txt)
ASSET(RP_txt)
ASSET(RN_txt)

void runAuton(const AutonTypes autonType) {
	using Devices::chassis;
	using Devices::holderPiston;
	using Devices::intakeMotorGroup;

	Config::controllerStrings[2] = fmt::format("Started {}", autonTypeString.at(autonType));
	pros::lcd::print(2, "Started %s", autonTypeString.at(autonType));

	const std::map<AutonTypes, std::vector<asset>> autonAssets = {
		{BP, {BP_txt}},
		{BN, {BN_txt}},
		{RP, {RP_txt}},
		{RN, {RN_txt}},
	};

	chassis.setPose(0, 0, 0);
	switch (autonType) {
		case BP:
			chassis.follow(autonAssets.at(BP)[0], 15, 2000, false, false);
			// chassis.follow(autonAssets.at(BP)[1], 15, 2000, false, false);
			break;
		case BN:
			chassis.follow(autonAssets.at(BN)[0], 15, 2000, false, false);
			// chassis.follow(autonAssets.at(BN)[1], 15, 2000, false, false);
			break;
		case RP:
			chassis.follow(autonAssets.at(RP)[0], 15, 2000, false, false);
			// chassis.follow(autonAssets.at(RP)[1], 15, 2000, false, false);
			break;
		case RN:
			chassis.follow(autonAssets.at(RN)[0], 15, 2000, false, false);
			// chassis.follow(autonAssets.at(RN)[1], 15, 2000, false, false);
			break;
		case TA:
			tuneAngularPID();
			break;
		case TL:
			tuneLateralPID();
			break;
	}
}

// chassis.follow(RABN_txt, 15, 2000, false, false);
// lookahead distance: 15 inches
// timeout: 2000 ms
// chassis.follow(example_txt, 15, 2000, true, false);
// pros::lcd::print(5, "E: %s", example_txt);
// follow the next path, but with the robot going backwards
// chassis.follow(example2_txt, 15, 2000, false, false);
/*
float f = flip ? -1 : 1;

intakeMotorGroup.move(0);
holderPiston.extend();
// -90 - start, do nothing, but go backwards to next point
chassis.moveToPose(0, 0 * f, 90, 5000);
// -20 - clamp BEFORE turning
chassis.moveToPoint(-19.331, 21.605 * f, 5000, {.forwards = false});
holderPiston.retract();
chassis.turnToHeading(20, 5000);
// -270 - turn on intake
chassis.moveToPose(0, 12.698 * f, 270, 5000);
intakeMotorGroup.move(127);
// -270 - turn off intake
chassis.moveToPose(0, 39.23 * f, 270, 5000, {.forwards = false});
intakeMotorGroup.move(0);
// -270 - nothing
chassis.moveToPose(-15.161, 28.806 * f, 270, 5000);

// -0 - turn on intake
chassis.moveToPose(-14.593, 41.694 * f, 0, 5000);
intakeMotorGroup.move(127);
// -80 - turn off intake
chassis.moveToPose(11.56, 41.883 * f, 80, 5000);
intakeMotorGroup.move(0);
// -90 - turn on intake
chassis.moveToPose(12.887, 12.887 * f, 90, 5000);
intakeMotorGroup.move(127);
// -90 - go backwards to next point
chassis.moveToPose(12.887, -5.685 * f, 90, 5000);
// -170 - turn off intake and unclamp
chassis.moveToPose(10.044, 6.633 * f, 170, 5000, {.forwards = false});
intakeMotorGroup.move(0);
holderPiston.extend();
// -270 - nothing
chassis.moveToPose(-48.137, 1.137 * f, 270, 5000);
// -270 turn on intake(try to point ring on wall stake), wait a bit then turn off intake
chassis.moveToPose(-48.137, -7.96 * f, 270, 5000);

intakeMotorGroup.move(127);
pros::delay(500);
intakeMotorGroup.move(0);
// -340 - nothing
chassis.moveToPose(-47.948, 11.75 * f, 340, 5000);
// 230 - nothing
chassis.moveToPose(21.984, -21.605 * f, 230, 5000);
// -230 - nothing
chassis.moveToPose(-31.46, 33.355 * f, 230, 5000);*/
