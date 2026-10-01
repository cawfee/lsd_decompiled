#ifndef LSD_DREAM_SYS_H
#define LSD_DREAM_SYS_H

#include <common.h>

#include "base/base_class.h"

#include "file/tim_image.h"

typedef enum {
    MOVE_NONE = 0,
    MOVE_FORWARD = 1,
    MOVE_BACKWARDS = 2,
    MOVE_LEFT = 3,
    MOVE_RIGHT = 4,

    MOVE_COUNT
} dream_sys_move_state_t;

/* Link-zone / dream-mood colours. g_DreamColorTable maps the (dynamic, upper)
   mood levels to these values; docs/lsd_wiki/Linking.md names the eight zones:
   green (upper static), blue (upper), pink (upper dynamic), white (static
   neutral), black (dynamic), yellow (downer static), red (downer),
   cyan (downer dynamic). */
typedef enum {
    DREAM_COLOR_BLACK = 0,
    DREAM_COLOR_BLUE = 1,
    DREAM_COLOR_GREEN = 2,
    DREAM_COLOR_CYAN = 3,
    DREAM_COLOR_RED = 4,
    DREAM_COLOR_PINK = 5,
    DREAM_COLOR_YELLOW = 6,
    DREAM_COLOR_WHITE = 7,
} dream_color_t;

typedef union {
    struct {
        s8 dynamic;
        s8 upper;
    } axis;

    s16 value;
} dream_sys_mood_graph_point_t;

typedef struct {
    dream_sys_mood_graph_point_t last_mood;
    s32 dynamic_mood;
    s32 upper_mood;
    s32 amount_mood;
} dream_sys_mood_graph_contrib_t;

typedef struct dream_sys_vtable {
    /* 0x000 80087bdc */ u32 type_id;
    /* 0x004 80087be0 */ base_class_t *(*Destroy)(base_class_t *);
    /* 0x008 80087be4 */ void (*dream_sys_construct)(void *, s32, s32, s32);
    /* 0x00C 80087be8 */ void (*Unk2)(void *);
    /* 0x010 80087bec */ void (*Attach)(base_class_t *, base_class_t *);
    /* 0x014 80087bf0 */ void (*Detach)(base_class_t *, base_class_t *);
    /* 0x018 80087bf4 */ void (*DetachAll)(base_class_t *);
    /* 0x01C 80087bf8 */ void (*IterChildren)(base_class_t *, void **, void **);
    /* 0x020 80087bfc */ void (*AddParent)(base_class_t *, base_class_t *);
    /* 0x024 80087c00 */ void (*RemoveParent)(base_class_t *, base_class_t *);
    /* 0x028 80087c04 */ void (*ClearParents)(base_class_t *);
    /* 0x02C 80087c08 */ void (*IterParents)(base_class_t *, void **, void **);
    /* 0x030 80087c0c */ void (*Notify)(base_class_t *, s32);
    /* 0x034 80087c10 */ void (*Nop)(base_class_t *);
    /* 0x038 80087c14 */ void (*OnNotify)(base_class_t *, base_class_t *, s32);
    /* 0x03C 80087c18 */ u32 pad;
    /* 0x040 80087c1c */ void (*dream_sys_unk15)(void *);
    /* 0x044 80087c20 */ void (*Unk16)(void *, s32, s32 *);
    /* 0x048 80087c24 */ void (*Unk17)(void *);
    /* 0x04C 80087c28 */ void (*dream_sys_unk18)(void *, void *);
    /* 0x050 80087c2c */ void (*dream_sys_detach_actor)(void *);
    /* 0x054 80087c30 */ void (*Unk20)(void *);
    /* 0x058 80087c34 */ void (*Unk21)(void *);
    /* 0x05C 80087c38 */ void (*Unk22)(void *, s32);
    /* 0x060 80087c3c */ void (*Unk23)(void *, s32);
    /* 0x064 80087c40 */ void (*Unk24)(void *);
    /* 0x068 80087c44 */ void (*Unk25)(void *);
    /* 0x06C 80087c48 */ void (*Unk26)(void *);
    /* 0x070 80087c4c */ void (*Unk27)(void *);
    /* 0x074 80087c50 */ void (*Unk28)(void *);
    /* 0x078 80087c54 */ void (*Unk29)(void *);
    /* 0x07C 80087c58 */ void (*Unk30)(void *, s32);
    /* 0x080 80087c5c */ void (*Unk31)(void *);
    /* 0x084 80087c60 */ void (*Unk32)(void *);
    /* 0x088 80087c64 */ void (*dream_sys_on_floor_event)(void *);
    /* 0x08C 80087c68 */ void (*Unk34)(void *);
    /* 0x090 80087c6c */ void (*Unk35)(void *);
    /* 0x094 80087c70 */ void (*set_move_from_pad)(void *, s32, s32);
    /* 0x098 80087c74 */ void (*dream_sys_timer_tick)(void *);
    /* 0x09C 80087c78 */ void (*dream_sys_on_chunk_event)(void *);
    /* 0x0A0 80087c7c */ void (*Unk39)(void *);
    /* 0x0A4 80087c80 */ void (*Unk40)(void *);
    /* 0x0A8 80087c84 */ void (*Unk41)(void *);
    /* 0x0AC 80087c88 */ void (*Unk42)(void *);
    /* 0x0B0 80087c8c */ u32 pad2;
    /* 0x0B4 80087c90 */ void (*Unk44)(void *);
    /* 0x0B8 80087c94 */ void (*Unk45)(void *, s32);
    /* 0x0BC 80087c98 */ void (*Unk46)(void *, void *);
    /* 0x0C0 80087c9c */ void (*Unk47)(void *);
    /* 0x0C4 80087ca0 */ void (*Unk48)(void *, s32, s32);
    /* 0x0C8 80087ca4 */ void (*Unk49)(void *, s32, s32);
    /* 0x0CC 80087ca8 */ void (*Unk50)(void *, s32, s32);
    /* 0x0D0 80087cac */ void (*Unk51)(void *);
    /* 0x0D4 80087cb0 */ void (*Unk52)(void *);
    /* 0x0D8 80087cb4 */ void (*Unk53)(void *);
    /* 0x0DC 80087cb8 */ void (*dream_sys_on_journal_event)(void *);
    /* 0x0E0 80087cbc */ void (*dream_sys_wall_link)(void *, void *, s32);
    /* 0x0E4 80087cc0 */ s32 (*Unk56)(void *);
    /* 0x0E8 80087cc4 */ void (*dream_sys_nop)(void *);
    /* 0x0EC 80087cc8 */ void (*Unk58)(void *, s32);
    /* 0x0F0 80087ccc */ s32 (*dream_sys_get_set_flashback)(void *, void *, s32);
    /* 0x0F4 80087cd0 */ void (*dream_sys_set_paused)(void *, s32);
    /* 0x0F8 80087cd4 */ void (*reset_motion_for_link)(void *, s32, s32);
    /* 0x0FC 80087cd8 */ void (*dream_sys_lock_input)(void *);
    /* 0x100 80087cdc */ s32 (*dream_sys_get_action_pressed)(void *);
    /* 0x104 80087ce0 */ s32 (*dream_sys_get_set_dream_time_limit)(void *, s32);
    /* 0x108 80087ce4 */ s32 (*dream_sys_get_elapsed_seconds)(void *);
    /* 0x10C 80087ce8 */ void (*dream_sys_set_actor)(void *, s32);
    /* 0x110 80087cec */ void (*dream_sys_set_transform)(void *, void *);
    /* 0x114 80087cf0 */ void (*dream_sys_set_texture)(void *, tim_image_t *);
    /* 0x118 80087cf4 */ void (*dream_sys_update_link_timer)(void *);
    /* 0x11C 80087cf8 */ void (*dream_sys_run_callbacks)(void *);
    /* 0x120 80087cfc */ s32 (*dream_sys_resolve_target_position)(void *, s32, s32, s32 *, s32);
    /* 0x124 80087d00 */ void (*dream_sys_reset_flag7c)(void *);
    /* 0x128 80087d04 */ void (*dream_sys_reset_flag78)(void *);
    /* 0x12C 80087d08 */ void (*dream_sys_link_action_hook)(void *);
    /* 0x130 80087d0c */ void (*dream_sys_clear_callbacks)(void *, s32);
    /* 0x134 80087d10 */ void (*dream_sys_set_callbacks)(void *, s32, s32);
    /* 0x138 80087d14 */ void (*dream_sys_set_view_callback)(void *, s32);
    /* 0x13C 80087d18 */ void (*dream_sys_set_move_callback)(void *, s32);
    /* 0x140 80087d1c */ void (*dream_sys_update_view)(void *);
    /* 0x144 80087d20 */ void (*dream_sys_update_look)(void *);
    /* 0x148 80087d24 */ void (*dream_sys_update_turn)(void *);
    /* 0x14C 80087d28 */ void (*dream_sys_update_view_mode2)(void *);
    /* 0x150 80087d2c */ void (*dream_sys_update_view_mode3)(void *);
    /* 0x154 80087d30 */ void (*dream_sys_update_movement)(void *);
    /* 0x158 80087d34 */ void (*dream_sys_move_step)(void *);
    /* 0x15C 80087d38 */ void (*dream_sys_move_forward)(void *);
    /* 0x160 80087d3c */ void (*dream_sys_set_move_forward)(void *);
    /* 0x164 80087d40 */ s32 (*dream_sys_process_move)(void *, s32);
    /* 0x168 80087d44 */ void (*dream_sys_apply_floor_surface)(void *);
    /* 0x16C 80087d48 */ void (*dream_sys_release_floor_effect)(void *);
    /* 0x170 80087d4c */ void (*dream_sys_trigger_link_action)(void *, s32);
    /* 0x174 80087d50 */ void (*dream_sys_update_turn_delta)(void *);
    /* 0x178 80087d54 */ void (*dream_sys_reset_view)(void *);
    /* 0x17C 80087d58 */ void (*dream_sys_set_view_mode)(void *, s32);
    /* 0x180 80087d5c */ void (*dream_sys_get_set_move_direction)(void *, s32);
    /* 0x184 80087d60 */ void (*dream_sys_set_move_direction)(void *, s32);
    /* 0x188 80087d64 */ void (*dream_sys_restore_move_direction)(void *, s32);
    /* 0x18C 80087d68 */ void (*dream_sys_set_link_params)(void *, s32, s32, s32, s32);
    /* 0x190 80087d6c */ void (*dream_sys_set_link_interval)(void *, s32);
    /* 0x194 80087d70 */ void (*dream_sys_configure_entity_link)(void *, s32 *);
    /* 0x198 80087d74 */ void (*dream_sys_init_new_game)(void *);
    /* 0x19C 80087d78 */ void (*dream_sys_get_set_screen_shake)(void *, void *);
    /* 0x1A0 80087d7c */ s32 (*get_day_number)(void *, s32 *);
    /* 0x1A4 80087d80 */ s32 (*dream_sys_advance_day)(void *);
    /* 0x1A8 80087d84 */ void (*dream_sys_clear_new_game)(void *);
    /* 0x1AC 80087d88 */ s32 (*dream_sys_is_new_game)(void *);
    /* 0x1B0 80087d8c */ void *(*dream_sys_get_save_data)(void *, s32 *);
    /* 0x1B4 80087d90 */ s32 (*dream_sys_start_day)(void *);
    /* 0x1B8 80087d94 */ s32 (*dream_sys_end_day)(void *, s32);
    /* 0x1BC 80087d98 */ void (*dream_sys_get_cinematic)(void *, void *);
    /* 0x1C0 80087d9c */ void (*dream_sys_init_spawn_loc)(void *);
    /* 0x1C4 80087da0 */ void (*dream_sys_dynamic_link)(void *);
    /* 0x1C8 80087da4 */ s32 (*dream_sys_static_wall_link)(void *, s32);
    /* 0x1CC 80087da8 */ s32 (*dream_sys_load_next_flashback)(void *, s32);
    /* 0x1D0 80087dac */ s32 (*dream_sys_tunnel_link)(void *, s32);
    /* 0x1D4 80087db0 */ s32 (*dream_sys_random_spawn_link)(void *, s32);
    /* 0x1D8 80087db4 */ s32 (*dream_sys_teleport_link)(void *, s32);
    /* 0x1DC 80087db8 */ s32 (*dream_sys_staircase_link)(void *, s32);
    /* 0x1E0 80087dbc */ s32 (*dream_sys_get_current_map)(void *);
    /* 0x1E4 80087dc0 */ void (*dream_sys_process_chunk_change)(void *, void *, s32);
    /* 0x1E8 80087dc4 */ void (*dream_sys_instance_effects_on_journal)(void *, void **, s32);
    /* 0x1EC 80087dc8 */ void (*dream_sys_get_previous_day_mood)(void *, dream_sys_mood_graph_point_t *, s32);
    /* 0x1F0 80087dcc */ void (*dream_sys_init_mood_contributors)(void *, dream_sys_mood_graph_point_t *);
    /* 0x1F4 80087dd0 */ void (*dream_sys_log_chunk_mood)(void *, void *);
    /* 0x1F8 80087dd4 */ void (*dream_sys_log_instance_mood)(void *, dream_sys_mood_graph_point_t *);
    /* 0x1FC 80087dd8 */ void (*dream_sys_update_dream_chart)(void *, dream_sys_mood_graph_point_t *);
    /* 0x200 80087ddc */ s32 (*dream_sys_get_dream_color)(void *);
    /* 0x204 80087de0 */ void (*dream_sys_clear_mood_graph)(void *, dream_sys_mood_graph_contrib_t *);
    /* 0x208 80087de4 */ void (*dream_sys_log_mood)(void *,
                                                    dream_sys_mood_graph_contrib_t *,
                                                    dream_sys_mood_graph_point_t *);
    /* 0x20C 80087de8 */ void (*dream_sys_get_mood_average)(void *,
                                                            dream_sys_mood_graph_contrib_t *,
                                                            dream_sys_mood_graph_point_t *);
    /* 0x210 80087dec */ void (*dream_sys_calc_unlock_score)(void *);
    /* 0x214 80087df0 */ void (*dream_sys_add_flashback)(void *);
    /* 0x218 80087df4 */ void (*dream_sys_flashback_saving)(void *, s32, s32);
    /* 0x21C 80087df8 */ void (*dream_sys_reset_flashback_list)(void *);
    /* 0x220 80087dfc */ void (*dream_sys_save_link_state)(void *);
    /* 0x224 80087e00 */ void (*dream_sys_restore_link_state)(void *);
    /* 0x228 80087e04 */ void (*dream_sys_get_set_flag)(void *, u32);
} dream_sys_vtable_t;

typedef struct {
    u8 m_data[8];
    s16 m_hi;
} dream_sys_fb_pkt10_t;

typedef struct {
    u8 m_data[12];
} dream_sys_fb_pkt12_t;

typedef struct {
    u8 m_data[4];
} dream_sys_pkt4_t;

typedef struct {
    u8 m_data[4];
    s16 m_hi;
} dream_sys_pkt6_t;

typedef struct dream_sys_spawn {
    /* 0x00 */ dream_sys_pkt4_t chunkTile;
    /* 0x04 */ dream_sys_pkt6_t position;
} dream_sys_spawn_t; /* 0x0A */

typedef struct dream_sys_flashback {
    /* 0x00 */ s32 stage;
    /* 0x04 */ dream_sys_fb_pkt10_t spawn;
    /* 0x0E */ dream_sys_fb_pkt12_t angles;
    /* 0x1A */ s16 timeLimit;
    /* 0x1C */ s16 flag;
    /* 0x20 */ s32 day;
} dream_sys_flashback_t; /* 0x24 */

typedef struct dream_sys {
    /* 0x000 */ dream_sys_vtable_t *vtable;
    /* 0x004 */ s32 m_Unk0; /* scene_node base state */
    /* 0x008 */ s32 m_Unk1;
    /* 0x00C */ s32 m_HasTransform;
    /* 0x010 */ s32 m_Unk3;
    /* 0x014 */ s32 m_Transform; /* pointer to the player/link transform */
    /* 0x018 */ s32 m_Unk5;
    /* 0x01C */ s32 m_Unk6;
    /* 0x020 */ s32 m_Unk7;
    /* 0x024 */ u32 m_DreamTimer;  /* ticks; /15 = elapsed seconds */
    /* 0x028 */ s32 m_FloorObject; /* object whose +0x36 holds the floor surface */
    /* 0x02C */ s32 m_Unk10;
    /* 0x030 */ s32 m_Unk11;
    /* 0x034 */ s32 m_Unk12;
    /* 0x038 */ s32 m_Unk13;
    /* 0x03C */ s32 m_Unk14;
    /* 0x040 */ s32 m_Unk15;
    /* 0x044 */ s32 m_LinkState; /* current link/transition event id, 0 = none */
    /* 0x048 */ s32 m_Unk17;
    /* 0x04C */ s32 m_AttachedActor; /* scene actor attached by the link system */
    /* 0x050 */ s32 m_Unk19;
    /* 0x054 */ s32 m_Unk20;
    /* 0x058 */ s32 m_Actor;         /* sound/entity actor used by the sound_entity_* helpers */
    /* 0x05C */ s32 m_ViewTransform; /* transform modified by look/turn */
    /* 0x060 */ s32 m_Model;         /* model object passed to dream_sys_create */
    /* 0x064 */ s32 m_Texture;
    /* 0x068 */ s32 m_IsFlashbackSession;
    /* 0x06C */ s32 m_Paused;
    /* 0x070 */ s32 m_InputLocked;
    /* 0x074 */ s32 m_ActionPressed; /* one-tick flag raised by set_move_from_pad */
    /* 0x078 */ s32 m_ResetFlag78;   /* only ever cleared */
    /* 0x07C */ s32 m_ResetFlag7C;   /* only ever cleared */
    /* 0x080 */ s32 m_ViewUpdateCallback;
    /* 0x084 */ s32 m_ViewMode;
    /* 0x088 */ s32 m_LookUpDownState;
    /* 0x08C */ s32 m_LookVerticalPosition;
    /* 0x090 */ s32 m_TurnState;
    /* 0x094 */ s32 m_TurnOffset;
    /* 0x098 */ s32 m_MoveUpdateCallback;
    /* 0x09C */ s32 m_MoveMode;
    /* 0x0A0 */ dream_sys_move_state_t m_MoveState;
    /* 0x0A4 */ s32 m_LeftRightState; /* 1 = turning left, 2 = turning right */
    /* 0x0A8 */ s32 m_IsForward;
    /* 0x0AC */ s32 m_MoveDirection;
    /* 0x0B0 */ s32 m_PrevMoveDirection;
    /* 0x0B4 */ s32 m_MoveStep;
    /* 0x0B8 */ s32 m_FloorSurfaceType;
    /* 0x0BC */ s32 m_FloorEffect;
    /* 0x0C0 */ s32 m_ReservedC0;
    /* 0x0C4 */ s32 m_ResetViewPending;
    /* 0x0C8 */ s32 m_ViewActive;
    /* 0x0CC */ s32 m_EntityContext;
    /* 0x0D0 */ u8 m_EntityContextData[0x50];
    /* 0x120 */ u32 m_LinkInterval;
    /* 0x124 */ s32 m_CanDynamicLink;
    /* 0x128 */ s32 m_LinkParam128;
    /* 0x12C */ s32 m_LinkParam12C;
    /* 0x130 */ s32 m_LinkParam130;
    /* 0x134 */ s32 m_DreamTimeLimit;
    /* 0x138 */ s32 m_Reserved138[3];
    /* 0x144 */ dream_sys_mood_graph_contrib_t m_ChunkMoods;
    /* 0x154 */ dream_sys_mood_graph_contrib_t m_InstanceMoods;
    /* 0x164 */ s32 m_NextMap;
    /* 0x168 */ s32 m_SpecialCinematic; /* SPDAY scene: low s16 = set index (0-11), high s16 = variant (0-5) */
    /* 0x16C */ dream_sys_spawn_t m_SpawnCoordinates;
    /* 0x176 */ s16 m_SpawnCoordinatesPad;
    /* 0x178 */ s32 m_SaveDataMagic;
    /* 0x17C */ s32 m_Year;
    /* 0x180 */ s32 m_DayOfYear; /* 0-based (0-364); get_day_number returns this + 1 */
    /* 0x184 */ s32 m_TotalUnlockScore;
    /* 0x188 */ s32 m_NavigationScore;
    /* 0x18C */ s32 m_InstanceScore;
    /* 0x190 */ dream_sys_mood_graph_point_t m_MoodHistory[365]; /* one per day */
    /* 0x46A */ s16 m_MoodHistoryPad;
    /* 0x46C */ s32 m_FlashbackCount;
    /* 0x470 */ dream_sys_flashback_t m_Flashbacks[10];
    /* 0x5D8 */ u8 m_Reserved5D8[8];
    /* 0x5E0 */ s8 m_NavChallenges[30];
    /* 0x5FE */ s16 m_NavChallengesPad;
    /* 0x600 */ s32 m_DynamicLinkCount;
    /* 0x604 */ u8 m_Reserved604[0x74];
    /* 0x678 */ s32 m_ScreenShakeEnabled;
    /* 0x67C */ s32 m_Reserved67C;
    /* 0x680 */ s32 m_Reserved680;
    /* 0x684 */ u8 m_Reserved684[0x1F4];
    /* 0x878 */ s32 m_IsNewGame;
    /* 0x87C */ s32 m_FlashbackIndex;
    /* 0x880 */ s32 m_TeleportData;
    /* 0x884 */ s32 m_SourceLinkTransform;
    /* 0x888 */ s32 m_TargetLinkTransform;
    /* 0x88C */ s32 m_StoredDay;
    /* 0x890 */ u8 m_SavedLinkHead[0x50];
    /* 0x8E0 */ u8 m_SavedLinkTail[0x28];
    /* 0x908 */ s32 m_AutoMoveLocked;
    /* 0x90C */ s32 m_AutoMoveActive;
    /* 0x910 */ s32 m_AutoMoveCallback;
    /* 0x914 */ s32 m_AutoMoveStep;
    /* 0x918 */ dream_sys_spawn_t m_AutoMoveTarget;
    /* 0x922 */ s16 m_AutoMoveTargetPad;
    /* 0x924 */ s32 m_Flag; /* set by dream_sys_get_set_flag, never read */
    /* 0x928 */ s32 m_Reserved928;
} dream_sys_t;

dream_sys_vtable_t *dream_sys_get_vtable(void);

#endif