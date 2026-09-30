#include "entity.h"
#include "55DD4.h"
#include "dream_sys.h"

extern entity_vtable_t g_ENTITY_VTABLE;

extern s32 D_80089C58[3];
extern s32 D_80089C64[3];
extern s32 D_80089C70[3];
extern s32 D_80089C7C[3];
extern s32 D_80089C88[3];
extern s32 D_80089C94[3];
extern s32 D_80089CA0[3];
extern s32 D_80089CAC[3];
extern s32 D_80089CB8[3];
extern s32 D_80089CC4[3];
extern s32 D_80089CD0[3];
extern s32 D_80089CDC[3];
extern s32 D_80089CE8[3];
extern s32 D_80089CF4[3];
extern s32 D_80089D00[3];
extern s32 D_80089D18[3];
extern s32 D_80089D24[6];
extern s32 D_80089D3C[3];
extern s32 D_80089D48[3];
extern s32 D_80089D54[3];
extern s32 D_80089D60[3];
extern s32 D_80089D6C[3];
extern s32 D_80089D78[6];
extern s32 D_80089D90[3];
extern s32 D_80089D9C[3];
extern s32 D_80089DA8[3];
extern s32 D_80089DB4[3];
extern s32 D_80089DC0[3];
extern s32 D_80089DCC[3];
extern s32 D_80089DD8[3];
extern s32 D_80089DE4[3];
extern s32 D_80089DF0[3];
extern s32 D_80089DFC[3];
extern s32 D_80089E14[3];
extern s32 D_80089E20[3];
extern s32 D_80089E2C[3];
extern s32 D_80089E38[3];
extern s32 D_80089E44[3];
extern s32 D_80089E50[3];
extern s32 D_80089E5C[6];
extern s32 D_80089E74[3];
extern s32 D_80089E80[3];
extern u8 D_80089E8C[22];
extern s16 D_80089EA2;
extern void *D_8008AC14;
extern void *D_8008AC0C;
extern void *D_8008AC1C;

extern entity_prop_t g_ENTITY_TABLE[];

void entity_check_event_video(entity_t *This, s32 Unk2);
s32 entity_check_proximity(entity_t *This, vec3d_t *Location, s32 Unk3, s32 Unk4);

entity_t *entity_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    entity_t *allocated = (entity_t *) memory_allocate_mem(0x108);

    if (allocated) {
        if (entity_get_vtable()->entity_construct(allocated, Unk1, Unk2, Unk3) == NULL) {
            memory_free_mem(allocated);
            return NULL;
        }

        return allocated;
    }

    return NULL;
}

entity_vtable_t *entity_construct(entity_t *This, s32 EntityID, s32 Unk3, s32 Unk4) {
    if (class_55DD4_get_vtable()->class_55DD4_construct(This, Unk3, Unk4)) {
        This->vtable = entity_get_vtable();
        This->m_EntityID = EntityID;
        This->m_EntityContext = 0;
        This->m_Effect = NULL;
        This->m_Unk64 = 0;
        This->vtable->Unk15(This);
        return This;
    }

    return NULL;
}

effect_t *entity_create_effect(entity_t *This, void *model, void *attach_arg, s32 color_step, s32 variant) {
    effect_t *out;
    effect_t *temp_v0;

    temp_v0 = This->m_Effect;
    if (temp_v0 == NULL) {
        void *create_arg = model;
        if (create_arg == NULL) {
            create_arg = &D_8008AC14;
        }

        out = effect_create(create_arg, 0, variant);
        if (out == NULL) {
            return NULL;
        }

        This->m_Effect = out;
    } else {
        out = temp_v0;
    }

    out->vtable->Unk19(out);

    out->vtable->Unk18(out, This, attach_arg != NULL ? attach_arg : &D_8008AC0C);
    out->vtable->effect_set_color_step(out, color_step);

    return out;
}

void entity_cleanup(entity_t *This) {
    if (This->m_Effect) {
        This->m_Effect->vtable->Destroy(This->m_Effect);
    }

    if (This->m_Unk64) {
        (*(void (**)(s32))(*(s32 *) This->m_Unk64 + 4))(This->m_Unk64);
    }

    class_55DD4_get_vtable()->class_55DD4_cleanup(This);
}

void entity_init(entity_t *This) {
    if ((u8) ((u32) (g_ENTITY_TABLE[This->m_EntityID].unlock - 1)) < 9) {
        This->vtable->Unk27(This, 1);
    }

    This->vtable->Unk66(This, 66);
    This->vtable->entity_disable_link(This);
}

void entity_start(entity_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    if (This->m_Unk2 == 0) {
        s32 entity_id;

        class_55DD4_get_vtable()->Unk18(This, Unk2, Unk3, Unk4, Unk5);

        entity_id = This->m_EntityID;
        This->m_Unk18 = Unk4;

        if (g_ENTITY_TABLE[entity_id].behaviour == 0) {
            This->vtable->entity_enable_link(This);

            if (g_ENTITY_TABLE[This->m_EntityID].link_flag == 0) {
                This->vtable->entity_start_behaviour(This);
            }
        }
    }
}

void entity_stop(entity_t *This) {
    if (This->m_Unk2) {
        This->vtable->entity_disable_link(This);
        class_55DD4_get_vtable()->Unk19(This);
        This->m_Unk18 = 0;
    }
}

void entity_update(entity_t *This, s32 Unk2, s32 Unk3) {
    if (This->vtable->entity_check_interaction(This)) {
        This->vtable->entity_check_interaction_range(This);
    }
    if (This->vtable->entity_check_link_trigger(This)) {
        This->vtable->entity_check_link_proximity(This);
    }
    This->vtable->entity_check_interaction_angle(This);
    class_55DD4_get_vtable()->Unk37(This, Unk2, Unk3);
}

void entity_notify_interaction(entity_t *This, s32 Unk2, s32 Unk3) {
    s32 v5;

    v5 = g_ENTITY_TABLE[This->m_EntityID].link_stage;

    if (((u32) (Unk3 - 2) >= 7U) || (v5 > 0)) {
        class_55DD4_get_vtable()->Unk54(This, Unk2, Unk3);

        if ((Unk3 == 4) && (v5 > 0)) {
            if (v5 != 127) {
                Unk3 = ENTITY_NOTIFY_LINK;
            } else {
                Unk3 = ENTITY_NOTIFY_LINK_END;
                if (g_ENTITY_TABLE[This->m_EntityID].event_video_id != 0) {
                    Unk3 = ENTITY_NOTIFY_LINK_VIDEO;
                }
            }
            This->vtable->Notify(This, Unk3);
        }
    }
}

void entity_notify_interaction_done(entity_t *This, s32 Unk2, s32 Unk3) {
    class_55DD4_get_vtable()->Unk55(This, Unk2, Unk3);
    if (Unk3 == 4) {
        This->vtable->entity_disable_link(This);
    }
}

void entity_tick(entity_t *This) {
    helper_1_update_entity(This->m_Helper, &This->m_EntityContext);
    ++This->m_Tick;
}

s32 entity_check_proximity(entity_t *This, vec3d_t *Location, s32 Unk3, s32 Unk4) {
    vec3d_t local_data;
    s8 unlock_value;
    s32 call_arg_1;
    s32 call_arg_2;

    local_data = *Location;

    unlock_value = g_ENTITY_TABLE[This->m_EntityID].unlock;

    if ((u8) (unlock_value + 9) < 9) {
        local_data.y += (s32) unlock_value << 10;
    }

    if (Unk4 < 0) {
        Unk4 = 2048 / ((~Unk4) + 1);
    } else {
        Unk4 = Unk4 << 11;
    }

    call_arg_1 = 0;
    call_arg_2 = Unk3 << 11;

    return This->m_DreamSys->vtable->dream_sys_resolve_target_position(This->m_DreamSys, call_arg_1, call_arg_2, &local_data, Unk4);
}

s32 entity_get_distance(entity_t *This, void *a1) {
    int *v2_ptr;
    void *a0_ptr;
    int diff1;
    s32 diff2;
    s32 result;

    v2_ptr = NULL;
    if (*(int *) ((char *) a1 + 0xC) != 0) {
        v2_ptr = (int *) (*(int *) ((char *) a1 + 0x14) + 0x38);
    }

    a0_ptr = This->m_Transform;

    diff1 = *(int *) ((char *) a0_ptr + 0x18) - *v2_ptr;
    if (diff1 < 0) {
        diff1 = ~diff1 + 1;
    }

    diff2 = *(int *) ((char *) a0_ptr + 0x20) - v2_ptr[2];

    if (diff2 >= 0) {
        result = diff1 + diff2;
    } else {
        result = diff1 - diff2;
    }

    return result;
}

s32 entity_get_trigger_ratio(entity_t *This) {
    dream_sys_t *dream = This->m_DreamSys;

    if (dream) {
        s32 vcall_result = This->vtable->entity_get_distance(This, dream);
        s32 array_val_shifted = (s32) g_ENTITY_TABLE[This->m_EntityID].proximity << 11;

        if (array_val_shifted >= vcall_result) {
            s32 temp_quotient = array_val_shifted / This->m_Unk43;

            return vcall_result / temp_quotient;
        }
    }

    return -1;
}

s8 *entity_get_mood_effect(entity_t *This) {
    return &g_ENTITY_TABLE[This->m_EntityID].mood_effect[0];
}

s32 entity_get_unlock_effect(entity_t *This) {
    return 1000 * g_ENTITY_TABLE[This->m_EntityID].unlock;
}

s32 entity_get_link_stage(entity_t *This) {
    s8 val = g_ENTITY_TABLE[This->m_EntityID].link_stage;

    if (val < 0) {
        return ~val;
    } else {
        return val - 1;
    }
}

s32 entity_get_event_video(entity_t *This) {
    return g_ENTITY_TABLE[This->m_EntityID].event_video_id - 1;
}

void entity_enable_link(entity_t *This) {
    This->vtable->Unk23(This, 1);
    This->m_LinkEnabled = 1;
    This->m_Unk8 = 0;
}

void entity_disable_link(entity_t *This) {
    This->vtable->Unk23(This, 0);
    This->vtable->entity_stop_behaviour(This);
    This->vtable->entity_set_triggered(This, 0);
    This->m_LinkEnabled = 0;
}

void entity_set_triggered(entity_t *This, s32 Value) {
    if (Value) {
        This->vtable->Notify(This, ENTITY_NOTIFY_TRIGGERED);
    }
    This->m_Triggered = Value;
}

void entity_start_behaviour(entity_t *This) {
    helper_1_set_entity(This->m_Helper, &This->m_EntityContext, This->m_EntityID + 1, This,
                        g_ENTITY_TABLE[This->m_EntityID].behaviour_fn);

    This->vtable->Unk74(This); // This->m_Unk35 = 1
    This->vtable->Unk67(This); // This->m_Unk34 = 1

    This->m_Tick = 0;
    This->m_BehaviourActive = 1;
}

void entity_stop_behaviour(entity_t *This) {
    sound_update_entity(This->m_Helper, &This->m_EntityContext);
    This->vtable->Unk75(This);
    This->vtable->Unk68(This);
    This->m_BehaviourActive = 0;
}

s32 entity_check_interaction(entity_t *This) {
    if (This->m_LinkEnabled == 0 && This->m_State != 1) {
        entity_prop_t *property = &g_ENTITY_TABLE[This->m_EntityID];
        s32 flag = 0;
        s8 p3;

        p3 = property->behaviour;
        if (p3 == 0) {
            goto end_logic;
        }
        if (p3 == 4) {
            goto rand_check;
        }
        if (property->interaction_range == 0) {
            goto end_logic;
        }

        if (entity_check_proximity(This, This->m_Transform + 24, property->interaction_range, property->interaction_param) ==
            0) {
            goto func_returned_zero;
        }

        p3 = property->behaviour;
        if (p3 == 1) {
            flag = 1;
            goto end_logic;
        } else if (p3 == 3) {
            goto rand_check;
        } else {
            goto end_logic;
        }

    func_returned_zero:
        if (property->behaviour != 2) {
            goto end_logic;
        } else {
            flag = 1;
            goto end_logic;
        }

    rand_check:
        if ((rand() & 0x7F) == 0) {
            flag = 1;
        }

    end_logic:
        if (flag) {
            This->vtable->entity_enable_link(This);
        }
    }
    return This->m_LinkEnabled;
}

s32 entity_check_interaction_range(entity_t *This) {
    if (This->m_LinkEnabled != 0) {
        u8 *data_ptr;
        s32 should_call;

        data_ptr = &g_ENTITY_TABLE[This->m_EntityID];
        entity_check_event_video(This, 0);

        should_call = 0;

        if ((data_ptr[4] != 0) && (data_ptr[4] != 3)) {
            if (data_ptr[4] >= 10) {
                should_call = (This->m_Unk8 == (data_ptr[4] * 15));
            } else {
                s8 val5 = ((s8 *) data_ptr)[5];

                if (val5 != 0) {
                    s8 val9 = ((s8 *) data_ptr)[9];

                    if (entity_check_proximity(This, This->m_Transform + 24, val5, val9) != 0) {
                        if (data_ptr[4] == 1) {
                            should_call = 1;
                        }
                    } else {
                        if (data_ptr[4] == 2) {
                            should_call = 1;
                        }
                    }
                }
            }
        }

        if (should_call) {
            This->vtable->entity_disable_link(This);
        }
    }

    return This->m_LinkEnabled;
}

s32 entity_check_interaction_angle(entity_t *this) {
    entity_prop_t *property;
    s32 val;

    property = &g_ENTITY_TABLE[this->m_EntityID];

    if (this->m_LinkEnabled != 0) {
        if (this->m_Triggered == 0) {
            s32 func_arg1 = this->m_Transform + 24;

            val = property->interaction_angle;

            if (val < 0) {
                val = ~val + 1;
            }

            if (entity_check_proximity(this, func_arg1, val, property->interaction_param) != 0) {
                this->vtable->entity_set_triggered(this, 1);
            }
        }

        if (property->interaction_angle < 0) {
            func_8001EACC(this, this->m_DreamSys, 1, 0, 0);
        }
    }

    return this->m_Triggered;
}

s32 entity_check_link_trigger(entity_t *This) {
    if (This->m_LinkEnabled) {
        if (This->m_BehaviourActive) {
            return This->m_BehaviourActive;
        }

        if (This->m_State != 1) {
            entity_prop_t *property = &g_ENTITY_TABLE[This->m_EntityID];
            s32 link_flag = property->link_flag;

            if (link_flag) {
                s32 arg1_val = This->m_Transform + 24;

                if (link_flag < 0) {
                    link_flag = ~link_flag + 1;
                }

                if (entity_check_proximity(This, arg1_val, link_flag, property->interaction_param)) {
                    This->vtable->entity_start_behaviour(This);
                }
            }
        }
    }

    return This->m_BehaviourActive;
}

void entity_check_event_video(entity_t *This, s32 Unk2) {
    s32 entity_id = This->m_EntityID;

    if (g_ENTITY_TABLE[entity_id].link_stage < 0) {
        s8 val = g_ENTITY_TABLE[entity_id].event_video_id;

        if (val) {
            if (entity_is_facing_target(This, val << 9)) {
                This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
            }
        }
    }
}

s32 entity_is_facing_target(entity_t *This, s32 Unk2) {
    s32 v2;
    s32 v3;
    void *ptr_from_unk36;
    void *ptr_from_unk36_deref;
    void *ptr_from_unk4;

    ptr_from_unk36 = This->m_DreamSys;
    ptr_from_unk36_deref = *(void **) ((char *) ptr_from_unk36 + 0x14);
    ptr_from_unk4 = (void *) This->m_Transform;
    v2 = *(s32 *) ((char *) ptr_from_unk36_deref + 0x1C);
    v3 = *(s32 *) ((char *) ptr_from_unk4 + 0x1C);

    if (v2 + 512 < v3) {
        return 0;
    }
    if (v3 < v2 - 512) {
        return 0;
    }

    {
        s32 call_result;
        s32 ret_val;

        call_result =
            ((s32(*)(entity_t *, void *, s32))This->vtable->entity_get_distance)(This, ptr_from_unk36, v2);

        if (call_result < Unk2) {
            ret_val = 1;
        } else {
            ret_val = (ret_val = 1, ret_val & 0);
        }
        return ret_val;
    }
}

s32 entity_check_link_proximity(const entity_t *This) {
    if (This->m_LinkEnabled != 0 && This->m_BehaviourActive != 0) {
        entity_prop_t *property;
        s8 link_flag;
        s32 unk4;

        property = &g_ENTITY_TABLE[This->m_EntityID];
        link_flag = property->link_flag;

        if (link_flag < 0) {
            unk4 = This->m_Transform;

            if (entity_check_proximity(This, unk4 + 24, ~link_flag + 1, property->interaction_param) == 0) {
                This->vtable->entity_stop_behaviour(This);
            }
        }
    }

    return This->m_BehaviourActive;
}

entity_vtable_t *entity_get_vtable() {
    return &g_ENTITY_VTABLE;
}

// entity_t *, entity_context_t *, -1

void entity_astronaut(entity_t *This, s32 *arg1) {
    s32 tick;

    if (arg1[1] == 0) {
        if (This->m_DreamSys->vtable->dream_sys_get_dream_color(This->m_DreamSys) == DREAM_COLOR_PINK) {
            This->m_State = 0x64;
        }
    }
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (This->m_State == 0) {
        if ((arg1[1] % 10) == 0) {
            arg1[7] = 5;
            arg1[8] = -2;
        }
        tick = This->m_Tick;
        if (tick == 0x960) {
            This->m_Tick = -1;
            return;
        }
        if (tick < 0x4B0) {
            This->vtable->Unk48(This, 0x32, 0);
        } else {
            This->vtable->Unk48(This, -0x32, 0);
        }
        return;
    }
    tick = This->m_Tick;
    if (tick < 0xFA) {
        if ((arg1[1] % 10) == 0) {
            arg1[7] = 5;
            arg1[8] = -2;
        }
        tick = This->m_Tick;
        if (tick < 0x64) {
            This->vtable->Unk48(This, 0x32, 0);
            return;
        }
        if (tick < 0xFA) {
            This->vtable->Unk46(This, &D_80089DA8);
        }
        return;
    }
    if (tick == 0xFA) {
        This->vtable->Unk75(This);
        arg1[7] = -2;
        return;
    }
    if ((u32)(tick - 0x105) < 0x133) {
        This->vtable->Unk48(This, -0x32, 0);
        This->vtable->Unk16(This, 1, &D_80089CE8);
        return;
    }
    if (tick < 0x239) {
        return;
    }
    This->vtable->Unk16(This, 1, &D_80089CF4);
}

void entity_gargoyle(entity_t *This, s32 *arg1) {
    arg1[4] = 0;
    if (arg1[1] == 0) {
        arg1[7] = 0x14;
        arg1[12] = 0x14;
        arg1[17] = 0x14;
        This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 1);
    }
    func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    This->vtable->Unk48(This, -0x5A, 0);
    if (This->m_Tick == 0x1E) {
        This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
    }
}

void entity_futon(entity_t *This, s32 *Unk) {
    s32 v2; // $v0
  s32 v4; // $v1

  v2 = This->vtable->entity_get_trigger_ratio(This);
  v4 = Unk[1];
  Unk[4] = v2;
  if ( !v4 )
    Unk[7] = 23;
}

void entity_gargoyle_pit(entity_t *This, s32 *arg1) {
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (This->m_Unk32 == (This->m_Unk31 / 2)) {
        arg1[7] = 7;
        arg1[8] = -2;
        arg1[12] = 3;
        arg1[13] = -2;
    }
    if ((arg1[1] % 90) < 3) {
        arg1[17] = 6;
        arg1[18] = -1;
    }
    if (This->m_Tick >= 0x79) {
        This->vtable->Unk16(This, 0, &D_80089CA0);
        This->vtable->Unk48(This, -0x140, 0);
        return;
    }
    if ((This->m_Tick >= 0x38) || (entity_check_proximity(This, This->m_Transform + 24, 1, 1) != 0)) {
        This->vtable->Unk46(This, &D_80089D78);
        return;
    }
    if (This->m_Tick >= 0xA) {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        This->vtable->Unk48(This, -0x100, 0);
    } else {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    }
}

void entity_elephant(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DF0);
    This->vtable->Unk46(This, &D_80089D78);
}

void entity_minotaur(entity_t *This, s32 *arg1) {
    u32 temp;
    s32 half;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = This->m_Unk31;
    half = ((s32)(temp + (temp >> 31))) >> 1;
    if ((arg1[1] % half) == 0) {
        arg1[7] = 0xA;
    }
    This->vtable->Unk48(This, -0x1E, 0);
}

void entity_giant_minotaur(entity_t *This, s32 *Unk) {
    s32 v2; // $v0

  v2 = Unk[1];
  Unk[4] = 0;
  if ( !v2 )
  {
    Unk[7] = 11;
    Unk[12] = 11;
    Unk[17] = 11;
  }
  This->vtable->Unk48(This, -30, 0);
}

void entity_maiko_giant(entity_t *This, s32 *arg1) {
    s32 *ptr;
    s32 temp;
    u32 utemp;
    s32 half;

    *(s16 *)&This->m_Unk17 = -0x14;
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    utemp = This->m_Unk31;
    half = ((s32)(utemp + (utemp >> 31))) >> 1;
    ptr = NULL;
    if ((arg1[1] % half) == 0) {
        arg1[7] = 0xA;
        arg1[8] = 1;
    }
    temp = This->m_State;
    if (temp == 0xB) {
        temp = This->m_Tick;
        if (temp == 0xA8C) {
            ptr = &D_80089C94;
        }
        if (temp == 0xC6C) {
            ptr = &D_80089C88;
        }
        if (temp == 0xE10) {
            ptr = &D_80089C94;
        }
        if ((u32)(temp - 0xD5D) < 0x78U) {
            if (This->m_DreamSys->vtable->dream_sys_get_action_pressed(This->m_DreamSys) != 0) {
                This->m_Tick = 0;
                This->m_State = 0xD;
            }
        }
    } else if (temp == 0xC) {
        if (This->m_Tick == 0x7BC) {
            ptr = &D_80089C94;
        }
    } else if (temp == 0xD) {
        *(s16 *)&This->m_Unk17 = -0x78;
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        This->vtable->Unk17(This, 1, &D_80089DD8);
        if (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0x400) {
            This->vtable->Notify(This, ENTITY_NOTIFY_LINK_VIDEO);
        }
    }
    if (This->m_Tick == 0x618) {
        if (rand() & 1) {
            ptr = &D_80089C88;
            This->m_State = 0xB;
        } else {
            ptr = &D_80089C94;
            This->m_State = 0xC;
        }
    }
    if (ptr != NULL) {
        This->vtable->Unk16(This, 0, ptr);
    }
    This->vtable->Unk51(This, *(s16 *)&This->m_Unk17, 0);
    if ((This->m_State != 0xC) && (This->m_Unk9 != 0)) {
        This->vtable->Unk50(This, -0xC8, 0);
    }
}

void entity_old_woman(entity_t *This) {
    s32 count;

    if (This->m_Tick == 0) {
        if ((rand() & 1) == 0) {
            This->m_State = 0xB;
        }
    }
    if (*(s32 *)(This->m_Transform + 0x1C) < 0x7D0) {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    }
    if (This->m_State == 0xB) {
        if (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0xA00) {
            (*(void (**)(s32, s32, s32))(*(s32 *)This->m_Unk18 + 0x138))(This->m_Unk18, 1, 1);
            This->m_Tick = 1;
            This->m_State = 0xC;
        }
    } else if (This->m_State == 0xC) {
        count = This->m_Tick;
        This->m_Tick = count + 1;
        if (count == 0x12C) {
            This->vtable->Notify(This, ENTITY_NOTIFY_LINK_END);
        }
    }
}

void entity_bell_striker(entity_t *This, s32 *arg1) {
    s32 temp;
    s32 r;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = arg1[1];
    if (temp == 0) {
        arg1[7] = 0xC;
        This->m_State++;
    } else if (temp >= (This->m_Unk31 - 1)) {
        arg1[1] = -1;
    }
    if (This->m_State == 0x24) {
        r = rand();
        if (r == ((r / 3) * 3)) {
            This->vtable->Notify(This, ENTITY_NOTIFY_LINK_VIDEO);
        }
    }
}

void entity_boatman(entity_t *This, s32 *Unk) {
    Unk[4] = This->vtable->entity_get_trigger_ratio(This);
    if (This->m_Unk32 == 0xA) {
        Unk[7] = 0xD;
    }
    This->vtable->Unk48(This, -0xA, 0);
}

void entity_drumstick(entity_t *This, s32 *Unk) {
    if (!This->m_Tick) {
        Unk[4] = 0;
        Unk[7] = 15;
    }
}

void entity_fox(entity_t *This) {
    s32 state;
    s32 roll;
    s32 *clip;

    if (This->m_Tick == 0) {
        if (rand() & 1) {
            This->m_State = 0xB;
        }
    }
    state = This->m_State;
    if (state == 0) {
        if (This->m_Tick < 0x40) {
            This->vtable->Unk48(This, -0x5A, 0);
            return;
        }
        if (This->m_Tick == 0x40) {
            roll = rand();
            clip = &D_80089C94;
            if (roll & 1) {
                clip = &D_80089C88;
            }
            This->vtable->Unk16(This, 0, clip);
            This->vtable->Unk46(This, &D_80089D3C);
            return;
        }
        This->vtable->Unk51(This, -0x176, rand() % 2);
        return;
    }
    if (state != 0xB) {
        return;
    }
    if ((This->m_Tick % 5) == 0) {
        This->vtable->Unk16(This, 0, &D_80089C88);
    }
    This->vtable->Unk48(This, -0x800, 0);
    This->vtable->Unk23(This, (rand() % 7) == 0);
}

void entity_halo(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DD8);
}

void entity_tea_doll(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[7] = 0x11;
    }
    This->vtable->Unk48(This, -0x100, 0);
}

void entity_buddha(entity_t *This, s32 *arg1) {
    s32 r;

    if (This->m_Tick == 0) {
        r = rand();
        if (r == ((r / 7) * 7)) {
            This->vtable->Unk17(This, 1, &D_80089E50);
        }
    }
    if (!(arg1[1] & 3)) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 0x1C;
    }
    This->vtable->Unk48(This, -0x64, 0);
}

void entity_ox_cart(entity_t *This, s32 *arg1) {
    u32 temp;
    s32 half;
    s32 rem;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = This->m_Unk31;
    half = ((s32)(temp + (temp >> 31))) >> 1;
    rem = arg1[1] % half;
    if (rem == 0) {
        arg1[7] = 0xA;
    } else if (rem == 3) {
        arg1[12] = 0xD;
    }
    This->vtable->Unk48(This, -0x1E, 1);
}

void entity_peacock(entity_t *This) {
    func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
}

void entity_tennyo(entity_t *This) {
    s32 count;

    func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    if (This->m_Triggered != 0) {
        if (This->m_Tick >= 0x41) {
            This->m_Tick = 0;
        }
        if (This->m_Tick >= 7) {
            This->vtable->Unk46(This, &D_80089D78);
            This->vtable->Unk48(This, 0xA, 0);
        } else {
            This->vtable->Unk46(This, &D_80089D9C);
        }
    } else {
        count = This->m_Tick;
        if (count == 0) {
            This->vtable->Unk46(This, &D_80089D48);
        } else if (count < 0x41) {
            This->vtable->Unk46(This, &D_80089D60);
        } else if (count < 0x47) {
            This->vtable->Unk46(This, &D_80089D78);
            This->vtable->Unk48(This, -0x1E, 0);
        } else {
            entity_vtable_t *vt;
            s32 nudge;

            vt = This->vtable;
            if (count < 0x100) {
                nudge = -count - 0x41;
            } else {
                nudge = 0xFF;
            }
            vt->Unk48(This, nudge, 0);
        }
    }
}

void entity_bird(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = arg1[1];
    if (temp == ((temp / 15) * 15)) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 7;
        arg1[8] = -2;
    }
    This->vtable->Unk17(This, 1, &D_80089DF0);
    This->vtable->Unk16(This, 0, &D_80089CA0);
    This->vtable->Unk48(This, -0x200, 0);
}

void entity_rocket(entity_t *This, s32 *arg1) {
    s32 count;
    s32 n;

    arg1[4] = 0;
    count = This->m_Tick;
    if (count < 0x64) {
        n = arg1[1];
        if (n == ((n / 3) * 3)) {
            arg1[7] = 0x16;
            arg1[8] = 1;
        }
        This->vtable->Unk50(This, -0x40, 0);
    } else if (count < 0x12C) {
        arg1[7] = 0xC;
        arg1[8] = -1;
        arg1[12] = 0xC;
        arg1[13] = -1;
        arg1[17] = 0xC;
        arg1[18] = -1;
        This->vtable->Unk50(This, -0x100, 0);
    } else {
        This->vtable->Unk16(This, 0, &D_80089C58);
        This->vtable->Unk50(This, -0x200, 0);
    }
}

void entity_horse(entity_t *This, s32 *arg1) {
    if ((arg1[1] % This->m_Unk31) == 0) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 0x1A;
    }
    This->vtable->Unk51(
        This, (This->m_Tick == 0x6E) ? -0x2D00 : -0x180, 0);
}

void entity_ufo(entity_t *This, s32 *arg1) {
    s32 temp;
    s32 temp_v1;

    temp = arg1[1];
    if (temp == ((temp / 70) * 70)) {
        arg1[4] = 0;
        arg1[7] = 0x1B;
    }
    This->vtable->Unk48(This, -0x80, 0);
    temp_v1 = This->m_Tick;
    if (temp_v1 < 0x64) {
        This->vtable->Unk50(This, 0x20, 0);
    } else if (temp_v1 >= 0x12D) {
        This->vtable->Unk50(This, -0x20, 0);
    }
}

void entity_siblings_flock(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void entity_rainbow(entity_t *This) {
    if (This->m_Tick == 0) {
        if (This->m_DreamSys->vtable->dream_sys_get_dream_color(This->m_DreamSys) == DREAM_COLOR_WHITE) {
            This->vtable->Unk17(This, 1, &D_80089E74);
            This->vtable->Unk50(This, -0x7800, 0);
        }
        This->m_State = rand() % 5;
    }
    if (This->m_State == 0) {
        This->vtable->Unk16(This, 0, &D_80089D18);
    }
}

void entity_boat_bird(entity_t *This) {
    s32 temp;
    s32 a1;

    if (This->m_State == 0) {
        if (This->m_DreamSys->vtable->dream_sys_get_dream_color(This->m_DreamSys) == DREAM_COLOR_BLUE) {
            This->m_State = 0xB;
        } else {
            This->m_State = 0xC;
        }
    }
    if (This->m_State == 0xC) {
        This->vtable->Unk17(This, 1, &D_80089DF0);
        This->vtable->Unk50(This, -0x1E, 0);
    } else {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        temp = This->m_State;
        if (temp == 0xB) {
            This->vtable->Unk48(This, -0x64, 0);
            temp = This->m_Tick;
            if ((u32)(temp - 0x55) < 0x1EU) {
                This->vtable->Unk50(This, 0x50, 0);
            } else if (temp == 0x78) {
                This->m_State = 0xD;
            }
        } else if (temp == 0xD) {
            This->vtable->Unk45(This, This->m_DreamSys->m_Transform + 0x18);
            This->vtable->Unk46(This, &D_80089DB4);
        }
    }
}

void entity_demon_king(entity_t *This, s32 *arg1) {
    func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 1);
    if ((arg1[1] % 10) < 3) {
        arg1[4] = 0;
        arg1[7] = 0xD;
        arg1[12] = 0xD;
        arg1[17] = 0xD;
    }
    if (This->m_Tick == This->m_Unk31) {
        This->vtable->Unk75(This);
        This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
    }
}

void entity_sailboat(entity_t *This) {
    This->vtable->Unk48(This, -30, 0);
}

void entity_turtle_giant(entity_t *This, s32 *arg1) {
    s32 temp;

    if (This->m_Triggered != 0) {
        This->vtable->Unk17(This, 1, &D_80089DCC);
    } else {
        temp = arg1[1];
        if (temp == ((temp / 30) * 30)) {
            arg1[4] = 0;
            arg1[7] = 3;
        }
    }
    This->vtable->Unk51(This, -0x1E, 0);
    if (This->m_Unk9 != 0) {
        This->vtable->Unk50(This, -0xC8, 0);
    }
}

void entity_shark(entity_t *This) {
    s32 count;

    count = This->m_Tick;
    if ((u32)(count - 0x190) < 0xA) {
        This->vtable->Unk16(This, 0, &D_80089C64);
    } else if (((u32)(count - 0x2BC) < 0xA) || ((u32)(count - 0x33E) < 4)) {
        This->vtable->Unk16(This, 0, &D_80089C70);
    } else if (count >= 0x353) {
        This->vtable->entity_disable_link(This);
    }
    {
        entity_vtable_t *vt;
        s32 n;

        n = This->m_Tick;
        vt = This->vtable;
        vt->Unk48(This, n < 0x320 ? -0x3C : -0x200, 1);
    }
}

void entity_fish(entity_t *This) {
    s32 rem;
    s32 arg;
    s32 nudge;
    entity_vtable_t *vt;
    entity_vtable_t *vt2;
    entity_vtable_t *vt3;

    rem = This->m_Tick % 500;
    if ((vt = This->vtable, (This->m_Tick % 6) < 3)) {
        arg = -0x40;
    } else {
        arg = 0x40;
    }
    vt->Unk50(This, arg, 0);
    if ((vt2 = This->vtable, (This->m_Tick % 12) < 6)) {
        nudge = -0x40;
    } else {
        nudge = 0x40;
    }
    vt2->Unk49(This, nudge, 0);
    if ((vt3 = This->vtable, (This->m_Tick % 64) < 0x20)) {
        nudge = -0x80;
    } else {
        nudge = 0x80;
    }
    vt3->Unk48(This, nudge, 0);
    if (rem < 0x20) {
        This->vtable->Unk46(This, &D_80089D78);
    } else if (rem < 0x40) {
        This->vtable->Unk46(This, &D_80089D60);
    }
}

void entity_mirage(entity_t *This) {
    if (This->m_State == 0) {
        This->vtable->Unk17(This, 1, (rand() & 1) ? &D_80089DF0 : &D_80089E38);
        This->m_State = 0xB;
    }
    func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    if (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0x7000) {
        This->vtable->Unk48(This, 0x100, 0);
    }
}

void entity_balloon(entity_t *This) {
    This->vtable->Unk50(This, -90, 0);
}

void entity_opera_singer(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = arg1[1];
    if (temp == ((temp / 120) * 120)) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 1;
    }
}

void entity_mushroom(entity_t *This, s32 *arg1) {
    s32 roll;

    if (This->m_Tick == 0) {
        roll = This->m_DreamSys->vtable->get_day_number(This->m_DreamSys, NULL) % 3;
        if (roll == 0) {
            if ((rand() % 3) == 0) {
                This->vtable->Unk17(This, 1, &D_80089E5C);
            }
        } else if (roll == 2) {
            This->vtable->Unk17(This, 1, &D_80089E5C);
        }
    }
    if ((arg1[1] % 22) == 0) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 2;
    }
    if ((rand() % 12) == 0) {
        This->vtable->Unk75(This);
    } else if ((rand() % 6) == 0) {
        This->vtable->Unk74(This);
    }
}

void entity_soldier(entity_t *This, s32 *arg1) {
    s32 *ptr;
    s32 temp;
    s32 temp_v1;

    ptr = NULL;
    temp = arg1[1];
    if (temp == ((temp / 7) * 7)) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 3;
        arg1[9] = 0x40;
        arg1[10] = 0x40;
    }
    temp_v1 = This->m_Tick;
    if (temp_v1 == 0xC8) {
        ptr = &D_80089C94;
    } else if (temp_v1 == 0x190) {
        ptr = &D_80089C7C;
    } else if (temp_v1 == 0x258) {
        ptr = &D_80089C88;
    } else if (temp_v1 == 0x320) {
        ptr = &D_80089C7C;
        This->m_Tick = -1;
    }
    if (ptr != NULL) {
        This->vtable->Unk16(This, 0, ptr);
    }
    This->vtable->Unk51(This, -0x1E, 0);
    if (This->m_Unk9 != 0) {
        This->vtable->Unk50(This, -0xC8, 0);
    }
}

void entity_locomotive_factory(entity_t *This, s32 *arg1) {
    s32 count;
    s32 kind;
    s32 roll;
    s16 *slot;

    count = This->m_Tick;
    if (count == 0) {
        This->m_State = (rand() % 5) + 0xA;
    }
    kind = This->m_State;
    if ((kind < 0xE) || (This->m_Tick < 0x140)) {
        entity_locomotive_common(This, arg1, 0xBB8, 0x1F4, -0x100);
    } else if ((kind == 0xE) && ((This->m_Tick & 3) == 0)) {
        roll = rand();
        slot = &D_80089EA2;
        *slot = (roll % 32) + 1;
        This->vtable->Unk17(This, 1, (s32 *)(slot - 5));
    }
}

void entity_marching_band(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = This->m_Tick;
    if (temp < 0x14) {
        This->vtable->Unk75(This);
        This->vtable->Unk48(This, -0x1E, 0);
    } else if (temp == 0x14) {
        This->vtable->Unk74(This);
        arg1[4] = 0;
        arg1[7] = 5;
    } else if ((temp % ((This->m_Unk31 * 3) + 0x14)) == 0) {
        This->vtable->Unk75(This);
        arg1[7] = -2;
    }
}

void entity_bear(entity_t *This, s32 *arg1) {
    s32 temp;

    entity_bear_rabbit_common(This);
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = This->m_Unk32;
    if ((temp == 0) || (temp == 0xF)) {
        arg1[7] = 0x12;
        arg1[12] = 0x12;
    }
    if (This->m_Tick >= 0x141) {
        This->vtable->Unk49(This, (rand() & 1) != 0 ? -0x3C : 0x3C, 0);
        This->vtable->Unk16(This, 0, (rand() & 3) != 0 ? &D_80089C70 : &D_80089C64);
    }
}

void entity_rabbit(entity_t *This, s32 *arg1) {
    s32 temp;

    entity_bear_rabbit_common(This);
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = This->m_Unk32;
    if ((temp == 7) || (temp == 0x16)) {
        arg1[7] = 3;
    }
    temp = This->m_Tick;
    if ((u32)(temp - 0x12C) < 0x14U) {
        This->vtable->Unk48(This, -0x3C, 0);
    } else if ((u32)(temp - 0x141) < 0x13U) {
        This->vtable->Unk16(This, 0, &D_80089C70);
    } else if (temp >= 0x141) {
        ((void (*)(void *, s32, s32))This->vtable->Unk49)(
            This, (rand() & 1) ? 0x80 : -0x80, 1);
        This->vtable->Unk16(
            This, 0, (rand() & 3) ? &D_80089C70 : &D_80089C64);
    }
}

void entity_bear_rabbit_common(entity_t *This) {
    s32 r;

    if (This->m_Tick == 0) {
        r = rand() % 10;
        if (r >= 8) {
            This->vtable->Unk17(This, 1, &D_80089E8C);
        } else if (r >= 5) {
            This->m_State = 0xA;
        }
    }
    if ((This->m_State == 0xA) && (This->m_Tick >= 0xC9)) {
        This->vtable->Unk46(This, &D_80089DC0);
    }
}

void entity_prince_princess(void) {
}

void entity_human_face_flower(entity_t *This, s32 *arg1) {
    s32 rem;
    s32 r;

    if (This->m_Tick == 0) {
        rem = This->m_DreamSys->vtable->get_day_number(This->m_DreamSys, 0) % 3;
        if (rem == 0) {
            r = rand();
            if (r == ((r / 3) * 3)) {
                This->vtable->Unk17(This, 1, &D_80089E38);
            }
        } else if (rem == 1) {
            This->vtable->Unk17(This, 1, &D_80089E38);
        }
    }
    if (arg1[1] == 0) {
        arg1[4] = 0;
        arg1[7] = 0x12;
    }
    func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
}

/* Ferris wheel (entity id 0x2F).  Once the player triggers it (m_Unk60) it
 * runs a short state machine and Notifies 0xB then 0xC.  Its event-video id
 * (g_ENTITY_TABLE[0x2F].event_video_id == 2) is read back through
 * entity_get_event_video by dream_sys_instance_effects_on_journal, stored in
 * the dream_sys cinematic field at +0x168, and game_flow_play_special_day then
 * plays FILM\EVENT2.STR (low half -1 -> get_event_movie_path). */
void entity_ferris_wheel(entity_t *This) {
    s32 temp;

    if (This->m_Triggered != 0) {
        temp = This->m_State;
        if (temp == 0) {
            This->m_State = 0xC;
            This->m_Tick = 0;
        } else if (temp == 0xC) {
            if (This->m_Tick < 0x1E) {
                if (This->m_DreamSys->vtable->dream_sys_get_action_pressed(This->m_DreamSys) != 0) {
                    This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 0);
                    This->m_Tick = 0;
                    This->m_State = 0xB;
                }
            } else {
                This->vtable->Notify(This, ENTITY_NOTIFY_LINK_VIDEO);
                This->m_State = 0xA;
            }
        } else if (temp == 0xB) {
            if (This->m_Tick == 0x64) {
                This->vtable->Notify(This, ENTITY_NOTIFY_LINK_END);
            } else {
                This->m_DreamSys->vtable->Unk50(This->m_DreamSys, -0x64, 0);
            }
        }
    }
}

void entity_lips_giant(entity_t *This, s32 *out) {
    s32 angle;

    if (This->m_Unk32 == 0x26) {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        out[4] = This->vtable->entity_get_trigger_ratio(This);
        out[7] = 6;
    }
    angle = 0x1E;
    {
        entity_vtable_t *vt;

        vt = This->vtable;
        if ((This->m_Tick % 10) < 5) {
            angle = -0x1E;
        }
        vt->Unk50(This, angle, 0);
    }
    This->vtable->Unk48(This, -0x1E, 1);
}

void entity_locomotive_kyoto(entity_t *This, s32 *arg1) {
    s32 link;

    if (arg1[1] == 6) {
        arg1[4] = 0;
        arg1[7] = 4;
        arg1[12] = 4;
        arg1[17] = 4;
    }
    if (This->m_Triggered != 0) {
        if (This->m_State == 0) {
            This->m_State = 0xA;
            This->m_Tick = 0;
        } else if (This->m_State == 0xA) {
            if (This->m_Tick != 0xA) {
                if (This->m_DreamSys->vtable->dream_sys_get_action_pressed(This->m_DreamSys) != 0) {
                    dream_sys_t *sys;
                    dream_sys_vtable_t *vt;

                    sys = This->m_DreamSys;
                    vt = sys->vtable;
                    if (This->m_Unk2 != 0) {
                        link = This->m_Transform + 0x38;
                    } else {
                        link = 0;
                    }
                    vt->Unk45(This->m_DreamSys, link);
                    This->m_DreamSys->vtable->Unk16(This->m_DreamSys, 1, &D_80089C94);
                    This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 0);
                    This->m_Tick = 0;
                    This->m_State = 0xB;
                }
            } else {
                This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
            }
        } else if (This->m_State == 0xB) {
            dream_sys_t *sys;
            dream_sys_vtable_t *vt;

            link = 0;
            sys = This->m_DreamSys;
            vt = sys->vtable;
            if (This->m_Unk2 != 0) {
                link = This->m_Transform + 0x38;
            }
            vt->Unk45(*(dream_sys_t *volatile *)&This->m_DreamSys, link);
            if (This->m_Tick == 0x64) {
                This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
            }
        }
    }
    This->vtable->Unk48(This, -0x100, 0);
}

void entity_whale(entity_t *This, s32 *arg1) {
    s32 temp_a0;

    if (This->m_Tick < (This->m_Unk31 * 5)) {
        temp_a0 = This->m_Unk32;
        if ((temp_a0 == 0xF) || (temp_a0 == 0x46)) {
            arg1[4] = 0;
            arg1[7] = 7;
            arg1[12] = 7;
            arg1[17] = 7;
        }
    } else {
        This->vtable->entity_disable_link(This);
        This->m_State = 1;
    }
}

void entity_standing_penguin(entity_t *This, s32 *arg1) {
    s32 *ptr;
    s32 roll;
    s32 step;

    if (This->m_Tick == 0) {
        roll = rand();
        if ((roll % 5) == 0 && This->m_State == 0) {
            This->vtable->Unk17(This, 1, &D_80089E38);
            This->vtable->Unk50(This, 0x320, 0);
            This->m_State = 0xB;
        }
    }
    ptr = NULL;
    if ((arg1[1] % 5) == 0) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 8;
    }
    step = This->m_Tick;
    if (step == 0x5A) {
        ptr = &D_80089C94;
    } else if (step == 0xA0) {
        ptr = &D_80089C88;
    } else if (step == 0xDC && (rand() & 1) != 0) {
        ptr = &D_80089C7C;
    }
    if (ptr != NULL) {
        This->vtable->Unk16(This, 0, ptr);
    }
    This->vtable->Unk48(This, -0x50, 1);
}

void entity_sliding_penguin(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = This->m_Tick;
    if (temp < 0xBC) {
        if (temp == 0x54) {
            This->vtable->Unk16(This, 0, &D_80089C7C);
        }
        if (arg1[1] == ((arg1[1] / 20) * 20)) {
            arg1[7] = 9;
        }
    } else if (temp < 0xC8) {
        This->vtable->Unk16(This, 0, &D_80089C64);
    } else {
        This->vtable->entity_disable_link(This);
        arg1[12] = 0x1E;
        This->m_State = 1;
    }
    This->vtable->Unk51(This, -0x200, 0);
}

void entity_hopscotch_girl(entity_t *This, s32 *arg1) {
    s32 var_s0;
    s32 r;

    var_s0 = This->m_Unk32;
    if (This->m_Tick == 0) {
        r = rand();
        if (r == ((r / 3) * 3)) {
            This->vtable->Unk17(This, 1, &D_80089E50);
        }
    }
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (var_s0 >= 0x20) {
        var_s0 -= 0x20;
    }
    if ((var_s0 == 9) || (var_s0 == 0x11) || (var_s0 == 0x17)) {
        arg1[7] = 0x13;
        if (var_s0 == 0x17) {
            arg1[12] = 0x13;
        }
    }
}

void entity_corpse(entity_t *This) {
    if ( !This->m_Tick ) {
        This->vtable->Unk50(This, -200, 0);
    }
}

void entity_airplane(entity_t *This, s32 *arg1) {
    s32 step;
    s32 tick;

    if (This->m_Tick == 0) {
        This->m_State = rand() % 3;
        if (This->m_State == 0) {
            This->vtable->Unk75(This);
            This->vtable->Unk50(This, 0x1800, 0);
        }
    }
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (This->m_State != 0) {
        step = This->m_Unk32;
        if (step < 0x1E) {
            arg1[7] = 0xC;
            arg1[8] = -1;
            return;
        }
        if (step == 0x1E) {
            arg1[7] = -2;
            return;
        }
        if (step == 0x23) {
            arg1[17] = 0x16;
            arg1[18] = -2;
            return;
        }
        if (step == 0x30) {
            if (entity_check_proximity(This, This->m_Transform + 24, 0xF, 0xA) != 0) {
                if (entity_create_effect(This, NULL, NULL, EFFECT_COLOR_STEP_NORMAL, 0) != NULL) {
                    This->m_Effect->vtable->Unk52(This->m_Effect, This->m_Unk19, 4, 0);
                }
                if (rand() & 1) {
                    This->vtable->Notify(This, ENTITY_NOTIFY_LINK_VIDEO);
                }
            }
            return;
        }
        if (step == 0x3B) {
            This->vtable->entity_disable_link(This);
            This->m_State = 1;
        }
        return;
    }
    arg1[7] = 0xC;
    arg1[8] = -1;
    This->vtable->Unk48(This, -0x200, 0);
    tick = This->m_Tick;
    if ((u32)(tick - 0x80) < 0xC2) {
        This->vtable->Unk50(This, -0x80, 0);
        return;
    }
    if (tick == 0x142) {
        This->vtable->Unk74(This);
        This->m_State = 1;
    }
}

void entity_hanged_woman(entity_t *This, s32 *arg1) {
    s32 state;

    if (This->m_Tick == 0) {
        s32 pose;

        pose = 0xC;
        arg1[4] = 0;
        arg1[7] = pose;
        if (This->m_DreamSys->vtable->dream_sys_get_dream_color(This->m_DreamSys) == DREAM_COLOR_YELLOW) {
            This->m_State = 0xB;
        } else if ((rand() % 3) == 0) {
            This->m_State = pose;
        }
    }
    if ((arg1[1] % 100) == 0) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 0xC;
        arg1[8] = -1;
    }
    state = This->m_State;
    if (state == 0xB) {
        if (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0x400) {
            This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 0);
            This->m_State = 0xD;
            This->m_Tick = 0;
        }
    } else if (state == 0xC) {
        if (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0x400) {
            This->vtable->Unk75(This);
            This->m_State = 0xE;
            This->m_Tick = 0;
        }
    }
    state = This->m_State;
    if (state == 0xD) {
        s32 tick;

        tick = This->m_Tick;
        if (tick < 0x32) {
            This->m_DreamSys->vtable->Unk50(This->m_DreamSys, -0x14, 0);
        } else if (tick < 0x1F4) {
            dream_sys_t *dream;
            struct dream_sys_vtable *vt;
            s32 step;

            dream = This->m_DreamSys;
            vt = dream->vtable;
            step = 5;
            if ((tick % 40) < 0x14) {
                step = -5;
            }
            vt->Unk49(dream, step, 0);
        } else if (tick == 0x1F4) {
            This->vtable->Notify(This, ENTITY_NOTIFY_LINK_END);
        }
        state = This->m_State;
    }
    if (state == 0xE) {
        s32 tick;

        tick = This->m_Tick;
        if (tick < 0xA) {
            This->vtable->Unk50(This, 0xC8, 0);
        } else if (tick == 0xA) {
            entity_t *held;

            arg1[7] = 0x12;
            arg1[4] = 0;
            arg1[12] = 3;
            This->vtable->Unk16(This, 1, &D_80089D24);
            This->vtable->Unk49(This, 0x960, 0);
            This->vtable->Unk50(This, 0x5DC, 0);
            held = ((entity_t **)This->m_Unk27)[1];
            held->vtable->Unk23(held, 0);
            This->m_State = 1;
        }
    }
}

void entity_hanged_woman_paralysis(entity_t *This, s32 *arg1) {
    s32 tick;
    s32 nudge;

    if (This->m_State == 0) {
        if (entity_is_facing_target(This, 0x800) != 0) {
            This->m_State = 0xB;
            func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
            func_8001EACC(This->m_DreamSys, This, 1, 1, 0);
            This->vtable->entity_enable_link(This);
            This->vtable->entity_start_behaviour(This);
            This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 1);
            arg1[4] = 0;
            arg1[7] = 0xC;
            This->m_Tick = 0;
        }
        if (This->m_State == 0) {
            This->vtable->entity_disable_link(This);
            This->vtable->entity_stop_behaviour(This);
            goto func_80061778_near;
        }
    }
    if ((arg1[1] % 100) == 0) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 0xC;
        arg1[8] = -1;
    }
    tick = This->m_Tick;
    if (tick < 3) {
        This->vtable->Unk50(This, 0x96, 0);
    } else if (tick < 7) {
        entity_vtable_t *vt;

        vt = This->vtable;
        nudge = 0x32;
        if ((tick & 1) != 0) {
            nudge = -0x32;
        }
        vt->Unk50(This, nudge, 0);
    } else if (tick == 0x64) {
        if (rand() & 1) {
            This->m_State = 0xC;
            This->vtable->Unk75(This);
        }
    } else if (tick == 0xF0) {
        This->m_DreamSys->vtable->dream_sys_set_callbacks(This->m_DreamSys, 1, 1);
    }
    if (This->m_State == 0xC) {
        tick = This->m_Tick;
        if (tick < 0x82) {
            This->vtable->Unk50(This, 0xA, 0);
        } else if (tick < 0xA0) {
            This->vtable->Unk48(This, -0x1E, 0);
        } else if (tick >= 0x12D) {
            func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
            This->vtable->Unk48(This, -0x1E, 0);
        }
    }
func_80061778_near:
    if (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0x200) {
        This->vtable->entity_disable_link(This);
        This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
    }
}

void entity_starship(entity_t *This, s32 *arg1) {
    s32 r;
    s32 temp;

    if (This->m_Tick == 0) {
        r = rand();
        if (r == ((r / 10) * 10)) {
            This->m_State = 0xC;
        }
    }
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 0xC;
        arg1[8] = -1;
    }
    if (This->m_Tick == 0) {
        if (rand() & 1) {
            This->vtable->Unk50(This, 0x800, 0);
        }
    }
    This->vtable->Unk48(This, -0x80, 0);
    if ((This->m_State == 0xC) && (This->m_Tick == 0x12C)) {
        (*(void (**)(s32, s32, s32))(*(s32 *)This->m_Unk18 + 0x138))(This->m_Unk18, 1, 1);
    }
}

void entity_kicking_man(entity_t *This, s32 *Unk) {
    if (This->m_Unk32 == 30) {
        Unk[7] = 18;
        Unk[4] = 0;
        Unk[8] = -1;
    }
}

void entity_triangle_head(entity_t *This, s32 *arg1) {
    s32 tick;
    s32 choice;
    entity_t *link;

    if ((This->m_Unk32 % 30) == 0) {
        arg1[7] = 3;
        arg1[4] = 0;
        arg1[8] = -2;
    }
    if (This->m_Tick >= 0x65) {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    }
    This->vtable->Unk48(This, -5, 0);
    tick = This->m_Tick;
    if (tick == 0x12C) {
        if (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0x1000) {
            This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 0);
            goto func_80061C2C_state;
        }
        tick = This->m_Tick;
    }
    if (tick == 0x1F4) {
        This->m_DreamSys->vtable->dream_sys_set_callbacks(This->m_DreamSys, 1, 1);
    }
func_80061C2C_state:
    if (This->m_State == 0) {
        if (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0x400) {
            if (rand() & 1) {
                arg1[12] = 6;
                arg1[4] = 0;
                arg1[13] = -1;
                if (rand() & 1) {
                    link = (entity_t *)This->m_Unk18;
                    link->vtable->Unk77(link, -1, 0);
                }
                This->m_Tick = 0;
                This->m_State = 0xA;
            } else {
                This->m_State = 0xB;
            }
        }
    }
    if ((This->m_State == 0xA) && (This->m_Tick == 0x46)) {
        if (rand() & 1) {
            choice = 0xC;
        } else {
            choice = 0xB;
        }
        This->vtable->Notify(This, choice);
    }
}

void entity_ship(entity_t *This, s32 *arg1) {
    s32 rem;

    rem = arg1[1] % 300;
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (rem < 0x14) {
        arg1[7] = 5;
        arg1[8] = -2;
    } else if (rem == 0x16) {
        arg1[7] = -2;
    }
    This->vtable->Unk48(This, -0xA, 0);
}

void entity_maiko_palace(entity_t *This) {
    s32 r;

    if (This->m_Tick == 0) {
        r = rand();
        if (r == ((r / 3) * 3)) {
            This->vtable->Unk17(This, 1, &D_80089DD8);
            This->vtable->Unk50(This, -0x12C, 0);
            This->vtable->Unk16(This, 1, &D_80089C88);
            This->m_State = 0xB;
        }
    }
    if (This->m_State == 0xB) {
        if (This->m_Tick == 0x7D0) {
            This->vtable->Unk16(This, 0, &D_80089C94);
        }
        This->vtable->Unk48(This, -0x14, 0);
    }
}

void entity_acrobats(entity_t *This, s32 *Unk) {
    Unk[4] = This->vtable->entity_get_trigger_ratio(This);
    if (Unk[1] == ((Unk[1] / 30) * 30)) {
        Unk[7] = 0xD;
    }
}

void entity_light(entity_t *This) {
    s32 r;

    if (This->m_Tick == 0) {
        r = rand();
        if (r == ((r / 3) * 3)) {
            This->m_State = 0xB;
        }
    }
    if (This->m_State == 0xB) {
        if (This->m_Tick == 0x1F6) {
            This->vtable->Unk50(This, 0x800, 0);
            func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        }
        if (This->m_Tick >= 0x1F5) {
            This->vtable->Unk48(This, -0x200, 0);
        }
    }
}

void entity_dog(entity_t *This, s32 *arg1) {
    s32 nudge;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (arg1[1] == 0) {
        if (rand() & 1) {
            nudge = -0x176;
        } else {
            nudge = -0xC0;
        }
        *(s16 *)&This->m_Unk17 = nudge;
    }
    if (This->m_State == 0) {
        if ((arg1[1] % 10) == 0) {
            arg1[7] = 0x1C;
        }
        if ((arg1[1] % 20) == 0) {
            arg1[12] = 0x17;
            arg1[13] = -1;
            arg1[17] = 0x17;
            arg1[18] = -1;
        } else if ((arg1[1] % 20) == 0xE) {
            arg1[12] = -2;
            arg1[17] = -2;
        }
        if ((This->m_Tick & 1) == 0) {
            if (This->m_DreamSys->vtable->dream_sys_get_action_pressed(This->m_DreamSys) != 0) {
                This->m_Tick = -1;
                This->m_State = 0xA;
                arg1[7] = 0x12;
            }
        }
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        This->vtable->Unk48(This, *(s16 *)&This->m_Unk17, 1);
        return;
    }
    if (This->m_State == 0xA) {
        if (This->m_Tick < 8) {
            This->vtable->Unk16(This, 0, &D_80089CC4);
            This->vtable->Unk46(This, &D_80089D6C);
            return;
        }
        arg1[7] = 0x12;
        arg1[12] = 3;
        This->vtable->entity_stop_behaviour(This);
        This->m_State = ((u32)rand() % 2) == 0;
    }
}

void entity_gears(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (This->m_Unk32 == (This->m_Unk31 - 1)) {
        arg1[7] = 0x19;
        arg1[8] = -2;
    }
    if (!(arg1[1] & 3)) {
        arg1[12] = 0x15;
        arg1[13] = -1;
    }
    temp = arg1[1];
    if (temp == ((temp / 200) * 200)) {
        arg1[17] = 0xD;
        arg1[18] = 1;
    }
}

void entity_ring(entity_t *This) {
    s32 a1;
    s32 unk16;
    entity_vtable_t *vt;

    if ((This->m_Tick == 0) && (rand() & 1)) {
        This->m_State = 0xB;
    }
    if (This->m_Tick == 0x12C) {
        This->vtable->Unk16(This, 0, &D_80089C7C);
    }
    if (This->m_Tick < 0x258) {
        unk16 = This->m_State;
        vt = This->vtable;
        a1 = 0x100;
        if (unk16 == 0) {
            a1 = -0x100;
        }
        vt->Unk48(This, a1, 0);
    }
}

void entity_hoop_girl(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (arg1[1] == 0) {
        arg1[7] = 0;
        temp = rand() % 3;
        This->vtable->Unk49(This, temp * 0xC800, 0, temp);
    }
    if (This->m_Tick >= 0x961) {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    }
    This->vtable->Unk48(This, -0x1E, 0);
}

void entity_small_room(entity_t *This, s32 *arg1) {
    arg1[4] = 0;
    if (arg1[1] == 0) {
        This->m_DreamSys->vtable->Unk16(This->m_DreamSys, 1, &D_80089C88);
        This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 1);
        arg1[7] = 0x19;
        arg1[12] = 0x19;
        arg1[17] = 0x19;
    } else if (arg1[1] == 0x14) {
        arg1[12] = 0xD;
    }
    if (This->m_Tick == (This->m_Unk31 - 1)) {
        This->vtable->entity_disable_link(This);
    }
}

void entity_clouds_wind(entity_t *This) {
    u32 temp;
    s32 half;
    s32 unk62;

    if (This->m_Tick == 0) {
        (*(void (**)(void *, void **))(*(s32 *)This->m_DreamSys->m_ViewTransform + 0x64))(
            (void *)This->m_DreamSys->m_ViewTransform, (void **)&D_8008AC1C);
        This->m_State = rand() % 3;
        if (*(s32 *)((char *)This->m_DreamSys->m_Transform + 0x20) < 0x262) {
            This->m_State = 0;
        }
    }
    if (This->m_State != 0) {
        temp = This->m_Unk31;
        half = ((s32)(temp + (temp >> 31))) >> 1;
        if (half < This->m_Tick) {
            This->m_DreamSys->vtable->Unk48(This->m_DreamSys, 0x80, 0);
        }
        if (This->m_Tick == (This->m_Unk31 - 0x1E)) {
            This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
        }
    } else {
        unk62 = This->m_Tick;
        if ((u32)(unk62 - 0x14) < 0x64U) {
            This->m_DreamSys->vtable->Unk48(This->m_DreamSys, -((unk62 - 0x13) << 5), 1);
            if (This->m_Tick == 0x55) {
                This->m_DreamSys->vtable->dream_sys_set_callbacks(This->m_DreamSys, 1, 1);
            }
        }
    }
}

void entity_window(entity_t *This, s32 *arg1) {
    if (arg1[1] == 0) {
        arg1[4] = 0;
        arg1[7] = 0x19;
        arg1[12] = 0x19;
        arg1[17] = 0x19;
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    }
    if (This->m_Tick == This->m_Unk31) {
        This->vtable->Unk75(This);
        This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
    }
}

void entity_flower(entity_t *This) {
    if (This->m_Triggered != 0) {
        This->vtable->Unk74(This);
        if (This->m_Unk32 == (This->m_Unk31 - 1)) {
            This->vtable->Unk75(This);
            This->vtable->Unk17(This, 0, &D_80089DFC);
        }
    } else {
        This->vtable->Unk75(This);
        This->vtable->Unk16(This, 0, &D_80089C64);
    }
}

void entity_bear_apartment(entity_t *This, s32 *arg1) {
    s32 tick;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if ((arg1[1] % 5) == 0) {
        arg1[7] = 0x11;
        arg1[8] = -2;
    }
    if (This->m_Unk30 == 0) {
        if (This->m_Tick == This->m_Unk31) {
            This->vtable->Unk73(This, 1);
            if (rand() & 1) {
                This->m_State = 0xB;
            }
        }
        return;
    }
    if (This->m_State == 0) {
        tick = This->m_Tick;
        if ((tick == 0x3C) || (tick == 0xD4) || (tick == 0x122) || (tick == 0x140)) {
            This->vtable->Unk16(This, 0, &D_80089C88);
            tick = This->m_Tick;
        }
        if (tick == 0x18E) {
            This->vtable->Unk16(This, 0, &D_80089C94);
        }
        This->vtable->Unk51(This, -0x32, 0);
        return;
    }
    tick = This->m_Tick;
    if ((tick == 0x3C) || (tick == 0x8C)) {
        This->vtable->Unk16(This, 0, &D_80089C88);
    }
    if (This->m_Tick < 0xAE) {
        This->vtable->Unk51(This, -0x32, 0);
    }
    if (This->m_Tick == 0xAE) {
        This->vtable->entity_stop_behaviour(This);
        This->m_State = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/entity", entity_paper_sumo);

/*
Best typed attempt; kept commented out pending a matching source promotion.

extern s32 D_80089D0C;
s32 D_8008ACCC;

void entity_paper_sumo(entity_t *This, s32 *arg1) {
    s32 *var_a2_2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_s1;
    s32 temp_v0;
    s32 var_s1;
    u32 temp_v1;
    u32 var_a2;
    s32 var_a1;

    if (arg1[1] == 0) {
        D_8008ACCC = 0;
        temp_s1 = rand() % 3;
        if (temp_s1 == 1) {
            This->m_State = 0xB;
        }
        if (temp_s1 == 2) {
            This->m_State = 0xC;
        }
    }
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if ((This->m_Unk35 != 0) && !(arg1[1] & 3)) {
        arg1[7] = 0x1C;
    }
    temp_v1 = This->m_Unk31;
    temp_a1 = This->m_Tick;
    var_a2 = temp_v1;
    if (temp_a1 == (temp_v1 - 1)) {
        This->m_Tick = -1;
    } else {
        temp_a0 = (s32) (temp_v1 + (temp_v1 >> 0x1F)) >> 1;
        if ((s32) temp_v1 < 0) {
            var_a2 = temp_v1 + 3;
        }
        temp_a2 = (s32) var_a2 >> 2;
        if (temp_a1 < (temp_a0 + temp_a2)) {
            if (temp_a1 < temp_a0) {
                if (temp_a1 < temp_a2) {
                    goto end_movement;
                }
                This->vtable->Unk75(This);
                var_a1 = -0x6E;
                goto call_movement;
            }
            if (temp_a1 == temp_a0) {
                arg1[7] = 0x10;
            }
            var_a1 = 0x6E;
            goto call_movement;
        } else {
            This->vtable->Unk74(This);
        }
    }

call_movement:
    This->vtable->Unk48(This, var_a1, 0);

end_movement:
    if ((This->m_State == 0xB) && (arg1[1] == 0x1FE)) {
        This->vtable->Unk50(This, -0x17C, 0);
        This->vtable->Unk16(This, 0, &D_80089D0C);
        This->vtable->entity_stop_behaviour(This);
        This->m_State = 1;
        D_8008ACCC = 1;
    } else if (This->m_State >= 0xC) {
        temp_a0_2 = arg1[1];
        if ((temp_a0_2 >= 0x14A) && (((temp_a0_2 / 60) * 0x3C) == (temp_a0_2 - 0x1E))) {
            var_s1 = 0;
            if (rand() & 1) {
                var_a2_2 = &D_80089E50;
                temp_v0 = This->m_State;
                This->m_State = 0xD;
                var_s1 = -(temp_v0 == 0xC) & 0x190;
            } else {
                var_a2_2 = &D_80089E14;
                if (This->m_State == 0xD) {
                    var_s1 = -0x190;
                }
                This->m_State = 0xC;
            }
            This->vtable->Unk17(This, 1, var_a2_2);
            This->vtable->Unk50(This, var_s1, 0);
        }
    }
    if ((arg1[1] == 0x208) && (D_8008ACCC != 0)) {
        This->vtable->entity_stop_behaviour(This);
        This->m_State = 1;
    }
}
*/

void entity_orrery(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[7] = 0x19;
        arg1[8] = 2;
    }
    This->vtable->Unk16(This, 0, &D_80089CA0);
    if ((This->m_State == 0) && (This->m_Triggered != 0)) {
        This->vtable->Notify(This, ENTITY_NOTIFY_LINK_VIDEO);
        This->m_State = 0xB;
    }
}

void entity_face(entity_t *This, s32 *arg1) {
    if (This->m_Tick < This->m_Unk31) {
        if (This->m_Unk32 != 0) {
            if (This->m_Unk32 == 0x14) {
                arg1[4] = 0;
                arg1[7] = 0x10;
            }
        }
    } else {
        This->vtable->Unk75(This);
        This->vtable->Unk46(This, &D_80089D54);
    }
    func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/entity", entity_lion);

void entity_dress_woman(entity_t *This, s32 *arg1) {
    s32 state;

    if ((This->m_State == 0) && (This->m_Tick == 0)) {
        if ((rand() % 3) != 0) {
            if (rand() & 1) {
                state = 0xB;
            } else {
                state = 0xC;
            }
            This->m_State = state;
        } else {
            This->vtable->entity_stop_behaviour(This);
            This->vtable->Unk48(This, -0x5000, 0);
            rand();
        }
    }
    if (This->m_State == 0xC) {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        if (This->m_Tick == 0x14) {
            arg1[7] = 0x12;
            arg1[4] = 0;
            arg1[12] = 3;
            This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 1);
        }
        if (This->m_Tick >= 0x15) {
            This->vtable->Unk48(This, -0x28, 0);
        }
        if (This->m_Tick == 0x28) {
            This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
        }
    } else if (This->m_State == 0xB) {
        This->vtable->Unk75(This);
        if (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0x200) {
            if ((rand() % 3) != 0) {
                This->vtable->entity_disable_link(This);
            } else {
                This->vtable->entity_stop_behaviour(This);
            }
        }
    }
}

void entity_can(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = This->m_Unk32;
    if (temp == ((temp / 15) * 15)) {
        arg1[7] = 0xC;
        arg1[4] = 0;
        arg1[8] = 2;
    }
    if (This->m_Tick == This->m_Unk31) {
        arg1[7] = -2;
        This->vtable->entity_stop_behaviour(This);
        This->m_State = 1;
    }
}

void entity_car_water(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = This->m_Unk32;
    if (temp < 0x28) {
        arg1[7] = 0xC;
        arg1[8] = -2;
        arg1[17] = 5;
        arg1[18] = -1;
    } else if (temp == 0x28) {
        arg1[7] = -2;
        arg1[17] = -2;
    } else if (temp == 0x2D) {
        arg1[12] = 0x12;
        arg1[13] = 1;
    } else if (temp == 0x40) {
        arg1[7] = 7;
    } else if (temp == 0x59) {
        This->vtable->entity_stop_behaviour(This);
        This->m_State = 1;
    }
}

void entity_gunman(entity_t *This, entity_t *arg1) {
    s32 tick;

    if (This->m_State == 0) {
        if (This->m_Unk32 == 5) {
            entity_set_aim_pose(arg1);
        }
        if (This->m_Tick == This->m_Unk31) {
            This->vtable->Unk75(This);
            This->m_State = 0xA;
            This->m_Tick = -1;
        }
        return;
    }
    if (This->m_State == 0xA) {
        if (This->m_Tick < 0xA) {
            This->vtable->Unk16(This, 0, &D_80089C64);
            if (This->m_DreamSys->vtable->dream_sys_get_action_pressed(This->m_DreamSys) == 0) {
                return;
            }
            entity_set_aim_pose(arg1);
            This->m_State = 0xC;
            This->m_Tick = -1;
            return;
        }
        This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 1);
        This->m_State = 0xB;
        This->m_Tick = -1;
        return;
    }
    if (This->m_State == 0xB) {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        if (This->m_Tick < 0x1E) {
            This->vtable->Unk48(This, -0xA, 0);
            return;
        }
        entity_set_aim_pose(arg1);
        if (entity_create_effect(This, NULL, NULL, EFFECT_COLOR_STEP_FAST, 0) != NULL) {
            This->m_Effect->vtable->Unk52(This->m_Effect, This->m_Unk19, 7, 0);
        }
        This->m_State = 0xD;
        This->m_Tick = -1;
        return;
    }
    if (This->m_State == 0xD) {
        tick = This->m_Tick;
        if (tick < 0x5A) {
            if (tick == 0x1E) {
                if (entity_create_effect(This, NULL, NULL, EFFECT_COLOR_STEP_NORMAL, 0) != NULL) {
                    This->m_Effect->vtable->Unk53(This->m_Effect, This->m_Unk19, 0, 0);
                }
            }
            This->m_DreamSys->vtable->Unk16(This->m_DreamSys, 0, &D_80089CD0);
            return;
        }
        entity_set_fall_pose(arg1);
        This->m_DreamSys->vtable->Unk16(This->m_DreamSys, 1, &D_80089C7C);
        This->vtable->Notify(This, (rand() % 5) != 0 ? 0xA : 0xC);
        This->m_State = 0xE;
        return;
    }
    if (This->m_State == 0xC) {
        if (This->m_Tick < 0xA) {
            This->vtable->Unk16(This, 0, &D_80089CDC);
            return;
        }
        entity_set_fall_pose(arg1);
        This->vtable->entity_stop_behaviour(This);
        This->m_State = 1;
    }
}

void entity_gunman_victim(entity_t *This, s32 *arg1) {
    if (This->m_Tick < 0xA) {
        This->vtable->Unk75(This);
    } else if (This->m_Tick == 0xA) {
        This->vtable->Unk74(This);
    }
    if (This->m_Unk32 == 0xA) {
        entity_set_fall_pose((entity_t *)arg1);
    }
    if (This->m_Tick == (This->m_Unk31 + 0xA)) {
        This->vtable->entity_stop_behaviour(This);
        This->m_State = 1;
    }
}

void entity_set_aim_pose(entity_t *This) {
    This->m_Unk3 = 0;
    This->m_Unk6 = 7;
    This->m_Unk7 = -2;
    This->m_Unk11 = 7;
    This->m_Unk12 = -2;
    This->m_State = 7;
    This->m_Unk17 = -2;
}

void entity_set_fall_pose(entity_t *This) {
    This->m_Unk6 = 18;
    This->m_Unk3 = 0;
    This->m_Unk11 = 3;
    This->m_State = 3;
}

void entity_kemari_boy_west(entity_t *This, s32 *arg1) {
    s32 temp_v0;

    temp_v0 = This->vtable->entity_get_trigger_ratio(This);
    arg1[4] = temp_v0;
    if (arg1[1] == 0) {
        arg1[7] = 0x12;
    }
    if (arg1[1] >= (This->m_Unk31 - 1)) {
        arg1[1] = -1;
    }
}

void entity_kemari_boy_east(entity_t *This, s32 *arg1) {
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (arg1[1] == (This->m_Unk31 / 2)) {
        arg1[7] = 0x12;
    }
    if (arg1[1] >= (This->m_Unk31 - 1)) {
        arg1[1] = -1;
    }
}

void entity_trash_can(entity_t *This, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = This->m_Tick;
    if (temp_v1 == 0x14) {
        arg1[7] = 0x12;
        arg1[4] = 0;
        arg1[12] = 3;
        return;
    }
    if (temp_v1 == This->m_Unk31) {
        This->vtable->entity_stop_behaviour(This);
        This->m_State = 1;
        if (rand() & 1) {
            This->vtable->Notify(This, ENTITY_NOTIFY_LINK_VIDEO);
        }
    }
}

void entity_television(entity_t *This, s32 *arg1) {
    s32 v;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    if (arg1[1] == 0) {
        if (rand() & 1) {
            v = 2;
        } else {
            v = 1;
        }
        arg1[7] = v;
        arg1[8] = 2;
    }
}

void entity_big_face_man_hidden(entity_t *This, s32 *arg1) {
    effect_t *child;

    if (This->m_Tick == 0) {
        if (entity_create_effect(This, NULL, NULL, EFFECT_COLOR_STEP_SLOW, 0) != NULL) {
            if (rand() & 1) {
                This->vtable->Unk46(This, &D_80089D90);
            }
            child = This->m_Effect;
            child->vtable->Unk52(child, This->m_Unk19, 0, 0);
        }
    } else if (This->m_Unk32 == 0) {
        do {
            This->m_Unk33 = This->vtable->Unk76(This, This->m_Unk33, 0);
            This->m_Unk32 += 1;
        } while (This->m_Unk32 < 0x18);
    }
    if (This->m_Unk32 >= 0x19) {
        This->vtable->Unk48(This, -0x14, 0);
        This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 1);
    }
    if (This->m_Tick == 0x32) {
        This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
    } else if (This->m_Tick == 0xC) {
        arg1[4] = 0;
        arg1[7] = 0x15;
    }
    This->vtable->Unk17(This, 1, &D_80089DE4);
}

void entity_big_face_man(entity_t *This, s32 *arg1) {
    if (This->m_Unk30 == 0) {
        if (This->m_Triggered != 0) {
            func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
            This->vtable->Unk73(This, 1);
            This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 1);
        } else if (This->m_Unk32 == 0) {
            do {
                This->m_Unk33 = This->vtable->Unk76(This, This->m_Unk33, 0);
                This->m_Unk32++;
            } while (This->m_Unk32 < 0x18);
        }
    } else if (This->m_Unk32 == 0) {
        arg1[4] = 0;
        arg1[7] = 0x16;
    } else if (This->m_Unk32 == (This->m_Unk31 - 1)) {
        arg1[4] = 0;
        arg1[12] = 0x12;
        This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
    }
    This->vtable->Unk17(This, 1, &D_80089DE4);
}

void entity_yokai(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[7] = 3;
    }
    if (This->m_Tick == This->m_Unk31) {
        This->vtable->Unk73(This, 1);
    }
    if (This->m_Unk30 == 1) {
        This->vtable->Unk48(This, -0x80, 1);
    }
}

void entity_tengu(entity_t *This, s32 *arg1) {
    s32 temp;
    s32 r;

    if (This->m_Tick == 0) {
        if (This->m_DreamSys->vtable->dream_sys_get_dream_color(This->m_DreamSys) != DREAM_COLOR_WHITE) {
            This->m_State = 0xB;
        }
    }
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[7] = 0xE;
    }
    if (This->m_Tick == This->m_Unk31) {
        This->vtable->Unk73(This, 1);
        if ((This->m_State != 0) && !(rand() & 1)) {
            This->vtable->Unk17(This, 1, &D_80089E38);
            This->vtable->Unk50(This, 0x800, 0);
        }
        r = rand();
        if (r == ((r / 3) * 3)) {
            This->vtable->Unk16(This, 0, &D_80089C7C);
        }
    }
    if (This->m_Unk30 != 0) {
        This->vtable->Unk48(This, -0x80, 1);
    }
}

void entity_fetus_walk(entity_t *This) {
    if (This->m_Tick == 0) {
        This->vtable->Unk73(This, 3);
    } else if (This->m_Tick == This->m_Unk31) {
        This->vtable->Unk73(This, 1);
    }
    if (This->m_Unk30 == 1) {
        This->vtable->Unk48(This, -0x80, 0);
    }
}

void entity_fetus_jump(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = This->m_Tick;
    if (temp == 0) {
        This->vtable->Unk73(This, rand() % 4);
        return;
    }
    if ((temp % This->m_Unk31) == 0) {
        This->vtable->Unk73(This, rand() % 4);
        arg1[4] = This->vtable->entity_get_trigger_ratio(This);
        arg1[7] = 0x16;
        arg1[8] = 2;
        arg1[9] = 0x40;
        arg1[10] = 0x20;
    }
}

void entity_gray_man(entity_t *This) {
    if (This->m_Triggered != 0) {
        if (entity_create_effect(This, NULL, NULL, EFFECT_COLOR_STEP_NORMAL, 0) != NULL) {
            This->m_Effect->vtable->Unk52(
                This->m_Effect, This->m_Unk19, 7, 0);
            This->vtable->entity_disable_link(This);
            This->m_DreamSys->vtable->dream_sys_reset_flashback_list(This->m_DreamSys);
        }
    }
    This->vtable->Unk48(This, -0x1E, 1);
}

void entity_winged_minotaur(entity_t *This, s32 *arg1) {
    s32 *ptr;
    u32 utemp;
    s32 half;
    s32 unk62;

    if (This->m_Tick == 0) {
        This->vtable->Unk50(This, -0x200, 0);
    }
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    utemp = This->m_Unk31;
    half = ((s32)(utemp + (utemp >> 31))) >> 1;
    if (This->m_Unk32 == half) {
        arg1[7] = 7;
        arg1[8] = -2;
        arg1[12] = 3;
        arg1[13] = -2;
    }
    if (This->m_Tick >= 0x33) {
        This->vtable->Unk16(This, 0, &D_80089CAC);
    }
    if (This->m_Tick >= 0x30D) {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        unk62 = This->m_Tick;
        if (unk62 >= 0x790) {
            ptr = &D_80089E14;
        } else if (unk62 >= 0x78B) {
            ptr = &D_80089DE4;
        } else if (unk62 >= 0x786) {
            ptr = &D_80089DD8;
        } else if (unk62 >= 0x781) {
            ptr = &D_80089DCC;
        } else {
            ptr = &D_80089E20;
        }
        This->vtable->Unk17(This, 1, ptr);
        if (This->m_Tick < 0x7D0) {
            This->vtable->Unk48(This, -0x40, 0);
        } else {
            This->m_State = 1;
        }
    } else {
        This->vtable->Unk48(This, -0x100, 0);
    }
    if ((This->m_Triggered != 0) && (This->m_State == 0)) {
        This->m_State = 0xC;
        This->m_DreamSys->vtable->dream_sys_clear_callbacks(This->m_DreamSys, 1);
        This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
    }
    if (This->m_State == 0xC) {
        This->m_DreamSys->vtable->Unk48(This->m_DreamSys, 0x100, 0);
    }
}

void entity_airship(entity_t *This) {
    s32 count;
    entity_t *child;

    count = This->m_Tick;
    if (count != 0x2BC) {
        goto check16;
    }
    if ((rand() % 3) != 0) {
        goto check16;
    }
    This->m_State = 0xB;
check16:
    if (This->m_State != 0xB) {
        goto other;
    }
    if (This->m_Tick < 0x3FC) {
        This->vtable->Unk16(This, 0, &D_80089CB8);
        This->vtable->Unk50(This, 0x1E, 0);
    }
    if (This->m_Tick != 0x3A2) {
        goto tail;
    }
    This->vtable->Notify(This, ENTITY_NOTIFY_LINK);
    goto tail;
other:
    count = This->m_Tick;
    if (count == 0x64 || count == 0x320) {
        if ((rand() % 5) == 0) {
            child = (entity_t *)This->m_Unk18;
            child->vtable->Unk77(child, 4, 0);
        }
    }
tail:
    This->vtable->Unk48(This, -0x1E, 0);
}

void entity_maiko_small(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DCC);
    if ((u32)(This->m_Tick - 0xC9) < 0x63U) {
        This->vtable->Unk50(This, -0x20, 0);
    }
}

void entity_bed_bone_dead(entity_t *This) {
    This->vtable->Unk23(This, (rand() % 20) == 0);
}

void entity_yokai_bartender(entity_t *This) {
    s32 count;

    if (This->m_Tick == 0) {
        if ((rand() & 1) == 0) {
            This->m_State = 0xB;
        }
    }
    if (This->m_State == 0xB) {
        if (This->m_Tick == 0) {
            This->vtable->Unk75(This);
        }
        This->vtable->Unk17(This, 1, &D_80089E2C);
    } else {
        if (This->m_Tick == 0) {
            This->vtable->Unk73(This, 1);
        }
        count = This->m_Tick;
        This->vtable->Unk49(This, (count % 20) < 10 ? 0x20 : -0x20, 0);
    }
}

void entity_hoop_girl_giant(entity_t *This) {
    entity_hoop_girl();
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void entity_elephant_small(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DD8);
    This->vtable->Unk48(This, -0xA, 0);
}

void entity_maiko_bridge(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E44);
    This->vtable->Unk75(This);
    if ((This->m_State == 0) && (This->vtable->entity_get_distance(This, This->m_DreamSys) < 0x800)) {
        This->m_State = 0xA;
        This->m_Tick = 0;
    }
    if (This->m_State == 0xA) {
        if (This->m_Tick < 0x2D) {
            This->vtable->Unk16(This, 0, &D_80089D00);
        }
        if (This->m_Tick >= 0x1F5) {
            This->m_State = 0;
        }
    }
}

void entity_locomotive_natural(entity_t *This, s32 *arg1) {
    s32 temp;

    if (This->m_Tick == 0) {
        if (This->m_DreamSys->vtable->dream_sys_get_dream_color(This->m_DreamSys) == DREAM_COLOR_PINK) {
            This->m_State = 0xB;
        }
    }
    if ((This->m_State != 0) && (This->m_Tick >= 0x870)) {
        temp = This->m_Tick;
        if ((u32)(temp - 0x870) < 0x191U) {
            if (temp == 0x870) {
                This->vtable->Unk75(This);
                arg1[7] = -2;
                arg1[12] = -2;
                arg1[17] = -2;
                return;
            }
            if ((u32)(temp - 0x9F6) < 0xAU) {
                arg1[7] = 5;
                arg1[8] = -2;
                return;
            }
            if (temp == 0xA00) {
                This->vtable->Unk74(This);
                arg1[1] = 1;
            }
        } else if (temp >= 0xA03) {
            if (temp >= 0xAF1) {
                This->vtable->Unk50(This, -0x20, 0);
            }
            entity_locomotive_common(This, arg1, 0x1E1, 0xFA0, -0x3C);
        }
    } else {
        entity_locomotive_common(This, arg1, 0x1E1, 0x884, -0x3C);
    }
}

void entity_locomotive_common(entity_t *This, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp;

    arg1[4] = 0;
    if (arg1[1] == 6) {
        arg1[7] = 4;
        arg1[12] = 4;
        arg1[17] = 4;
    }
    temp = This->m_Tick;
    if (((temp >= arg2) && (temp <= (arg2 + 0x5B))) ||
        ((temp >= (arg2 + 0x155)) && (temp <= (arg2 + 0x1B1))) ||
        ((temp >= (arg2 + 0x2BA)) && (temp <= (arg2 + 0x317)))) {
        This->vtable->Unk16(This, 0, &D_80089D18);
    }
    This->vtable->Unk48(This, arg4, 0);
    if (This->m_Tick == arg3) {
        This->vtable->entity_disable_link(This);
        This->m_State = 1;
    }
}

void entity_question_mark_penguin(entity_t *This, void *Unk) {
    entity_standing_penguin(This, Unk);
}

void entity_standing_penguin_flock(entity_t *This) {
    if ((rand() % 3) == 0) {
        return;
    }
    This->vtable->Unk16(This, 0, (rand() % 3) != 0 ? &D_80089C64 : &D_80089C70);
}

void entity_triangle_head_giant(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void entity_fish_giant(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void entity_turtle_small(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DCC);
}

void entity_car(entity_t *This) {
    s32 r;

    if (This->m_Tick == 0) {
        r = rand();
        if (r == ((r / 5) * 5)) {
            This->m_State = 0xB;
        }
    }
    This->vtable->Unk75(This);
    This->vtable->Unk48(This, 0x64, 0);
    if (This->m_Tick == 0x3E8) {
        This->vtable->entity_stop_behaviour(This);
        This->m_State = 1;
    }
    if ((This->m_State == 0xB) && (This->m_Tick >= 0x12D)) {
        This->m_DreamSys->vtable->set_move_from_pad(This->m_DreamSys, 0, 2);
        This->m_DreamSys->vtable->set_move_from_pad(This->m_DreamSys, 0, 7);
    }
}

void entity_maiko_plain(entity_t *This, s32 *arg1) {
    u32 temp;
    s32 half;

    if (((This->m_Tick == 0) && !(rand() & 3)) || (This->m_Tick == 0xE10)) {
        This->vtable->entity_disable_link(This);
        This->m_State = 1;
    }
    This->vtable->Unk17(This, 1, &D_80089E44);
    arg1[4] = This->vtable->entity_get_trigger_ratio(This);
    temp = This->m_Unk31;
    half = ((s32)(temp + (temp >> 31))) >> 1;
    if ((arg1[1] % half) == 0) {
        arg1[7] = 0xA;
        arg1[8] = 1;
    }
    This->vtable->Unk48(This, -0xA, 0);
}

void entity_lips_small(entity_t *This) {
    func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
    This->vtable->Unk17(This, 1, &D_80089E80);
    This->vtable->Unk48(This, -0x1E, 1);
}

void entity_paper_sumo_wait(entity_t *This) {
    u32 r;
    s32 rem;

    if (This->m_Tick == 0) {
        r = rand();
        rem = (s32)(r + (r >> 31)) >> 1;
        This->m_State = 0xA + (s32)(r - (rem << 1));
    }
    This->vtable->Unk75(This);
    if (This->m_Tick >= 0xC9) {
        func_8001EACC(This, This->m_DreamSys, 1, 0, 0);
        if (This->m_State == 0xA) {
            This->vtable->Unk51(This, -0x200, 0);
        }
    }
}

/* Defined by INCLUDE_ASM below; declared so g_ENTITY_TABLE can reference them. */
void entity_paper_sumo(entity_t *This, s32 *arg1);
void entity_lion(entity_t *This, s32 *arg1);

/* Entity vtable, animation/pose tables and the per-type property table.
 * These live at the bottom of the file because the vtable and table take the
 * address of the behaviour functions defined above; the linker places them at
 * their fixed addresses via the [.data, entity] subsegment in the splat config,
 * so file position does not affect the layout. */
extern void func_8001CEB4();
extern void func_8001D008();
extern void func_8001D204();
extern void func_8001D280();
extern void func_8001D33C();
extern void func_8001D374();
extern void func_8001D3A0();
extern void func_8001D3CC();
extern void func_8001D424();
extern void func_8001D450();
extern void func_8001D480();
extern void func_8001D4AC();
extern void func_8001D4DC();
extern void func_8001D600();
extern void func_8001D624();
extern void func_8001D6A4();
extern void func_8001D714();
extern void func_8001D950();
extern void func_8001DA28();
extern void func_8001DDF4();
extern void func_8001E4A4();
extern void func_800570B4();
extern void func_80057130();
extern void func_800571A8();
extern void func_800571F8();
extern void func_80057320();
extern void func_80057384();
extern void func_800573A8();
extern void func_80057444();
extern void func_8005748C();
extern void func_800574C4();
extern void func_800574FC();
extern void func_800575B0();
extern void func_800575E0();
extern void func_80057610();
extern void func_80057C6C();
extern void func_80057C74();
extern void func_80057C7C();
extern void func_80065790();
extern void func_80065A5C();
extern void func_80065AE0();
extern void func_80065BF4();
extern void func_80065BFC();
extern void func_80065C2C();
extern void func_80065D64();
extern void func_80065DBC();
extern void func_80065DEC();
extern void func_80065FD8();
extern void func_800660BC();
extern void func_8006613C();
extern void func_80066148();
extern void func_80066150();
extern void func_800661CC();
extern void func_800661D4();
extern void func_80066214();
extern void func_800662A8();
extern void func_800662B4();
extern void func_800662BC();
extern void func_80066340();
extern void func_80066748();
extern void func_800667B0();

entity_vtable_t g_ENTITY_VTABLE = {
    0x0001F234,
    base_class_destructor,
    (void *(*)(void *, s32, s32, s32))entity_construct,
    (void(*)(void *))entity_cleanup,
    (void(*)(base_class_t *, base_class_t *))func_800570B4,
    (void(*)(base_class_t *, base_class_t *))func_80057130,
    (void(*)(base_class_t *))func_800571A8,
    (void(*)(base_class_t *, void **, void **))base_class_iter_children,
    (void(*)(base_class_t *, base_class_t *))base_class_add_parent,
    (void(*)(base_class_t *, base_class_t *))base_class_remove_parent,
    (void(*)(base_class_t *))base_class_clear_parents,
    (void(*)(base_class_t *, void **, void **))base_class_iter_parents,
    (void(*)(base_class_t *, s32))base_class_notify,
    (void(*)(base_class_t *))base_class_nop,
    (void(*)(base_class_t *, base_class_t *, s32))func_80065790,
    0x00000000,
    (void(*)(void *))entity_init,
    (void(*)(void *, s32, s32 *))func_8001CEB4,
    (void(*)(void *, s32, s32 *))func_8001D008,
    (void(*)(void *, s32, s32, s32, s32))entity_start,
    (void(*)(void *))entity_stop,
    (void(*)(void *))func_8001D204,
    (void(*)(void *))func_8001D280,
    (void(*)(void *))func_8001D33C,
    (void(*)(void *, s32))func_80065A5C,
    (void(*)(void *))func_8001D374,
    (void(*)(void *))func_8001D3A0,
    (void(*)(void *))func_8001D3CC,
    (void(*)(void *, s32))func_80065AE0,
    (void(*)(void *))func_8001D424,
    (void(*)(void *))func_8001D450,
    (void(*)(void *))func_8001D480,
    (void(*)(void *))func_8001D4AC,
    (void(*)(void *))func_8001D4DC,
    (void(*)(void *))func_800571F8,
    (void(*)(void *))func_8001D600,
    (void(*)(void *))func_8001D624,
    (void(*)(void *))func_8001D6A4,
    (void(*)(void *))entity_update,
    (void(*)(void *))func_80057320,
    (void(*)(void *))func_8001D714,
    (void(*)(void *))func_8001D950,
    (void(*)(void *))func_8001DA28,
    (void(*)(void *))func_8001DDF4,
    0x00000000,
    (void(*)(void *))func_8001E4A4,
    (void(*)(void *, s32))func_80057384,
    (void(*)(void *, s32 *))func_800573A8,
    (void(*)(void *))func_80057444,
    (void(*)(void *, s32, s32))func_8005748C,
    (void(*)(void *, s32, s32, s32))func_800574C4,
    (void(*)(void *, s32, s32))func_800574FC,
    (void(*)(void *, s32, s32))func_800575B0,
    (void(*)(void *))func_800575E0,
    (void(*)(void *))func_80057610,
    (void(*)(void *))entity_notify_interaction,
    (void(*)(void *))entity_notify_interaction_done,
    (void(*)(void *))func_80057C6C,
    (void(*)(void *))func_80057C74,
    (void(*)(void *))func_80057C7C,
    (void(*)(void *))func_80065BF4,
    (void(*)(void *))func_80065BFC,
    (void(*)(void *))func_80065C2C,
    (void(*)(void *))func_80065D64,
    (void(*)(void *))func_80065DBC,
    (void(*)(void *))func_80065DEC,
    (void(*)(void *))func_80065FD8,
    (void(*)(void *, s32))func_800660BC,
    (void(*)(void *))func_8006613C,
    (void(*)(void *))func_80066148,
    (void(*)(void *))func_80066150,
    (void(*)(void *))entity_tick,
    (void(*)(void *))func_800661CC,
    (void(*)(void *))func_800661D4,
    (void(*)(void *, s32))func_80066214,
    (void(*)(void *))func_800662A8,
    (void(*)(void *))func_800662B4,
    (s32(*)(void *, s32, s32))func_800662BC,
    (void(*)(void *, s32, s32))func_80066340,
    (void(*)(void *))func_80066748,
    (void(*)(void *))func_800667B0,
    entity_get_distance,
    entity_get_trigger_ratio,
    entity_get_mood_effect,
    entity_get_unlock_effect,
    entity_get_link_stage,
    entity_get_event_video,
    entity_enable_link,
    entity_disable_link,
    entity_set_triggered,
    entity_start_behaviour,
    entity_stop_behaviour,
    entity_check_interaction,
    entity_check_interaction_range,
    entity_check_interaction_angle,
    entity_check_link_trigger,
    entity_check_link_proximity,
};

s32 D_80089C58[3] = { 0x00080001, 0x00010000, 0x00010000 };
s32 D_80089C64[3] = { 0x00010000, 0x00010009, 0x00010000 };
s32 D_80089C70[3] = { 0x00010000, 0x0001FFF7, 0x00010000 };
s32 D_80089C7C[3] = { 0x00010000, 0x000100B4, 0x00010000 };
s32 D_80089C88[3] = { 0x00010000, 0x0001005A, 0x00010000 };
s32 D_80089C94[3] = { 0x00010000, 0x0001FFA6, 0x00010000 };
s32 D_80089CA0[3] = { 0x00010000, 0x00010002, 0x00010000 };
s32 D_80089CAC[3] = { 0x00010000, 0x0003FFFF, 0x00010000 };
s32 D_80089CB8[3] = { 0x00010000, 0x0002FFFF, 0x00010000 };
s32 D_80089CC4[3] = { 0x00010000, 0x00010000, 0x00010009 };
s32 D_80089CD0[3] = { 0x00010000, 0x00010000, 0x00010001 };
s32 D_80089CDC[3] = { 0x00010000, 0x00010000, 0x0001FFF7 };
s32 D_80089CE8[3] = { 0x00010000, 0x0001FF88, 0x00010000 };
s32 D_80089CF4[3] = { 0x00010032, 0x0001FF88, 0x0001001E };
s32 D_80089D00[3] = { 0x00010000, 0x00010004, 0x00010000 };
s32 D_80089D0C[3] = { 0x0001005A, 0x00010000, 0x00010000 };
s32 D_80089D18[3] = { 0x00010000, 0x00010001, 0x00010000 };
s32 D_80089D24[6] = { 0x00010000, 0x00010000, 0x0001FFA6, 0x00010000, 0x0001010E, 0x00010000 };
s32 D_80089D3C[3] = { 0x00000000, 0x00000100, 0x00000000 };
s32 D_80089D48[3] = { 0x00000000, 0xFFFFF000, 0x00000000 };
s32 D_80089D54[3] = { 0x00000000, 0xFFFFFE00, 0x00000000 };
s32 D_80089D60[3] = { 0x00000000, 0x00000040, 0x00000000 };
s32 D_80089D6C[3] = { 0x00000000, 0x00000008, 0x00000000 };
s32 D_80089D78[6] = { 0x00000000, 0xFFFFFFC0, 0x00000000, 0x00000000, 0xFFFFFFE0, 0x00000000 };
s32 D_80089D90[3] = { 0x00000000, 0xFFFFFF00, 0x00000000 };
s32 D_80089D9C[3] = { 0xFFFFFFC0, 0x00000000, 0x00000000 };
s32 D_80089DA8[3] = { 0x00000000, 0x00000040, 0xFFFFFFC0 };
s32 D_80089DB4[3] = { 0x00000000, 0xFFFFFA24, 0x00000400 };
s32 D_80089DC0[3] = { 0x00000000, 0x00000000, 0xFFFFFF00 };
s32 D_80089DCC[3] = { 0x00040001, 0x00040001, 0x00040001 };
s32 D_80089DD8[3] = { 0x00020001, 0x00020001, 0x00020001 };
s32 D_80089DE4[3] = { 0x00050004, 0x00050006, 0x00050005 };
s32 D_80089DF0[3] = { 0x00010002, 0x00010002, 0x00010002 };
s32 D_80089DFC[3] = { 0x0040FFFF, 0x0040FFFF, 0x0040FFFF };
s32 D_80089E08[3] = { 0x00070008, 0x00070008, 0x00070008 };
s32 D_80089E14[3] = { 0x00010001, 0x00010001, 0x00010001 };
s32 D_80089E20[3] = { 0x00080001, 0x00080001, 0x00080001 };
s32 D_80089E2C[3] = { 0x00080001, 0x00010002, 0x00080001 };
s32 D_80089E38[3] = { 0x00010006, 0x00010006, 0x00010006 };
s32 D_80089E44[3] = { 0x00050002, 0x00050002, 0x00050002 };
s32 D_80089E50[3] = { 0x00010001, 0x00010002, 0x00010001 };
s32 D_80089E5C[6] = { 0x00010001, 0x00010004, 0x00010001, 0x00040001, 0x00010001, 0x00020001 };
s32 D_80089E74[3] = { 0x00010003, 0x00010003, 0x00010003 };
s32 D_80089E80[3] = { 0x00200001, 0x00200001, 0x00200001 };
u8 D_80089E8C[22] = { 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00 };
s16 D_80089EA2 = 0x0001;

entity_prop_t g_ENTITY_TABLE[130] = {
    { { 0, 2 }, 20, 0, 0, 0, 2, -13, 4, 1, 10, 0, (void (*)(entity_t *, void *))entity_astronaut },
    { { -2, 5 }, -1, 0, 0, 0, 1, -2, 0, -6, 10, 1, (void (*)(entity_t *, void *))entity_gargoyle },
    { { 0, 0 }, -100, 0, 0, 0, 1, -5, 1, 1, 0, 0, NULL },
    { { 0, -3 }, -100, 0, 0, 0, 1, -6, 1, 1, 0, 0, NULL },
    { { 0, -7 }, -100, 0, 0, 0, 1, -13, 1, 1, 0, 0, NULL },
    { { -4, 4 }, -50, 0, 0, 0, 1, -14, 1, -2, 10, -1, (void (*)(entity_t *, void *))entity_futon },
    { { 0, 0 }, 100, 0, 0, 0, 0, 0, 0, 3, 0, -1, NULL },
    { { -5, 0 }, 20, 3, -76, 5, 5, 0, 0, 3, 30, 5, (void (*)(entity_t *, void *))entity_gargoyle_pit },
    { { 3, 3 }, 100, 3, -76, 7, 7, 0, 0, 5, 0, 7, (void (*)(entity_t *, void *))entity_elephant },
    { { -3, -1 }, 20, 1, -76, 12, 6, -3, 3, 3, 30, 12, (void (*)(entity_t *, void *))entity_minotaur },
    { { -7, 3 }, 50, 0, -76, 0, 10, 0, 0, 3, 60, 0, (void (*)(entity_t *, void *))entity_giant_minotaur },
    { { 3, 0 }, 9, 0, -1, 0, 5, 8, 4, 3, 20, 0, (void (*)(entity_t *, void *))entity_maiko_giant },
    { { -3, -5 }, 5, 0, 0, 0, 3, 0, 0, 2, 0, 0, (void (*)(entity_t *, void *))entity_old_woman },
    { { -5, 5 }, 100, 0, 0, 0, 5, 0, 4, 3, 30, 5, (void (*)(entity_t *, void *))entity_bell_striker },
    { { 0, 1 }, -100, 0, 120, 0, 5, 0, 0, 3, 20, 5, (void (*)(entity_t *, void *))entity_boatman },
    { { -2, -1 }, -20, 0, 0, 0, 4, 0, 0, 3, 30, -5, (void (*)(entity_t *, void *))entity_drumstick },
    { { -3, 2 }, 50, 1, 24, 3, 3, 0, 0, 1, 30, 3, (void (*)(entity_t *, void *))entity_fox },
    { { 1, 0 }, 100, 0, 0, 0, 5, 0, 0, 3, 0, 0, (void (*)(entity_t *, void *))entity_halo },
    { { 0, 0 }, -100, 0, 0, 0, 2, 0, 0, 1, 0, 0, NULL },
    { { 2, 3 }, -50, 1, 30, 7, 5, -2, 2, 3, 30, 7, (void (*)(entity_t *, void *))entity_tea_doll },
    { { 0, -4 }, 8, 1, -76, 12, 5, -2, 1, 3, 30, 12, (void (*)(entity_t *, void *))entity_buddha },
    { { -1, -2 }, 20, 0, -1, 0, 6, -4, 4, 3, 30, 0, (void (*)(entity_t *, void *))entity_ox_cart },
    { { 1, 4 }, -20, 0, 0, 0, 2, -5, 2, 1, 0, 1, (void (*)(entity_t *, void *))entity_peacock },
    { { 5, 1 }, -20, 1, -1, 8, 1, 0, 0, 1, 0, 8, (void (*)(entity_t *, void *))entity_tennyo },
    { { 2, -7 }, 20, 0, 0, 0, 5, 0, 0, 3, 30, 0, (void (*)(entity_t *, void *))entity_bird },
    { { -5, -1 }, 50, 0, -76, 0, 3, 0, 0, 3, 30, 3, (void (*)(entity_t *, void *))entity_rocket },
    { { -3, 1 }, 7, 1, 60, 10, 7, 0, 0, 3, 30, 10, (void (*)(entity_t *, void *))entity_horse },
    { { 8, -1 }, -100, 1, 60, 8, 8, 0, 0, 5, 30, 8, (void (*)(entity_t *, void *))entity_ufo },
    { { 7, 1 }, 20, 0, 0, 0, -2, -11, 1, 1, 0, 0, NULL },
    { { -8, 1 }, 100, 0, 0, 0, 12, 0, 0, 5, 0, 0, (void (*)(entity_t *, void *))entity_rainbow },
    { { 0, -1 }, -50, 0, -76, 0, 5, 0, 0, 3, 0, 3, (void (*)(entity_t *, void *))entity_boat_bird },
    { { 2, -5 }, -100, 1, 120, 1, 1, -3, 0, 1, 30, 1, (void (*)(entity_t *, void *))entity_demon_king },
    { { 0, 4 }, 50, 1, 0, 15, 15, 0, 0, 5, 0, 15, (void (*)(entity_t *, void *))entity_sailboat },
    { { 2, 8 }, 8, 1, -76, 12, 2, -8, 1, 2, 30, 12, (void (*)(entity_t *, void *))entity_turtle_giant },
    { { -8, 4 }, -50, 0, 60, 3, 3, -14, 2, 1, 0, 3, (void (*)(entity_t *, void *))entity_shark },
    { { 6, 0 }, -20, 0, 0, 0, 2, 0, 0, 1, 0, 0, (void (*)(entity_t *, void *))entity_fish },
    { { 0, 7 }, 7, 1, 2, 17, 12, 0, 0, 8, 0, 17, (void (*)(entity_t *, void *))entity_mirage },
    { { -2, 6 }, 100, 1, 120, 6, 6, 0, 0, 5, 0, 6, (void (*)(entity_t *, void *))entity_balloon },
    { { -5, 2 }, -100, 1, 120, 10, 10, 0, 0, 3, 30, 10, (void (*)(entity_t *, void *))entity_opera_singer },
    { { -1, -1 }, 20, 1, 120, 20, 20, -5, 1, 3, 20, 20, (void (*)(entity_t *, void *))entity_mushroom },
    { { 3, 3 }, -100, 0, -76, 0, 4, -14, 2, 3, 30, 0, (void (*)(entity_t *, void *))entity_soldier },
    { { -9, 5 }, -50, 1, 0, 15, 15, -10, 8, 3, 50, 15, (void (*)(entity_t *, void *))entity_locomotive_factory },
    { { 2, 1 }, 1, 0, 120, 0, 4, 0, 0, 4, 30, 4, (void (*)(entity_t *, void *))entity_marching_band },
    { { -3, 0 }, 20, 1, -76, 6, 6, -4, 2, 2, 10, 6, (void (*)(entity_t *, void *))entity_bear },
    { { 0, -2 }, -20, 1, -76, 6, 6, -7, 2, 2, 10, 6, (void (*)(entity_t *, void *))entity_rabbit },
    { { 5, 3 }, -20, 1, 0, 8, 6, 0, 0, 3, 10, 8, (void (*)(entity_t *, void *))entity_prince_princess },
    { { 3, -1 }, -20, 1, 0, 2, 2, -6, 2, 1, 20, 2, (void (*)(entity_t *, void *))entity_human_face_flower },
    { { 9, 9 }, -50, 0, 0, 0, 1, 0, 2, 1, 30, 0, (void (*)(entity_t *, void *))entity_ferris_wheel },
    { { -4, -4 }, 50, 1, 90, 1, 1, -9, 1, 1, 30, 1, (void (*)(entity_t *, void *))entity_lips_giant },
    { { -2, -6 }, -100, 1, 30, 5, 1, -3, 0, 1, 30, 5, (void (*)(entity_t *, void *))entity_locomotive_kyoto },
    { { 9, 0 }, 20, 1, 0, 6, 6, 0, 0, 1, 0, 6, (void (*)(entity_t *, void *))entity_whale },
    { { 1, -1 }, -50, 1, 30, 6, 6, -5, 1, 3, 20, 6, (void (*)(entity_t *, void *))entity_standing_penguin },
    { { -3, 1 }, -50, 1, 30, 8, 8, -5, 1, 3, 30, 8, (void (*)(entity_t *, void *))entity_sliding_penguin },
    { { 0, 0 }, 50, 0, 0, 0, 4, 0, 0, 2, 30, 0, NULL },
    { { 0, 0 }, -50, 0, 0, 0, 4, 0, 0, 2, 30, 0, NULL },
    { { 7, 0 }, 100, 1, 0, 15, 8, -13, 2, 2, 20, 15, (void (*)(entity_t *, void *))entity_hopscotch_girl },
    { { 0, -4 }, -100, 0, 0, 0, 5, -6, 2, 3, 0, 0, (void (*)(entity_t *, void *))entity_corpse },
    { { -9, -3 }, -50, 1, 0, 15, 15, 0, 3, 3, 30, 15, (void (*)(entity_t *, void *))entity_airplane },
    { { -3, -6 }, -20, 1, 0, 1, 1, 0, 0, 1, 30, 1, (void (*)(entity_t *, void *))entity_hanged_woman },
    { { -3, 1 }, -50, 1, -76, 15, 8, 0, 0, 3, 30, 15, (void (*)(entity_t *, void *))entity_starship },
    { { 0, -9 }, -100, 0, 0, 0, 5, 0, 0, 3, 0, 5, NULL },
    { { 5, -1 }, 20, 1, 0, 10, 1, -6, 3, 3, 30, 10, (void (*)(entity_t *, void *))entity_kicking_man },
    { { -4, -5 }, -1, 1, 60, 2, 2, 0, 5, 1, 10, 2, (void (*)(entity_t *, void *))entity_triangle_head },
    { { 0, 8 }, 20, 2, 1, 1, 3, 0, 0, 2, 0, 0, NULL },
    { { 2, 1 }, 50, 0, 0, 0, 12, 0, 0, 5, 40, 0, (void (*)(entity_t *, void *))entity_ship },
    { { 1, 0 }, -20, 0, -1, 0, 3, -3, 2, 1, 0, 0, (void (*)(entity_t *, void *))entity_maiko_palace },
    { { -4, -1 }, 20, 0, 0, 0, 3, -8, 1, 1, 20, 0, (void (*)(entity_t *, void *))entity_acrobats },
    { { 0, 0 }, -50, 0, -36, 0, 3, 0, 0, 1, 0, 0, (void (*)(entity_t *, void *))entity_light },
    { { 0, -1 }, 50, 1, -76, 5, 5, 12, 0, 1, 30, 3, (void (*)(entity_t *, void *))entity_dog },
    { { 0, 0 }, -4, 0, 0, 0, 3, 0, 0, 3, 100, 3, (void (*)(entity_t *, void *))entity_gears },
    { { 2, 2 }, 50, 0, -76, 0, 10, 0, 0, 6, 30, 0, (void (*)(entity_t *, void *))entity_ring },
    { { 9, 0 }, 100, 1, -76, 6, 3, -3, 1, 1, 10, 6, (void (*)(entity_t *, void *))entity_hoop_girl },
    { { 0, 0 }, 0, 0, 0, 0, 0, 0, 0, 3, 30, 0, NULL },
    { { 4, 0 }, 9, 0, 0, 0, 1, 0, 0, 1, 30, -1, (void (*)(entity_t *, void *))entity_small_room },
    { { 0, 1 }, 100, 0, 0, 0, 1, -4, 0, 1, 30, 1, (void (*)(entity_t *, void *))entity_clouds_wind },
    { { 0, 0 }, 100, 0, 0, 0, 3, 13, 0, 1, 10, 3, (void (*)(entity_t *, void *))entity_window },
    { { 6, 2 }, -20, 1, 60, 17, 3, -5, 6, 2, 0, 17, (void (*)(entity_t *, void *))entity_flower },
    { { 9, 0 }, 100, 0, 60, 0, 1, -5, 1, -2, 10, 1, (void (*)(entity_t *, void *))entity_bear_apartment },
    { { -2, 3 }, 20, 0, 0, 0, 1, 0, 0, 1, 10, 0, (void (*)(entity_t *, void *))entity_paper_sumo },
    { { -6, 7 }, -6, 0, 0, 0, 2, 0, 1, 1, 20, 0, (void (*)(entity_t *, void *))entity_orrery },
    { { 5, 5 }, -100, 0, 120, 0, 2, -3, 4, 1, 10, 1, (void (*)(entity_t *, void *))entity_face },
    { { -3, 3 }, 50, 0, -76, 0, 1, 127, 0, 1, 30, 0, (void (*)(entity_t *, void *))entity_lion },
    { { 4, -5 }, -20, 0, 0, 0, 3, -5, 0, 1, 0, 1, (void (*)(entity_t *, void *))entity_dress_woman },
    { { 3, -1 }, -50, 1, 0, 1, 1, 0, 0, 3, 10, 1, (void (*)(entity_t *, void *))entity_can },
    { { -5, 5 }, -50, 1, 120, 3, 3, 0, 3, 3, 30, 3, (void (*)(entity_t *, void *))entity_car_water },
    { { 3, 0 }, 20, 1, 0, 8, 1, -10, 3, 1, 0, 1, (void (*)(entity_t *, void *))entity_gunman },
    { { 0, -8 }, -100, 1, 0, 10, 3, 0, 0, 1, 0, 3, (void (*)(entity_t *, void *))entity_gunman_victim },
    { { 3, 0 }, -50, 0, 0, 0, 3, 8, 0, 1, 20, 0, (void (*)(entity_t *, void *))entity_kemari_boy_west },
    { { 0, 3 }, -50, 0, 0, 0, 3, 11, 0, 1, 20, 0, (void (*)(entity_t *, void *))entity_kemari_boy_east },
    { { 0, -7 }, 0, 0, 0, 0, 2, 0, 5, -4, 10, 1, (void (*)(entity_t *, void *))entity_trash_can },
    { { 0, 5 }, -1, 0, 0, 0, 1, -9, 1, -2, 10, -1, (void (*)(entity_t *, void *))entity_television },
    { { 0, 1 }, -100, 1, 0, 1, 1, -6, 0, -4, 10, 1, (void (*)(entity_t *, void *))entity_big_face_man_hidden },
    { { -3, -4 }, -1, 0, 0, 0, 1, -6, 2, -8, 10, 0, (void (*)(entity_t *, void *))entity_big_face_man },
    { { 2, 8 }, 50, 0, 60, 0, 3, 0, 0, 1, 20, 3, (void (*)(entity_t *, void *))entity_yokai },
    { { 0, 5 }, 100, 0, 40, 8, 8, -11, 3, 3, 30, 0, (void (*)(entity_t *, void *))entity_tengu },
    { { 4, 2 }, -100, 1, 20, 3, 1, 0, 0, 2, 10, 1, (void (*)(entity_t *, void *))entity_fetus_walk },
    { { 2, 0 }, -100, 0, 0, 0, 2, -14, 2, 1, 20, 0, (void (*)(entity_t *, void *))entity_fetus_jump },
    { { 0, 0 }, 0, 0, 0, 0, 0, 0, 0, 3, 30, 0, NULL },
    { { -10, -10 }, 20, 0, -76, 0, 1, 0, 0, 1, 0, 0, (void (*)(entity_t *, void *))entity_gray_man },
    { { 10, 10 }, -20, 0, 0, 0, -2, 0, 0, 1, 30, -1, NULL },
    { { -10, -10 }, 100, 0, 0, 0, 0, 0, 0, 3, 30, 0, NULL },
    { { 9, 9 }, 100, 1, 0, 0, 0, 0, 0, 3, 30, 0, NULL },
    { { -5, 0 }, 20, 3, -76, 5, 1, -13, 0, 3, 30, 5, (void (*)(entity_t *, void *))entity_winged_minotaur },
    { { -6, 7 }, 100, 1, -76, 5, 5, -10, 0, 2, 0, 5, (void (*)(entity_t *, void *))entity_airship },
    { { 2, 2 }, -4, 1, 0, 2, 2, 0, 0, 1, 0, 2, (void (*)(entity_t *, void *))entity_maiko_small },
    { { 0, -3 }, -100, 0, 60, 0, 2, 0, 0, 1, 0, 0, (void (*)(entity_t *, void *))entity_bed_bone_dead },
    { { 0, 5 }, -1, 0, 60, 0, 1, 0, 0, -2, 10, 1, (void (*)(entity_t *, void *))entity_yokai_bartender },
    { { 0, 5 }, -1, 0, 60, 0, 1, -2, 1, -2, 10, -1, (void (*)(entity_t *, void *))entity_yokai },
    { { 9, 0 }, 100, 1, -76, 6, 3, -3, 1, 1, 10, 6, (void (*)(entity_t *, void *))entity_hoop_girl_giant },
    { { 3, 3 }, 100, 0, -76, 0, 7, -2, 4, 5, 0, 0, (void (*)(entity_t *, void *))entity_elephant_small },
    { { 3, 0 }, 9, 0, 120, 0, 5, -13, 1, 3, 0, 0, (void (*)(entity_t *, void *))entity_maiko_bridge },
    { { -9, 5 }, -50, 1, 0, 15, 15, -4, 8, 3, 50, 15, (void (*)(entity_t *, void *))entity_locomotive_natural },
    { { 8, 8 }, 100, 0, -76, 0, 15, -6, 2, 3, 50, 0, NULL },
    { { 1, -1 }, -50, 1, 30, 6, 6, -5, 1, 3, 20, 6, (void (*)(entity_t *, void *))entity_question_mark_penguin },
    { { 1, 1 }, -80, 1, 90, 6, 6, -5, 1, 3, 20, 6, (void (*)(entity_t *, void *))entity_standing_penguin_flock },
    { { -3, -6 }, -20, 1, 0, 1, 1, -6, 1, 1, 30, 1, (void (*)(entity_t *, void *))entity_hanged_woman_paralysis },
    { { -3, -6 }, -20, 1, 0, 1, 1, -6, 3, 1, 30, 1, NULL },
    { { -4, -5 }, -1, 1, 60, 8, 8, -11, 8, 3, 10, 8, (void (*)(entity_t *, void *))entity_triangle_head_giant },
    { { 6, 0 }, -20, 0, 0, 0, 2, -3, 8, 1, 0, 0, (void (*)(entity_t *, void *))entity_fish_giant },
    { { 7, 1 }, 20, 0, 0, 0, -10, 0, 0, 5, 0, 0, (void (*)(entity_t *, void *))entity_siblings_flock },
    { { -6, 8 }, 20, 1, 120, 8, 1, 8, 0, 1, 30, 8, (void (*)(entity_t *, void *))entity_lion },
    { { 1, 1 }, 20, 1, 90, 8, 3, -4, 1, 3, 30, 8, (void (*)(entity_t *, void *))entity_turtle_small },
    { { 0, -1 }, -50, 1, 90, 3, 5, 0, 0, 3, 0, 3, (void (*)(entity_t *, void *))entity_boat_bird },
    { { -7, 6 }, 8, 0, -116, 0, 3, 0, 0, 3, 0, 3, (void (*)(entity_t *, void *))entity_car },
    { { 4, 4 }, -100, 0, 120, 0, 5, 0, 0, 3, 20, 5, NULL },
    { { -5, 6 }, 9, 1, -1, 5, 5, -14, 1, 3, 20, 5, (void (*)(entity_t *, void *))entity_maiko_plain },
    { { -5, 4 }, 9, 0, -116, 0, 5, -4, 3, 3, 0, 0, (void (*)(entity_t *, void *))entity_car },
    { { 5, 1 }, -20, 0, 120, 0, 3, -5, 1, 1, 0, 0, NULL },
    { { -4, -4 }, 50, 1, 0, 1, 1, -14, 1, 1, 0, 1, (void (*)(entity_t *, void *))entity_lips_small },
    { { 2, -3 }, -20, 0, 120, 0, 2, -14, 1, 1, 0, 1, (void (*)(entity_t *, void *))entity_paper_sumo_wait },
};
