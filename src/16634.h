#ifndef LSD_16334_H
#define LSD_16334_H

#include <common.h>

typedef struct class_16634_vtable {
    /* 0x000 8006d370 */ u32 value;
    /* 0x004 8006d374 */ void (*Destroy)(void *);
    /* 0x008 8006d378 */ void (*Construct)(void *, s32, s32);
    /* 0x00C 8006d37c */ void (*Cleanup)(void *);
    /* 0x010 8006d380 */ void (*Unk3)(void *);
    /* 0x014 8006d384 */ void (*Unk4)(void *);
    /* 0x018 8006d388 */ void (*Unk5)(void *);
    /* 0x01C 8006d38c */ void (*Unk6)(void *);
    /* 0x020 8006d390 */ void (*Unk7)(void *);
    /* 0x024 8006d394 */ void (*Unk8)(void *);
    /* 0x028 8006d398 */ void (*Unk9)(void *);
    /* 0x02C 8006d39c */ void (*Unk10)(void *);
    /* 0x030 8006d3a0 */ void (*Unk11)(void *);
    /* 0x034 8006d3a4 */ void (*Unk12)(void *);
    /* 0x038 8006d3a8 */ void (*Unk13)(void *);
    /* 0x03C 8006d3ac */ u32 pad;
    /* 0x040 8006d3b0 */ void (*Unk15)(void *);
    /* 0x044 8006d3b4 */ void (*Unk16)(void *);
    /* 0x048 8006d3b8 */ void (*Unk17)(void *);
    /* 0x04C 8006d3bc */ void (*Unk18)(void *);
    /* 0x050 8006d3c0 */ void (*Unk19)();
    /* 0x054 8006d3c4 */ void (*Unk20)(void *);
} class_16634_vtable_t;

typedef struct class_16634 {
    /* 0x00 */ class_16634_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ u16 m_Unk2_1;
    s16 m_Unk2_2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
} class_16634_t;

class_16634_t *func_80025B34(s32 Unk1, s32 Unk2);
class_16634_vtable_t *func_80025E9C(void);

#endif