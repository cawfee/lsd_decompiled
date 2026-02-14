#ifndef LSD_34388_H
#define LSD_34388_H

#include <common.h>

typedef struct class_34388_vtable {
    /* 0x000 8006f1c4 */ u32 value;
    /* 0x004 8006f1c8 */ void (*Destroy)(void *);
    /* 0x008 8006f1cc */ void (*Construct)(void *, s32);
    /* 0x00C 8006f1d0 */ void (*Cleanup)(void *);
    /* 0x010 8006f1d4 */ void (*Unk3)(void *);
    /* 0x014 8006f1d8 */ void (*Unk4)(void *);
    /* 0x018 8006f1dc */ void (*Unk5)(void *);
    /* 0x01C 8006f1e0 */ void (*Unk6)(void *);
    /* 0x020 8006f1e4 */ void (*Unk7)(void *);
    /* 0x024 8006f1e8 */ void (*Unk8)(void *);
    /* 0x028 8006f1ec */ void (*Unk9)(void *);
    /* 0x02C 8006f1f0 */ void (*Unk10)(void *);
    /* 0x030 8006f1f4 */ void (*Unk11)(void *);
    /* 0x034 8006f1f8 */ void (*Unk12)(void *);
    /* 0x038 8006f1fc */ void (*Unk13)(void *);
    /* 0x03C 8006f200 */ void (*Unk14)(void *);
    /* 0x040 8006f204 */ void (*Unk15)(void *);
    /* 0x044 8006f208 */ void (*Unk16)(void *);
    /* 0x048 8006f20c */ void (*Unk17)(void *);
    /* 0x04C 8006f210 */ void (*Unk18)(void *);
    /* 0x050 8006f214 */ void (*Unk19)(void *);
    /* 0x054 8006f218 */ void (*Unk20)(void *);
    /* 0x058 8006f21c */ void (*Unk21)(void *);
    /* 0x05C 8006f220 */ void (*Unk22)(void *);
    /* 0x060 8006f224 */ void (*Unk23)(void *);
    /* 0x064 8006f228 */ void (*Unk24)(void *);
    /* 0x068 8006f22c */ void (*Unk25)(void *);
    /* 0x06C 8006f230 */ void (*Unk26)(void *);
    /* 0x070 8006f234 */ void (*Unk27)(void *);
    /* 0x074 8006f238 */ void (*Unk28)(void *);
    /* 0x078 8006f23c */ void (*Unk29)(void *);
    /* 0x07C 8006f240 */ void (*Unk30)(void *);
} class_34388_vtable_t;

typedef struct class_34388 {
    /* 0x00 */ class_34388_vtable_t *vtable;
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
} class_34388_t;

class_34388_vtable_t *func_80043E74(void);

#endif // LSD_34388_H