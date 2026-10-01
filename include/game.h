#ifndef GAME_COMMON_H
#define GAME_COMMON_H

#include "types.h"

/* File/CD driver class id. 0x13 selects the real CD driver (g_CLASS_1C92C /
   D_8006D4E8); 0x23 selects the no-op debug_file_driver used by a dev-only
   build, which never loads assets and therefore crashes. Passed to system
   Construct -> file_driver_set_class and read back through get_file_driver(). */
typedef enum {
    LSD_FILE_DRIVER_CD = 0x13,
    LSD_FILE_DRIVER_DEBUG = 0x23,
} lsd_file_driver_t;

typedef struct {
    lsd_file_driver_t m_FileDriverClass;
    /* Handed to dream_session_create; drives frame_setup(FrameSyncMode == 0, 1, 1)
       during dream session construction. */
    s32 m_FrameSyncMode;
    s32 m_EnableMovie;
    s32 m_EnableLogo;
    s32 m_EnableMainMenu;
    /* Forwarded to dream_sys->vtable->dream_sys__set_unk_flag, which stores it
       into dream_sys->m_UnkFlag. That field is never read anywhere, so this flag
       has no effect in the retail build. */
    s32 m_UnusedFlag;
} game_config_t;

#endif