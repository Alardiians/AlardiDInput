@echo off
setlocal

set OUT=AlardiDInput.dll

rc /nologo pj64_dinput.rc

cl /nologo /O2 /W3 /DWIN32 /D_WINDOWS /D_CRT_SECURE_NO_WARNINGS /D_MBCS ^
  /LD ^
  main.c dinput_backend.c bindings.c bind_capture.c calibration.c ^
  pj64_dinput.res ^
  /link /DLL ^
  /DEF:exports.def ^
  /OUT:%OUT% ^
  dinput8.lib dxguid.lib user32.lib comctl32.lib

echo Built %OUT%
endlocal
