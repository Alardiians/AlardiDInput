@echo off
REM AlardiDInput deployment wrapper

echo AlardiDInput Deployment
echo =======================
echo.

powershell -ExecutionPolicy Bypass -File "%~dp0deploy.ps1"

echo.
pause
