#ifndef LSD_4225C_H
#define LSD_4225C_H

#include <common.h>

typedef struct class_4225C_vtable {
    /* 0x000 80086f88 */ u32 value;
    /* 0x004 80086f8c */ void (*Destroy)(void *);
    /* 0x008 80086f90 */ void (*Construct)(void *, s32, s32);
    /* 0x00C 80086f94 */ void (*Cleanup)(void *);
    /* 0x010 80086f98 */ void (*Unk3)(void *);
    /* 0x014 80086f9c */ void (*Unk4)(void *, s32);
    /* 0x018 80086fa0 */ void (*Unk5)(void *);
    /* 0x01C 80086fa4 */ void (*Unk6)(void *);
    /* 0x020 80086fa8 */ void (*Unk7)(void *);
    /* 0x024 80086fac */ void (*Unk8)(void *);
    /* 0x028 80086fb0 */ void (*Unk9)(void *);
    /* 0x02C 80086fb4 */ void (*Unk10)(void *);
    /* 0x030 80086fb8 */ void (*Unk11)(void *);
    /* 0x034 80086fbc */ void (*Unk12)(void *);
    /* 0x038 80086fc0 */ void (*Unk13)(void *);
    /* 0x03C 80086fc4 */ void (*Unk14)(void *);
    /* 0x040 80086fc8 */ void (*Unk15)(void *);
    /* 0x044 80086fcc */ void (*Unk16)(void *);
    /* 0x048 80086fd0 */ void (*Unk17)(void *);
    /* 0x04C 80086fd4 */ void (*Unk18)(void *);
    /* 0x050 80086fd8 */ void (*Unk19)(void *);
    /* 0x054 80086fdc */ void (*Unk20)(void *);
    /* 0x058 80086fe0 */ void (*Unk21)(void *);
    /* 0x05C 80086fe4 */ void (*Unk22)(void *);
    /* 0x060 80086fe8 */ void (*Unk23)(void *);
    /* 0x064 80086fec */ void (*Unk24)(void *);
    /* 0x068 80086ff0 */ void (*Unk25)(void *);
    /* 0x06C 80086ff4 */ void (*Unk26)(void *);
    /* 0x070 80086ff8 */ void (*Unk27)(void *);
    /* 0x074 80086ffc */ void (*Unk28)(void *);
    /* 0x078 80087000 */ void (*Unk29)(void *);
    /* 0x07C 80087004 */ void (*Unk30)(void *);
    /* 0x080 80087008 */ void (*Unk31)(void *);
    /* 0x084 8008700c */ void (*Unk32)(void *);
    /* 0x088 80087010 */ void (*Unk33)(void *);
    /* 0x08C 80087014 */ void (*Unk34)(void *);
    /* 0x090 80087018 */ void (*Unk35)(void *);
    /* 0x094 8008701c */ void (*Unk36)(void *);
    /* 0x098 80087020 */ void (*Unk37)(void *);
    /* 0x09C 80087024 */ void (*Unk38)(void *);
    /* 0x0A0 80087028 */ void (*Unk39)(void *);
} class_4225C_vtable_t;

typedef struct class_4225C {
    /* 0x00 */ class_4225C_vtable_t *vtable;
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
} class_4225C_t;

class_4225C_vtable_t *func_80052B60(void);

#endif // LSD_4225C_H