#ifndef LSD_3770C_H
#define LSD_3770C_H

#include <common.h>

typedef struct class_3770C_vtable {
    /* 0x000 800817e0 */ u32 value;
    /* 0x004 800817e4 */ void (*Destroy)(void *);
    /* 0x008 800817e8 */ void (*Construct)(void *, s32, s32, s32);
    /* 0x00C 800817ec */ void (*Cleanup)(void *);
    /* 0x010 800817f0 */ void (*Unk3)(void *);
    /* 0x014 800817f4 */ void (*Unk4)(void *);
    /* 0x018 800817f8 */ void (*Unk5)(void *);
    /* 0x01C 800817fc */ void (*Unk6)(void *);
    /* 0x020 80081800 */ void (*Unk7)(void *);
    /* 0x024 80081804 */ void (*Unk8)(void *);
    /* 0x028 80081808 */ void (*Unk9)(void *);
    /* 0x02C 8008180c */ void (*Unk10)(void *);
    /* 0x030 80081810 */ void (*Unk11)(void *);
    /* 0x034 80081814 */ void (*Unk12)(void *);
    /* 0x038 80081818 */ void (*Unk13)(void *);
    /* 0x03C 8008181c */ void (*Unk14)(void *);
    /* 0x040 80081820 */ void (*Unk15)(void *);
    /* 0x044 80081824 */ void (*Unk16)(void *);
    /* 0x048 80081828 */ void (*Unk17)(void *);
    /* 0x04C 8008182c */ void (*Unk18)(void *, s32 *);
    /* 0x050 80081830 */ void (*Unk19)(void *);
    /* 0x054 80081834 */ void (*Unk20)(void *);
    /* 0x058 80081838 */ void (*Unk21)(void *);
    /* 0x05C 8008183c */ void (*Unk22)(void *);
    /* 0x060 80081840 */ void (*Unk23)(void *);
    /* 0x064 80081844 */ void (*Unk24)(void *);
    /* 0x068 80081848 */ void (*Unk25)(void *);
    /* 0x06C 8008184c */ void (*Unk26)(void *);
    /* 0x070 80081850 */ void (*Unk27)(void *, u32 *);
    /* 0x074 80081854 */ void (*Unk28)(void *);
    /* 0x078 80081858 */ void (*Unk29)(void *);
    /* 0x07C 8008185c */ void (*Unk30)(void *);
} class_3770C_vtable_t;

typedef struct class_3770C {
    /* 0x00 */ class_3770C_vtable_t *vtable;
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
    /* 0x38 */ u32 m_Unk13;
    /* 0x3C */ s32 m_Unk14;
    /* 0x40 */ s32 m_Unk15;
    /* 0x44 */ s32 m_Unk16;
    /* 0x48 */ s32 m_Unk17;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Unk19;
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ s32 m_Unk21;
    /* 0x5C */ s32 m_Unk22;
} class_3770C_t;

class_3770C_vtable_t *func_80047900(void);

#endif