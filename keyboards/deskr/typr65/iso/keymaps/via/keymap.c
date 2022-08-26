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

enum custom_keycodes {
    KC_BLTG = USER00, // Toggle backlighting RGB LEDs
    KC_SLTG           // Toggle sidelighting RGB LEDs
};

typedef union {
    uint32_t raw;

    struct {
        bool backlight_enable : 1;
        bool sidelight_enable : 1;
    };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

void eeconfig_user_init(void) {
    user_config.raw = 0;
    user_config.backlight_enable = true;
    user_config.sidelight_enable = true;
    eeconfig_update_user(user_config.raw);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BLTG, KC_SLTG,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BLTG:
            if (record->event.pressed) {
                user_config.backlight_enable = !user_config.backlight_enable;
                eeconfig_update_user(user_config.raw);
            }
            break;
        case KC_SLTG:
            if (record->event.pressed) {
                user_config.sidelight_enable = !user_config.sidelight_enable;
                eeconfig_update_user(user_config.raw);
            }
            break;
        default:
            return true;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {{
    // Key Matrix to LED Index
    {      0,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12,     13,     14 },
    {     29,     28,     27,     26,     25,     24,     23,     22,     21,     20,     19,     18,     17,     16,     15 },
    {     30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42, NO_LED,     43 },
    {     58,     57,     56,     55,     54,     53,     52,     51,     50,     49,     48,     47,     46,     45,     44 },
    {     59,     60,     61, NO_LED, NO_LED, NO_LED,     62, NO_LED, NO_LED,     63, NO_LED,     64,     65,     66,     67 }
}, {
    // LED Index to Position
    // -- Matrix
    {  0,0  }, { 15,0  }, { 30,0  }, { 45,0  }, { 60,0  }, { 75,0  }, { 90,0  }, {105,0  }, {119,0  }, {134,0  }, {149,0  }, {164,0  }, {179,0  }, {202,0  }, {224,0  },
    {224,16 }, {207,24 }, {187,16 }, {172,16 }, {157,16 }, {142,16 }, {127,16 }, {112,16 }, { 97,16 }, { 82,16 }, { 67,16 }, { 52,16 }, { 37,16 }, { 22,16 }, {  4,16 },
    {  6,32 }, { 26,32 }, { 41,32 }, { 56,32 }, { 71,32 }, { 86,32 }, {101,32 }, {116,32 }, {131,32 }, {146,32 }, {161,32 }, {175,32 }, {190,32 },            {224,32 },
    {224,48 }, {209,48 }, {189,48 }, {168,48 }, {153,48 }, {138,48 }, {123,48 }, {108,48 }, { 93,48 }, { 78,48 }, { 63,48 }, { 49,48 }, { 34,48 }, { 19,48 }, {  2,48 },
    {  2,64 }, { 21,64 }, { 39,64 },                                  { 95,64 },                       {151,64 }, {170,64 },            {194,64 }, {209,64 }, {224,64 },
    // -- Left Underglow
    {  3,32 }, {  3,24 }, {  3,16 }, {  3,8  }, {  3,0  },
    {  2,0  }, {  2,8  }, {  2,16 }, {  2,24 }, {  2,32 },
    {  1,32 }, {  1,24 }, {  1,16 }, {  1,8  }, {  1,0  },
    {  0,0  }, {  0,8  }, {  0,16 }, {  0,24 }, {  0,32 },
    // -- Right Underglow
    {221,32 }, {221,24 }, {221,16 }, {221,8  }, {221,0  },
    {222,0  }, {222,8  }, {222,16 }, {222,24 }, {222,32 },
    {223,32 }, {223,24 }, {223,16 }, {223,8  }, {223,0  },
    {224,0  }, {224,8  }, {224,16 }, {224,24 }, {224,32 }
}, {
    // LED Index to Flags
    // -- Matrix
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,    1,
    1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 1,          1,       1, 1,    1, 1, 1,
    // -- Left Underglow
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    // -- Right Underglow
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2
}};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!user_config.backlight_enable) {
        for (uint8_t i=0; i<68; i++) {
            RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0);
        }
    }

    if (!user_config.sidelight_enable) {
        for (uint8_t i=68; i<108; i++) {
            RGB_MATRIX_INDICATOR_SET_COLOR(i, 0, 0, 0);
        }
    }
}
#endif
