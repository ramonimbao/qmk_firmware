// Copyright 2023 Ramon Imbao (@ramonimbao)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp.h"

static bool display_enabled;

static painter_device_t display;

void keyboard_post_init_kb() {
    backlight_enable();

    display = qp_st7789_make_spi_device(240, 320, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 16, 3);
    display_enabled = false;
    if (qp_init(display, QP_ROTATION_0) || qp_power(display, true) || qp_lvgl_attach(display)) display_enabled = true;

    // qp_set_viewport_offsets(display, 0, 20);

    keyboard_post_init_user();
}

void housekeeping_task_kb(void) {
    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();
        // Draw 8px-wide rainbow down the left side of the display
        for (int i = 0; i < 320; ++i) {
            qp_line(display, 0, i, 240, i, i, 255, 255);
        }
        qp_flush(display);
    }

    housekeeping_task_user();
}
