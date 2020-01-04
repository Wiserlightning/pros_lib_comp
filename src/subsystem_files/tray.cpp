#include "main.h"
#include "subsystem_headers\globals_and_defs.hpp"
#include "subsystem_headers\tray.hpp"

int mode_tray = 0;

using namespace pros;

//HELPER FUNCS.
void set_tray_vel(int vel_tray) {
    tray.move_velocity(vel_tray);
}

void set_tray_aut(float dist_tray, int vel_tray) {
    tray.move_absolute(dist_tray, vel_tray);
}

void set_tray_brke(motor_brake_mode_e_t brke_tray) {
    tray.set_brake_mode(brke_tray);
}

//MAIN FUNCS.
void tray_op(void) {
    int read_tray = std::ceil(200 * (mstr_ctrl.get_analog(JOY_LY)/127));
    set_tray_brke(BRKE_HOLD);
    set_tray_vel(read_tray);
}

void tray_aut(float dist_tray, int vel_tray, bool async_tray) {
    set_tray_brke(BRKE_HOLD);
    set_tray_aut(dist_tray, vel_tray);
    if (async_tray == false) {
        while (!(tray.get_position() < (dist_tray + 5) && (tray.get_position() > (dist_tray - 5)))) {
            delay(1);
        }
    }
}