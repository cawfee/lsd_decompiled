#ifndef LSD_35730_H
#define LSD_35730_H

#include <common.h>

typedef struct class_35730_vtable {
    /* 0x000 8006f514 */ u32 value;
    /* 0x004 8006f518 */ void (*Destroy)(void *);
    /* 0x008 8006f51c */ void (*Construct)(void *, s32);
    /* 0x00C 8006f520 */ void (*Cleanup)(void *);
    /* 0x010 8006f524 */ void (*Unk3)(void *);
    /* 0x014 8006f528 */ void (*Unk4)(void *);
    /* 0x018 8006f52c */ void (*Unk5)(void *);
    /* 0x01C 8006f530 */ void (*Unk6)(void *);
    /* 0x020 8006f534 */ void (*Unk7)(void *);
    /* 0x024 8006f538 */ void (*Unk8)(void *);
    /* 0x028 8006f53c */ void (*Unk9)(void *);
    /* 0x02C 8006f540 */ void (*Unk10)(void *);
    /* 0x030 8006f544 */ void (*Unk11)(void *);
    /* 0x034 8006f548 */ void (*Unk12)(void *);
    /* 0x038 8006f54c */ void (*Unk13)(void *);
    /* 0x03C 8006f550 */ void (*Unk14)(void *);
    /* 0x040 8006f554 */ void (*Unk15)(void *);
    /* 0x044 8006f558 */ void (*Unk16)(void *);
    /* 0x048 8006f55c */ void (*Unk17)(void *);
    /* 0x04C 8006f560 */ void (*Unk18)(void *);
    /* 0x050 8006f564 */ void (*Unk19)(void *);
    /* 0x054 8006f568 */ void (*Unk20)(void *);
    /* 0x058 8006f56c */ void (*Unk21)(void *);
    /* 0x05C 8006f570 */ void (*Unk22)(void *);
    /* 0x060 8006f574 */ void (*Unk23)(void *);
    /* 0x064 8006f578 */ void (*Unk24)(void *);
    /* 0x068 8006f57c */ void (*Unk25)(void *);
    /* 0x06C 8006f580 */ void (*Unk26)(void *);
    /* 0x070 8006f584 */ void (*Unk27)(void *);
    /* 0x074 8006f588 */ void (*Unk28)(void *);
    /* 0x078 8006f58c */ void (*Unk29)(void *);
} class_35730_vtable_t;

typedef struct class_35730 {
    /* 0x00 */ class_35730_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s16 m_Unk9_1;
    /* 0x2A */ u16 m_Unk9_2;
    /* 0x2C */ s32 m_Unk10;
    /* 0x30 */ s16 m_Unk11_1;
    /* 0x32 */ s16 m_Unk11_2;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Unk13;
} class_35730_t;

class_35730_t *func_80044F30(u32 Unk1);
class_35730_vtable_t *func_800451A8(void);

#endif