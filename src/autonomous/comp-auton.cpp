#include "autonomous/comp-auton.hpp"
#include "autonomous/autonomous.hpp"

#include "configuration.hpp"
#include "devices.hpp"

// ASSET(example_txt)
// ASSET(example2_txt)
ASSET(BNNH1B_txt)
ASSET(BNPH1B_txt)
ASSET(BN2_txt)
ASSET(BN3_txt)
ASSET(BN4C_txt)
ASSET(BN4NC_txt)

ASSET(BPNH1B_txt)
ASSET(BPPH1B_txt)
ASSET(BP2_txt)
ASSET(BPPH3_txt)
ASSET(BPNH3_txt)
ASSET(BP4_txt)

// ASSET(RNNH1B_txt)
// ASSET(RNPH1B_txt)
// ASSET(RN2_txt)
// ASSET(RN3_txt)
// ASSET(RN4C_txt)
// ASSET(RN4NC_txt)

// ASSET(RPNH1B_txt)
// ASSET(RPPH1B_txt)
// ASSET(RP2_txt)
// ASSET(RPPH3_txt)
// ASSET(RPNH3_txt)
// ASSET(RP4_txt)


void runAuton(const AutonTypes autonType) {
	using Devices::chassis;
	using Devices::holderPiston;
	using Devices::intakeMotorGroup;

	Config::controllerStrings[2] = fmt::format("Started {}", autonTypeString.at(autonType));
	pros::lcd::print(2, "Started %s", autonTypeString.at(autonType));

	// const std::map<AutonTypes, std::vector<asset>> autonAssets = {
	// 	{BP, {}},
	// 	{BN, {}},
	// 	{RP, {RPPH1B_txt, RP2_txt, RPPH3_txt, RP4_txt}},
	// 	{RN, {RNPH1B_txt, RN2_txt, RN3_txt, RN4NC_txt}},
	// };

	// chassis.setPose(0, 0, 0);
	intakeMotorGroup.move(0);
	holderPiston.extend();

	switch (autonType) {
		case BP:
		Devices::leftMotorGroup.move(-75);
		Devices::rightMotorGroup.move(-75);
		pros::delay(750);
		Devices::leftMotorGroup.move(0);
		Devices::rightMotorGroup.move(0);
		holderPiston.retract();
		intakeMotorGroup.move(-127);
		
		// // chassis.moveToPoint(24, 0, 5000, {.forwards = false}, true);   
		// pros::delay(500);                                                                                                   
		// holderPiston.retract();
		// intakeMotorGroup.move(127);
			// chassis.follow(autonAssets.at(BP)[0], 15, 2000, false, false);

			// holderPiston.extend();
			// intakeMotorGroup.move(127);

			// chassis.follow(autonAssets.at(BP)[1], 15, 2000, true, false);
			
			// intakeMotorGroup.move(0);
			// chassis.follow(autonAssets.at(BP)[2], 15, 2000, true, false);
			
			// holderPiston.extend();
			// intakeMotorGroup.move(127);

			// chassis.follow(autonAssets.at(BP)[3], 15, 2000, true, false);
			// intakeMotorGroup.move(0);
			// // chassis.follow(autonAssets.at(RP)[1], 15, 2000, false, false);
			// break;
		// case BN:
		// 	chassis.follow(autonAssets.at(BN)[0], 15, 2000, false, false);
		// 	holderPiston.extend();
		// 	chassis.follow(autonAssets.at(BN)[1], 15, 2000, true, false);
		// 	intakeMotorGroup.move(127);
		// 	chassis.follow(autonAssets.at(BN)[2], 15, 2000, true, false);
		// 	chassis.follow(autonAssets.at(BN)[3], 15, 2000, true, false);
		// 	intakeMotorGroup.move(0);
		// 	// chassis.follow(autonAssets.at(RN)[1], 15, 2000, false, false);
		// 	break;
		// case RP:
		// 	chassis.follow(autonAssets.at(RP)[0], 15, 2000, false, false);

		// 	holderPiston.extend();
		// 	intakeMotorGroup.move(127);

		// 	chassis.follow(autonAssets.at(RP)[1], 15, 2000, true, false);
			
		// 	intakeMotorGroup.move(0);
		// 	chassis.follow(autonAssets.at(RP)[2], 15, 2000, true, false);
			
		// 	holderPiston.extend();
		// 	intakeMotorGroup.move(127);

		// 	chassis.follow(autonAssets.at(RP)[3], 15, 2000, true, false);
		// 	intakeMotorGroup.move(0);
		// 	// chassis.follow(autonAssets.at(RP)[1], 15, 2000, false, false);
		// 	break;
		// case RN:
		// 	chassis.follow(autonAssets.at(RN)[0], 15, 2000, false, false);
		// 	holderPiston.extend();
		// 	chassis.follow(autonAssets.at(RN)[1], 15, 2000, true, false);
		// 	intakeMotorGroup.move(127);
		// 	chassis.follow(autonAssets.at(RN)[2], 15, 2000, true, false);
		// 	chassis.follow(autonAssets.at(RN)[3], 15, 2000, true, false);
		// 	intakeMotorGroup.move(0);
		// 	// chassis.follow(autonAssets.at(RN)[1], 15, 2000, false, false);
		// 	break;
		// case TA:
		// 	tuneAngularPID();
		// 	break;
		// case TL:
		// 	tuneLateralPID();
		// 	break;
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
