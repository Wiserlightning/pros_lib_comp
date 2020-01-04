#include "main.h"
#include "subsystem_headers\globals_and_defs.hpp"

using namespace pros;

const std::vector<std::string> col {
    "RED",
    "BLUE",
    "SKILLS",
    "TEST_RUN"
};
const std::vector<std::string> num {
    "ONE",
    "TWO"
};
const int col_objs = col.size();
const int num_objs = num.size();
std::string sel_aut;


Controller mstr_ctrl (E_CONTROLLER_MASTER);

Motor lt_ft (2, GRN_GEAR, false, ENC_TIC);
Motor lt_bk (1, GRN_GEAR, false, ENC_TIC);
Motor rt_ft (19, GRN_GEAR, true, ENC_TIC);
Motor rt_bk (9, GRN_GEAR, true, ENC_TIC);

Motor intk_lt (11, GRN_GEAR, false, ENC_TIC);
Motor intk_rt (20, GRN_GEAR, true, ENC_TIC);

Motor tray (10, RED_GEAR, false, ENC_TIC);
Motor tw_br (13, GRN_GEAR, false, ENC_TIC);