#pragma once
#include <stdint.h>
#include <dinput.h>
#include "plugin_zilmar.h"
#include "calibration.h"

void eval_port_to_buttons(int port,
                          const DIJOYSTATE2 *js,
                          const DeviceCal *cal,
                          BUTTONS *out,
                          const uint8_t kb[256]);

