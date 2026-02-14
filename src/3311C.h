#ifndef LSD_3311C_H
#define LSD_3311C_H

#include <common.h>

typedef struct class_3311C_vtable {
    /* 0x000 8006f06c */ u32 value;
    /* 0x004 8006f070 */ void (*Destroy)(void *);
    /* 0x008 8006f074 */ void (*Construct)(void *, s32);
    /* 0x00C 8006f078 */ void (*Cleanup)(void *);
    /* 0x010 8006f07c */ void (*Unk3)(void *);
    /* 0x014 8006f080 */ void (*Unk4)(void *);
    /* 0x018 8006f084 */ void (*Unk5)(void *);
    /* 0x01C 8006f088 */ void (*Unk6)(void *);
    /* 0x020 8006f08c */ void (*Unk7)(void *);
    /* 0x024 8006f090 */ void (*Unk8)(void *);
    /* 0x028 8006f094 */ void (*Unk9)(void *);
    /* 0x02C 8006f098 */ void (*Unk10)(void *);
    /* 0x030 8006f09c */ void (*Unk11)(void *);
    /* 0x034 8006f0a0 */ void (*Unk12)(void *);
    /* 0x038 8006f0a4 */ void (*Unk13)(void *);
    /* 0x03C 8006f0a8 */ void (*Unk14)(void *);
    /* 0x040 8006f0ac */ void (*Unk15)(void *, s32);
    /* 0x044 8006f0b0 */ void (*Unk16)(void *);
    /* 0x048 8006f0b4 */ void (*Unk17)(void *);
    /* 0x04C 8006f0b8 */ void (*Unk18)(void *);
} class_3311C_vtable_t;

typedef struct class_3311C {
    /* 0x00 */ class_3311C_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s8 m_Unk6[4];
    /* 0x20 */ s32 m_Unk7;
} class_3311C_t;

class_3311C_vtable_t *func_80042A7C();

#endif // LSD_3311C_H