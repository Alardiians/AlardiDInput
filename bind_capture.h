#pragma once
#include <dinput.h>
#include "bindings.h"

int capture_next_input(const DIJOYSTATE2 *prev,
                       const DIJOYSTATE2 *cur,
                       Binding *outBind,
                       int wantAnalogAxis);

