#ifndef LSD_FRAME_PHASE_H
#define LSD_FRAME_PHASE_H

#include <common.h>

#include "base/base.h"

typedef struct frame_phase frame_phase_t;

typedef struct frame_phase_vtable {
    /* 0x000 8006ef50 */ u32 type_id;
    /* 0x004 8006ef54 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006ef58 */ void (*Construct)(frame_phase_t *);
    /* 0x00C 8006ef5c */ void (*Cleanup)(frame_phase_t *);
    /* 0x010 8006ef60 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006ef64 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006ef68 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006ef6c */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006ef70 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006ef74 */ void (*RemoveParent)(frame_phase_t *, base_class_t *);
    /* 0x028 8006ef78 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006ef7c */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006ef80 */ void (*Notify)(frame_phase_t *, s32);
    /* 0x034 8006ef84 */ void (*Nop)(base_class_t *);
    /* 0x038 8006ef88 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006ef8c */ void (*Unk14)(void *);
    /* 0x040 8006ef90 */ void (*frame_phase_reset)(frame_phase_t *, s32);
    /* 0x044 8006ef94 */ void (*frame_phase_advance)(frame_phase_t *);
    /* 0x048 8006ef98 */ s32 (*frame_phase_get_phase)(frame_phase_t *);
    /* 0x04C 8006ef9c */ void (*frame_phase_set_waiting)(frame_phase_t *);
    /* 0x050 8006efa0 */ void (*frame_phase_clear_waiting)(frame_phase_t *);
    /* 0x054 8006efa4 */ s32 (*frame_phase_is_waiting)(frame_phase_t *);
    /* 0x058 8006efa8 */ void (*frame_phase_set_finished)(frame_phase_t *);
} frame_phase_vtable_t;

typedef struct frame_phase {
    /* 0x00 */ frame_phase_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Parents;
    /* 0x0C */ s32 m_Phase;
    /* 0x10 */ s32 m_Waiting;
    /* 0x14 */ s32 m_Finished;
    /* 0x18 */ void *m_NotifyCursor;
    /* 0x1C */ s32 m_Unk6;
} frame_phase_t;

frame_phase_t *frame_phase_create(void);
void frame_phase_construct(frame_phase_t *This);
void frame_phase_cleanup(frame_phase_t *This);
void frame_phase_remove_parent(frame_phase_t *This, base_class_t *Unk);
void frame_phase_notify(frame_phase_t *This, s32 Unk);
void frame_phase_reset(frame_phase_t *This, s32 Unk);
void frame_phase_advance(frame_phase_t *This);
s32 frame_phase_get_phase(frame_phase_t *This);
void frame_phase_set_waiting(frame_phase_t *This);
void frame_phase_clear_waiting(frame_phase_t *This);
s32 frame_phase_is_waiting(frame_phase_t *This);
void frame_phase_set_finished(frame_phase_t *This);
frame_phase_vtable_t *frame_phase_get_vtable(void);

#endif