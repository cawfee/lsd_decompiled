#ifndef LSD_TILE_BUFFER_H
#define LSD_TILE_BUFFER_H

#include <common.h>

#include "base/base.h"

typedef struct tile_buffer_vtable {
    /* 0x000 8006f498 */ u32 type_id;
    /* 0x004 8006f49c */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006f4a0 */ void (*Construct)(void *, s32, void *);
    /* 0x00C 8006f4a4 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006f4a8 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006f4ac */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006f4b0 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006f4b4 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006f4b8 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006f4bc */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006f4c0 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006f4c4 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006f4c8 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006f4cc */ void (*Nop)(base_class_t *);
    /* 0x038 8006f4d0 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006f4d4 */ void (*Unk14)(void *);
    /* 0x040 8006f4d8 */ void (*Unk15)(void *);
    /* 0x044 8006f4dc */ void (*Unk16)(void *);
    /* 0x048 8006f4e0 */ void (*Unk17)(void *);
    /* 0x04C 8006f4e4 */ void (*Unk18)(void *);
    /* 0x050 8006f4e8 */ void (*Unk19)(void *);
    /* 0x054 8006f4ec */ void (*Unk20)(void *);
    /* 0x058 8006f4f0 */ void (*Unk21)(void *);
    /* 0x05C 8006f4f4 */ void (*file_buf_release)(void *);
    /* 0x060 8006f4f8 */ void (*Unk23)(void *);
    /* 0x064 8006f4fc */ void (*Unk24)(void *);
    /* 0x068 8006f500 */ void (*Unk25)(void *);
    /* 0x06C 8006f504 */ void (*Unk26)(void *);
    /* 0x070 8006f508 */ void (*Unk27)(void *);
    /* 0x074 8006f50c */ void (*Unk28)(void *);
    /* 0x078 8006f510 */ void (*Unk29)(void *);
} tile_buffer_vtable_t;

typedef struct tile_buffer {
    /* 0x00 */ tile_buffer_vtable_t *vtable;
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
    /* 0x2C */ u8 m_Unk10_0;
    /* 0x2D */ u8 m_Unk10_1;
    /* 0x2E */ u16 m_Unk10_2;
    /* 0x30 */ u16 m_Unk11_0;
    /* 0x32 */ u16 m_Unk11_1;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Unk13;
    /* 0x3C */ s32 m_Unk14;
    /* 0x40 */ u16 m_Unk15_1;
    /* 0x42 */ s16 m_Unk15_2;
    /* 0x44 */ s32 m_Unk16;
} tile_buffer_t;

tile_buffer_t *func_80044CD4(s32 Unk1, void *Unk2);
tile_buffer_vtable_t *func_80044F20(void);

#endif // LSD_TILE_BUFFER_H