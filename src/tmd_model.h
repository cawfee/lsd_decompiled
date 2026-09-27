#ifndef LSD_TMD_MODEL_H
#define LSD_TMD_MODEL_H

#include <common.h>

#include "base_class.h"

typedef struct tmd_model_vtable {
    /* 0x000 8006f13c */ u32 type_id;
    /* 0x004 8006f140 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006f144 */ s32 (*Construct)(void *, s32);
    /* 0x00C 8006f148 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006f14c */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006f150 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006f154 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006f158 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006f15c */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006f160 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006f164 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006f168 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006f16c */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006f170 */ void (*Nop)(base_class_t *);
    /* 0x038 8006f174 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006f178 */ void (*Unk14)(void *);
    /* 0x040 8006f17c */ void (*Unk15)(void *);
    /* 0x044 8006f180 */ void (*Unk16)(void *);
    /* 0x048 8006f184 */ void (*Unk17)(void *);
    /* 0x04C 8006f188 */ void (*Unk18)(void *);
    /* 0x050 8006f18c */ void (*Unk19)(void *);
    /* 0x054 8006f190 */ void (*Unk20)(void *);
    /* 0x058 8006f194 */ void (*Unk21)(void *);
    /* 0x05C 8006f198 */ void (*file_buf_release)(void *);
    /* 0x060 8006f19c */ void (*Unk23)(void *);
    /* 0x064 8006f1a0 */ void (*Unk24)(void *);
    /* 0x068 8006f1a4 */ void (*Unk25)(void *);
    /* 0x06C 8006f1a8 */ void (*Unk26)(void *);
    /* 0x070 8006f1ac */ void (*Unk27)(void *);
    /* 0x074 8006f1b0 */ void (*Unk28)(void *);
    /* 0x078 8006f1b4 */ void (*tmd_map)(void *);
    /* 0x07C 8006f1b8 */ void (*Unk30)(void *);
    /* 0x080 8006f1bc */ void (*Unk31)(void *);
    /* 0x084 8006f1c0 */ void (*Unk32)(void *);
    /* 0x088 8006f1c4 */ void (*Unk33)(void *);
} tmd_model_vtable_t;

typedef struct tmd_model {
    /* 0x00 */ tmd_model_vtable_t *vtable;
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
} tmd_model_t;

tmd_model_vtable_t *func_80043B78(void);

#endif // LSD_TMD_MODEL_H