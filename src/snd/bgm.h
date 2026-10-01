#ifndef LSD_BGM_H
#define LSD_BGM_H

#include <common.h>

#include "base/base_class.h"

#include "snd/sound.h"

typedef struct bgm_vtable {
    /* 0x000 8006e48c */ u32 type_id;
    /* 0x004 8006e490 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006e494 */ void (*bgm_construct)(void *, s32, s32, s32);
    /* 0x00C 8006e498 */ void (*bgm_cleanup)(void *);
    /* 0x010 8006e49c */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006e4a0 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006e4a4 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006e4a8 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006e4ac */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006e4b0 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006e4b4 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006e4b8 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006e4bc */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006e4c0 */ void (*Nop)(base_class_t *);
    /* 0x038 8006e4c4 */ void (*bgm_on_notify)(void *);
    /* 0x03C 8006e4c8 */ void (*Unk14)(void *);
    /* 0x040 8006e4cc */ void (*bgm_handle_event)(void *, void **, s32);
    /* 0x044 8006e4d0 */ void (*seq_play)(void *);
    /* 0x048 8006e4d4 */ void (*seq_stop)(void *);
    /* 0x04C 8006e4d8 */ void (*seq_pause)(void *);
    /* 0x050 8006e4dc */ void (*seq_resume)(void *);
    /* 0x054 8006e4e0 */ void (*seq_set_vol)(void *);
    /* 0x058 8006e4e4 */ void (*bgm_set_crescendo)(void *);
    /* 0x05C 8006e4e8 */ void (*bgm_set_sequence)(void *, s32);
    /* 0x060 8006e4ec */ void (*bgm_set_sound)(void *, s32);
} bgm_vtable_t;

typedef struct bgm {
    /* 0x00 */ bgm_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ sound_t *m_Sound;
    /* 0x10 */ s32 m_SeqFile;
    /* 0x14 */ s16 m_SeqAccess;
    /* 0x16 */ s16 m_Unk4_2;
    /* 0x18 */ u16 m_Unk5_1;
    /* 0x20 */ u16 m_IsOpened;
    /* 0x1C */ u16 m_Paused;
    /* 0x1E */ u16 m_Playing;
    /* 0x20 */ s32 m_AutoPlay;
    /* 0x24 */ s32 m_Unk8;
} bgm_t;

bgm_vtable_t *bgm_get_vtable(void);

#endif