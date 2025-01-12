#include "autonomous/comp-auton.hpp"
#include "autonomous/autonomous.hpp"
#include "utils/configuration.hpp"
#include "utils/devices.hpp"

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

ASSET(RNNH1B_txt)
ASSET(RNPH1B_txt)
ASSET(RN2_txt)
ASSET(RN3_txt)
ASSET(RN4C_txt)
ASSET(RN4NC_txt)

ASSET(RPNH1B_txt)
ASSET(RPPH1B_txt)
ASSET(RP2_txt)
ASSET(RPPH3_txt)
ASSET(RPNH3_txt)
ASSET(RP4_txt)

void runAuton(const AutonTypes autonType) {
	using Devices::chassis;
	using Devices::holderPiston;
	using Devices::intakeMotorGroup;

	Config::controllerStrings[2] = fmt::format("Started {}", autonTypeString.at(autonType));
	pros::lcd::print(2, "Started %s", autonTypeString.at(autonType));

	const std::map<AutonTypes, std::vector<asset>> autonAssets = {
		{BP, {BPPH1B_txt, BP2_txt, BPPH3_txt, BP4_txt}},
		{BN, {BNPH1B_txt, BN2_txt, BN3_txt, BN4NC_txt}},
		{RP, {RPPH1B_txt, RP2_txt, RPPH3_txt, RP4_txt}},
		{RN, {RNPH1B_txt, RN2_txt, RN3_txt, RN4NC_txt}},
	};

	// chassis.setPose(0, 0, 0);
	intakeMotorGroup.move(0);
	Devices::leftMotorGroup.move(0);
	Devices::rightMotorGroup.move(0);
	holderPiston.extend();
	pros::delay(750);

	switch (autonType) {
		case BP:
			// chassis.moveToPoint(24, 0, 5000, {.forwards = false}, true);
			chassis.follow(autonAssets.at(BP)[0], 15, 2000, false, false);

			holderPiston.extend();
			intakeMotorGroup.move(127);

			chassis.follow(autonAssets.at(BP)[1], 15, 2000, true, false);

			intakeMotorGroup.move(0);
			chassis.follow(autonAssets.at(BP)[2], 15, 2000, true, false);

			holderPiston.extend();
			intakeMotorGroup.move(127);

			chassis.follow(autonAssets.at(BP)[3], 15, 2000, true, false);
			intakeMotorGroup.move(0);
			// chassis.follow(autonAssets.at(RP)[1], 15, 2000, false, false);
			break;
		case BN:
			chassis.follow(autonAssets.at(BN)[0], 15, 2000, false, false);
			holderPiston.extend();
			chassis.follow(autonAssets.at(BN)[1], 15, 2000, true, false);
			intakeMotorGroup.move(127);
			chassis.follow(autonAssets.at(BN)[2], 15, 2000, true, false);
			chassis.follow(autonAssets.at(BN)[3], 15, 2000, true, false);
			intakeMotorGroup.move(0);
			// chassis.follow(autonAssets.at(RN)[1], 15, 2000, false, false);
			break;
		case RP:
			chassis.follow(autonAssets.at(RP)[0], 15, 2000, false, false);

			holderPiston.extend();
			intakeMotorGroup.move(127);

			chassis.follow(autonAssets.at(RP)[1], 15, 2000, true, false);

			intakeMotorGroup.move(0);
			chassis.follow(autonAssets.at(RP)[2], 15, 2000, true, false);

			holderPiston.extend();
			intakeMotorGroup.move(127);

			chassis.follow(autonAssets.at(RP)[3], 15, 2000, true, false);
			intakeMotorGroup.move(0);
			// chassis.follow(autonAssets.at(RP)[1], 15, 2000, false, false);
			break;
		case RN:
			chassis.follow(autonAssets.at(RN)[0], 15, 2000, false, false);
			holderPiston.extend();
			chassis.follow(autonAssets.at(RN)[1], 15, 2000, true, false);
			intakeMotorGroup.move(127);
			chassis.follow(autonAssets.at(RN)[2], 15, 2000, true, false);
			chassis.follow(autonAssets.at(RN)[3], 15, 2000, true, false);
			intakeMotorGroup.move(0);
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
