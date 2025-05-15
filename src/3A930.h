#ifndef LSD_3A930_H
#define LSD_3A930_H

#include <common.h>

#include "sound_engine.h"

typedef struct class_3A930_vtable {
    /* 0x000 80086668 */ u32 value;
    /* 0x004 8008666c */ void (*Destroy)(void *);
    /* 0x008 80086670 */ void (*Construct)(void *, s32, s32);
    /* 0x00C 80086674 */ void (*Cleanup)(void *);
    /* 0x010 80086678 */ void (*Unk3)(void *);
    /* 0x014 8008667c */ void (*Unk4)(void *);
    /* 0x018 80086680 */ void (*Unk5)(void *);
    /* 0x01C 80086684 */ void (*Unk6)(void *);
    /* 0x020 80086688 */ void (*Unk7)(void *);
    /* 0x024 8008668c */ void (*Unk8)(void *);
    /* 0x028 80086690 */ void (*Unk9)(void *);
    /* 0x02C 80086694 */ void (*Unk10)(void *);
    /* 0x030 80086698 */ void (*Unk11)(void *);
    /* 0x034 8008669c */ void (*Unk12)(void *);
    /* 0x038 800866a0 */ void (*Unk13)(void *, void **, s32);
    /* 0x03C 800866a4 */ void (*Unk14)(void *);
    /* 0x040 800866a8 */ void (*Unk15)(void *);
    /* 0x044 800866ac */ void (*Unk16)(void *, s32, s32);
    /* 0x048 800866b0 */ void (*Unk17)(void *);
    /* 0x04C 800866b4 */ void (*Unk18)(void *);
    /* 0x050 800866b8 */ void (*Unk19)(void *);
    /* 0x054 800866bc */ void (*Unk20)(void *);
    /* 0x058 800866c0 */ void (*Unk21)(void *);
    /* 0x05C 800866c4 */ void (*Unk22)(void *);
    /* 0x060 800866c8 */ void (*Unk23)(void *, s32);
    /* 0x064 800866cc */ void (*Unk24)(void *);
    /* 0x068 800866d0 */ void (*Unk25)(void *);
    /* 0x06C 800866d4 */ void (*Unk26)(void *, s32);
    /* 0x070 800866d8 */ void (*Unk27)(void *);
    /* 0x074 800866dc */ void (*Unk28)(void *);
    /* 0x074 800866E0 */ void (*Unk29)(void *);
    /* 0x074 800866E4 */ void (*Unk30)(void *);
} class_3A930_vtable_t;

typedef struct class_3A930 {
    /* 0x00 */ class_3A930_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ u32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ s32 m_Unk10;
    /* 0x30 */ void *m_Unk11;
    /* 0x34 */ sound_engine_t *m_SoundEngine;
    /* 0x38 */ s32 m_Unk13;
} class_3A930_t;

class_3A930_vtable_t *func_8004A4B8(void);

#endif