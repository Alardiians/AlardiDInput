#pragma once
#include <windows.h>
#include <stdint.h>

typedef enum { AX_LX=0, AX_LY, AX_LZ, AX_LRX, AX_LRY, AX_LRZ, AX_S0, AX_S1, AX_COUNT } AxisId;

typedef struct {
    LONG minv;
    LONG maxv;
    LONG center;
    int  valid;
} AxisCal;

typedef struct {
    AxisCal axis[AX_COUNT];
} DeviceCal;

// Calibration functions
float norm_axis(LONG v, const AxisCal *c);
float apply_deadzone_f(float x, float dz);
int8_t f_to_s8(float x);
int axisid_from_dwOfs(DWORD ofs);
void debug_print_calibration(const DeviceCal *cal);
