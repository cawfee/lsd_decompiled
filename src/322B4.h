#ifndef LSD_322B4_H
#define LSD_322B4_H

#include <common.h>

typedef struct class_322B4_vtable {
    /* 0x000 8006ec74 */ u32 value;
    /* 0x004 8006ec78 */ void (*Destroy)(void *);
    /* 0x008 8006ec7c */ void (*Construct)(void *, s32, u8);
    /* 0x00C 8006ec80 */ void (*Cleanup)(void *);
    /* 0x010 8006ec84 */ void (*Unk3)(void *);
    /* 0x014 8006ec88 */ void (*Unk4)(void *);
    /* 0x018 8006ec8c */ void (*Unk5)(void *);
    /* 0x01C 8006ec90 */ void (*Unk6)(void *);
    /* 0x020 8006ec94 */ void (*Unk7)(void *);
    /* 0x024 8006ec98 */ void (*Unk8)(void *);
    /* 0x028 8006ec9c */ void (*Unk9)(void *);
    /* 0x02C 8006eca0 */ void (*Unk10)(void *);
    /* 0x030 8006eca4 */ void (*Unk11)(void *);
    /* 0x034 8006eca8 */ void (*Unk12)(void *);
    /* 0x038 8006ecac */ void (*Unk13)(void *);
    /* 0x03C 8006ecb0 */ void (*Unk14)(void *);
    /* 0x040 8006ecb4 */ void (*Unk15)(void *, u8);
    /* 0x044 8006ecb8 */ void (*Unk16)(void *);
    /* 0x048 8006ecbc */ void (*Unk17)(void *);
    /* 0x04C 8006ecc0 */ void (*Unk18)(void *);
    /* 0x050 8006ecc4 */ void (*Unk19)(void *);
    /* 0x054 8006ecc8 */ void (*Unk20)(void *);
    /* 0x058 8006eccc */ void (*Unk21)(void *);
    /* 0x05C 8006ecd0 */ void (*Unk22)(void *);
    /* 0x060 8006ecd4 */ void (*Unk23)(void *);
    /* 0x064 8006ecd8 */ void (*Unk24)(void *);
    /* 0x068 8006ecdc */ void (*Unk25)(void *);
    /* 0x06C 8006ece0 */ void (*Unk26)(void *);
    /* 0x070 8006ece4 */ void (*Unk27)(void *);
    /* 0x074 8006ece8 */ void (*Unk28)(void *);
    /* 0x078 8006ecec */ void (*Unk29)(void *);
    /* 0x07C 8006ecf0 */ void (*Unk30)(void *);
    /* 0x080 8006ecf4 */ void (*Unk31)(void *);
    /* 0x084 8006ecf8 */ void (*Unk32)(void *);
    /* 0x088 8006ecfc */ void (*Unk33)(void *);
    /* 0x08C 8006ed00 */ void (*Unk34)(void *);
    /* 0x090 8006ed04 */ void (*Unk35)(void *);
    /* 0x094 8006ed08 */ void (*Unk36)(void *);
    /* 0x098 8006ed0c */ void (*Unk37)(void *);
    /* 0x09C 8006ed10 */ void (*Unk38)(void *);
    /* 0x0A0 8006ed14 */ void (*Unk39)(void *);
    /* 0x0A4 8006ed18 */ void (*Unk40)(void *);
    /* 0x0A8 8006ed1c */ void (*Unk41)(void *);
    /* 0x0AC 8006ed20 */ void (*Unk42)(void *);
    /* 0x0B0 8006ed24 */ void (*Unk43)(void *);
    /* 0x0B4 8006ed28 */ void (*Unk44)(void *);
    /* 0x0B8 8006ed2c */ void (*Unk45)(void *);
    /* 0x0BC 8006ed30 */ void (*Unk46)(void *);
    /* 0x0C0 8006ed34 */ void (*Unk47)(void *);
    /* 0x0C4 8006ed38 */ void (*Unk48)(void *);
    /* 0x0C8 8006ed3c */ void (*Unk49)(void *);
} class_322B4_vtable_t;

typedef struct class_322B4 {
    /* 0x00 */ class_322B4_vtable_t *vtable;
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
    /* 0x74 */ s32 m_Unk28;
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
    /* 0xAC */ s32 m_Unk42;
} class_322B4_t;

class_322B4_vtable_t *func_80041C3C(void);

#endif