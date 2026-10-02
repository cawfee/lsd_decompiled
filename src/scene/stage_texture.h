#ifndef LSD_STAGE_TEXTURE_H
#define LSD_STAGE_TEXTURE_H

#include <common.h>

#include "base/base.h"

typedef struct class_stage_texture_vtable {
    /* 0x000 8006f0b8 */ u32 type_id;
    /* 0x004 8006f0bc */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006f0c0 */ void (*Construct)(void *, s32);
    /* 0x00C 8006f0c4 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006f0c8 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006f0cc */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006f0d0 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006f0d4 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006f0d8 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006f0dc */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006f0e0 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006f0e4 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006f0e8 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006f0ec */ void (*Nop)(base_class_t *);
    /* 0x038 8006f0f0 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006f0f4 */ void (*Unk14)(void *);
    /* 0x040 8006f0f8 */ void (*Unk15)(void *);
    /* 0x044 8006f0fc */ void (*Unk16)(void *);
    /* 0x048 8006f100 */ void (*Unk17)(void *);
    /* 0x04C 8006f104 */ void (*Unk18)(void *);
    /* 0x050 8006f108 */ void (*Unk19)(void *);
    /* 0x054 8006f10c */ void (*Unk20)(void *);
    /* 0x058 8006f110 */ void (*Unk21)(void *);
    /* 0x05C 8006f114 */ void (*file_buf_release)(void *);
    /* 0x060 8006f118 */ void (*Unk23)(void *);
    /* 0x064 8006f11c */ void (*Unk24)(void *);
    /* 0x068 8006f120 */ void (*Unk25)(void *);
    /* 0x06C 8006f124 */ void (*Unk26)(void *);
    /* 0x070 8006f128 */ void (*Unk27)(void *);
    /* 0x074 8006f12c */ void (*Unk28)(void *);
    /* 0x078 8006f130 */ void (*Unk29)(void *);
    /* 0x07C 8006f134 */ void (*Unk30)(void *);
    /* 0x080 8006f138 */ void (*Unk31)(void *);
    /* 0x084 8006f13c */ void (*Unk32)(void *);
} class_stage_texture_vtable_t;

typedef struct class_stage_texture_slot {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ u16 unk1;
    /* 0x04 */ u8 unk4[6];
    /* 0x0A */ s16 unkA;
    /* 0x0C */ s8 rgb[3];
    /* 0x0F */ s8 pad;
} class_stage_texture_slot_t;

typedef struct class_stage_texture {
    /* 0x00 */ class_stage_texture_vtable_t *vtable;
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
    /* 0x40 */ class_stage_texture_slot_t m_Slots[4];
    /* 0x80 */ s32 m_Unk31;
    /* 0x84 */ s32 m_Unk32;
} class_stage_texture_t;

class_stage_texture_vtable_t *func_80043830(void);

#endif // LSD_STAGE_TEXTURE_H