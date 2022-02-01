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

// Split backspace
// Split left shift
// Split right shift
// ANSI enter layout
#define LAYOUT_all( \
    k00,      k01, k11, k02, k12, k03, k13, k04, k14, k05, k15, k06, k16, k07, k17, k08, k18, \
    k20, k30, k21, k31, k22, k32, k23, k33, k24, k34, k25, k35, k26, k36, k27, k37, k28, k38, \
    k40, k50, k41, k51, k42, k52,      k53, k44, k54, k45, k55, k46, k56, k47, k57, k48, k58, \
    k60, k70, k61, k71, k62, k72,                     k65, k75, k66, k76, k67, k77, k68,      \
    k80, k90, k81, k91, k82, k92, k83,      k84,      k85, k95, k86, k96, k87, k97, k88, k98, \
    ka0,           kb1,      kb2,      kb3, ka4, kb4, ka5,      ka6,                     kb8  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08 }, \
    { ___, k11, k12, k13, k14, k15, k16, k17, k18 }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28 }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38 }, \
    { k40, k41, k42, ___, k44, k45, k46, k47, k48 }, \
    { k50, k51, k52, k53, k54, k55, k56, k57, k58 }, \
    { k60, k61, k62, ___, ___, k65, k66, k67, k68 }, \
    { k70, k71, k72, ___, ___, k75, k76, k77, ___ }, \
    { k80, k81, k82, k83, k84, k85, k86, k87, k88 }, \
    { k90, k91, k92, ___, ___, k95, k96, k97, k98 }, \
    { ka0, ___, ___, ___, ka4, ka5, ka6, ___, ___ }, \
    { ___, kb1, kb2, kb3, kb4, ___, ___, ___, kb8 }, \
}
