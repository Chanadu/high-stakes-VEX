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
			{{-24.868_in, -43.17_in, 164_deg}, fwd, static_cast<int>(DRIVE_SPEED * .75)},
			{{-17.414_in, -29.22_in, 0_deg}, fwd, DRIVE_SPEED},
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

void baseNegative() {
	chassis.odom_xyt_set(-61_in, 23.525_in, 270_deg);

	intakeMotors.move(0);
	holderPiston.extend();

	chassis.pid_odom_set(
		{

			{{-33.807_in, 33.672_in, 315_deg}, rev, DRIVE_SPEED},
			{{-29.991_in, 29.348_in, 315_deg}, rev, DRIVE_SPEED},  // Goal / Preload
			{{-22.665_in, 22.864_in, 315_deg}, rev, DRIVE_SPEED},
			{{-29.991_in, 29.348_in, 315_deg}, fwd, DRIVE_SPEED},

			{{-23.632_in, 46.644_in, 45_deg}, fwd, DRIVE_SPEED},  // Disk 2
			{{-23.246_in, 34.275_in, 0_deg}, rev, DRIVE_SPEED},

			{{-9.776_in, 43.335_in, 90_deg}, fwd, DRIVE_SPEED},	 // Disk 3
			{{-23.246_in, 34.275_in, 45_deg}, rev, DRIVE_SPEED},

			{{-11.921_in, 7.692_in, 145_deg}, fwd, DRIVE_SPEED},
		},
		true);

	int currentIndex = 0;

	chassis.pid_wait_until_index(currentIndex++);  // 0

	chassis.pid_wait_until_index(currentIndex++);  // 1
	{
		holderPiston.retract();
		pros::delay(100);
		intakeMotors.move(-100);
	}
	chassis.pid_wait_until_index(currentIndex++);  // 2

	chassis.pid_wait_until_index(currentIndex++);  // 3

	chassis.pid_wait_until_index(currentIndex++);  // 4

	chassis.pid_wait_until_index(currentIndex++);  // 5

	chassis.pid_wait_until_index(currentIndex++);  // 6

	chassis.pid_wait_until_index(currentIndex++);  // 7

	chassis.pid_wait_until_index(currentIndex++);  // 8
	{
		intakeMotors.move(0);
	}
	chassis.pid_wait_until_index(currentIndex++);  // 9

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
