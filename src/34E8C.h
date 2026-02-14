#ifndef LSD_34E8C_H
#define LSD_34E8C_H

#include <common.h>

typedef struct class_34E8C_vtable {
    /* 0x000 8006f384 */ u32 value;
    /* 0x004 8006f388 */ void (*Destroy)(void *);
    /* 0x008 8006f38c */ s32 (*Construct)(void *, s32, s32);
    /* 0x00C 8006f390 */ void (*Cleanup)(void *);
    /* 0x010 8006f394 */ void (*Unk3)(void *);
    /* 0x014 8006f398 */ void (*Unk4)(void *);
    /* 0x018 8006f39c */ void (*Unk5)(void *);
    /* 0x01C 8006f3a0 */ void (*Unk6)(void *);
    /* 0x020 8006f3a4 */ void (*Unk7)(void *);
    /* 0x024 8006f3a8 */ void (*Unk8)(void *);
    /* 0x028 8006f3ac */ void (*Unk9)(void *);
    /* 0x02C 8006f3b0 */ void (*Unk10)(void *);
    /* 0x030 8006f3b4 */ void (*Unk11)(void *);
    /* 0x034 8006f3b8 */ void (*Unk12)(void *);
    /* 0x038 8006f3bc */ void (*Unk13)(void *);
    /* 0x03C 8006f3c0 */ void (*Unk14)(void *);
    /* 0x040 8006f3c4 */ void (*Unk15)(void *);
    /* 0x044 8006f3c8 */ void (*Unk16)(void *);
    /* 0x048 8006f3cc */ void (*Unk17)(void *);
    /* 0x04C 8006f3d0 */ void (*Unk18)(void *);
    /* 0x050 8006f3d4 */ void (*Unk19)(void *);
    /* 0x054 8006f3d8 */ void (*Unk20)(void *);
    /* 0x058 8006f3dc */ void (*Unk21)(void *);
    /* 0x05C 8006f3e0 */ void (*Unk22)(void *);
    /* 0x060 8006f3e4 */ void (*Unk23)(void *);
    /* 0x064 8006f3e8 */ void (*Unk24)(void *);
    /* 0x068 8006f3ec */ void (*Unk25)(void *);
    /* 0x06C 8006f3f0 */ void (*Unk26)(void *);
    /* 0x070 8006f3f4 */ void (*Unk27)(void *);
    /* 0x074 8006f3f8 */ void (*Unk28)(void *);
    /* 0x078 8006f3fc */ void (*Unk29)(void *);
    /* 0x07C 8006f400 */ void (*Unk30)(void *);
    /* 0x080 8006f404 */ void (*Unk31)(void *);
    /* 0x084 8006f408 */ void (*Unk32)(void *);
    /* 0x088 8006f40c */ void (*Unk33)(void *);
} class_34E8C_vtable_t;

typedef struct class_34E8C {
    /* 0x00 */ class_34E8C_vtable_t *vtable;
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
} class_34E8C_t;

class_34E8C_vtable_t *func_800449FC(void);

#endif // LSD_34E8C_H