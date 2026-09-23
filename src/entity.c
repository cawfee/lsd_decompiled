#include "entity.h"
#include "55DD4.h"
#include "dream_sys.h"

extern entity_vtable_t g_ENTITY_VTABLE;

extern s32 D_80089DCC;
extern s32 D_80089DD8;
extern s32 D_80089D48;
extern s32 D_80089D78;
extern s32 D_80089D90;
extern s32 D_80089D9C;
extern s32 D_80089DF0;
extern s32 D_80089E38;
extern s32 D_80089E80;
extern s32 D_80089C58;
extern s32 D_80089C64;
extern s32 D_80089C70;
extern s32 D_80089C7C;
extern s32 D_80089C88;
extern s32 D_80089C94;
extern s32 D_80089CC4;
extern s32 D_80089CD0;
extern s32 D_80089CDC;
extern s32 D_80089CB8;
extern s32 D_80089CE8;
extern s32 D_80089CF4;
extern s32 D_80089DA8;
extern s32 D_80089CAC;
extern s32 D_80089CA0;
extern s32 D_80089D00;
extern s32 D_80089D18;
extern s32 D_80089D24;
extern s32 D_80089D3C;
extern s32 D_80089D54;
extern s32 D_80089D60;
extern s32 D_80089D6C;
extern s32 D_80089DB4;
extern s32 D_80089DC0;
extern s32 D_80089DE4;
extern s32 D_80089DFC;
extern s32 D_80089E14;
extern s32 D_80089E20;
extern s32 D_80089E2C;
extern s32 D_80089E44;
extern s32 D_80089E50;
extern s32 D_80089E5C;
extern s32 D_80089E74;
extern s32 D_80089E8C;
extern s16 D_80089EA2;
extern void *D_8008AC14;
extern void *D_8008AC0C;
extern void *D_8008AC1C;

extern entity_prop_t g_ENTITY_TABLE[];

void func_8005DF9C(entity_t *This, s32 Unk2);
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
        This->m_Class_305B0 = NULL;
        This->m_Unk64 = 0;
        This->vtable->Unk15(This);
        return This;
    }

    return NULL;
}

class_305B0_t *func_8005D108(entity_t *This, void *Unk2, void *Unk3, s32 Unk4, s32 Unk5) {
    class_305B0_t *out;
    class_305B0_t *temp_v0;

    temp_v0 = This->m_Class_305B0;
    if (temp_v0 == NULL) {
        void *create_arg = Unk2;
        if (create_arg == NULL) {
            create_arg = &D_8008AC14;
        }

        out = class_305B0_create(create_arg, 0, Unk5);
        if (out == NULL) {
            return NULL;
        }

        This->m_Class_305B0 = out;
    } else {
        out = temp_v0;
    }

    out->vtable->Unk19(out);

    out->vtable->Unk18(out, This, Unk3 != NULL ? Unk3 : &D_8008AC0C);
    out->vtable->Unk51(out, Unk4);

    return out;
}

void entity_cleanup(entity_t *This) {
    if (This->m_Class_305B0) {
        This->m_Class_305B0->vtable->base_class_destructor(This->m_Class_305B0);
    }

    if (This->m_Unk64) {
        (*(void (**)(s32))(*(s32 *) This->m_Unk64 + 4))(This->m_Unk64);
    }

    class_55DD4_get_vtable()->class_55DD4_cleanup(This);
}

void func_8005D278(entity_t *This) {
    if ((u8) ((u32) (g_ENTITY_TABLE[This->m_EntityID].unlock - 1)) < 9) {
        This->vtable->Unk27(This, 1);
    }

    This->vtable->Unk66(This, 66);
    This->vtable->Unk87(This);
}

void func_8005D314(entity_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    if (This->m_Unk2 == 0) {
        s32 entity_id;

        class_55DD4_get_vtable()->Unk18(This, Unk2, Unk3, Unk4, Unk5);

        entity_id = This->m_EntityID;
        This->m_Unk18 = Unk4;

        if (g_ENTITY_TABLE[entity_id].behaviour == 0) {
            This->vtable->Unk86(This);

            if (g_ENTITY_TABLE[This->m_EntityID].link_flag == 0) {
                This->vtable->Unk89(This);
            }
        }
    }
}

void func_8005D418(entity_t *This) {
    if (This->m_Unk2) {
        This->vtable->Unk87(This);
        class_55DD4_get_vtable()->Unk19(This);
        This->m_Unk18 = 0;
    }
}

void func_8005D480(entity_t *This, s32 Unk2, s32 Unk3) {
    if (This->vtable->Unk91(This)) {
        This->vtable->Unk92(This);
    }
    if (This->vtable->Unk94(This)) {
        This->vtable->Unk95(This);
    }
    This->vtable->Unk93(This);
    class_55DD4_get_vtable()->Unk37(This, Unk2, Unk3);
}

void func_8005D560(entity_t *This, s32 Unk2, s32 Unk3) {
    s32 v5;

    v5 = g_ENTITY_TABLE[This->m_EntityID].link_stage;

    if (((u32) (Unk3 - 2) >= 7U) || (v5 > 0)) {
        class_55DD4_get_vtable()->Unk54(This, Unk2, Unk3);

        if ((Unk3 == 4) && (v5 > 0)) {
            if (v5 != 127) {
                Unk3 = 10;
            } else {
                Unk3 = 12;
                if (g_ENTITY_TABLE[This->m_EntityID].event_video_id != 0) {
                    Unk3 = 11;
                }
            }
            This->vtable->Unk11(This, Unk3);
        }
    }
}

void func_8005D658(entity_t *This, s32 Unk2, s32 Unk3) {
    class_55DD4_get_vtable()->Unk55(This, Unk2, Unk3);
    if (Unk3 == 4) {
        This->vtable->Unk87(This);
    }
}

void func_8005D6D4(entity_t *This) {
    helper_1_update_entity(This->m_Unk21, &This->m_EntityContext);
    ++This->m_Unk62;
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

    return This->m_Unk36->vtable->Unk71(This->m_Unk36, call_arg_1, call_arg_2, &local_data, Unk4);
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

    a0_ptr = This->m_Unk4;

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

s32 func_8005D864(entity_t *This) {
    if (This->m_Unk36) {
        s32 vcall_result = This->vtable->entity_get_distance(This, This->m_Unk36);
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

void func_8005D9F4(entity_t *This) {
    This->vtable->Unk23(This, 1);
    This->m_Unk59 = 1;
    This->m_Unk8 = 0;
}

void func_8005DA3C(entity_t *This) {
    This->vtable->Unk23(This, 0);
    This->vtable->Unk90(This);
    This->vtable->Unk88(This, 0);
    This->m_Unk59 = 0;
}

void func_8005DAAC(entity_t *This, s32 Value) {
    if (Value) {
        This->vtable->Unk11(This, 9);
    }
    This->m_Unk60 = Value;
}

void func_8005DAFC(entity_t *This) {
    helper_1_set_entity(This->m_Unk21, &This->m_EntityContext, This->m_EntityID + 1, This,
                        g_ENTITY_TABLE[This->m_EntityID].behaviour_fn);

    This->vtable->Unk74(This); // This->m_Unk35 = 1
    This->vtable->Unk67(This); // This->m_Unk34 = 1

    This->m_Unk62 = 0;
    This->m_Unk61 = 1;
}

void func_8005DB8C(entity_t *This) {
    func_8002CC84(This->m_Unk21, &This->m_EntityContext);
    This->vtable->Unk75(This);
    This->vtable->Unk68(This);
    This->m_Unk61 = 0;
}

s32 func_8005DBF0(entity_t *This) {
    if (This->m_Unk59 == 0 && This->m_Unk16 != 1) {
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

        if (entity_check_proximity(This, This->m_Unk4 + 24, property->interaction_range, property->interaction_param) ==
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
            This->vtable->Unk86(This);
        }
    }
    return This->m_Unk59;
}

s32 func_8005DD18(entity_t *This) {
    if (This->m_Unk59 != 0) {
        u8 *data_ptr;
        s32 should_call;

        data_ptr = &g_ENTITY_TABLE[This->m_EntityID];
        func_8005DF9C(This, 0);

        should_call = 0;

        if ((data_ptr[4] != 0) && (data_ptr[4] != 3)) {
            if (data_ptr[4] >= 10) {
                should_call = (This->m_Unk8 == (data_ptr[4] * 15));
            } else {
                s8 val5 = ((s8 *) data_ptr)[5];

                if (val5 != 0) {
                    s8 val9 = ((s8 *) data_ptr)[9];

                    if (entity_check_proximity(This, This->m_Unk4 + 24, val5, val9) != 0) {
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
            This->vtable->Unk87(This);
        }
    }

    return This->m_Unk59;
}

s32 func_8005DE18(entity_t *this) {
    entity_prop_t *property;
    s32 val;

    property = &g_ENTITY_TABLE[this->m_EntityID];

    if (this->m_Unk59 != 0) {
        if (this->m_Unk60 == 0) {
            s32 func_arg1 = this->m_Unk4 + 24;

            val = property->interaction_angle;

            if (val < 0) {
                val = ~val + 1;
            }

            if (entity_check_proximity(this, func_arg1, val, property->interaction_param) != 0) {
                this->vtable->Unk88(this, 1);
            }
        }

        if (property->interaction_angle < 0) {
            func_8001EACC(this, this->m_Unk36, 1, 0, 0);
        }
    }

    return this->m_Unk60;
}

s32 func_8005DEE0(entity_t *This) {
    if (This->m_Unk59) {
        if (This->m_Unk61) {
            return This->m_Unk61;
        }

        if (This->m_Unk16 != 1) {
            entity_prop_t *property = &g_ENTITY_TABLE[This->m_EntityID];
            s32 link_flag = property->link_flag;

            if (link_flag) {
                s32 arg1_val = This->m_Unk4 + 24;

                if (link_flag < 0) {
                    link_flag = ~link_flag + 1;
                }

                if (entity_check_proximity(This, arg1_val, link_flag, property->interaction_param)) {
                    This->vtable->Unk89(This);
                }
            }
        }
    }

    return This->m_Unk61;
}

void func_8005DF9C(entity_t *This, s32 Unk2) {
    s32 entity_id = This->m_EntityID;

    if (g_ENTITY_TABLE[entity_id].link_stage < 0) {
        s8 val = g_ENTITY_TABLE[entity_id].event_video_id;

        if (val) {
            if (func_8005E02C(This, val << 9)) {
                This->vtable->Unk11(This, 10);
            }
        }
    }
}

s32 func_8005E02C(entity_t *This, s32 Unk2) {
    s32 v2;
    s32 v3;
    void *ptr_from_unk36;
    void *ptr_from_unk36_deref;
    void *ptr_from_unk4;

    ptr_from_unk36 = This->m_Unk36;
    ptr_from_unk36_deref = *(void **) ((char *) ptr_from_unk36 + 0x14);
    ptr_from_unk4 = (void *) This->m_Unk4;
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

s32 func_8005E0B0(const entity_t *This) {
    if (This->m_Unk59 != 0 && This->m_Unk61 != 0) {
        entity_prop_t *property;
        s8 link_flag;
        s32 unk4;

        property = &g_ENTITY_TABLE[This->m_EntityID];
        link_flag = property->link_flag;

        if (link_flag < 0) {
            unk4 = This->m_Unk4;

            if (entity_check_proximity(This, unk4 + 24, ~link_flag + 1, property->interaction_param) == 0) {
                This->vtable->Unk90(This);
            }
        }
    }

    return This->m_Unk61;
}

entity_vtable_t *entity_get_vtable() {
    return &g_ENTITY_VTABLE;
}

// entity_t *, entity_context_t *, -1

void func_8005E160(entity_t *This, s32 *arg1) {
    s32 tick;

    if (arg1[1] == 0) {
        if (This->m_Unk36->vtable->dream_sys__get_dream_color(This->m_Unk36) == 5) {
            This->m_Unk16 = 0x64;
        }
    }
    arg1[4] = This->vtable->Unk81(This);
    if (This->m_Unk16 == 0) {
        if ((arg1[1] % 10) == 0) {
            arg1[7] = 5;
            arg1[8] = -2;
        }
        tick = This->m_Unk62;
        if (tick == 0x960) {
            This->m_Unk62 = -1;
            return;
        }
        if (tick < 0x4B0) {
            This->vtable->Unk48(This, 0x32, 0);
        } else {
            This->vtable->Unk48(This, -0x32, 0);
        }
        return;
    }
    tick = This->m_Unk62;
    if (tick < 0xFA) {
        if ((arg1[1] % 10) == 0) {
            arg1[7] = 5;
            arg1[8] = -2;
        }
        tick = This->m_Unk62;
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

void func_8005E3C4(entity_t *This, s32 *arg1) {
    arg1[4] = 0;
    if (arg1[1] == 0) {
        arg1[7] = 0x14;
        arg1[12] = 0x14;
        arg1[17] = 0x14;
        This->m_Unk36->vtable->Unk75(This->m_Unk36, 1);
    }
    func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    This->vtable->Unk48(This, -0x5A, 0);
    if (This->m_Unk62 == 0x1E) {
        This->vtable->Unk11(This, 0xA);
    }
}

void func_8005E480(entity_t *This, s32 *Unk) {
    s32 v2; // $v0
  s32 v4; // $v1

  v2 = This->vtable->Unk81(This);
  v4 = Unk[1];
  Unk[4] = v2;
  if ( !v4 )
    Unk[7] = 23;
}

void func_8005E4D0(entity_t *This, s32 *arg1) {
    arg1[4] = This->vtable->Unk81(This);
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
    if (This->m_Unk62 >= 0x79) {
        This->vtable->Unk16(This, 0, &D_80089CA0);
        This->vtable->Unk48(This, -0x140, 0);
        return;
    }
    if ((This->m_Unk62 >= 0x38) || (entity_check_proximity(This, This->m_Unk4 + 24, 1, 1) != 0)) {
        This->vtable->Unk46(This, &D_80089D78);
        return;
    }
    if (This->m_Unk62 >= 0xA) {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        This->vtable->Unk48(This, -0x100, 0);
    } else {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    }
}

void func_8005E694(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DF0);
    This->vtable->Unk46(This, &D_80089D78);
}

void func_8005E6F0(entity_t *This, s32 *arg1) {
    u32 temp;
    s32 half;

    arg1[4] = This->vtable->Unk81(This);
    temp = This->m_Unk31;
    half = ((s32)(temp + (temp >> 31))) >> 1;
    if ((arg1[1] % half) == 0) {
        arg1[7] = 0xA;
    }
    This->vtable->Unk48(This, -0x1E, 0);
}

void func_8005E7A8(entity_t *This, s32 *Unk) {
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

void func_8005E7F8(entity_t *This, s32 *arg1) {
    s32 *ptr;
    s32 temp;
    u32 utemp;
    s32 half;

    *(s16 *)&This->m_Unk17 = -0x14;
    arg1[4] = This->vtable->Unk81(This);
    utemp = This->m_Unk31;
    half = ((s32)(utemp + (utemp >> 31))) >> 1;
    ptr = NULL;
    if ((arg1[1] % half) == 0) {
        arg1[7] = 0xA;
        arg1[8] = 1;
    }
    temp = This->m_Unk16;
    if (temp == 0xB) {
        temp = This->m_Unk62;
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
            if (This->m_Unk36->vtable->Unk63(This->m_Unk36) != 0) {
                This->m_Unk62 = 0;
                This->m_Unk16 = 0xD;
            }
        }
    } else if (temp == 0xC) {
        if (This->m_Unk62 == 0x7BC) {
            ptr = &D_80089C94;
        }
    } else if (temp == 0xD) {
        *(s16 *)&This->m_Unk17 = -0x78;
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        This->vtable->Unk17(This, 1, &D_80089DD8);
        if (This->vtable->entity_get_distance(This, This->m_Unk36) < 0x400) {
            This->vtable->Unk11(This, 0xB);
        }
    }
    if (This->m_Unk62 == 0x618) {
        if (rand() & 1) {
            ptr = &D_80089C88;
            This->m_Unk16 = 0xB;
        } else {
            ptr = &D_80089C94;
            This->m_Unk16 = 0xC;
        }
    }
    if (ptr != NULL) {
        This->vtable->Unk16(This, 0, ptr);
    }
    This->vtable->Unk51(This, *(s16 *)&This->m_Unk17, 0);
    if ((This->m_Unk16 != 0xC) && (This->m_Unk9 != 0)) {
        This->vtable->Unk50(This, -0xC8, 0);
    }
}

void func_8005EA94(entity_t *This) {
    s32 count;

    if (This->m_Unk62 == 0) {
        if ((rand() & 1) == 0) {
            This->m_Unk16 = 0xB;
        }
    }
    if (*(s32 *)(This->m_Unk4 + 0x1C) < 0x7D0) {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    }
    if (This->m_Unk16 == 0xB) {
        if (This->vtable->entity_get_distance(This, This->m_Unk36) < 0xA00) {
            (*(void (**)(s32, s32, s32))(*(s32 *)This->m_Unk18 + 0x138))(This->m_Unk18, 1, 1);
            This->m_Unk62 = 1;
            This->m_Unk16 = 0xC;
        }
    } else if (This->m_Unk16 == 0xC) {
        count = This->m_Unk62;
        This->m_Unk62 = count + 1;
        if (count == 0x12C) {
            This->vtable->Unk11(This, 0xC);
        }
    }
}

void func_8005EBB4(entity_t *This, s32 *arg1) {
    s32 temp;
    s32 r;

    arg1[4] = This->vtable->Unk81(This);
    temp = arg1[1];
    if (temp == 0) {
        arg1[7] = 0xC;
        This->m_Unk16++;
    } else if (temp >= (This->m_Unk31 - 1)) {
        arg1[1] = -1;
    }
    if (This->m_Unk16 == 0x24) {
        r = rand();
        if (r == ((r / 3) * 3)) {
            This->vtable->Unk11(This, 0xB);
        }
    }
}

void func_8005EC98(entity_t *This, s32 *Unk) {
    Unk[4] = This->vtable->Unk81(This);
    if (This->m_Unk32 == 0xA) {
        Unk[7] = 0xD;
    }
    This->vtable->Unk48(This, -0xA, 0);
}

void func_8005ED10(entity_t *This, s32 *Unk) {
    if (!This->m_Unk62) {
        Unk[4] = 0;
        Unk[7] = 15;
    }
}

void func_8005ED30(entity_t *This) {
    s32 state;
    s32 roll;
    s32 *clip;

    if (This->m_Unk62 == 0) {
        if (rand() & 1) {
            This->m_Unk16 = 0xB;
        }
    }
    state = This->m_Unk16;
    if (state == 0) {
        if (This->m_Unk62 < 0x40) {
            This->vtable->Unk48(This, -0x5A, 0);
            return;
        }
        if (This->m_Unk62 == 0x40) {
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
    if ((This->m_Unk62 % 5) == 0) {
        This->vtable->Unk16(This, 0, &D_80089C88);
    }
    This->vtable->Unk48(This, -0x800, 0);
    This->vtable->Unk23(This, (rand() % 7) == 0);
}

void func_8005EF20(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DD8);
}

void func_8005EF54(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->Unk81(This);
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[7] = 0x11;
    }
    This->vtable->Unk48(This, -0x100, 0);
}

void func_8005EFF4(entity_t *This, s32 *arg1) {
    s32 r;

    if (This->m_Unk62 == 0) {
        r = rand();
        if (r == ((r / 7) * 7)) {
            This->vtable->Unk17(This, 1, &D_80089E50);
        }
    }
    if (!(arg1[1] & 3)) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 0x1C;
    }
    This->vtable->Unk48(This, -0x64, 0);
}

void func_8005F0D8(entity_t *This, s32 *arg1) {
    u32 temp;
    s32 half;
    s32 rem;

    arg1[4] = This->vtable->Unk81(This);
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

void func_8005F1A8(entity_t *This) {
    func_8001EACC(This, This->m_Unk36, 1, 0, 0);
}

void func_8005F1D4(entity_t *This) {
    s32 count;

    func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    if (This->m_Unk60 != 0) {
        if (This->m_Unk62 >= 0x41) {
            This->m_Unk62 = 0;
        }
        if (This->m_Unk62 >= 7) {
            This->vtable->Unk46(This, &D_80089D78);
            This->vtable->Unk48(This, 0xA, 0);
        } else {
            This->vtable->Unk46(This, &D_80089D9C);
        }
    } else {
        count = This->m_Unk62;
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

void func_8005F368(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = arg1[1];
    if (temp == ((temp / 15) * 15)) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 7;
        arg1[8] = -2;
    }
    This->vtable->Unk17(This, 1, &D_80089DF0);
    This->vtable->Unk16(This, 0, &D_80089CA0);
    This->vtable->Unk48(This, -0x200, 0);
}

void func_8005F454(entity_t *This, s32 *arg1) {
    s32 count;
    s32 n;

    arg1[4] = 0;
    count = This->m_Unk62;
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

void func_8005F544(entity_t *This, s32 *arg1) {
    if ((arg1[1] % This->m_Unk31) == 0) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 0x1A;
    }
    This->vtable->Unk51(
        This, (This->m_Unk62 == 0x6E) ? -0x2D00 : -0x180, 0);
}

void func_8005F608(entity_t *This, s32 *arg1) {
    s32 temp;
    s32 temp_v1;

    temp = arg1[1];
    if (temp == ((temp / 70) * 70)) {
        arg1[4] = 0;
        arg1[7] = 0x1B;
    }
    This->vtable->Unk48(This, -0x80, 0);
    temp_v1 = This->m_Unk62;
    if (temp_v1 < 0x64) {
        This->vtable->Unk50(This, 0x20, 0);
    } else if (temp_v1 >= 0x12D) {
        This->vtable->Unk50(This, -0x20, 0);
    }
}

void func_8005F6D4(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void func_8005F708(entity_t *This) {
    if (This->m_Unk62 == 0) {
        if (This->m_Unk36->vtable->dream_sys__get_dream_color(This->m_Unk36) == 7) {
            This->vtable->Unk17(This, 1, &D_80089E74);
            This->vtable->Unk50(This, -0x7800, 0);
        }
        This->m_Unk16 = rand() % 5;
    }
    if (This->m_Unk16 == 0) {
        This->vtable->Unk16(This, 0, &D_80089D18);
    }
}

void func_8005F800(entity_t *This) {
    s32 temp;
    s32 a1;

    if (This->m_Unk16 == 0) {
        if (This->m_Unk36->vtable->dream_sys__get_dream_color(This->m_Unk36) == 1) {
            This->m_Unk16 = 0xB;
        } else {
            This->m_Unk16 = 0xC;
        }
    }
    if (This->m_Unk16 == 0xC) {
        This->vtable->Unk17(This, 1, &D_80089DF0);
        This->vtable->Unk50(This, -0x1E, 0);
    } else {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        temp = This->m_Unk16;
        if (temp == 0xB) {
            This->vtable->Unk48(This, -0x64, 0);
            temp = This->m_Unk62;
            if ((u32)(temp - 0x55) < 0x1EU) {
                This->vtable->Unk50(This, 0x50, 0);
            } else if (temp == 0x78) {
                This->m_Unk16 = 0xD;
            }
        } else if (temp == 0xD) {
            This->vtable->Unk45(This, This->m_Unk36->m_Unk4 + 0x18);
            This->vtable->Unk46(This, &D_80089DB4);
        }
    }
}

void func_8005F970(entity_t *This, s32 *arg1) {
    func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    This->m_Unk36->vtable->Unk75(This->m_Unk36, 1);
    if ((arg1[1] % 10) < 3) {
        arg1[4] = 0;
        arg1[7] = 0xD;
        arg1[12] = 0xD;
        arg1[17] = 0xD;
    }
    if (This->m_Unk62 == This->m_Unk31) {
        This->vtable->Unk75(This);
        This->vtable->Unk11(This, 0xA);
    }
}

void func_8005FA64(entity_t *This) {
    This->vtable->Unk48(This, -30, 0);
}

void func_8005FA94(entity_t *This, s32 *arg1) {
    s32 temp;

    if (This->m_Unk60 != 0) {
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

void func_8005FB6C(entity_t *This) {
    s32 count;

    count = This->m_Unk62;
    if ((u32)(count - 0x190) < 0xA) {
        This->vtable->Unk16(This, 0, &D_80089C64);
    } else if (((u32)(count - 0x2BC) < 0xA) || ((u32)(count - 0x33E) < 4)) {
        This->vtable->Unk16(This, 0, &D_80089C70);
    } else if (count >= 0x353) {
        This->vtable->Unk87(This);
    }
    {
        entity_vtable_t *vt;
        s32 n;

        n = This->m_Unk62;
        vt = This->vtable;
        vt->Unk48(This, n < 0x320 ? -0x3C : -0x200, 1);
    }
}

void func_8005FC58(entity_t *This) {
    s32 rem;
    s32 arg;
    s32 nudge;
    entity_vtable_t *vt;
    entity_vtable_t *vt2;
    entity_vtable_t *vt3;

    rem = This->m_Unk62 % 500;
    if ((vt = This->vtable, (This->m_Unk62 % 6) < 3)) {
        arg = -0x40;
    } else {
        arg = 0x40;
    }
    vt->Unk50(This, arg, 0);
    if ((vt2 = This->vtable, (This->m_Unk62 % 12) < 6)) {
        nudge = -0x40;
    } else {
        nudge = 0x40;
    }
    vt2->Unk49(This, nudge, 0);
    if ((vt3 = This->vtable, (This->m_Unk62 % 64) < 0x20)) {
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

void func_8005FDFC(entity_t *This) {
    if (This->m_Unk16 == 0) {
        This->vtable->Unk17(This, 1, (rand() & 1) ? &D_80089DF0 : &D_80089E38);
        This->m_Unk16 = 0xB;
    }
    func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    if (This->vtable->entity_get_distance(This, This->m_Unk36) < 0x7000) {
        This->vtable->Unk48(This, 0x100, 0);
    }
}

void func_8005FEC8(entity_t *This) {
    This->vtable->Unk50(This, -90, 0);
}

void func_8005FEF8(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = arg1[1];
    if (temp == ((temp / 120) * 120)) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 1;
    }
}

void func_8005FF7C(entity_t *This, s32 *arg1) {
    s32 roll;

    if (This->m_Unk62 == 0) {
        roll = This->m_Unk36->vtable->get_day_number(This->m_Unk36, NULL) % 3;
        if (roll == 0) {
            if ((rand() % 3) == 0) {
                This->vtable->Unk17(This, 1, &D_80089E5C);
            }
        } else if (roll == 2) {
            This->vtable->Unk17(This, 1, &D_80089E5C);
        }
    }
    if ((arg1[1] % 22) == 0) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 2;
    }
    if ((rand() % 12) == 0) {
        This->vtable->Unk75(This);
    } else if ((rand() % 6) == 0) {
        This->vtable->Unk74(This);
    }
}

void func_80060148(entity_t *This, s32 *arg1) {
    s32 *ptr;
    s32 temp;
    s32 temp_v1;

    ptr = NULL;
    temp = arg1[1];
    if (temp == ((temp / 7) * 7)) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 3;
        arg1[9] = 0x40;
        arg1[10] = 0x40;
    }
    temp_v1 = This->m_Unk62;
    if (temp_v1 == 0xC8) {
        ptr = &D_80089C94;
    } else if (temp_v1 == 0x190) {
        ptr = &D_80089C7C;
    } else if (temp_v1 == 0x258) {
        ptr = &D_80089C88;
    } else if (temp_v1 == 0x320) {
        ptr = &D_80089C7C;
        This->m_Unk62 = -1;
    }
    if (ptr != NULL) {
        This->vtable->Unk16(This, 0, ptr);
    }
    This->vtable->Unk51(This, -0x1E, 0);
    if (This->m_Unk9 != 0) {
        This->vtable->Unk50(This, -0xC8, 0);
    }
}

void func_800602AC(entity_t *This, s32 *arg1) {
    s32 count;
    s32 kind;
    s32 roll;
    s16 *slot;

    count = This->m_Unk62;
    if (count == 0) {
        This->m_Unk16 = (rand() % 5) + 0xA;
    }
    kind = This->m_Unk16;
    if ((kind < 0xE) || (This->m_Unk62 < 0x140)) {
        func_80064FBC(This, arg1, 0xBB8, 0x1F4, -0x100);
    } else if ((kind == 0xE) && ((This->m_Unk62 & 3) == 0)) {
        roll = rand();
        slot = &D_80089EA2;
        *slot = (roll % 32) + 1;
        This->vtable->Unk17(This, 1, (s32 *)(slot - 5));
    }
}

void func_800603C4(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = This->m_Unk62;
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

void func_800604DC(entity_t *This, s32 *arg1) {
    s32 temp;

    func_80060710(This);
    arg1[4] = This->vtable->Unk81(This);
    temp = This->m_Unk32;
    if ((temp == 0) || (temp == 0xF)) {
        arg1[7] = 0x12;
        arg1[12] = 0x12;
    }
    if (This->m_Unk62 >= 0x141) {
        This->vtable->Unk49(This, (rand() & 1) != 0 ? -0x3C : 0x3C, 0);
        This->vtable->Unk16(This, 0, (rand() & 3) != 0 ? &D_80089C70 : &D_80089C64);
    }
}

void func_800605D0(entity_t *This, s32 *arg1) {
    s32 temp;

    func_80060710(This);
    arg1[4] = This->vtable->Unk81(This);
    temp = This->m_Unk32;
    if ((temp == 7) || (temp == 0x16)) {
        arg1[7] = 3;
    }
    temp = This->m_Unk62;
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

void func_80060710(entity_t *This) {
    s32 r;

    if (This->m_Unk62 == 0) {
        r = rand() % 10;
        if (r >= 8) {
            This->vtable->Unk17(This, 1, &D_80089E8C);
        } else if (r >= 5) {
            This->m_Unk16 = 0xA;
        }
    }
    if ((This->m_Unk16 == 0xA) && (This->m_Unk62 >= 0xC9)) {
        This->vtable->Unk46(This, &D_80089DC0);
    }
}

void func_800607F8(void) {
}

void func_80060800(entity_t *This, s32 *arg1) {
    s32 rem;
    s32 r;

    if (This->m_Unk62 == 0) {
        rem = This->m_Unk36->vtable->get_day_number(This->m_Unk36, 0) % 3;
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
    func_8001EACC(This, This->m_Unk36, 1, 0, 0);
}

void func_8006090C(entity_t *This) {
    s32 temp;

    if (This->m_Unk60 != 0) {
        temp = This->m_Unk16;
        if (temp == 0) {
            This->m_Unk16 = 0xC;
            This->m_Unk62 = 0;
        } else if (temp == 0xC) {
            if (This->m_Unk62 < 0x1E) {
                if (This->m_Unk36->vtable->Unk63(This->m_Unk36) != 0) {
                    This->m_Unk36->vtable->Unk75(This->m_Unk36, 0);
                    This->m_Unk62 = 0;
                    This->m_Unk16 = 0xB;
                }
            } else {
                This->vtable->Unk11(This, 0xB);
                This->m_Unk16 = 0xA;
            }
        } else if (temp == 0xB) {
            if (This->m_Unk62 == 0x64) {
                This->vtable->Unk11(This, 0xC);
            } else {
                This->m_Unk36->vtable->Unk50(This->m_Unk36, -0x64, 0);
            }
        }
    }
}

void func_80060A4C(entity_t *This, s32 *out) {
    s32 angle;

    if (This->m_Unk32 == 0x26) {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        out[4] = This->vtable->Unk81(This);
        out[7] = 6;
    }
    angle = 0x1E;
    {
        entity_vtable_t *vt;

        vt = This->vtable;
        if ((This->m_Unk62 % 10) < 5) {
            angle = -0x1E;
        }
        vt->Unk50(This, angle, 0);
    }
    This->vtable->Unk48(This, -0x1E, 1);
}

void func_80060B34(entity_t *This, s32 *arg1) {
    s32 link;

    if (arg1[1] == 6) {
        arg1[4] = 0;
        arg1[7] = 4;
        arg1[12] = 4;
        arg1[17] = 4;
    }
    if (This->m_Unk60 != 0) {
        if (This->m_Unk16 == 0) {
            This->m_Unk16 = 0xA;
            This->m_Unk62 = 0;
        } else if (This->m_Unk16 == 0xA) {
            if (This->m_Unk62 != 0xA) {
                if (This->m_Unk36->vtable->Unk63(This->m_Unk36) != 0) {
                    dream_sys_t *sys;
                    dream_sys_vtable_t *vt;

                    sys = This->m_Unk36;
                    vt = sys->vtable;
                    if (This->m_Unk2 != 0) {
                        link = This->m_Unk4 + 0x38;
                    } else {
                        link = 0;
                    }
                    vt->Unk45(This->m_Unk36, link);
                    This->m_Unk36->vtable->Unk16(This->m_Unk36, 1, &D_80089C94);
                    This->m_Unk36->vtable->Unk75(This->m_Unk36, 0);
                    This->m_Unk62 = 0;
                    This->m_Unk16 = 0xB;
                }
            } else {
                This->vtable->Unk11(This, 0xA);
            }
        } else if (This->m_Unk16 == 0xB) {
            dream_sys_t *sys;
            dream_sys_vtable_t *vt;

            link = 0;
            sys = This->m_Unk36;
            vt = sys->vtable;
            if (This->m_Unk2 != 0) {
                link = This->m_Unk4 + 0x38;
            }
            vt->Unk45(*(dream_sys_t *volatile *)&This->m_Unk36, link);
            if (This->m_Unk62 == 0x64) {
                This->vtable->Unk11(This, 0xA);
            }
        }
    }
    This->vtable->Unk48(This, -0x100, 0);
}

void func_80060CF0(entity_t *This, s32 *arg1) {
    s32 temp_a0;

    if (This->m_Unk62 < (This->m_Unk31 * 5)) {
        temp_a0 = This->m_Unk32;
        if ((temp_a0 == 0xF) || (temp_a0 == 0x46)) {
            arg1[4] = 0;
            arg1[7] = 7;
            arg1[12] = 7;
            arg1[17] = 7;
        }
    } else {
        This->vtable->Unk87(This);
        This->m_Unk16 = 1;
    }
}

void func_80060D80(entity_t *This, s32 *arg1) {
    s32 *ptr;
    s32 roll;
    s32 step;

    if (This->m_Unk62 == 0) {
        roll = rand();
        if ((roll % 5) == 0 && This->m_Unk16 == 0) {
            This->vtable->Unk17(This, 1, &D_80089E38);
            This->vtable->Unk50(This, 0x320, 0);
            This->m_Unk16 = 0xB;
        }
    }
    ptr = NULL;
    if ((arg1[1] % 5) == 0) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 8;
    }
    step = This->m_Unk62;
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

void func_80060F38(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->Unk81(This);
    temp = This->m_Unk62;
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
        This->vtable->Unk87(This);
        arg1[12] = 0x1E;
        This->m_Unk16 = 1;
    }
    This->vtable->Unk51(This, -0x200, 0);
}

void func_80061070(entity_t *This, s32 *arg1) {
    s32 var_s0;
    s32 r;

    var_s0 = This->m_Unk32;
    if (This->m_Unk62 == 0) {
        r = rand();
        if (r == ((r / 3) * 3)) {
            This->vtable->Unk17(This, 1, &D_80089E50);
        }
    }
    arg1[4] = This->vtable->Unk81(This);
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

void func_80061158(entity_t *This) {
    if ( !This->m_Unk62 ) {
        This->vtable->Unk50(This, -200, 0);
    }
}

void func_80061198(entity_t *This, s32 *arg1) {
    s32 step;
    s32 tick;

    if (This->m_Unk62 == 0) {
        This->m_Unk16 = rand() % 3;
        if (This->m_Unk16 == 0) {
            This->vtable->Unk75(This);
            This->vtable->Unk50(This, 0x1800, 0);
        }
    }
    arg1[4] = This->vtable->Unk81(This);
    if (This->m_Unk16 != 0) {
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
            if (entity_check_proximity(This, This->m_Unk4 + 24, 0xF, 0xA) != 0) {
                if (func_8005D108(This, NULL, NULL, 0xA, 0) != NULL) {
                    This->m_Class_305B0->vtable->Unk52(This->m_Class_305B0, This->m_Unk19, 4, 0);
                }
                if (rand() & 1) {
                    This->vtable->Unk11(This, 0xB);
                }
            }
            return;
        }
        if (step == 0x3B) {
            This->vtable->Unk87(This);
            This->m_Unk16 = 1;
        }
        return;
    }
    arg1[7] = 0xC;
    arg1[8] = -1;
    This->vtable->Unk48(This, -0x200, 0);
    tick = This->m_Unk62;
    if ((u32)(tick - 0x80) < 0xC2) {
        This->vtable->Unk50(This, -0x80, 0);
        return;
    }
    if (tick == 0x142) {
        This->vtable->Unk74(This);
        This->m_Unk16 = 1;
    }
}

void func_80061400(entity_t *This, s32 *arg1) {
    s32 state;

    if (This->m_Unk62 == 0) {
        s32 pose;

        pose = 0xC;
        arg1[4] = 0;
        arg1[7] = pose;
        if (This->m_Unk36->vtable->dream_sys__get_dream_color(This->m_Unk36) == 6) {
            This->m_Unk16 = 0xB;
        } else if ((rand() % 3) == 0) {
            This->m_Unk16 = pose;
        }
    }
    if ((arg1[1] % 100) == 0) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 0xC;
        arg1[8] = -1;
    }
    state = This->m_Unk16;
    if (state == 0xB) {
        if (This->vtable->entity_get_distance(This, This->m_Unk36) < 0x400) {
            This->m_Unk36->vtable->Unk75(This->m_Unk36, 0);
            This->m_Unk16 = 0xD;
            This->m_Unk62 = 0;
        }
    } else if (state == 0xC) {
        if (This->vtable->entity_get_distance(This, This->m_Unk36) < 0x400) {
            This->vtable->Unk75(This);
            This->m_Unk16 = 0xE;
            This->m_Unk62 = 0;
        }
    }
    state = This->m_Unk16;
    if (state == 0xD) {
        s32 tick;

        tick = This->m_Unk62;
        if (tick < 0x32) {
            This->m_Unk36->vtable->Unk50(This->m_Unk36, -0x14, 0);
        } else if (tick < 0x1F4) {
            dream_sys_t *dream;
            struct dream_sys_vtable *vt;
            s32 step;

            dream = This->m_Unk36;
            vt = dream->vtable;
            step = 5;
            if ((tick % 40) < 0x14) {
                step = -5;
            }
            vt->Unk49(dream, step, 0);
        } else if (tick == 0x1F4) {
            This->vtable->Unk11(This, 0xC);
        }
        state = This->m_Unk16;
    }
    if (state == 0xE) {
        s32 tick;

        tick = This->m_Unk62;
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
            This->m_Unk16 = 1;
        }
    }
}

void func_80061778(entity_t *This, s32 *arg1) {
    s32 tick;
    s32 nudge;

    if (This->m_Unk16 == 0) {
        if (func_8005E02C(This, 0x800) != 0) {
            This->m_Unk16 = 0xB;
            func_8001EACC(This, This->m_Unk36, 1, 0, 0);
            func_8001EACC(This->m_Unk36, This, 1, 1, 0);
            This->vtable->Unk86(This);
            This->vtable->Unk89(This);
            This->m_Unk36->vtable->Unk75(This->m_Unk36, 1);
            arg1[4] = 0;
            arg1[7] = 0xC;
            This->m_Unk62 = 0;
        }
        if (This->m_Unk16 == 0) {
            This->vtable->Unk87(This);
            This->vtable->Unk90(This);
            goto func_80061778_near;
        }
    }
    if ((arg1[1] % 100) == 0) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 0xC;
        arg1[8] = -1;
    }
    tick = This->m_Unk62;
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
            This->m_Unk16 = 0xC;
            This->vtable->Unk75(This);
        }
    } else if (tick == 0xF0) {
        This->m_Unk36->vtable->Unk76(This->m_Unk36, 1, 1);
    }
    if (This->m_Unk16 == 0xC) {
        tick = This->m_Unk62;
        if (tick < 0x82) {
            This->vtable->Unk50(This, 0xA, 0);
        } else if (tick < 0xA0) {
            This->vtable->Unk48(This, -0x1E, 0);
        } else if (tick >= 0x12D) {
            func_8001EACC(This, This->m_Unk36, 1, 0, 0);
            This->vtable->Unk48(This, -0x1E, 0);
        }
    }
func_80061778_near:
    if (This->vtable->entity_get_distance(This, This->m_Unk36) < 0x200) {
        This->vtable->Unk87(This);
        This->vtable->Unk11(This, 0xA);
    }
}

void func_80061A90(entity_t *This, s32 *arg1) {
    s32 r;
    s32 temp;

    if (This->m_Unk62 == 0) {
        r = rand();
        if (r == ((r / 10) * 10)) {
            This->m_Unk16 = 0xC;
        }
    }
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 0xC;
        arg1[8] = -1;
    }
    if (This->m_Unk62 == 0) {
        if (rand() & 1) {
            This->vtable->Unk50(This, 0x800, 0);
        }
    }
    This->vtable->Unk48(This, -0x80, 0);
    if ((This->m_Unk16 == 0xC) && (This->m_Unk62 == 0x12C)) {
        (*(void (**)(s32, s32, s32))(*(s32 *)This->m_Unk18 + 0x138))(This->m_Unk18, 1, 1);
    }
}

void func_80061C04(entity_t *This, s32 *Unk) {
    if (This->m_Unk32 == 30) {
        Unk[7] = 18;
        Unk[4] = 0;
        Unk[8] = -1;
    }
}

void func_80061C2C(entity_t *This, s32 *arg1) {
    s32 tick;
    s32 choice;
    entity_t *link;

    if ((This->m_Unk32 % 30) == 0) {
        arg1[7] = 3;
        arg1[4] = 0;
        arg1[8] = -2;
    }
    if (This->m_Unk62 >= 0x65) {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    }
    This->vtable->Unk48(This, -5, 0);
    tick = This->m_Unk62;
    if (tick == 0x12C) {
        if (This->vtable->entity_get_distance(This, This->m_Unk36) < 0x1000) {
            This->m_Unk36->vtable->Unk75(This->m_Unk36, 0);
            goto func_80061C2C_state;
        }
        tick = This->m_Unk62;
    }
    if (tick == 0x1F4) {
        This->m_Unk36->vtable->Unk76(This->m_Unk36, 1, 1);
    }
func_80061C2C_state:
    if (This->m_Unk16 == 0) {
        if (This->vtable->entity_get_distance(This, This->m_Unk36) < 0x400) {
            if (rand() & 1) {
                arg1[12] = 6;
                arg1[4] = 0;
                arg1[13] = -1;
                if (rand() & 1) {
                    link = (entity_t *)This->m_Unk18;
                    link->vtable->Unk77(link, -1, 0);
                }
                This->m_Unk62 = 0;
                This->m_Unk16 = 0xA;
            } else {
                This->m_Unk16 = 0xB;
            }
        }
    }
    if ((This->m_Unk16 == 0xA) && (This->m_Unk62 == 0x46)) {
        if (rand() & 1) {
            choice = 0xC;
        } else {
            choice = 0xB;
        }
        This->vtable->Unk11(This, choice);
    }
}

void func_80061E60(entity_t *This, s32 *arg1) {
    s32 rem;

    rem = arg1[1] % 300;
    arg1[4] = This->vtable->Unk81(This);
    if (rem < 0x14) {
        arg1[7] = 5;
        arg1[8] = -2;
    } else if (rem == 0x16) {
        arg1[7] = -2;
    }
    This->vtable->Unk48(This, -0xA, 0);
}

void func_80061F30(entity_t *This) {
    s32 r;

    if (This->m_Unk62 == 0) {
        r = rand();
        if (r == ((r / 3) * 3)) {
            This->vtable->Unk17(This, 1, &D_80089DD8);
            This->vtable->Unk50(This, -0x12C, 0);
            This->vtable->Unk16(This, 1, &D_80089C88);
            This->m_Unk16 = 0xB;
        }
    }
    if (This->m_Unk16 == 0xB) {
        if (This->m_Unk62 == 0x7D0) {
            This->vtable->Unk16(This, 0, &D_80089C94);
        }
        This->vtable->Unk48(This, -0x14, 0);
    }
}

void func_8006204C(entity_t *This, s32 *Unk) {
    Unk[4] = This->vtable->Unk81(This);
    if (Unk[1] == ((Unk[1] / 30) * 30)) {
        Unk[7] = 0xD;
    }
}

void func_800620C4(entity_t *This) {
    s32 r;

    if (This->m_Unk62 == 0) {
        r = rand();
        if (r == ((r / 3) * 3)) {
            This->m_Unk16 = 0xB;
        }
    }
    if (This->m_Unk16 == 0xB) {
        if (This->m_Unk62 == 0x1F6) {
            This->vtable->Unk50(This, 0x800, 0);
            func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        }
        if (This->m_Unk62 >= 0x1F5) {
            This->vtable->Unk48(This, -0x200, 0);
        }
    }
}

void func_800621A8(entity_t *This, s32 *arg1) {
    s32 nudge;

    arg1[4] = This->vtable->Unk81(This);
    if (arg1[1] == 0) {
        if (rand() & 1) {
            nudge = -0x176;
        } else {
            nudge = -0xC0;
        }
        *(s16 *)&This->m_Unk17 = nudge;
    }
    if (This->m_Unk16 == 0) {
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
        if ((This->m_Unk62 & 1) == 0) {
            if (This->m_Unk36->vtable->Unk63(This->m_Unk36) != 0) {
                This->m_Unk62 = -1;
                This->m_Unk16 = 0xA;
                arg1[7] = 0x12;
            }
        }
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        This->vtable->Unk48(This, *(s16 *)&This->m_Unk17, 1);
        return;
    }
    if (This->m_Unk16 == 0xA) {
        if (This->m_Unk62 < 8) {
            This->vtable->Unk16(This, 0, &D_80089CC4);
            This->vtable->Unk46(This, &D_80089D6C);
            return;
        }
        arg1[7] = 0x12;
        arg1[12] = 3;
        This->vtable->Unk90(This);
        This->m_Unk16 = ((u32)rand() % 2) == 0;
    }
}

void func_800623E8(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->Unk81(This);
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

void func_800624BC(entity_t *This) {
    s32 a1;
    s32 unk16;
    entity_vtable_t *vt;

    if ((This->m_Unk62 == 0) && (rand() & 1)) {
        This->m_Unk16 = 0xB;
    }
    if (This->m_Unk62 == 0x12C) {
        This->vtable->Unk16(This, 0, &D_80089C7C);
    }
    if (This->m_Unk62 < 0x258) {
        unk16 = This->m_Unk16;
        vt = This->vtable;
        a1 = 0x100;
        if (unk16 == 0) {
            a1 = -0x100;
        }
        vt->Unk48(This, a1, 0);
    }
}

void func_80062570(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->Unk81(This);
    if (arg1[1] == 0) {
        arg1[7] = 0;
        temp = rand() % 3;
        This->vtable->Unk49(This, temp * 0xC800, 0, temp);
    }
    if (This->m_Unk62 >= 0x961) {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    }
    This->vtable->Unk48(This, -0x1E, 0);
}

void func_80062660(entity_t *This, s32 *arg1) {
    arg1[4] = 0;
    if (arg1[1] == 0) {
        This->m_Unk36->vtable->Unk16(This->m_Unk36, 1, &D_80089C88);
        This->m_Unk36->vtable->Unk75(This->m_Unk36, 1);
        arg1[7] = 0x19;
        arg1[12] = 0x19;
        arg1[17] = 0x19;
    } else if (arg1[1] == 0x14) {
        arg1[12] = 0xD;
    }
    if (This->m_Unk62 == (This->m_Unk31 - 1)) {
        This->vtable->Unk87(This);
    }
}

void func_80062730(entity_t *This) {
    u32 temp;
    s32 half;
    s32 unk62;

    if (This->m_Unk62 == 0) {
        (*(void (**)(void *, void **))(*(s32 *)This->m_Unk36->m_Unk22 + 0x64))(
            (void *)This->m_Unk36->m_Unk22, (void **)&D_8008AC1C);
        This->m_Unk16 = rand() % 3;
        if (*(s32 *)((char *)This->m_Unk36->m_Unk4 + 0x20) < 0x262) {
            This->m_Unk16 = 0;
        }
    }
    if (This->m_Unk16 != 0) {
        temp = This->m_Unk31;
        half = ((s32)(temp + (temp >> 31))) >> 1;
        if (half < This->m_Unk62) {
            This->m_Unk36->vtable->Unk48(This->m_Unk36, 0x80, 0);
        }
        if (This->m_Unk62 == (This->m_Unk31 - 0x1E)) {
            This->vtable->Unk11(This, 0xA);
        }
    } else {
        unk62 = This->m_Unk62;
        if ((u32)(unk62 - 0x14) < 0x64U) {
            This->m_Unk36->vtable->Unk48(This->m_Unk36, -((unk62 - 0x13) << 5), 1);
            if (This->m_Unk62 == 0x55) {
                This->m_Unk36->vtable->Unk76(This->m_Unk36, 1, 1);
            }
        }
    }
}

void func_800628D4(entity_t *This, s32 *arg1) {
    if (arg1[1] == 0) {
        arg1[4] = 0;
        arg1[7] = 0x19;
        arg1[12] = 0x19;
        arg1[17] = 0x19;
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    }
    if (This->m_Unk62 == This->m_Unk31) {
        This->vtable->Unk75(This);
        This->vtable->Unk11(This, 0xA);
    }
}

void func_80062970(entity_t *This) {
    if (This->m_Unk60 != 0) {
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

void func_80062A40(entity_t *This, s32 *arg1) {
    s32 tick;

    arg1[4] = This->vtable->Unk81(This);
    if ((arg1[1] % 5) == 0) {
        arg1[7] = 0x11;
        arg1[8] = -2;
    }
    if (This->m_Unk30 == 0) {
        if (This->m_Unk62 == This->m_Unk31) {
            This->vtable->Unk73(This, 1);
            if (rand() & 1) {
                This->m_Unk16 = 0xB;
            }
        }
        return;
    }
    if (This->m_Unk16 == 0) {
        tick = This->m_Unk62;
        if ((tick == 0x3C) || (tick == 0xD4) || (tick == 0x122) || (tick == 0x140)) {
            This->vtable->Unk16(This, 0, &D_80089C88);
            tick = This->m_Unk62;
        }
        if (tick == 0x18E) {
            This->vtable->Unk16(This, 0, &D_80089C94);
        }
        This->vtable->Unk51(This, -0x32, 0);
        return;
    }
    tick = This->m_Unk62;
    if ((tick == 0x3C) || (tick == 0x8C)) {
        This->vtable->Unk16(This, 0, &D_80089C88);
    }
    if (This->m_Unk62 < 0xAE) {
        This->vtable->Unk51(This, -0x32, 0);
    }
    if (This->m_Unk62 == 0xAE) {
        This->vtable->Unk90(This);
        This->m_Unk16 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/entity", func_80062C58);

void func_80062FAC(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->Unk81(This);
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[7] = 0x19;
        arg1[8] = 2;
    }
    This->vtable->Unk16(This, 0, &D_80089CA0);
    if ((This->m_Unk16 == 0) && (This->m_Unk60 != 0)) {
        This->vtable->Unk11(This, 0xB);
        This->m_Unk16 = 0xB;
    }
}

void func_80063094(entity_t *This, s32 *arg1) {
    if (This->m_Unk62 < This->m_Unk31) {
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
    func_8001EACC(This, This->m_Unk36, 1, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_80063144);

void func_800634A8(entity_t *This, s32 *arg1) {
    s32 state;

    if ((This->m_Unk16 == 0) && (This->m_Unk62 == 0)) {
        if ((rand() % 3) != 0) {
            if (rand() & 1) {
                state = 0xB;
            } else {
                state = 0xC;
            }
            This->m_Unk16 = state;
        } else {
            This->vtable->Unk90(This);
            This->vtable->Unk48(This, -0x5000, 0);
            rand();
        }
    }
    if (This->m_Unk16 == 0xC) {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        if (This->m_Unk62 == 0x14) {
            arg1[7] = 0x12;
            arg1[4] = 0;
            arg1[12] = 3;
            This->m_Unk36->vtable->Unk75(This->m_Unk36, 1);
        }
        if (This->m_Unk62 >= 0x15) {
            This->vtable->Unk48(This, -0x28, 0);
        }
        if (This->m_Unk62 == 0x28) {
            This->vtable->Unk11(This, 0xA);
        }
    } else if (This->m_Unk16 == 0xB) {
        This->vtable->Unk75(This);
        if (This->vtable->entity_get_distance(This, This->m_Unk36) < 0x200) {
            if ((rand() % 3) != 0) {
                This->vtable->Unk87(This);
            } else {
                This->vtable->Unk90(This);
            }
        }
    }
}

void func_800636E4(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = This->m_Unk32;
    if (temp == ((temp / 15) * 15)) {
        arg1[7] = 0xC;
        arg1[4] = 0;
        arg1[8] = 2;
    }
    if (This->m_Unk62 == This->m_Unk31) {
        arg1[7] = -2;
        This->vtable->Unk90(This);
        This->m_Unk16 = 1;
    }
}

void func_80063784(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->Unk81(This);
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
        This->vtable->Unk90(This);
        This->m_Unk16 = 1;
    }
}

void func_80063874(entity_t *This, entity_t *arg1) {
    s32 tick;

    if (This->m_Unk16 == 0) {
        if (This->m_Unk32 == 5) {
            func_80063C84(arg1);
        }
        if (This->m_Unk62 == This->m_Unk31) {
            This->vtable->Unk75(This);
            This->m_Unk16 = 0xA;
            This->m_Unk62 = -1;
        }
        return;
    }
    if (This->m_Unk16 == 0xA) {
        if (This->m_Unk62 < 0xA) {
            This->vtable->Unk16(This, 0, &D_80089C64);
            if (This->m_Unk36->vtable->Unk63(This->m_Unk36) == 0) {
                return;
            }
            func_80063C84(arg1);
            This->m_Unk16 = 0xC;
            This->m_Unk62 = -1;
            return;
        }
        This->m_Unk36->vtable->Unk75(This->m_Unk36, 1);
        This->m_Unk16 = 0xB;
        This->m_Unk62 = -1;
        return;
    }
    if (This->m_Unk16 == 0xB) {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        if (This->m_Unk62 < 0x1E) {
            This->vtable->Unk48(This, -0xA, 0);
            return;
        }
        func_80063C84(arg1);
        if (func_8005D108(This, NULL, NULL, 0x1E, 0) != NULL) {
            This->m_Class_305B0->vtable->Unk52(This->m_Class_305B0, This->m_Unk19, 7, 0);
        }
        This->m_Unk16 = 0xD;
        This->m_Unk62 = -1;
        return;
    }
    if (This->m_Unk16 == 0xD) {
        tick = This->m_Unk62;
        if (tick < 0x5A) {
            if (tick == 0x1E) {
                if (func_8005D108(This, NULL, NULL, 0xA, 0) != NULL) {
                    This->m_Class_305B0->vtable->Unk53(This->m_Class_305B0, This->m_Unk19, 0, 0);
                }
            }
            This->m_Unk36->vtable->Unk16(This->m_Unk36, 0, &D_80089CD0);
            return;
        }
        func_80063CAC(arg1);
        This->m_Unk36->vtable->Unk16(This->m_Unk36, 1, &D_80089C7C);
        This->vtable->Unk11(This, (rand() % 5) != 0 ? 0xA : 0xC);
        This->m_Unk16 = 0xE;
        return;
    }
    if (This->m_Unk16 == 0xC) {
        if (This->m_Unk62 < 0xA) {
            This->vtable->Unk16(This, 0, &D_80089CDC);
            return;
        }
        func_80063CAC(arg1);
        This->vtable->Unk90(This);
        This->m_Unk16 = 1;
    }
}

void func_80063BC0(entity_t *This, s32 *arg1) {
    if (This->m_Unk62 < 0xA) {
        This->vtable->Unk75(This);
    } else if (This->m_Unk62 == 0xA) {
        This->vtable->Unk74(This);
    }
    if (This->m_Unk32 == 0xA) {
        func_80063CAC((entity_t *)arg1);
    }
    if (This->m_Unk62 == (This->m_Unk31 + 0xA)) {
        This->vtable->Unk90(This);
        This->m_Unk16 = 1;
    }
}

void func_80063C84(entity_t *This) {
    This->m_Unk3 = 0;
    This->m_Unk6 = 7;
    This->m_Unk7 = -2;
    This->m_Unk11 = 7;
    This->m_Unk12 = -2;
    This->m_Unk16 = 7;
    This->m_Unk17 = -2;
}

void func_80063CAC(entity_t *This) {
    This->m_Unk6 = 18;
    This->m_Unk3 = 0;
    This->m_Unk11 = 3;
    This->m_Unk16 = 3;
}

void func_80063CC8(entity_t *This, s32 *arg1) {
    s32 temp_v0;

    temp_v0 = This->vtable->Unk81(This);
    arg1[4] = temp_v0;
    if (arg1[1] == 0) {
        arg1[7] = 0x12;
    }
    if (arg1[1] >= (This->m_Unk31 - 1)) {
        arg1[1] = -1;
    }
}

void func_80063D40(entity_t *This, s32 *arg1) {
    arg1[4] = This->vtable->Unk81(This);
    if (arg1[1] == (This->m_Unk31 / 2)) {
        arg1[7] = 0x12;
    }
    if (arg1[1] >= (This->m_Unk31 - 1)) {
        arg1[1] = -1;
    }
}

void func_80063DC8(entity_t *This, s32 *arg1) {
    s32 temp_v1;

    temp_v1 = This->m_Unk62;
    if (temp_v1 == 0x14) {
        arg1[7] = 0x12;
        arg1[4] = 0;
        arg1[12] = 3;
        return;
    }
    if (temp_v1 == This->m_Unk31) {
        This->vtable->Unk90(This);
        This->m_Unk16 = 1;
        if (rand() & 1) {
            This->vtable->Unk11(This, 0xB);
        }
    }
}

void func_80063E68(entity_t *This, s32 *arg1) {
    s32 v;

    arg1[4] = This->vtable->Unk81(This);
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

void func_80063ED4(entity_t *This, s32 *arg1) {
    class_305B0_t *child;

    if (This->m_Unk62 == 0) {
        if (func_8005D108(This, NULL, NULL, 5, 0) != NULL) {
            if (rand() & 1) {
                This->vtable->Unk46(This, &D_80089D90);
            }
            child = This->m_Class_305B0;
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
        This->m_Unk36->vtable->Unk75(This->m_Unk36, 1);
    }
    if (This->m_Unk62 == 0x32) {
        This->vtable->Unk11(This, 0xA);
    } else if (This->m_Unk62 == 0xC) {
        arg1[4] = 0;
        arg1[7] = 0x15;
    }
    This->vtable->Unk17(This, 1, &D_80089DE4);
}

void func_80064078(entity_t *This, s32 *arg1) {
    if (This->m_Unk30 == 0) {
        if (This->m_Unk60 != 0) {
            func_8001EACC(This, This->m_Unk36, 1, 0, 0);
            This->vtable->Unk73(This, 1);
            This->m_Unk36->vtable->Unk75(This->m_Unk36, 1);
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
        This->vtable->Unk11(This, 0xA);
    }
    This->vtable->Unk17(This, 1, &D_80089DE4);
}

void func_800641C0(entity_t *This, s32 *arg1) {
    s32 temp;

    arg1[4] = This->vtable->Unk81(This);
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[7] = 3;
    }
    if (This->m_Unk62 == This->m_Unk31) {
        This->vtable->Unk73(This, 1);
    }
    if (This->m_Unk30 == 1) {
        This->vtable->Unk48(This, -0x80, 1);
    }
}

void func_80064294(entity_t *This, s32 *arg1) {
    s32 temp;
    s32 r;

    if (This->m_Unk62 == 0) {
        if (This->m_Unk36->vtable->dream_sys__get_dream_color(This->m_Unk36) != 7) {
            This->m_Unk16 = 0xB;
        }
    }
    arg1[4] = This->vtable->Unk81(This);
    temp = arg1[1];
    if (temp == ((temp / 10) * 10)) {
        arg1[7] = 0xE;
    }
    if (This->m_Unk62 == This->m_Unk31) {
        This->vtable->Unk73(This, 1);
        if ((This->m_Unk16 != 0) && !(rand() & 1)) {
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

void func_80064450(entity_t *This) {
    if (This->m_Unk62 == 0) {
        This->vtable->Unk73(This, 3);
    } else if (This->m_Unk62 == This->m_Unk31) {
        This->vtable->Unk73(This, 1);
    }
    if (This->m_Unk30 == 1) {
        This->vtable->Unk48(This, -0x80, 0);
    }
}

void func_800644E8(entity_t *This, s32 *arg1) {
    s32 temp;

    temp = This->m_Unk62;
    if (temp == 0) {
        This->vtable->Unk73(This, rand() % 4);
        return;
    }
    if ((temp % This->m_Unk31) == 0) {
        This->vtable->Unk73(This, rand() % 4);
        arg1[4] = This->vtable->Unk81(This);
        arg1[7] = 0x16;
        arg1[8] = 2;
        arg1[9] = 0x40;
        arg1[10] = 0x20;
    }
}

void func_80064618(entity_t *This) {
    if (This->m_Unk60 != 0) {
        if (func_8005D108(This, NULL, NULL, 0xA, 0) != NULL) {
            This->m_Class_305B0->vtable->Unk52(
                This->m_Class_305B0, This->m_Unk19, 7, 0);
            This->vtable->Unk87(This);
            This->m_Unk36->vtable->dream_sys__reset_flashback_list(This->m_Unk36);
        }
    }
    This->vtable->Unk48(This, -0x1E, 1);
}

void func_800646D8(entity_t *This, s32 *arg1) {
    s32 *ptr;
    u32 utemp;
    s32 half;
    s32 unk62;

    if (This->m_Unk62 == 0) {
        This->vtable->Unk50(This, -0x200, 0);
    }
    arg1[4] = This->vtable->Unk81(This);
    utemp = This->m_Unk31;
    half = ((s32)(utemp + (utemp >> 31))) >> 1;
    if (This->m_Unk32 == half) {
        arg1[7] = 7;
        arg1[8] = -2;
        arg1[12] = 3;
        arg1[13] = -2;
    }
    if (This->m_Unk62 >= 0x33) {
        This->vtable->Unk16(This, 0, &D_80089CAC);
    }
    if (This->m_Unk62 >= 0x30D) {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        unk62 = This->m_Unk62;
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
        if (This->m_Unk62 < 0x7D0) {
            This->vtable->Unk48(This, -0x40, 0);
        } else {
            This->m_Unk16 = 1;
        }
    } else {
        This->vtable->Unk48(This, -0x100, 0);
    }
    if ((This->m_Unk60 != 0) && (This->m_Unk16 == 0)) {
        This->m_Unk16 = 0xC;
        This->m_Unk36->vtable->Unk75(This->m_Unk36, 1);
        This->vtable->Unk11(This, 0xA);
    }
    if (This->m_Unk16 == 0xC) {
        This->m_Unk36->vtable->Unk48(This->m_Unk36, 0x100, 0);
    }
}

void func_80064928(entity_t *This) {
    s32 count;
    entity_t *child;

    count = This->m_Unk62;
    if (count != 0x2BC) {
        goto check16;
    }
    if ((rand() % 3) != 0) {
        goto check16;
    }
    This->m_Unk16 = 0xB;
check16:
    if (This->m_Unk16 != 0xB) {
        goto other;
    }
    if (This->m_Unk62 < 0x3FC) {
        This->vtable->Unk16(This, 0, &D_80089CB8);
        This->vtable->Unk50(This, 0x1E, 0);
    }
    if (This->m_Unk62 != 0x3A2) {
        goto tail;
    }
    This->vtable->Unk11(This, 0xA);
    goto tail;
other:
    count = This->m_Unk62;
    if (count == 0x64 || count == 0x320) {
        if ((rand() % 5) == 0) {
            child = (entity_t *)This->m_Unk18;
            child->vtable->Unk77(child, 4, 0);
        }
    }
tail:
    This->vtable->Unk48(This, -0x1E, 0);
}

void func_80064AA4(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DCC);
    if ((u32)(This->m_Unk62 - 0xC9) < 0x63U) {
        This->vtable->Unk50(This, -0x20, 0);
    }
}

void func_80064B14(entity_t *This) {
    This->vtable->Unk23(This, (rand() % 20) == 0);
}

void func_80064B80(entity_t *This) {
    s32 count;

    if (This->m_Unk62 == 0) {
        if ((rand() & 1) == 0) {
            This->m_Unk16 = 0xB;
        }
    }
    if (This->m_Unk16 == 0xB) {
        if (This->m_Unk62 == 0) {
            This->vtable->Unk75(This);
        }
        This->vtable->Unk17(This, 1, &D_80089E2C);
    } else {
        if (This->m_Unk62 == 0) {
            This->vtable->Unk73(This, 1);
        }
        count = This->m_Unk62;
        This->vtable->Unk49(This, (count % 20) < 10 ? 0x20 : -0x20, 0);
    }
}

void func_80064CA4(entity_t *This) {
    func_80062570();
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void func_80064CEC(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DD8);
    This->vtable->Unk48(This, -0xA, 0);
}

void func_80064D48(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E44);
    This->vtable->Unk75(This);
    if ((This->m_Unk16 == 0) && (This->vtable->entity_get_distance(This, This->m_Unk36) < 0x800)) {
        This->m_Unk16 = 0xA;
        This->m_Unk62 = 0;
    }
    if (This->m_Unk16 == 0xA) {
        if (This->m_Unk62 < 0x2D) {
            This->vtable->Unk16(This, 0, &D_80089D00);
        }
        if (This->m_Unk62 >= 0x1F5) {
            This->m_Unk16 = 0;
        }
    }
}

void func_80064E34(entity_t *This, s32 *arg1) {
    s32 temp;

    if (This->m_Unk62 == 0) {
        if (This->m_Unk36->vtable->dream_sys__get_dream_color(This->m_Unk36) == 5) {
            This->m_Unk16 = 0xB;
        }
    }
    if ((This->m_Unk16 != 0) && (This->m_Unk62 >= 0x870)) {
        temp = This->m_Unk62;
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
            func_80064FBC(This, arg1, 0x1E1, 0xFA0, -0x3C);
        }
    } else {
        func_80064FBC(This, arg1, 0x1E1, 0x884, -0x3C);
    }
}

void func_80064FBC(entity_t *This, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp;

    arg1[4] = 0;
    if (arg1[1] == 6) {
        arg1[7] = 4;
        arg1[12] = 4;
        arg1[17] = 4;
    }
    temp = This->m_Unk62;
    if (((temp >= arg2) && (temp <= (arg2 + 0x5B))) ||
        ((temp >= (arg2 + 0x155)) && (temp <= (arg2 + 0x1B1))) ||
        ((temp >= (arg2 + 0x2BA)) && (temp <= (arg2 + 0x317)))) {
        This->vtable->Unk16(This, 0, &D_80089D18);
    }
    This->vtable->Unk48(This, arg4, 0);
    if (This->m_Unk62 == arg3) {
        This->vtable->Unk87(This);
        This->m_Unk16 = 1;
    }
}

void func_800650D4(entity_t *This, void *Unk) {
    func_80060D80(This, Unk);
}

void func_800650F4(entity_t *This) {
    if ((rand() % 3) == 0) {
        return;
    }
    This->vtable->Unk16(This, 0, (rand() % 3) != 0 ? &D_80089C64 : &D_80089C70);
}

void func_8006519C(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void func_800651D0(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void func_80065204(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DCC);
}

void func_80065238(entity_t *This) {
    s32 r;

    if (This->m_Unk62 == 0) {
        r = rand();
        if (r == ((r / 5) * 5)) {
            This->m_Unk16 = 0xB;
        }
    }
    This->vtable->Unk75(This);
    This->vtable->Unk48(This, 0x64, 0);
    if (This->m_Unk62 == 0x3E8) {
        This->vtable->Unk90(This);
        This->m_Unk16 = 1;
    }
    if ((This->m_Unk16 == 0xB) && (This->m_Unk62 >= 0x12D)) {
        This->m_Unk36->vtable->set_move_from_pad(This->m_Unk36, 0, 2);
        This->m_Unk36->vtable->set_move_from_pad(This->m_Unk36, 0, 7);
    }
}

void func_8006536C(entity_t *This, s32 *arg1) {
    u32 temp;
    s32 half;

    if (((This->m_Unk62 == 0) && !(rand() & 3)) || (This->m_Unk62 == 0xE10)) {
        This->vtable->Unk87(This);
        This->m_Unk16 = 1;
    }
    This->vtable->Unk17(This, 1, &D_80089E44);
    arg1[4] = This->vtable->Unk81(This);
    temp = This->m_Unk31;
    half = ((s32)(temp + (temp >> 31))) >> 1;
    if ((arg1[1] % half) == 0) {
        arg1[7] = 0xA;
        arg1[8] = 1;
    }
    This->vtable->Unk48(This, -0xA, 0);
}

void func_800654A0(entity_t *This) {
    func_8001EACC(This, This->m_Unk36, 1, 0, 0);
    This->vtable->Unk17(This, 1, &D_80089E80);
    This->vtable->Unk48(This, -0x1E, 1);
}

void func_80065514(entity_t *This) {
    u32 r;
    s32 rem;

    if (This->m_Unk62 == 0) {
        r = rand();
        rem = (s32)(r + (r >> 31)) >> 1;
        This->m_Unk16 = 0xA + (s32)(r - (rem << 1));
    }
    This->vtable->Unk75(This);
    if (This->m_Unk62 >= 0xC9) {
        func_8001EACC(This, This->m_Unk36, 1, 0, 0);
        if (This->m_Unk16 == 0xA) {
            This->vtable->Unk51(This, -0x200, 0);
        }
    }
}
