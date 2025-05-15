#ifndef LSD_3DB8C_H
#define LSD_3DB8C_H

#include <common.h>

typedef struct class_3DB8C_vtable {
    /* 0x000 80086aa0 */ u32 value;
    /* 0x004 80086aa4 */ void (*Destroy)(void *);
    /* 0x008 80086aa8 */ void (*Construct)(void *);
    /* 0x00C 80086aac */ void (*Cleanup)(void *);
    /* 0x010 80086ab0 */ void (*Unk3)(void *);
    /* 0x014 80086ab4 */ void (*Unk4)(void *);
    /* 0x018 80086ab8 */ void (*Unk5)(void *);
    /* 0x01C 80086abc */ void (*Unk6)(void *);
    /* 0x020 80086ac0 */ void (*Unk7)(void *);
    /* 0x024 80086ac4 */ void (*Unk8)(void *);
    /* 0x028 80086ac8 */ void (*Unk9)(void *);
    /* 0x02C 80086acc */ void (*Unk10)(void *);
    /* 0x030 80086ad0 */ void (*Unk11)(void *);
    /* 0x034 80086ad4 */ void (*Unk12)(void *);
    /* 0x038 80086ad8 */ void (*Unk13)(void *);
    /* 0x03C 80086adc */ void (*Unk14)(void *);
    /* 0x040 80086ae0 */ void (*Unk15)(void *);
    /* 0x044 80086ae4 */ void (*Unk16)(void *);
    /* 0x048 80086ae8 */ void (*Unk17)(void *);
    /* 0x04C 80086aec */ void (*Unk18)(void *);
    /* 0x050 80086af0 */ void (*Unk19)(void *);
    /* 0x054 80086af4 */ void (*Unk20)(void *);
    /* 0x058 80086af8 */ void (*Unk21)(void *);
    /* 0x05C 80086afc */ void (*Unk22)(void *);
    /* 0x060 80086b00 */ void (*Unk23)(void *);
    /* 0x064 80086b04 */ void (*Unk24)(void *);
    /* 0x068 80086b08 */ void (*Unk25)(void *);
    /* 0x06C 80086b0c */ void (*Unk26)(void *);
    /* 0x070 80086b10 */ void (*Unk27)(void *);
    /* 0x074 80086b14 */ void (*Unk28)(void *);
    /* 0x078 80086b18 */ void (*Unk29)(void *);
    /* 0x07C 80086b1c */ void (*Unk30)(void *);
    /* 0x080 80086b20 */ void (*Unk31)(void *);
    /* 0x084 80086b24 */ void (*Unk32)(void *);
    /* 0x088 80086b28 */ void (*Unk33)(void *);
    /* 0x08C 80086b2c */ void (*Unk34)(void *);
    /* 0x090 80086b30 */ void (*Unk35)(void *);
    /* 0x094 80086b34 */ void (*Unk36)(void *);
    /* 0x098 80086b38 */ void (*Unk37)(void *);
    /* 0x09C 80086b3c */ void (*Unk38)(void *);
    /* 0x0A0 80086b40 */ void (*Unk39)(void *, void **, s32);
    /* 0x0A4 80086b44 */ void (*Unk40)(void *);
    /* 0x0A8 80086b48 */ void (*Unk41)(void *);
    /* 0x0AC 80086b4c */ void (*Unk42)(void *);
    /* 0x0B0 80086b50 */ void (*Unk43)(void *);
    /* 0x0B4 80086b54 */ void (*Unk44)(void *);
    /* 0x0B8 80086b58 */ void (*Unk45)(void *);
    /* 0x0BC 80086b5c */ void (*Unk46)(void *);
} class_3DB8C_vtable_t;

typedef struct class_3DB8C {
    /* 0x00 */ class_3DB8C_vtable_t *vtable;
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
    /* 0x34 */ s16 m_Unk12_1;
    /* 0x36 */ s16 m_Unk12_2;
    /* 0x38 */ s32 m_Unk13;
    /* 0x3C */ s32 m_Unk14;
} class_3DB8C_t;

class_3DB8C_vtable_t *func_8004D508(void);

#endif