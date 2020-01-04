#include "main.h"
#include "subsystem_headers\drive.hpp"
#include "subsystem_headers\intake.hpp"
#include "subsystem_headers\two_bar.hpp"
#include "subsystem_headers\tray.hpp"

using namespace pros;

void opcontrol(void) {
	while (1) {
        drive_op();
        intake_op();
        two_bar_op();
        tray_op();
        delay(10);
    }
}