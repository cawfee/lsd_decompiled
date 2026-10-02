#ifndef LSD_SCENE_H
#define LSD_SCENE_H

#include <common.h>

#include "base/base.h"

#include "dream/dream_session.h"
#include "sound/sound.h"

typedef struct scene_vtable {
    /* 0x000 80086668 */ u32 type_id;
    /* 0x004 8008666c */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 80086670 */ void (*Construct)(void *, s32, s32);
    /* 0x00C 80086674 */ void (*Cleanup)(base_class_t *);
    /* 0x010 80086678 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8008667c */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 80086680 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 80086684 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 80086688 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8008668c */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 80086690 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 80086694 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 80086698 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8008669c */ void (*Nop)(base_class_t *);
    /* 0x038 800866a0 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 800866a4 */ void (*Unk14)(void *);
    /* 0x040 800866a8 */ void (*Unk15)(void *);
    /* 0x044 800866ac */ void (*scene_run)(void *, void *, s32);
    /* 0x048 800866b0 */ void (*Unk17)(void *);
    /* 0x04C 800866b4 */ void (*Unk18)(void *);
    /* 0x050 800866b8 */ void (*Unk19)(void *);
    /* 0x054 800866bc */ void (*Unk20)(void *, void *, s32);
    /* 0x058 800866c0 */ void (*Unk21)(void *);
    /* 0x05C 800866c4 */ void (*Unk22)(void *);
    /* 0x060 800866c8 */ void (*Unk23)(void *, s32);
    /* 0x064 800866cc */ void (*Unk24)(void *);
    /* 0x068 800866d0 */ void (*Unk25)(void *);
    /* 0x06C 800866d4 */ void (*Unk26)(void *, s32);
    /* 0x070 800866d8 */ void (*Unk27)(void *);
    /* 0x074 800866dc */ void (*Unk28)(void *);
    /* 0x078 800866e0 */ void (*Unk29)(void *);
    /* 0x07C 800866e4 */ void (*Unk30)(void *);
} scene_vtable_t;

typedef struct scene {
    /* 0x00 */ scene_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ u32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Unk9;
    /* 0x2C */ s32 m_Unk10;
    /* 0x30 */ void *m_Unk11;
    /* 0x34 */ sound_t *m_Sound;
    /* 0x38 */ s32 m_Unk13;
} scene_t;

scene_t *scene_create(u32 soundName, u32 soundEngine);
void scene_construct(scene_t *This, void *soundName, sound_vtable_t *soundEngine);
void scene_cleanup(scene_t *This);
void scene_reset(scene_t *This);
void scene_stop(scene_t *This);
void scene_noop(void *This);
void scene_update(scene_t *This, void **Event, void *Data);
void scene_finish(scene_t *This, s32 Mode);
void scene_set_duration(scene_t *This, s32 Days);
void scene_play_note(scene_t *This, s32 Note);
s32 scene_run(scene_t *This, s32 Unk2, s32 Unk3);
scene_vtable_t *scene_get_vtable(void);

#endif