#ifndef LSD_2B78C_H
#define LSD_2B78C_H

#include <common.h>

#include "16634.h"
#include "gs_helper.h"

typedef struct class_2B78C_vtable {
    /* 0x000 8006E4F0 */ u32 value;
    /* 0x004 8006E4F4 */ void (*Destroy)(void *);
    /* 0x008 8006E4F8 */ void (*Construct)(void *, s32);
    /* 0x00C 8006E4FC */ void (*Cleanup)(void *);
    /* 0x010 8006E500 */ void (*Unk3)(void *, void *);
    /* 0x014 8006E504 */ void (*Unk4)(void *, void *);
    /* 0x018 8006E508 */ void (*Unk5)(void *);
    /* 0x01C 8006E50C */ void (*Unk6)(void *, void *, void **);
    /* 0x020 8006E510 */ void (*Unk7)(void *, void *);
    /* 0x024 8006E514 */ void (*Unk8)(void *, void *);
    /* 0x028 8006E518 */ void (*Unk9)(void *);
    /* 0x02C 8006E51C */ void (*Unk10)(void *, void *, void **);
    /* 0x030 8006E520 */ void (*Unk11)(void *, s32);
    /* 0x034 8006E524 */ void (*Unk12)(void *);
    /* 0x038 8006E528 */ void (*Unk13)(void *, void *, s32);
    /* 0x03C 8006E52C */ void (*Unk14)(void *);
    /* 0x040 8006E530 */ void (*Unk15)(void *, s32 *, s32);
    /* 0x044 8006E534 */ void (*InitGraphics)(void *, gs_helper_t *, class_16634_t *, u32);
    /* 0x048 8006E538 */ void (*Unk17)(void *);
    /* 0x04C 8006E53C */ void (*Unk18)(void *);
} class_2B78C_vtable_t;

typedef struct class_2B78C {
    /* 0x00 */ class_2B78C_vtable_t *vtable;
    /* 0x04 */ void *m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
} class_2B78C_t;

class_2B78C_vtable_t *func_8003B20C(void);

#endif