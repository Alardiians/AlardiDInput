#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define DIRECTINPUT_VERSION 0x0800
#include <windows.h>
#include <stdio.h>
#include <dinput.h>
#include <math.h>
#include "calibration.h"

int axisid_from_dwOfs(DWORD ofs) {
    if (ofs == DIJOFS_X) return AX_LX;
    if (ofs == DIJOFS_Y) return AX_LY;
    if (ofs == DIJOFS_Z) return AX_LZ;
    if (ofs == DIJOFS_RX) return AX_LRX;
    if (ofs == DIJOFS_RY) return AX_LRY;
    if (ofs == DIJOFS_RZ) return AX_LRZ;
    if (ofs == DIJOFS_SLIDER(0)) return AX_S0;
    if (ofs == DIJOFS_SLIDER(1)) return AX_S1;
    return -1;
}

float norm_axis(LONG v, const AxisCal *c)
{
    if (!c || !c->valid) {
        // fallback assumption
        return (float)v / 32767.0f;
    }
    float denom = (v >= c->center)
        ? (float)(c->maxv - c->center)
        : (float)(c->center - c->minv);

    if (denom < 1.0f) return 0.0f;
    return (float)(v - c->center) / denom;   // approx [-1..1]
}

float apply_deadzone_f(float x, float dz)
{
    float ax = (x < 0.f) ? -x : x;
    if (ax <= dz) return 0.f;
    // rescale so dz..1 maps to 0..1
    float s = (ax - dz) / (1.f - dz);
    return (x < 0.f) ? -s : s;
}

int8_t f_to_s8(float x)
{
    if (x < -1.f) x = -1.f;
    if (x >  1.f) x =  1.f;
    int v = (int)(x * 127.f);
    if (v < -128) v = -128;
    if (v > 127)  v = 127;
    return (int8_t)v;
}

// For debugging - print calibration info
void debug_print_calibration(const DeviceCal *cal)
{
    const char *axis_names[AX_COUNT] = {"LX", "LY", "LZ", "LRX", "LRY", "LRZ", "S0", "S1"};
    char buf[256];

    for (int i = 0; i < AX_COUNT; i++) {
        if (cal->axis[i].valid) {
            sprintf(buf, "Axis %s: min=%ld max=%ld center=%ld\n",
                axis_names[i],
                cal->axis[i].minv,
                cal->axis[i].maxv,
                cal->axis[i].center);
            OutputDebugStringA(buf);
        }
    }
}
