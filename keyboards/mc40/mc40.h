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

// Split right shift
// 1.25 - 1.25 - 2.25 - 1 - 2.75 - 1.25 - 1 - 1.25 bottom row
// Encoder pins exposed (k40 = ccw, k41 = cw)
#define LAYOUT_all( \
    k40,  k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k3a, \
    k33,  k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a,      \
    k41,  k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a,      \
          k30, k31, k32,      k34, k35, k36, k37, k38, k39            \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a }, \
    { k40, k41, ___, ___, ___, ___, ___, ___, ___, ___, ___ }, \
}
