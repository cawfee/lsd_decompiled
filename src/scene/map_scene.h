#ifndef LSD_MAP_SCENE_H
#define LSD_MAP_SCENE_H

#include <common.h>

#include "base/base_class.h"

typedef struct dream_sys dream_sys_t;

typedef struct map_scene_vtable {
    /* 0x000 80087034 */ u32 type_id;
    /* 0x004 80087038 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8008703c */ void (*Construct)(void *, s32, s32, s32, s32, s32);
    /* 0x00C 80087040 */ void (*Cleanup)(base_class_t *);
    /* 0x010 80087044 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 80087048 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8008704c */ void (*DetachAll)(base_class_t *);
    /* 0x01C 80087050 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 80087054 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 80087058 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8008705c */ void (*ClearParents)(base_class_t *);
    /* 0x02C 80087060 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 80087064 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 80087068 */ void (*Nop)(base_class_t *);
    /* 0x038 8008706c */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 80087070 */ void (*Unk14)(void *);
    /* 0x040 80087074 */ void (*Unk15)(void *);
    /* 0x044 80087078 */ void (*Run)(void *);
    /* 0x048 8008707c */ void (*Unk17)(void *);
    /* 0x04C 80087080 */ void (*Unk18)(void *);
    /* 0x050 80087084 */ void (*Unk19)(void *);
    /* 0x054 80087088 */ void (*Unk20)(void *);
    /* 0x058 8008708c */ void (*Unk21)(void *);
    /* 0x05C 80087090 */ void (*Unk22)(void *);
    /* 0x060 80087094 */ void (*Unk23)(void *);
    /* 0x064 80087098 */ void (*Unk24)(void *);
    /* 0x068 8008709c */ void (*Unk25)(void *);
    /* 0x06C 800870a0 */ void (*Unk26)(void *);
    /* 0x070 800870a4 */ void (*Unk27)(void *);
    /* 0x074 800870a8 */ void (*Unk28)(void *);
    /* 0x078 800870ac */ void (*Unk29)(void *);
    /* 0x07C 800870b0 */ void (*Unk30)(void *);
    /* 0x080 800870b4 */ void (*Unk31)(void *);
    /* 0x084 800870b8 */ void (*Unk32)(void *);
    /* 0x088 800870bc */ void (*Unk33)(void *);
    /* 0x08C 800870c0 */ void (*Unk34)(void *);
    /* 0x090 800870c4 */ void (*Unk35)(void *, void **, s32);
    /* 0x094 800870c8 */ void (*Unk36)(void *);
    /* 0x098 800870cc */ void (*Unk37)(void *);
    /* 0x09C 800870d0 */ void (*Unk38)(void *);
    /* 0x0A0 800870d4 */ void (*Unk39)(void *);
    /* 0x0A4 800870d8 */ void (*Unk40)(void *);
    /* 0x0A8 800870dc */ void (*Unk41)(void *);
    /* 0x0AC 800870e0 */ void (*Unk42)(void *);
    /* 0x0B0 800870e4 */ void (*Unk43)(void *, void **, s32);
    /* 0x0B4 800870e8 */ void (*Unk44)(void *, void **, s32);
    /* 0x0B8 800870ec */ void (*Unk45)(void *, s32);
    /* 0x0BC 800870f0 */ void (*Unk46)(void *);
    /* 0x0C0 800870f4 */ void (*Unk47)(void *);
    /* 0x0C4 800870f8 */ void (*Unk48)(void *);
    /* 0x0C8 800870fc */ void (*Unk49)(void *);
    /* 0x0CC 80087100 */ void (*Unk50)(void *);
    /* 0x0D0 80087104 */ void (*Unk51)(void *);
    /* 0x0D4 80087108 */ void (*Unk52)(void *);
} map_scene_vtable_t;

typedef struct map_scene {
    /* 0x00 */ map_scene_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ void *m_Unk3;
    /* 0x14 */ void *m_SceneObject;
    /* 0x18 */ void *m_StageObject;
    /* 0x1C */ s32 m_Tick;
    /* 0x20 */ s32 m_State;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ s32 m_Unk10;
    /* 0x30 */ s32 m_Unk11;
    /* 0x34 */ void *m_Unk12;
    /* 0x38 */ s32 m_Location;
    /* 0x3C */ dream_sys_t *m_DreamSys;
    /* 0x40 */ s32 m_Unk15;
    /* 0x44 */ s32 m_Unk16;
    /* 0x48 */ s32 m_Unk17;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Generation;
    /* 0x54 */ void *m_Music;
    /* 0x58 */ s32 m_Unk21;
    /* 0x5C */ s32 m_Unk22;
    /* 0x60 */ s32 m_Active;
    /* 0x64 */ s32 m_Unk24;
    /* 0x68 */ s32 m_LinkActive;
    /* 0x6C */ s32 m_EntityContext;
    /* 0x70 */ s32 m_Unk27;
    /* 0x74 */ s32 m_Unk28;
    /* 0x78 */ s32 m_Unk29;
    /* 0x7C */ void *m_TextLine;
    /* 0x80 */ s32 m_TextStarted;
    /* 0x84 */ s32 m_Unk32;
    /* 0x88 */ s32 m_Unk33;
} map_scene_t;

map_scene_vtable_t *func_800544D4(void);

#endif