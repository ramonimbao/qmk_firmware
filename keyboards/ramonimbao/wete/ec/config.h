/* Copyright 2022 Cipulot
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

#pragma once

#include "config_common.h"

#define MATRIX_COLS 16
#define MATRIX_ROWS 7

/* Custom matrix pins and port select array */
#define MATRIX_ROW_PINS \
    { B3, B4, B1, A2, A1, A0, A15 }
#define MATRIX_COL_CHANNELS \
    {  4,  3,  2,  5,  0,  6,  1,  7, \
      12, 13, 14, 11, 15,  8,  9, 10 }
#define MUX_SEL_PINS \
    { A7, A6, A5 }

/* Hardware peripherals pins */
#define APLEX_EN_PIN_0 A4
#define APLEX_EN_PIN_1 B0
#define DISCHARGE_PIN B12
#define ANALOG_PORT A3

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
//#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define DEBUG_MATRIX_SCAN_RATE
