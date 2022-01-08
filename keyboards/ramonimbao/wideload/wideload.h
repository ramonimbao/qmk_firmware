// Copyright 2022 Ramon Imbao (@ramonimbao)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define ___ KC_NO

// ANSI enter
// Split left shift
// Split right shift
// Split spacebar
// 6.25u bottom row
// Split 2u Numpad 0
// Encoder exposed
#define LAYOUT_all( \
    k00,   k10, k01, k11,   k02, k12, k03, k13, k04, k14, k05, k15, k06, k16, k07, k17, k08, k18,   k09, k19, k0a,   k1a, k0b, k1b, \
           k30, k21, k31,   k22, k32, k23, k33, k24, k34, k25, k35, k26, k36, k27, k37, k28,        k29, k39, k2a,   k3a, k2b, k3b, \
           k50, k41, k51,   k42, k52, k43, k53, k44, k54, k45, k55, k46, k56, k47, k57, k48, k58,        k59,        k5a, k4b, k5b, \
           k70, k61, k71,   k62, k72, k63,      k64,      k65,      k66,      k67, k77, k68, k78,   k69, k79, k6a,   k7a, k6b, k7b, \
    k40, k60 \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b }, \
    { ___, k31, k32, k33, k34, k35, k36, k37, ___, k39, k3a, k3b }, \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48, ___, ___, k4b }, \
    { k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b }, \
    { k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a, k6b }, \
    { k70, k71, k72, ___, ___, ___, ___, k77, k78, k79, k7a, k7b }, \
}
