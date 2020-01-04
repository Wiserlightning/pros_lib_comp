#include "main.h"
#include "subsystem_headers\globals_and_defs.hpp"
#include "subsystem_headers\drive.hpp"

using namespace pros;

//HELPER FUNCS.
void set_drv_vol(int vol_lt, int vol_rt) {
    lt_ft.move(vol_lt);
    lt_bk.move(vol_lt);
    rt_ft.move(vol_rt);
    rt_bk.move(vol_rt);
}

void set_drv_aut(float dist_lt, float dist_rt, int vel_drv) {
    lt_ft.move_relative(dist_lt, vel_drv);
    lt_bk.move_relative(dist_lt, vel_drv);
    rt_ft.move_relative(dist_rt, vel_drv);
    rt_bk.move_relative(dist_rt, vel_drv);
}

void set_drv_brke(motor_brake_mode_e_t brke_drv) {
    lt_ft.set_brake_mode(brke_drv);
    lt_bk.set_brake_mode(brke_drv);
    rt_ft.set_brake_mode(brke_drv);
    rt_bk.set_brake_mode(brke_drv);
}

double get_drv_tic(int mode) {
    if (mode == 1) {
        return (lt_ft.get_position() + lt_bk.get_position()) / 2;
    } else if (mode == 2) {
        return (rt_ft.get_position() + rt_bk.get_position()) / 2;
    } else if (mode == 3) {
        return (lt_ft.get_position() + lt_bk.get_position() + rt_ft.get_position() + rt_bk.get_position()) / 2;
    }
}

//MAIN FUNCS.
void drive_op(void) {
    int read_ly = mstr_ctrl.get_analog(JOY_RY);
    int read_lx = mstr_ctrl.get_analog(JOY_RX);
    set_drv_brke(BRKE_CST);
    set_drv_vol(read_ly + read_lx, read_ly - read_lx);
}

void drive_aut_mov(float dist_mov, int vel_mov, bool async_mov) {
    float dist_to_tics = std::floor(900 * (dist_mov / DEF_WHL_CIR()));
    set_drv_brke(BRKE_HOLD);
    set_drv_aut(dist_to_tics, dist_to_tics, vel_mov);
    if (async_mov == false) {
        while (!((get_drv_tic(3) < (dist_mov + 5)) && (get_drv_tic(3) < (dist_mov - 5)))) {
            delay(1);
        }
    }
}

void drive_aut_piv(float deg_mov, int vel_mov, bool async_mov) {
    float deg_to_tics = std::floor(deg_mov * DEF_DEG_TIC_RATIO());
    set_drv_brke(BRKE_HOLD);
    set_drv_aut(deg_to_tics, -1 * deg_to_tics, vel_mov);
    if (async_mov == false) {
        while (!((get_drv_tic(3) < (deg_to_tics + 5)) && (get_drv_tic(3) < (deg_to_tics - 5)))) {
            delay(1);
        }
    }
}