#ifndef LSD_OBJECT_MODEL_LIST_H
#define LSD_OBJECT_MODEL_LIST_H

#include <common.h>

#include "base/base_class.h"

typedef struct class_object_model_list_vtable {
    /* 0x000 8006f40c */ u32 type_id;
    /* 0x004 8006f410 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006f414 */ s32 (*Construct)(void *, s32);
    /* 0x00C 8006f418 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006f41c */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006f420 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006f424 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006f428 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006f42c */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006f430 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006f434 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006f438 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006f43c */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006f440 */ void (*Nop)(base_class_t *);
    /* 0x038 8006f444 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006f448 */ void (*Unk14)(void *);
    /* 0x040 8006f44c */ void (*Unk15)(void *);
    /* 0x044 8006f450 */ void (*Unk16)(void *);
    /* 0x048 8006f454 */ void (*Unk17)(void *);
    /* 0x04C 8006f458 */ void (*Unk18)(void *);
    /* 0x050 8006f45c */ void (*Unk19)(void *);
    /* 0x054 8006f460 */ void (*Unk20)(void *);
    /* 0x058 8006f464 */ void (*Unk21)(void *);
    /* 0x05C 8006f468 */ void (*file_buf_release)(void *);
    /* 0x060 8006f46c */ void (*Unk23)(void *);
    /* 0x064 8006f470 */ s32 (*Unk24)(void *);
    /* 0x068 8006f474 */ void (*Unk25)(void *);
    /* 0x06C 8006f478 */ void (*Unk26)(void *);
    /* 0x070 8006f47c */ void (*Unk27)(void *);
    /* 0x074 8006f480 */ void (*Unk28)(void *);
    /* 0x078 8006f484 */ void (*Unk29)(void *);
    /* 0x07C 8006f488 */ void (*Unk30)(void *);
    /* 0x080 8006f48c */ void (*Unk31)(void *);
    /* 0x084 8006f490 */ void (*Unk32)(void *);
    /* 0x088 8006f494 */ s32 (*Unk33)(void *, s32);
    /* 0x08C 8006f498 */ void (*Unk34)(void *);
} class_object_model_list_vtable_t;

typedef struct class_object_model_list {
    /* 0x00 */ class_object_model_list_vtable_t *vtable;
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
} class_object_model_list_t;

class_object_model_list_vtable_t *func_80044CC4();

#endif // LSD_OBJECT_MODEL_LIST_H