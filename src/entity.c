#include "entity.h"
#include "55DD4.h"

extern entity_vtable_t g_ENTITY_VTABLE;

extern s32 D_80089DCC;
extern s32 D_80089DD8;
extern s32 D_80089E38;
extern void *D_8008AC14;
extern void *D_8008AC0C;

extern entity_prop_t g_ENTITY_TABLE[];

void func_8005DF9C(entity_t *This, s32 Unk2);
s32 entity_check_proximity(entity_t *This, vec3d_t *Location, s32 Unk3, s32 Unk4);

entity_t *entity_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    entity_t *allocated = (entity_t *) memory_allocate_mem(0x108);

    if (allocated) {
        if (entity_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3) == NULL) {
            memory_free_mem(allocated);
            return NULL;
        }

        return allocated;
    }

    return NULL;
}

entity_vtable_t *entity_construct(entity_t *This, s32 EntityID, s32 Unk3, s32 Unk4) {
    if (class_55DD4_get_vtable()->Construct(This, Unk3, Unk4)) {
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
        This->m_Class_305B0->vtable->Destroy(This->m_Class_305B0);
    }

    if (This->m_Unk64) {
        (*(void (**)(s32))(*(s32 *) This->m_Unk64 + 4))(This->m_Unk64);
    }

    class_55DD4_get_vtable()->Cleanup(This);
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

    return (*(s32(**)(s32, s32, s32, s32 *, s32))(*(s32 *) This->m_Unk36 + 288))(This->m_Unk36, call_arg_1, call_arg_2,
                                                                                 &local_data, Unk4);
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
        s32 vcall_result = This->vtable->Unk80(This, This->m_Unk36);
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

    ptr_from_unk36 = (void *) This->m_Unk36;
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
            ((s32(*)(entity_t *, void *, s32))(*(void **) ((char *) This->vtable + 0x144)))(This, ptr_from_unk36, v2);

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

INCLUDE_ASM("asm/nonmatchings/entity", func_8005E160);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005E3C4);

void func_8005E480(entity_t *This, s32 *Unk) {
    s32 v2; // $v0
  s32 v4; // $v1

  v2 = This->vtable->Unk81(This);
  v4 = Unk[1];
  Unk[4] = v2;
  if ( !v4 )
    Unk[7] = 23;
}

INCLUDE_ASM("asm/nonmatchings/entity", func_8005E4D0);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005E694);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005E6F0);

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

INCLUDE_ASM("asm/nonmatchings/entity", func_8005E7F8);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005EA94);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005EBB4);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005EC98);

void func_8005ED10(entity_t *This, s32 *Unk) {
    if (!This->m_Unk62) {
        Unk[4] = 0;
        Unk[7] = 15;
    }
}

INCLUDE_ASM("asm/nonmatchings/entity", func_8005ED30);

void func_8005EF20(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DD8);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_8005EF54);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005EFF4);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005F0D8);

void func_8005F1A8(entity_t *This) {
    func_8001EACC(This, This->m_Unk36, 1, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_8005F1D4);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005F368);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005F454);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005F544);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005F608);

void func_8005F6D4(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E38);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_8005F708);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005F800);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005F970);

void func_8005FA64(entity_t *This) {
    This->vtable->Unk48(This, -30, 0);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_8005FA94);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005FB6C);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005FC58);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005FDFC);

void func_8005FEC8(entity_t *This) {
    This->vtable->Unk50(This, -90, 0);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_8005FEF8);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005FF7C);

INCLUDE_ASM("asm/nonmatchings/entity", func_80060148);

INCLUDE_ASM("asm/nonmatchings/entity", func_800602AC);

INCLUDE_ASM("asm/nonmatchings/entity", func_800603C4);

INCLUDE_ASM("asm/nonmatchings/entity", func_800604DC);

INCLUDE_ASM("asm/nonmatchings/entity", func_800605D0);

INCLUDE_ASM("asm/nonmatchings/entity", func_80060710);

void func_800607F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/entity", func_80060800);

INCLUDE_ASM("asm/nonmatchings/entity", func_8006090C);

INCLUDE_ASM("asm/nonmatchings/entity", func_80060A4C);

INCLUDE_ASM("asm/nonmatchings/entity", func_80060B34);

INCLUDE_ASM("asm/nonmatchings/entity", func_80060CF0);

INCLUDE_ASM("asm/nonmatchings/entity", func_80060D80);

INCLUDE_ASM("asm/nonmatchings/entity", func_80060F38);

INCLUDE_ASM("asm/nonmatchings/entity", func_80061070);

void func_80061158(entity_t *This) {
    if ( !This->m_Unk62 ) {
        This->vtable->Unk50(This, -200, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/entity", func_80061198);

INCLUDE_ASM("asm/nonmatchings/entity", func_80061400);

INCLUDE_ASM("asm/nonmatchings/entity", func_80061778);

INCLUDE_ASM("asm/nonmatchings/entity", func_80061A90);

void func_80061C04(entity_t *This, s32 *Unk) {
    if (This->m_Unk32 == 30) {
        Unk[7] = 18;
        Unk[4] = 0;
        Unk[8] = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/entity", func_80061C2C);

INCLUDE_ASM("asm/nonmatchings/entity", func_80061E60);

INCLUDE_ASM("asm/nonmatchings/entity", func_80061F30);

INCLUDE_ASM("asm/nonmatchings/entity", func_8006204C);

INCLUDE_ASM("asm/nonmatchings/entity", func_800620C4);

INCLUDE_ASM("asm/nonmatchings/entity", func_800621A8);

INCLUDE_ASM("asm/nonmatchings/entity", func_800623E8);

INCLUDE_ASM("asm/nonmatchings/entity", func_800624BC);

INCLUDE_ASM("asm/nonmatchings/entity", func_80062570);

INCLUDE_ASM("asm/nonmatchings/entity", func_80062660);

INCLUDE_ASM("asm/nonmatchings/entity", func_80062730);

INCLUDE_ASM("asm/nonmatchings/entity", func_800628D4);

INCLUDE_ASM("asm/nonmatchings/entity", func_80062970);

INCLUDE_ASM("asm/nonmatchings/entity", func_80062A40);

INCLUDE_ASM("asm/nonmatchings/entity", func_80062C58);

INCLUDE_ASM("asm/nonmatchings/entity", func_80062FAC);

INCLUDE_ASM("asm/nonmatchings/entity", func_80063094);

INCLUDE_ASM("asm/nonmatchings/entity", func_80063144);

INCLUDE_ASM("asm/nonmatchings/entity", func_800634A8);

INCLUDE_ASM("asm/nonmatchings/entity", func_800636E4);

INCLUDE_ASM("asm/nonmatchings/entity", func_80063784);

INCLUDE_ASM("asm/nonmatchings/entity", func_80063874);

INCLUDE_ASM("asm/nonmatchings/entity", func_80063BC0);

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

INCLUDE_ASM("asm/nonmatchings/entity", func_80063CC8);

INCLUDE_ASM("asm/nonmatchings/entity", func_80063D40);

INCLUDE_ASM("asm/nonmatchings/entity", func_80063DC8);

INCLUDE_ASM("asm/nonmatchings/entity", func_80063E68);

INCLUDE_ASM("asm/nonmatchings/entity", func_80063ED4);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064078);

INCLUDE_ASM("asm/nonmatchings/entity", func_800641C0);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064294);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064450);

INCLUDE_ASM("asm/nonmatchings/entity", func_800644E8);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064618);

INCLUDE_ASM("asm/nonmatchings/entity", func_800646D8);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064928);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064AA4);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064B14);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064B80);

void func_80064CA4(entity_t *This) {
    func_80062570();
    This->vtable->Unk17(This, 1, &D_80089E38);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_80064CEC);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064D48);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064E34);

INCLUDE_ASM("asm/nonmatchings/entity", func_80064FBC);

void func_800650D4(entity_t *This, void *Unk) {
    func_80060D80(This, Unk);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_800650F4);

void func_8006519C(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void func_800651D0(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089E38);
}

void func_80065204(entity_t *This) {
    This->vtable->Unk17(This, 1, &D_80089DCC);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_80065238);

INCLUDE_ASM("asm/nonmatchings/entity", func_8006536C);

INCLUDE_ASM("asm/nonmatchings/entity", func_800654A0);

INCLUDE_ASM("asm/nonmatchings/entity", func_80065514);
