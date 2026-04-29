# AlardiDInput Build Guide

## Prerequisites

### Option 1: Visual Studio (Recommended)
- **Visual Studio 2019 or 2022** with C++ development workload
- **Windows SDK** (latest version)
- **DirectX SDK** (June 2010 or later)

### Option 2: MinGW-w64 (Alternative)
- **MinGW-w64 GCC compiler**
- **Windows SDK headers**
- **DirectX headers and libraries**

## Build Methods

### Method 1: Visual Studio Build Script (Recommended)

```cmd
# From pj64_dinput directory
build.bat
```

**What it does:**
1. Compiles dialog resources (`pj64_dinput.rc`)
2. Compiles & links all C source files in one step using `/LD`
3. Optimizes with `/O2` for release build
4. Links into `AlardiDInput.dll` with required libraries

**Requirements:**
- Run from "Developer Command Prompt for VS" (or regular cmd with VS tools in PATH)
- Visual Studio 2019+ with C++ build tools
- Windows SDK and DirectX SDK

### Method 2: Syntax Check Only

```cmd
# Check if code compiles without linking
syntax_check.bat
```

### Method 3: Build Tools Check

```cmd
# Verify Visual Studio tools are available
build_check.bat
```

### Method 4: Manual Compilation

```cmd
# Create build directory
mkdir build
cd build

# Compile resources
rc /i.. /fo pj64_dinput.res ..\pj64_dinput.rc

# Compile C files
cl /c /DWIN32 /D_WINDOWS /W3 /MD /I.. ^
   ..\main.c ^
   ..\dinput_backend.c ^
   ..\bindings.c ^
   ..\bind_capture.c ^
   ..\calibration.c

# Link DLL
link /DLL /OUT:AlardiDInput.dll ^
     /DEF:..\exports.def ^
     main.obj dinput_backend.obj bindings.obj bind_capture.obj calibration.obj pj64_dinput.res ^
     dinput8.lib dxguid.lib user32.lib comctl32.lib
```

### Method 5: Makefile (MinGW)

```bash
# Using MinGW make
make
```

## Troubleshooting

### "rc is not recognized"
- Install Visual Studio with C++ development tools
- Add Visual Studio's `VC\bin` directory to PATH
- Or use MinGW-w64 instead

### "Cannot open include file: 'dinput.h'"
- Install Windows SDK
- Make sure `Include` directories are in PATH

### "Cannot open input file: 'dinput8.lib'"
- Install DirectX SDK
- Or download DirectX SDK and add to LIB path
- Modern Windows SDKs include DirectInput headers but may need legacy DirectX SDK for libs

### Linker errors about missing functions
- Ensure all source files are compiled: `main.c`, `dinput_backend.c`, `bindings.c`, `bind_capture.c`, `calibration.c`
- Check that `comctl32.lib` is linked for ListView support

## Output Files

After successful build:
- `build/AlardiDInput.dll` - The plugin DLL
- Various `.obj` files - Intermediate object files
- `pj64_dinput.res` - Compiled resources

## Installation

1. Copy `AlardiDInput.dll` to Project64's `Plugin` directory
2. Launch Project64
3. Select "AlardiDInput" from input plugins
4. Configure via Options → Configure Controller Plugin

## Testing

1. Open config dialog - should show live input test panel
2. Move analog sticks - N64 values should show calibrated ±127
3. Press buttons - should be counted in raw buttons display
4. Bind controls - double-click to capture input

## Development Notes

- The plugin uses Zilmar Plugin ABI v1.0
- Compatible with Project64 1.6+
- Requires Windows Vista or later for DirectInput 8
- Debug output goes to Visual Studio Output window or debugger

## Alternative Build Environments

### MSYS2/MinGW-w64
```bash
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-binutils
# Then use the Makefile
```

### CMake (Advanced)
Create `CMakeLists.txt` for cross-platform build configuration.
