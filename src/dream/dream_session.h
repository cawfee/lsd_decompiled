#ifndef LSD_DREAM_SESSION_H
#define LSD_DREAM_SESSION_H

#include <common.h>

#include "base/base_class.h"

#include "base/frame_phase.h"
#include "dream/dream_sys.h"
#include "file/tim_image.h"
#include "graphics/scene_renderer.h"
#include "scene/render_context.h"
#include "graphics/display.h"
#include "sys/pad.h"

// TODO move?
typedef struct {
    display_t *display;
    pad_t *cls_16634;
    frame_phase_t *cls_32c00;
    render_context_t *cls_3acc8;
    scene_renderer_t *cls_3da54;
} game_graphics_ctx_t;

typedef struct dream_session dream_session_t;
typedef struct dream_session_vtable dream_session_vtable_t;
typedef struct dream_session_actor dream_session_actor_t;

struct dream_session_vtable {
    /* 0x000 800865c8 */ u32 type_id;
    /* 0x004 800865cc */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 800865d0 */ void (*dream_session_construct)(dream_session_t *, game_graphics_ctx_t *, dream_sys_t *, s32);
    /* 0x00C 800865d4 */ void (*dream_session_cleanup)(dream_session_t *);
    /* 0x010 800865d8 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 800865dc */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 800865e0 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 800865e4 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 800865e8 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 800865ec */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 800865f0 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 800865f4 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 800865f8 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 800865fc */ void (*Nop)(base_class_t *);
    /* 0x038 80086600 */ void (*dream_session_on_tick)(dream_session_t *, void **, s32);
    /* 0x03C 80086604 */ void (*Unk14)(dream_session_t *);
    /* 0x040 80086608 */ void (*dream_session_reset)(dream_session_t *);
    /* 0x044 8008660c */ s32 (*dream_session_execute)(dream_session_t *);
    /* 0x048 80086610 */ void (*dream_session_stop)(dream_session_t *);
    /* 0x04C 80086614 */ void (*dream_session_start)(dream_session_t *);
    /* 0x050 80086618 */ void (*dream_session_update_actor)(dream_session_t *);
    /* 0x054 8008661c */ void (*dream_session_tick)(dream_session_t *, void *, s32);
    /* 0x058 80086620 */ void (*scene_noop)(void *);
    /* 0x05C 80086624 */ void (*scene_update)(void *, void **, void *);
    /* 0x060 80086628 */ void (*scene_finish)(void *, s32);
    /* 0x064 8008662c */ void (*timer_begin_frame)(void *);
    /* 0x068 80086630 */ void (*timer_end_frame)(void *);
    /* 0x06C 80086634 */ void (*scene_set_duration)(void *, s32);
    /* 0x070 80086638 */ void (*scene_play_note)(void *, s32);
    /* 0x074 8008663c */ void (*Unk28)(dream_session_t *);
    /* 0x078 80086640 */ void (*Unk29)(dream_session_t *);
    /* 0x07C 80086644 */ void (*dream_session_noop)(dream_session_t *);
    /* 0x080 80086648 */ void (*dream_session_noop2)(dream_session_t *, void **, s32);
    /* 0x084 8008664c */ void (*dream_session_on_link_code)(dream_session_t *, s32, s32);
};

struct dream_session {
    /* 0x00 */ dream_session_vtable_t *vtable;
    /* 0x04 */ linked_list_node_t *m_Children;
    /* 0x08 */ linked_list_node_t *m_Parents;
    /* 0x0C */ game_graphics_ctx_t *m_GraphicsCtx;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ dream_session_actor_t *m_Actor;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s32 m_Result;
    /* 0x2C */ s32 m_Duration;
    /* 0x30 */ s32 m_SoundArg;
    /* 0x34 */ s32 m_StageArg;
    /* 0x38 */ dream_sys_t *m_DreamSys;
    /* 0x3C */ s32 m_State;
    /* 0x40 */ s32 m_Bgm;
    /* 0x44 */ tim_image_t *m_TextureHelper;
    /* 0x48 */ s32 m_Model;
    /* 0x4C */ s32 m_MapScene;
};

dream_session_t *dream_session_create(game_graphics_ctx_t *GraphicsCtx, dream_sys_t *DreamSys, s32 FrameSyncMode);
dream_session_vtable_t *dream_session_get_vtable(void);

void dream_session_construct(dream_session_t *This,
                             game_graphics_ctx_t *GraphicsCtx,
                             dream_sys_t *DreamSys,
                             s32 FrameSyncMode);
void dream_session_cleanup(dream_session_t *This);
void dream_session_on_tick(dream_session_t *This, void **Unk2, s32 Unk3);
void dream_session_reset(dream_session_t *This);
void dream_session_execute(dream_session_t *This);
void dream_session_stop(dream_session_t *This);
void dream_session_start(dream_session_t *This);
void dream_session_update_actor(dream_session_t *This);
void dream_session_tick(dream_session_t *This, void *arg1, s32 arg2);
void dream_session_noop(dream_session_t *This);
void dream_session_noop2(dream_session_t *This, void **Unk2, s32 Unk3);
void dream_session_on_link_code(dream_session_t *This, s32 Unk2, s32 Unk3);
void open_map(dream_session_t *This, s32 Unk);

#endif
