#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <dinput.h>
#include "calibration.h"

typedef struct DInputBackend
{
    CRITICAL_SECTION lock;
    int lock_init;

    HMODULE dinput8_mod;

    IDirectInput8A *di;
    IDirectInputDevice8A *keyboard;
    IDirectInputDevice8A *joystick;

    DeviceCal cal;  // axis calibration data
    int center_calibrated;

    HWND hwnd;
    DWORD owner_tid;
    int ready;
    HRESULT last_hr;  // Last DirectInput HRESULT for debugging
} DInputBackend;

// Returns 1 on success, 0 on fail (but fail is non-fatal; plugin can keep running)
int dinput_init(DInputBackend *b, HINSTANCE hInst, HWND hwnd);

// Safe to call multiple times.
void dinput_shutdown(DInputBackend *b);

// Select and acquire a specific device by GUID (NULL = clear device)
int dinput_select_device(DInputBackend *b, const GUID *guidInstance, HWND hwnd, DWORD coopFlags);

// Poll helpers. Return 1 if state valid, else 0.
int dinput_poll_keyboard(DInputBackend *b, uint8_t keys[256]);
int dinput_poll_joystick(DInputBackend *b, DIJOYSTATE2 *js);
