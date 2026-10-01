#include "base/base_class.h"
#ifndef LSD_GAME_FLOW_H
#define LSD_GAME_FLOW_H

#include "sys/pad.h"
#include "dream/dream_session.h"
#include "dream/dream_sys.h"
#include "sys/display.h"

typedef struct game_flow_vtable {
    /* 0x000 8006d3c8 */ u32 type_id;
    /* 0x004 8006d3cc */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 8006d3d0 */ void (*game_flow_on_construct)(void *, void *);
    /* 0x00C 8006d3d4 */ void (*Cleanup)(base_class_t *);
    /* 0x010 8006d3d8 */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 8006d3dc */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 8006d3e0 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 8006d3e4 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 8006d3e8 */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 8006d3ec */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 8006d3f0 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 8006d3f4 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 8006d3f8 */ void (*Notify)(base_class_t *, s32);
    /* 0x034 8006d3fc */ void (*Nop)(base_class_t *);
    /* 0x038 8006d400 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 8006d404 */ u32 pad;
    /* 0x040 8006d408 */ void (*game_flow_get_day_rand)(void *);
    /* 0x044 8006d40c */ void (*game_flow_init)(void *, display_t *, pad_t *);
    /* 0x048 8006d410 */ void (*Unk17)(void *);
    /* 0x04C 8006d414 */ void (*game_flow_execute_phases)(void *);
    /* 0x050 8006d418 */ void (*game_flow_display_logo_sequence)(void *);
    /* 0x054 8006d41c */ void (*game_flow_play_intro_movie)(void *);
    /* 0x058 8006d420 */ s32 (*game_flow_execute_main_menu)(void *);
    /* 0x05C 8006d424 */ void (*Menu_Unused)(void *);
    /* 0x060 8006d428 */ s32 (*game_flow_execute_dream)(void *);
    /* 0x064 8006d42c */ void (*game_flow_play_ending_movie)(void *);
} game_flow_vtable_t;

typedef struct game_flow {
    /* 0x00 */ game_flow_vtable_t *vtable;
    /* 0x04 */ linked_list_node_t *m_Children;
    /* 0x08 */ linked_list_node_t *m_Parents;
    /* 0x0C */ vec2d_t m_ScreenSize;
    /* 0x14 */ s32 m_VarMode;
    /* 0x18 */ s32 m_IsInit;
    /* 0x1C */ game_graphics_ctx_t *m_GraphicsCtx;
    /* 0x20 */ game_config_t *m_Config;
    /* 0x24 */ s32 m_SkipDreamChart; // Set when execute_dream returns 3 (special day handled); skips graph_screen once
    /* 0x28 */ dream_sys_t *m_DreamSys;
} game_flow_t;

game_flow_t *game_flow_create(game_config_t *);
game_flow_vtable_t *game_flow_get_vtable(void);

void game_flow_logo_callback();

// Top-level flow helpers (not vtable slots)
void game_flow_display_logo(game_flow_t *This, const char *Path);
void game_flow_play_special_day(game_flow_t *This);
s32 run_screen(s32 (*Callback)(s32), s32 Unk1, s32 Unk2);
void play_special_reel(game_flow_t *This);

#endif