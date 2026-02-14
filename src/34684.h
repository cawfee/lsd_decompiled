#ifndef LSD_34684_H
#define LSD_34684_H

#include <common.h>

typedef struct class_34684_vtable {
    /* 0x000 8006f240 */ u32 value;
    /* 0x004 8006f244 */ void (*Destroy)(void *);
    /* 0x008 8006f248 */ void (*Construct)(void *, s32);
    /* 0x00C 8006f24c */ void (*Cleanup)(void *);
    /* 0x010 8006f250 */ void (*Unk3)(void *);
    /* 0x014 8006f254 */ void (*Unk4)(void *);
    /* 0x018 8006f258 */ void (*Unk5)(void *);
    /* 0x01C 8006f25c */ void (*Unk6)(void *);
    /* 0x020 8006f260 */ void (*Unk7)(void *);
    /* 0x024 8006f264 */ void (*Unk8)(void *);
    /* 0x028 8006f268 */ void (*Unk9)(void *);
    /* 0x02C 8006f26c */ void (*Unk10)(void *);
    /* 0x030 8006f270 */ void (*Unk11)(void *);
    /* 0x034 8006f274 */ void (*Unk12)(void *);
    /* 0x038 8006f278 */ void (*Unk13)(void *);
    /* 0x03C 8006f27c */ void (*Unk14)(void *);
    /* 0x040 8006f280 */ void (*Unk15)(void *);
    /* 0x044 8006f284 */ void (*Unk16)(void *);
    /* 0x048 8006f288 */ void (*Unk17)(void *);
    /* 0x04C 8006f28c */ void (*Unk18)(void *);
    /* 0x050 8006f290 */ void (*Unk19)(void *);
    /* 0x054 8006f294 */ void (*Unk20)(void *);
    /* 0x058 8006f298 */ void (*Unk21)(void *);
    /* 0x05C 8006f29c */ void (*Unk22)(void *);
    /* 0x060 8006f2a0 */ void (*Unk23)(void *);
    /* 0x064 8006f2a4 */ void (*Unk24)(void *);
    /* 0x068 8006f2a8 */ void (*Unk25)(void *);
    /* 0x06C 8006f2ac */ void (*Unk26)(void *, s32);
    /* 0x070 8006f2b0 */ void (*Unk27)(void *);
    /* 0x074 8006f2b4 */ void (*Unk28)(void *);
    /* 0x078 8006f2b8 */ void (*Unk29)(void *);
    /* 0x07C 8006f2bc */ u8 (*Unk30)(void *, s32, s32, s32);
    /* 0x080 8006f2c0 */ void (*Unk31)(void *);
    /* 0x084 8006f2c4 */ void (*Unk32)(void *);
} class_34684_vtable_t;

typedef struct class_34684 {
    /* 0x00 */ class_34684_vtable_t *vtable;
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
} class_34684_t;

class_34684_vtable_t *func_800441A4(void);

#endif // LSD_34684_H