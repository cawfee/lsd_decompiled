#ifndef LSD_D294_H
#define LSD_D294_H

#include <common.h>

typedef struct class_D294_vtable {
    /* 0x000 8006b5cc */ u32 value;
    /* 0x004 8006b5d0 */ void (*Destroy)(void *);
    /* 0x008 8006b5d4 */ void *(*Construct)(void *);
    /* 0x00C 8006b5d8 */ void (*Cleanup)(void *);
    /* 0x010 8006b5dc */ void (*Unk3)(void *);
    /* 0x014 8006b5e0 */ void (*Unk4)(void *);
    /* 0x018 8006b5e4 */ void (*Unk5)(void *);
    /* 0x01C 8006b5e8 */ void (*Unk6)(void *);
    /* 0x020 8006b5ec */ void (*Unk7)(void *);
    /* 0x024 8006b5f0 */ void (*Unk8)(void *);
    /* 0x028 8006b5f4 */ void (*Unk9)(void *);
    /* 0x02C 8006b5f8 */ void (*Unk10)(void *);
    /* 0x030 8006b5fc */ void (*Unk11)(void *);
    /* 0x034 8006b600 */ void (*Unk12)(void *);
    /* 0x038 8006b604 */ void (*Unk13)(void *);
    /* 0x03C 8006b608 */ void (*Unk14)(void *);
    /* 0x040 8006b60c */ void (*Unk15)(void *);
    /* 0x044 8006b610 */ void (*Unk16)(void *, s32, s32 *);
    /* 0x048 8006b614 */ void (*Unk17)(void *, s32, s32 *);
    /* 0x04C 8006b618 */ void (*Unk18)(void *);
    /* 0x050 8006b61c */ void (*Unk19)(void *);
    /* 0x054 8006b620 */ void (*Unk20)(void *);
    /* 0x058 8006b624 */ void (*Unk21)(void *);
    /* 0x05C 8006b628 */ void (*Unk22)(void *, s32);
    /* 0x060 8006b62c */ void (*Unk23)(void *);
    /* 0x064 8006b630 */ void (*Unk24)(void *);
    /* 0x068 8006b634 */ void (*Unk25)(void *);
    /* 0x06C 8006b638 */ void (*Unk26)(void *);
    /* 0x070 8006b63c */ void (*Unk27)(void *);
    /* 0x074 8006b640 */ void (*Unk28)(void *);
    /* 0x078 8006b644 */ void (*Unk29)(void *);
    /* 0x07C 8006b648 */ void (*Unk30)(void *);
    /* 0x080 8006b64c */ void (*Unk31)(void *);
    /* 0x084 8006b650 */ void (*Unk32)(void *);
    /* 0x088 8006b654 */ void (*Unk33)(void *);
    /* 0x08C 8006b658 */ void (*Unk34)(void *);
    /* 0x090 8006b65c */ void (*Unk35)(void *);
    /* 0x094 8006b660 */ void (*Unk36)(void *, void **, s32);
    /* 0x098 8006b664 */ void (*Unk37)(void *, void **, s32);
    /* 0x09C 8006b668 */ void (*Unk38)(void *, void **, s32);
    /* 0x0A0 8006b66c */ void (*Unk39)(void *);
    /* 0x0A4 8006b670 */ void (*Unk40)(void *);
    /* 0x0A8 8006b674 */ void (*Unk41)(void *);
    /* 0x0AC 8006b678 */ void (*Unk42)(void *);
    /* 0x0B0 8006b67c */ void (*Unk43)(void *);
    /* 0x0B4 8006b680 */ void (*Unk44)(void *);
} class_D294_vtable_t;

typedef struct class_D294 {
    /* 0x00 */ class_D294_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ void *m_Unk4;
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
} class_D294_t;

class_D294_vtable_t *func_8001E57C(void);

#endif