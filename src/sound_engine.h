#ifndef LSD_SOUND_ENGINE_H
#define LSD_SOUND_ENGINE_H

#include <common.h>

typedef struct {
    u32 value;
    void (*Destruct)(void *);
    void (*Construct)(void *, s32);
    void (*CallBase3)(void *);
    void (*_Unk4)(void *, void *);
    void (*_Unk5)(void *, void *);
    void (*_Unk6)(void *);
    void (*_Unk7)(void *, void *, void **);
    void (*_Unk8)(void *, void *);
    void (*_Unk9)(void *, void *);
    void (*_Unk10)(void *);
    void (*_Unk11)(void *, void *, void **);
    void (*_Unk12)(void *);
    void (*_Unk13)(void *);
    void (*_Unk14)(void *, void *, void *);
    u32 _pad;
    u32 pad2;
    void (*Unk1)(void *);
    void (*Unk2)(void *);
    void (*Unk3)(void *);
    void (*Unk4)(void *);
    void (*Unk5)(void *);
    void (*Unk6)(void *, char *);
    void (*Unk7)(void *);
    void (*Unk8)(void *);
    void (*Unk9)(void *);
    void (*Unk10)(void *);
    void (*Unk11)(void *);
    void (*Unk12)(void *);
    void (*Unk13)(void *);
    void (*Unk14)(void *, s32);
    void (*Unk15)(void *);
    void (*Unk16)(void *, s32, s32, s32);
    void (*Unk17)(void *);
    void (*Unk18)(void *);
    void (*Unk19)(void *);
    void (*Unk20)(void *);
    void (*Unk21)(void *);
    void (*Unk22)(void *);
    void (*Unk23)(void *, s32);
} sound_engine_vtable_t;

typedef struct sound_engine {
    sound_engine_vtable_t *vtable;
    s32 unk1;
    s32 unk2;
    s32 unk3;
    s32 unk4;
    s32 unk5;
    s32 unk6;
    s32 unk7;
    s32 unk8;
    s32 m_FlagsUnk;
    s16 unk10_1;
    u16 unk10_2;
    s32 unk11;
    s32 unk12;
    s32 unk13;
    s32 unk14;
    s32 unk15;
    s32 unk16;
    s32 unk17;
    s32 unk18;
    s32 unk19;
    s32 unk20;
    s16 unk21_1;
    s16 m_IsMuted;
    u16 unk22_1;
    u16 unk22_2;
    s32 unk23;
    s32 unk24;
    s32 unk25;
} sound_engine_t;

sound_engine_t *sound_engine_create(u32 Unk1);
sound_engine_vtable_t *sound_engine_get_vtable(void);

#endif