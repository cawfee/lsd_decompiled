#ifndef LSD_DREAM_CONTEXT_H
#define LSD_DREAM_CONTEXT_H

#include <common.h>

typedef struct dream_context_vtable {
    /* 0x000 800865c8 */ u32 value;
    /* 0x004 800865cc */ void (*Destroy)(void *);
    /* 0x008 800865d0 */ void (*Construct)(void *, s32, s32, s32);
    /* 0x00C 800865d4 */ void (*Cleanup)(void *);
    /* 0x010 800865d8 */ void (*Unk3)(void *);
    /* 0x014 800865dc */ void (*Unk4)(void *);
    /* 0x018 800865e0 */ void (*Unk5)(void *);
    /* 0x01C 800865e4 */ void (*Unk6)(void *);
    /* 0x020 800865e8 */ void (*Unk7)(void *);
    /* 0x024 800865ec */ void (*Unk8)(void *);
    /* 0x028 800865f0 */ void (*Unk9)(void *);
    /* 0x02C 800865f4 */ void (*Unk10)(void *);
    /* 0x030 800865f8 */ void (*Unk11)(void *);
    /* 0x034 800865fc */ void (*Unk12)(void *);
    /* 0x038 80086600 */ void (*Unk13)(void *);
    /* 0x03C 80086604 */ void (*Unk14)(void *);
    /* 0x040 80086608 */ void (*Unk15)(void *);
    /* 0x044 8008660c */ void (*Unk16)(void *);
    /* 0x048 80086610 */ void (*Unk17)(void *);
    /* 0x04C 80086614 */ void (*Unk18)(void *);
    /* 0x050 80086618 */ void (*Unk19)(void *);
    /* 0x054 8008661c */ void (*Unk20)(void *);
    /* 0x058 80086620 */ void (*Unk21)(void *);
    /* 0x05C 80086624 */ void (*Unk22)(void *);
    /* 0x060 80086628 */ void (*Unk23)(void *);
    /* 0x064 8008662c */ void (*Unk24)(void *);
    /* 0x068 80086630 */ void (*Unk25)(void *);
    /* 0x06C 80086634 */ void (*Unk26)(void *);
    /* 0x070 80086638 */ void (*Unk27)(void *);
    /* 0x074 8008663c */ void (*Unk28)(void *);
    /* 0x078 80086640 */ void (*Unk29)(void *);
    /* 0x07C 80086644 */ void (*Unk30)(void *);
    /* 0x080 80086648 */ void (*Unk31)(void *);
    /* 0x084 8008664c */ void (*Unk32)(void *);
} dream_context_vtable_t;

typedef struct dream_context {
    /* 0x00 */ dream_context_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ s32 m_Unk10;
    /* 0x30 */ s32 m_Unk11;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Unk13;
    /* 0x3C */ s32 m_Unk14;
    /* 0x40 */ s32 m_Unk15;
    /* 0x44 */ s32 m_Unk16;
    /* 0x48 */ s32 m_Unk17;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Unk19;
} dream_context_t;

dream_context_vtable_t *dream_context_get_vtable(void);

#endif