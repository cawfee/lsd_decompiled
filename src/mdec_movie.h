#ifndef LSD_MDEC_MOVIE_H
#define LSD_MDEC_MOVIE_H

#include <common.h>

#include "base_class.h"

typedef struct mdec_movie_vtable {
    /* 0x000 8006f614 */ u32 type_id;
    /* 0x004 8006f618 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006f61c */ s32 (*Construct)(void *, s32, s32, s32);
    /* 0x00C 8006f620 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006f624 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006f628 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006f62c */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006f630 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006f634 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006f638 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006f63c */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006f640 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006f644 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006f648 */ void (*Nop)(base_class_t *);
    /* 0x038 8006f64c */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006f650 */ void (*Unk14)(void *);
    /* 0x040 8006f654 */ void (*Unk15)(void *);
    /* 0x044 8006f658 */ void (*Unk16)(void *);
    /* 0x048 8006f65c */ void (*Unk17)(void *);
    /* 0x04C 8006f660 */ void (*Unk18)(void *);
    /* 0x050 8006f664 */ void (*Unk19)(void *);
    /* 0x054 8006f668 */ void (*Unk20)(void *);
    /* 0x058 8006f66c */ void (*Unk21)(void *);
    /* 0x05C 8006f670 */ void (*Unk22)(void *);
    /* 0x060 8006f674 */ void (*Unk23)(void *);
    /* 0x064 8006f678 */ void (*Unk24)(void *);
    /* 0x068 8006f67c */ void (*Unk25)(void *);
    /* 0x06C 8006f680 */ void (*Unk26)(void *);
    /* 0x070 8006f684 */ void (*Unk27)(void *);
} mdec_movie_vtable_t;

typedef struct mdec_movie {
    /* 0x00 */ mdec_movie_vtable_t *vtable;
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
    /* 0x40 */ s32 m_Unk15;
    /* 0x44 */ s32 m_Unk16;
    /* 0x48 */ s32 m_Unk17;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Unk19;
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ s32 m_Unk21;
    /* 0x5C */ s32 m_Unk22;
    /* 0x60 */ s32 m_Unk23;
    /* 0x64 */ s32 m_Unk24;
    /* 0x68 */ s32 m_Unk25;
    /* 0x6C */ s32 m_Unk26;
} mdec_movie_t;

mdec_movie_vtable_t *func_80045E44(void);

#endif // LSD_MDEC_MOVIE_H