@echo off
REM Syntax check - verifies code compiles without linking

if not exist "build" mkdir build
cd build

echo Checking syntax of C files...

REM Try to compile each file with /Zs (syntax check only)
echo Checking main.c...
cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\main.c >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ERROR in main.c
    cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\main.c
) else (
    echo ✓ main.c OK
)

echo Checking dinput_backend.c...
cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\dinput_backend.c >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ERROR in dinput_backend.c
    cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\dinput_backend.c
) else (
    echo ✓ dinput_backend.c OK
)

echo Checking bindings.c...
cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\bindings.c >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ERROR in bindings.c
    cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\bindings.c
) else (
    echo ✓ bindings.c OK
)

echo Checking bind_capture.c...
cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\bind_capture.c >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ERROR in bind_capture.c
    cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\bind_capture.c
) else (
    echo ✓ bind_capture.c OK
)

echo Checking calibration.c...
cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\calibration.c >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ERROR in calibration.c
    cl /Zs /DWIN32 /D_WINDOWS /W3 /I.. ..\calibration.c
) else (
    echo ✓ calibration.c OK
)

echo.
echo Syntax check complete.
cd ..

