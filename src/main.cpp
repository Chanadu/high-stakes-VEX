#include "main.h"

ez::Drive chassis(
    {-4, 5, -8},
    {1, -12, 3},
    11,
    2.75,
    (600.0) * (48.0 / 60.0));

void initialize() {
    ez::ez_template_print();

    pros::delay(500);

    chassis.opcontrol_curve_buttons_toggle(true);
    chassis.opcontrol_drive_activebrake_set(2.0);
    chassis.opcontrol_curve_default_set(1.019, 1.019);

    default_constants();

    // Autonomous Selector using LLEMU
    ez::as::auton_selector.autons_add(  //
        {
            // {"Drive\n\nDrive forward and come back", drive_example},
            // {"Turn\n\nTurn 3 times.", turn_example},
            // {"Drive and Turn\n\nDrive forward, turn, come back", drive_and_turn},
            // {"Drive and Turn\n\nSlow down during drive", wait_until_change_speed},
            // {"Swing Turn\n\nSwing in an 'S' curve", swing_example},
            // {"Motion Chaining\n\nDrive forward, turn, and come back, but blend everything together :D", motion_chaining},
            // {"Combine all 3 movements", combining_movements},
            // {"Interference\n\nAfter driving forward, robot performs differently if interfered or not", interfered_example},
            // {"Simple Odom\n\nThis is the same as the drive example, but it uses odom instead!", odom_drive_example},
            // {"Pure Pursuit\n\nGo to (0, 30) and pass through (6, 10) on the way.  Come back to (0, 0)", odom_pure_pursuit_example},
            // {"Pure Pursuit Wait Until\n\nGo to (24, 24) but start running an intakeMotors once the robot passes (12, 24)", odom_pure_pursuit_wait_until_example},
            // {"Boomerang\n\nGo to (0, 24, 45) then come back to (0, 0, 0)", odom_boomerang_example},
            // {"Boomerang Pure Pursuit\n\nGo to (0, 24, 45) on the way to (24, 24) then come back to (0, 0, 0)", odom_boomerang_injected_pure_pursuit_example},
            // {"Measure Offsets\n\nThis will turn the robot a bunch of times and calculate your offsets for your tracking wheels.", odom_boomerang_injected_pure_pursuit_example},
            {"Red Positive", redPositive},
            {"Red Negative", redNegative},
            {"Blue Positive", bluePositive},
            {"Blue Negative", blueNegative},
            {"Drive Forward 2ft", drive_forward},
            {"Turn Right 90 Degrees", turn_right}  //
        }  //
    );

    // Initialize chassis and auton selector
    chassis.initialize();
    ez::as::initialize();
    master.rumble(chassis.drive_imu_calibrated() ? "." : "---");
}

void disabled() {
    // . . .
}

void competition_initialize() {
    // . . .
}

void autonomous() {
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();

    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);

    // drive_forward();
    // turn_right();
    redPositive();
    // redNegative();
    // bluePositive();
    // blueNegative();

    // ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
}

/**
 * Simplifies printing tracker values to the brain screen
 */
void screen_print_tracker(ez::tracking_wheel *tracker, const std::string name, int line) {
    std::string tracker_value = "", tracker_width = "";
    // Check if the tracker exists
    if (tracker != nullptr) {
        tracker_value = name + " tracker: " + util::to_string_with_precision(tracker->get());             // Make text for the tracker value
        tracker_width = "  width: " + util::to_string_with_precision(tracker->distance_to_center_get());  // Make text for the distance to center
    }
    ez::screen_print(tracker_value + tracker_width, line);  // Print final tracker text
}

/**
 * Ez screen task
 * Adding new pages here will let you view them during user control or autonomous
 * and will help you debug problems you're having
 */
void ez_screen_task() {
    while (true) {
        // Only run this when not connected to a competition switch
        if (!pros::competition::is_connected()) {
            // Blank page for odom debugging
            if (chassis.odom_enabled() && !chassis.pid_tuner_enabled()) {
                // If we're on the first blank page...
                if (ez::as::page_blank_is_on(0)) {
                    // Display X, Y, and Theta
                    ez::screen_print("x: " + util::to_string_with_precision(chassis.odom_x_get()) +
                                         "\ny: " + util::to_string_with_precision(chassis.odom_y_get()) +
                                         "\na: " + util::to_string_with_precision(chassis.odom_theta_get()),
                                     1);  // Don't override the top Page line

                    // Display all trackers that are being used
                    screen_print_tracker(chassis.odom_tracker_left, "l", 4);
                    screen_print_tracker(chassis.odom_tracker_right, "r", 5);
                    screen_print_tracker(chassis.odom_tracker_back, "b", 6);
                    screen_print_tracker(chassis.odom_tracker_front, "f", 7);
                }
            }
        }
        // Remove all blank pages when connected to a comp switch
        else {
            if (ez::as::page_blank_amount() > 0)
                ez::as::page_blank_remove_all();
        }

        pros::delay(ez::util::DELAY_TIME);
    }
}
pros::Task ezScreenTask(ez_screen_task);

/**
 * Gives you some extras to run in your opcontrol:
 * - run your autonomous routine in opcontrol by pressing DOWN and B
 *   - to prevent this from accidentally happening at a competition, this
 *     is only enabled when you're not connected to competition control.
 * - gives you a GUI to change your PID values live by pressing X
 */
void ez_template_extras() {
    // Only run this when not connected to a competition switch
    if (!pros::competition::is_connected()) {
        // PID Tuner
        // - after you find values that you're happy with, you'll have to set them in auton.cpp

        // Enable / Disable PID Tuner
        //  When enabled:
        //  * use A and Y to increment / decrement the constants
        //  * use the arrow keys to navigate the constants
        if (master.get_digital_new_press(DIGITAL_X))
            chassis.pid_tuner_toggle();

        // Trigger the selected autonomous routine
        if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
            pros::motor_brake_mode_e_t preference = chassis.drive_brake_get();
            autonomous();
            chassis.drive_brake_set(preference);
        }

        // Allow PID Tuner to iterate
        chassis.pid_tuner_iterate();
    }

    // Disable PID Tuner when connected to a comp switch
    else {
        if (chassis.pid_tuner_enabled())
            chassis.pid_tuner_disable();
    }
}

void intakeMotorControl() {
    pros::controller_digital_e_t intakeInButton = pros::E_CONTROLLER_DIGITAL_R2;
    pros::controller_digital_e_t intakeOutButton = pros::E_CONTROLLER_DIGITAL_R1;
    double intakeVelocity = 1.0;

    const int motorPower =
        static_cast<int>((master.get_digital(intakeInButton) -
                          master.get_digital(intakeOutButton)) *
                         127 * intakeVelocity);
    intakeMotors.move(motorPower);
}

void armMotorControl() {
    pros::controller_digital_e_t armInButton = pros::E_CONTROLLER_DIGITAL_L2;
    pros::controller_digital_e_t armOutButton = pros::E_CONTROLLER_DIGITAL_L1;
    double armVelocity = 1.0;

    const int motorPower = (master.get_digital(armInButton) -
                            master.get_digital(armOutButton)) *
                           127 * armVelocity;
    armMotor.move(motorPower);
}

void holderPistonControl() {
    pros::controller_digital_e_t holderPistonButton = pros::E_CONTROLLER_DIGITAL_Y;
    if (master.get_digital_new_press(holderPistonButton)) {
        holderPiston.toggle();
    }
}

void opcontrol() {
    chassis.drive_brake_set(MOTOR_BRAKE_COAST);

    while (true) {
        ez_template_extras();
        chassis.opcontrol_arcade_standard(ez::SPLIT);  // Standard split arcade
        intakeMotorControl();
        armMotorControl();
        holderPistonControl();

        pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
    }
}
