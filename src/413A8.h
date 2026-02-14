#ifndef LSD_413A8_H
#define LSD_413A8_H

#include <common.h>

typedef struct class_413A8_vtable {
    /* 0x000 80086ed0 */ u32 value;
    /* 0x004 80086ed4 */ void (*Destroy)(void *);
    /* 0x008 80086ed8 */ void (*Construct)(void *, char *, s32);
    /* 0x00C 80086edc */ void (*Cleanup)(void *);
    /* 0x010 80086ee0 */ void (*Unk3)(void *, s32);
    /* 0x014 80086ee4 */ void (*Unk4)(void *, s32);
    /* 0x018 80086ee8 */ void (*Unk5)(void *);
    /* 0x01C 80086eec */ void (*Unk6)(void *);
    /* 0x020 80086ef0 */ void (*Unk7)(void *);
    /* 0x024 80086ef4 */ void (*Unk8)(void *);
    /* 0x028 80086ef8 */ void (*Unk9)(void *);
    /* 0x02C 80086efc */ void (*Unk10)(void *);
    /* 0x030 80086f00 */ void (*Unk11)(void *);
    /* 0x034 80086f04 */ void (*Unk12)(void *);
    /* 0x038 80086f08 */ void (*Unk13)(void *);
    /* 0x03C 80086f0c */ void (*Unk14)(void *);
    /* 0x040 80086f10 */ void (*Unk15)(void *, char *, s32);
    /* 0x044 80086f14 */ void (*Unk16)(void *);
    /* 0x048 80086f18 */ void (*Unk17)(void *);
    /* 0x04C 80086f1c */ void (*Unk18)(void *);
    /* 0x050 80086f20 */ void (*Unk19)(void *);
    /* 0x054 80086f24 */ void (*Unk20)(void *, s32);
    /* 0x058 80086f28 */ void (*Unk21)(void *);
    /* 0x05C 80086f2c */ void (*Unk22)(void *);
    /* 0x060 80086f30 */ void (*Unk23)(void *);
    /* 0x064 80086f34 */ void (*Unk24)(void *);
    /* 0x068 80086f38 */ void (*Unk25)(void *);
    /* 0x06C 80086f3c */ void (*Unk26)(void *);
    /* 0x070 80086f40 */ void (*Unk27)(void *);
    /* 0x074 80086f44 */ void (*Unk28)(void *);
    /* 0x078 80086f48 */ void (*Unk29)(void *);
    /* 0x07C 80086f4c */ void (*Unk30)(void *);
    /* 0x080 80086f50 */ void (*Unk31)(void *);
    /* 0x084 80086f54 */ void (*Unk32)(void *);
    /* 0x088 80086f58 */ void (*Unk33)(void *);
    /* 0x08C 80086f5c */ void (*Unk34)(void *);
    /* 0x090 80086f60 */ void (*Unk35)(void *);
    /* 0x094 80086f64 */ void (*Unk36)(void *);
    /* 0x098 80086f68 */ void (*Unk37)(void *);
    /* 0x09C 80086f6c */ void (*Unk38)(void *);
    /* 0x0A0 80086f70 */ void (*Unk39)(void *);
    /* 0x0A4 80086f74 */ void (*Unk40)(void *, s32, s32);
    /* 0x0A8 80086f78 */ void (*Unk41)(void *);
    /* 0x0AC 80086f7c */ void (*Unk42)(void *);
} class_413A8_vtable_t;

typedef struct class_413A8 {
    /* 0x00 */ class_413A8_vtable_t *vtable;
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
} class_413A8_t;

class_413A8_vtable_t *func_80051A4C(void);

#endif // LSD_413A8_H