// Copyright 2023 Ramon Imbao (@ramonimbao)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef STM32_SPI_USE_SPI2
#define STM32_SPI_USE_SPI2 TRUE

// #undef STM32_I2C_USE_I2C2
// #define STM32_I2C_USE_I2C2 TRUE

// // From: https://github.com/ChibiOS/ChibiOS/blob/master/demos/STM32/RT-STM32F072-DISCOVERY/cfg/mcuconf.h#L131-L132
// #define STM32_I2C_I2C2_RX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 5)
// #define STM32_I2C_I2C2_TX_DMA_STREAM        STM32_DMA_STREAM_ID(1, 4)
