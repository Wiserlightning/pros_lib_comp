#include "main.h"
#include "subsystem_headers\globals_and_defs.hpp"

using namespace pros;

std::string sel_col;
std::string sel_num;
unsigned int cur_obj;

//HELPER FUNCS.
void auton_selector(void) {
    lcd::print(0, "Auton Selector v1.0");
    lcd::print(1, "[LEFT] and [RIGHT] to scroll.");
    lcd::print(2, "[CENTER] to select.");
    while (1) {
        lcd::print(3, "SELECTED COLOUR: %s", col.at(cur_obj));
        if (lcd::read_buttons() == LCD_BTN_LEFT) {
            if (cur_obj == 0) {
                lcd::print(4, "ERROR: UNDERFLOW ERR");
                delay(1000);
                lcd::clear_line(4);
            } else {
                cur_obj--;
                delay(500);
            }
        } else if (lcd::read_buttons() == LCD_BTN_RIGHT) {
            if (cur_obj == col_objs) {
                lcd::print(4, "ERROR: OVERFLOW ERR");
                delay(1000);
                lcd::clear_line(4);
            } else {
                cur_obj++;
                delay(500);
            }
        } else if (lcd::read_buttons() == LCD_BTN_CENTER) {
            sel_col = col.at(cur_obj);
            lcd::clear_line(3);
            lcd::print(3, "COLOUR SELECTED");
            delay(500);
            cur_obj = 0;
            lcd::clear_line(3);
            lcd::clear_line(4);
            break;
        }
        delay(10);
    }

    while (1) {
        if (sel_col == "SKILLS" || sel_col == "TEST_RUN") {
            break;
        }

        lcd::print(3, "SELECTED COLOUR: %s", num.at(cur_obj));
        if (lcd::read_buttons() == LCD_BTN_LEFT) {
            if (cur_obj == 0) {
                lcd::print(4, "ERROR: UNDERFLOW ERR");
                delay(1000);
                lcd::clear_line(4);
            } else {
                cur_obj--;
                delay(500);
            }
        } else if (lcd::read_buttons() == LCD_BTN_RIGHT) {
            if (cur_obj == num_objs) {
                lcd::print(4, "ERROR: OVERFLOW ERR");
                delay(1000);
                lcd::clear_line(4);
            } else {
                cur_obj++;
                delay(500);
            }
        } else if (lcd::read_buttons() == LCD_BTN_CENTER) {
            sel_num = num.at(cur_obj);
            lcd::clear_line(3);
            lcd::print(2, "POSITION SELECTED");
            delay(500);
            lcd::clear_line(3);
            lcd::clear_line(4);
            break;
        }
        delay(10);
    }
    if (sel_col == "SKILLS" || sel_col == "TEST_RUN") {
        sel_aut = sel_col;
    } else {
        sel_aut = sel_col + "_" + sel_num;
    }
    lcd::print(3, "FINAL AUTON: %s", sel_aut);
    delay(2000);
    lcd::clear();
}

void tune_robot(void) {
    tray.tare_position();
    tw_br.tare_position();
    lt_ft.tare_position();
    lt_bk.tare_position();
    rt_ft.tare_position();
    rt_bk.tare_position();

    lcd::initialize();
    delay(1000);
    lcd::shutdown();
    delay(1000);
    lcd::initialize();
    delay(1000);
}

//MAIN FUNCS.
void initialize(void) {
    tune_robot();
    auton_selector();
    lcd::shutdown();
    delay(1000);
}