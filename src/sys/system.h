#ifndef LSD_SYSTEM_H
#define LSD_SYSTEM_H

#include <common.h>

#include "base/base.h"

#include "graphics/display.h"
#include "sys/game_flow.h"
#include "sys/pad.h"

typedef struct system_vtable {
    /* 0x000 8006E4F0 */ u32 type_id;
    /* 0x004 8006E4F4 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006E4F8 */ void (*Construct)(void *, s32);
    /* 0x00C 8006E4FC */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006E500 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006E504 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006E508 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006E50C */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006E510 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006E514 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006E518 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006E51C */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006E520 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006E524 */ void (*Nop)(base_class_t *);
    /* 0x038 8006E528 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006E52C */ void (*Unk14)(void *);
    /* 0x040 8006E530 */ void (*Unk15)(void *, s32 *, s32);
    /* 0x044 8006E534 */ void (*game_flow_init_graphics)(game_flow_t *, display_t *, pad_t *, u32);
    /* 0x048 8006E538 */ void (*game_flow_pre_execute)(void *);
    /* 0x04C 8006E53C */ void (*game_flow_execute_phases)(game_flow_t *);
    /* 0x050 8006E540 */ void (*Unk19)(void *);
    /* 0x054 8006E544 */ void (*Unk20)(void *);
    /* 0x058 8006E548 */ void (*Unk21)(void *);
    /* 0x05C 8006E54C */ void (*Unk22)(void *);
    /* 0x060 8006E550 */ void (*Unk23)(void *);
    /* 0x064 8006E554 */ void (*Unk24)(void *);
} system_vtable_t;

typedef struct system {
    /* 0x00 */ system_vtable_t *vtable;
    /* 0x04 */ void *m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
} system_t;

system_vtable_t *system_get_vtable(void);

void nullsub25(base_class_t *This);

#endif