#ifndef LSD_SPRITE_ATLAS_H
#define LSD_SPRITE_ATLAS_H

#include <common.h>

#include "base/base.h"

typedef struct sprite_atlas_vtable {
    /* 0x000 8006f514 */ u32 type_id;
    /* 0x004 8006f518 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006f51c */ void (*Construct)(void *, s32);
    /* 0x00C 8006f520 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006f524 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006f528 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006f52c */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006f530 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006f534 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006f538 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006f53c */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006f540 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006f544 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006f548 */ void (*Nop)(base_class_t *);
    /* 0x038 8006f54c */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006f550 */ void (*Unk14)(void *);
    /* 0x040 8006f554 */ void (*Unk15)(void *);
    /* 0x044 8006f558 */ void (*Unk16)(void *);
    /* 0x048 8006f55c */ void (*Unk17)(void *);
    /* 0x04C 8006f560 */ void (*Unk18)(void *);
    /* 0x050 8006f564 */ void (*Unk19)(void *);
    /* 0x054 8006f568 */ void (*Unk20)(void *);
    /* 0x058 8006f56c */ void (*Unk21)(void *);
    /* 0x05C 8006f570 */ void (*file_buf_release)(void *);
    /* 0x060 8006f574 */ void (*Unk23)(void *);
    /* 0x064 8006f578 */ void (*Unk24)(void *);
    /* 0x068 8006f57c */ void (*Unk25)(void *);
    /* 0x06C 8006f580 */ void (*Unk26)(void *);
    /* 0x070 8006f584 */ void (*Unk27)(void *);
    /* 0x074 8006f588 */ void (*Unk28)(void *);
    /* 0x078 8006f58c */ void (*Unk29)(void *);
} sprite_atlas_vtable_t;

typedef struct sprite_atlas {
    /* 0x00 */ sprite_atlas_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s16 m_Unk9_1;
    /* 0x2A */ u16 m_Unk9_2;
    /* 0x2C */ s32 m_Unk10;
    /* 0x30 */ u16 m_Unk11_1;
    /* 0x32 */ s16 m_Unk11_2;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Unk13;
} sprite_atlas_t;

sprite_atlas_t *func_80044F30(u32 Unk1);
sprite_atlas_vtable_t *func_800451A8(void);

#endif