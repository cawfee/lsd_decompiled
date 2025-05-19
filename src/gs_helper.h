#ifndef LSD_GS_HELPER_H
#define LSD_GS_HELPER_H

#include <common.h>

typedef struct gs_helper_vtable {
    /* 0x000 8006c070 */ u32 value;
    /* 0x004 8006c074 */ void (*Destroy)(void *);
    /* 0x008 8006c078 */ void (*Construct)(void *);
    /* 0x00C 8006c07c */ void (*Cleanup)(void *);
    /* 0x010 8006c080 */ void (*Unk3)(void *);
    /* 0x014 8006c084 */ void (*Unk4)(void *);
    /* 0x018 8006c088 */ void (*Unk5)(void *);
    /* 0x01C 8006c08c */ void (*Unk6)(void *);
    /* 0x020 8006c090 */ void (*Unk7)(void *);
    /* 0x024 8006c094 */ void (*Unk8)(void *);
    /* 0x028 8006c098 */ void (*Unk9)(void *);
    /* 0x02C 8006c09c */ void (*Unk10)(void *);
    /* 0x030 8006c0a0 */ void (*Unk11)(void *, s32);
    /* 0x034 8006c0a4 */ void (*Unk12)(void *);
    /* 0x038 8006c0a8 */ void (*Unk13)(void *);
    /* 0x03C 8006c0ac */ void (*Unk14)(void *);
    /* 0x040 8006c0b0 */ void (*Reset)(void *);
    /* 0x044 8006c0b4 */ void (*InitGS)(void *, s16 *, s32);
    /* 0x048 8006c0b8 */ void (*DoVSync)(void *);
    /* 0x04C 8006c0bc */ void (*Unk18)(void *);
    /* 0x050 8006c0c0 */ void (*ResetVSyncCount)(void *);
    /* 0x054 8006c0c4 */ void (*SwapDisplayBuffer)(void *);
    /* 0x058 8006c0c8 */ void (*GetActiveBuffer)(void *);
    /* 0x05C 8006c0cc */ void (*Unk22)(void *);
    /* 0x060 8006c0d0 */ void (*Unk23)(void *);
    /* 0x064 8006c0d4 */ void (*Unk24)(void *);
    /* 0x068 8006c0d8 */ void (*VSync)(void *);
    /* 0x06C 8006c0dc */ void (*Unk26)(void *);
    /* 0x070 8006c0e0 */ void (*SetVBlanks)(void *, s32);
    /* 0x074 8006c0e4 */ void (*GetVBlanks)(void *);
    /* 0x078 8006c0e8 */ void (*Unk29)(void *, unsigned char *, s32);
    /* 0x07C 8006c0ec */ void *(*GetScreenSize)(void *, void *);
    /* 0x080 8006c0f0 */ void (*Unk31)(void *, s32);
    /* 0x084 8006c0f4 */ void (*SetVSyncCallback)(void *, void (*Callback)());
} gs_helper_vtable_t;

typedef struct gs_helper {
    /* 0x00 */ gs_helper_vtable_t *vtable;
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
    /* 0x2C */ void (*m_VsyncCallback)();
    /* 0x30 */ s32 m_Unk11;
    /* 0x34 */ s32 m_Unk12;
} gs_helper_t;

gs_helper_t *gs_helper_create();
gs_helper_vtable_t *gs_helper_get_vtable(void);

#endif