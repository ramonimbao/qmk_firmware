// Copyright 2021 Ramon Imbao (@ramonimbao)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
                 KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT,
        KC_VOLD, KC_VOLU
    )
};

keyevent_t encoder_ccw = {
    .key = (keypos_t){.row = 6, .col = 0},
    .pressed = false
};

keyevent_t encoder_cw = {
    .key = (keypos_t){.row = 6, .col = 1},
    .pressed = false
};

void matrix_scan_user(void) {
    if (IS_PRESSED(encoder_ccw)) {
        encoder_ccw.pressed = false;
        encoder_ccw.time = (timer_read() | 1);
        action_exec(encoder_ccw);
    }

    if (IS_PRESSED(encoder_cw)) {
        encoder_cw.pressed = false;
        encoder_cw.time = (timer_read() | 1);
        action_exec(encoder_cw);
    }
}

#ifdef OLED_ENABLE
uint32_t anim_sleep = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        encoder_cw.pressed = true;
        encoder_cw.time = (timer_read() | 1);
        action_exec(encoder_cw);
        wait_ms(20);
        anim_sleep = timer_read32();
        oled_on();
    } else {
        encoder_ccw.pressed = true;
        encoder_ccw.time = (timer_read() | 1);
        action_exec(encoder_ccw);
        wait_ms(20);
        anim_sleep = timer_read32();
        oled_on();
    }
    return true;
}

static void handle_sleep(void) {
    if (get_current_wpm() != 000) {
        oled_on();
        anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            oled_on();
        }
    }
}

bool oled_task_user(void) {
    handle_sleep();

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_set_cursor(0, 0);
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_set_cursor(0, 1);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_set_cursor(0, 2);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    oled_render();
    return false;
}
#endif
