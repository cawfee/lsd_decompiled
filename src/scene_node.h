#ifndef LSD_SCENE_NODE_H
#define LSD_SCENE_NODE_H

#include <common.h>

#include "base_class.h"

typedef struct scene_node_vtable {
    /* 0x000 800878d4 */ u32 type_id;
    /* 0x004 800878d8 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 800878dc */ s32 (*Construct)(void *);
    /* 0x00C 800878e0 */ void (*Cleanup)(base_class_t *);
    /* 0x010 800878e4 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 800878e8 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 800878ec */ void (*DetachAll)(base_class_t *);
    /* 0x01C 800878f0 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 800878f4 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 800878f8 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 800878fc */ void (*ClearParents)(base_class_t *);
    /* 0x02C 80087900 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 80087904 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 80087908 */ void (*Nop)(base_class_t *);
    /* 0x038 8008790c */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 80087910 */ void (*Unk14)(void *);
    /* 0x040 80087914 */ void (*Unk15)(void *);
    /* 0x044 80087918 */ void (*Unk16)(void *);
    /* 0x048 8008791c */ void (*Unk17)(void *);
    /* 0x04C 80087920 */ void (*Unk18)(void *, s32, s32);
    /* 0x050 80087924 */ void (*Unk19)(void *);
    /* 0x054 80087928 */ void (*Unk20)(void *);
    /* 0x058 8008792c */ void (*Unk21)(void *);
    /* 0x05C 80087930 */ void (*Unk22)(void *);
    /* 0x060 80087934 */ void (*Unk23)(void *, s32);
    /* 0x064 80087938 */ void (*Unk24)(void *);
    /* 0x068 8008793c */ void (*Unk25)(void *);
    /* 0x06C 80087940 */ void (*Unk26)(void *);
    /* 0x070 80087944 */ void (*Unk27)(void *, s32);
    /* 0x074 80087948 */ void (*Unk28)(void *);
    /* 0x078 8008794c */ void (*Unk29)(void *);
    /* 0x07C 80087950 */ void (*Unk30)(void *);
    /* 0x080 80087954 */ void (*Unk31)(void *);
    /* 0x084 80087958 */ void (*Unk32)(void *);
    /* 0x088 8008795c */ void (*Unk33)(void *, s32);
    /* 0x08C 80087960 */ void (*Unk34)(void *, void *);
    /* 0x090 80087964 */ void (*Unk35)(void *, void *, s32);
    /* 0x094 80087968 */ void (*Unk36)(void *);
    /* 0x098 8008796c */ void (*Unk37)(void *);
    /* 0x09C 80087970 */ void (*Unk38)(void *, void **, s32);
    /* 0x0A0 80087974 */ void (*Unk39)(void *);
    /* 0x0A4 80087978 */ void (*Unk40)(void *);
    /* 0x0A8 8008797c */ void (*Unk41)(void *);
    /* 0x0AC 80087980 */ void (*Unk42)(void *);
    /* 0x0B0 80087984 */ void (*Unk43)(void *);
    /* 0x0B4 80087988 */ void (*Unk44)(void *);
    /* 0x0B8 8008798c */ void (*Unk45)(void *, void *);
    /* 0x0BC 80087990 */ void (*Unk46)(void *, void *);
    /* 0x0C0 80087994 */ void (*Unk47)(void *);
    /* 0x0C4 80087998 */ void (*Unk48)(void *);
    /* 0x0C8 8008799c */ void (*Unk49)(void *);
    /* 0x0CC 800879a0 */ void (*Unk50)(void *);
    /* 0x0D0 800879a4 */ void (*Unk51)(void *);
    /* 0x0D4 800879a8 */ void (*Unk52)(void *);
    /* 0x0D8 800879ac */ void (*Unk53)(void *);
    /* 0x0DC 800879b0 */ void (*Unk54)(void *, void **, s32);
    /* 0x0E0 800879b4 */ void (*Unk55)(void *);
    /* 0x0E4 800879b8 */ void (*Unk56)(void *);
    /* 0x0E8 800879bc */ void (*Unk57)(void *);
    /* 0x0EC 800879c0 */ void (*Unk58)(void *);
} scene_node_vtable_t;

typedef struct scene_node {
    /* 0x00 */ scene_node_vtable_t *vtable;
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
    /* 0x40 */ s32 m_Unk15;
    /* 0x44 */ s32 m_Unk16;
    /* 0x48 */ s16 m_Unk17_1;
    /* 0x4A */ s16 m_Unk17_2;
    /* 0x4C */ s32 m_Unk18;
    /* 0x50 */ s32 m_Unk19;
    /* 0x54 */ s32 m_Unk20;
    /* 0x58 */ s32 m_Unk21;
} scene_node_t;

scene_node_vtable_t *scene_node_get_vtable(void);
void func_80057618(scene_node_t *This, void (*Fnc)(s32, s32, s32), s32 Unk1, s32 Unk2);

#endif