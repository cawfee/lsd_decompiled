#ifndef LSD_GRAPH_SCREEN_H
#define LSD_GRAPH_SCREEN_H

#include <common.h>

#include "base/base_class.h"

typedef struct graph_screen_vtable {
    /* 0x000 80087aac */ u32 type_id;
    /* 0x004 80087ab0 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 80087ab4 */ void (*Construct)(void *, s32);
    /* 0x00C 80087ab8 */ void (*Cleanup)(base_class_t *);
    /* 0x010 80087abc */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 80087ac0 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 80087ac4 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 80087ac8 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 80087acc */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 80087ad0 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 80087ad4 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 80087ad8 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 80087adc */ void (*Notify)(base_class_t *, s32);
    /* 0x034 80087ae0 */ void (*Nop)(base_class_t *);
    /* 0x038 80087ae4 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 80087ae8 */ void (*Unk14)(void *);
    /* 0x040 80087aec */ void (*show_graph)(void *, void *);
    /* 0x044 80087af0 */ void (*Run)(void *);
    /* 0x048 80087af4 */ void (*Unk17)(void *);
    /* 0x04C 80087af8 */ void (*Unk18)(void *);
    /* 0x050 80087afc */ void (*Unk19)(void *);
    /* 0x054 80087b00 */ void (*Unk20)(void *);
    /* 0x058 80087b04 */ void (*Unk21)(void *);
    /* 0x05C 80087b08 */ void (*Unk22)(void *);
    /* 0x060 80087b0c */ void (*Unk23)(void *);
    /* 0x064 80087b10 */ void (*Unk24)(void *);
    /* 0x068 80087b14 */ void (*Unk25)(void *);
    /* 0x06C 80087b18 */ void (*Unk26)(void *, s32);
    /* 0x070 80087b1c */ void (*Unk27)(void *, s32);
    /* 0x074 80087b20 */ void (*Unk28)(void *);
    /* 0x078 80087b24 */ void (*Unk29)(void *);
    /* 0x07C 80087b28 */ void (*Unk30)(void *);
    /* 0x080 80087b2c */ void (*Unk31)(void *);
    /* 0x084 80087b30 */ void (*Unk32)(void *);
    /* 0x088 80087b34 */ void (*Unk33)(void *);
    /* 0x08C 80087b38 */ void (*Unk34)(void *);
    /* 0x090 80087b3c */ void (*Unk35)(void *);
    /* 0x094 80087b40 */ void (*Unk36)(void *);
    /* 0x098 80087b44 */ void (*Unk37)(void *);
    /* 0x09C 80087b48 */ void (*Unk38)(void *);
    /* 0x0A0 80087b4c */ void (*Unk39)(void *);
    /* 0x0A4 80087b50 */ void (*Unk40)(void *);
    /* 0x0A8 80087b54 */ void (*Unk41)(void *);
    /* 0x0AC 80087b58 */ void (*Unk42)(void *);
    /* 0x0B0 80087b5c */ void (*Unk43)(void *);
    /* 0x0B4 80087b60 */ void (*Unk44)(void *);
    /* 0x0B8 80087b64 */ void (*Unk45)(void *);
    /* 0x0BC 80087b68 */ void (*Unk46)(void *);
    /* 0x0C0 80087b6c */ void (*Unk47)(void *);
    /* 0x0C4 80087b70 */ void (*Unk48)(void *);
    /* 0x0C8 80087b74 */ void (*Unk49)(void *);
    /* 0x0CC 80087b78 */ void (*Unk50)(void *);
    /* 0x0D0 80087b7c */ void (*Unk51)(void *);
    /* 0x0D4 80087b80 */ void (*Unk52)(void *, const char *, void *);
    /* 0x0D8 80087b84 */ void (*Unk53)(void *, s32);
    /* 0x0DC 80087b88 */ void (*Unk54)(void *);
    /* 0x0E0 80087b8c */ void (*Unk55)(void *);
    /* 0x0E4 80087b90 */ void (*Unk56)(void *);
    /* 0x0E8 80087b94 */ void (*Unk57)(void *);
    /* 0x0EC 80087b98 */ void (*Unk58)(void *);
    /* 0x0F0 80087b9c */ void (*Unk59)(void *);
    /* 0x0F4 80087ba0 */ void (*Unk60)(void *);
    /* 0x0F8 80087ba4 */ void (*Unk61)(void *);
    /* 0x0FC 80087ba8 */ void (*Unk62)(void *);
    /* 0x100 80087bac */ void (*Unk63)(void *);
    /* 0x104 80087bb0 */ void (*Unk64)(void *);
    /* 0x108 80087bb4 */ void (*Unk65)(void *);
    /* 0x10C 80087bb8 */ void (*Unk66)(void *);
    /* 0x110 80087bbc */ void (*Unk67)(void *);
    /* 0x114 80087bc0 */ void (*Unk68)(void *);
    /* 0x118 80087bc4 */ void (*Unk69)(void *);
    /* 0x11C 80087bc8 */ void (*Unk70)(void *);
    /* 0x120 80087bcc */ void (*Unk71)(void *);
    /* 0x124 80087bd0 */ void (*Unk72)(void *);
    /* 0x128 80087bd4 */ void (*Unk73)(void *);
} graph_screen_vtable_t;

typedef struct graph_screen {
    /* 0x00 */ graph_screen_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Tick;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ s32 m_Timer;
    /* 0x30 */ s32 m_Unk11;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Result;
    /* 0x3C */ s32 m_Mode;
    /* 0x40 */ s32 m_Unk15;
    /* 0x44 */ s32 m_Unk16;
    /* 0x48 */ s32 m_Sound;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Unk19;
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ s32 m_Unk21;
    /* 0x5C */ s32 m_Unk22;
    /* 0x60 */ s32 m_Unk23;
    /* 0x64 */ s32 m_Unk24;
    /* 0x68 */ s32 m_Unk25;
    /* 0x6C */ s32 m_Unk26;
    /* 0x70 */ s32 m_Unk27;
    /* 0x74 */ s32 m_Unk28;
    /* 0x78 */ s32 m_Unk29;
    /* 0x7C */ s32 m_Unk30;
    /* 0x80 */ s32 m_Unk31;
    /* 0x84 */ s32 m_State;
    /* 0x88 */ s32 m_Unk33;
    /* 0x8C */ s32 m_Unk34;
    /* 0x90 */ s32 m_Unk35;
    /* 0x94 */ s32 m_Unk36;
    /* 0x98 */ s32 m_Unk37;
    /* 0x9C */ s32 m_Unk38;
    /* 0xA0 */ s32 m_Unk39;
    /* 0xA4 */ void *m_DreamSys;
    /* 0x0A8 */ void *m_DreamCells[100]; /* one per stored dream day */
    s32 m_VideoReelReady;
    s32 m_EventCellIndex;
    void *m_EventCellIndices;
    s32 m_Unk144;
    s32 m_Unk145;
} graph_screen_t;

graph_screen_t *graph_screen_create(s32 Unk1);
graph_screen_vtable_t *func_80058764(void);

#endif