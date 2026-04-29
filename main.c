#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define DIRECTINPUT_VERSION 0x0800

// Common Controls 6.0 symbols used by the dialog.
#define _WIN32_IE 0x0600
#define _WIN32_WINNT 0x0600

#include <windows.h>
#include <commctrl.h>
#include <objbase.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <dinput.h>

#include "plugin_zilmar.h"
#include "dinput_backend.h"
#include "bindings.h"
#include "calibration.h"
#include "eval.h"
#include "bind_capture.h"
#include <objbase.h>
#pragma comment(lib, "Ole32.lib")
#include "resource.h"

// Zilmar controller pak types.
#ifndef PLUGIN_NONE
#define PLUGIN_NONE 1
#endif
#ifndef PLUGIN_MEMPAK
#define PLUGIN_MEMPAK 2
#endif
#ifndef PLUGIN_RUMBLE_PAK
#define PLUGIN_RUMBLE_PAK 3
#endif

static CONTROL_INFO  g_ci;
static int           g_ci_valid = 0;
static CONTROL       g_controls[MAX_CONTROLLERS];

static DInputBackend g_di_cfg;
static DInputBackend g_di_run;
static HINSTANCE     g_hInst = NULL;
static N64Map        g_n64maps[MAX_CONTROLLERS];
static char          g_iniPath[MAX_PATH] = "";

static void init_default_n64map(N64Map *map);
static int  port_should_be_present(int port);
static void load_config(void);
static void save_config(void);

static void copy_controls_to_host(void)
{
    if (!g_ci.Controls) return;
    for (int i = 0; i < MAX_CONTROLLERS; i++) {
        g_ci.Controls[i] = g_controls[i];
    }
}

static void InitiateControllers_impl(CONTROL_INFO *ControlInfo)
{
    memset(&g_ci, 0, sizeof(g_ci));
    memset(g_controls, 0, sizeof(g_controls));
    g_ci_valid = 0;

    if (ControlInfo) {
        g_ci = *ControlInfo;
    }
    if (!g_ci.hinst) {
        g_ci.hinst = g_hInst;
    }

    for (int i = 0; i < MAX_CONTROLLERS; i++) {
        init_default_n64map(&g_n64maps[i]);
    }
    load_config();

    for (int i = 0; i < MAX_CONTROLLERS; i++) {
        int present = port_should_be_present(i);
        g_controls[i].Present = present;
        g_controls[i].RawData = 0;
        g_controls[i].Plugin  = PLUGIN_NONE;
    }
    copy_controls_to_host();

    g_ci_valid = 1;
}

typedef struct {
    int port;
    int capturing;
    int capture_row;
    DIJOYSTATE2 prev_js;
    int prev_valid;
    int base_ticks;
    DIJOYSTATE2 base_js;
    int preview_x;
    int preview_y;
    int preview_valid;
} DlgState;

static DlgState g_ds;

#define MAX_DEVICES 32
static DeviceInfo g_devices[MAX_DEVICES];
static int g_device_count = 0;

// forward
static INT_PTR CALLBACK ConfigDlgProc(HWND dlg, UINT msg, WPARAM wParam, LPARAM lParam);
static void enumerate_devices(void);
static void start_capture(HWND dlg, int row);

static void init_default_n64map(N64Map *map) {
    memset(map, 0, sizeof(*map));
    map->deadzone = 8000;
    map->invertY = 0;
}

static void ensure_ini_path(void)
{
    if (!g_iniPath[0] && g_hInst) {
        GetModuleFileNameA(g_hInst, g_iniPath, sizeof(g_iniPath));
        char *ext = strrchr(g_iniPath, '.');
        if (ext) strcpy_s(ext, sizeof(g_iniPath) - (size_t)(ext - g_iniPath), ".ini");
    }
}

static int guid_from_stringA(const char* s, GUID* out)
{
    if (!s || !s[0] || !out) return 0;
    wchar_t ws[80];
    MultiByteToWideChar(CP_ACP, 0, s, -1, ws, 80);
    return SUCCEEDED(CLSIDFromString(ws, out)) ? 1 : 0;
}

static int guid_to_stringA(const GUID *g, char *out, size_t outsz)
{
    if (!g || !out || outsz < 40) return 0;

    wchar_t wbuf[64];
    if (StringFromGUID2(g, wbuf, 64) <= 0) return 0;

    return WideCharToMultiByte(CP_ACP, 0, wbuf, -1, out, (int)outsz, NULL, NULL) > 0;
}

static int port_should_be_present(int port)
{
    return (g_n64maps[port].deviceGUID[0] != '\0');
}

static void update_present_flags(void)
{
    for (int i = 0; i < MAX_CONTROLLERS; i++) {
        g_controls[i].Present = port_should_be_present(i) ? 1 : 0;
        g_controls[i].RawData = 0;
        g_controls[i].Plugin = PLUGIN_NONE;
    }
    copy_controls_to_host();
}

static int guid_from_string(const char *s, GUID *out)
{
    if (!s || !out || s[0] != '{') return 0;

    unsigned int d4[8];
    unsigned long d1;
    unsigned int d2, d3;

    int n = sscanf(s,
        "{%8lx-%4x-%4x-%2x%2x-%2x%2x%2x%2x%2x%2x}",
        &d1, &d2, &d3,
        &d4[0], &d4[1], &d4[2], &d4[3], &d4[4], &d4[5], &d4[6], &d4[7]);

    if (n != 11) return 0;

    out->Data1 = (DWORD)d1;
    out->Data2 = (WORD)d2;
    out->Data3 = (WORD)d3;
    for (int i = 0; i < 8; i++) out->Data4[i] = (BYTE)d4[i];
    return 1;
}

static void ensure_runtime_device_for_port(int port, HWND hwnd)
{
    if (port < 0 || port >= MAX_CONTROLLERS) return;
    if (!hwnd) return;

    if (g_n64maps[port].deviceGUID[0] == '\0')
        return;

    GUID g;
    if (!guid_from_stringA(g_n64maps[port].deviceGUID, &g))
        return;

    dinput_select_device(&g_di_run, &g, hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
}

static int select_saved_device_for_port(HWND hwnd, int port)
{
    if (!hwnd) return 0;
    if (!g_n64maps[port].deviceGUID[0]) return 1;

    GUID g;
    if (!guid_from_stringA(g_n64maps[port].deviceGUID, &g)) return 0;

    return dinput_select_device(&g_di_run, &g, hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) ? 1 : 0;
}

static void ensure_runtime_dinput(HWND hwnd, int port)
{
    if (!hwnd) return;
    dinput_shutdown(&g_di_run);
    HINSTANCE hApp = g_hInst ? g_hInst : GetModuleHandleA(NULL);
    if (!dinput_init(&g_di_run, hApp, hwnd)) return;
    select_saved_device_for_port(hwnd, port);
}

static void load_config(void)
{
    ensure_ini_path();
    for (int i = 0; i < MAX_CONTROLLERS; i++) {
        load_n64map_from_ini(&g_n64maps[i], g_iniPath, i + 1);
    }
}

static void save_config(void)
{
    ensure_ini_path();
    if (!g_iniPath[0]) return;

    for (int i = 0; i < MAX_CONTROLLERS; i++) {
        save_n64map_to_ini(&g_n64maps[i], g_iniPath, i + 1);
    }
}

static int8_t clamp_s8(int v)
{
    if (v < -128) return -128;
    if (v > 127) return 127;
    return (int8_t)v;
}

static void trim_inplace(char* s)
{
    if (!s) return;
    char* p = s;
    while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') p++;
    if (p != s) memmove(s, p, strlen(p) + 1);

    size_t n = strlen(s);
    while (n && (s[n-1] == ' ' || s[n-1] == '\t' || s[n-1] == '\r' || s[n-1] == '\n'))
        s[--n] = 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    (void)lpvReserved;
    if (fdwReason == DLL_PROCESS_ATTACH) {
        g_hInst = hinstDLL;
    } else if (fdwReason == DLL_PROCESS_DETACH) {
        dinput_shutdown(&g_di_cfg);
        dinput_shutdown(&g_di_run);
    }
    return TRUE;
}

EXPORT void CALL GetDllInfo(PLUGIN_INFO *PluginInfo)
{
    if (!PluginInfo) return;
    memset(PluginInfo, 0, sizeof(*PluginInfo));
    PluginInfo->Version = 0x0102;
    PluginInfo->Type = PLUGIN_TYPE_CONTROLLER;
    lstrcpynA(PluginInfo->Name, "AlardiDInput", sizeof(PluginInfo->Name));
    PluginInfo->NormalMemory = 0;
    PluginInfo->MemoryBswaped = 1;
}

EXPORT void CALL InitiateControllers(CONTROL_INFO *ControlInfo)
{
    InitiateControllers_impl(ControlInfo);
}

EXPORT void CALL CloseDLL(void)
{
    dinput_shutdown(&g_di_run);
    dinput_shutdown(&g_di_cfg);
    g_ci_valid = 0;
    memset(&g_ci, 0, sizeof(g_ci));
    memset(g_controls, 0, sizeof(g_controls));
}

EXPORT void CALL RomOpen(void)
{
    dinput_shutdown(&g_di_run);
    if (g_ci.hMainWindow && g_hInst) {
        dinput_init(&g_di_run, g_hInst, g_ci.hMainWindow);
        for (int i = 0; i < MAX_CONTROLLERS; i++) {
            if (port_should_be_present(i)) {
                ensure_runtime_device_for_port(i, g_ci.hMainWindow);
                break;
            }
        }
    }
}

EXPORT void CALL RomClosed(void)
{
    dinput_shutdown(&g_di_run);
}

EXPORT void CALL GetKeys(int Control, BUTTONS *Keys)
{
    if (!Keys) return;
    Keys->Value = 0;
    Keys->X_AXIS = 0;
    Keys->Y_AXIS = 0;

    if (Control < 0 || Control >= MAX_CONTROLLERS) return;
    if (!g_controls[Control].Present) return;

    if (!g_di_run.ready && g_ci.hMainWindow) {
        ensure_runtime_dinput(g_ci.hMainWindow, Control);
    }

    DIJOYSTATE2 js;
    ZeroMemory(&js, sizeof(js));

    int haveJoystick = dinput_poll_joystick(&g_di_run, &js);
    if (!haveJoystick && g_di_run.last_hr == HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS)) {
        ensure_runtime_dinput(g_ci.hMainWindow, Control);
        haveJoystick = dinput_poll_joystick(&g_di_run, &js);
    }

    uint8_t kb[256];
    ZeroMemory(kb, sizeof(kb));
    int haveKeyboard = dinput_poll_keyboard(&g_di_run, kb);

    if (!haveJoystick && !haveKeyboard) {
        static DWORD s_last = 0;
        DWORD now = GetTickCount();
        if (now - s_last > 1000) {
            char msg[128];
            sprintf_s(msg, sizeof(msg), "AlardiDInput: poll failed hr=0x%08lX\n", (unsigned long)g_di_run.last_hr);
            OutputDebugStringA(msg);
            s_last = now;
        }
        return;
    }

    eval_port_to_buttons(Control, &js, &g_di_run.cal, Keys, haveKeyboard ? kb : NULL);

    Keys->X_AXIS = clamp_s8(Keys->X_AXIS);
    Keys->Y_AXIS = clamp_s8(Keys->Y_AXIS);
}

#define N64CMD_STATUS 0x00
#define N64CMD_READ   0x01
#define N64CMD_RESET  0xFF

static BYTE status_byte3_for_port(int port)
{
    (void)port;
    return 0x02;
}

static int port_present_now(int port)
{
    if (port < 0 || port >= MAX_CONTROLLERS) return 0;
    return g_controls[port].Present ? 1 : 0;
}

EXPORT void CALL ControllerCommand(int Control, BYTE *Command)
{
    if (Control < 0) return;
    if (!Command) return;

    if (!port_present_now(Control))
    {
        Command[1] |= 0x80;
        return;
    }

    BYTE tx = Command[0];
    BYTE rx = (BYTE)(Command[1] & 0x3F);
    BYTE cmd = Command[2];

    (void)tx;

    if (cmd == N64CMD_STATUS || cmd == N64CMD_RESET)
    {
        if (rx >= 3)
        {
            Command[3] = 0x05;
            Command[4] = 0x00;
            Command[5] = status_byte3_for_port(Control);
        }
        return;
    }

    if (cmd == N64CMD_READ)
    {
        if (rx >= 4)
        {
            BUTTONS k;  memset(&k, 0, sizeof(k));
            GetKeys(Control, &k);

            unsigned short btn = k.Value;
            Command[3] = (BYTE)((btn >> 8) & 0xFF);
            Command[4] = (BYTE)(btn & 0xFF);
            Command[5] = (BYTE)k.X_AXIS;
            Command[6] = (BYTE)k.Y_AXIS;
        }
        return;
    }

    Command[1] |= 0x80;
}

EXPORT void CALL ReadController(int Control, BYTE *Command)
{
    ControllerCommand(Control, Command);
}

static BOOL CALLBACK enum_dev_cb(const DIDEVICEINSTANCEA *inst, VOID *ref)
{
    (void)ref;
    if (g_device_count >= MAX_DEVICES) return DIENUM_STOP;

    g_devices[g_device_count].guid = inst->guidInstance;
    strncpy_s(g_devices[g_device_count].name, sizeof(g_devices[g_device_count].name),
              inst->tszInstanceName, _TRUNCATE);

    guid_to_stringA(&g_devices[g_device_count].guid,
                    g_devices[g_device_count].guid_str,
                    sizeof(g_devices[g_device_count].guid_str));

    g_device_count++;
    return DIENUM_CONTINUE;
}

static void enumerate_devices(void)
{
    g_device_count = 0;
    if (!g_di_cfg.di) return;

    IDirectInput8_EnumDevices(g_di_cfg.di, DI8DEVCLASS_GAMECTRL,
                             enum_dev_cb, NULL, DIEDFL_ATTACHEDONLY);
}

#define DEADZONE_MIN 0
#define DEADZONE_MAX 16000
#define DEADZONE_RECOMMENDED_LOW 4000
#define DEADZONE_RECOMMENDED_HIGH 8000

static void status_set(HWND dlg, const char *msg)
{
    SetDlgItemTextA(dlg, IDC_STATUS_TEXT, msg);
}

static int clamp_deadzone(int dz)
{
    if (dz < DEADZONE_MIN) return DEADZONE_MIN;
    if (dz > DEADZONE_MAX) return DEADZONE_MAX;
    return dz;
}

static void update_deadzone_controls(HWND dlg)
{
    if (!dlg || g_ds.port < 0 || g_ds.port >= MAX_CONTROLLERS) return;

    int dz = clamp_deadzone(g_n64maps[g_ds.port].deadzone);
    g_n64maps[g_ds.port].deadzone = (int16_t)dz;

    HWND slider = GetDlgItem(dlg, IDC_DEADZONE_SLIDER);
    if (slider) {
        SendMessageA(slider, TBM_SETRANGE, TRUE, MAKELONG(DEADZONE_MIN, DEADZONE_MAX));
        SendMessageA(slider, TBM_SETTICFREQ, 2000, 0);
        SendMessageA(slider, TBM_SETPAGESIZE, 0, 1000);
        SendMessageA(slider, TBM_SETLINESIZE, 0, 500);
        SendMessageA(slider, TBM_SETPOS, TRUE, dz);
    }

    char text[64];
    sprintf_s(text, sizeof(text), "Value: %d", dz);
    SetDlgItemTextA(dlg, IDC_DEADZONE_VALUE, text);

    char rec[80];
    sprintf_s(rec, sizeof(rec), "Recommended: %d-%d", DEADZONE_RECOMMENDED_LOW, DEADZONE_RECOMMENDED_HIGH);
    SetDlgItemTextA(dlg, IDC_DEADZONE_RECOMMEND, rec);
}

static void apply_deadzone_from_slider(HWND dlg)
{
    if (!dlg || g_ds.port < 0 || g_ds.port >= MAX_CONTROLLERS) return;

    HWND slider = GetDlgItem(dlg, IDC_DEADZONE_SLIDER);
    if (!slider) return;

    int dz = clamp_deadzone((int)SendMessageA(slider, TBM_GETPOS, 0, 0));
    g_n64maps[g_ds.port].deadzone = (int16_t)dz;

    char text[64];
    sprintf_s(text, sizeof(text), "Value: %d", dz);
    SetDlgItemTextA(dlg, IDC_DEADZONE_VALUE, text);

    save_config();
}

static void lv_set_columns(HWND lv)
{
    LVCOLUMNA col;
    ZeroMemory(&col, sizeof(col));
    col.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;

    col.pszText = (LPSTR)"N64 Control";
    col.cx = 160;
    col.iSubItem = 0;
    SendMessageA(lv, LVM_INSERTCOLUMNA, 0, (LPARAM)&col);

    col.pszText = (LPSTR)"Binding";
    col.cx = 160;
    col.iSubItem = 1;
    SendMessageA(lv, LVM_INSERTCOLUMNA, 1, (LPARAM)&col);
}

static void lv_fill_rows(HWND lv, int port)
{
    ListView_DeleteAllItems(lv);
    if (port < 0 || port >= MAX_CONTROLLERS) port = 0;

    for (int i = 0; i < ROW_COUNT; i++) {
        LVITEMA it;
        ZeroMemory(&it, sizeof(it));
        it.mask = LVIF_TEXT;
        it.iItem = i;
        it.pszText = (LPSTR)get_row_name(i);
        SendMessageA(lv, LVM_INSERTITEMA, 0, (LPARAM)&it);

        Binding *b = row_to_binding(&g_n64maps[port], i);
        char buf[128];
        ZeroMemory(buf, sizeof(buf));
        if (b) binding_to_text(b, buf, sizeof(buf));

        LVITEMA item = {0};
        item.iSubItem = 1;
        item.pszText = buf;
        SendMessageA(lv, LVM_SETITEMTEXTA, (WPARAM)i, (LPARAM)&item);
    }
}

static void devices_populate_combo(HWND cbDev, int port, HWND dlg)
{
    SendMessageA(cbDev, CB_RESETCONTENT, 0, 0);
    enumerate_devices();

    int noneIdx = (int)SendMessageA(cbDev, CB_ADDSTRING, 0, (LPARAM)"None");
    SendMessageA(cbDev, CB_SETITEMDATA, noneIdx, (LPARAM)-1);

    int wantSel = noneIdx;

    for (int i = 0; i < g_device_count; i++) {
        int idx = (int)SendMessageA(cbDev, CB_ADDSTRING, 0, (LPARAM)g_devices[i].name);
        SendMessageA(cbDev, CB_SETITEMDATA, idx, (LPARAM)i);

        if (g_n64maps[port].deviceGUID[0] &&
            lstrcmpiA(g_devices[i].guid_str, g_n64maps[port].deviceGUID) == 0)
        {
            wantSel = idx;
        }
    }

    SendMessageA(cbDev, CB_SETCURSEL, wantSel, 0);

    int sel = (int)SendMessageA(cbDev, CB_GETCURSEL, 0, 0);
    int dev_idx = (int)SendMessageA(cbDev, CB_GETITEMDATA, sel, 0);

    if (dev_idx >= 0 && dev_idx < g_device_count) {
        dinput_select_device(&g_di_cfg, &g_devices[dev_idx].guid, dlg,
                             DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
    } else {
        dinput_select_device(&g_di_cfg, NULL, dlg,
                             DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
    }
}

static int retry_config_device_from_combo(HWND dlg)
{
    HWND cbDev = GetDlgItem(dlg, IDC_DEVICE_COMBO);
    if (!cbDev) return 0;

    int sel = (int)SendMessageA(cbDev, CB_GETCURSEL, 0, 0);
    if (sel == CB_ERR) return 0;

    int dev_idx = (int)SendMessageA(cbDev, CB_GETITEMDATA, sel, 0);
    if (dev_idx < 0 || dev_idx >= g_device_count) return 0;

    return dinput_select_device(&g_di_cfg, &g_devices[dev_idx].guid, dlg,
                                DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
}

static void start_capture(HWND dlg, int row)
{
    g_ds.capturing = 1;
    g_ds.capture_row = row;
    g_ds.prev_valid = 0;
    g_ds.base_ticks = 0;
    ZeroMemory(&g_ds.base_js, sizeof(g_ds.base_js));
    status_set(dlg, "Release all controls…");
    SetTimer(dlg, 1, 10, NULL);
}

static void stop_capture(HWND dlg, const char *msg)
{
    KillTimer(dlg, 1);
    g_ds.capturing = 0;
    g_ds.capture_row = -1;
    g_ds.prev_valid = 0;
    status_set(dlg, msg ? msg : "Double-click a control to bind.");
}

static void draw_stick_grid(const DRAWITEMSTRUCT *dis)
{
    if (!dis) return;

    HDC dc = dis->hDC;
    RECT rc = dis->rcItem;
    FillRect(dc, &rc, (HBRUSH)(COLOR_WINDOW + 1));

    RECT grid = rc;
    InflateRect(&grid, -6, -6);

    HPEN border = CreatePen(PS_SOLID, 1, RGB(120, 120, 120));
    HPEN gridpen = CreatePen(PS_DOT, 1, RGB(190, 190, 190));
    HPEN axispen = CreatePen(PS_SOLID, 1, RGB(130, 130, 130));
    HPEN oldpen = (HPEN)SelectObject(dc, border);

    Rectangle(dc, grid.left, grid.top, grid.right, grid.bottom);

    SelectObject(dc, gridpen);
    int w = grid.right - grid.left;
    int h = grid.bottom - grid.top;
    for (int i = 1; i < 4; i++) {
        int x = grid.left + (w * i) / 4;
        int y = grid.top + (h * i) / 4;
        MoveToEx(dc, x, grid.top, NULL); LineTo(dc, x, grid.bottom);
        MoveToEx(dc, grid.left, y, NULL); LineTo(dc, grid.right, y);
    }

    int cx = (grid.left + grid.right) / 2;
    int cy = (grid.top + grid.bottom) / 2;
    SelectObject(dc, axispen);
    MoveToEx(dc, cx, grid.top, NULL); LineTo(dc, cx, grid.bottom);
    MoveToEx(dc, grid.left, cy, NULL); LineTo(dc, grid.right, cy);

    if (g_ds.preview_valid) {
        int halfw = w / 2 - 3;
        int halfh = h / 2 - 3;
        int px = cx + (g_ds.preview_x * halfw) / 127;
        int py = cy - (g_ds.preview_y * halfh) / 127; // positive N64 Y is up

        HBRUSH dot = CreateSolidBrush(RGB(40, 120, 230));
        HBRUSH oldbrush = (HBRUSH)SelectObject(dc, dot);
        HPEN dotpen = CreatePen(PS_SOLID, 1, RGB(20, 70, 160));
        SelectObject(dc, dotpen);
        Ellipse(dc, px - 5, py - 5, px + 6, py + 6);
        SelectObject(dc, oldbrush);
        DeleteObject(dot);
        DeleteObject(dotpen);
    }

    SelectObject(dc, oldpen);
    DeleteObject(border);
    DeleteObject(gridpen);
    DeleteObject(axispen);
}

static void update_live_input_preview(HWND dlg, const DIJOYSTATE2 *cur)
{
    if (!dlg || !cur) return;

    BUTTONS n64;
    ZeroMemory(&n64, sizeof(n64));
    eval_port_to_buttons(g_ds.port, cur, &g_di_cfg.cal, &n64, NULL);

    g_ds.preview_x = n64.X_AXIS;
    g_ds.preview_y = n64.Y_AXIS;
    g_ds.preview_valid = 1;

    char rawAxes[160];
    sprintf_s(rawAxes, sizeof(rawAxes), "LX=%ld LY=%ld RX=%ld RY=%ld Z=%ld RZ=%ld",
              cur->lX, cur->lY, cur->lRx, cur->lRy, cur->lZ, cur->lRz);
    SetDlgItemTextA(dlg, IDC_TEST_RAWAXES, rawAxes);

    char pov[64];
    if (cur->rgdwPOV[0] == 0xFFFFFFFF || cur->rgdwPOV[0] == 0xFFFF) {
        strcpy_s(pov, sizeof(pov), "neutral");
    } else {
        sprintf_s(pov, sizeof(pov), "%lu", (unsigned long)cur->rgdwPOV[0]);
    }
    SetDlgItemTextA(dlg, IDC_TEST_RAWPOV, pov);

    char btns[160] = "";
    int used = 0;
    for (int i = 0; i < 128 && used < (int)sizeof(btns) - 8; i++) {
        if (cur->rgbButtons[i] & 0x80) {
            int n = sprintf_s(btns + used, sizeof(btns) - used, "%s%d", used ? "," : "", i);
            if (n > 0) used += n;
        }
    }
    if (!btns[0]) strcpy_s(btns, sizeof(btns), "none");
    SetDlgItemTextA(dlg, IDC_TEST_RAWBTN, btns);

    char n64Stick[64];
    sprintf_s(n64Stick, sizeof(n64Stick), "X=%d Y=%d", (int)n64.X_AXIS, (int)n64.Y_AXIS);
    SetDlgItemTextA(dlg, IDC_TEST_N64STICK, n64Stick);

    char n64Btns[64];
    sprintf_s(n64Btns, sizeof(n64Btns), "0x%04X", (unsigned)n64.Value);
    SetDlgItemTextA(dlg, IDC_TEST_N64BTN, n64Btns);

    InvalidateRect(GetDlgItem(dlg, IDC_STICK_GRID), NULL, FALSE);
}

EXPORT void CALL DllConfig(HWND hParent)
{
    INITCOMMONCONTROLSEX icc = { sizeof(icc), ICC_LISTVIEW_CLASSES | ICC_BAR_CLASSES };
    InitCommonControlsEx(&icc);

    load_config();

    dinput_shutdown(&g_di_cfg);

    INT_PTR r = DialogBoxParamA(g_hInst, MAKEINTRESOURCEA(IDD_CONFIG),
                               hParent, ConfigDlgProc, 0);

    if (r == -1) {
        char buf[256];
        DWORD err = GetLastError();
        sprintf_s(buf, sizeof(buf), "DialogBoxParamA failed. GetLastError=%lu", err);
        MessageBoxA(hParent, buf, "AlardiDInput Error", MB_OK | MB_ICONERROR);
    }

    dinput_shutdown(&g_di_cfg);
}

EXPORT void CALL DllAbout(HWND hParent)
{
    MessageBoxA(hParent,
        "AlardiDInput\n"
        "DirectInput controller plugin for Project64.\n",
        "About",
        MB_OK | MB_ICONINFORMATION);
}

static INT_PTR CALLBACK ConfigDlgProc(HWND dlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
    (void)lParam;

    switch (msg)
    {
    case WM_INITDIALOG:
    {
        g_ds.port = 0;
        g_ds.capturing = 0;
        g_ds.capture_row = -1;
        g_ds.prev_valid = 0;
        g_ds.preview_x = 0;
        g_ds.preview_y = 0;
        g_ds.preview_valid = 0;

        HWND lv = GetDlgItem(dlg, IDC_BIND_LIST);
        HWND cbPort = GetDlgItem(dlg, IDC_PORT_COMBO);
        HWND cbDev  = GetDlgItem(dlg, IDC_DEVICE_COMBO);

        if (!lv || !cbPort || !cbDev) {
            MessageBoxA(dlg, "Missing control(s). Check resource IDs.", "AlardiDInput", MB_OK | MB_ICONERROR);
            EndDialog(dlg, 0);
            return TRUE;
        }

        LONG style = GetWindowLongA(lv, GWL_STYLE);
        style |= LVS_REPORT | LVS_SINGLESEL;
        SetWindowLongA(lv, GWL_STYLE, style);
        ListView_SetExtendedListViewStyle(lv, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);

        lv_set_columns(lv);
        lv_fill_rows(lv, 0);
        update_deadzone_controls(dlg);

        SendMessageA(cbPort, CB_RESETCONTENT, 0, 0);
        SendMessageA(cbPort, CB_ADDSTRING, 0, (LPARAM)"Port 1");
        SendMessageA(cbPort, CB_ADDSTRING, 0, (LPARAM)"Port 2");
        SendMessageA(cbPort, CB_ADDSTRING, 0, (LPARAM)"Port 3");
        SendMessageA(cbPort, CB_ADDSTRING, 0, (LPARAM)"Port 4");
        SendMessageA(cbPort, CB_SETCURSEL, 0, 0);

        dinput_shutdown(&g_di_cfg);
        if (dinput_init(&g_di_cfg, GetModuleHandleA(NULL), dlg) && g_di_cfg.di) {
            devices_populate_combo(cbDev, 0, dlg);
            SetTimer(dlg, 2, 33, NULL);
            status_set(dlg, "Ready. Double-click a control to bind.");
        } else {
            SendMessageA(cbDev, CB_RESETCONTENT, 0, 0);
            SendMessageA(cbDev, CB_ADDSTRING, 0, (LPARAM)"DirectInput not available");
            SendMessageA(cbDev, CB_SETCURSEL, 0, 0);
            status_set(dlg, "DirectInput not available.");
        }

        return TRUE;
    }

    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDOK:
        case IDCANCEL:
            KillTimer(dlg, 1);
            KillTimer(dlg, 2);
            EndDialog(dlg, 0);
            return TRUE;

        case IDC_PORT_COMBO:
            if (HIWORD(wParam) == CBN_SELCHANGE) {
                int sel = (int)SendDlgItemMessageA(dlg, IDC_PORT_COMBO, CB_GETCURSEL, 0, 0);
                if (sel >= 0 && sel < MAX_CONTROLLERS) {
                    stop_capture(dlg, NULL);
                    g_ds.port = sel;
                    lv_fill_rows(GetDlgItem(dlg, IDC_BIND_LIST), g_ds.port);
                    devices_populate_combo(GetDlgItem(dlg, IDC_DEVICE_COMBO), g_ds.port, dlg);
                    update_deadzone_controls(dlg);
                }
            }
            return TRUE;

        case IDC_DEVICE_COMBO:
            if (HIWORD(wParam) == CBN_SELCHANGE) {
                int sel = (int)SendDlgItemMessageA(dlg, IDC_DEVICE_COMBO, CB_GETCURSEL, 0, 0);
                if (sel == CB_ERR) return TRUE;

                int dev_idx = (int)SendDlgItemMessageA(dlg, IDC_DEVICE_COMBO, CB_GETITEMDATA, sel, 0);

                if (dev_idx >= 0 && dev_idx < g_device_count) {
                    strcpy_s(g_n64maps[g_ds.port].deviceGUID,
                             sizeof(g_n64maps[g_ds.port].deviceGUID),
                             g_devices[dev_idx].guid_str);

                    if (!dinput_select_device(&g_di_cfg, &g_devices[dev_idx].guid, dlg,
                                             DISCL_BACKGROUND | DISCL_NONEXCLUSIVE)) {
                        char msg[128];
                        sprintf_s(msg, sizeof(msg), "Failed to select device (hr=0x%08lX)", (unsigned long)g_di_cfg.last_hr);
                        status_set(dlg, msg);
                    } else {
                        status_set(dlg, "Device selected");
                    }
                } else {
                    g_n64maps[g_ds.port].deviceGUID[0] = 0;
                    dinput_select_device(&g_di_cfg, NULL, dlg, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
                    status_set(dlg, "No device");
                }

                g_controls[g_ds.port].Present = g_n64maps[g_ds.port].deviceGUID[0] ? 1 : 0;
                g_controls[g_ds.port].RawData = 0;
                g_controls[g_ds.port].Plugin = PLUGIN_NONE;
                copy_controls_to_host();

                g_ds.prev_valid = 0;
                g_ds.base_ticks = 0;

                save_config();
            }
            return TRUE;

        case IDC_CLEAR_BIND:
        {
            HWND lv = GetDlgItem(dlg, IDC_BIND_LIST);
            int row = ListView_GetNextItem(lv, -1, LVNI_SELECTED);
            if (row >= 0) {
                Binding *b = row_to_binding(&g_n64maps[g_ds.port], row);
                if (b) memset(b, 0, sizeof(*b));
                lv_fill_rows(lv, g_ds.port);
                save_config();
            }
            return TRUE;
        }

        case IDC_CLEAR_ALL:
            init_default_n64map(&g_n64maps[g_ds.port]);
            lv_fill_rows(GetDlgItem(dlg, IDC_BIND_LIST), g_ds.port);
            update_deadzone_controls(dlg);
            save_config();
            return TRUE;
        }
        break;
    }

    case WM_HSCROLL:
        if ((HWND)lParam == GetDlgItem(dlg, IDC_DEADZONE_SLIDER)) {
            apply_deadzone_from_slider(dlg);
            return TRUE;
        }
        break;

    case WM_NOTIFY:
    {
        NMHDR *nm = (NMHDR*)lParam;
        if (nm && nm->idFrom == IDC_BIND_LIST && nm->code == NM_DBLCLK) {
            if (!g_ds.capturing) {
                HWND lv = GetDlgItem(dlg, IDC_BIND_LIST);
                int row = ListView_GetNextItem(lv, -1, LVNI_SELECTED);
                if (row >= 0) start_capture(dlg, row);
            }
            return TRUE;
        }
        break;
    }

    case WM_DRAWITEM:
    {
        DRAWITEMSTRUCT *dis = (DRAWITEMSTRUCT*)lParam;
        if (dis && dis->CtlID == IDC_STICK_GRID) {
            draw_stick_grid(dis);
            return TRUE;
        }
        break;
    }

    case WM_TIMER:
        if (wParam == 1 && g_ds.capturing) {
            DIJOYSTATE2 cur;
            int ok = dinput_poll_joystick(&g_di_cfg, &cur);
            if (!ok) {
                if (g_di_cfg.last_hr == HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS) &&
                    retry_config_device_from_combo(dlg)) {
                    ok = dinput_poll_joystick(&g_di_cfg, &cur);
                }
            }

            if (!ok) {
                char msg[128];
                sprintf_s(msg, sizeof(msg), "Poll failed (hr=0x%08lX)", (unsigned long)g_di_cfg.last_hr);
                status_set(dlg, msg);
                return TRUE;
            }

            if (!g_ds.prev_valid) {
                int anyBtn = 0;
                for (int i = 0; i < 128; i++) {
                    if (cur.rgbButtons[i] & 0x80) { anyBtn = 1; break; }
                }
                int povNeutral = (cur.rgdwPOV[0] == 0xFFFF || cur.rgdwPOV[0] == 0xFFFFFFFF);

                if (anyBtn || !povNeutral) {
                    g_ds.base_ticks = 0;
                    status_set(dlg, "Release all controls…");
                    return TRUE;
                }

                if (g_ds.base_ticks == 0) {
                    g_ds.base_js = cur;
                }
                g_ds.base_ticks++;

                if (g_ds.base_ticks < 8) {
                    status_set(dlg, "Center stick / neutral…");
                    return TRUE;
                }

                g_ds.prev_valid = 1;
                status_set(dlg, "Now press an input to bind…");
                return TRUE;
            }

            Binding new_bind;
            ZeroMemory(&new_bind, sizeof(new_bind));
            int wantAnalog = (g_ds.capture_row == ROW_STICKX || g_ds.capture_row == ROW_STICKY);

            if (capture_next_input(&g_ds.base_js, &cur, &new_bind, wantAnalog)) {
                Binding *dst = row_to_binding(&g_n64maps[g_ds.port], g_ds.capture_row);
                if (dst) *dst = new_bind;

                char buf[128];
                binding_to_text(&new_bind, buf, sizeof(buf));

                LVITEMA item = {0};
                item.iSubItem = 1;
                item.pszText  = buf;
                SendMessageA(GetDlgItem(dlg, IDC_BIND_LIST), LVM_SETITEMTEXTA,
                             (WPARAM)g_ds.capture_row, (LPARAM)&item);

                save_config();
                stop_capture(dlg, "Bound!");
            }

            return TRUE;
        }

        if (wParam == 2) {
            DIJOYSTATE2 cur;
            int ok = dinput_poll_joystick(&g_di_cfg, &cur);
            if (!ok && g_di_cfg.last_hr == HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS) &&
                retry_config_device_from_combo(dlg)) {
                ok = dinput_poll_joystick(&g_di_cfg, &cur);
            }

            char s[128];
            sprintf_s(s, sizeof(s), "DI ok=%d hr=0x%08lX", ok, (unsigned long)g_di_cfg.last_hr);
            SetDlgItemTextA(dlg, IDC_STATUS_TEXT, s);

            if (!ok) {
                g_ds.preview_valid = 0;
                InvalidateRect(GetDlgItem(dlg, IDC_STICK_GRID), NULL, FALSE);
                return TRUE;
            }

            update_live_input_preview(dlg, &cur);
            return TRUE;
        }
        return TRUE;

    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE && g_ds.capturing) {
            stop_capture(dlg, "Cancelled.");
            return TRUE;
        }
        break;
    }

    return FALSE;
}

EXPORT void CALL WM_KeyDown(uint32_t wParam, uint32_t lParam) { (void)wParam; (void)lParam; }
EXPORT void CALL WM_KeyUp(uint32_t wParam, uint32_t lParam)   { (void)wParam; (void)lParam; }

static int raw_axis_from_js(const DIJOYSTATE2 *js, int axid)
{
    switch (axid) {
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

void eval_port_to_buttons(int port, const DIJOYSTATE2 *js, const DeviceCal *cal, BUTTONS *out, const uint8_t kb[256])
{
    (void)kb;

    out->Value = 0;
    out->X_AXIS = 0;
    out->Y_AXIS = 0;

    if (!js || port < 0 || port >= MAX_CONTROLLERS) return;

    const N64Map *map = &g_n64maps[port];

    if (evaluate_binding(&map->A,      js)) out->Value |= A_BUTTON;
    if (evaluate_binding(&map->B,      js)) out->Value |= B_BUTTON;
    if (evaluate_binding(&map->Z,      js)) out->Value |= Z_TRIG;
    if (evaluate_binding(&map->Start,  js)) out->Value |= START_BUTTON;
    if (evaluate_binding(&map->L,      js)) out->Value |= L_TRIG;
    if (evaluate_binding(&map->R,      js)) out->Value |= R_TRIG;

    if (evaluate_binding(&map->DUp,    js)) out->Value |= U_DPAD;
    if (evaluate_binding(&map->DDown,  js)) out->Value |= D_DPAD;
    if (evaluate_binding(&map->DLeft,  js)) out->Value |= L_DPAD;
    if (evaluate_binding(&map->DRight, js)) out->Value |= R_DPAD;

    if (evaluate_binding(&map->CUp,    js)) out->Value |= U_CBUTTON;
    if (evaluate_binding(&map->CDown,  js)) out->Value |= D_CBUTTON;
    if (evaluate_binding(&map->CLeft,  js)) out->Value |= L_CBUTTON;
    if (evaluate_binding(&map->CRight, js)) out->Value |= R_CBUTTON;

    float dz = (map->deadzone > 0) ? (float)map->deadzone / 32767.0f : 0.15f;
    if (dz > 0.95f) dz = 0.95f;

    float sx = 0.0f, sy = 0.0f;

    if (map->StickX.type == BIND_AXIS && map->StickX.index < AX_COUNT) {
        const AxisCal *ac = cal ? &cal->axis[map->StickX.index] : NULL;
        sx = norm_axis(raw_axis_from_js(js, map->StickX.index), ac);
        sx = apply_deadzone_f(sx, dz);
    }
    if (map->StickY.type == BIND_AXIS && map->StickY.index < AX_COUNT) {
        const AxisCal *ac = cal ? &cal->axis[map->StickY.index] : NULL;
        sy = norm_axis(raw_axis_from_js(js, map->StickY.index), ac);
        sy = apply_deadzone_f(sy, dz);
    }

    if (!map->invertY) sy = -sy;

    out->X_AXIS = f_to_s8(sx);
    out->Y_AXIS = f_to_s8(sy);
}

EXPORT void CALL DllTest(HWND hParent) { (void)hParent; }
EXPORT void CALL PluginLoaded(void) { }
EXPORT void CALL SetPluginNotification(void *p) { (void)p; }
EXPORT void CALL SetSettingInfo(void *p) { (void)p; }
EXPORT void CALL SetSettingInfo2(void *p) { (void)p; }
EXPORT void CALL SetSettingInfo3(void *p) { (void)p; }
EXPORT void CALL SetSettingNotificationInfo(void *p) { (void)p; }