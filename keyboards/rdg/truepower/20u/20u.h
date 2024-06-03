/* Copyright 2024 ramonimbao
 * Copyright 2023 sporkus
 * Copyright 2023 Cipulot
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
#include "ec_switch_matrix.h"

enum ec_keycodes {
    EC_AP_I = QK_KB_0,  // Increases actuation point (more travel)
    EC_AP_D,            // Decreases actuation point
    EC_CLR              // Reset EC config
};
