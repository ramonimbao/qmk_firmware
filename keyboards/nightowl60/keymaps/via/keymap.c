// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "via.h"
#include "eeprom_driver.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(1),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
    ),
    [1] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, KC_DOWN,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
};

#ifdef RGB_MATRIX_ENABLE
enum via_indicator_value {
    id_caps_lock_toggle_on_num_lock    = 1,
    id_caps_lock_toggle_on_caps_lock,
    id_caps_lock_toggle_on_scroll_lock,
    id_caps_lock_toggle_on_ctrl,
    id_caps_lock_toggle_on_alt,
    id_caps_lock_toggle_on_shift,
    id_caps_lock_toggle_on_layer_0,
    id_caps_lock_toggle_on_layer_1,
    id_caps_lock_toggle_on_layer_2,
    id_caps_lock_toggle_on_layer_3,
};

enum lock_indicators {
    lock_caps = 0,
};

uint32_t g_value[1] = { 0 };

void indicator_config_set_value(uint8_t* data) {
    // data = [ value_id, value_data ]
    uint8_t* value_id   = &(data[0]);
    uint8_t* value_data = &(data[1]);
    switch (*value_id) {
        case id_caps_lock_toggle_on_num_lock:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_num_lock);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_num_lock);
            }
            break;
        case id_caps_lock_toggle_on_caps_lock:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_caps_lock);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_caps_lock);
            }
            break;
        case id_caps_lock_toggle_on_scroll_lock:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_scroll_lock);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_scroll_lock);
            }
            break;
        case id_caps_lock_toggle_on_ctrl:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_ctrl);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_ctrl);
            }
            break;
        case id_caps_lock_toggle_on_alt:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_alt);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_alt);
            }
            break;
        case id_caps_lock_toggle_on_shift:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_shift);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_shift);
            }
            break;
        case id_caps_lock_toggle_on_layer_0:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_layer_0);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_layer_0);
            }
            break;
        case id_caps_lock_toggle_on_layer_1:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_layer_1);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_layer_1);
            }
            break;
        case id_caps_lock_toggle_on_layer_2:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_layer_2);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_layer_2);
            }
            break;
        case id_caps_lock_toggle_on_layer_3:
            if (*value_data) {
                g_value[lock_caps] |= (1 << id_caps_lock_toggle_on_layer_3);
            } else {
                g_value[lock_caps] &= ~(1 << id_caps_lock_toggle_on_layer_3);
            }
            break;
    }
}

void indicator_config_get_value(uint8_t* data) {
    // data = [ value_id, value_data ]
    uint8_t* value_id   = &(data[0]);
    uint8_t* value_data = &(data[1]);
    switch (*value_id) {
        case id_caps_lock_toggle_on_num_lock:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_num_lock) ? 1 : 0;
            break;
        case id_caps_lock_toggle_on_caps_lock:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_caps_lock) ? 1 : 0;
            break;
        case id_caps_lock_toggle_on_scroll_lock:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_scroll_lock) ? 1 : 0;
            break;
        case id_caps_lock_toggle_on_ctrl:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_ctrl) ? 1 : 0;
            break;
        case id_caps_lock_toggle_on_alt:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_alt) ? 1 : 0;
            break;
        case id_caps_lock_toggle_on_shift:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_shift) ? 1 : 0;
            break;
        case id_caps_lock_toggle_on_layer_0:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_layer_0) ? 1 : 0;
            break;
        case id_caps_lock_toggle_on_layer_1:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_layer_1) ? 1 : 0;
            break;
        case id_caps_lock_toggle_on_layer_2:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_layer_2) ? 1 : 0;
            break;
        case id_caps_lock_toggle_on_layer_3:
            *value_data = g_value[lock_caps] & (1 << id_caps_lock_toggle_on_layer_3) ? 1 : 0;
            break;
    }
}

void indicator_config_load(void) {
    eeprom_read_block(&g_value, ((void*)VIA_EEPROM_CUSTOM_CONFIG_ADDR), VIA_EEPROM_CUSTOM_CONFIG_SIZE);
}

void indicator_config_save(void) {
    eeprom_update_block(&g_value, ((void*)VIA_EEPROM_CUSTOM_CONFIG_ADDR), VIA_EEPROM_CUSTOM_CONFIG_SIZE);
}

void via_init_kb(void) {
    if (via_eeprom_is_valid()) {
        indicator_config_load();
    } else {
        indicator_config_save();
    }
}

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *channel_id        = &(data[1]);
    uint8_t *value_id_and_data = &(data[2]);

    if (*channel_id == id_custom_channel) {
        switch (*command_id) {
            case id_custom_set_value:
                indicator_config_set_value(value_id_and_data);
                break;
            case id_custom_get_value:
                indicator_config_get_value(value_id_and_data);
                break;
            case id_custom_save:
                indicator_config_save();
                break;
            default:
                // Unhandled message.
                *command_id = id_unhandled;
                break;
        }
        return;
    }

    // Return the unhandled state
    *command_id = id_unhandled;

    // DO NOT call raw_hid_send(data,length) here, let caller do this
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint32_t highest_layer = get_highest_layer(layer_state);

    if (!((host_keyboard_led_state().num_lock && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_num_lock))) ||
        (host_keyboard_led_state().caps_lock && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_caps_lock))) ||
        (host_keyboard_led_state().scroll_lock && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_scroll_lock))) ||
        ((get_mods() & MOD_MASK_CTRL) && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_ctrl))) ||
        ((get_mods() & MOD_MASK_ALT) && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_alt))) ||
        ((get_mods() & MOD_MASK_SHIFT) && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_shift))) ||
        (highest_layer == 0 && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_layer_0))) ||
        (highest_layer == 1 && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_layer_1))) ||
        (highest_layer == 2 && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_layer_2))) ||
        (highest_layer == 3 && (g_value[lock_caps] & (1 << id_caps_lock_toggle_on_layer_3))))) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
    }

    return true;
}
#endif
