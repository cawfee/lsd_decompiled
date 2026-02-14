#ifndef LSD_359B8_H
#define LSD_359B8_H

#include <common.h>

typedef struct class_359B8_vtable {
    /* 0x000 8006f590 */ u32 value;
    /* 0x004 8006f594 */ void (*Destroy)(void *);
    /* 0x008 8006f598 */ s32 (*Construct)(void *, s32);
    /* 0x00C 8006f59c */ void (*Cleanup)(void *);
    /* 0x010 8006f5a0 */ void (*Unk3)(void *);
    /* 0x014 8006f5a4 */ void (*Unk4)(void *);
    /* 0x018 8006f5a8 */ void (*Unk5)(void *);
    /* 0x01C 8006f5ac */ void (*Unk6)(void *);
    /* 0x020 8006f5b0 */ void (*Unk7)(void *);
    /* 0x024 8006f5b4 */ void (*Unk8)(void *);
    /* 0x028 8006f5b8 */ void (*Unk9)(void *);
    /* 0x02C 8006f5bc */ void (*Unk10)(void *);
    /* 0x030 8006f5c0 */ void (*Unk11)(void *);
    /* 0x034 8006f5c4 */ void (*Unk12)(void *);
    /* 0x038 8006f5c8 */ void (*Unk13)(void *);
    /* 0x03C 8006f5cc */ void (*Unk14)(void *);
    /* 0x040 8006f5d0 */ void (*Unk15)(void *);
    /* 0x044 8006f5d4 */ void (*Unk16)(void *);
    /* 0x048 8006f5d8 */ void (*Unk17)(void *);
    /* 0x04C 8006f5dc */ void (*Unk18)(void *);
    /* 0x050 8006f5e0 */ void (*Unk19)(void *);
    /* 0x054 8006f5e4 */ void (*Unk20)(void *);
    /* 0x058 8006f5e8 */ void (*Unk21)(void *);
    /* 0x05C 8006f5ec */ void (*Unk22)(void *);
    /* 0x060 8006f5f0 */ void (*Unk23)(void *);
    /* 0x064 8006f5f4 */ void (*Unk24)(void *);
    /* 0x068 8006f5f8 */ void (*Unk25)(void *);
    /* 0x06C 8006f5fc */ void (*Unk26)(void *);
    /* 0x070 8006f600 */ void (*Unk27)(void *);
    /* 0x074 8006f604 */ void (*Unk28)(void *);
    /* 0x078 8006f608 */ void (*Unk29)(void *);
    /* 0x07C 8006f60c */ void (*Unk30)(void *);
    /* 0x080 8006f610 */ void (*Unk31)(void *);
    /* 0x084 8006f614 */ void (*Unk32)(void *);
} class_359B8_vtable_t;

typedef struct class_359B8 {
    /* 0x00 */ class_359B8_vtable_t *vtable;
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
} class_359B8_t;

class_359B8_vtable_t *func_80045428(void);

#endif // LSD_359B8_H