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
#define LAYOUT_all( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, k0f, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c,      k1e, k1f, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,      k2d,      k2f, \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c,      k3e, k3f, \
    k40,      k42,                k46,                     k4b, k4c,      k4e, k4f  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, k0f }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, ___, k1e, k1f }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, ___, k2d, ___, k2f }, \
    { k30, ___, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, ___, k3e, k3f }, \
    { k40, ___, k42, ___, ___, ___, k46, ___, ___, ___, ___, k4b, k4c, ___, k4e, k4f }, \
}
