#include "main.h"

constexpr int DRIVE_SPEED = 50;
constexpr int TURN_SPEED = 25;
constexpr int SWING_SPEED = 25;
void basePositive() {
	// chassis.odom_xyt_set(-58.481_in, -24.53_in, 270_deg);
	chassis.odom_xyt_set(-61_in, -24.53_in, 270_deg);

	intakeMotors.move(0);
	holderPiston.extend();

	chassis.pid_odom_set(
		{
			{{-26.66_in, -25.665_in, 225_deg}, rev, DRIVE_SPEED},
			{{-24.868_in, -43.17_in, 164_deg}, fwd, (int) (DRIVE_SPEED * .75)},
			// {{-23.795_in, -47.701_in, 90_deg}, fwd, DRIVE_SPEED},
			// {{-9_in, -47.052_in, 270_deg}, rev, DRIVE_SPEED},
			// {{-12.947_in, -38.402_in, 0_deg}, fwd, DRIVE_SPEED},
			{{-20.33_in, -34.059_in, 0_deg}, fwd, DRIVE_SPEED},
			{{-14.723_in, -11.338_in, 0_deg}, fwd, DRIVE_SPEED},
		},
		true);

	int currentIndex = 0;

	chassis.pid_wait_until_index(currentIndex++);  // 0
	holderPiston.retract();
	intakeMotors.move(-127);

	chassis.pid_wait_until_index(currentIndex++);  // 1

	chassis.pid_wait_until_index(currentIndex++);  // 2
	intakeMotors.move(0);

	chassis.pid_wait_until_index(currentIndex++);  // 3
	

	chassis.pid_wait();


}

void centerGoalPositive() {
	// chassis.odom_xyt_set(-58.481_in, -24.53_in, 270_deg);
	chassis.odom_xyt_set(-61_in, -24.53_in, 270_deg);

	intakeMotors.move(0);
	holderPiston.extend();

	chassis.pid_odom_set(
		{
			{{-26.66_in, -25.665_in, 225_deg}, rev, DRIVE_SPEED},
			{{-24.868_in, -43.17_in, 164_deg}, fwd, DRIVE_SPEED},
			{{-23.795_in, -47.701_in, 90_deg}, fwd, DRIVE_SPEED},
			{{-9_in, -47.052_in, 270_deg}, rev, DRIVE_SPEED},
			{{-12.947_in, -38.402_in, 0_deg}, fwd, DRIVE_SPEED},
			{{-14.723_in, -11.338_in, 0_deg}, fwd, DRIVE_SPEED},
		},
		true);

	chassis.pid_wait_until_index(0);
	holderPiston.retract();
	intakeMotors.move(-127);

	chassis.pid_wait_until_index(1);
	intakeMotors.move(0);
	holderPiston.extend();

	chassis.pid_wait_until_index(3);
	holderPiston.retract();

	chassis.pid_wait_until_index(4);
	intakeMotors.move(-127);
	chassis.pid_wait();
	intakeMotors.move(0);
}

void baseNegative() {
	chassis.odom_xyt_set(-61_in, 23.525_in, 270_deg);

	intakeMotors.move(0);
	holderPiston.extend();

	chassis.pid_odom_set(
		{
			{{-29.991_in, 29.348_in, 315_deg}, rev, DRIVE_SPEED},
			{{-33.807_in, 33.672_in, 315_deg}, rev, DRIVE_SPEED + 30},
			{{-14.475_in, 37.487_in, 45_deg}, fwd, DRIVE_SPEED - 10},
			{{-23.632_in, 46.644_in, 315_deg}, fwd, DRIVE_SPEED},
			{{-15.238_in, 50.714_in, 90_deg}, fwd, DRIVE_SPEED},
			{{-34.316_in, 44.355_in, 330_deg}, rev, DRIVE_SPEED * 2},
			{{-13.996_in, 7.128_in, 140_deg}, fwd, DRIVE_SPEED},
		},
		true);

	int currentIndex = 0;
	chassis.pid_wait_until_index(currentIndex++);  // 0

	chassis.pid_wait_until_index(currentIndex++);  // 1

	holderPiston.retract();
	holderPiston.retract();

	intakeMotors.move(-100);

	chassis.pid_wait_until_index(currentIndex++);  // 1

	chassis.pid_wait_until_index(currentIndex++);  // 2

	chassis.pid_wait_until_index(currentIndex++);  // 3

	intakeMotors.move(0);

	chassis.pid_wait_until_index(currentIndex++);  // 4

	chassis.pid_wait_until_index(currentIndex++);  // 4

	chassis.pid_wait();

}

void redPositive() {
	basePositive();
	// centerGoalPositive();
}

void redNegative() {
	baseNegative();
}

void blueModify() {
	chassis.odom_x_flip();
	// chassis.odom_theta_flip();
}

void bluePositive() {
	blueModify();
	basePositive();
	// centerGoalPositive();
}

void blueNegative() {
	blueModify();
	baseNegative();
}
