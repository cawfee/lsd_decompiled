#ifndef LSD_TIM_IMAGE_H
#define LSD_TIM_IMAGE_H

#include <common.h>
#include <psx/libgs.h>

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
} tim_image_vtable_t;

typedef struct tim_image {
    /* 0x00 */ tim_image_vtable_t *vtable;
    /* 0x04 */ s32 unk1;
    /* 0x08 */ s32 unk2;
    /* 0x0C */ s32 unk3;
    /* 0x10 */ s32 m_Image;
    /* 0x14 */ s32 unk5;
    /* 0x18 */ s32 unk6;
    /* 0x1C */ s32 unk7;
    /* 0x20 */ s32 unk8;
    /* 0x24 */ s32 unk9;
    /* 0x28 */ s32 unk10;
    /* 0x2C */ gs_image_t m_TimInfo;
    /* 0x48 */ s32 m_MaybeLoaded;
    /* 0x4C */ s32 unk19;
} tim_image_t;

tim_image_t *tim_image_create(const char *Unk1);
tim_image_vtable_t *tim_image_get_vtable(void);

#endif