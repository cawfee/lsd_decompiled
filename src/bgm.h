#ifndef LSD_BGM_H
#define LSD_BGM_H

#include <common.h>

#include "sound_engine.h"

typedef struct bgm_vtable {
    /* 0x000 8006e48c */ u32 value;
    /* 0x004 8006e490 */ void (*Destroy)(void *);
    /* 0x008 8006e494 */ void (*Construct)(void *, s32, s32, s32);
    /* 0x00C 8006e498 */ void (*Cleanup)(void *);
    /* 0x010 8006e49c */ void (*Unk3)(void *, void *);
    /* 0x014 8006e4a0 */ void (*Unk4)(void *, void *);
    /* 0x018 8006e4a4 */ void (*Unk5)(void *);
    /* 0x01C 8006e4a8 */ void (*Unk6)(void *);
    /* 0x020 8006e4ac */ void (*Unk7)(void *);
    /* 0x024 8006e4b0 */ void (*Unk8)(void *);
    /* 0x028 8006e4b4 */ void (*Unk9)(void *);
    /* 0x02C 8006e4b8 */ void (*Unk10)(void *);
    /* 0x030 8006e4bc */ void (*Unk11)(void *);
    /* 0x034 8006e4c0 */ void (*Unk12)(void *);
    /* 0x038 8006e4c4 */ void (*Unk13)(void *);
    /* 0x03C 8006e4c8 */ void (*Unk14)(void *);
    /* 0x040 8006e4cc */ void (*Unk15)(void *, void **, s32);
    /* 0x044 8006e4d0 */ void (*Unk16)(void *);
    /* 0x048 8006e4d4 */ void (*Unk17)(void *);
    /* 0x04C 8006e4d8 */ void (*Unk18)(void *);
    /* 0x050 8006e4dc */ void (*Unk19)(void *);
    /* 0x054 8006e4e0 */ void (*Unk20)(void *);
    /* 0x058 8006e4e4 */ void (*Unk21)(void *);
    /* 0x05C 8006e4e8 */ void (*Unk22)(void *, s32);
    /* 0x060 8006e4ec */ void (*Unk23)(void *, s32);
} bgm_vtable_t;

typedef struct bgm {
    /* 0x00 */ bgm_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ sound_engine_t *m_SoundEngine;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s16 m_SeqAccess;
    /* 0x16 */ s16 m_Unk4_2;
    /* 0x18 */ u16 m_Unk5_1;
    /* 0x20 */ u16 m_IsOpened;
    /* 0x1C */ u16 m_Unk6_1;
    /* 0x1E */ u16 m_Unk6_2;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
} bgm_t;

bgm_vtable_t *bgm_get_vtable(void);

#endif