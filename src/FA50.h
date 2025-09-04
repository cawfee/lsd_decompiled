#ifndef LSD_FA50_H
#define LSD_FA50_H

#include "common.h"

typedef struct class_FA50_vtable {
    /* 0x000 8006bea0 */ u32 value;
    /* 0x004 8006bea4 */ void (*Destroy)(void *);
    /* 0x008 8006bea8 */ void (*Construct)(void *, s32);
    /* 0x00C 8006beac */ void (*Cleanup)(void *);
    /* 0x010 8006beb0 */ void (*Unk3)(void *);
    /* 0x014 8006beb4 */ void (*Unk4)(void *);
    /* 0x018 8006beb8 */ void (*Unk5)(void *);
    /* 0x01C 8006bebc */ void (*Unk6)(void *);
    /* 0x020 8006bec0 */ void (*Unk7)(void *);
    /* 0x024 8006bec4 */ void (*Unk8)(void *);
    /* 0x028 8006bec8 */ void (*Unk9)(void *);
    /* 0x02C 8006becc */ void (*Unk10)(void *);
    /* 0x030 8006bed0 */ void (*Unk11)(void *);
    /* 0x034 8006bed4 */ void (*Unk12)(void *);
    /* 0x038 8006bed8 */ void (*Unk13)(void *);
    /* 0x03C 8006bedc */ u32 dummy;
    /* 0x040 8006bee0 */ void (*Unk15)(void *);
    /* 0x044 8006bee4 */ void (*Unk16)(void *);
    /* 0x048 8006bee8 */ void (*Unk17)(void *);
    /* 0x04C 8006beec */ void (*Unk18)(void *);
} class_FA50_vtable_t;

typedef struct class_FA50 {
    /* 0x00 */ class_FA50_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ void *m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
} class_FA50_t;

class_FA50_t *class_FA50_create(s32 Unk1);
class_FA50_vtable_t *class_FA50_get_vtable();

#endif // LSD_FA50_H