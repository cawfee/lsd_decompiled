#ifndef GAME_COMMON_H
#define GAME_COMMON_H

#include "types.h"

typedef struct {
    /* File/CD driver class id: 0x13 selects the real CD driver (g_CLASS_1C92C /
       D_8006D4E8); 0x23 selects the no-op debug_file_driver used by a dev-only
       build, which never loads assets and therefore crashes. Passed to system
       Construct -> file_driver_set_class and read back through get_file_driver(). */
    s32 file_driver_class;
    /* Handed to dream_session_create; drives frame_setup(FrameSyncMode == 0, 1, 1)
       during dream session construction. */
    s32 frame_sync_mode;
    s32 enable_movie;
    s32 enable_logo;
    s32 enable_main_menu;
    /* Forwarded to dream_sys->vtable->dream_sys__set_unk_flag, which stores it
       into dream_sys->m_UnkFlag. That field is never read anywhere, so this flag
       has no effect in the retail build. */
    s32 unused_flag;
} game_config_t;

#endif