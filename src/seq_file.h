#ifndef LSD_SEQ_FILE_H
#define LSD_SEQ_FILE_H

#include <common.h>

#include "base_class.h"

typedef struct seq_file_vtable {
    /* 0x000 8006eed8 */ u32 type_id;
    /* 0x004 8006eedc */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006eee0 */ void (*Construct)(void *, s32);
    /* 0x00C 8006eee4 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006eee8 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006eeec */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006eef0 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006eef4 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006eef8 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006eefc */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006ef00 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006ef04 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006ef08 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006ef0c */ void (*Nop)(base_class_t *);
    /* 0x038 8006ef10 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006ef14 */ u32 pad1;
    /* 0x040 8006ef18 */ u32 pad2;
    /* 0x044 8006ef1c */ u32 pad3;
    /* 0x048 8006ef20 */ u32 pad4;
    /* 0x04C 8006ef24 */ u32 pad5;
    /* 0x050 8006ef28 */ u32 pad6;
    /* 0x054 8006ef2c */ u32 pad7;
    /* 0x058 8006ef30 */ u32 pad8;
    /* 0x05C 8006ef34 */ void (*file_buf_release)(void *);
    /* 0x060 8006ef38 */ void (*Unk23)(void *);
    /* 0x064 8006ef3c */ void (*Unk24)(void *);
    /* 0x068 8006ef40 */ void (*pad9)(void *);
    /* 0x06C 8006ef44 */ void (*pad10)(struct seq_file *, unsigned char *);
    /* 0x070 8006ef48 */ void (*pad11)(void *);
    /* 0x074 8006ef4C */ void (*pad12)(void *);
} seq_file_vtable_t;

typedef struct seq_file {
    /* 0x00 */ seq_file_vtable_t *vtable;
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
    /* 0x2C */ s32 m_Flag;
    /* 0x30 */ s32 m_Unk11;
} seq_file_t;

seq_file_t *seq_file_create(u32 Unk1);
seq_file_vtable_t *seq_file_get_vtable(void);

#endif