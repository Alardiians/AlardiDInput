#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define DIRECTINPUT_VERSION 0x0800
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <dinput.h>
#include <ctype.h>
#include "bindings.h"
#include "calibration.h"

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

static void trim_inplace(char* s)
{
    if (!s) return;
    char* p = s;
    while (*p && isspace((unsigned char)*p)) p++;
    if (p != s) memmove(s, p, strlen(p) + 1);

    size_t n = strlen(s);
    while (n > 0 && isspace((unsigned char)s[n - 1])) s[--n] = 0;
}

static int axis_name_to_id(const char* name, AxisId* outId)
{
    if (!name || !outId) return 0;
    if (_stricmp(name, "LX") == 0)  { *outId = AX_LX;  return 1; }
    if (_stricmp(name, "LY") == 0)  { *outId = AX_LY;  return 1; }
    if (_stricmp(name, "LZ") == 0)  { *outId = AX_LZ;  return 1; }
    if (_stricmp(name, "LRX") == 0) { *outId = AX_LRX; return 1; }
    if (_stricmp(name, "LRY") == 0) { *outId = AX_LRY; return 1; }
    if (_stricmp(name, "LRZ") == 0) { *outId = AX_LRZ; return 1; }
    if (_stricmp(name, "S0") == 0)  { *outId = AX_S0;  return 1; }
    if (_stricmp(name, "S1") == 0)  { *outId = AX_S1;  return 1; }
    return 0;
}

static const char* axis_id_to_name(AxisId id)
{
    switch (id) {
    case AX_LX:  return "LX";
    case AX_LY:  return "LY";
    case AX_LZ:  return "LZ";
    case AX_LRX: return "LRX";
    case AX_LRY: return "LRY";
    case AX_LRZ: return "LRZ";
    case AX_S0:  return "S0";
    case AX_S1:  return "S1";
    default:     return "?";
    }
}

static void binding_to_ini_string(const Binding* b, char* out, size_t outsz)
{
    if (!out || outsz < 2) return;
    out[0] = 0;

    if (!b || b->type == BIND_NONE) {
        strcpy_s(out, outsz, "NONE");
        return;
    }

    switch (b->type) {
    case BIND_BTN:
        sprintf_s(out, outsz, "BTN:%u", (unsigned)b->index);
        return;

    case BIND_POV: {
        const char* dirs[] = { "UP", "RIGHT", "DOWN", "LEFT" };
        const char* d = (b->pov_dir < 4) ? dirs[b->pov_dir] : "UP";
        sprintf_s(out, outsz, "POV%u:%s", (unsigned)b->index, d);
        return;
    }

    case BIND_AXIS:
        // optional threshold
        if (b->threshold > 0)
            sprintf_s(out, outsz, "AXIS:%s:%u", axis_id_to_name((AxisId)b->index), (unsigned)b->threshold);
        else
            sprintf_s(out, outsz, "AXIS:%s", axis_id_to_name((AxisId)b->index));
        return;

    case BIND_AXIS_POS:
        if (b->threshold > 0)
            sprintf_s(out, outsz, "AXIS:%s+:%u", axis_id_to_name((AxisId)b->index), (unsigned)b->threshold);
        else
            sprintf_s(out, outsz, "AXIS:%s+", axis_id_to_name((AxisId)b->index));
        return;

    case BIND_AXIS_NEG:
        if (b->threshold > 0)
            sprintf_s(out, outsz, "AXIS:%s-:%u", axis_id_to_name((AxisId)b->index), (unsigned)b->threshold);
        else
            sprintf_s(out, outsz, "AXIS:%s-", axis_id_to_name((AxisId)b->index));
        return;

    default:
        strcpy_s(out, outsz, "NONE");
        return;
    }
}

static int binding_from_ini_string(Binding* out, const char* in)
{
    if (!out) return 0;
    ZeroMemory(out, sizeof(*out));
    out->type = BIND_NONE;

    if (!in || !in[0]) return 1;

    char tmp[128];
    strcpy_s(tmp, sizeof(tmp), in);
    trim_inplace(tmp);

    if (tmp[0] == 0 || _stricmp(tmp, "NONE") == 0) return 1;

    // BTN:<n>
    if (_strnicmp(tmp, "BTN:", 4) == 0) {
        int idx = atoi(tmp + 4);
        if (idx < 0) idx = 0;
        if (idx > 127) idx = 127;
        out->type = BIND_BTN;
        out->index = (uint8_t)idx;
        return 1;
    }

    // POV0:UP / POV:UP (defaults index 0)
    if (_strnicmp(tmp, "POV", 3) == 0) {
        const char* p = tmp + 3;
        int povIdx = 0;
        if (isdigit((unsigned char)*p)) {
            povIdx = atoi(p);
            while (isdigit((unsigned char)*p)) p++;
        }
        if (*p == ':') p++;
        trim_inplace((char*)p);

        uint8_t dir = 0;
        if (_stricmp(p, "UP") == 0) dir = 0;
        else if (_stricmp(p, "RIGHT") == 0) dir = 1;
        else if (_stricmp(p, "DOWN") == 0) dir = 2;
        else if (_stricmp(p, "LEFT") == 0) dir = 3;
        else return 0;

        out->type = BIND_POV;
        out->index = (uint8_t)povIdx;
        out->pov_dir = dir;
        return 1;
    }

    // AXIS:LX / AXIS:LX+ / AXIS:LX- / optional :<threshold>
    if (_strnicmp(tmp, "AXIS:", 5) == 0) {
        char* p = tmp + 5;

        // split token and optional threshold
        char* th = strchr(p, ':');
        if (th) { *th++ = 0; trim_inplace(th); }

        trim_inplace(p);

        // check trailing +/-
        int sign = 0;
        size_t n = strlen(p);
        if (n > 0 && (p[n - 1] == '+' || p[n - 1] == '-')) {
            sign = (p[n - 1] == '+') ? +1 : -1;
            p[n - 1] = 0;
            trim_inplace(p);
        }

        AxisId id;
        if (!axis_name_to_id(p, &id)) return 0;

        out->index = (uint8_t)id;
        out->threshold = (th && *th) ? (uint16_t)atoi(th) : 12000;

        if (sign == 0) out->type = BIND_AXIS;
        else out->type = (sign > 0) ? BIND_AXIS_POS : BIND_AXIS_NEG;

        return 1;
    }

    return 0;
}

static int pov_to_dir(DWORD pov) {
  if (pov == 0xFFFFFFFF) return -1;
  if (pov >= 31500 || pov <= 4500) return 0;      // Up
  if (pov > 4500  && pov < 13500) return 1;       // Right
  if (pov >= 13500 && pov <= 22500) return 2;     // Down
  if (pov > 22500 && pov < 31500) return 3;       // Left
  return -1;
}

int evaluate_binding(const Binding *b, const DIJOYSTATE2 *js) {
  if (!b || !js || b->type == BIND_NONE) return 0;

  switch (b->type) {
    case BIND_BTN:
      return (b->index < 128) ? (js->rgbButtons[b->index] & 0x80) : 0;

    case BIND_POV: {
      if (b->index >= 4) return 0; // only support POV 0 for now
      int dir = pov_to_dir(js->rgdwPOV[b->index]);
      return (dir == b->pov_dir) ? 1 : 0;
    }

    case BIND_AXIS_POS: {
      int val = axis_value_by_id(js, (AxisId)b->index);
      return (val >= b->threshold) ? 1 : 0;
    }

    case BIND_AXIS_NEG: {
      int val = axis_value_by_id(js, (AxisId)b->index);
      return (val <= -b->threshold) ? 1 : 0;
    }

    default:
      return 0;
  }
}

int16_t evaluate_axis_binding(const Binding *b, const DIJOYSTATE2 *js, const DeviceCal *cal) {
  if (!b || !js || b->type != BIND_AXIS) return 0;

  int val = axis_value_by_id(js, (AxisId)b->index);

  // Get calibration for this axis
  const AxisCal *axis_cal = (cal && b->index < AX_COUNT) ? &cal->axis[b->index] : NULL;

  // Normalize using calibration
  float norm = norm_axis(val, axis_cal);

  // Apply small deadzone for axis evaluation
  const float deadzone = 0.02f; // 2% deadzone
  norm = apply_deadzone_f(norm, deadzone);

  // Convert to int8
  return f_to_s8(norm);
}

void binding_to_text(const Binding *b, char *buf, size_t bufsize) {
  if (!b || !buf || bufsize < 2) {
    if (buf && bufsize >= 5) lstrcpynA(buf, "None", bufsize);
    return;
  }

  switch (b->type) {
    case BIND_BTN:
      snprintf(buf, bufsize, "Btn %d", b->index);
      break;
    case BIND_POV: {
      const char *dirs[] = {"Up", "Right", "Down", "Left"};
      if (b->pov_dir < 4)
        snprintf(buf, bufsize, "POV %s", dirs[b->pov_dir]);
      else
        snprintf(buf, bufsize, "POV ?");
      break;
    }
    case BIND_AXIS: {
      const char *axes[] = {"LX", "LY", "LZ", "LRX", "LRY", "LRZ", "S0", "S1"};
      if (b->index < 8)
        snprintf(buf, bufsize, "Axis %s", axes[b->index]);
      else
        snprintf(buf, bufsize, "Axis ?");
      break;
    }
    case BIND_AXIS_POS: {
      const char *axes[] = {"LX+", "LY+", "LZ+", "LRX+", "LRY+", "LRZ+", "S0+", "S1+"};
      if (b->index < 8)
        snprintf(buf, bufsize, "%s", axes[b->index]);
      else
        snprintf(buf, bufsize, "Axis+ ?");
      break;
    }
    case BIND_AXIS_NEG: {
      const char *axes[] = {"LX-", "LY-", "LZ-", "LRX-", "LRY-", "LRZ-", "S0-", "S1-"};
      if (b->index < 8)
        snprintf(buf, bufsize, "%s", axes[b->index]);
      else
        snprintf(buf, bufsize, "Axis- ?");
      break;
    }
    default:
      lstrcpynA(buf, "None", bufsize);
      break;
  }
}

static const char *kRowNames[ROW_COUNT] = {
  "A","B","Z","Start",
  "D-Pad Up","D-Pad Down","D-Pad Left","D-Pad Right",
  "C Up","C Down","C Left","C Right",
  "L","R",
  "Stick X","Stick Y"
};

const char *get_row_name(int row) {
  if (row >= 0 && row < ROW_COUNT) return kRowNames[row];
  return "Unknown";
}

Binding* row_to_binding(N64Map *map, int row) {
    if (!map) return NULL;
    switch(row){
      case ROW_A: return &map->A;
      case ROW_B: return &map->B;
      case ROW_Z: return &map->Z;
      case ROW_START: return &map->Start;
      case ROW_DU: return &map->DUp;
      case ROW_DD: return &map->DDown;
      case ROW_DL: return &map->DLeft;
      case ROW_DR: return &map->DRight;
      case ROW_CU: return &map->CUp;
      case ROW_CD: return &map->CDown;
      case ROW_CL: return &map->CLeft;
      case ROW_CR: return &map->CRight;
      case ROW_L: return &map->L;
      case ROW_R: return &map->R;
      case ROW_STICKX: return &map->StickX;
      case ROW_STICKY: return &map->StickY;
      default: return NULL;
    }
}

static const char *axis_names[] = {"LX", "LY", "LZ", "LRX", "LRY", "LRZ", "S0", "S1"};
static const char *pov_dirs[] = {"UP", "RIGHT", "DOWN", "LEFT"};

void load_n64map_from_ini(N64Map *map, const char *iniPath, int port)
{
    if (!map || !iniPath) return;

    char section[32];
    snprintf(section, sizeof(section), "Port%d", port);

    char buf[256];

    // Bindings
    GetPrivateProfileStringA(section, "A",      "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->A, buf);
    GetPrivateProfileStringA(section, "B",      "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->B, buf);
    GetPrivateProfileStringA(section, "Z",      "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->Z, buf);
    GetPrivateProfileStringA(section, "Start",  "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->Start, buf);
    GetPrivateProfileStringA(section, "L",      "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->L, buf);
    GetPrivateProfileStringA(section, "R",      "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->R, buf);

    GetPrivateProfileStringA(section, "DUp",    "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->DUp, buf);
    GetPrivateProfileStringA(section, "DDown",  "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->DDown, buf);
    GetPrivateProfileStringA(section, "DLeft",  "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->DLeft, buf);
    GetPrivateProfileStringA(section, "DRight", "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->DRight, buf);

    GetPrivateProfileStringA(section, "CUp",    "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->CUp, buf);
    GetPrivateProfileStringA(section, "CDown",  "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->CDown, buf);
    GetPrivateProfileStringA(section, "CLeft",  "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->CLeft, buf);
    GetPrivateProfileStringA(section, "CRight", "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->CRight, buf);

    GetPrivateProfileStringA(section, "StickX", "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->StickX, buf);
    GetPrivateProfileStringA(section, "StickY", "NONE", buf, sizeof(buf), iniPath); binding_from_ini_string(&map->StickY, buf);

    // Settings
    map->deadzone = (int16_t)GetPrivateProfileIntA(section, "Deadzone", 8000, iniPath);
    map->invertY  = (uint8_t)GetPrivateProfileIntA(section, "InvertY", 0, iniPath);

    // Device
    GetPrivateProfileStringA(section, "DeviceGUID", "", map->deviceGUID, sizeof(map->deviceGUID), iniPath);
    trim_inplace(map->deviceGUID);
}

void save_n64map_to_ini(const N64Map *map, const char *iniPath, int port)
{
    if (!map || !iniPath) return;

    char section[32];
    snprintf(section, sizeof(section), "Port%d", port);

    char buf[128];

    // Bindings
    binding_to_ini_string(&map->A, buf, sizeof(buf));      WritePrivateProfileStringA(section, "A", buf, iniPath);
    binding_to_ini_string(&map->B, buf, sizeof(buf));      WritePrivateProfileStringA(section, "B", buf, iniPath);
    binding_to_ini_string(&map->Z, buf, sizeof(buf));      WritePrivateProfileStringA(section, "Z", buf, iniPath);
    binding_to_ini_string(&map->Start, buf, sizeof(buf));  WritePrivateProfileStringA(section, "Start", buf, iniPath);
    binding_to_ini_string(&map->L, buf, sizeof(buf));      WritePrivateProfileStringA(section, "L", buf, iniPath);
    binding_to_ini_string(&map->R, buf, sizeof(buf));      WritePrivateProfileStringA(section, "R", buf, iniPath);

    binding_to_ini_string(&map->DUp, buf, sizeof(buf));    WritePrivateProfileStringA(section, "DUp", buf, iniPath);
    binding_to_ini_string(&map->DDown, buf, sizeof(buf));  WritePrivateProfileStringA(section, "DDown", buf, iniPath);
    binding_to_ini_string(&map->DLeft, buf, sizeof(buf));  WritePrivateProfileStringA(section, "DLeft", buf, iniPath);
    binding_to_ini_string(&map->DRight, buf, sizeof(buf)); WritePrivateProfileStringA(section, "DRight", buf, iniPath);

    binding_to_ini_string(&map->CUp, buf, sizeof(buf));    WritePrivateProfileStringA(section, "CUp", buf, iniPath);
    binding_to_ini_string(&map->CDown, buf, sizeof(buf));  WritePrivateProfileStringA(section, "CDown", buf, iniPath);
    binding_to_ini_string(&map->CLeft, buf, sizeof(buf));  WritePrivateProfileStringA(section, "CLeft", buf, iniPath);
    binding_to_ini_string(&map->CRight, buf, sizeof(buf)); WritePrivateProfileStringA(section, "CRight", buf, iniPath);

    binding_to_ini_string(&map->StickX, buf, sizeof(buf)); WritePrivateProfileStringA(section, "StickX", buf, iniPath);
    binding_to_ini_string(&map->StickY, buf, sizeof(buf)); WritePrivateProfileStringA(section, "StickY", buf, iniPath);

    // Settings
    char nbuf[32];
    snprintf(nbuf, sizeof(nbuf), "%d", (int)map->deadzone);
    WritePrivateProfileStringA(section, "Deadzone", nbuf, iniPath);

    snprintf(nbuf, sizeof(nbuf), "%d", (int)map->invertY);
    WritePrivateProfileStringA(section, "InvertY", nbuf, iniPath);

    // DeviceGUID: ALWAYS write (so clearing actually clears the INI)
    WritePrivateProfileStringA(section, "DeviceGUID", map->deviceGUID, iniPath);
}

// Device enumeration
// Old DeviceInfo functions and structs removed - using new index-based enumeration in main.c
