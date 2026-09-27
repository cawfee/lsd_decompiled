#ifndef LSD_FA50_H
#define LSD_FA50_H

#include "common.h"
#include "base_class.h"

typedef struct class_FA50_vtable {
    /* 0x000 8006bea0 */ u32 type_id;
    /* 0x004 8006bea4 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006bea8 */ void (*class_FA50_construct)(void *, s32);
    /* 0x00C 8006beac */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006beb0 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006beb4 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006beb8 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006bebc */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006bec0 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006bec4 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006bec8 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006becc */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006bed0 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006bed4 */ void (*Nop)(base_class_t *);
    /* 0x038 8006bed8 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006bedc */ u32 dummy;
    /* 0x040 8006bee0 */ void (*Unk15)(void *);
    /* 0x044 8006bee4 */ void (*Unk16)(void *);
    /* 0x048 8006bee8 */ void (*Unk17)(void *);
    /* 0x04C 8006beec */ void (*Unk18)(void *);
} class_FA50_vtable_t;

typedef struct class_FA50 {
    /* 0x00 */ class_FA50_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ void *m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
} class_FA50_t;

class_FA50_t *class_FA50_create(s32 Unk1);
class_FA50_vtable_t *class_FA50_get_vtable();

#endif // LSD_FA50_H