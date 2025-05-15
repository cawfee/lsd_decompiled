#ifndef LSD_3249C_H
#define LSD_3249C_H

#include <common.h>

typedef struct class_3249C_vtable {
    /* 0x000 8006ed4c */ u32 value;
    /* 0x004 8006ed50 */ void (*Destroy)(void *);
    /* 0x008 8006ed54 */ void (*Construct)(void *, s32, s32, s32);
    /* 0x00C 8006ed58 */ void (*Cleanup)(void *);
    /* 0x010 8006ed5c */ void (*Unk3)(void *);
    /* 0x014 8006ed60 */ void (*Unk4)(void *);
    /* 0x018 8006ed64 */ void (*Unk5)(void *);
    /* 0x01C 8006ed68 */ void (*Unk6)(void *);
    /* 0x020 8006ed6c */ void (*Unk7)(void *);
    /* 0x024 8006ed70 */ void (*Unk8)(void *);
    /* 0x028 8006ed74 */ void (*Unk9)(void *);
    /* 0x02C 8006ed78 */ void (*Unk10)(void *);
    /* 0x030 8006ed7c */ void (*Unk11)(void *);
    /* 0x034 8006ed80 */ void (*Unk12)(void *);
    /* 0x038 8006ed84 */ void (*Unk13)(void *);
    /* 0x03C 8006ed88 */ void (*Unk14)(void *);
    /* 0x040 8006ed8c */ void (*Unk15)(void *);
    /* 0x044 8006ed90 */ void (*Unk16)(void *);
    /* 0x048 8006ed94 */ void (*Unk17)(void *);
    /* 0x04C 8006ed98 */ void (*Unk18)(void *);
    /* 0x050 8006ed9c */ void (*Unk19)(void *);
    /* 0x054 8006eda0 */ void (*Unk20)(void *);
    /* 0x058 8006eda4 */ void (*Unk21)(void *);
    /* 0x05C 8006eda8 */ void (*Unk22)(void *);
    /* 0x060 8006edac */ void (*Unk23)(void *);
    /* 0x064 8006edb0 */ void (*Unk24)(void *);
    /* 0x068 8006edb4 */ void (*Unk25)(void *);
    /* 0x06C 8006edb8 */ void (*Unk26)(void *);
    /* 0x070 8006edbc */ void (*Unk27)(void *);
    /* 0x074 8006edc0 */ void (*Unk28)(void *);
    /* 0x078 8006edc4 */ void (*Unk29)(void *);
    /* 0x07C 8006edc8 */ void (*Unk30)(void *);
    /* 0x080 8006edcc */ void (*Unk31)(void *);
    /* 0x084 8006edd0 */ void (*Unk32)(void *);
    /* 0x088 8006edd4 */ void (*Unk33)(void *);
    /* 0x08C 8006edd8 */ void (*Unk34)(void *);
    /* 0x090 8006eddc */ void (*Unk35)(void *);
    /* 0x094 8006ede0 */ void (*Unk36)(void *);
    /* 0x098 8006ede4 */ void (*Unk37)(void *);
    /* 0x09C 8006ede8 */ void (*Unk38)(void *);
    /* 0x0A0 8006edec */ void (*Unk39)(void *);
    /* 0x0A4 8006edf0 */ void (*Unk40)(void *);
    /* 0x0A8 8006edf4 */ void (*Unk41)(void *);
    /* 0x0AC 8006edf8 */ void (*Unk42)(void *);
    /* 0x0B0 8006edfc */ void (*Unk43)(void *);
    /* 0x0B4 8006ee00 */ void (*Unk44)(void *);
    /* 0x0B8 8006ee04 */ void (*Unk45)(void *);
    /* 0x0BC 8006ee08 */ void (*Unk46)(void *);
    /* 0x0C0 8006ee0c */ void (*Unk47)(void *);
} class_3249C_vtable_t;

typedef struct class_3249C {
    /* 0x00 */ class_3249C_vtable_t *vtable;
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
} class_3249C_t;

class_3249C_vtable_t *func_80041ED8(void);

#endif