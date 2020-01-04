#include "main.h"
#include "subsystem_headers\globals_and_defs.hpp"
#include "subsystem_headers\drive.hpp"
#include "subsystem_headers\intake.hpp"
#include "subsystem_headers\two_bar.hpp"
#include "subsystem_headers\tray.hpp"

using namespace pros;

void red_one(void) {
    lcd::print(0, "AUTON: RED_ONE");
}

void red_two(void) {
    lcd::print(0, "AUTON: RED_TWO");
}

void blue_one(void) {
    lcd::print(0, "AUTON: BLUE_ONE");
}

void blue_two(void) {
    lcd::print(0, "AUTON: BLUE_TWO");
}

void skills(void) {
    lcd::print(0, "AUTON: SKILLS");
}

void test_run(void) {
    lcd::print(0, "AUTON: TEST_RUN");
    lcd::print(1, "TESTING: DRIVE, STRAIGHT");
    drive_aut_mov(48.0, 100, false);
    drive_aut_mov(-48.0, 100, false);
    lcd::clear_line(1);
    lcd::print(1, "TESTING: DRIVE, PIV TURN");
    drive_aut_piv(180, 100, false);
    drive_aut_piv(-180, 100, false);
    lcd::clear_line(1);
    lcd::print(1, "TESTING: INTAKE");
    intake_aut(200, false);
    delay(2000);
    intake_aut(200, true);
    delay(2000);
    intake_aut(0, false);
    lcd::clear_line(1);
    lcd::print(1, "TESTING: TWO BAR");
    two_bar_aut(ARM_TOW1, 150, false);
    two_bar_aut(ARM_TOW2, 150, false);
    two_bar_aut(ARM_TOW1, 150, false);
    two_bar_aut(0, 150, false);
    lcd::clear_line(1);
    lcd::print(1, "TESTING: TRAY");
    tray_aut(TRAY_TOW1, 200, false);
    tray_aut(TRAY_TOW2, 200, false);
    tray_aut(TRAY_STACK, 200, false);
    tray_aut(TRAY_TOW2, 200, false);
    tray_aut(TRAY_TOW1, 200, false);
    tray_aut(0, 200, false);
    lcd::clear_line(1);
    lcd::print(1, "TESTING: COMPLETE");
    delay(2000);
    lcd::clear();
    lcd::shutdown();
}

void autonomous(void) {
    lcd::initialize();
    delay(1000);
    if (sel_aut == "RED_ONE") {
        red_one();
    } else if (sel_aut == "RED_TWO") {
        red_two();
    } else if (sel_aut == "BLUE_ONE") {
        blue_one();
    } else if (sel_aut == "BLUE_TWO") {
        blue_two();
    } else if (sel_aut == "SKILLS") {
        skills();
    } else if (sel_aut == "TEST_RUN") {
        test_run();
    } else {
        lcd::print(0, "ERROR: AUT. NOT FOUND");
    }
}