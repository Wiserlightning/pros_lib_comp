#include "main.h"

#ifndef GLOBALS_DEFS_H
#define GLOBALS_DEFS_H

//Include libraries
#include <vector>

//Autonomous related
#define TRAY_TOW1 0.0
#define TRAY_TOW2 0.0
#define TRAY_STACK 0.0
#define ARM_TOW1 0.0
#define ARM_TOW2 0.0
extern const std::vector<std::string> col;
extern const std::vector<std::string> num;
extern const int col_objs;
extern const int num_objs;
extern std::string sel_aut;

//Misc.
#define TRAY_UP 2 * 900
constexpr float DEF_PI(void) {return std::atan(1) * 4;};
constexpr float DEF_WHL_CIR(void) {return 8 * DEF_PI();};
constexpr float DEF_DEG_TIC_RATIO() {return 0 / 360;};

//Hardware Definitions
#define GRN_GEAR pros::motor_gearset_e::E_MOTOR_GEARSET_18
#define RED_GEAR pros::motor_gearset_e::E_MOTOR_GEARSET_36

#define ENC_TIC pros::motor_encoder_units_e::E_MOTOR_ENCODER_COUNTS

#define BRKE_CST pros::motor_brake_mode_e_t::E_MOTOR_BRAKE_COAST
#define BRKE_BRKE pros::motor_brake_mode_e_t::E_MOTOR_BRAKE_BRAKE
#define BRKE_HOLD pros::motor_brake_mode_e_t::E_MOTOR_BRAKE_HOLD

#define JOY_LX pros::controller_analog_e_t::E_CONTROLLER_ANALOG_LEFT_X
#define JOY_LY pros::controller_analog_e_t::E_CONTROLLER_ANALOG_LEFT_Y
#define JOY_RX pros::controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_X
#define JOY_RY pros::controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_Y
#define BUT_L1 pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L1
#define BUT_L2 pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L2
#define BUT_R1 pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R1
#define BUT_R2 pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R2
#define BUT_UP pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_UP
#define BUT_DWN pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_DOWN
#define BUT_LT pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_LEFT
#define BUT_RT pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_RIGHT
#define BUT_A pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_A
#define BUT_B pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_B
#define BUT_X pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_X
#define BUT_Y pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_Y

//Hardware Prototypes
extern pros::Controller mstr_ctrl;

extern pros::Motor lt_ft;
extern pros::Motor lt_bk;
extern pros::Motor rt_ft;
extern pros::Motor rt_bk;

extern pros::Motor intk_lt;
extern pros::Motor intk_rt;

extern pros::Motor tray;
extern pros::Motor tw_br;

#endif