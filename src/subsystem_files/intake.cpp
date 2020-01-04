#include "main.h"
#include "subsystem_headers\globals_and_defs.hpp"
#include "subsystem_headers\intake.hpp"

using namespace pros;

//HELPER FUNCS.
void set_intk_vel(int vel_intk) {
    intk_lt.move_velocity(vel_intk);
    intk_rt.move_velocity(vel_intk);
}

void set_intk_brke(motor_brake_mode_e_t brke_intk) {
    intk_lt.set_brake_mode(brke_intk);
    intk_rt.set_brake_mode(brke_intk);
}

//MAIN FUNCS.
void intake_op(void) {
    int read_intk = 200 * (mstr_ctrl.get_digital(BUT_R1) - mstr_ctrl.get_digital(BUT_R2));
    set_intk_brke(BRKE_HOLD);
    set_intk_vel(read_intk);
}

void intake_aut(int vel_intk, bool rev_intk) {
    if (rev_intk == true) {
        set_intk_brke(BRKE_HOLD);
        set_intk_vel(-1 * vel_intk);
    } else {
        set_intk_brke(BRKE_HOLD);
        set_intk_vel(vel_intk);
    }
}