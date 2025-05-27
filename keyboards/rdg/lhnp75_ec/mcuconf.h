// Copyright 2025 Ramon Imbao (@ramonimbao)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE

// #undef STM32_SPI_USE_SPI2
// #define STM32_SPI_USE_SPI2 TRUE

#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE

#undef STM32_ST_USE_TIMER
#define STM32_ST_USE_TIMER 15

#undef STM32_PWR_CR3
#define STM32_PWR_CR3 (PWR_CR3_EIWF | PWR_CR3_UCPD_DBDIS)
