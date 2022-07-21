// Copyright 2022 Ramon Imbao (@ramonimbao)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
static uint16_t rgb_timer;
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_NO,   KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_NO,   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_NO,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_DOT,  KC_RSFT, MO(1),
                 KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  MO(2),   KC_SPC,  KC_RALT, KC_RGUI, KC_RCTL
    ),
    [1] = LAYOUT_all(
        _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______, KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_SCLN, KC_QUOT,
        _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_COMM, KC_SLSH, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT_all(
        _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_CAPS, KC_LBRC, KC_BSLS, KC_RBRC, KC_MINS, KC_EQL,  _______, _______, _______, KC_SCLN, KC_QUOT,
        _______, _______, KC_LCBR, KC_PIPE, KC_RCBR, KC_UNDS, KC_PLUS, _______, _______, KC_COMM, KC_SLSH, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

keyevent_t encoder_ccw = {
    .key = (keypos_t){.row = 4, .col = 0},
    .pressed = false
};

keyevent_t encoder_cw = {
    .key = (keypos_t){.row = 4, .col = 1},
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

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        encoder_cw.pressed = true;
        encoder_cw.time = (timer_read() | 1);
        action_exec(encoder_cw);
        wait_ms(20);
    } else {
        encoder_ccw.pressed = true;
        encoder_ccw.time = (timer_read() | 1);
        action_exec(encoder_ccw);
        wait_ms(20);
    }
    return false;
}

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {{
    // Key Matrix to LED Index
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
    // LED Index to Position
    { 214, 48 }, { 173, 48 }, { 132, 48 }, {  92, 48 }, {  51, 48 }, {  10, 48 },
    {  10,  5 }, {  51,  5 }, {  92,  5 }, { 132,  5 }, { 173,  5 }, { 214,  5 }
}, {
    // LED Index to Flags
    2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2
}};

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}
#endif
