#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define DIRECTINPUT_VERSION 0x0800
#include <windows.h>
#include <stdint.h>
#include <dinput.h>
#include "bindings.h"

static int axis_value_by_id(const DIJOYSTATE2 *js, AxisId id) {
  switch(id){
    case AX_LX:  return js->lX;
    case AX_LY:  return js->lY;
    case AX_LZ:  return js->lZ;
    case AX_LRX: return js->lRx;
    case AX_LRY: return js->lRy;
    case AX_LRZ: return js->lRz;
    case AX_S0:  return js->rglSlider[0];
    case AX_S1:  return js->rglSlider[1];
    default: return 0;
  }
}

static int pov_to_dir(DWORD pov)
{
    if (pov == 0xFFFFFFFF || pov == 0xFFFF) return -1;
    if (pov > 35999) return -1;

    if (pov >= 31500 || pov <= 4500) return 0;      // Up
    if (pov > 4500  && pov < 13500) return 1;       // Right
    if (pov >= 13500 && pov <= 22500) return 2;     // Down
    if (pov > 22500 && pov < 31500) return 3;       // Left
    return -1;
}

int capture_next_input(const DIJOYSTATE2 *prev,
                       const DIJOYSTATE2 *cur,
                       Binding *outBind,
                       int wantAnalogAxis)
{
    for (int i = 0; i < 128; i++) {
        if ((prev->rgbButtons[i] & 0x80) == 0 && (cur->rgbButtons[i] & 0x80) != 0) {
            outBind->type = BIND_BTN;
            outBind->index = (uint8_t)i;
            outBind->threshold = 0;
            outBind->pov_dir = 0;
            return 1;
        }
    }

    int prevDir = pov_to_dir(prev->rgdwPOV[0]);
    int curDir  = pov_to_dir(cur->rgdwPOV[0]);
    if (prevDir == -1 && curDir != -1) {
        outBind->type = BIND_POV;
        outBind->index = 0;
        outBind->pov_dir = (uint8_t)curDir;
        outBind->threshold = 0;
        return 1;
    }

    const int axisThreshold = 12000;
    int bestAxis = -1;
    int bestMag  = 0;
    int bestDelta = 0;

    for (int a = 0; a <= AX_S1; a++) {
        int v0 = axis_value_by_id(prev, (AxisId)a);
        int v1 = axis_value_by_id(cur,  (AxisId)a);
        int d  = v1 - v0;
        int mag = (d < 0) ? -d : d;

        if (mag > axisThreshold && mag > bestMag) {
            bestMag   = mag;
            bestAxis  = a;
            bestDelta = d;
        }
    }

    if (bestAxis != -1) {
        outBind->index = (uint8_t)bestAxis;
        outBind->threshold = axisThreshold;
        outBind->pov_dir = 0;

        if (wantAnalogAxis) {
            outBind->type = BIND_AXIS;
        } else {
            outBind->type = (bestDelta >= 0) ? BIND_AXIS_POS : BIND_AXIS_NEG;
        }
        return 1;
    }

    return 0;
}

