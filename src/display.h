#ifndef LSD_DISPLAY_H
#define LSD_DISPLAY_H

#include <common.h>

#include "base_class.h"

typedef struct display display_t;
typedef struct display_vtable display_vtable_t;

struct display_vtable {
    /* 0x000 8006c070 */ u32 type_id;
    /* 0x004 8006c074 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006c078 */ void (*Construct)(display_t *);
    /* 0x00C 8006c07c */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006c080 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006c084 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006c088 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006c08c */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006c090 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006c094 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006c098 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006c09c */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006c0a0 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006c0a4 */ void (*Nop)(base_class_t *);
    /* 0x038 8006c0a8 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006c0ac */ void (*Unk14)(display_t *);
    /* 0x040 8006c0b0 */ void (*display_reset)(display_t *);
    /* 0x044 8006c0b4 */ void (*display_init_gs)(display_t *, vec2d_t *, s32);
    /* 0x048 8006c0b8 */ void (*display_do_vsync)(display_t *);
    /* 0x04C 8006c0bc */ void (*display_reset_vsync_count)(display_t *);
    /* 0x050 8006c0c0 */ void (*display_swap_disp_buffer)(display_t *);
    /* 0x054 8006c0c4 */ s32 (*display_get_active_buffer)(display_t *);
    /* 0x058 8006c0c8 */ void (*display_load_image)(display_t *, s16 *, s32);
    /* 0x05C 8006c0cc */ void (*display_store_image)(display_t *, s32, s16 *);
    /* 0x060 8006c0d0 */ s32 (*Unk23)(display_t *);
    /* 0x064 8006c0d4 */ void (*Unk24)(display_t *, s16 *, s16, s16);
    /* 0x068 8006c0d8 */ void (*display_do_vsync_internal)(display_t *);
    /* 0x06C 8006c0dc */ void (*Unk26)(display_t *);
    /* 0x070 8006c0e0 */ void (*display_set_vblanks)(display_t *, s32);
    /* 0x074 8006c0e4 */ s32 (*display_get_vblanks)(display_t *);
    /* 0x078 8006c0e8 */ void (*Unk29)(display_t *, unsigned char *, s32);
    /* 0x07C 8006c0ec */ void *(*display_get_screen_size)(display_t *, void *);
    /* 0x080 8006c0f0 */ void (*Unk31)(display_t *, s32);
    /* 0x084 8006c0f4 */ void (*display_set_vsync_callback)(display_t *, void (*Callback)(void));
};

struct display {
    /* 0x00 */ display_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_VSyncCount;
    /* 0x14 */ vec2d_t m_ScreenSize;
    /* 0x18 */ s32 m_VarMode;
    /* 0x1C */ s32 m_NextVBlank;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ void (*m_VsyncCallback)(void);
    /* 0x30 */ s32 m_Unk11;
    /* 0x34 */ s32 m_Unk12;
};

display_t *display_create(void);
display_vtable_t *display_get_vtable(void);

#endif
