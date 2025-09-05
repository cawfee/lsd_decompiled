#include "entity.h"
#include "55DD4.h"

extern entity_vtable_t g_ENTITY_VTABLE;

extern void *D_8008AC14;
extern void *D_8008AC0C;
extern s8 D_80089EAB[];
extern s8 D_80089EAC[];
extern s8 D_80089EA4[];
extern s8 D_80089EA6[];
extern s8 D_80089EAE[];
extern s32 D_80089EB0[];

void func_8005DF9C(entity_t *This, s32 Unk2);
s32 func_8005D714(void *This, vec3d_t *data, s32 arg2, s32 arg3);

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

entity_vtable_t *entity_construct(entity_t *This, s32 Unk2, s32 Unk3, s32 Unk4) {
    if (class_55DD4_get_vtable()->Construct(This, Unk3, Unk4)) {
        This->vtable = entity_get_vtable();
        This->m_Unk37 = Unk2;
        This->m_Unk38 = 0;
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

void func_8005D1EC(entity_t *This) {
    if (This->m_Class_305B0) {
        This->m_Class_305B0->vtable->Destroy(This->m_Class_305B0);
    }

    if (This->m_Unk64) {
        (*(void (**)(s32))(*(s32 *) This->m_Unk64 + 4))(This->m_Unk64);
    }

    class_55DD4_get_vtable()->Cleanup(This);
}

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D278);

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D314);

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

INCLUDE_ASM("asm/nonmatchings/entity", func_8005D560);

void func_8005D658(entity_t *This, s32 Unk2, s32 Unk3) {
    class_55DD4_get_vtable()->Unk55(This, Unk2, Unk3);
    if (Unk3 == 4) {
        This->vtable->Unk87(This);
    }
}

void func_8005D6D4(entity_t *This) {
    func_8002CD08(This->m_Unk21, &This->m_Unk38);
    ++This->m_Unk62;
}

// https://decomp.me/scratch/N3lft
s32 func_8005D714(void *This, vec3d_t *data, s32 arg2, s32 arg3) {
    vec3d_t local_data;
    s8 byte_val;

    // This struct copy generates the exact function prologue, including the
    // `move t1, a0` to save the `this` pointer from register pressure.
    local_data = *data;

    // Access member at offset 0x98 using pointer arithmetic.
    byte_val = D_80089EA6[*(s32 *) ((u8 *) This + 0x98) * 16];

    // This condition checks if `byte_val` is in the signed range [-9, -1].
    if ((u8) (byte_val + 9) < 9) {
        // Sign-extended left shift, matching the `sll`/`sra` pair.
        local_data.y += (s32) byte_val << 10;
    }

    // Modify `arg3` in-place to ensure the result ends up in the $a3 register.
    if (arg3 < 0) {
        // The `(~x) + 1` idiom generates the target's `nor`/`addiu` negation.
        arg3 = 2048 / ((~arg3) + 1);
    } else {
        arg3 = arg3 << 11;
    }

    // --- The Virtual Call ---
    {
        // By pre-calculating these arguments, we make them available to the
        // instruction scheduler. The scheduler can then use these independent
        // operations to fill the load-delay slots of the subsequent memory fetches.
        s32 call_arg_1 = 0;
        s32 call_arg_2 = arg2 << 11;

        // This complex, single expression resolves the function pointer via the vtable.
        // It is cast and called in the same statement.
        return ((s32(*)(void *, s32, s32, void *, s32))(*((void ***) (*(void **) ((u8 *) This + 0x94))))[0x120 / 4])(
            // Arg 0: Re-evaluate to force the `lw a0, 0x94(t1)` instruction.
            *(void **) ((u8 *) This + 0x94),
            // Args 1 & 2: Use the pre-calculated local variables.
            call_arg_1, call_arg_2,
            // Arg 3: The address of the stack variable, which the compiler
            // will place into $a3 during the `jalr` delay slot.
            &local_data,
            // Arg 4: The modified arg3, passed on the stack.
            arg3);
    }
}

s32 func_8005D7FC(entity_t *This, void *a1) {
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
        s32 array_val_shifted = (s32) D_80089EAE[This->m_Unk37 * 16] << 11;

        if (array_val_shifted >= vcall_result) {
            s32 temp_quotient = array_val_shifted / This->m_Unk43;

            return vcall_result / temp_quotient;
        }
    }

    return -1;
}

s8 *entity_get_mood_effect(entity_t *This) {
    return &D_80089EA4[16 * This->m_Unk37];
}

s32 entity_get_unlock_effect(entity_t *This) {
    return 1000 * D_80089EA6[16 * This->m_Unk37];
}

s32 entity_get_link_stage(entity_t *This) {
    s8 val = D_80089EAB[This->m_Unk37 * 16];

    if (val < 0) {
        return ~val;
    } else {
        return val - 1;
    }
}

s32 entity_get_event_video(entity_t *This) {
    return D_80089EAC[This->m_Unk37 * 16] - 1;
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
    func_8002CC34(This->m_Unk21, &This->m_Unk38, This->m_Unk37 + 1, This, D_80089EB0[This->m_Unk37 * 4]);

    This->vtable->Unk74(This);
    This->vtable->Unk67(This);

    This->m_Unk62 = 0;
    This->m_Unk61 = 1;
}

void func_8005DB8C(entity_t *This) {
    func_8002CC84(This->m_Unk21, &This->m_Unk38);
    This->vtable->Unk75(This);
    This->vtable->Unk68(This);
    This->m_Unk61 = 0;
}

s32 func_8005DBF0(entity_t *This) {
    if (This->m_Unk59 == 0 && This->m_Unk16 != 1) {
        s8 *p = &D_80089EA4[This->m_Unk37 * 16];
        s32 flag = 0;
        s8 p3;

        p3 = p[3];
        if (p3 == 0) {
            goto end_logic;
        }
        if (p3 == 4) {
            goto rand_check;
        }
        if (p[5] == 0) {
            goto end_logic;
        }

        if (func_8005D714(This, This->m_Unk4 + 24, p[5], p[9]) == 0) {
            goto func_returned_zero;
        }

        p3 = p[3];
        if (p3 == 1) {
            flag = 1;
            goto end_logic;
        } else if (p3 == 3) {
            goto rand_check;
        } else {
            goto end_logic;
        }

    func_returned_zero:
        if (p[3] != 2) {
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

        data_ptr = &D_80089EA4[This->m_Unk37 * 16];
        func_8005DF9C(This, 0);

        should_call = 0;

        if ((data_ptr[4] != 0) && (data_ptr[4] != 3)) {
            if (data_ptr[4] >= 10) {
                should_call = (This->m_Unk8 == (data_ptr[4] * 15));
            } else {
                s8 val5 = ((s8 *) data_ptr)[5];

                if (val5 != 0) {
                    s8 val9 = ((s8 *) data_ptr)[9];

                    if (func_8005D714(This, This->m_Unk4 + 24, val5, val9) != 0) {
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
    s8 *v2;
    s32 val;

    v2 = &D_80089EA4[this->m_Unk37 * 16];

    if (this->m_Unk59 != 0) {
        if (this->m_Unk60 == 0) {
            s32 func_arg1 = this->m_Unk4 + 24;

            val = v2[6];

            if (val < 0) {
                val = ~val + 1;
            }

            if (func_8005D714(this, func_arg1, val, v2[9]) != 0) {
                this->vtable->Unk88(this, 1);
            }
        }

        if ((s8) v2[6] < 0) {
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
            s8 *p = &D_80089EA4[This->m_Unk37 * 16];
            s32 val_b = p[11];

            if (val_b) {
                s32 arg1_val = This->m_Unk4 + 24;

                if (val_b < 0) {
                    val_b = ~val_b + 1;
                }

                if (func_8005D714(This, arg1_val, val_b, p[9])) {
                    This->vtable->Unk89(This);
                }
            }
        }
    }

    return This->m_Unk61;
}

void func_8005DF9C(entity_t *This, s32 Unk2) {
    s32 index = This->m_Unk37 << 4;

    if (D_80089EAB[index] < 0) {
        s8 val = D_80089EAC[index];

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
        s8 *p;
        s8 val;
        s32 unk4;

        p = &D_80089EA4[This->m_Unk37 * 16];
        val = p[11];

        if (val < 0) {
            unk4 = This->m_Unk4;

            if (func_8005D714(This, unk4 + 24, ~val + 1, p[9]) == 0) {
                This->vtable->Unk90(This);
            }
        }
    }

    return This->m_Unk61;
}

entity_vtable_t *entity_get_vtable() {
    return &g_ENTITY_VTABLE;
}
