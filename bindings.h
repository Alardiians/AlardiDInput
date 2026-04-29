#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include "calibration.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  ROW_A, ROW_B, ROW_Z, ROW_START,
  ROW_DU, ROW_DD, ROW_DL, ROW_DR,
  ROW_CU, ROW_CD, ROW_CL, ROW_CR,
  ROW_L, ROW_R,
  ROW_STICKX, ROW_STICKY,
  ROW_COUNT
} RowId;

typedef enum {
  BIND_NONE = 0,
  BIND_BTN,
  BIND_POV,
  BIND_AXIS,
  BIND_AXIS_POS,
  BIND_AXIS_NEG
} BindType;

typedef struct {
  BindType type;
  uint8_t  index;
  int16_t  threshold;
  uint8_t  pov_dir;
} Binding;

typedef struct {
  Binding A,B,Z,Start,L,R;
  Binding DUp,DDown,DLeft,DRight;
  Binding CUp,CDown,CLeft,CRight;
  Binding StickX, StickY;
  int16_t deadzone;
  uint8_t invertY;
  char deviceGUID[64];
} N64Map;

int evaluate_binding(const Binding *b, const DIJOYSTATE2 *js);
int16_t evaluate_axis_binding(const Binding *b, const DIJOYSTATE2 *js, const DeviceCal *cal);

void load_n64map_from_ini(N64Map *map, const char *iniPath, int port);
void save_n64map_to_ini(const N64Map *map, const char *iniPath, int port);

void binding_to_text(const Binding *b, char *buf, size_t bufsize);
const char *get_row_name(int row);
Binding* row_to_binding(N64Map *map, int row);

typedef struct DeviceInfo {
    GUID guid;
    char name[128];
    char guid_str[64];
} DeviceInfo;

#ifdef __cplusplus
}
#endif
