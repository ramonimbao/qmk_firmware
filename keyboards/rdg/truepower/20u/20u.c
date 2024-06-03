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

#include "20u.h"

extern ecsm_config_t ecsm_config;

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case EC_AP_I:
                ecsm_ap_inc();
                return false;
            case EC_AP_D:
                ecsm_ap_dec();
                return false;
            case EC_CLR:
                ecsm_eeprom_clear();
                return false;
        }
    }

    return process_record_user(keycode, record);
};


void keyboard_post_init_kb(void) {
    #ifdef ECSM_TUNE_ON_BOOT
        ecsm_config.configured = 0;
        eeconfig_update_kb_datablock(&ecsm_config);
    #endif
    keyboard_post_init_user();
}
