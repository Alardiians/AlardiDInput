# AlardiDInput

A complete DirectInput input plugin for Project64 with configurable bindings.

## Features

- **DirectInput Support**: Full DirectInput 8 support for joysticks/gamepads and keyboard
- **Configurable Bindings**: Map any DirectInput input to N64 controls
- **INI Configuration**: Settings saved to `AlardiDInput.ini` in the plugin directory
- **Real-time Binding**: Click any control to bind it to the next pressed input
- **Multi-device Support**: Support for multiple controllers (up to 4)
- **Analog Stick Support**: Full analog stick mapping with deadzone
- **Zilmar ABI Compliant**: Compatible with Project64 and other Zilmar-spec emulators

## Building

### Prerequisites
- Visual Studio 2019+ with C++ build tools
- Windows SDK with DirectInput headers
- DirectX SDK (for dinput8.lib, dxguid.lib)

### Build Steps
```cmd
cd pj64_dinput
build.bat
```

The build script will:
1. Compile the dialog resource (.rc)
2. Compile all C source files
3. Link into `AlardiDInput.dll` with required libraries

The resulting `AlardiDInput.dll` will be in the `build/` directory.

### Manual Build
```cmd
cl /c /DWIN32 /D_WINDOWS /W3 /MD /I. *.c
link /DLL /OUT:AlardiDInput.dll /DEF:exports.def *.obj dinput8.lib dxguid.lib user32.lib comctl32.lib
```

## Installation

1. Copy `AlardiDInput.dll` to your Project64 plugins directory
2. Launch Project64 and select "AlardiDInput" from the input plugins list
3. Configure bindings via the config dialog (Options → Configure Controller Plugin)

## Configuration Dialog

The configuration dialog provides:

- **Port Selection**: Choose which controller port (1-4) to configure
- **Device Selection**: Pick which DirectInput device to use for the selected port
- **Control Binding**: Double-click any N64 control to bind it
- **Real-time Capture**: Press any button/stick/POV to bind it immediately
- **Clear Functions**: Remove individual bindings or clear all bindings for a port
- **Live Input Test**: Real-time display of raw DirectInput values and interpreted N64 controls

### Binding Process

1. Select the controller port you want to configure
2. Choose the input device from the dropdown
3. Double-click on an N64 control (A, B, Start, D-pad, etc.)
4. The status shows "Listening..."
5. Press/move the input you want to bind
6. The binding is captured and saved automatically
7. Repeat for other controls

### Input Test Panel

The "Input Test (Live)" section at the bottom shows real-time input data:

- **Axes**: Raw DirectInput axis values (lX, lY, lZ, rX, rY, rZ, s0, s1)
- **POV**: Raw POV hat value (0xFFFFFFFF when centered)
- **Btns**: Count of currently pressed buttons
- **N64**: Interpreted N64 button bitmask (hex) and analog stick values

This helps debug input issues and verify that bindings are working correctly.

## Configuration

### Default Mappings
- **Keyboard Fallback**: Arrow keys for D-pad, WASD for analog, X/Z for A/B, etc.
- **Configurable**: Use the config dialog to bind any DirectInput input

### INI File Format
```ini
[Port1]
A=BTN,0
B=BTN,1
StickX=AXIS,LX
StickY=AXIS,LY
Deadzone=8000
InvertY=0
DeviceGUID={12345678-1234-1234-1234-123456789012}
```

### Binding Types
- `BTN,X` - Button X (0-127)
- `POV,IDX,DIR` - POV hat IDX in direction (UP=0, RIGHT=1, DOWN=2, LEFT=3)
- `AXIS,NAME` - Analog axis (LX, LY, LZ, LRX, LRY, LRZ, S0, S1)
- `AXIS+,NAME` - Positive axis direction
- `AXIS-,NAME` - Negative axis direction

## Architecture

### Core Components
- **plugin_zilmar.h**: Zilmar plugin ABI definitions
- **dinput_backend.h/c**: DirectInput initialization and polling
- **bindings.h/c**: Binding structures and INI save/load
- **bind_capture.c**: Input capture logic for config UI
- **main.c**: Plugin entry points and config dialog

### Key Functions
- `GetKeys()`: Main input polling, evaluates bindings
- `DllConfig()`: Configuration dialog (ListView + real-time binding)
- `capture_next_input()`: Detects next pressed input during binding

## Features

- **Complete Configuration UI**: Full dialog with ListView, device selection, and real-time binding
- **Real-time Input Capture**: Double-click controls to bind them to any DirectInput input
- **Device Management**: Select specific devices per controller port
- **Memory Management**: Proper cleanup of device enumeration data
- **Anti-ghosting**: Prevents instant binding by requiring neutral state first
- **Live Input Test Panel**: Real-time display of raw DirectInput values and interpreted N64 controls
- **Axis Calibration**: Automatic axis range detection and normalization for consistent stick behavior

## Limitations

- Raw PIF mode (rumble/mempak) not implemented
- Single device per port (no multi-device binding)

## Future Enhancements

1. **Complete Config UI**: Full dialog with ListView and device selection
2. **Device Auto-Detection**: Automatically select appropriate devices per port
3. **Rumble Support**: Implement Raw PIF mode for force feedback
4. **Memory Pak Support**: Virtual memory pak functionality
5. **Transfer Pak Support**: Game Boy cartridge reading
6. **Profile System**: Multiple binding profiles
7. **Advanced Mapping**: Curves, sensitivity, button combinations

## Troubleshooting

**Plugin won't load:**
- Ensure DirectInput 8 runtime is installed
- Check that dinput8.dll is available

**No input detected:**
- Verify device is connected and recognized by Windows
- Check device permissions (run as administrator if needed)

**Bindings not saving:**
- Ensure write permissions to plugin directory
- Check that INI file isn't read-only

## License

This is a clean-room implementation based on public Zilmar plugin specifications. No copyrighted code from other plugins was used.
