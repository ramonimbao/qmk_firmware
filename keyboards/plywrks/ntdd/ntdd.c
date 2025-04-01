// Copyright 2025 Ramon Imbao (@ramonimbao)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }
    led_t state = host_keyboard_led_state();

    if (!state.caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
    }

    return false;
}
#endif
