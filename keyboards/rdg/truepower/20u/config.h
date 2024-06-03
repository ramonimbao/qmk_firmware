/* Copyright 2024 ramonimbao
 * Copyright 2023 sporkus
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

// --- EC matrix user configuration ---
// Actuation/release threshold = idle + offset
// Larger offset = More key travel distance, less sensitive
// Sensitivity can be adjusted using keycode: EC_AP_I/EC_AP_D
#define ACTUATION_OFFSET 150
#define RELEASE_OFFSET 170
#define DEFAULT_IDLE 500      // default value before tuning is completed
#define ECSM_DEBUG            // enables printing ec config and ADC readings */
#define EC_MATRIX            // allows ec code to be enabled with ifdef

// enables tuning ec config every power cycle, disable to reduce write cycle to flash
// #define ECSM_TUNE_ON_BOOT

// --- Misc ---
#define DEBUG_MATRIX_SCAN_RATE

// --- Pin configuration ---
#define MATRIX_ROWS 6
#define MATRIX_COLS 4
#define EC_MATRIX_ROWS 6
#define EC_MATRIX_COLS 4

#define EC_MATRIX_ROW_PINS \
    { B9, B3, B4, B5, B6, B7 }

/* offset the second multiplexer channel by 8 */
#define EC_MATRIX_COL_CHANNELS \
    { \
        4,  6,  7,  5,  0,  1,  2,  3 \
    }

#define MUX_SEL_PINS \
    { A5, A6, A7 }

#define MUX_EN_PINS \
    { B1 }

#define DISCHARGE_PIN B0 // opamp v+/mux output
#define ANALOG_PORT A3   // opamp v_out/adc

// // extra list of direct pins to read
// #define EXTRA_SWITCHES 1                      // number of extra switches
// #define EXTRA_SWITCH_ROW (MATRIX_ROWS - 1)    // the last row
// #define EXTRA_SWITCH_PINS {B3}

// --- Persistent Storage config ---
// Data size is in bytes. uint16_t = 2 bytes
// data block size needs to be uint16_t array length * 2
// Two addition words for actuation offsets and one byte for configuration check
#define EECONFIG_KB_DATA_SIZE ((MATRIX_ROWS * MATRIX_COLS + 2) * 2 + 1)


// --- RGB stuff ---
#define WS2812_SPI_DRIVER SPID2
#define WS2812_SPI_MOSI_PAL_MODE 0
#define WS2812_SPI_SCK_PIN B13
#define WS2812_SPI_SCK_PAL_MODE 0
#define WS2812_EXTERNAL_PULLUP
#define RGB_MATRIX_LED_COUNT 1
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
