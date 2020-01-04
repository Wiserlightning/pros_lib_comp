#include "main.h"

#ifndef DRIVE_H
#define DRIVE_H

extern void drive_op(void);
extern void drive_aut_mov(float dist_mov, int vel_mov, bool async_mov);
extern void drive_aut_piv(float deg_mov, int vel_mov, bool async_mov);

#endif