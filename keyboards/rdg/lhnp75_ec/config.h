// Copyright 2025 Ramon Imbao (@ramonimbao)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// --- EC matrix user configuration ---
// Actuation/release threshold = idle + offset
// Larger offset = More key travel distance, less sensitive
// Sensitivity can be adjusted using keycode: EC_AP_I/EC_AP_D
#define ACTUATION_OFFSET 150
#define RELEASE_OFFSET 170
#define DEFAULT_IDLE 500      // default value before tuning is completed
// #define ECSM_DEBUG            // enables printing ec config and ADC readings */
#define EC_MATRIX            // allows ec code to be enabled with ifdef

// enables tuning ec config every power cycle, disable to reduce write cycle to flash
// #define ECSM_TUNE_ON_BOOT

// --- Misc ---
// #define DEBUG_MATRIX_SCAN_RATE

// --- Pin configuration ---
#define MATRIX_ROWS 7
#define MATRIX_COLS 16
#define EC_MATRIX_ROWS 7
#define EC_MATRIX_COLS 16

#define EC_MATRIX_ROW_PINS \
    { A10, B3, A4, A5, A6, A7, B4 }

/* offset the second multiplexer channel by 8 */
#define EC_MATRIX_COL_CHANNELS \
    { \
        6,  4,  7,  5,  3,  0,  1,  2, \
       11,  8,  9, 10, 12, 14, 15, 13 \
    }

#define MUX_SEL_PINS \
    { B5, B6, B7 }

#define MUX_EN_PINS \
    { A2, A3 }

#define DISCHARGE_PIN A1 // opamp v+/mux output
#define ANALOG_PORT A0   // opamp v_out/adc

// // extra list of direct pins to read
// #define EXTRA_SWITCHES 1                      // number of extra switches
// #define EXTRA_SWITCH_ROW (MATRIX_ROWS - 1)    // the last row
// #define EXTRA_SWITCH_PINS {B3}

// --- Persistent Storage config ---
// Data size is in bytes. uint16_t = 2 bytes
// data block size needs to be uint16_t array length * 2
// Two addition words for actuation offsets and one byte for configuration check
#define EECONFIG_KB_DATA_SIZE ((MATRIX_ROWS * MATRIX_COLS + 2) * 2 + 1)

/* RGB */
// #define WS2812_PWM_COMPLEMENTARY_OUTPUT
// #define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 1
#define WS2812_PWM_PAL_MODE 2
#define WS2812_PWM_DMA_STREAM STM32_DMA1_STREAM5
#define WS2812_PWM_DMAMUX_ID STM32_DMAMUX1_TIM2_UP
#define WS2812_PWM_DMA_CHANNEL 5
#define WS2812_EXTERNAL_PULLUP

// #define WS2812_BITBANG_NOP_FUDGE 0.4
