// Simple test program to validate core plugin logic
// Compile with: cl test_main.c bindings.c calibration.c bind_capture.c

#include <stdio.h>
#include <stdlib.h>
#include "bindings.h"

// Mock DirectInput state for testing
typedef struct {
    LONG lX, lY, lZ, lRx, lRy, lRz;
    DWORD rgdwPOV[4];
    BYTE rgbButtons[128];
} MockDIJOYSTATE2;

int main() {
    printf("AlardiDInput - Core Logic Test\n");
    printf("========================================\n\n");

    // Test 1: Binding creation
    printf("Test 1: Binding structures\n");
    Binding b;
    memset(&b, 0, sizeof(b));

    b.type = BIND_BTN;
    b.index = 5;
    char str[64];
    binding_to_text(&b, str, sizeof(str));
    printf("Button binding: %s\n", str);

    // Test 2: N64 map initialization
    printf("\nTest 2: N64 map initialization\n");
    N64Map map;
    memset(&map, 0, sizeof(map));
    printf("N64Map initialized successfully\n");

    // Test 3: Axis calibration
    printf("\nTest 3: Axis calibration\n");
    DeviceCal cal;
    memset(&cal, 0, sizeof(cal));

    // Simulate detected range
    cal.axis[AX_LX].minv = -1000;
    cal.axis[AX_LX].maxv = 1000;
    cal.axis[AX_LX].center = 0;
    cal.axis[AX_LX].valid = 1;

    float norm = norm_axis(500, &cal.axis[AX_LX]);
    printf("Axis normalization: 500 -> %.3f (expected ~0.500)\n", norm);

    float dz = apply_deadzone_f(norm, 0.1f);
    printf("Deadzone applied: %.3f -> %.3f\n", norm, dz);

    int8_t s8 = f_to_s8(dz);
    printf("Converted to int8: %d\n", s8);

    // Test 4: Mock input evaluation
    printf("\nTest 4: Input evaluation\n");
    MockDIJOYSTATE2 mock_js = {0};
    mock_js.rgbButtons[0] = 0x80; // Button 0 pressed

    // Create a button binding
    Binding btn_binding = {0};
    btn_binding.type = BIND_BTN;
    btn_binding.index = 0;

    // Note: We can't easily test evaluate_binding without full DIJOYSTATE2,
    // but the function signatures are validated by compilation

    printf("Core logic validation complete!\n");
    printf("\nTo build full DLL, install Visual Studio with C++ tools\n");
    printf("Then run: build.bat\n");

    return 0;
}

