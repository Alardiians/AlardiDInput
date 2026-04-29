#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define DIRECTINPUT_VERSION 0x0800
#include <windows.h>
#include <stdio.h>
#include <dinput.h>
#include <string.h>
#include "dinput_backend.h"
#include "calibration.h"

typedef HRESULT (WINAPI *PFN_DirectInput8Create)(
    HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID *ppvOut, LPUNKNOWN punkOuter
);

typedef struct EnumCtx
{
    IDirectInput8A *di;
    IDirectInputDevice8A **out_dev;
    int found;
} EnumCtx;

typedef struct EnumAxisCtx
{
    IDirectInputDevice8A *dev;
    DeviceCal *cal;
} EnumAxisCtx;

static BOOL CALLBACK enum_joysticks_cb(const DIDEVICEINSTANCEA *inst, VOID *ref)
{
    EnumCtx *ctx = (EnumCtx *)ref;
    if (!ctx || !ctx->di || !ctx->out_dev) return DIENUM_CONTINUE;

    IDirectInputDevice8A *dev = NULL;
    HRESULT hr = IDirectInput8_CreateDevice(ctx->di, &inst->guidInstance, &dev, NULL);
    if (FAILED(hr) || !dev) return DIENUM_CONTINUE;

    *ctx->out_dev = dev;
    ctx->found = 1;
    return DIENUM_STOP;
}

static BOOL CALLBACK enum_axis_cb(const DIDEVICEOBJECTINSTANCEA *doi, VOID *ref)
{
    EnumAxisCtx *ctx = (EnumAxisCtx*)ref;
    if (!(doi->dwType & DIDFT_AXIS)) return DIENUM_CONTINUE;

    int ax = axisid_from_dwOfs(doi->dwOfs);
    if (ax < 0) return DIENUM_CONTINUE;

    // Common DInput gamepads report sticks centered near 32767.
    DIPROPRANGE pr;
    pr.diph.dwSize = sizeof(pr);
    pr.diph.dwHeaderSize = sizeof(pr.diph);
    pr.diph.dwHow = DIPH_BYOFFSET;
    pr.diph.dwObj = doi->dwOfs;
    pr.lMin = 0;
    pr.lMax = 65535;
    IDirectInputDevice8_SetProperty(ctx->dev, DIPROP_RANGE, &pr.diph);

    ctx->cal->axis[ax].minv = pr.lMin;
    ctx->cal->axis[ax].maxv = pr.lMax;
    ctx->cal->axis[ax].center = (pr.lMin + pr.lMax) / 2;
    ctx->cal->axis[ax].valid = 1;

    // Keep the driver's reported range when available.
    DIPROPRANGE got = pr;
    if (SUCCEEDED(IDirectInputDevice8_GetProperty(ctx->dev, DIPROP_RANGE, &got.diph))) {
        ctx->cal->axis[ax].minv = got.lMin;
        ctx->cal->axis[ax].maxv = got.lMax;
        ctx->cal->axis[ax].center = (got.lMin + got.lMax) / 2;
    }

    return DIENUM_CONTINUE;
}

static void safe_release(IUnknown *u)
{
    if (u) u->lpVtbl->Release(u);
}

static LONG axis_value_from_state(const DIJOYSTATE2 *js, AxisId id)
{
    switch (id) {
    case AX_LX:  return js->lX;
    case AX_LY:  return js->lY;
    case AX_LZ:  return js->lZ;
    case AX_LRX: return js->lRx;
    case AX_LRY: return js->lRy;
    case AX_LRZ: return js->lRz;
    case AX_S0:  return js->rglSlider[0];
    case AX_S1:  return js->rglSlider[1];
    default:     return 0;
    }
}

static void calibrate_centers_from_state(DInputBackend *b, const DIJOYSTATE2 *js)
{
    if (!b || !js || b->center_calibrated) return;

    for (int i = 0; i < AX_COUNT; i++) {
        if (!b->cal.axis[i].valid) {
            b->cal.axis[i].minv = 0;
            b->cal.axis[i].maxv = 65535;
            b->cal.axis[i].valid = 1;
        }
        b->cal.axis[i].center = axis_value_from_state(js, (AxisId)i);
    }
    b->center_calibrated = 1;
}

static int is_fatal_hr(HRESULT hr)
{
    if (hr == HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS)) return 1; // 0x8007000C
    if (hr == E_ACCESSDENIED) return 1;
    if (hr == HRESULT_FROM_WIN32(ERROR_ACCESS_DENIED)) return 1;
    return 0;
}

int dinput_init(DInputBackend *b, HINSTANCE hInst, HWND hwnd)
{
    if (!b) return 0;

    if (!b->lock_init)
    {
        InitializeCriticalSection(&b->lock);
        b->lock_init = 1;
    }

    EnterCriticalSection(&b->lock);

    if (b->ready)
    {
        LeaveCriticalSection(&b->lock);
        return 1;
    }

    b->hwnd = hwnd;

    b->dinput8_mod = LoadLibraryA("dinput8.dll");
    if (!b->dinput8_mod)
    {
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    PFN_DirectInput8Create pCreate =
        (PFN_DirectInput8Create)GetProcAddress(b->dinput8_mod, "DirectInput8Create");
    if (!pCreate)
    {
        FreeLibrary(b->dinput8_mod);
        b->dinput8_mod = NULL;
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    HRESULT hr = pCreate(hInst, DIRECTINPUT_VERSION, &IID_IDirectInput8A, (void **)&b->di, NULL);
    if (FAILED(hr) || !b->di)
    {
        FreeLibrary(b->dinput8_mod);
        b->dinput8_mod = NULL;
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    hr = IDirectInput8_CreateDevice(b->di, &GUID_SysKeyboard, &b->keyboard, NULL);
    if (SUCCEEDED(hr) && b->keyboard)
    {
        IDirectInputDevice8_SetDataFormat(b->keyboard, &c_dfDIKeyboard);
        IDirectInputDevice8_SetCooperativeLevel(b->keyboard, hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
        IDirectInputDevice8_Acquire(b->keyboard);
    }

    EnumCtx ctx;
    memset(&ctx, 0, sizeof(ctx));
    ctx.di = b->di;
    ctx.out_dev = &b->joystick;

    IDirectInput8_EnumDevices(b->di, DI8DEVCLASS_GAMECTRL, enum_joysticks_cb, &ctx, DIEDFL_ATTACHEDONLY);

    if (b->joystick)
    {
        IDirectInputDevice8_SetDataFormat(b->joystick, &c_dfDIJoystick2);

        HRESULT hr2 = IDirectInputDevice8_SetCooperativeLevel(
            b->joystick, hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);

        if (FAILED(hr2)) {
            safe_release((IUnknown*)b->joystick);
            b->joystick = NULL;
            b->last_hr = hr2;
        } else {
            memset(&b->cal, 0, sizeof(b->cal));
            EnumAxisCtx ctx = { b->joystick, &b->cal };
            IDirectInputDevice8_EnumObjects(b->joystick, enum_axis_cb, &ctx, DIDFT_AXIS);

            debug_print_calibration(&b->cal);

            HRESULT ahr = IDirectInputDevice8_Acquire(b->joystick);
            if (FAILED(ahr)) {
                safe_release((IUnknown*)b->joystick);
                b->joystick = NULL;
                b->last_hr = ahr;
            }
        }
    }

    b->ready = (b->di != NULL);
    b->hwnd = hwnd;
    b->owner_tid = GetCurrentThreadId();
    b->last_hr = S_OK;
    LeaveCriticalSection(&b->lock);
    return 1;
}

static void dinput_reset_internal(DInputBackend *b)
{
    if (b->keyboard) {
        IDirectInputDevice8_Unacquire(b->keyboard);
        safe_release((IUnknown*)b->keyboard);
        b->keyboard = NULL;
    }
    if (b->joystick) {
        IDirectInputDevice8_Unacquire(b->joystick);
        safe_release((IUnknown*)b->joystick);
        b->joystick = NULL;
    }
    if (b->di) {
        safe_release((IUnknown*)b->di);
        b->di = NULL;
    }
    if (b->dinput8_mod) {
        FreeLibrary(b->dinput8_mod);
        b->dinput8_mod = NULL;
    }
    b->ready = 0;
    b->last_hr = S_OK;
    b->hwnd = NULL;
    b->owner_tid = 0;
    b->center_calibrated = 0;
    ZeroMemory(&b->cal, sizeof(b->cal));
}

void dinput_shutdown(DInputBackend *b)
{
    if (!b || !b->lock_init) return;

    EnterCriticalSection(&b->lock);
    dinput_reset_internal(b);
    b->hwnd = NULL;
    b->last_hr = S_OK;
    LeaveCriticalSection(&b->lock);
}

static void dinput_release_device(IDirectInputDevice8A **pdev)
{
    if (pdev && *pdev) {
        (*pdev)->lpVtbl->Unacquire(*pdev);
        (*pdev)->lpVtbl->Release(*pdev);
        *pdev = NULL;
    }
}

int dinput_select_device(DInputBackend *b, const GUID *guidInstance, HWND hwnd, DWORD coopFlags)
{
    if (!b || !b->di) return 0;

    EnterCriticalSection(&b->lock);

    if (!b->di) {
        b->last_hr = DIERR_NOTINITIALIZED;
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    dinput_release_device(&b->joystick);
    b->center_calibrated = 0;

    if (!guidInstance) {
        LeaveCriticalSection(&b->lock);
        return 1;
    }

    IDirectInputDevice8A *dev = NULL;
    HRESULT hr = b->di->lpVtbl->CreateDevice(b->di, guidInstance, &dev, NULL);
    if (FAILED(hr) || !dev) {
        b->last_hr = hr;
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    hr = dev->lpVtbl->SetDataFormat(dev, &c_dfDIJoystick2);
    if (FAILED(hr)) {
        b->last_hr = hr;
        dev->lpVtbl->Release(dev);
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    hr = dev->lpVtbl->SetCooperativeLevel(dev, hwnd, coopFlags);
    if (FAILED(hr)) {
        b->last_hr = hr;
        dev->lpVtbl->Release(dev);
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    memset(&b->cal, 0, sizeof(b->cal));
    EnumAxisCtx axctx = { dev, &b->cal };
    dev->lpVtbl->EnumObjects(dev, enum_axis_cb, &axctx, DIDFT_AXIS);

    hr = dev->lpVtbl->Acquire(dev);
    if (FAILED(hr)) {
        b->last_hr = hr;
        dev->lpVtbl->Release(dev);
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    b->joystick = dev;
    b->hwnd = hwnd;
    b->owner_tid = GetCurrentThreadId();
    b->center_calibrated = 0;
    b->last_hr = S_OK;

    LeaveCriticalSection(&b->lock);
    return 1;
}

static int is_fatal_di_hr(HRESULT hr)
{
    if (hr == DIERR_NOTINITIALIZED) return 1;
    if (hr == DIERR_DEVICENOTREG) return 1;
    if (hr == DIERR_UNPLUGGED) return 1;
    return 0;
}

static int reacquire_if_needed(IDirectInputDevice8A *dev, HRESULT hr)
{
    if (!dev) return 0;

    if (hr == DIERR_INPUTLOST || hr == DIERR_NOTACQUIRED ||
        hr == DIERR_OTHERAPPHASPRIO || hr == E_ACCESSDENIED ||
        hr == HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS)) {
        HRESULT a = dev->lpVtbl->Acquire(dev);
        while (a == DIERR_INPUTLOST) a = dev->lpVtbl->Acquire(dev);
        return SUCCEEDED(a) ? 1 : 0;
    }

    return 0;
}

int dinput_poll_keyboard(DInputBackend *b, uint8_t keys[256])
{
    if (!b || !keys || !b->lock_init) return 0;

    EnterCriticalSection(&b->lock);
    if (!b->di || !b->keyboard) {
        b->last_hr = DIERR_NOTACQUIRED;
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    HRESULT hr = IDirectInputDevice8_GetDeviceState(b->keyboard, 256, keys);
    if (FAILED(hr))
    {
        b->last_hr = hr;
        int ok = reacquire_if_needed(b->keyboard, hr);
        if (!ok)
        {
            memset(keys, 0, 256);
            LeaveCriticalSection(&b->lock);
            return 0;
        }
        hr = IDirectInputDevice8_GetDeviceState(b->keyboard, 256, keys);
        if (FAILED(hr)) b->last_hr = hr;
    } else {
        b->last_hr = S_OK;
    }

    LeaveCriticalSection(&b->lock);
    return SUCCEEDED(hr) ? 1 : 0;
}

int dinput_poll_joystick(DInputBackend *b, DIJOYSTATE2 *js)
{
    if (!b || !js || !b->lock_init) return 0;
    ZeroMemory(js, sizeof(*js));

    EnterCriticalSection(&b->lock);

    if (!b->di || !b->joystick) {
        b->last_hr = DIERR_NOTACQUIRED;
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    HRESULT hr = b->joystick->lpVtbl->Poll(b->joystick);
    if (FAILED(hr)) {
        if (hr == HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS) || hr == E_ACCESSDENIED) {
            b->last_hr = hr;
            IDirectInputDevice8_Unacquire(b->joystick);
            safe_release((IUnknown*)b->joystick);
            b->joystick = NULL;
            b->ready = 0;
            LeaveCriticalSection(&b->lock);
            return 0;
        }
        if (is_fatal_di_hr(hr)) {
            b->last_hr = hr;
            dinput_release_device(&b->joystick);
            b->ready = (b->di != NULL);
            LeaveCriticalSection(&b->lock);
            return 0;
        }
        if (!reacquire_if_needed(b->joystick, hr)) {
            b->last_hr = hr;
            LeaveCriticalSection(&b->lock);
            return 0;
        }

        hr = b->joystick->lpVtbl->Poll(b->joystick);
        if (FAILED(hr)) {
            if (hr == HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS) || hr == E_ACCESSDENIED) {
                b->last_hr = hr;
                IDirectInputDevice8_Unacquire(b->joystick);
                safe_release((IUnknown*)b->joystick);
                b->joystick = NULL;
                b->ready = 0;
                LeaveCriticalSection(&b->lock);
                return 0;
            }
            if (is_fatal_di_hr(hr)) {
                b->last_hr = hr;
                dinput_release_device(&b->joystick);
                b->ready = (b->di != NULL);
                LeaveCriticalSection(&b->lock);
                return 0;
            }
            b->last_hr = hr;
            LeaveCriticalSection(&b->lock);
            return 0;
        }
    }

    hr = b->joystick->lpVtbl->GetDeviceState(b->joystick, sizeof(*js), js);
    if (FAILED(hr)) {
        if (hr == HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS) || hr == E_ACCESSDENIED) {
            b->last_hr = hr;
            IDirectInputDevice8_Unacquire(b->joystick);
            safe_release((IUnknown*)b->joystick);
            b->joystick = NULL;
            b->ready = 0;
            ZeroMemory(js, sizeof(*js));
            LeaveCriticalSection(&b->lock);
            return 0;
        }
        if (is_fatal_di_hr(hr)) {
            b->last_hr = hr;
            dinput_release_device(&b->joystick);
            b->ready = (b->di != NULL);
            ZeroMemory(js, sizeof(*js));
            LeaveCriticalSection(&b->lock);
            return 0;
        }
        if (reacquire_if_needed(b->joystick, hr)) {
            b->joystick->lpVtbl->Poll(b->joystick);
            hr = b->joystick->lpVtbl->GetDeviceState(b->joystick, sizeof(*js), js);
        }
    }

    if (FAILED(hr)) {
        if (hr == HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS) || hr == E_ACCESSDENIED) {
            b->last_hr = hr;
            IDirectInputDevice8_Unacquire(b->joystick);
            safe_release((IUnknown*)b->joystick);
            b->joystick = NULL;
            b->ready = 0;
            ZeroMemory(js, sizeof(*js));
            LeaveCriticalSection(&b->lock);
            return 0;
        }
        b->last_hr = hr;
        ZeroMemory(js, sizeof(*js));
        LeaveCriticalSection(&b->lock);
        return 0;
    }

    calibrate_centers_from_state(b, js);
    b->last_hr = S_OK;
    LeaveCriticalSection(&b->lock);
    return 1;
}
