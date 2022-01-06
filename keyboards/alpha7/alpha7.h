// Copyright 2021 Ramon Imbao (@ramonimbao)
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

// 2u Backspace
// ANSI enter
// Encoder pins not exposed
#define LAYOUT_ansi( \
    k00, k10, k01, k11, k02, k12, k03, k13, k04, k14, k05, k15, k06, k16, k07, \
    k20, k30, k21, k31, k22, k32, k23, k33, k24, k34, k25, k35, k26, k36, k27, \
    k40, k50, k41, k51, k42, k52, k43, k53, k44, k54, k45, k55, k46, k56, k47, \
    k60, k70, k61, k71, k62, k72, k63, k73, k64, k74, k65, k75, k66,      k67, \
    k80,      k81, k91, k82, k92, k83, k93, k84, k94, k85, k95, k86, k96,      \
    ka0,      ka1,                ka3,                ka5, kb5, ka6, kb6, ka7  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07 }, \
    { k10, k11, k12, k13, k14, k15, k16, ___ }, \
    { k20, k21, k22, k23, k24, k25, k26, k27 }, \
    { k30, k31, k32, k33, k34, k35, k36, ___ }, \
    { k40, k41, k42, k43, k44, k45, k46, k47 }, \
    { k50, k51, k52, k53, k54, k55, k56, ___ }, \
    { k60, k61, k62, k63, k64, k65, k66, k67 }, \
    { k70, k71, k72, k73, k74, k75, ___, ___ }, \
    { k80, k81, k82, k83, k84, k85, k86, ___ }, \
    { ___, k91, k92, k93, k94, k95, k96, ___ }, \
    { ka0, ka1, ___, ka3, ___, ka5, ka6, ka7 }, \
    { ___, ___, ___, ___, ___, kb5, kb6, ___ }, \
    { ___, ___, ___, ___, ___, ___, ___, ___ }  \
}

// 2u backspace
// ISO enter
// Encoder pins not exposed
#define LAYOUT_iso( \
    k00, k10, k01, k11, k02, k12, k03, k13, k04, k14, k05, k15, k06, k16, k07, \
    k20, k30, k21, k31, k22, k32, k23, k33, k24, k34, k25, k35, k26,      k27, \
    k40, k50, k41, k51, k42, k52, k43, k53, k44, k54, k45, k55, k46, k56, k36, k47, \
    k60, k70, k61, k71, k62, k72, k63, k73, k64, k74, k65, k75, k66,      k67, \
    k80,      k81, k91, k82, k92, k83, k93, k84, k94, k85, k95, k86, k96,      \
    ka0,      ka1,                ka3,                ka5, kb5, ka6, kb6, ka7  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07 }, \
    { k10, k11, k12, k13, k14, k15, k16, ___ }, \
    { k20, k21, k22, k23, k24, k25, k26, k27 }, \
    { k30, k31, k32, k33, k34, k35, k36, ___ }, \
    { k40, k41, k42, k43, k44, k45, k46, k47 }, \
    { k50, k51, k52, k53, k54, k55, k56, ___ }, \
    { k60, k61, k62, k63, k64, k65, k66, k67 }, \
    { k70, k71, k72, k73, k74, k75, ___, ___ }, \
    { k80, k81, k82, k83, k84, k85, k86, ___ }, \
    { ___, k91, k92, k93, k94, k95, k96, ___ }, \
    { ka0, ka1, ___, ka3, ___, ka5, ka6, ka7 }, \
    { ___, ___, ___, ___, ___, kb5, kb6, ___ }, \
    { ___, ___, ___, ___, ___, ___, ___, ___ }  \
}

// Split Backspace
// ANSI enter
// Encoder pins exposed
#define LAYOUT_all( \
    k00, k10, k01, k11, k02, k12, k03, k13, k04, k14, k05, k15, k06, k16, k07, \
    k20, k30, k21, k31, k22, k32, k23, k33, k24, k34, k25, k35, k26, k36, k76, k27, \
    k40, k50, k41, k51, k42, k52, k43, k53, k44, k54, k45, k55, k46, k56, k47, \
    k60, k70, k61, k71, k62, k72, k63, k73, k64, k74, k65, k75, k66,      k67, \
    k80,      k81, k91, k82, k92, k83, k93, k84, k94, k85, k95, k86, k96,      \
    ka0,      ka1,                ka3,                ka5, kb5, ka6, kb6, ka7, \
    enccw, encw \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07 }, \
    { k10, k11, k12, k13, k14, k15, k16, ___ }, \
    { k20, k21, k22, k23, k24, k25, k26, k27 }, \
    { k30, k31, k32, k33, k34, k35, k36, ___ }, \
    { k40, k41, k42, k43, k44, k45, k46, k47 }, \
    { k50, k51, k52, k53, k54, k55, k56, ___ }, \
    { k60, k61, k62, k63, k64, k65, k66, k67 }, \
    { k70, k71, k72, k73, k74, k75, k76, ___ }, \
    { k80, k81, k82, k83, k84, k85, k86, ___ }, \
    { ___, k91, k92, k93, k94, k95, k96, ___ }, \
    { ka0, ka1, ___, ka3, ___, ka5, ka6, ka7 }, \
    { ___, ___, ___, ___, ___, kb5, kb6, ___ }, \
    { enccw, encw, ___, ___, ___, ___, ___, ___, } \
}
