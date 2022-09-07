/* Copyright 2022 Ramon Imbao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include "solder.h"

led_config_t g_led_config = {{
    // Key Matrix to LED Index
    {      0,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12,     13,     15 },
    {     31,     30,     29,     28,     27,     26,     25,     24,     23,     22,     21,     20,     19,     18,     16 },
    {     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     44,     45,     17 },
    {     61,     59,     58,     57,     56,     55,     54,     53,     52,     51,     50,     49,     48,     47,     46 },
    {     62,     63,     64, NO_LED, NO_LED, NO_LED,     65, NO_LED, NO_LED,     67,     68,     69,     70,     71, NO_LED }
}, {
    // LED Index to Position
    {  0,0  }, { 14,0  }, { 29,0  }, { 43,0  }, { 58,0  }, { 72,0  }, { 87,0  }, {101,0  }, {116,0  }, {130,0  }, {145,0  }, {159,0  }, {173,0  }, {188,0  }, {195,0  }, {202,0  }, {224,0  },
    {224,16 }, {199,16 }, {181,16 }, {166,16 }, {152,16 }, {137,16 }, {123,16 }, {108,16 }, { 94,16 }, { 79,16 }, { 65,16 }, { 51,16 }, { 36,16 }, { 22,16 }, {  4,16 },
    {  4,32 }, { 25,32 }, { 40,32 }, { 54,32 }, { 69,32 }, { 83,32 }, { 98,32 }, {112,32 }, {126,32 }, {141,32 }, {155,32 }, {170,32 }, {184,32 }, {193,32 }, {224,32 },
    {202,48 }, {182,48 }, {163,48 }, {148,48 }, {134,48 }, {119,48 }, {105,48 }, { 90,48 }, { 76,48 }, { 61,48 }, { 47,48 }, { 33,48 }, { 18,48 }, {  9,48 }, {  2,48 },
    {  2,64 }, { 20,64 }, { 38,64 }, { 92,64 }, {101,64 }, {146,64 }, {188,64 }, {202,64 }, {217,64 }, {224,64 }
}, {
    // LED Index to Flags
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    1, 1, 1, 4, 4, 1, 1, 1, 1, 1
}};
