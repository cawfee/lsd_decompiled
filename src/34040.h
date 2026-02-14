#ifndef LSD_34040_H
#define LSD_34040_H

#include <common.h>

typedef struct class_34040_vtable {
    /* 0x000 8006f13c */ u32 value;
    /* 0x004 8006f140 */ void (*Destroy)(void *);
    /* 0x008 8006f144 */ s32 (*Construct)(void *, s32);
    /* 0x00C 8006f148 */ void (*Cleanup)(void *);
    /* 0x010 8006f14c */ void (*Unk3)(void *);
    /* 0x014 8006f150 */ void (*Unk4)(void *);
    /* 0x018 8006f154 */ void (*Unk5)(void *);
    /* 0x01C 8006f158 */ void (*Unk6)(void *);
    /* 0x020 8006f15c */ void (*Unk7)(void *);
    /* 0x024 8006f160 */ void (*Unk8)(void *);
    /* 0x028 8006f164 */ void (*Unk9)(void *);
    /* 0x02C 8006f168 */ void (*Unk10)(void *);
    /* 0x030 8006f16c */ void (*Unk11)(void *);
    /* 0x034 8006f170 */ void (*Unk12)(void *);
    /* 0x038 8006f174 */ void (*Unk13)(void *);
    /* 0x03C 8006f178 */ void (*Unk14)(void *);
    /* 0x040 8006f17c */ void (*Unk15)(void *);
    /* 0x044 8006f180 */ void (*Unk16)(void *);
    /* 0x048 8006f184 */ void (*Unk17)(void *);
    /* 0x04C 8006f188 */ void (*Unk18)(void *);
    /* 0x050 8006f18c */ void (*Unk19)(void *);
    /* 0x054 8006f190 */ void (*Unk20)(void *);
    /* 0x058 8006f194 */ void (*Unk21)(void *);
    /* 0x05C 8006f198 */ void (*Unk22)(void *);
    /* 0x060 8006f19c */ void (*Unk23)(void *);
    /* 0x064 8006f1a0 */ void (*Unk24)(void *);
    /* 0x068 8006f1a4 */ void (*Unk25)(void *);
    /* 0x06C 8006f1a8 */ void (*Unk26)(void *);
    /* 0x070 8006f1ac */ void (*Unk27)(void *);
    /* 0x074 8006f1b0 */ void (*Unk28)(void *);
    /* 0x078 8006f1b4 */ void (*Unk29)(void *);
    /* 0x07C 8006f1b8 */ void (*Unk30)(void *);
    /* 0x080 8006f1bc */ void (*Unk31)(void *);
    /* 0x084 8006f1c0 */ void (*Unk32)(void *);
    /* 0x088 8006f1c4 */ void (*Unk33)(void *);
} class_34040_vtable_t;

typedef struct class_34040 {
    /* 0x00 */ class_34040_vtable_t *vtable;
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
} class_34040_t;

class_34040_vtable_t *func_80043B78(void);

#endif // LSD_34040_H