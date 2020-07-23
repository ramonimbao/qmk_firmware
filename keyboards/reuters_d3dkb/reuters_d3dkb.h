/* Copyright 2019 Ramon Imbao
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

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define XXX KC_NO

/*
#define LAYOUT( \
    k00, k10, k01, k11, k02, k12, k03,   k13, k04,   k14, k05,   k15, k06,     k16,     k07,    k09, k19, k0a, k1a, \
         k20, k30, k21, k32, k22, k33,   k23, k24,     k34,       k25,     k36, k26,    k37,       k29,     k3a,    \
    \
    k50, k40, k41, k51, k42, k52, k43, k53, k44, k54, k45, k55, k46, k56,   k47,      k57, k48, k58,   k49, k59, k4a, k5a, \
        k60,    k70, k61, k71, k62, k72, k63, k73, k64, k74, k65, k75, k66,  k76,     k67, k77, k68,   k79, k69, k7a,      \
         k80,    k90, k81, k91, k82, k92, k83, k93, k84, k94, k85, k95,    k96,       k87, k97, k88,   k99, k89, k9a, k8a, \
    ka0,   kb0,    ka1, kb1, ka2, kb2, ka3, kb3, ka4, kb4, ka5, kb5,     kb6,         ka7, kb7, ka8,   kb9, ka9, kba,      \
       kd0,   kd1, kc1, kc2,             kd3,            kc4, kd5, kc5, kd6, kc6,     kd7, kc7, kd8,   kc8, kd9,     kca   \
    ) { \
        {k00, k01, k02, k03, k04, k05, k06, k07, XXX, k09, k0a}, \
        {k10, k11, k12, k13, k14, k15, k16, XXX, XXX, k19, k1a}, \
        {k20, k21, k22, k23, k24, k25, k26, XXX, XXX, k29, XXX}, \
        {k30, XXX, k32, k33, k34, XXX, k36, k37, XXX, XXX, k3a}, \
        {k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a}, \
        {k50, k51, k52, k53, k54, k55, k56, k57, k56, k59, k5a}, \
        {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, XXX}, \
        {k70, k71, k72, k73, k74, k75, k76, k77, XXX, k79, k7a}, \
        {k80, k81, k82, k83, k84, k85, XXX, k87, k88, k89, k8a}, \
        {k90, k91, k92, k93, k94, k95, k96, k97, XXX, k99, k9a}, \
        {ka0, ka1, ka2, ka3, ka4, ka5, XXX, ka7, ka8, ka9, XXX}, \
        {kb0, kb1, kb2, kb3, kb4, kb5, kb6, kb7, XXX, kb9, kba}, \
        {XXX, kc1, kc2, XXX, kc4, kc5, kc6, kc7, kc8, XXX, kca}, \
        {kd0, kd1, XXX, kd3, XXX, kd5, kd6, kd7, kd8, kd9, XXX}, \
    }
*/


#define LAYOUT( \
    k00, k01, k10, k11, k20, k21, k30,   k31, k40,   k41, k50,   k51, k60,     k61,     k70,    k90, k91, ka0, ka1, \
         k02, k03, k12, k23, k22, k33,   k32, k43,     k42,       k53,     k63, k62,    k73,       k92,     ka3,    \
    \
    k04, k05, k14, k15, k24, k25, k34, k35, k44, k45, k54, k55, k64, k65,   k74,      k75, k84, k85,   k94, k95, ka4, ka5, \
        k06,    k07, k16, k17, k26, k27, k36, k37, k46, k47, k56, k57, k66,  k67,     k76, k77, k86,   k97, k96, ka7,      \
         k08,    k09, k18, k19, k28, k29, k38, k39, k48, k49, k58, k59,    k69,       k78, k79, k88,   k99, k98, ka9, ka8, \
    k0a,   k0b,    k1a, k1b, k2a, k2b, k3a, k3b, k4a, k4b, k5a, k5b,     k6b,         k7a, k7b, k8a,   k9b, k9a, kab,      \
       k0d,   k1c, k1d, k2c,             k3d,            k4c, k5d, k5c, k6d, k6c,     k7d, k7c, k8d,   k8c, k9d,     kac   \
    ) \
    { \
        {k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, XXX, k0d}, \
        {k10, k11, k12, XXX, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d}, \
        {k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, XXX}, \
        {k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, XXX, k3d}, \
        {k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, XXX}, \
        {k50, k51, XXX, k53, k54, k55, k56, k57, k58, k59, k5a, k5b, k5c, k5d}, \
        {k60, k61, k62, k63, k64, k65, k66, k67, XXX, k69, XXX, k6b, k6c, k6d}, \
        {k70, XXX, XXX, k73, k74, k75, k76, k77, k78, k79, k7a, k7b, k7c, k7d}, \
        {XXX, XXX, XXX, XXX, k84, k85, k86, XXX, k88, XXX, k8a, XXX, k8c, k8d}, \
        {k90, k91, k92, XXX, k94, k95, k96, k97, k98, k99, k9a, k9b, XXX, k9d}, \
        {ka0, ka1, XXX, ka3, ka4, ka5, XXX, ka7, ka8, ka9, XXX, kab, kac, XXX}, \
    }
    
