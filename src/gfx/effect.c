#include "gfx/effect.h"
#include "gfx/effect_base.h"

extern effect_vtable_t g_EFFECT_VTABLE;

extern s32 D_8006EAA8[];
extern s32 D_8006EA90[];

effect_t *effect_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    effect_t *allocated = (effect_t *) memory_allocate_mem(0xA0);

    if (allocated) {
        effect_get_vtable()->effect_construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void effect_construct(effect_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    effect_base_vtable_t *parent;
    void *color;

    parent = func_800408BC();
    if (Unk2 != 0) {
        color = (u8 *)&D_8006EA90 + (Unk2 * 3);
    } else {
        color = &D_8006EAA8;
    }
    parent->Construct(This, Unk1, (u32)color, Unk3);
    This->vtable = effect_get_vtable();
    This->vtable->Unk15(This, Unk2);
}

void effect_reset(effect_t *This, s32 Unk2) {
    This->m_Variant = Unk2;
    This->m_State = 0;
    This->m_ColorStep = 10;
    This->m_ColorChannels = 0;
    This->m_Mode = 0;
    This->vtable->Unk23(This, 0);
    This->vtable->Unk24(This, 0);
    This->m_Unk37 = 0;
}

void effect_tick(effect_t *This, int Unk2, int Unk3) {
    if (Unk3 == 2) {
        s32 value = This->m_Life;

        This->m_Life = value - 1;

        if (value > 0) {
            if (This->m_Mode != 9) {
                if ((This->m_ColorChannels & 4) != 0) {
                    ((u8 *) &This->m_Color)[0] += (u8) This->m_ColorStep;
                }

                if ((This->m_ColorChannels & 2) != 0) {
                    ((u8 *) &This->m_Color)[1] += (u8) This->m_ColorStep;
                }

                if ((This->m_ColorChannels & 1) != 0) {
                    ((u8 *) &This->m_Color)[2] += (u8) This->m_ColorStep;
                }
            }
        } else {
            This->vtable->Unk55(This, Unk2);
        }
    }
}

void effect_set_color_step(effect_t *This, s32 Value) {
    This->m_ColorStep = Value;
}

// Best attempt: all 35 instructions present and equal; only a scheduling
// tie-break differs. Target sets arg1 (ori a1,1) right after the Unk54 call and
// loads the D_8006EA90 lui/addiu after lw v0,0(s0); GCC 2.6.3 emits
// sll/addu, lui/addiu a2, lw v0,0(s0), li a1,1 instead. Reconfirmed with
// inline color, temp local, `one` local, vt local: none reorder the schedule.
//
// void effect_start(effect_t *This) {
//     s32 temp;
//     if (This->m_State == 0) {
//         temp = This->vtable->Unk54(This);
//         This->vtable->Unk45(This, 1, (s32 *)((u8 *)D_8006EA90 + (temp * 3)));
//         This->m_State = 1;
//         This->m_ColorStep = -This->m_ColorStep;
//     }
// }
INCLUDE_ASM("asm/nonmatchings/gfx/effect", effect_start);

/*
 * Best attempt (not matching: target is 41 insns, compiled 40. The only real
 * difference is the dead parameter copy `addu t0,a2,zero` in the delay slot of
 * the first `bnez`; t0 is immediately overwritten with the Unk54 result. gcc
 * 2.6.3 removes the copy for s32 temp=Unk2 / temp=Unk2 / parameter-reassign
 * forms. Everything else matches: `This->m_State == 0` guard, Unk54 call,
 * m_Unk37 branch, m_Life-=1, and Unk45(This,1,&D_8006EAA8[temp*3]).)
 *
 * void effect_start_attached(effect_t *This, s32 Unk1, s32 Unk2) {
 *     s32 temp;
 *
 *     temp = Unk2;
 *     if (This->m_State == 0) {
 *         temp = ((s32 (*)(effect_t *))This->vtable->Unk54)(This);
 *         if (This->m_Unk37 != 0) {
 *             This->m_Life -= 1;
 *         } else {
 *             This->vtable->Unk45(This, 1, (s32 *)((u8 *)D_8006EAA8 + (temp * 3)));
 *         }
 *         This->m_State = 2;
 *     }
 * }
 */
INCLUDE_ASM("asm/nonmatchings/gfx/effect", effect_start_attached);


s32 effect_activate(effect_t *This, base_class_t *arg1, s32 arg2, s32 arg3) {
    effect_vtable_t *vtable;
    s32 state;
    s32 life;
    s32 variant;

    vtable = This->vtable;
    variant = arg2;
    if (variant < 0) {
        variant = This->m_Variant;
    } else {
        This->m_Variant = variant;
    }
    state = 1;
    if (variant != 0) {
        This->m_ColorChannels = variant;
    } else {
        state = 2;
        This->m_ColorChannels = 0xF;
    }
    This->m_ColorChannels = variant;
    if (variant == 0) {
        This->m_ColorChannels = 0xF;
    }
    life = 0x100 / This->m_ColorStep;
    This->m_Mode = arg3;
    This->m_Life = life;
    if (This->m_Unk37 != 0) {
        This->m_Life = life - life / This->m_Unk38;
    }
    This->m_Unk32 = This->m_ColorMask / This->m_Life;
    vtable->Attach((base_class_t *)This, arg1);
    vtable->Unk24((void *)This, 1);
    vtable->Unk25((void *)This, state);
    vtable->Unk23((void *)This, 1);
    return variant;
}

void effect_deactivate(effect_t *This, s32 arg1) {
    effect_vtable_t *vt;
    s32 state;
    s32 which;

    state = This->m_State;
    vt = This->vtable;
    if (state != 0) {
        if (state == 1) {
            which = 5;
            if (This->m_Unk37 == 0) {
                vt->Unk23(This, 0);
                vt->Unk24(This, 0);
            }
        } else {
            which = 6;
            if (This->m_Unk37 != 0) {
                if (This->m_ColorChannels == 0xF) {
                    vt->Unk45(This, 1, D_8006EAA8);
                }
                vt->Unk24(This, 0);
            }
        }
        vt->Detach(This, arg1);
        if (This->m_ColorStep < 0) {
            This->m_ColorStep = -This->m_ColorStep;
        }
        This->m_State = 0;
        vt->Notify(This, which);
    }
}

s32 effect_get_color_impl(effect_t *This) {
    if (This->m_ColorChannels == 15) {
        return D_8006EAA8;
    }

    return (s32 *)((s8 *)D_8006EA90 + 3 * This->m_ColorChannels);
}

void effect_save_render_state(effect_t *This, u16 *a, s32 *b) {
    if (This->m_Unk2 != 0) {
        This->m_Unk33 = (u16)This->m_Unk23_1;
        This->m_Unk34 = (u16)This->m_Unk23_2;
        __builtin_memcpy(&This->m_Unk35, &This->m_Unk19, 8);
        This->m_Unk23_1 = a[0];
        This->m_Unk23_2 = a[2];
        __builtin_memcpy(&This->m_Unk19, b, 8);
    }
}

void effect_restore_render_state(effect_t *This) {
    __builtin_memcpy(&This->m_Unk19, &This->m_Unk35, 8);
    This->m_Unk23_1 = This->m_Unk33;
    This->m_Unk23_2 = This->m_Unk34;
}

void effect_set_linked(effect_t *This, s32 Unk2, s32 Unk3) {
    This->m_Unk37 = Unk2;
    This->m_Unk38 = Unk3;
}

effect_vtable_t *effect_get_vtable() {
    return &g_EFFECT_VTABLE;
}
