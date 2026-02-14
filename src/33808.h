#ifndef LSD_33808_H
#define LSD_33808_H

#include <common.h>

typedef struct class_33808_vtable {
    /* 0x000 8006f0b8 */ u32 value;
    /* 0x004 8006f0bc */ void (*Destroy)(void *);
    /* 0x008 8006f0c0 */ void (*Construct)(void *, s32);
    /* 0x00C 8006f0c4 */ void (*Cleanup)(void *);
    /* 0x010 8006f0c8 */ void (*Unk3)(void *);
    /* 0x014 8006f0cc */ void (*Unk4)(void *);
    /* 0x018 8006f0d0 */ void (*Unk5)(void *);
    /* 0x01C 8006f0d4 */ void (*Unk6)(void *);
    /* 0x020 8006f0d8 */ void (*Unk7)(void *);
    /* 0x024 8006f0dc */ void (*Unk8)(void *);
    /* 0x028 8006f0e0 */ void (*Unk9)(void *);
    /* 0x02C 8006f0e4 */ void (*Unk10)(void *);
    /* 0x030 8006f0e8 */ void (*Unk11)(void *);
    /* 0x034 8006f0ec */ void (*Unk12)(void *);
    /* 0x038 8006f0f0 */ void (*Unk13)(void *);
    /* 0x03C 8006f0f4 */ void (*Unk14)(void *);
    /* 0x040 8006f0f8 */ void (*Unk15)(void *);
    /* 0x044 8006f0fc */ void (*Unk16)(void *);
    /* 0x048 8006f100 */ void (*Unk17)(void *);
    /* 0x04C 8006f104 */ void (*Unk18)(void *);
    /* 0x050 8006f108 */ void (*Unk19)(void *);
    /* 0x054 8006f10c */ void (*Unk20)(void *);
    /* 0x058 8006f110 */ void (*Unk21)(void *);
    /* 0x05C 8006f114 */ void (*Unk22)(void *);
    /* 0x060 8006f118 */ void (*Unk23)(void *);
    /* 0x064 8006f11c */ void (*Unk24)(void *);
    /* 0x068 8006f120 */ void (*Unk25)(void *);
    /* 0x06C 8006f124 */ void (*Unk26)(void *);
    /* 0x070 8006f128 */ void (*Unk27)(void *);
    /* 0x074 8006f12c */ void (*Unk28)(void *);
    /* 0x078 8006f130 */ void (*Unk29)(void *);
    /* 0x07C 8006f134 */ void (*Unk30)(void *);
    /* 0x080 8006f138 */ void (*Unk31)(void *);
    /* 0x084 8006f13c */ void (*Unk32)(void *);
} class_33808_vtable_t;

typedef struct class_33808 {
    /* 0x00 */ class_33808_vtable_t *vtable;
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
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ s32 m_Unk21;
    /* 0x5C */ s32 m_Unk22;
    /* 0x60 */ s32 m_Unk23;
    /* 0x64 */ s32 m_Unk24;
    /* 0x68 */ s32 m_Unk25;
    /* 0x6C */ s32 m_Unk26;
    /* 0x70 */ s32 m_Unk27;
    /* 0x74 */ s32 m_Unk28;
    /* 0x78 */ s32 m_Unk29;
    /* 0x7C */ s32 m_Unk30;
    /* 0x80 */ s32 m_Unk31;
    /* 0x84 */ s32 m_Unk32;
} class_33808_t;

class_33808_vtable_t *func_80043830(void);

#endif // LSD_33808_H