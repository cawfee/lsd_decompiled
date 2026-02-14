#ifndef LSD_48494_H
#define LSD_48494_H

#include <common.h>

typedef struct class_48494_vtable {
    /* 0x000 800879c4 */ u32 value;
    /* 0x004 800879c8 */ void (*Destroy)(void *);
    /* 0x008 800879cc */ void (*Construct)(void *, s32, s32, s32);
    /* 0x00C 800879d0 */ void (*Cleanup)(void *);
    /* 0x010 800879d4 */ void (*Unk3)(void *);
    /* 0x014 800879d8 */ void (*Unk4)(void *);
    /* 0x018 800879dc */ void (*Unk5)(void *);
    /* 0x01C 800879e0 */ void (*Unk6)(void *);
    /* 0x020 800879e4 */ void (*Unk7)(void *);
    /* 0x024 800879e8 */ void (*Unk8)(void *);
    /* 0x028 800879ec */ void (*Unk9)(void *);
    /* 0x02C 800879f0 */ void (*Unk10)(void *);
    /* 0x030 800879f4 */ void (*Unk11)(void *);
    /* 0x034 800879f8 */ void (*Unk12)(void *);
    /* 0x038 800879fc */ void (*Unk13)(void *);
    /* 0x03C 80087a00 */ void (*Unk14)(void *);
    /* 0x040 80087a04 */ void (*Unk15)(void *);
    /* 0x044 80087a08 */ void (*Unk16)(void *);
    /* 0x048 80087a0c */ void (*Unk17)(void *);
    /* 0x04C 80087a10 */ void (*Unk18)(void *);
    /* 0x050 80087a14 */ void (*Unk19)(void *);
    /* 0x054 80087a18 */ void (*Unk20)(void *);
    /* 0x058 80087a1c */ void (*Unk21)(void *);
    /* 0x05C 80087a20 */ void (*Unk22)(void *);
    /* 0x060 80087a24 */ void (*Unk23)(void *);
    /* 0x064 80087a28 */ void (*Unk24)(void *);
    /* 0x068 80087a2c */ void (*Unk25)(void *);
    /* 0x06C 80087a30 */ void (*Unk26)(void *);
    /* 0x070 80087a34 */ void (*Unk27)(void *);
    /* 0x074 80087a38 */ void (*Unk28)(void *);
    /* 0x078 80087a3c */ void (*Unk29)(void *);
    /* 0x07C 80087a40 */ void (*Unk30)(void *);
    /* 0x080 80087a44 */ void (*Unk31)(void *);
    /* 0x084 80087a48 */ void (*Unk32)(void *);
    /* 0x088 80087a4c */ void (*Unk33)(void *);
    /* 0x08C 80087a50 */ void (*Unk34)(void *);
    /* 0x090 80087a54 */ void (*Unk35)(void *);
    /* 0x094 80087a58 */ void (*Unk36)(void *);
    /* 0x098 80087a5c */ void (*Unk37)(void *);
    /* 0x09C 80087a60 */ void (*Unk38)(void *);
    /* 0x0A0 80087a64 */ void (*Unk39)(void *);
    /* 0x0A4 80087a68 */ void (*Unk40)(void *);
    /* 0x0A8 80087a6c */ void (*Unk41)(void *);
    /* 0x0AC 80087a70 */ void (*Unk42)(void *);
    /* 0x0B0 80087a74 */ void (*Unk43)(void *);
    /* 0x0B4 80087a78 */ void (*Unk44)(void *);
    /* 0x0B8 80087a7c */ void (*Unk45)(void *);
    /* 0x0BC 80087a80 */ void (*Unk46)(void *);
    /* 0x0C0 80087a84 */ void (*Unk47)(void *);
    /* 0x0C4 80087a88 */ void (*Unk48)(void *);
    /* 0x0C8 80087a8c */ void (*Unk49)(void *);
} class_48494_vtable_t;

typedef struct class_48494 {
    /* 0x00 */ class_48494_vtable_t *vtable;
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
    /* 0x6C */ s32 m_Unk26;
    /* 0x70 */ s32 m_Unk27;
    /* 0x74 */ s16 m_Unk28_1;
    /* 0x76 */ s16 m_Unk28_2;
    /* 0x78 */ s32 m_Unk29;
    /* 0x7C */ s32 m_Unk30;
    /* 0x80 */ s32 m_Unk31;
    /* 0x84 */ s32 m_Unk32;
    /* 0x88 */ s32 m_Unk33;
    /* 0x8C */ s32 m_Unk34;
    /* 0x90 */ s32 m_Unk35;
    /* 0x94 */ s32 m_Unk36;
    /* 0x98 */ s32 m_Unk37;
    /* 0x9C */ s32 m_Unk38;
    /* 0xA0 */ s32 m_Unk39;
    /* 0xA4 */ s32 m_Unk40;
    /* 0xA8 */ s32 m_Unk41;
} class_48494_t;

class_48494_vtable_t *func_80057F58(void);

#endif // LSD_48494_H