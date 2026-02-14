#ifndef LSD_326E8_H
#define LSD_326E8_H

#include <common.h>

typedef struct class_326E8_vtable {
    /* 0x000 8006ee1c */ u32 value;
    /* 0x004 8006ee20 */ void (*Destroy)(void *);
    /* 0x008 8006ee24 */ void (*Construct)(void *, s32, s32, s32, s32, s32);
    /* 0x00C 8006ee28 */ void (*Cleanup)(void *);
    /* 0x010 8006ee2c */ void (*Unk3)(void *);
    /* 0x014 8006ee30 */ void (*Unk4)(void *);
    /* 0x018 8006ee34 */ void (*Unk5)(void *);
    /* 0x01C 8006ee38 */ void (*Unk6)(void *);
    /* 0x020 8006ee3c */ void (*Unk7)(void *);
    /* 0x024 8006ee40 */ void (*Unk8)(void *);
    /* 0x028 8006ee44 */ void (*Unk9)(void *);
    /* 0x02C 8006ee48 */ void (*Unk10)(void *);
    /* 0x030 8006ee4c */ void (*Unk11)(void *);
    /* 0x034 8006ee50 */ void (*Unk12)(void *);
    /* 0x038 8006ee54 */ void (*Unk13)(void *);
    /* 0x03C 8006ee58 */ void (*Unk14)(void *);
    /* 0x040 8006ee5c */ void (*Unk15)(void *, s32, s32, s32, s32, s32);
    /* 0x044 8006ee60 */ void (*Unk16)(void *);
    /* 0x048 8006ee64 */ void (*Unk17)(void *);
    /* 0x04C 8006ee68 */ void (*Unk18)(void *);
    /* 0x050 8006ee6c */ void (*Unk19)(void *);
    /* 0x054 8006ee70 */ void (*Unk20)(void *);
    /* 0x058 8006ee74 */ void (*Unk21)(void *);
    /* 0x05C 8006ee78 */ void (*Unk22)(void *);
    /* 0x060 8006ee7c */ void (*Unk23)(void *);
    /* 0x064 8006ee80 */ void (*Unk24)(void *);
    /* 0x068 8006ee84 */ void (*Unk25)(void *);
    /* 0x06C 8006ee88 */ void (*Unk26)(void *);
    /* 0x070 8006ee8c */ void (*Unk27)(void *);
    /* 0x074 8006ee90 */ void (*Unk28)(void *);
    /* 0x078 8006ee94 */ void (*Unk29)(void *);
    /* 0x07C 8006ee98 */ void (*Unk30)(void *);
    /* 0x080 8006ee9c */ void (*Unk31)(void *);
    /* 0x084 8006eea0 */ void (*Unk32)(void *);
    /* 0x088 8006eea4 */ void (*Unk33)(void *);
    /* 0x08C 8006eea8 */ void (*Unk34)(void *);
    /* 0x090 8006eeac */ void (*Unk35)(void *);
    /* 0x094 8006eeb0 */ void (*Unk36)(void *);
    /* 0x098 8006eeb4 */ void (*Unk37)(void *);
    /* 0x09C 8006eeb8 */ void (*Unk38)(void *);
    /* 0x0A0 8006eebc */ void (*Unk39)(void *);
    /* 0x0A4 8006eec0 */ void (*Unk40)(void *);
    /* 0x0A8 8006eec4 */ void (*Unk41)(void *);
    /* 0x0AC 8006eec8 */ void (*Unk42)(void *);
    /* 0x0B0 8006eecc */ void (*Unk43)(void *);
    /* 0x0B4 8006eed0 */ void (*Unk44)(void *);
    /* 0x0B8 8006eed4 */ void (*Unk45)(void *);
} class_326E8_vtable_t;

typedef struct class_326E8 {
    /* 0x00 */ class_326E8_vtable_t *vtable;
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
    /* 0x78 */ s8 m_Unk29[4];
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
} class_326E8_t;

class_326E8_vtable_t *func_800422BC(void);

#endif