#include "ec_f072_norgb.h"

void keyboard_post_init_kb(void) {
    #ifdef ECSM_TUNE_ON_BOOT
        ecsm_config.configured = 0;
        eeconfig_update_kb_datablock(&ecsm_config);
    #endif
    keyboard_post_init_user();
}
