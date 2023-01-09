#include QMK_KEYBOARD_H
#include "via.h"
#include "eeprom_driver.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(1),
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_APP,  KC_RCTL
    ),
    [1] = LAYOUT_60(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [2] = LAYOUT_60(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [3] = LAYOUT_60(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
};

enum via_indicator_value {
    id_caps_lock_toggle_on_num_lock    = 1,
    id_caps_lock_toggle_on_caps_lock   = 2,
    id_caps_lock_toggle_on_scroll_lock = 3,
    id_caps_lock_toggle_on_layer_0     = 4,
    id_caps_lock_toggle_on_layer_1     = 5,
    id_caps_lock_toggle_on_layer_2     = 6,
    id_caps_lock_toggle_on_layer_3     = 7
};

uint8_t g_value[7] = {0, 0, 0, 0, 0, 0, 0};
uint8_t highest_layer = 0;

void indicator_config_set_value(uint8_t* data) {
    // data = [ value_id, value_data ]
    uint8_t* value_id   = &(data[0]);
    uint8_t* value_data = &(data[1]);
    switch (*value_id) {
        case id_caps_lock_toggle_on_num_lock:
            g_value[0] = *value_data;
            break;
        case id_caps_lock_toggle_on_caps_lock:
            g_value[1] = *value_data;
            break;
        case id_caps_lock_toggle_on_scroll_lock:
            g_value[2] = *value_data;
            break;
        case id_caps_lock_toggle_on_layer_0:
            g_value[3] = *value_data;
            break;
        case id_caps_lock_toggle_on_layer_1:
            g_value[4] = *value_data;
            break;
        case id_caps_lock_toggle_on_layer_2:
            g_value[5] = *value_data;
            break;
        case id_caps_lock_toggle_on_layer_3:
            g_value[6] = *value_data;
            break;
    }
}

void indicator_config_get_value(uint8_t* data) {
    // data = [ value_id, value_data ]
    uint8_t* value_id   = &(data[0]);
    uint8_t* value_data = &(data[1]);
    switch (*value_id) {
        case id_caps_lock_toggle_on_num_lock:
            *value_data = g_value[0];
            break;
        case id_caps_lock_toggle_on_caps_lock:
            *value_data = g_value[1];
            break;
        case id_caps_lock_toggle_on_scroll_lock:
            *value_data = g_value[2];
            break;
        case id_caps_lock_toggle_on_layer_0:
            *value_data = g_value[3];
            break;
        case id_caps_lock_toggle_on_layer_1:
            *value_data = g_value[4];
            break;
        case id_caps_lock_toggle_on_layer_2:
            *value_data = g_value[5];
            break;
        case id_caps_lock_toggle_on_layer_3:
            *value_data = g_value[6];
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
    { 6, 32 },
}, {
    // LED Index to Flags
    LED_FLAG_INDICATOR
}};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!((host_keyboard_led_state().num_lock && g_value[0]) ||
        (host_keyboard_led_state().caps_lock && g_value[1]) ||
        (host_keyboard_led_state().scroll_lock && g_value[2]) ||
        (highest_layer == 0 && g_value[3]) ||
        (highest_layer == 1 && g_value[4]) ||
        (highest_layer == 2 && g_value[5]) ||
        (highest_layer == 3 && g_value[6]))) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        highest_layer = 0;
        break;
    case 1:
        highest_layer = 1;
        break;
    case 2:
        highest_layer = 2;
        break;
    case 3:
        highest_layer = 3;
        break;
    default: //  for any other layers, or the default layer
        highest_layer = 0;
        break;
    }
  return state;
}
#endif
