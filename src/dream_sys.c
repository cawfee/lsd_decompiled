#include "dream_sys.h"
#include "477E4.h"
#include "base_class.h"

extern dream_sys_vtable_t g_DREAM_SYS_VTABLE;

extern s32 STAGE_PERMALINK_SPAWNS[];
extern s32 STAGE_PERMALINK_TRIGGERS[];
extern s32 LEN_STAGE_PERMALINK_TRIGGERS[];
extern s32 D_80088820[];
extern s32 D_80088980[];
extern s32 D_800889F0[];
extern s32 D_80088A80[];
extern s32 D_80088B24[];
extern s32 D_80088B5C[];
extern s32 D_80088BA4[];
extern s32 D_80088C4C[];
extern s32 D_80088CBC[];
extern s16 STAGE_TIME_LIMITS[];
extern s32 D_8008ABE4;
extern s32 D_8008ABF0[];
extern s32 gpNavChallengesComplete;
extern s32 gpDinamicLinkPenalty;
extern s32 D_8008ACBC;
extern s32 D_8008ACC4;
extern s32 D_8008ACC8;
extern s32 D_80087E80[];
extern s32 D_80087EA4[];
extern s32 D_80087E08[];
extern s32 D_8008ABE0;

s32 test_for_static_link(s32 *Unk0, s32 Unk1, s32 Unk2);
void execute_link(dream_sys_t *This, s32 Unk1, s32 Unk2, s32 Unk3);
s32 calc_navigation_score(void);
void helper_1_update_entity(s32 arg0, void *arg1);
void init_nav_challenges_array(s32 *Unk1, s32 *Unk2);
void *memset(void *s, int c, u32 n);

dream_sys_t *dream_sys_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    dream_sys_t *allocated = (dream_sys_t *) memory_allocate_mem(0x928);

    if (allocated) {
        dream_sys_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys_construct);

void dream_sys_unk15(dream_sys_t *This) {
    This->vtable->Unk23(This, 0);
    This->vtable->Unk16(This, 1, &D_80087E08);
    This->m_Unk31 = 0;
    This->m_Unk37 = 0;
    This->m_Unk50 = 0;
    This->m_Unk577 = 0;
    This->m_Unk578 = 0;
    This->m_Unk579 = 0;
    This->m_Unk29 = 0;
    This->m_Unk584 = 0;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys_unk18);

void func_80058A94(dream_sys_t *This) {
    void **temp_a0;

    temp_a0 = (void **)This->m_Unk18;
    ((void (*)(void **))(*(void **)((s8 *)*temp_a0 + 0xF0)))(temp_a0);
    This->vtable->Unk4(This, (void *)This->m_Unk18);
    func_80057C84()->Unk19(This);
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058B08);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80058C58);

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__timer_tick);

void func_80058E8C(dream_sys_t *This, void **Unk2, s32 Unk3) {
    func_80057C84()->Unk38(This, Unk2, Unk3);

    if ((*(u32 *) *Unk2 & 0xFFF) == 0x114) {
        This->vtable->Unk120(This, Unk2, Unk3);
    }
}

void func_80058F18(dream_sys_t *This, void **Unk2, s32 Unk3) {
    func_80057C84()->Unk54(This, Unk2, Unk3);

    if ((*(u32 *) *Unk2 & 0xFFFFF) == 0x1F234) {
        This->vtable->Unk121(This, Unk2, Unk3);
    }
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__wall_link);

void func_800590E0(void) {
}

s32 func_800590E8(dream_sys_t *This, void **Unk2, s32 Unk3) {
    s32 value;

    value = This->m_Unk25;
    if (Unk3 < 0) {
        *Unk2 = (void *) calc_dream_color((char *) &This->m_Unk99 + 2 * This->m_Unk95);
    } else {
        This->m_Unk25 = Unk3;
    }

    return value;
}

void func_80059148(dream_sys_t *This, s32 arg1) {
    This->m_Unk26 = arg1;
    if (arg1 != 0) {
        This->vtable->Unk95(This, 1);
        if (This->m_Unk544 != 0) {
            This->vtable->Unk16(This, 1, (s32 *)This->m_Unk544);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800591B4);

void func_80059310(dream_sys_t *This) {
    This->m_Unk27 = 1;
}

s32 func_8005931C(dream_sys_t *This) {
    return This->m_Unk28;
}

s32 dream_sys__get_set_dream_time_limit(dream_sys_t *This, s32 Limit) {
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

s32 func_80059360(dream_sys_t *This) {
    return This->m_GameTick / 15;
}

void func_8005937C(dream_sys_t *This, s32 Value) {
    This->m_Unk21 = Value;
}

void func_80059384(dream_sys_t *This, s32 Value) {
    This->m_Unk22 = Value;
}

void func_8005938C(dream_sys_t *This, s32 Value) {
    This->m_Unk24 = Value;
}

void func_80059394(dream_sys_t *This) {
    if (This->m_Unk27 == 0) {
        This->m_Unk28 = 0;
        This->m_Unk72 = This->m_GameTick % This->m_Unk71 == 0;
    }
}

void func_800593D8(dream_sys_t *This) {
    void (*m_Unk31)(void);
  void (*m_Unk37)(dream_sys_t *);

    m_Unk31 = (void (*)(void))This->m_Unk31;
  if ( m_Unk31 )
    m_Unk31();
    
  m_Unk37 = (void ( *)(dream_sys_t *))This->m_Unk37;
  if ( m_Unk37 )
    m_Unk37(This);
}


INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005942C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005950C);

void func_80059590(dream_sys_t *This) {
    This->m_Unk30 = 0;
}

void func_80059598(dream_sys_t *This) {
    This->m_Unk29 = 0;
}

s32 func_800595A0(dream_sys_t *This) {
    return 0;
}

void func_800595A8(dream_sys_t *This, s32 Unk) {
    This->vtable->Unk78(This, 0);

    if (Unk) {
        This->vtable->Unk77(This, 0);
    }
}

void func_80059610(dream_sys_t *This, s32 Unk2, s32 Unk3) {
    This->vtable->Unk78(This, Unk2);
    This->vtable->Unk77(This, Unk3);
}

void func_8005966C(dream_sys_t *This, s32 Unk) {
    dream_sys_vtable_t *vtable = This->vtable;

    This->m_Unk32 = Unk;

    switch (Unk) {
        case 0:
            This->m_Unk31 = 0;
            break;

        case 1:
            This->m_Unk31 = vtable->Unk79;
            break;

        case 2:
            This->m_Unk31 = vtable->Unk82;
            break;

        case 3:
            This->m_Unk31 = vtable->Unk83;
            break;

        default:
            break;
    }
}

void func_800596E8(dream_sys_t *This, s32 Unk) {
    s32 fnc;
    dream_sys_vtable_t *vtable = This->vtable;

    if (This->m_Unk38 == 2) {
        vtable->Unk94(This, 0);
    }

    This->m_Unk38 = Unk;

    switch (Unk) {
        case 0:
            This->m_Unk37 = 0;
            break;

        case 1:
            This->m_Unk37 = vtable->Unk84;
            break;

        case 2:
            fnc = vtable->Unk93;
            This->m_Unk48 = 1;
            This->m_Unk49 = 1;
            This->m_Unk37 = fnc;
            helper_1_set_entity(This->m_Unk21, &This->m_Unk50, 1, This, This->vtable->Unk100);
            break;

        default:
            break;
    }
}

void func_800597C0(dream_sys_t *This) {
    This->vtable->Unk80(This);
    This->vtable->Unk81(This);
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059814);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_800598E8);

void func_80059A1C(dream_sys_t *This) {
    This->m_Unk41 = 0;

    if (This->m_MoveState) {
        if ((This->m_MoveState & 1) == 0) {
            This->m_MoveState -= 1;
        } else {
            This->m_MoveState += 1;
        }
    }
}

void func_80059A48(void) {
}

void func_80059A50(void) {
}

void func_80059A58(dream_sys_t *This) {
    if (This->m_Unk26 == 0) {
        This->vtable->Unk92(This);
        This->vtable->Unk85(This);
    } else if (This->m_Unk26 == 2) {
        This->vtable->Unk87(This);
    } else {
        This->vtable->Unk86(This);
    }
}

void func_80059AEC(dream_sys_t *This) {
    s32 value;

    if (!This->m_Unk27) {
        value = This->vtable->Unk88(This, 1);
        This->vtable->Unk91(This, value);
    }
}

void func_80059B50(dream_sys_t *This) {
    s32 value;

    This->m_MoveState = MOVE_FORWARD;

    if (!This->m_Unk27) {
        value = This->vtable->Unk88(This, 1);
        This->vtable->Unk91(This, value);
    } else {
        This->vtable->Unk88(This, 0);
    }
}

void func_80059BD4(dream_sys_t *This) {
    This->m_MoveState = MOVE_FORWARD;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059BE0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059D1C);

void func_80059E3C(dream_sys_t *This) {
    if (This->m_Unk46 >= 0) {
        (*(void ( **)(s32, s32))(*(s32 *)This->m_Unk21 + 132))(This->m_Unk21, This->m_Unk46);
        This->m_Unk46 = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_80059E98);

void func_8005A050(dream_sys_t *This) {
    s32 state;

    state = This->m_LeftRightState;
    if (state != 0) {
        This->vtable->Unk16(This, 0, (s32 *)((state * 0xC) + (s32)D_80087E80));
        This->m_LeftRightState = 0;
    }
}

void func_8005A0B0(dream_sys_t *This) {
    s32 *temp_v1;

    if (This->m_Unk48 != 0) {
        This->vtable->Unk46(This, D_80087EA4);
        temp_v1 = (s32 *)This->m_Unk22;
        temp_v1[9] = temp_v1[9] - 0x258;
    }
    if (This->m_Unk49 != 0) {
        helper_1_update_entity(This->m_Unk21, (u8 *)This + 0xCC);
    }
}

void func_8005A134(dream_sys_t *This, s32 Unk) {
    This->m_Unk48 = 0;
    This->m_Unk49 = Unk;

    if (Unk) {
        func_8002CC84(This->m_Unk21, &This->m_Unk50);
    }
}

s32 func_8005A168(dream_sys_t *This, s32 Value) {
    s32 old_value = This->m_Unk42;

    if (Value >= 0) {
        This->m_Unk42 = Value;
        This->m_Unk43 = Value;
    }

    return old_value;
}

s32 func_8005A184(dream_sys_t *This, s32 Value) {
    s32 next_value;

    next_value = This->m_Unk42;
    if (next_value != Value) {
        This->m_Unk43 = next_value;
        This->m_Unk42 = Value;
    }
    return next_value;
}

void func_8005A1A4(dream_sys_t *This) {
    This->m_Unk42 = This->m_Unk43;
}

void func_8005A1B0(dream_sys_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    if (Unk2 >= 0) {
        This->m_Unk72 = Unk2;
    }
    if (Unk3 >= 0) {
        This->m_Unk73 = Unk3;
    }
    if (Unk4 >= 0) {
        This->m_Unk74 = Unk4;
    }
    if (Unk5 >= 0) {
        This->m_Unk75 = Unk5;
    }
}

void func_8005A1EC(dream_sys_t *This, s32 Value) {
    This->m_Unk71 = Value;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A1F4);

void dream_sys__init_new_game(dream_sys_t *This) {
    s32 temp_v1;

    temp_v1 = D_8008ABE0;
    This->m_Unk94 = 0;
    This->m_Unk95 = 0;
    This->m_Unk96 = 0;
    This->m_Unk97 = 0;
    This->m_Unk98 = 0;
    This->m_Unk282 = 0;
    *((u8 *)This + 0x5DF) = 0;
    *((u8 *)This + 0x5D8) = 0;
    This->screen_shake_enabled = 1;
    This->m_Unk414 = 0;
    This->m_Unk415 = 0;
    This->m_Unk93 = temp_v1;
    init_nav_challenges_array(&This->m_Unk375, &This->m_Unk383);
    memset(&This->m_Unk416, 0, 0x1F4);
}

void dream_sys__get_set_screen_shake(dream_sys_t *This, s32 *Value) {
    s32 old_value = This->screen_shake_enabled;
    This->screen_shake_enabled = *Value;
    *Value = old_value;
}

s32 func_8005A2E4(dream_sys_t *This, s32 *Out) {
    if (Out) {
        *Out = This->m_Unk94;
    }
    return This->m_Unk95 + 1;
}

s32 dream_sys__advance_day(dream_sys_t *This) {
    s32 next_day = This->m_Unk95 + 1;
    This->m_Unk95 = next_day;

    if (next_day > 364) {
        This->m_Unk95 = 0;
        This->m_Unk94++;
    }

    return This->m_Unk95;
}

void func_8005A33C(dream_sys_t *This) {
    This->m_Unk541 = 0;
}

s32 func_8005A344(dream_sys_t *This) {
    return This->m_Unk541;
}

s32 *func_8005A350(dream_sys_t *This, s32 *Size) {
    if (Size) {
        *Size = 0x700;
    }

    return &This->m_Unk93;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__start_day);

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__end_day);

dream_sys_t *dream_sys__get_cinematic(dream_sys_t *This, void *Unk) {
    return (dream_sys_t *)__builtin_memcpy((char *)This, (char *)Unk + 0x168, 4);
}

s32 generate_initial_spawn(void *arg0, s32 *arg1, void *arg2, s32 arg3);

void dream_sys__init_spawn_loc(dream_sys_t *This) {
    s32 sp14;
    dream_sys_mood_graph_point_t sp10;

    This->vtable->Unk122(This, &sp10, 1);
    This->m_NextMap =
        generate_initial_spawn(&This->m_Unk90, &sp14, &sp10, This->m_Unk95);
    sp14 = This->vtable->Unk64(This, sp14);
    This->m_Unk16 = 0xB;
}

void dream_sys__dynamic_link(dream_sys_t *This) {
    s32 RandomSpawnFromStage;;
    
    if ( !This->m_Unk16 )
  {
    RandomSpawnFromStage = get_random_spawn_from_stage(&This->m_Unk90, This->m_NextMap, This->m_GameTick);
    execute_link(This, RandomSpawnFromStage, 12, 1);
  }
}

s32 dream_sys__static_wall_link(dream_sys_t *This, s32 arg1) {
    s32 temp_v0;

    if (This->m_Unk16 != 0) {
        return 0;
    }
    temp_v0 = test_for_static_link(&This->m_Unk90, arg1, This->m_NextMap);
    if (temp_v0 < 0) {
        return 0;
    }
    execute_link(This, temp_v0, 0xD, 1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__load_next_flashback);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A700);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A7A0);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A82C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", execute_link);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005A9CC);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AB2C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AC24);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AD68);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AE40);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005AF64);

s32 func_8005AFD0(dream_sys_t *This) {
    return This->m_NextMap;
}

void dream_sys__process_chunk_change(dream_sys_t *This, void *arg1, s32 arg2) {
    if (arg2 == 5) {
        This->vtable->Unk124(
            This,
            (void *)((s32 (*)(void *, s32, s32))(*(void **)(*(s32 *)arg1 + 0x10C)))(arg1, 0, 0));
    }
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__instance_effects_on_journal);

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__get_previous_day_mood);

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__init_mood_contibutors);

void dream_sys__log_chunk_mood(dream_sys_t *This, void *CurrentPosition) {
    dream_sys_mood_graph_point_t *point = get_mood_from_stage_chunk(This->m_NextMap, CurrentPosition);
    This->vtable->Unk129(This, &This->m_Unk80, point);
}

void dream_sys__log_instance_mood(dream_sys_t *This, dream_sys_mood_graph_point_t *Source) {
    This->vtable->Unk129(This, &This->m_Unk84, Source);
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__update_dream_chart);

s32 dream_sys__get_dream_color(dream_sys_t *This) {
    dream_sys_mood_graph_point_t current_mood;

    This->vtable->Unk126(This, &current_mood);
    return calc_dream_color(&current_mood);
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", calc_dream_color);

void dream_sys__clear_mood_graph(dream_sys_t *This, dream_sys_mood_graph_contrib_t *Contrib) {
    Contrib->last_mood.value = 0;
    Contrib->upper_mood = 0;
    Contrib->dynamic_mood = 0;
    Contrib->amount_mood = 0;
}

void dream_sys__log_mood(dream_sys_t *This, dream_sys_mood_graph_contrib_t *Contrib, dream_sys_mood_graph_point_t *Point) {
    Contrib->last_mood.value = Point->value;
    Contrib->dynamic_mood += Point->axis.dynamic;
    Contrib->upper_mood += Point->axis.upper;
    Contrib->amount_mood += 1;
}

void dream_sys__get_mood_average(dream_sys_t *This, dream_sys_mood_graph_contrib_t *arg1,
                                 dream_sys_mood_graph_point_t *arg2) {
    s32 temp_a2;

    temp_a2 = arg1->amount_mood;
    if (temp_a2 != 0) {
        arg2->axis.dynamic =
            calc_mood_axis(arg1->last_mood.axis.dynamic, arg1->dynamic_mood, temp_a2);
        arg2->axis.upper =
            calc_mood_axis(arg1->last_mood.axis.upper, arg1->upper_mood, arg1->amount_mood);
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

void dream_sys__calc_unlock_score(dream_sys_t *This) {
    s32 temp_a0;

    This->m_Unk97 = calc_navigation_score();
    temp_a0 = This->m_Unk98;
    if (temp_a0 < 0) {
        This->m_Unk98 = 0;
    } else if (temp_a0 > 0x02FAF080) {
        This->m_Unk98 = 0x02FAF080;
    }
    This->m_Unk96 = This->m_Unk97 + This->m_Unk98;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__add_flashback);

INCLUDE_ASM("asm/nonmatchings/dream_sys", dream_sys__flashback_saving);

void dream_sys__reset_flashback_list(dream_sys_t *This) {
    This->m_Unk282 = 0;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005B904);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005B990);

s32 func_8005BA20(dream_sys_t *This, s32 Value) {
    s32 out;

    if (Value >= 0) {
        out = This->m_Unk584;
        This->m_Unk584 = Value;
    } else {
        out = This->m_Unk584;
    }

    return out;
}


dream_sys_vtable_t *dream_sys_get_vtable(void) {
    return &g_DREAM_SYS_VTABLE;
}

void init_nav_challenges_array(s32 *Unk1, s32 *Unk2) {
    s32 var_v1;
    s8* var_v0;

    var_v1 = 0x1D;
    var_v0 = (char *) Unk1 + 0x1D;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    gpNavChallengesComplete = Unk1;
    *Unk2 = 0;
    gpDinamicLinkPenalty = Unk2;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", calc_navigation_score);

s32 func_8005BB14(s32 Unk) {
    return STAGE_TIME_LIMITS[Unk];
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", get_random_spawn_from_stage);

s32 test_for_static_link(s32 *Unk0, s32 Unk1, s32 Unk2) {
    return get_static_spawn(Unk0, Unk1, Unk2, LEN_STAGE_PERMALINK_TRIGGERS, &STAGE_PERMALINK_TRIGGERS, &STAGE_PERMALINK_SPAWNS, 1);
}

void test_4_tunnel_links(s32 Unk0, s32 Unk1, s32 Unk2) {
    get_static_spawn(Unk0, Unk1, Unk2, D_800889F0, &D_80088980, &D_80088820, 1);
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BD3C);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BE28);

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005BE90);

s32 *func_8005BF48(void) {
    s32 *out = NULL;
    
    if (D_8008ACC4 != 0xC) {
        out = &D_8008ABF0;
    }
    
    return out;
}

void func_8005BF68(s32 Unk) {
    D_8008ABE4 = Unk;
}

s32 test_4_instant_teleporters(s32 Unk1, s32 Unk2, s32 Unk3) {
    if (D_8008ABE4) {
        return get_static_spawn(Unk1, Unk2, Unk3, &D_80088B5C, &D_80088B24, &D_80088A80, 0);
    }
    
    return -1;
}

s32 func_8005BFC4(void) {
    return D_8008ACBC == 0 ? 0xA : 0;
}

s32 test_4_staircase_nodes(s32 Unk1, s32 Unk2, s32 Unk3) {
    if (!Unk3) {
        return get_static_spawn(Unk1, Unk2, 0, D_80088CBC, &D_80088C4C, &D_80088BA4, 0);
    }

    return -1;
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", func_8005C02C);

s8 func_8005C118(void) {
    return ((s8 *)D_80088BA4[D_8008ACC4])[D_8008ACC8 * 6 + 5];
}

INCLUDE_ASM("asm/nonmatchings/dream_sys", get_static_spawn);

INCLUDE_ASM("asm/nonmatchings/dream_sys", generate_initial_spawn);

INCLUDE_ASM("asm/nonmatchings/dream_sys", is_day_special);
