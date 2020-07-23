/* Copyright 2019 Ramon Imbao
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

#include <quantum.h>

enum custom_keycodes {
    DESK_PC1 = SAFE_RANGE,
    DESK_PC2,
    PREV_WORKSPACE,
    NEXT_WORKSPACE,
    PREV_COMPONENT,
    NEXT_COMPONENT,
    D3000_CONV,
    TRANSFER,
    TICKET,
    END_CONTACT,
    CONFIRM,
    RED_RESET,
    PROMPT,
    CONV_UP,
    CONV_DOWN,
    CAPTURE,
    NTG_THERE,
    I_SELL,
    BELL,
    LOGOFF,
    I_BUY,
    ACCEPT,
    CONTACT,
    INTERRUPT,
    DEAL,
    LLEFT,
    RRIGHT,
};

static bool pc1 = false;
static bool pc2 = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //[0] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3),
    [0] = LAYOUT(
        // Top Half
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,       PREV_WORKSPACE, NEXT_WORKSPACE,   DESK_PC1, DESK_PC2,   TRANSFER, TICKET,        CONFIRM,          CONV_UP,    CAPTURE, NTG_THERE,    BELL, LOGOFF,
                KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,    PREV_COMPONENT, NEXT_COMPONENT,         D3000_CONV,         END_CONTACT,      RED_RESET, PROMPT,   CONV_DOWN,       I_SELL,              I_BUY,
        // Bottom Half
        KC_TAB, KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPACE,    KC_PSCR, KC_SLCK, KC_PAUSE,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
               ACCEPT,      KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,   KC_INS, KC_HOME, KC_PGUP,     KC_KP_7, KC_KP_8, KC_KP_9,
                 CONTACT,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOT, KC_ENTER,     KC_DEL, KC_END, KC_PGDN,      KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS,
        KC_CLCK,    KC_LSFT,   KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLASH,    KC_RSFT,      LLEFT, KC_UP, RRIGHT,         KC_KP_1, KC_KP_2, KC_KP_3,
            INTERRUPT,      KC_LCTL, KC_NO, KC_LALT,    KC_SPACE,     KC_RALT, KC_RGUI, KC_APP, KC_RCTL, KC_NO,      KC_LEFT, KC_DOWN, KC_RIGHT,   KC_KP_0, KC_KP_DOT, KC_KP_ENTER
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PREV_WORKSPACE:
            // Win + Shift + Left
            if (record->event.pressed) {
                register_code16(LSFT(LGUI(KC_LEFT)));
            } else {
                unregister_code16(LSFT(LGUI(KC_LEFT)));
            }

        case NEXT_WORKSPACE:
            // Win + Shift + Right
            if (record->event.pressed) {
                register_code16(LSFT(LGUI(KC_RIGHT)));
            } else {
                unregister_code16(LSFT(LGUI(KC_RIGHT)));
            }
            break;

        case PREV_COMPONENT:
            // Alt + Shift + Tab
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
                tap_code(KC_TAB);
            } else {
                unregister_mods(MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT));
            }
            break;
        case NEXT_COMPONENT:
            // Alt + Tab
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LALT));
                tap_code(KC_TAB);
            } else {
                unregister_mods(MOD_BIT(KC_LALT));
            }
            break;

        case DESK_PC1:
            // Currently does nothing but toggle the LED
            if (record->event.pressed) {
                pc1 = !pc1;
                if (pc1) {
                    #ifdef LED_DESK_PC1
                    writePinLow(LED_DESK_PC1);
                    #endif
                } else {
                    #ifdef LED_DESK_PC1
                    writePinHigh(LED_DESK_PC1);
                    #endif
                }
            }
            break;
        case DESK_PC2:
            // Currently does nothing but toggle the LED
            if (record->event.pressed) {
                pc2 = !pc2;
                if (pc2) {
                    #ifdef LED_DESK_PC2
                    writePinLow(LED_DESK_PC2);
                    #endif
                } else {
                    #ifdef LED_DESK_PC2
                    writePinHigh(LED_DESK_PC2);
                    #endif
                }
            }
            break;

        case D3000_CONV:
            break;

        case TRANSFER:
            break;
        case TICKET:
            break;

        case END_CONTACT:
            // Ctrl + W
            if (record->event.pressed) {
                register_code16(LCTL(KC_W));
            } else {
                unregister_code16(LCTL(KC_W));
            }
            break;

        case CONFIRM:
            break;

        case RED_RESET:
            break;
        case PROMPT:
            break;

        case CONV_UP:
            break;
        case CONV_DOWN:
            break;

        case CAPTURE:
            // Win + Shift + S
            if (record->event.pressed) {
                register_code16(LWIN(LSFT(KC_S)));
            } else {
                unregister_code16(LWIN(LSFT(KC_S)));
            }
            break;
        case NTG_THERE:
            break;

        case I_SELL:
            break;

        case BELL:
            break;
        case LOGOFF:
            // Win + L (Nah, never mind, lol.)
            /*if (record->event.pressed) {
                register_code16(LWIN(KC_L));
            } else {
                unregister_code16(LWIN(KC_L));
            }*/
            break;

        case I_BUY:
            break;

        case INTERRUPT:
            break;

        case DEAL:
            break;

        case LLEFT:
            // Ctrl + Left
            if (record->event.pressed) {
                register_code16(LCTL(KC_LEFT));
            } else {
                unregister_code16(LCTL(KC_LEFT));
            }
            break;
        case RRIGHT:
            // Ctrl + Right
            if (record->event.pressed) {
                register_code16(LCTL(KC_RIGHT));
            } else {
                unregister_code16(LCTL(KC_RIGHT));
            }
            break;
    }
    return true;
}

void keyboard_pre_init_user(void) {
#ifdef LED_NUMLOCK
    setPinOutput(LED_NUMLOCK);
#endif
#ifdef LED_CAPSLOCK
    setPinOutput(LED_CAPSLOCK);
#endif
#ifdef LED_SCROLLLOCK
    setPinOutput(LED_SCROLLLOCK);
#endif
#ifdef LED_DESK_PC1
    setPinOutput(LED_DESK_PC1);
#endif
#ifdef LED_DESK_PC2
    setPinOutput(LED_DESK_PC2);
#endif
#ifdef LED_D3000_CONV
    setPinOutput(LED_D3000_CONV);
#endif
#ifdef LED_ALARM
    setPinOutput(LED_ALARM);
#endif
}

void led_set_user(uint8_t usb_led) {
    #ifdef LED_NUMLOCK
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinLow(LED_NUMLOCK);
    } else {
        writePinHigh(LED_NUMLOCK);
    }
    #endif

    #ifdef LED_CAPSLOCK
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinLow(LED_CAPSLOCK);
    } else {
        writePinHigh(LED_CAPSLOCK);
    }
    #endif

    #ifdef LED_SCROLLLOCK
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        writePinLow(LED_SCROLLLOCK);
    } else {
        writePinHigh(LED_SCROLLLOCK);
    }
    #endif
}
