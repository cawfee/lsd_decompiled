#ifndef LSD_TRANSFORM_H
#define LSD_TRANSFORM_H

#include <common.h>

#include "base/base.h"

typedef struct transform_vtable {
    /* 0x000 8006b5cc */ u32 type_id;
    /* 0x004 8006b5d0 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006b5d4 */ void *(*Construct)(void *);
    /* 0x00C 8006b5d8 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006b5dc */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006b5e0 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006b5e4 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006b5e8 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006b5ec */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006b5f0 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006b5f4 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006b5f8 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006b5fc */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006b600 */ void (*Nop)(base_class_t *);
    /* 0x038 8006b604 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006b608 */ void (*Unk14)(void *);
    /* 0x040 8006b60c */ void (*Unk15)(void *);
    /* 0x044 8006b610 */ void (*Unk16)(void *, s32, s32 *);
    /* 0x048 8006b614 */ void (*Unk17)(void *, s32, s32 *);
    /* 0x04C 8006b618 */ void (*Unk18)(void *);
    /* 0x050 8006b61c */ void (*Unk19)(void *);
    /* 0x054 8006b620 */ void (*Unk20)(void *);
    /* 0x058 8006b624 */ void (*Unk21)(void *, void **, s32 *);
    /* 0x05C 8006b628 */ void (*Unk22)(void *, s32);
    /* 0x060 8006b62c */ void (*Unk23)(void *);
    /* 0x064 8006b630 */ void (*Unk24)(void *);
    /* 0x068 8006b634 */ void (*Unk25)(void *);
    /* 0x06C 8006b638 */ void (*Unk26)(void *);
    /* 0x070 8006b63c */ void (*Unk27)(void *);
    /* 0x074 8006b640 */ void (*Unk28)(void *);
    /* 0x078 8006b644 */ void (*Unk29)(void *);
    /* 0x07C 8006b648 */ void (*Unk30)(void *);
    /* 0x080 8006b64c */ void (*Unk31)(void *);
    /* 0x084 8006b650 */ void (*Unk32)(void *, void *, s32);
    /* 0x088 8006b654 */ void (*Unk33)(void *);
    /* 0x08C 8006b658 */ void (*Unk34)(void *, void *);
    /* 0x090 8006b65c */ s32 (*Unk35)(void *, void *, s32);
    /* 0x094 8006b660 */ void (*Unk36)(void *, void **, s32);
    /* 0x098 8006b664 */ void (*Unk37)(void *, void **, s32);
    /* 0x09C 8006b668 */ void (*Unk38)(void *, void **, s32);
    /* 0x0A0 8006b66c */ void (*Unk39)(void *, s32);
    /* 0x0A4 8006b670 */ void (*Unk40)(void *, void *, void *, void *, s32);
    /* 0x0A8 8006b674 */ s32 (*Unk41)(void *, void *, void *);
    /* 0x0AC 8006b678 */ s32 (*Unk42)(void *, void *, void *, void *);
    /* 0x0B0 8006b67c */ void (*Unk43)(void *);
    /* 0x0B4 8006b680 */ void (*Unk44)(void *);
} transform_vtable_t;

typedef struct transform {
    /* 0x00 */ transform_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ void *m_Unk4;
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
    /* 0x40 */ s32 m_Unk15;
} transform_t;

/* Fixed-point helpers shared by the transform/object-math code.
 * frac_t packs a fraction as two s16: value = num * 4096 / den
 * (see object_math.c func_8001EC84).  fixed_vec3_t is a plain s32 vector in
 * the same 4096-per-unit scale (0x1000 == 1.0). */
typedef struct {
    s16 num;
    s16 den;
} frac_t;
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} fixed_vec3_t;

transform_vtable_t *func_8001E57C(void);

#endif