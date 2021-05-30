/* Copyright 2021 Ramon Imbao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22,
        KC_PGUP, KC_PGDN
    ),
    [1] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
    ),
    [2] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
    ),
    [3] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
    ),
    [4] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
    ),
    [5] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
    ),
    [6] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
    ),
    [7] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______
    ),
};

keyevent_t encoder_ccw = {
    .key = (keypos_t){.row = 0, .col = 10},
    .pressed = false
};

keyevent_t encoder_cw = {
    .key = (keypos_t){.row = 0, .col = 11},
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

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        encoder_cw.pressed = true;
        encoder_cw.time = (timer_read() | 1);
        action_exec(encoder_cw);
    } else {
        encoder_ccw.pressed = true;
        encoder_ccw.time = (timer_read() | 1);
        action_exec(encoder_ccw);
    }
}
