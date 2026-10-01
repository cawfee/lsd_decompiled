#ifndef LSD_PAD_H
#define LSD_PAD_H

#include <common.h>

#include "base/base_class.h"

typedef struct pad_vtable {
    /* 0x000 8006d370 */ u32 type_id;
    /* 0x004 8006d374 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006d378 */ void (*Construct)(void *, s32, s32);
    /* 0x00C 8006d37c */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006d380 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006d384 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006d388 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006d38c */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006d390 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006d394 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006d398 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006d39c */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006d3a0 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006d3a4 */ void (*Nop)(base_class_t *);
    /* 0x038 8006d3a8 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006d3ac */ u32 pad;
    /* 0x040 8006d3b0 */ void (*Unk15)(void *);
    /* 0x044 8006d3b4 */ void (*Unk16)(void *);
    /* 0x048 8006d3b8 */ void (*Unk17)(void *);
    /* 0x04C 8006d3bc */ void (*Unk18)(void *);
    /* 0x050 8006d3c0 */ void (*Unk19)();
    /* 0x054 8006d3c4 */ void (*Unk20)(void *);
} pad_vtable_t;

typedef struct pad {
    /* 0x00 */ pad_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ u16 m_Port;
    s16 m_Unk2_2;
    /* 0x10 */ s32 m_Buttons;
    /* 0x14 */ s32 m_Released;
    /* 0x18 */ s32 m_Pressed;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
} pad_t;

pad_t *pad_create(s32 Unk1, s32 Unk2);
pad_vtable_t *pad_get_vtable(void);

#endif