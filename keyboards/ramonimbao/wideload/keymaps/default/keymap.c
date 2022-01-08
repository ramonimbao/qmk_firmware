// Copyright 2022 Ramon Imbao (@ramonimbao)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_INS,  KC_HOME, KC_PGUP, KC_P7,   KC_P8,   KC_P9,
                 KC_F4,   KC_F5,   KC_F6,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_DEL,  KC_END,  KC_PGDN, KC_P4,   KC_P5,   KC_P6,
                 KC_F7,   KC_F8,   KC_F9,   KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),            KC_UP,            KC_P1,   KC_P2,   KC_P3,
                 KC_F10,  KC_F11,  KC_F12,  KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           KC_SPC,           KC_RALT, KC_RGUI, KC_APP,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_P0,   KC_PDOT,
        KC_NO,   KC_NO
    ),
    [1] = LAYOUT_all(
        _______, KC_F13,  KC_F14,  KC_F15,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, _______, _______, _______, _______, _______, _______,
                 KC_F16,  KC_F17,  KC_F18,  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______,          _______, _______, _______, _______, _______, _______,
                 KC_F19,  KC_F20,  KC_F21,  _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______, _______,
                 KC_F22,  KC_F23,  KC_F24,  _______, _______, _______,          _______,          _______,          _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}
