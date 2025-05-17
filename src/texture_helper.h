#ifndef LSD_TEXTURE_HELPER_H
#define LSD_TEXTURE_HELPER_H

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
    void (*Unk6)(void *);
    void (*Unk7)(void *);
    void (*Unk8)(void *);
    void (*Unk9)(void *);
    void (*Unk10)(void *);
    void (*Unk11)(void *, s32);
    void (*Unk12)(void *);
    void (*Unk13)(void *);
    void (*Unk14)(void *);
    void (*Unk15)(void *);
    void (*Unk16)(void *);
    void (*Unk17)(void *);
    void (*Unk18)(void *);
    void (*Unk19)(void *);
    void (*Unk20)(void *);
    void (*Unk21)(void *);
    void (*Unk22)(void *);
    void (*Unk23)(void *, void *);
} texture_helper_vtable_t;

typedef struct texture_helper {
    texture_helper_vtable_t *vtable;
    s32 unk1;
    s32 unk2;
    s32 unk3;
    s32 m_Image;
    s32 unk5;
    s32 unk6;
    s32 unk7;
    s32 unk8;
    s32 unk9;
    s32 unk10;
    s32 unk11;
    s32 unk12;
    s32 unk13;
    s32 unk14;
    s32 unk15;
    s32 unk16;
    s32 unk17;
    s32 m_MaybeLoaded; // Unchecked
    s32 unk19;
    s32 unk20;
} texture_helper_t;

texture_helper_t *texture_helper_create(const char *Unk1);
texture_helper_vtable_t *texture_helper_get_vtable(void);

#endif