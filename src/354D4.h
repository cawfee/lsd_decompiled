#ifndef LSD_354D4_H
#define LSD_354D4_H

#include <common.h>

typedef struct class_354D4_vtable {
    /* 0x000 8006f498 */ u32 value;
    /* 0x004 8006f49c */ void (*Destroy)(void *);
    /* 0x008 8006f4a0 */ void (*Construct)(void *, s32, void *);
    /* 0x00C 8006f4a4 */ void (*Cleanup)(void *);
    /* 0x010 8006f4a8 */ void (*Unk3)(void *);
    /* 0x014 8006f4ac */ void (*Unk4)(void *);
    /* 0x018 8006f4b0 */ void (*Unk5)(void *);
    /* 0x01C 8006f4b4 */ void (*Unk6)(void *);
    /* 0x020 8006f4b8 */ void (*Unk7)(void *);
    /* 0x024 8006f4bc */ void (*Unk8)(void *);
    /* 0x028 8006f4c0 */ void (*Unk9)(void *);
    /* 0x02C 8006f4c4 */ void (*Unk10)(void *);
    /* 0x030 8006f4c8 */ void (*Unk11)(void *);
    /* 0x034 8006f4cc */ void (*Unk12)(void *);
    /* 0x038 8006f4d0 */ void (*Unk13)(void *);
    /* 0x03C 8006f4d4 */ void (*Unk14)(void *);
    /* 0x040 8006f4d8 */ void (*Unk15)(void *);
    /* 0x044 8006f4dc */ void (*Unk16)(void *);
    /* 0x048 8006f4e0 */ void (*Unk17)(void *);
    /* 0x04C 8006f4e4 */ void (*Unk18)(void *);
    /* 0x050 8006f4e8 */ void (*Unk19)(void *);
    /* 0x054 8006f4ec */ void (*Unk20)(void *);
    /* 0x058 8006f4f0 */ void (*Unk21)(void *);
    /* 0x05C 8006f4f4 */ void (*Unk22)(void *);
    /* 0x060 8006f4f8 */ void (*Unk23)(void *);
    /* 0x064 8006f4fc */ void (*Unk24)(void *);
    /* 0x068 8006f500 */ void (*Unk25)(void *);
    /* 0x06C 8006f504 */ void (*Unk26)(void *);
    /* 0x070 8006f508 */ void (*Unk27)(void *);
    /* 0x074 8006f50c */ void (*Unk28)(void *);
    /* 0x078 8006f510 */ void (*Unk29)(void *);
} class_354D4_vtable_t;

typedef struct class_354D4 {
    /* 0x00 */ class_354D4_vtable_t *vtable;
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
} class_354D4_t;

class_354D4_t *func_80044CD4(s32 Unk1, void *Unk2);
class_354D4_vtable_t *func_80044F20(void);

#endif