#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PLUGIN_TYPE_RSP         1
#define PLUGIN_TYPE_GFX         2
#define PLUGIN_TYPE_AUDIO       3
#define PLUGIN_TYPE_CONTROLLER  4

#define MAX_CONTROLLERS 4

#define R_DPAD        0x0001
#define L_DPAD        0x0002
#define D_DPAD        0x0004
#define U_DPAD        0x0008
#define START_BUTTON  0x0010
#define Z_TRIG        0x0020
#define B_BUTTON      0x0040
#define A_BUTTON      0x0080
#define R_CBUTTON     0x0100
#define L_CBUTTON     0x0200
#define D_CBUTTON     0x0400
#define U_CBUTTON     0x0800
#define R_TRIG        0x1000
#define L_TRIG        0x2000

#pragma pack(push, 1)

typedef struct PLUGIN_INFO
{
    uint16_t Version;
    uint16_t Type;
    char     Name[100];
    int32_t  NormalMemory;
    int32_t  MemoryBswaped;
} PLUGIN_INFO;

typedef struct CONTROL
{
    int32_t Present;
    int32_t RawData;
    int32_t Plugin;
} CONTROL;

typedef struct CONTROL_INFO
{
    HWND   hMainWindow;
    HINSTANCE hinst;

    int32_t MemoryBswaped;
    uint8_t *HEADER;
    CONTROL *Controls;
} CONTROL_INFO;

typedef struct BUTTONS
{
    uint16_t Value;
    int8_t   X_AXIS;
    int8_t   Y_AXIS;
} BUTTONS;

#pragma pack(pop)

#if defined(_MSC_VER)
  #define EXPORT __declspec(dllexport)
  #define CALL   __cdecl
#else
  #define EXPORT __attribute__((visibility("default")))
  #define CALL
#endif

EXPORT void CALL GetDllInfo(PLUGIN_INFO *PluginInfo);
EXPORT void CALL InitiateControllers(CONTROL_INFO *ControlInfo);
EXPORT void CALL CloseDLL(void);

EXPORT void CALL RomOpen(void);
EXPORT void CALL RomClosed(void);

EXPORT void CALL GetKeys(int Control, BUTTONS *Keys);
EXPORT void CALL ReadController(int Control, uint8_t *Command);

EXPORT void CALL DllConfig(HWND hParent);
EXPORT void CALL DllAbout(HWND hParent);

EXPORT void CALL WM_KeyDown(uint32_t wParam, uint32_t lParam);
EXPORT void CALL WM_KeyUp(uint32_t wParam, uint32_t lParam);

#ifdef __cplusplus
}
#endif

