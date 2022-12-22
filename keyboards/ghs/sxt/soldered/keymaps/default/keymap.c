/* Copyright 2022 Ramon Imbao
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
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
    ),

    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
};

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {{
    // Key Matrix to LED Index
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {      0, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED }
}, {
    // LED Index to Position
    {  13, 32 },
    {   0, 26 },
    {   0, 13 },
    {  30,  0 },
    {  60,  0 },
    {  90,  0 },
    { 119,  0 },
    { 149,  0 },
    { 179,  0 },
    { 209,  0 },
    { 224, 13 },
    { 224, 26 },
    { 224, 38 },
    { 224, 51 },
    { 209, 64 },
    { 179, 64 },
    { 153, 64 },
    { 127, 64 },
    { 101, 64 },
    {  75, 64 },
    {  45, 64 },
    {  11, 64 },
    {   0, 51 },
    {   0, 38 },
}, {
    // LED Index to Flags
    LED_FLAG_INDICATOR,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
    LED_FLAG_UNDERGLOW,
}};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
    }

    return false;
}
#endif
