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

// ANSI enter
// Full-sized backspace
// Full-sized left shift
// 6.25u bottom row
#define LAYOUT_ansi( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1e, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2d, \
    k30, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3e, \
    k40, k41, k42,           k46,           k4a, k4b, k4d, k4e \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, ___ }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, ___, k1e }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, ___, k2d, ___ }, \
    { k30, ___, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, ___, k3d, k3e }, \
    { k40, k41, k42, ___, ___, ___, k46, ___, ___, ___, k4a, k4b, ___, k4d, k4e }, \
}

// ISO enter
// Full-sized backspace
// Split left shift
// 6.25u bottom row
#define LAYOUT_iso( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c,  \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2d, k1e, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3e, \
    k40, k41, k42,           k46,           k4a, k4b, k4d, k4e \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, ___ }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, ___, k1e }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, ___, k2d, ___ }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, ___, k3d, k3e }, \
    { k40, k41, k42, ___, ___, ___, k46, ___, ___, ___, k4a, k4b, ___, k4d, k4e }, \
}

// Split backspace
// Split left shift
// Split spacebars
#define LAYOUT_all( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1e, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2d, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3e, \
    k40, k41, k42,      k44,      k46,      k48,      k4a, k4b, k4d, k4e \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, ___, k1e }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, ___, k2d, ___ }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, ___, k3d, k3e }, \
    { k40, k41, k42, ___, k44, ___, k46, ___, k48, ___, k4a, k4b, ___, k4d, k4e }, \
}
