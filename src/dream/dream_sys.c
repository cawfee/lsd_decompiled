#include "dream/dream_sys.h"
#include <psx/rand.h>

#include "base/base_class.h"
#include "scene/scene_node.h"
#include "scene/stage_grid.h"

extern dream_sys_vtable_t g_DREAM_SYS_VTABLE;

extern s32 STAGE_PERMALINK_SPAWNS[];
extern s32 STAGE_PERMALINK_TRIGGERS[];
extern s32 LEN_STAGE_PERMALINK_TRIGGERS[];
extern s32 g_TunnelLinkSpawns[];
extern s32 g_TunnelLinkTriggers[];
extern s32 g_TunnelLinkCounts[];
extern s32 g_TeleportLinkSpawns[];
extern s32 g_TeleportLinkTriggers[];
extern s32 g_TeleportLinkCounts[];
extern s32 g_StaircaseLinkSpawns[];
extern s32 g_StaircaseLinkTriggers[];
extern s32 g_StaircaseLinkCounts[];
extern s16 STAGE_TIME_LIMITS[];
extern s16 *STAGE_SPAWNPOINTS[];
extern u8 LEN_STAGE_SPAWNPOINTS[];
extern s32 g_TeleportLinksEnabled;
extern s32 g_ViolenceLinkTile;
extern s32 g_DefaultLinkTransform[];
extern s32 gpNavChallengesComplete;
extern s32 gpDynamicLinkPenalty;
extern s32 g_LinkSourceStage;
extern s32 g_LinkSourceIndex;
extern s32 g_LinkTargetStage;
extern s32 g_LinkTargetIndex;
extern u8 *g_StaircaseLinkTriggerTransforms[];
extern u8 *g_StaircaseLinkSpawnTransforms[];
extern u8 *g_TunnelLinkTriggerTransforms[];
extern u8 *g_TunnelLinkSpawnTransforms[];
extern u8 g_LinkTransforms[];
extern s16 SPAWN_POS_ADJUST[];
extern s32 g_LookVerticalDelta[];
extern s32 g_LookVerticalLimit[];
extern s32 g_TurnDelta[];
extern s32 g_TurnLimit[];
extern s32 g_TurnTransforms[];
extern s16 g_TurnTransformYaw[];
extern s32 g_ViewResetOffset[];
extern s32 g_DreamStartTransform[];
extern s32 g_SaveDataMagic;
extern u8 g_LinkTransformAngles[];
extern s8 g_DreamColorTable[];
extern s8 g_FloorSurfaceAnim[];
extern s8 g_FloorSurfaceParam[];
extern s32 g_AutoMoveTable[]; /* used by the saved dream_sys_staircase_link attempt */
extern s16 g_AutoMoveTarget2[];
extern s16 g_AutoMoveTarget0[];
extern s16 g_AutoMoveTarget1[];
extern s16 g_AutoMoveTarget3[];
extern s32 g_TurnStepCw[];
extern s32 g_TurnStepCcw[];

s32 test_for_static_link(s32 *Unk0, s32 Unk1, s32 Unk2);
s32 get_static_spawn(void *dst, s16 *key, s32 chunk, s32 *counts, s32 *records, s32 *entries, s32 flag);
s32 execute_link(dream_sys_t *This, s32 Unk1, s32 Unk2, s32 Unk3);
s32 test_4_tunnel_links(void *Unk0, s32 Unk1, s32 Unk2);
void object_get_rotation_360(void *This, void *out);
s32 get_tunnel_link(void *a, void *b, void *c);
s32 dream_sys_translate_toward(dream_sys_t *This, s16 *a, s16 *b);
s32 is_facing_angle(s16 *arg0, s32 arg1);
s32 get_random_spawn_from_stage(void *dst, s32 chunk, s32 tick);
s32 calc_navigation_score(void);
void sound_entity_update(sound_t *This, void *Ctx);
void init_nav_challenges_array(s32 *Unk1, s32 *Unk2);
void *memset(void *s, int c, u32 n);

typedef struct {
    s16 m_Chunk;
    s16 m_Tile;
    s8 m_TargetStage;
    u8 m_TargetSpawn;
} dream_sys_static_spawn_t;

typedef struct {
    dream_sys_pkt4_t m_ChunkTile;
    u8 m_Adjustment;
    s8 m_NavChallenge;
} dream_sys_spawn_entry_t;

dream_sys_t *dream_sys_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    dream_sys_t *allocated = (dream_sys_t *) memory_allocate_mem(0x928);

    if (allocated) {
        dream_sys_get_vtable()->dream_sys_construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void dream_sys_construct(dream_sys_t *This, void *Unk1, s32 Unk2, s32 Unk3) {
    scene_node_get_vtable()->Construct(This);
    This->vtable = dream_sys_get_vtable();
    This->m_Actor = Unk2;
    This->m_ViewTransform = Unk3;
    This->m_Texture = 0;
    This->m_Model = (s32) Unk1;
    This->vtable->Attach(This, (*(s32(**)(void *, s32))(*(u32 *) Unk1 + 0x80))(Unk1, 0));
    This->vtable->dream_sys_get_set_dream_time_limit(This, -1);
    This->m_InputLocked = 1;
    This->m_Paused = 0;
    This->m_IsNewGame = 1;
    This->vtable->dream_sys_init_new_game(This);
    This->vtable->dream_sys_unk15(This);
}

void dream_sys_unk15(dream_sys_t *This) {
    This->vtable->Unk23(This, 0);
    This->vtable->Unk16(This, 1, &g_DreamStartTransform);
    This->m_ViewUpdateCallback = 0;
    This->m_MoveUpdateCallback = 0;
    This->m_EntityContext = 0;
    This->m_AutoMoveLocked = 0;
    This->m_AutoMoveActive = 0;
    This->m_AutoMoveCallback = 0;
    This->m_ResetFlag78 = 0;
    This->m_Flag = 0;
}

void dream_sys_unk18(dream_sys_t *This, void **arg1) {
    s32 sp10[4];
    u8 *slot;
    s32 off;

    ((void (*)(void **, void *, void *, void *)) * (void **) ((u8 *) *arg1 + 0xE4))(arg1, sp10, This,
                                                                                    (u8 *) This + 0x16C);
    ((void (*)(void *, void **, void *)) scene_node_get_vtable()->Unk18)(This, arg1, sp10);
    This->vtable->Attach(This, arg1);
    if (This->m_LinkState == 0xE) {
        off = *(s32 *) ((u8 *) This + 0x87C) * 0x24 + 0x470;
        slot = (u8 *) This + off;
        This->vtable->Unk16(This, 1, (s32 *) (slot + 0xE));
        This->vtable->dream_sys_get_set_dream_time_limit(This, *(s16 *) (slot + 0x1A) + 4);
        *(s32 *) ((u8 *) This + 0x87C) = *(s32 *) ((u8 *) This + 0x87C) + 1;
    }
    if (This->m_Paused != 0) {
        if (*(s32 *) ((u8 *) This + 0x888) != 0) {
            This->vtable->Unk16(This, 1, (s32 *) *(s32 *) ((u8 *) This + 0x888));
        }
    }
}

void dream_sys_detach_actor(dream_sys_t *This) {
    void **temp_a0;

    temp_a0 = (void **) This->m_AttachedActor;
    ((void (*)(void **))(*(void **) ((s8 *) *temp_a0 + 0xF0)))(temp_a0);
    This->vtable->Detach(This, (void *) This->m_AttachedActor);
    scene_node_get_vtable()->Unk19(This);
}

void dream_sys_on_floor_event(dream_sys_t *This, s32 arg1) {
    void **obj;
    s32 *link;
    s32 value;
    s32 surface;

    scene_node_get_vtable()->Unk33(This, arg1);
    if (arg1 == -2) {
        goto neg2;
    }
    if (arg1 != -1) {
        return;
    }
    surface = *(u16 *) (This->m_FloorObject + 0x36) & 0x7F;
    This->m_FloorSurfaceType = surface;
    if (surface >= 0x18) {
        This->m_FloorSurfaceType = 0;
    }
    if (This->m_LinkState == 0xF && This->m_FloorSurfaceType == 0) {
        This->m_FloorSurfaceType = 2;
    }
    if (This->m_NextMap == 9) {
        goto shared;
    }
    return;
neg2:
    obj = (void **) This->m_AttachedActor;
    link = ((s32 * (*) (void *, s32))(*(void **) ((u8 *) *obj + 0x11C)))(obj, This->m_Transform + 0x18);
    if (*(s16 *) (link[1] + 0x2C) != 2) {
        goto other;
    }
shared:
    obj = (void **) This->m_AttachedActor;
    value = (*(s32(**)(void **, s32, s32))(*(u32 *) obj + 0x10C))(obj, 0, 0);
    This->vtable->dream_sys_random_spawn_link(This, value);
    return;
other:
    This->vtable->dream_sys_restore_link_state(This);
}

void set_move_from_pad(dream_sys_t *This, s32 arg1, s32 arg2) {
    if (This->m_Paused != 0) {
        return;
    }
    if (This->m_InputLocked != 0) {
        return;
    }
    if (This->m_AutoMoveLocked != 0) {
        return;
    }
    arg2 -= 2;
    switch (arg2) {
        case 0:
            This->m_MoveState = MOVE_FORWARD;
            return;
        case 1:
            This->m_MoveState = MOVE_BACKWARDS;
            return;
        case 2:
            This->m_LeftRightState = 1;
            return;
        case 3:
            This->m_LeftRightState = 2;
            return;
        case 4:
            This->m_LookUpDownState = 1;
            return;
        case 5:
            if (This->m_MoveState != MOVE_FORWARD) {
                return;
            }
            This->vtable->dream_sys_set_move_direction(This, 4);
            return;
        case 6:
            This->m_LookUpDownState = 2;
            return;
        case 11:
            This->m_TurnState = 2;
            return;
        case 12:
            This->m_MoveState = MOVE_RIGHT;
            return;
        case 13:
            This->m_TurnState = 1;
            return;
        case 14:
            This->m_MoveState = MOVE_LEFT;
            return;
        case 23:
            This->m_ActionPressed = 1;
            return;
        case 32:
            ((void (*)(dream_sys_t *)) This->vtable->dream_sys_restore_move_direction)(This);
            return;
        case 47:
            return;
        default:
            return;
    }
}

s32 dream_sys_timer_tick(dream_sys_t *This, s32 arg1, s32 arg2) {
    u32 tick;
    s32 temp;

    temp = 2;
    if (arg2 == 2) {
        tick = This->m_DreamTimer;
        This->m_DreamTimer = tick + 1;
        if (tick >= (u32) This->m_DreamTimeLimit) {
            if (This->m_IsFlashbackSession != 0) {
                temp = This->m_LinkState;
                if ((temp != 0) || ((temp = This->vtable->dream_sys_load_next_flashback(This, 0)) != 0)) {
                    This->m_DreamTimer = 0;
                    return temp;
                }
            } else {
                This->vtable->dream_sys_flashback_saving(This, 0, 0x10);
            }
            This->vtable->Notify(This, 0xA);
            This->m_DreamTimer = 0;
        } else {
            This->vtable->dream_sys_update_link_timer(This);
            This->vtable->dream_sys_run_callbacks(This);
        }
    }
#ifdef NON_MATCHING
    return temp;
#endif
}

void dream_sys_on_chunk_event(dream_sys_t *This, void **Unk2, s32 Unk3) {
    scene_node_get_vtable()->Unk38(This, Unk2, Unk3);

    if ((*(u32 *) *Unk2 & 0xFFF) == 0x114) {
        This->vtable->dream_sys_process_chunk_change(This, Unk2, Unk3);
    }
}

void dream_sys_on_journal_event(dream_sys_t *This, void **Unk2, s32 Unk3) {
    scene_node_get_vtable()->Unk54(This, Unk2, Unk3);

    if ((*(u32 *) *Unk2 & 0xFFFFF) == 0x1F234) {
        This->vtable->dream_sys_instance_effects_on_journal(This, Unk2, Unk3);
    }
}

void dream_sys_wall_link(dream_sys_t *This, s32 arg1, s32 arg2) {
    void **obj;
    void *pkt;

    ((void (*)(void *, s32, s32)) scene_node_get_vtable()->Unk55)(This, arg1, arg2);
    if ((arg2 == 4) && (This->m_LinkState == 0)) {
        obj = (void **) This->m_AttachedActor;
        pkt = ((void *(*) (void *, s32))(*(void **) ((u8 *) *obj + 0xD4)))(obj, arg1);
        *(dream_sys_fb_pkt10_t *) &This->m_SpawnCoordinates = *(dream_sys_fb_pkt10_t *) pkt;
        if (This->vtable->dream_sys_static_wall_link(This, (s32) &This->m_SpawnCoordinates) == 0) {
            if (This->m_CanDynamicLink != 0) {
                This->vtable->dream_sys_dynamic_link(This);
            }
        }
        This->vtable->dream_sys_restore_link_state(This);
        This->vtable->dream_sys_nop(This);
    }
}

void dream_sys_nop(void) {
}

s32 dream_sys_get_set_flashback(dream_sys_t *This, void **Unk2, s32 Unk3) {
    s32 value;

    value = This->m_IsFlashbackSession;
    if (Unk3 < 0) {
        *Unk2 = (void *) calc_dream_color((char *) &This->m_MoodHistory + 2 * This->m_DayOfYear);
    } else {
        This->m_IsFlashbackSession = Unk3;
    }

    return value;
}

void dream_sys_set_paused(dream_sys_t *This, s32 arg1) {
    This->m_Paused = arg1;
    if (arg1 != 0) {
        This->vtable->dream_sys_get_set_move_direction(This, 1);
        if (This->m_SourceLinkTransform != 0) {
            This->vtable->Unk16(This, 1, (s32 *) This->m_SourceLinkTransform);
        }
    }
}

typedef struct {
    s32 m_Pad0;
    s32 m_Pad1;
    s16 m_A;
    s16 m_B;
    s32 m_Pad2;
} dream_sys_link_buf_t;

void reset_motion_for_link(dream_sys_t *This, s32 arg1, s32 arg2) {
    dream_sys_link_buf_t buf;

    This->vtable->dream_sys_log_chunk_mood(This, &This->m_SpawnCoordinates);
    This->vtable->dream_sys_set_view_callback(This, 1);
    This->vtable->dream_sys_set_move_callback(This, 1);
    This->vtable->dream_sys_get_set_move_direction(This, arg1);
    This->m_FloorEffect = -1;
    This->m_MoveStep = 0;
    This->m_FloorSurfaceType = 0;
    This->m_MoveState = MOVE_NONE;
    This->m_LeftRightState = 0;
    This->m_LookUpDownState = 0;
    This->m_TurnState = 0;
    This->m_LookVerticalPosition = 0;
    This->m_TurnOffset = 0;
    This->vtable->dream_sys_set_link_params(This, 0, 1, 1, 1);
    This->vtable->dream_sys_set_link_interval(This, arg2);
    *(s16 *) ((u8 *) &This->m_SpecialCinematic + 2) = -1;
    This->m_InputLocked = 0;
    This->m_LinkState = 0;
    This->m_ActionPressed = 0;
    This->m_AutoMoveLocked = 0;
    This->m_AutoMoveActive = 0;
    This->m_AutoMoveCallback = 0;
    This->m_ResetFlag78 = 0;
    object_get_rotation_360(This, &buf);
    buf.m_A = 0;
    buf.m_B = 1;
    This->vtable->Unk16(This, 1, (s32 *) &buf);
}

void dream_sys_lock_input(dream_sys_t *This) {
    This->m_InputLocked = 1;
}

s32 dream_sys_get_action_pressed(dream_sys_t *This) {
    return This->m_ActionPressed;
}

s32 dream_sys_get_set_dream_time_limit(dream_sys_t *This, s32 Limit) {
    s32 old_limit;

    if (Limit >= 0) {
        Limit *= 15;
    }

    old_limit = This->m_DreamTimeLimit;
    This->m_DreamTimeLimit = Limit;

    if (old_limit >= 0) {
        old_limit /= 15U;
    }

    return old_limit;
}

s32 dream_sys_get_elapsed_seconds(dream_sys_t *This) {
    return This->m_DreamTimer / 15;
}

void dream_sys_set_actor(dream_sys_t *This, s32 Value) {
    This->m_Actor = Value;
}

void dream_sys_set_transform(dream_sys_t *This, s32 Value) {
    This->m_ViewTransform = Value;
}

void dream_sys_set_texture(dream_sys_t *This, s32 Value) {
    This->m_Texture = Value;
}

void dream_sys_update_link_timer(dream_sys_t *This) {
    if (This->m_InputLocked == 0) {
        This->m_ActionPressed = 0;
        This->m_CanDynamicLink = This->m_DreamTimer % This->m_LinkInterval == 0;
    }
}

void dream_sys_run_callbacks(dream_sys_t *This) {
    void (*viewCallback)(void);
    void (*moveCallback)(dream_sys_t *);

    viewCallback = (void (*)(void)) This->m_ViewUpdateCallback;
    if (viewCallback) {
        viewCallback();
    }

    moveCallback = (void (*)(dream_sys_t *)) This->m_MoveUpdateCallback;
    if (moveCallback) {
        moveCallback(This);
    }
}

extern s32 g_LinkTargetPos[];

void transform_local_to_world(void *arg0, void *arg1, void *arg2, s32 arg3);
s32 is_point_within_radius(s32 *arg0, s32 arg1, s32 *arg2);

s32 dream_sys_resolve_target_position(dream_sys_t *This, vec3d_t *arg1, s32 arg2, s32 *arg3, s32 arg4) {
    vec3d_t pos;
    s32 temp;
    s32 *p;

    g_LinkTargetPos[0] = arg2;
    transform_local_to_world(This, &pos, &g_LinkTargetPos[-2], 0);
    temp = lerp_position((s32 *) (This->m_ViewTransform + 0x14), (s32 *) (This->m_ViewTransform + 0x20), arg2);
    if (This->m_HasTransform != 0) {
        p = (s32 *) (This->m_Transform + 0x38);
    } else {
        p = NULL;
    }
    pos.y = temp + p[1];
    if (arg1 != NULL) {
        *arg1 = pos;
    }
    if (arg3 != NULL) {
        return is_point_within_radius((s32 *) &pos, arg4, arg3);
    } else {
        return 0;
    }
}

s32 lerp_position(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 var_a3;
    s32 mult;
    s32 var_v1;
    s32 divisor;

    var_a3 = arg2;
    mult = var_a3;
    if (arg2 < 0) {
        var_a3 += 0x3FF;
    }
    mult = var_a3 >> 10;
    var_v1 = arg1[2] - arg0[2];
    if (var_v1 < 0) {
        var_v1 += 0x3FF;
    }
    divisor = var_v1 >> 10;
    if (divisor == 0) {
        divisor = 1;
    }
    return ((arg1[1] - arg0[1]) * mult) / divisor + arg0[1];
}

void dream_sys_reset_flag7c(dream_sys_t *This) {
    This->m_ResetFlag7C = 0;
}

void dream_sys_reset_flag78(dream_sys_t *This) {
    This->m_ResetFlag78 = 0;
}

s32 dream_sys_link_action_hook(dream_sys_t *This) {
    return 0;
}

void dream_sys_clear_callbacks(dream_sys_t *This, s32 Unk) {
    This->vtable->dream_sys_set_move_callback(This, 0);

    if (Unk) {
        This->vtable->dream_sys_set_view_callback(This, 0);
    }
}

void dream_sys_set_callbacks(dream_sys_t *This, s32 Unk2, s32 Unk3) {
    This->vtable->dream_sys_set_move_callback(This, Unk2);
    This->vtable->dream_sys_set_view_callback(This, Unk3);
}

void dream_sys_set_view_callback(dream_sys_t *This, s32 Unk) {
    dream_sys_vtable_t *vtable = This->vtable;

    This->m_ViewMode = Unk;

    switch (Unk) {
        case 0:
            This->m_ViewUpdateCallback = 0;
            break;

        case 1:
            This->m_ViewUpdateCallback = vtable->dream_sys_update_view;
            break;

        case 2:
            This->m_ViewUpdateCallback = vtable->dream_sys_update_view_mode2;
            break;

        case 3:
            This->m_ViewUpdateCallback = vtable->dream_sys_update_view_mode3;
            break;

        default:
            break;
    }
}

void dream_sys_set_move_callback(dream_sys_t *This, s32 Unk) {
    s32 fnc;
    dream_sys_vtable_t *vtable = This->vtable;

    if (This->m_MoveMode == 2) {
        vtable->dream_sys_set_view_mode(This, 0);
    }

    This->m_MoveMode = Unk;

    switch (Unk) {
        case 0:
            This->m_MoveUpdateCallback = 0;
            break;

        case 1:
            This->m_MoveUpdateCallback = vtable->dream_sys_update_movement;
            break;

        case 2:
            fnc = vtable->dream_sys_reset_view;
            This->m_ResetViewPending = 1;
            This->m_ViewActive = 1;
            This->m_MoveUpdateCallback = fnc;
            sound_entity_init(This->m_Actor, &This->m_EntityContext, 1, This,
                              This->vtable->dream_sys_configure_entity_link);
            break;

        default:
            break;
    }
}

void dream_sys_update_view(dream_sys_t *This) {
    This->vtable->dream_sys_update_look(This);
    This->vtable->dream_sys_update_turn(This);
}

void dream_sys_update_look(dream_sys_t *This) {
    s32 index;
    s32 delta;
    s32 limit;
    s32 sum;
    s32 *obj;
    s32 pos;

    index = This->m_LookUpDownState;
    if (index != 0) {
        delta = g_LookVerticalDelta[index];
        limit = g_LookVerticalLimit[index];
        sum = This->m_LookVerticalPosition + delta;
        if (sum >= 0) {
            if (sum < limit) {
                goto apply;
            }
        } else if ((~sum + 1) < limit) {
            goto apply;
        }
        goto clear;
    apply:
        obj = (s32 *) This->m_ViewTransform;
        obj[9] += delta;
        This->m_LookVerticalPosition = sum;
    clear:
        This->m_LookUpDownState = 0;
    } else {
        pos = This->m_LookVerticalPosition;
        if (pos != 0) {
            if (pos < 0) {
                delta = 0x258;
            } else {
                delta = -0x258;
            }
            ((s32 *) This->m_ViewTransform)[9] = ((s32 *) This->m_ViewTransform)[9] + delta;
            This->m_LookVerticalPosition += delta;
        }
    }
}

void dream_sys_decay_turn(dream_sys_t *This);

void dream_sys_update_turn(dream_sys_t *This) {
    s32 index;
    s32 delta;
    s32 limit;
    s32 sum;
    s32 pos;

    This->m_IsForward = This->m_MoveState == MOVE_FORWARD;
    index = This->m_TurnState;
    if (index != 0) {
        delta = g_TurnDelta[index];
        limit = g_TurnLimit[index];
        sum = This->m_TurnOffset + delta;
        if (sum >= 0) {
            if (sum < limit) {
                goto apply;
            }
        } else if ((~sum + 1) < limit) {
            goto apply;
        }
        goto clear;
    apply:
        g_TurnTransformYaw[0] = delta;
        This->vtable->Unk16(This, 0, (s32 *) ((u8 *) &g_TurnTransformYaw[0] - 4));
        This->m_TurnOffset = sum;
    clear:
        This->m_TurnState = 0;
        dream_sys_decay_turn(This);
    } else {
        pos = This->m_TurnOffset;
        if (pos != 0) {
            if (pos < 0) {
                delta = 0x2D;
            } else {
                delta = -0x2D;
            }
            g_TurnTransformYaw[0] = delta;
            This->vtable->Unk16(This, 0, (s32 *) ((u8 *) &g_TurnTransformYaw[0] - 4));
            This->m_TurnOffset += delta;
            dream_sys_decay_turn(This);
        }
    }
}

void dream_sys_decay_turn(dream_sys_t *This) {
    This->m_IsForward = 0;

    if (This->m_MoveState) {
        if ((This->m_MoveState & 1) == 0) {
            This->m_MoveState -= 1;
        } else {
            This->m_MoveState += 1;
        }
    }
}

/* Empty view-update callback installed for view mode 2 by
   dream_sys_set_view_callback. */
void dream_sys_update_view_mode2(void) {
}

/* Empty view-update callback installed for view mode 3 by
   dream_sys_set_view_callback. */
void dream_sys_update_view_mode3(void) {
}

void dream_sys_update_movement(dream_sys_t *This) {
    if (This->m_Paused == 0) {
        This->vtable->dream_sys_update_turn_delta(This);
        This->vtable->dream_sys_move_step(This);
    } else if (This->m_Paused == 2) {
        This->vtable->dream_sys_set_move_forward(This);
    } else {
        This->vtable->dream_sys_move_forward(This);
    }
}

void dream_sys_move_step(dream_sys_t *This) {
    s32 value;

    if (!This->m_InputLocked) {
        value = This->vtable->dream_sys_process_move(This, 1);
        This->vtable->dream_sys_trigger_link_action(This, value);
    }
}

void dream_sys_move_forward(dream_sys_t *This) {
    s32 value;

    This->m_MoveState = MOVE_FORWARD;

    if (!This->m_InputLocked) {
        value = This->vtable->dream_sys_process_move(This, 1);
        This->vtable->dream_sys_trigger_link_action(This, value);
    } else {
        This->vtable->dream_sys_process_move(This, 0);
    }
}

void dream_sys_set_move_forward(dream_sys_t *This) {
    This->m_MoveState = MOVE_FORWARD;
}

s32 dream_sys_process_move(dream_sys_t *This, s32 arg1) {
    s32 flag;
    s32 saved;
    s32 count;
    s32 delta;
    s32 *obj;

    flag = 0;
    saved = 0;
    if (This->m_MoveState != 0) {
        saved = This->m_MoveState;
        count = This->m_MoveStep + 1;
        This->m_MoveStep = count;
        if (count >= 4) {
            goto wrap;
        }
        if (This->m_MoveDirection != MOVE_RIGHT) {
            goto step;
        }
        {
            u32 bit;

            bit = count & 1;
            flag = bit < 1;
        }
        goto step;
    wrap:
        This->m_MoveState = MOVE_NONE;
        flag = 1;
    step:
        if (flag != 0) {
            This->vtable->dream_sys_apply_floor_surface(This);
        }
        obj = (s32 *) This->m_ViewTransform;
        if (obj != 0 && This->m_ScreenShakeEnabled != 0 && arg1 != 0) {
            delta = -0x32;
            if (This->m_MoveStep >= 3) {
                delta = 0x32;
            }
            obj[6] += delta;
            obj[9] += delta;
        }
        if (This->m_MoveState == MOVE_NONE) {
            This->m_MoveStep = 0;
        }
    }
    if (flag == 0) {
        This->vtable->dream_sys_release_floor_effect(This);
    }
    return saved;
}

void dream_sys_apply_floor_surface(dream_sys_t *This) {
    s32 *link;
    s32 surface;
    void **vtable;
    s32 offset;

    link = (s32 *) This->m_Actor;
    surface = This->m_FloorSurfaceType;
    vtable = (void **) *link;
    if (surface != 0) {
        offset = g_FloorSurfaceAnim[surface] * 0x10;
        ((void (*)(s32 *, s32)) vtable[0x9C / 4])(link, g_FloorSurfaceParam[surface]);
        This->m_FloorEffect = ((s32(*)(s32 *, s32, s32, s32)) vtable[0x80 / 4])(link, offset, 0x6E, 0x6E);
        if (This->m_FloorSurfaceType != 0x16) {
            This->m_FloorEffect = -1;
        }
        if (This->m_FloorSurfaceType == 0xB) {
            ((void (*)(s32 *, s32)) vtable[0x9C / 4])(link, 1);
            ((s32(*)(s32 *, s32, s32, s32)) vtable[0x80 / 4])(link, offset, 0x6E, 0x6E);
            ((void (*)(s32 *, s32)) vtable[0x9C / 4])(link, 2);
            ((s32(*)(s32 *, s32, s32, s32)) vtable[0x80 / 4])(link, 0x90, 0x6E, 0x6E);
        }
    }
}

void dream_sys_release_floor_effect(dream_sys_t *This) {
    if (This->m_FloorEffect >= 0) {
        (*(void (**)(s32, s32))(*(s32 *) This->m_Actor + 132))(This->m_Actor, This->m_FloorEffect);
        This->m_FloorEffect = -1;
    }
}

extern s8 g_LinkDistanceSign[];
extern s32 g_LinkDistanceByDirection[];
extern void (*g_LinkActionTable[])(dream_sys_t *, s32, s32);

typedef struct link_actor link_actor_t;

typedef struct link_actor_vtable {
    /* 0x00 */ u8 pad[0x10C];
    /* 0x10C */ s32 (*get_spawn_key)(link_actor_t *, s32, s32);
} link_actor_vtable_t;

typedef struct link_actor {
    /* 0x00 */ link_actor_vtable_t *vtable;
} link_actor_t;

typedef struct link_actor_transform {
    /* 0x00 */ s32 cleared;
    /* 0x04 */ u8 pad[0x14];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} link_actor_transform_t;

void dream_sys_trigger_link_action(dream_sys_t *This, s32 arg) {
    s32 product;
    s32 ret;
    link_actor_t *link;
    link_actor_transform_t *inner;

    if (arg == 0) {
        return;
    }
    product = g_LinkDistanceSign[arg] * g_LinkDistanceByDirection[This->m_MoveDirection];
    This->vtable->dream_sys_link_action_hook(This);
    link = (link_actor_t *) This->m_AttachedActor;
    ret = link->vtable->get_spawn_key(link, 0, 0);
    if (This->vtable->dream_sys_staircase_link(This, ret) == 0 &&
        This->vtable->dream_sys_teleport_link(This, ret) == 0 && This->vtable->dream_sys_tunnel_link(This, ret) == 0) {
        This->vtable->dream_sys_save_link_state(This);
        g_LinkActionTable[arg](This, product, This->m_AutoMoveActive == 0);
        if (This->m_NextMap == 0) {
            inner = (link_actor_transform_t *) This->m_Transform;
            if (inner->field_1C < -0x7D0 && inner->field_18 >= -0x1F3) {
                This->vtable->dream_sys_wall_link(This, This, 4);
            }
        }
    }
    *(s32 *) This->m_Transform = 0;
}

void dream_sys_update_turn_delta(dream_sys_t *This) {
    s32 state;

    state = This->m_LeftRightState;
    if (state != 0) {
        This->vtable->Unk16(This, 0, (s32 *) ((state * 0xC) + (s32) g_TurnTransforms));
        This->m_LeftRightState = 0;
    }
}

void dream_sys_reset_view(dream_sys_t *This) {
    s32 *temp_v1;

    if (This->m_ResetViewPending != 0) {
        This->vtable->Unk46(This, g_ViewResetOffset);
        temp_v1 = (s32 *) This->m_ViewTransform;
        temp_v1[9] = temp_v1[9] - 0x258;
    }
    if (This->m_ViewActive != 0) {
        sound_entity_update(This->m_Actor, (u8 *) This + 0xCC);
    }
}

void dream_sys_set_view_mode(dream_sys_t *This, s32 Unk) {
    This->m_ResetViewPending = 0;
    This->m_ViewActive = Unk;

    if (Unk) {
        sound_entity_stop(This->m_Actor, &This->m_EntityContext);
    }
}

s32 dream_sys_get_set_move_direction(dream_sys_t *This, s32 Value) {
    s32 old_value = This->m_MoveDirection;

    if (Value >= 0) {
        This->m_MoveDirection = Value;
        This->m_PrevMoveDirection = Value;
    }

    return old_value;
}

s32 dream_sys_set_move_direction(dream_sys_t *This, s32 Value) {
    s32 next_value;

    next_value = This->m_MoveDirection;
    if (next_value != Value) {
        This->m_PrevMoveDirection = next_value;
        This->m_MoveDirection = Value;
    }
    return next_value;
}

void dream_sys_restore_move_direction(dream_sys_t *This) {
    This->m_MoveDirection = This->m_PrevMoveDirection;
}

void dream_sys_set_link_params(dream_sys_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    if (Unk2 >= 0) {
        This->m_CanDynamicLink = Unk2;
    }
    if (Unk3 >= 0) {
        This->m_LinkParam128 = Unk3;
    }
    if (Unk4 >= 0) {
        This->m_LinkParam12C = Unk4;
    }
    if (Unk5 >= 0) {
        This->m_LinkParam130 = Unk5;
    }
}

void dream_sys_set_link_interval(dream_sys_t *This, s32 Value) {
    This->m_LinkInterval = Value;
}

void dream_sys_configure_entity_link(dream_sys_t *This, s32 *arg1) {
    s32 temp;

    if (arg1[0] != 1) {
        return;
    }
    temp = arg1[1] % 20;
    if (temp == 0) {
        arg1[7] = 9;
        arg1[8] = -1;
        return;
    }
    arg1[12] = 9;
    arg1[13] = -1;
}

void dream_sys_init_new_game(dream_sys_t *This) {
    s32 temp_v1;

    temp_v1 = g_SaveDataMagic;
    This->m_Year = 0;
    This->m_DayOfYear = 0;
    This->m_TotalUnlockScore = 0;
    This->m_NavigationScore = 0;
    This->m_InstanceScore = 0;
    This->m_FlashbackCount = 0;
    *((u8 *) This + 0x5DF) = 0;
    *((u8 *) This + 0x5D8) = 0;
    This->m_ScreenShakeEnabled = 1;
    This->m_Reserved67C = 0;
    This->m_Reserved680 = 0;
    This->m_SaveDataMagic = temp_v1;
    init_nav_challenges_array((s32 *) &This->m_NavChallenges, &This->m_DynamicLinkCount);
    memset(&This->m_Reserved684, 0, 0x1F4);
}

void dream_sys_get_set_screen_shake(dream_sys_t *This, s32 *Value) {
    s32 old_value = This->m_ScreenShakeEnabled;
    This->m_ScreenShakeEnabled = *Value;
    *Value = old_value;
}

s32 get_day_number(dream_sys_t *This, s32 *Year) {
    if (Year) {
        *Year = This->m_Year;
    }
    return This->m_DayOfYear + 1;
}

s32 dream_sys_advance_day(dream_sys_t *This) {
    s32 next_day = This->m_DayOfYear + 1;
    This->m_DayOfYear = next_day;

    if (next_day > 364) {
        This->m_DayOfYear = 0;
        This->m_Year++;
    }

    return This->m_DayOfYear;
}

void dream_sys_clear_new_game(dream_sys_t *This) {
    This->m_IsNewGame = 0;
}

s32 dream_sys_is_new_game(dream_sys_t *This) {
    return This->m_IsNewGame;
}

s32 *dream_sys_get_save_data(dream_sys_t *This, s32 *Size) {
    if (Size) {
        *Size = 0x700;
    }

    return &This->m_SaveDataMagic;
}

s32 is_day_special(s16 *out, s32 day);

s32 dream_sys_start_day(dream_sys_t *This) {
    s32 special;

    This->m_FlashbackIndex = 0;
    This->m_DreamTimer = 0;
    This->m_StoredDay = This->m_DayOfYear;
    if (This->m_IsFlashbackSession != 0) {
        ((void (*)(void *, s32)) This->vtable->dream_sys_load_next_flashback)(This, 1);
    } else {
        special = is_day_special((u8 *) This + 0x168, This->m_DayOfYear + 1);
        ((void (*)(void *, s32)) This->vtable->dream_sys_init_mood_contributors)(This, special);
        if (special != 0) {
            return -1;
        }
        This->vtable->dream_sys_init_spawn_loc(This);
    }
    return This->m_NextMap;
}

s32 dream_sys_end_day(dream_sys_t *This, s32 arg1) {
    s32 off;

    This->m_DayOfYear = This->m_StoredDay;
    if (This->m_IsFlashbackSession == 0) {
        if (arg1 == 0) {
            This->vtable->dream_sys_calc_unlock_score(This);
            off = This->m_DayOfYear * 2;
            off += 0x190;
            ((void (*)(void *, void *)) This->vtable->dream_sys_update_dream_chart)(This, (u8 *) This + off);
            This->vtable->dream_sys_advance_day(This);
            goto done;
        }
    }
    if (arg1 == 2) {
        This->vtable->dream_sys_init_new_game(This);
        This->m_IsNewGame = 1;
    }
done:
    return This->m_IsFlashbackSession;
}

dream_sys_t *dream_sys_get_cinematic(dream_sys_t *This, void *Unk) {
    return (dream_sys_t *) __builtin_memcpy((char *) This, (char *) Unk + 0x168, 4);
}

s32 generate_initial_spawn(void *arg0, s32 *arg1, void *arg2, s32 arg3);

void dream_sys_init_spawn_loc(dream_sys_t *This) {
    s32 sp14;
    dream_sys_mood_graph_point_t sp10;

    This->vtable->dream_sys_get_previous_day_mood(This, &sp10, 1);
    This->m_NextMap = generate_initial_spawn(&This->m_SpawnCoordinates, &sp14, &sp10, This->m_DayOfYear);
    sp14 = This->vtable->dream_sys_get_set_dream_time_limit(This, sp14);
    This->m_LinkState = 0xB;
}

void dream_sys_dynamic_link(dream_sys_t *This) {
    s32 RandomSpawnFromStage;
    ;

    if (!This->m_LinkState) {
        RandomSpawnFromStage =
            get_random_spawn_from_stage(&This->m_SpawnCoordinates, This->m_NextMap, This->m_DreamTimer);
        execute_link(This, RandomSpawnFromStage, 12, 1);
    }
}

s32 dream_sys_static_wall_link(dream_sys_t *This, s32 arg1) {
    s32 temp_v0;

    if (This->m_LinkState != 0) {
        return 0;
    }
    temp_v0 = test_for_static_link((s32 *) &This->m_SpawnCoordinates, arg1, This->m_NextMap);
    if (temp_v0 < 0) {
        return 0;
    }
    execute_link(This, temp_v0, 0xD, 1);
    return 1;
}

s32 dream_sys_load_next_flashback(dream_sys_t *This, s32 arg1) {
    s32 idx;
    s32 off;
    u8 *slot;

    idx = *(s32 *) ((u8 *) This + 0x87C);
    if (idx < This->m_FlashbackCount) {
        *(s32 *) ((u8 *) This + 0x44) = 0xE;
        off = idx * 0x24 + 0x470;
        slot = (u8 *) This + off;
        if (arg1 == 0) {
            ((void (*)(void *, s32)) This->vtable->Notify)(This, 0xE);
        }
        This->m_DayOfYear = *(s32 *) (slot + 0x20);
        This->m_NextMap = *(s32 *) slot;
        *(dream_sys_fb_pkt10_t *) ((u8 *) This + 0x16C) = *(dream_sys_fb_pkt10_t *) (slot + 4);
        return 1;
    }
    return 0;
}

s32 dream_sys_tunnel_link(dream_sys_t *This, s32 arg1) {
    s32 idx;
    s32 buf[4];

    if (This->m_LinkState != 0) {
        return 0;
    }
    idx = test_4_tunnel_links(&This->m_SpawnCoordinates, arg1, This->m_NextMap);
    if (idx < 0) {
        return 0;
    }
    object_get_rotation_360(This, buf);
    if (get_tunnel_link(&This->m_TargetLinkTransform, &This->m_SourceLinkTransform, buf) == 0) {
        return 0;
    }
    if (This->m_IsForward == 0) {
        return 0;
    }
    execute_link(This, idx, 0xF, 0);
    return 1;
}

s32 dream_sys_random_spawn_link(dream_sys_t *This, s32 arg1) {
    s32 idx;

    if (This->m_LinkState != 0) {
        return 0;
    }
    idx = get_dynamic_link_spawn(&This->m_SpawnCoordinates, This->m_NextMap, arg1, This->m_DreamTimer);
    if (idx < 0) {
        return 0;
    }
    This->m_TeleportData = (s32) get_teleport_link_data();
    This->m_SourceLinkTransform = 0;
    This->m_TargetLinkTransform = 0;
    execute_link(This, idx, 0x10, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/dream/dream_sys", dream_sys_teleport_link);

s32 execute_link(dream_sys_t *This, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_a0;

    This->m_LinkState = arg2;
    This->vtable->Notify(This, arg2);
    if (This->m_LinkState == 0) {
        return 0;
    }
    This->m_NextMap = arg1;
    if (This->m_IsFlashbackSession != 0) {
        This->m_DreamTimer = 0;
    }
    if (arg3 != 0) {
        temp_a0 = (void *) This->m_Actor;
        (*(void (**)(void *, s32, s32, s32))(*(s32 *) temp_a0 + 0x80))(temp_a0, 0x90, 0x6E, 0x6E);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/dream/dream_sys", dream_sys_staircase_link);

s32 dream_sys_auto_move_0(dream_sys_t *This) {
    s32 v;

    if (This->m_AutoMoveStep == 0) {
        dream_sys_translate_toward(This, g_AutoMoveTarget0, (s16 *) &This->m_AutoMoveTarget.position);
    }
    if (This->m_MoveDirection != 4) {
        v = This->m_AutoMoveStep;
        if (v >= 0x85) {
            return 1;
        }
        if (((u32) (v - 0x2B) < 0xF) || ((u32) (v - 0x4B) < 0xF)) {
            This->m_LeftRightState = 2;
        }
    } else {
        v = This->m_AutoMoveStep;
        if (v >= 0x13) {
            return 1;
        }
        if (((u32) (v - 8) < 2) || ((u32) (v - 0xD) < 2)) {
            This->vtable->Unk16(This, 0, g_TurnStepCw);
        }
    }
    This->m_MoveState = MOVE_FORWARD;
    This->m_AutoMoveStep += 1;
    return 0;
}

s32 dream_sys_auto_move_1(dream_sys_t *This) {
    s32 v;
    s32 turn;

    if (This->m_AutoMoveStep == 0) {
        dream_sys_translate_toward(This, g_AutoMoveTarget1, (s16 *) &This->m_AutoMoveTarget.position);
    }
    if (This->m_MoveDirection != 4) {
        v = This->m_AutoMoveStep;
        if (v >= 0x95) {
            return 1;
        }
        if (((u32) (v - 0x16) < 0xF) || ((u32) (v - 0x39) < 0x10) || ((u32) (v - 0x6E) < 0xF)) {
            This->m_LeftRightState = 1;
        }
        turn = (u32) (This->m_AutoMoveStep - 0x39) < 0x35;
    } else {
        v = This->m_AutoMoveStep;
        if (v >= 0x19) {
            return 1;
        }
        if (((u32) (v - 6) < 2) || ((u32) (v - 0xB) < 2) || ((u32) (v - 0x14) < 2)) {
            This->vtable->Unk16(This, 0, g_TurnStepCcw);
        }
        turn = (u32) (This->m_AutoMoveStep - 3) < 0xE;
    }
    if (turn != 0) {
        This->m_LookUpDownState = 2;
    }
    This->m_MoveState = MOVE_FORWARD;
    This->m_AutoMoveStep += 1;
    return 0;
}

s32 dream_sys_auto_move_2(dream_sys_t *This) {
    s32 v;

    if (This->m_AutoMoveStep == 0) {
        dream_sys_translate_toward(This, g_AutoMoveTarget2, (s16 *) &This->m_AutoMoveTarget.position);
    }
    if (This->m_MoveDirection != 4) {
        v = This->m_AutoMoveStep;
        if (v >= 0x65) {
            return 1;
        }
        if ((u32) (v - 0x2B) < 0xF) {
            This->m_LeftRightState = 2;
        }
    } else {
        v = This->m_AutoMoveStep;
        if (v >= 0xF) {
            return 1;
        }
        if ((u32) (v - 8) < 2) {
            This->vtable->Unk16(This, 0, g_TurnStepCw);
        }
    }
    This->m_MoveState = MOVE_FORWARD;
    This->m_AutoMoveStep += 1;
    return 0;
}

s32 dream_sys_auto_move_3(dream_sys_t *This) {
    s32 v;
    s32 turn;

    if (This->m_AutoMoveStep == 0) {
        dream_sys_translate_toward(This, g_AutoMoveTarget3, (s16 *) &This->m_AutoMoveTarget.position);
    }
    if (This->m_MoveDirection != 4) {
        v = This->m_AutoMoveStep;
        if (v >= 0x71) {
            return 1;
        }
        if (((u32) (v - 0x1E) < 0xF) || ((u32) (v - 0x52) < 0xF)) {
            This->m_LeftRightState = 1;
        }
        turn = (u32) (This->m_AutoMoveStep - 0x1E) < 0x34;
    } else {
        v = This->m_AutoMoveStep;
        if (v >= 0x13) {
            return 1;
        }
        if (((u32) (v - 6) < 2) || ((u32) (v - 0xF) < 2)) {
            This->vtable->Unk16(This, 0, g_TurnStepCcw);
        }
        turn = (u32) This->m_AutoMoveStep < 9;
    }
    if (turn != 0) {
        This->m_LookUpDownState = 2;
    }
    This->m_MoveState = MOVE_FORWARD;
    This->m_AutoMoveStep += 1;
    return 0;
}

s32 dream_sys_translate_toward(dream_sys_t *This, s16 *a, s16 *b) {
    s32 vec[3];
    s32 t0;
    s32 t1;

    vec[0] = a[0] - b[0];
    vec[1] = a[1] - b[1];
    t0 = a[2];
    t1 = b[2];
    vec[1] = 0;
    vec[2] = t0 - t1;
    return ((s32(*)(dream_sys_t *, s32 *)) This->vtable->Unk46)(This, vec);
}

s32 dream_sys_get_current_map(dream_sys_t *This) {
    return This->m_NextMap;
}

void dream_sys_process_chunk_change(dream_sys_t *This, void *arg1, s32 arg2) {
    if (arg2 == 5) {
        This->vtable->dream_sys_log_chunk_mood(
            This, (void *) ((s32(*)(void *, s32, s32))(*(void **) (*(s32 *) arg1 + 0x10C)))(arg1, 0, 0));
    }
}

/*
 * Best-known C (109/110 insns; jump table, all five case bodies, offsets and
 * relocations correct). Only differences are a register/schedule tie:
 * target computes switch index into $v1 and preserves $a2 (`addiu v1,a2,-4`),
 * gcc 2.6.3 propagates the value back into $a2 (`addiu a2,a2,-4`) even with a
 * separate index variable/initializer; and in case 4 the target sets the call
 * this-pointer `addu a0,s1` before loading the method, gcc loads from $s1 first.
 *
 * s32 temp;
 * if (This->m_LinkState == 0) {
 *     switch (arg2) {
 *     case 4:
 *         (*(void (**)(void **, s32))(*(u32 *)arg1 + 0x38))(arg1, (s32)This);
 *         break;
 *     case 9:
 *         if (This->m_IsFlashbackSession == 0) {
 *             This->vtable->dream_sys_log_instance_mood(This,
 *                 (dream_sys_mood_graph_point_t *)(*(s32 (**)(void **))(*(u32 *)arg1 + 0x14C))(arg1));
 *             This->m_InstanceScore += (*(s32 (**)(void **))(*(u32 *)arg1 + 0x150))(arg1);
 *             This->vtable->dream_sys_flashback_saving(This, 0, 0x10);
 *         }
 *         break;
 *     case 10:
 *         temp = This->m_NextMap;
 *         This->m_NextMap = -(*(s32 (**)(void **))(*(u32 *)arg1 + 0x154))(arg1);
 *         This->vtable->dream_sys_dynamic_link(This);
 *         if (This->m_NextMap < 0) This->m_NextMap = temp;
 *         break;
 *     case 11:
 *         if (This->m_IsFlashbackSession == 0) {
 *             *(s16 *)((u8 *)This + 0x168) = -1;
 *             This->m_DreamTimer = This->m_DreamTimeLimit;
 *             *(s16 *)((u8 *)This + 0x16A) = (*(s32 (**)(void **))(*(u32 *)arg1 + 0x158))(arg1);
 *         }
 *         break;
 *     case 12:
 *         if (This->m_IsFlashbackSession == 0) This->m_DreamTimer = This->m_DreamTimeLimit;
 *         break;
 *     }
 * }
 */
INCLUDE_ASM("asm/nonmatchings/dream/dream_sys", dream_sys_instance_effects_on_journal);

void dream_sys_get_previous_day_mood(dream_sys_t *This, s8 *out, s32 mode) {
    s32 t0;
    s32 t1;
    s32 count;
    s8 *p;
    s32 i;
    s32 a;
    s32 b;

    t0 = 0;
    t1 = 0;
    if (mode != 0) {
        if (This->m_Year != 0) {
            goto last_day;
        }
        if (This->m_DayOfYear == 0) {
            goto store_both;
        }
    last_day: {
        void *row;
        row = (u8 *) This + ((This->m_DayOfYear - 1) << 1);
        t1 = ((s8 *) row)[0x190];
        t0 = ((s8 *) row)[0x191];
        out[0] = t1;
        out[1] = t0;
        return;
    }
    }
    count = 0x16D;
    if (This->m_Year == 0) {
        count = This->m_DayOfYear;
    }
    if (count != 0) {
        p = (s8 *) This + 0x190;
        i = 0;
        if (t0 < count) {
            do {
                i += 1;
                a = p[0];
                b = p[1];
                p += 2;
                t1 += a;
                t0 += b;
            } while (i < count);
        }
        t1 /= count;
        t0 /= count;
    }
store_both:
    out[0] = t1;
    out[1] = t0;
}

void dream_sys_init_mood_contributors(dream_sys_t *This, s32 arg1) {
    void *p144;
    void *p154;

    p144 = (u8 *) This + 0x144;
    This->vtable->dream_sys_clear_mood_graph(This, p144);
    p154 = (u8 *) This + 0x154;
    This->vtable->dream_sys_clear_mood_graph(This, p154);
    if (arg1 != 0) {
        ((void (*)(void *, void *, s32)) This->vtable->dream_sys_log_mood)(This, p144, arg1);
        ((void (*)(void *, void *, s32)) This->vtable->dream_sys_log_mood)(This, p154, arg1);
    }
}

void dream_sys_log_chunk_mood(dream_sys_t *This, void *CurrentPosition) {
    dream_sys_mood_graph_point_t *point = get_mood_from_stage_chunk(This->m_NextMap, CurrentPosition);
    This->vtable->dream_sys_log_mood(This, &This->m_ChunkMoods, point);
}

void dream_sys_log_instance_mood(dream_sys_t *This, dream_sys_mood_graph_point_t *Source) {
    This->vtable->dream_sys_log_mood(This, &This->m_InstanceMoods, Source);
}

void dream_sys_update_dream_chart(dream_sys_t *This, dream_sys_mood_graph_point_t *out) {
    dream_sys_mood_graph_point_t sp10;
    dream_sys_mood_graph_point_t sp12;

    This->vtable->dream_sys_get_mood_average(This, (dream_sys_mood_graph_contrib_t *) &This->m_ChunkMoods, &sp10);
    This->vtable->dream_sys_get_mood_average(This, (dream_sys_mood_graph_contrib_t *) &This->m_InstanceMoods, &sp12);
    if (This->m_InstanceMoods.amount_mood == 0) {
        sp12.value = sp10.value;
    }
    out->axis.dynamic = (s8) ((sp10.axis.dynamic + sp12.axis.dynamic) / 2);
    out->axis.upper = (s8) ((sp10.axis.upper + sp12.axis.upper) / 2);
}

s32 dream_sys_get_dream_color(dream_sys_t *This) {
    dream_sys_mood_graph_point_t current_mood;

    This->vtable->dream_sys_update_dream_chart(This, &current_mood);
    return calc_dream_color(&current_mood);
}

s32 calc_dream_color(u16 *arg0) {
    s8 *p;
    s32 i;
    u16 local;
    s8 v;
    s8 *table;
    s32 idx;

    p = (s8 *) &local;
    i = 0;
    local = *arg0;
    do {
        v = *p;
        if (v >= 4) {
            *p = 2;
        } else if (v < -3) {
            *p = 0;
        } else {
            *p = 1;
        }
        i += 1;
        p += 1;
    } while (i < 2);
    v = ((s8 *) &local)[0];
    table = g_DreamColorTable;
    idx = v * 3;
    v = ((s8 *) &local)[1];
    return *(table + idx + v);
}

void dream_sys_clear_mood_graph(dream_sys_t *This, dream_sys_mood_graph_contrib_t *Contrib) {
    Contrib->last_mood.value = 0;
    Contrib->upper_mood = 0;
    Contrib->dynamic_mood = 0;
    Contrib->amount_mood = 0;
}

void dream_sys_log_mood(dream_sys_t *This,
                        dream_sys_mood_graph_contrib_t *Contrib,
                        dream_sys_mood_graph_point_t *Point) {
    Contrib->last_mood.value = Point->value;
    Contrib->dynamic_mood += Point->axis.dynamic;
    Contrib->upper_mood += Point->axis.upper;
    Contrib->amount_mood += 1;
}

void dream_sys_get_mood_average(dream_sys_t *This,
                                dream_sys_mood_graph_contrib_t *arg1,
                                dream_sys_mood_graph_point_t *arg2) {
    s32 temp_a2;

    temp_a2 = arg1->amount_mood;
    if (temp_a2 != 0) {
        arg2->axis.dynamic = calc_mood_axis(arg1->last_mood.axis.dynamic, arg1->dynamic_mood, temp_a2);
        arg2->axis.upper = calc_mood_axis(arg1->last_mood.axis.upper, arg1->upper_mood, arg1->amount_mood);
        return;
    }
    arg2->value = arg1->last_mood.value;
}

s32 calc_mood_axis(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_a1;

    var_a1 = (arg1 / arg2) + (arg0 / 3);
    if (var_a1 >= 0xA) {
        var_a1 = -9;
    } else if (var_a1 < -9) {
        var_a1 = 9;
    }
    return var_a1;
}

void dream_sys_calc_unlock_score(dream_sys_t *This) {
    s32 temp_a0;

    This->m_NavigationScore = calc_navigation_score();
    temp_a0 = This->m_InstanceScore;
    if (temp_a0 < 0) {
        This->m_InstanceScore = 0;
    } else if (temp_a0 > 50000000) {
        This->m_InstanceScore = 50000000;
    }
    This->m_TotalUnlockScore = This->m_NavigationScore + This->m_InstanceScore;
}

void dream_sys_add_flashback(dream_sys_t *This, s32 arg1, void *arg2, void *arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 count;
    s32 idx;
    u8 *slot;

    count = *(s32 *) ((u8 *) This + 0x46C);
    slot = (u8 *) This + 0x470;
    if (count < 0xA) {
        *(s32 *) ((u8 *) This + 0x46C) = count + 1;
        idx = count * 9;
    } else {
        idx = ((u32) * (s32 *) ((u8 *) This + 0x24) % 9) * 9;
    }
    slot += idx * 4;
    *(s32 *) slot = arg1;
    *(dream_sys_fb_pkt10_t *) (slot + 4) = *(dream_sys_fb_pkt10_t *) arg2;
    *(dream_sys_fb_pkt12_t *) (slot + 0xE) = *(dream_sys_fb_pkt12_t *) arg3;
    *(s16 *) (slot + 0x1C) = arg4;
    *(s16 *) (slot + 0x1A) = arg5;
    *(s32 *) (slot + 0x20) = arg6;
}

void dream_sys_flashback_saving(dream_sys_t *This, s32 arg1, s32 arg2) {
    s32 r;
    s32 temp;
    void **obj;
    s32 sp20[4];

    if (This->m_AttachedActor != 0) {
        r = rand();
        if (r % 3 == 0) {
            obj = (void **) This->m_AttachedActor;
            temp = (*(s32(**)(void **, s32, s32))(*(u32 *) obj + 0x10C))(obj, 0, 0);
            object_get_rotation_360(This, sp20);
            ((void (*)(void *, s32, s32, void *, s32, s32, s32)) This->vtable->dream_sys_add_flashback)(
                This, This->m_NextMap, temp, sp20, arg1, arg2, This->m_DayOfYear);
        }
    }
}

void dream_sys_reset_flashback_list(dream_sys_t *This) {
    This->m_FlashbackCount = 0;
}

typedef struct dream_link {
    s32 head[17];
    void *tail;
} dream_link_t;

typedef struct {
    s32 w[20];
} dream_blk50_t;

typedef struct {
    s32 w[10];
} dream_blk28_t;

void dream_sys_save_link_state(dream_sys_t *This) {
    dream_link_t *link;

    link = (dream_link_t *) This->m_Transform;
    *(dream_blk50_t *) &This->m_SavedLinkHead = *(dream_blk50_t *) link;
    *(dream_blk28_t *) &This->m_SavedLinkTail = *(dream_blk28_t *) link->tail;
}

void dream_sys_restore_link_state(dream_sys_t *This) {
    dream_link_t *link;

    link = (dream_link_t *) This->m_Transform;
    *(dream_blk50_t *) link = *(dream_blk50_t *) &This->m_SavedLinkHead;
    *(dream_blk28_t *) link->tail = *(dream_blk28_t *) &This->m_SavedLinkTail;
    link->head[0] = 0;
}

s32 dream_sys_get_set_flag(dream_sys_t *This, s32 Value) {
    s32 out;

    if (Value >= 0) {
        out = This->m_Flag;
        This->m_Flag = Value;
    } else {
        out = This->m_Flag;
    }

    return out;
}

dream_sys_vtable_t *dream_sys_get_vtable(void) {
    return &g_DREAM_SYS_VTABLE;
}

void init_nav_challenges_array(s32 *Unk1, s32 *Unk2) {
    s32 var_v1;
    s8 *var_v0;

    var_v1 = 0x1D;
    var_v0 = (char *) Unk1 + 0x1D;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    gpNavChallengesComplete = Unk1;
    *Unk2 = 0;
    gpDynamicLinkPenalty = Unk2;
}

s32 calc_navigation_score(void) {
    s32 score;
    s32 addend;
    s8 *var_v1;
    s8 *temp_a1;

    score = 0;
    addend = 1000000;
    var_v1 = (s8 *) gpNavChallengesComplete;
    temp_a1 = var_v1 + 30;
    do {
        if (*var_v1 != 0) {
            score += addend;
        }
        var_v1 += 1;
    } while ((s32) var_v1 < (s32) temp_a1);
    if (score > 29999999) {
        score = 50000000;
    }
    score -= *(s32 *) gpDynamicLinkPenalty * 0x2B10;
    if (score < 0) {
        score = 0;
    }
    return score;
}

s32 get_stage_time_limit(s32 Unk) {
    return STAGE_TIME_LIMITS[Unk];
}

s32 get_random_spawn_from_stage(void *dst, s32 chunk, s32 tick) {
    s32 six;
    s32 selected;
    u8 *spawn;
    u8 idx;
    s32 len;
    s32 r;

    (void) tick;
    six = 6;
    if (chunk >= 0) {
        selected = rand() % six;
        if (selected == chunk) {
            selected += 1;
            if (selected >= 6) {
                selected = 0;
            }
        }
    } else {
        selected = -chunk;
    }
    r = rand();
    len = LEN_STAGE_SPAWNPOINTS[selected];
    spawn = (u8 *) STAGE_SPAWNPOINTS[selected] + (r % len) * 6;
    *(dream_sys_pkt4_t *) dst = *(dream_sys_pkt4_t *) spawn;
    idx = spawn[4];
    *(dream_sys_pkt6_t *) ((u8 *) dst + 4) = *(dream_sys_pkt6_t *) ((u8 *) SPAWN_POS_ADJUST + idx * 6);
    *(s32 *) gpDynamicLinkPenalty += 1;
    return selected;
}

s32 test_for_static_link(s32 *Unk0, s32 Unk1, s32 Unk2) {
    return get_static_spawn(Unk0, Unk1, Unk2, LEN_STAGE_PERMALINK_TRIGGERS, &STAGE_PERMALINK_TRIGGERS,
                            &STAGE_PERMALINK_SPAWNS, 1);
}

s32 test_4_tunnel_links(void *Unk0, s32 Unk1, s32 Unk2) {
    return get_static_spawn(Unk0, Unk1, Unk2, g_TunnelLinkCounts, &g_TunnelLinkTriggers, &g_TunnelLinkSpawns, 1);
}

s32 get_tunnel_link(void **arg0, void **arg1, s16 *arg2) {
    u8 temp_s0;

    temp_s0 = g_TunnelLinkTriggerTransforms[g_LinkSourceStage][g_LinkSourceIndex];
    if (is_facing_angle(arg2, temp_s0) != 0) {
        if (arg1 != NULL) {
            *arg1 = (void *) (g_LinkTransforms + temp_s0 * 0xC);
        }
        if (arg0 != NULL) {
            *arg0 =
                (void *) (g_LinkTransforms + g_TunnelLinkSpawnTransforms[g_LinkTargetStage][g_LinkTargetIndex] * 0xC);
        }
        return 1;
    }
    return 0;
}

s32 is_facing_angle(s16 *arg0, s32 arg1) {
    s16 diff;
    s16 wrapped;
    u16 *table;

    table = (u16 *) ((u8 *) g_LinkTransformAngles + ((arg1 & 0xFF) * 0xC));
    diff = arg0[2] - table[0];
    wrapped = diff;
    if (diff >= 0xB5) {
        wrapped = diff - 0x168;
    } else if (diff < -0xB4) {
        wrapped = diff + 0x168;
    }
    return ((u16) (wrapped + 0x2C)) < 0x59U;
}

s32 get_dynamic_link_spawn(void *dst, s32 map, void *arg2, s32 tick) {
    s32 result;

    if (map == 3) {
        goto shared;
    }
    if (map == 1) {
        goto shared;
    }
    if (map == 5) {
        goto case5;
    }
    if (map == 9) {
        goto shared;
    }
    if (map != 0xC) {
        return -1;
    }
shared:
    if (map != 5) {
        goto check9;
    }
case5:
    if (*(s16 *) ((u8 *) arg2 + 6) < -0xFFF) {
        goto do_spawn;
    }
    if (*(s32 *) arg2 == g_ViolenceLinkTile) {
        goto do_spawn;
    }
    return -1;
check9:
    if (map != 9) {
        goto do_spawn;
    }
    if (*(s16 *) ((u8 *) arg2 + 6) < 0x800) {
        return -1;
    }
do_spawn:
    if ((tick & 1) != 0) {
        map = -0xC;
    }
    result = get_random_spawn_from_stage(dst, map, tick);
    g_LinkTargetStage = result;
    return result;
}

s32 *get_teleport_link_data(void) {
    s32 *out = NULL;

    if (g_LinkTargetStage != 0xC) {
        out = &g_DefaultLinkTransform;
    }

    return out;
}

void set_teleport_links_enabled(s32 Unk) {
    g_TeleportLinksEnabled = Unk;
}

s32 test_4_instant_teleporters(s32 Unk1, s32 Unk2, s32 Unk3) {
    if (g_TeleportLinksEnabled) {
        return get_static_spawn(Unk1, Unk2, Unk3, &g_TeleportLinkCounts, &g_TeleportLinkTriggers, &g_TeleportLinkSpawns,
                                0);
    }

    return -1;
}

s32 get_teleport_time_bonus(void) {
    return g_LinkSourceStage == 0 ? 0xA : 0;
}

s32 test_4_staircase_nodes(s32 Unk1, s32 Unk2, s32 Unk3) {
    if (!Unk3) {
        return get_static_spawn(Unk1, Unk2, 0, g_StaircaseLinkCounts, &g_StaircaseLinkTriggers, &g_StaircaseLinkSpawns,
                                0);
    }

    return -1;
}

s32 get_staircase_link(void **arg0, void **arg1, s16 *arg2) {
    u8 temp_s0;

    temp_s0 = g_StaircaseLinkTriggerTransforms[g_LinkSourceStage][g_LinkSourceIndex];
    if (is_facing_angle(arg2, temp_s0) != 0) {
        if (arg1 != NULL) {
            *arg1 = (void *) (g_LinkTransforms + temp_s0 * 0xC);
        }
        if (arg0 != NULL) {
            *arg0 = (void *) (g_LinkTransforms +
                              g_StaircaseLinkSpawnTransforms[g_LinkTargetStage][g_LinkTargetIndex] * 0xC);
        }
        return 1;
    }
    return 0;
}

s8 get_staircase_spawn_index(void) {
    return ((s8 *) g_StaircaseLinkSpawns[g_LinkTargetStage])[g_LinkTargetIndex * 6 + 5];
}

s32 get_static_spawn(void *dst, s16 *key, s32 chunk, s32 *counts, s32 *records, s32 *entries, s32 flag) {
    s32 count;
    s32 i;
    s32 table;
    s32 sub;
    dream_sys_static_spawn_t *rec;
    dream_sys_spawn_entry_t *entry;

    count = ((u8 *) counts)[chunk];
    if (count != 0) {
        rec = ((dream_sys_static_spawn_t **) records)[chunk];
        i = 0;
        while (i < count) {
            if (key[0] == rec->m_Chunk && (key[1] == rec->m_Tile || rec->m_Tile < 0)) {
                g_LinkSourceStage = chunk;
                g_LinkSourceIndex = i;
                table = rec->m_TargetStage;
                g_LinkTargetStage = table;
                sub = rec->m_TargetSpawn;
                entry = (dream_sys_spawn_entry_t *) ((u8 *) entries[table] + sub * 6);
                g_LinkTargetIndex = sub;
                *(dream_sys_pkt4_t *) dst = entry->m_ChunkTile;
                *(dream_sys_pkt6_t *) ((u8 *) dst + 4) =
                    *(dream_sys_pkt6_t *) ((u8 *) SPAWN_POS_ADJUST + entry->m_Adjustment * 6);
                if (flag != 0) {
                    ((u8 *) gpNavChallengesComplete)[entry->m_NavChallenge] = 1;
                }
                return g_LinkTargetStage;
            }
            i += 1;
            rec += 1;
        }
    }
    return -1;
}

s32 generate_initial_spawn(void *dst, s32 *time_out, void *mood, s32 tick) {
    struct {
        s16 coords;
        char pad[14];
    } loc;
    s32 chunk;
    s32 count;
    s16 *ptr;
    s32 i;
    s16 key;
    s32 ret;
    u8 idx;

    chunk = get_stage_chunk_from_mood((s8 *) &loc.coords, mood);
    if (chunk >= 0) {
        *time_out = STAGE_TIME_LIMITS[chunk];
        count = LEN_STAGE_SPAWNPOINTS[chunk];
        ptr = STAGE_SPAWNPOINTS[chunk];
        i = 0;
        if (count != 0) {
            key = loc.coords;
            do {
                i += 1;
                if (key == *ptr) {
                    goto found;
                }
                ptr += 3;
            } while (i < count);
        }
        ptr = (s16 *) ((u8 *) STAGE_SPAWNPOINTS[chunk] + (loc.coords % count) * 6);
    found:
        *(dream_sys_pkt4_t *) dst = *(dream_sys_pkt4_t *) ptr;
        idx = ((u8 *) ptr)[4];
        ret = chunk;
        *(dream_sys_pkt6_t *) ((u8 *) dst + 4) = *(dream_sys_pkt6_t *) ((u8 *) SPAWN_POS_ADJUST + idx * 6);
        return ret;
    }
    chunk = get_random_spawn_from_stage(dst, chunk, tick);
    *time_out = STAGE_TIME_LIMITS[chunk];
    return chunk;
}

extern s16 SPECIAL_DAYS[];
extern s32 g_SpecialDayMarker[4]; /* size > G8 so & uses lui */

s32 is_day_special(s16 *out, s32 day) {
    s32 magic;
    s32 i;
    s32 r;

    magic = 0x2AAAAAAB;
    i = 0;
    do {
        if (day != SPECIAL_DAYS[i]) {
            i += 1;
        } else {
            r = rand();
            out[1] = r % 6;
            out[0] = i % 12;
            return (s32) g_SpecialDayMarker;
        }
    } while ((u32) i < 0x2AU);
    return 0;
}
