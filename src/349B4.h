#ifndef LSD_349B4_H
#define LSD_349B4_H

#include <common.h>

typedef struct class_349B4_vtable {
    /* 0x000 8006f2c4 */ u32 value;
    /* 0x004 8006f2c8 */ void (*Destroy)(void *);
    /* 0x008 8006f2cc */ void (*Construct)(void *, s32, s32);
    /* 0x00C 8006f2d0 */ void (*Cleanup)(void *);
    /* 0x010 8006f2d4 */ void (*Unk3)(void *);
    /* 0x014 8006f2d8 */ void (*Unk4)(void *);
    /* 0x018 8006f2dc */ void (*Unk5)(void *);
    /* 0x01C 8006f2e0 */ void (*Unk6)(void *);
    /* 0x020 8006f2e4 */ void (*Unk7)(void *);
    /* 0x024 8006f2e8 */ void (*Unk8)(void *);
    /* 0x028 8006f2ec */ void (*Unk9)(void *);
    /* 0x02C 8006f2f0 */ void (*Unk10)(void *);
    /* 0x030 8006f2f4 */ void (*Unk11)(void *);
    /* 0x034 8006f2f8 */ void (*Unk12)(void *);
    /* 0x038 8006f2fc */ void (*Unk13)(void *);
    /* 0x03C 8006f300 */ void (*Unk14)(void *);
    /* 0x040 8006f304 */ void (*Unk15)(void *);
    /* 0x044 8006f308 */ void (*Unk16)(void *);
    /* 0x048 8006f30c */ void (*Unk17)(void *);
    /* 0x04C 8006f310 */ void (*Unk18)(void *);
    /* 0x050 8006f314 */ void (*Unk19)(void *);
    /* 0x054 8006f318 */ void (*Unk20)(void *);
    /* 0x058 8006f31c */ void (*Unk21)(void *);
    /* 0x05C 8006f320 */ void (*Unk22)(void *);
    /* 0x060 8006f324 */ void (*Unk23)(void *);
    /* 0x064 8006f328 */ void (*Unk24)(void *);
    /* 0x068 8006f32c */ void (*Unk25)(void *);
    /* 0x06C 8006f330 */ void (*Unk26)(void *);
    /* 0x070 8006f334 */ void (*Unk27)(void *);
    /* 0x074 8006f338 */ void (*Unk28)(void *);
    /* 0x078 8006f33c */ void (*Unk29)(void *);
    /* 0x07C 8006f340 */ void (*Unk30)(void *);
    /* 0x080 8006f344 */ void (*Unk31)(void *);
    /* 0x084 8006f348 */ void (*Unk32)(void *);
    /* 0x088 8006f34c */ void (*Unk33)(void *);
    /* 0x08C 8006f350 */ void (*Unk34)(void *);
    /* 0x090 8006f354 */ void (*Unk35)(void *);
    /* 0x094 8006f358 */ void (*Unk36)(void *);
    /* 0x098 8006f35c */ void (*Unk37)(void *);
    /* 0x09C 8006f360 */ void (*Unk38)(void *);
    /* 0x0A0 8006f364 */ void (*Unk39)(void *);
    /* 0x0A4 8006f368 */ void (*Unk40)(void *);
    /* 0x0A8 8006f36c */ void (*Unk41)(void *);
    /* 0x0AC 8006f370 */ void (*Unk42)(void *);
    /* 0x0B0 8006f374 */ void (*Unk43)(void *);
    /* 0x0B4 8006f378 */ void (*Unk44)(void *);
    /* 0x0B8 8006f37c */ void (*Unk45)(void *);
    /* 0x0BC 8006f380 */ void (*Unk46)(void *);
} class_349B4_vtable_t;

typedef struct class_349B4 {
    /* 0x00 */ class_349B4_vtable_t *vtable;
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
} class_349B4_t;

class_349B4_t *func_800441B4(s32 Unk1, s32 Unk2);
class_349B4_vtable_t *func_8004467C(void);

#endif