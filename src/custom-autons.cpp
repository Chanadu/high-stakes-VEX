#include "main.h"
//
// Created by chanadu on 1/17/25.
//

constexpr int DRIVE_SPEED = 50;
constexpr int TURN_SPEED = 25;
constexpr int SWING_SPEED = 25;
void basePositive() {
    // chassis.odom_xyt_set(-58.481_in, -24.53_in, 270_deg);
    chassis.odom_xyt_set(-61_in, -24.53_in, 270_deg);

    intakeMotors.move(0);
    holderPiston.extend();

    chassis.pid_odom_set({
                             {{-26.66_in, -25.665_in, 225_deg}, rev, DRIVE_SPEED},
                             {{-24.868_in, -43.17_in, 164_deg}, fwd, DRIVE_SPEED},
                             // {{-23.795_in, -47.701_in, 90_deg}, fwd, DRIVE_SPEED},
                             // {{-9_in, -47.052_in, 270_deg}, rev, DRIVE_SPEED},
                             // {{-12.947_in, -38.402_in, 0_deg}, fwd, DRIVE_SPEED},
                             {{-14.723_in, -11.338_in, 0_deg}, fwd, DRIVE_SPEED},
                         },
                         true);

    int currentIndex = 0;

    chassis.pid_wait_until_index(currentIndex++);  // 0
    holderPiston.retract();
    intakeMotors.move(-127);

    chassis.pid_wait_until_index(currentIndex++);  // 1

    chassis.pid_wait_until_index(currentIndex++);  // 2

    chassis.pid_wait();

    intakeMotors.move(0);
}

void centerGoalPositive() {
    // chassis.odom_xyt_set(-58.481_in, -24.53_in, 270_deg);
    chassis.odom_xyt_set(-61_in, -24.53_in, 270_deg);

    intakeMotors.move(0);
    holderPiston.extend();

    chassis.pid_odom_set({
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
    chassis.odom_xyt_set(-61.161_in, 23.525_in, 270_deg);

    intakeMotors.move(0);
    holderPiston.extend();

    chassis.pid_odom_set({
                             {{-27.964_in, 27.126_in, 315_deg}, rev, DRIVE_SPEED},
                             {{-10.757_in, 37.904_in, 45_deg}, fwd, DRIVE_SPEED},
                             {{-19.019_in, 42.312_in, 315_deg}, fwd, DRIVE_SPEED},
                             {{-9.969_in, 50.321_in, 90_deg}, fwd, DRIVE_SPEED},
                             {{-14.715_in, 12.552_in, 140_deg}, fwd, DRIVE_SPEED},
                         },
                         true);

    int currentIndex = 0;
    chassis.pid_wait_until_index(currentIndex++);  // 0

    chassis.pid_wait_until_index(currentIndex++);  // 1
    holderPiston.retract();
    intakeMotors.move(-127);

    chassis.pid_wait_until_index(currentIndex++);  // 2

    chassis.pid_wait_until_index(currentIndex++);  // 3

    chassis.pid_wait_until_index(currentIndex++);  // 4

    chassis.pid_wait();

    intakeMotors.move(0);
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
