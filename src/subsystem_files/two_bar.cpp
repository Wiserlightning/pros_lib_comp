#include "main.h"
#include "subsystem_headers\globals_and_defs.hpp"
#include "subsystem_headers\two_bar.hpp"

using namespace pros;

//HELPER FUNCS.
void set_twbr_vel(int vel_twbr) {
    tw_br.move_velocity(vel_twbr);
}

void set_twbr_aut(float dist_twbr, int vel_twbr) {
    tw_br.move_absolute(dist_twbr, vel_twbr);
}

void set_twbr_brke(motor_brake_mode_e_t brke_twbr) {
    tw_br.set_brake_mode(brke_twbr);
}

//MAIN FUNCS.
void two_bar_op(void) {
    int read_twbr = 150 * (mstr_ctrl.get_digital(BUT_L1) - mstr_ctrl.get_digital(BUT_L2));
    set_twbr_brke(BRKE_HOLD);
    set_twbr_vel(read_twbr);
}

void two_bar_aut(float dist_twbr, int vel_twbr, bool async_twbr) {
    set_twbr_brke(BRKE_HOLD);
    set_twbr_aut(dist_twbr, vel_twbr);
    if (async_twbr == false) {
        while (!(tw_br.get_position() < (dist_twbr + 5) && (tw_br.get_position() > (dist_twbr - 5)))) {
            delay(1);
        }
    }
}