#ifndef LSD_FILE_BUF_H
#define LSD_FILE_BUF_H

#include <common.h>

#include "base_class.h"

typedef struct file_buf_vtable {
    /* 0x000 8006d430 */ u32 type_id;
    /* 0x004 8006d434 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006d438 */ void (*Construct)(void *);
    /* 0x00C 8006d43c */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006d440 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006d444 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006d448 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006d44c */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006d450 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006d454 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006d458 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006d45c */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006d460 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006d464 */ void (*Nop)(base_class_t *);
    /* 0x038 8006d468 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006d46c */ void (*Unk14)(void *);
    /* 0x040 8006d470 */ void (*Unk15)(void *);
    /* 0x044 8006d474 */ void (*Unk16)(void *, s32, s32, s32);
    /* 0x048 8006d478 */ void (*Unk17)(void *);
    /* 0x04C 8006d47c */ s32 (*Unk18)(void *, s32, s32);
    /* 0x050 8006d480 */ void (*Unk19)(void *);
    /* 0x054 8006d484 */ void (*Unk20)(void *, void *, s32);
    /* 0x058 8006d488 */ void (*file_buf_load)(void *);
    /* 0x05C 8006d48c */ void (*file_buf_release)(void *);
    /* 0x060 8006d490 */ void (*Unk23)(void *);
    /* 0x064 8006d494 */ void (*Unk24)(void *);
    /* 0x068 8006d498 */ void (*Unk25)(void *);
    /* 0x06C 8006d49c */ void (*Unk26)(void *);
    /* 0x070 8006d4a0 */ void (*Unk27)(void *);
    /* 0x074 8006d4a4 */ void (*Unk28)(void *);
    /* 0x078 8006d4a8 */ void (*Unk29)(void *);
} file_buf_vtable_t;

typedef struct file_buf {
    /* 0x00 */ file_buf_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    s32 m_Unk2;
    void *m_Buffer;
    s32 m_Unk4;
    s32 m_Unk5;
    s32 m_Unk6;
    u16 m_Unk7_1;
    s16 m_Unk7_2;
    s32 m_Unk8;
    s16 m_Unk9;
    s16 m_Unk10;
} file_buf_t;

void *get_file_driver();
file_buf_vtable_t *file_buf_get_vtable(void);

#endif