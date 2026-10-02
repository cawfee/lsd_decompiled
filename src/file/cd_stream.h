#ifndef LSD_CD_STREAM_H
#define LSD_CD_STREAM_H

#include <common.h>

#include "base/base.h"

typedef struct cd_stream_vtable {
    /* 0x000 80081940 */ u32 type_id;
    /* 0x004 80081944 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 80081948 */ void (*Construct)(void *);
    /* 0x00C 8008194c */ void (*Cleanup)(base_class_t *);
    /* 0x010 80081950 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 80081954 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 80081958 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8008195c */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 80081960 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 80081964 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 80081968 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8008196c */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 80081970 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 80081974 */ void (*Nop)(base_class_t *);
    /* 0x038 80081978 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8008197c */ void (*Unk14)(void *);
    /* 0x040 80081980 */ void (*Unk15)(void *);
    /* 0x044 80081984 */ void (*Unk16)(void *);
    /* 0x048 80081988 */ void (*Unk17)(void *);
    /* 0x04C 8008198c */ void (*Unk18)(void *);
    /* 0x050 80081990 */ void (*Unk19)(void *);
    /* 0x054 80081994 */ void (*Unk20)(void *);
    /* 0x058 80081998 */ void (*Unk21)(void *);
    /* 0x05C 8008199c */ void (*file_buf_release)(void *);
    /* 0x060 800819a0 */ void (*Unk23)(void *);
    /* 0x064 800819a4 */ void (*Unk24)(void *);
    /* 0x068 800819a8 */ void (*Unk25)(void *);
    /* 0x06C 800819ac */ void (*Unk26)(void *);
    /* 0x070 800819b0 */ void (*Unk27)(void *);
    /* 0x074 800819b4 */ void (*Unk28)(void *);
    /* 0x078 800819b8 */ void (*Unk29)(void *);
    /* 0x07C 800819bc */ void (*Unk30)(void *);
    /* 0x080 800819c0 */ void (*Unk31)(void *);
    /* 0x084 800819c4 */ void (*Unk32)(void *);
    /* 0x088 800819c8 */ void (*Unk33)(void *);
    /* 0x08C 800819cc */ void (*Unk34)(void *);
} cd_stream_vtable_t;

typedef struct cd_stream {
    /* 0x00 */ cd_stream_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s16 m_Unk9_1;
    s16 m_Unk9_2;
    /* 0x2C */ s16 m_Unk10_1;
    s16 m_Unk10_2;
    /* 0x30 */ s16 m_Unk11_1;
    s16 m_Unk11_2;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Unk13;
    /* 0x3C */ s32 m_Unk14;
} cd_stream_t;

cd_stream_vtable_t *func_80048CE0(void);

#endif // LSD_CD_STREAM_H