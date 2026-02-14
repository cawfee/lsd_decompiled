#ifndef LSD_30CD0_H
#define LSD_30CD0_H

#include <common.h>

typedef struct class_30CD0_vtable {
    /* 0x000 8006eac0 */ u32 value;
    /* 0x004 8006eac4 */ void (*Destroy)(void *);
    /* 0x008 8006eac8 */ void (*Construct)(void *, u32, u32, u32);
    /* 0x00C 8006eacc */ void (*Cleanup)(void *);
    /* 0x010 8006ead0 */ void (*Unk3)(void *);
    /* 0x014 8006ead4 */ void (*Unk4)(void *);
    /* 0x018 8006ead8 */ void (*Unk5)(void *);
    /* 0x01C 8006eadc */ void (*Unk6)(void *);
    /* 0x020 8006eae0 */ void (*Unk7)(void *);
    /* 0x024 8006eae4 */ void (*Unk8)(void *);
    /* 0x028 8006eae8 */ void (*Unk9)(void *);
    /* 0x02C 8006eaec */ void (*Unk10)(void *);
    /* 0x030 8006eaf0 */ void (*Unk11)(void *);
    /* 0x034 8006eaf4 */ void (*Unk12)(void *);
    /* 0x038 8006eaf8 */ void (*Unk13)(void *);
    /* 0x03C 8006eafc */ void (*Unk14)(void *);
    /* 0x040 8006eb00 */ void (*Unk15)(void *);
    /* 0x044 8006eb04 */ void (*Unk16)(void *);
    /* 0x048 8006eb08 */ void (*Unk17)(void *);
    /* 0x04C 8006eb0c */ void (*Unk18)(void *, s32, s32);
    /* 0x050 8006eb10 */ void (*Unk19)(void *);
    /* 0x054 8006eb14 */ void (*Unk20)(void *);
    /* 0x058 8006eb18 */ void (*Unk21)(void *);
    /* 0x05C 8006eb1c */ void (*Unk22)(void *);
    /* 0x060 8006eb20 */ void (*Unk23)(void *);
    /* 0x064 8006eb24 */ void (*Unk24)(void *);
    /* 0x068 8006eb28 */ void (*Unk25)(void *);
    /* 0x06C 8006eb2c */ void (*Unk26)(void *);
    /* 0x070 8006eb30 */ void (*Unk27)(void *);
    /* 0x074 8006eb34 */ void (*Unk28)(void *);
    /* 0x078 8006eb38 */ void (*Unk29)(void *);
    /* 0x07C 8006eb3c */ void (*Unk30)(void *);
    /* 0x080 8006eb40 */ void (*Unk31)(void *);
    /* 0x084 8006eb44 */ void (*Unk32)(void *);
    /* 0x088 8006eb48 */ void (*Unk33)(void *);
    /* 0x08C 8006eb4c */ void (*Unk34)(void *);
    /* 0x090 8006eb50 */ void (*Unk35)(void *);
    /* 0x094 8006eb54 */ void (*Unk36)(void *);
    /* 0x098 8006eb58 */ void (*Unk37)(void *);
    /* 0x09C 8006eb5c */ void (*Unk38)(void *);
    /* 0x0A0 8006eb60 */ void (*Unk39)(void *);
    /* 0x0A4 8006eb64 */ void (*Unk40)(void *);
    /* 0x0A8 8006eb68 */ void (*Unk41)(void *);
    /* 0x0AC 8006eb6c */ void (*Unk42)(void *);
    /* 0x0B0 8006eb70 */ void (*Unk43)(void *);
    /* 0x0B4 8006eb74 */ void (*Unk44)(void *);
    /* 0x0B8 8006eb78 */ void (*Unk45)(void *);
    /* 0x0BC 8006eb7c */ void (*Unk46)(void *);
    /* 0x0C0 8006eb80 */ void (*Unk47)(void *);
    /* 0x0C4 8006eb84 */ void (*Unk48)(void *);
    /* 0x0C8 8006eb88 */ void (*Unk49)(void *);
    /* 0x0CC 8006eb8c */ void (*Unk50)(void *);
    /* 0x0D0 8006eb90 */ void (*Unk51)(void *);
} class_30CD0_vtable_t;

typedef struct class_30CD0 {
    /* 0x00 */ class_30CD0_vtable_t *vtable;
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
    /* 0x60 */ s16 m_Unk23[2];
    /* 0x64 */ s32 m_Unk24;
    /* 0x68 */ s32 m_Unk25;
    /* 0x6C */ s32 m_Unk26;
} class_30CD0_t;

class_30CD0_vtable_t *func_800408BC(void);

#endif // LSD_30CD0_H