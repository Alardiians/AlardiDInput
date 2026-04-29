@echo off
REM Build verification script - checks for required tools

echo Checking for required build tools...

REM Check for Resource Compiler
where rc >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Resource Compiler (rc.exe) not found
    echo Make sure Visual Studio is installed with C++ build tools
    goto :error
) else (
    echo ✓ Resource Compiler found
)

REM Check for C Compiler
where cl >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: C Compiler (cl.exe) not found
    echo Make sure Visual Studio is installed with C++ build tools
    goto :error
) else (
    echo ✓ C Compiler found
)

REM Check for Linker
where link >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Linker (link.exe) not found
    echo Make sure Visual Studio is installed with C++ build tools
    goto :error
) else (
    echo ✓ Linker found
)

echo.
echo All build tools found! Ready to build.
echo Run: build.bat
goto :end

:error
echo.
echo Please install Visual Studio with C++ development tools.
echo Required workloads: "Desktop development with C++"
echo Required components: Windows SDK, C++ build tools
exit /b 1

:end

