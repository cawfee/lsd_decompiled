#ifndef LSD_32E94_H
#define LSD_32E94_H

#include <common.h>

typedef struct class_32E94_vtable {
    /* 0x000 8006efac */ u32 value;
    /* 0x004 8006efb0 */ void (*Destroy)(void *);
    /* 0x008 8006efb4 */ void (*Construct)(void *);
    /* 0x00C 8006efb8 */ void (*Cleanup)(void *);
    /* 0x010 8006efbc */ void (*Unk3)(void *);
    /* 0x014 8006efc0 */ void (*Unk4)(void *);
    /* 0x018 8006efc4 */ void (*Unk5)(void *);
    /* 0x01C 8006efc8 */ void (*Unk6)(void *);
    /* 0x020 8006efcc */ void (*Unk7)(void *);
    /* 0x024 8006efd0 */ void (*Unk8)(void *);
    /* 0x028 8006efd4 */ void (*Unk9)(void *);
    /* 0x02C 8006efd8 */ void (*Unk10)(void *);
    /* 0x030 8006efdc */ void (*Unk11)(void *);
    /* 0x034 8006efe0 */ void (*Unk12)(void *);
    /* 0x038 8006efe4 */ void (*Unk13)(void *);
    /* 0x03C 8006efe8 */ void (*Unk14)(void *);
    /* 0x040 8006efec */ void (*Unk15)(void *);
    /* 0x044 8006eff0 */ void (*Unk16)(void *);
    /* 0x048 8006eff4 */ void (*Unk17)(void *);
    /* 0x04C 8006eff8 */ void (*Unk18)(void *);
    /* 0x050 8006effc */ void (*Unk19)(void *);
    /* 0x054 8006f000 */ void (*Unk20)(void *);
    /* 0x058 8006f004 */ void (*Unk21)(void *);
    /* 0x05C 8006f008 */ void (*Unk22)(void *);
    /* 0x060 8006f00c */ void (*Unk23)(void *);
    /* 0x064 8006f010 */ void (*Unk24)(void *);
    /* 0x068 8006f014 */ void (*Unk25)(void *);
    /* 0x06C 8006f018 */ void (*Unk26)(void *);
    /* 0x070 8006f01c */ void (*Unk27)(void *);
    /* 0x074 8006f020 */ void (*Unk28)(void *);
    /* 0x078 8006f024 */ void (*Unk29)(void *);
    /* 0x07C 8006f028 */ void (*Unk30)(void *);
    /* 0x080 8006f02c */ void (*Unk31)(void *);
    /* 0x084 8006f030 */ void (*Unk32)(void *);
    /* 0x088 8006f034 */ void (*Unk33)(void *);
    /* 0x08C 8006f038 */ void (*Unk34)(void *);
    /* 0x090 8006f03c */ void (*Unk35)(void *);
    /* 0x094 8006f040 */ void (*Unk36)(void *);
    /* 0x098 8006f044 */ void (*Unk37)(void *);
    /* 0x09C 8006f048 */ void (*Unk38)(void *);
    /* 0x0A0 8006f04c */ void (*Unk39)(void *);
    /* 0x0A4 8006f050 */ void (*Unk40)(void *);
    /* 0x0A8 8006f054 */ void (*Unk41)(void *);
    /* 0x0AC 8006f058 */ void (*Unk42)(void *);
    /* 0x0B0 8006f05c */ void (*Unk43)(void *);
    /* 0x0B4 8006f060 */ void (*Unk44)(void *);
    /* 0x0B8 8006f064 */ void *(*Unk45)(void *, int);
    /* 0x0BC 8006f068 */ void (*Unk46)(void *);
    /* 0x0C0 8006f06c */ void (*Unk47)(void *);
} class_32E94_vtable_t;

typedef struct class_32E94 {
    /* 0x00 */ class_32E94_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 *m_Unk4;
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
} class_32E94_t;

class_32E94_vtable_t *func_800428E4();

#endif