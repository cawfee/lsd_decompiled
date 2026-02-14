#ifndef LSD_3520C_H
#define LSD_3520C_H

#include <common.h>

typedef struct class_3520C_vtable {
    /* 0x000 8006f40c */ u32 value;
    /* 0x004 8006f410 */ void (*Destroy)(void *);
    /* 0x008 8006f414 */ s32 (*Construct)(void *, s32);
    /* 0x00C 8006f418 */ void (*Cleanup)(void *);
    /* 0x010 8006f41c */ void (*Unk3)(void *);
    /* 0x014 8006f420 */ void (*Unk4)(void *);
    /* 0x018 8006f424 */ void (*Unk5)(void *);
    /* 0x01C 8006f428 */ void (*Unk6)(void *);
    /* 0x020 8006f42c */ void (*Unk7)(void *);
    /* 0x024 8006f430 */ void (*Unk8)(void *);
    /* 0x028 8006f434 */ void (*Unk9)(void *);
    /* 0x02C 8006f438 */ void (*Unk10)(void *);
    /* 0x030 8006f43c */ void (*Unk11)(void *);
    /* 0x034 8006f440 */ void (*Unk12)(void *);
    /* 0x038 8006f444 */ void (*Unk13)(void *);
    /* 0x03C 8006f448 */ void (*Unk14)(void *);
    /* 0x040 8006f44c */ void (*Unk15)(void *);
    /* 0x044 8006f450 */ void (*Unk16)(void *);
    /* 0x048 8006f454 */ void (*Unk17)(void *);
    /* 0x04C 8006f458 */ void (*Unk18)(void *);
    /* 0x050 8006f45c */ void (*Unk19)(void *);
    /* 0x054 8006f460 */ void (*Unk20)(void *);
    /* 0x058 8006f464 */ void (*Unk21)(void *);
    /* 0x05C 8006f468 */ void (*Unk22)(void *);
    /* 0x060 8006f46c */ void (*Unk23)(void *);
    /* 0x064 8006f470 */ void (*Unk24)(void *);
    /* 0x068 8006f474 */ void (*Unk25)(void *);
    /* 0x06C 8006f478 */ void (*Unk26)(void *);
    /* 0x070 8006f47c */ void (*Unk27)(void *);
    /* 0x074 8006f480 */ void (*Unk28)(void *);
    /* 0x078 8006f484 */ void (*Unk29)(void *);
    /* 0x07C 8006f488 */ void (*Unk30)(void *);
    /* 0x080 8006f48c */ void (*Unk31)(void *);
    /* 0x084 8006f490 */ void (*Unk32)(void *);
    /* 0x088 8006f494 */ void (*Unk33)(void *);
    /* 0x08C 8006f498 */ void (*Unk34)(void *);
} class_3520C_vtable_t;

typedef struct class_3520C {
    /* 0x00 */ class_3520C_vtable_t *vtable;
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
} class_3520C_t;

class_3520C_vtable_t *func_80044CC4();

#endif // LSD_3520C_H