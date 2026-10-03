#include "menu/card/comment_input.h"
#include "base/base.h"
#include "file/tim_image.h"
#include "menu/glyph.h"
#include "menu/sprite_node.h"
#include "menu/text_line.h"

class_comment_input_t *func_80050BA8(char *Unk1, s32 Unk2) {
    class_comment_input_t *allocated = ALLOCATE_STRUCT(class_comment_input_t);

    if (allocated) {
        func_80051A4C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

extern u8 *D_8008AAE4;

int strlen(char *s);
void func_80050CD8(class_comment_input_t *This);

void func_80050C14(class_comment_input_t *This, char *arg1, s32 arg2) {
    s32 len;
    u8 *p;
    s32 count;

    base_class_get_vtable()->Construct(This);
    This->vtable = func_80051A4C();
    len = strlen(arg1);
    This->m_Unk3 = len;
    This->m_Unk9 = (s32) memory_allocate_mem(len + 4);
    p = D_8008AAE4;
    count = 0;
    if (*p != 0) {
        do {
            p += 1;
            count += 1;
        } while (*p != 0);
    }
    This->m_Unk4 = count;
    func_80050CD8(This);
    This->vtable->Unk15(This, arg1, arg2);
}

void func_80050CD8(class_comment_input_t *This) {
    This->m_Unk12 = 0;
    This->m_Unk13 = 0;
    This->m_Unk17 = 0;
}

void func_80050CE8(class_comment_input_t *This) {
    memory_free_mem(This->m_Unk9);
    base_class_get_vtable()->Cleanup((base_class_t *) This);
}

void func_80050D30(class_comment_input_t *This, void **Unk) {
    s32 kind;

    if (Unk != NULL) {
        base_class_get_vtable()->Attach((base_class_t *) This, (base_class_t *) Unk);
        kind = *(u32 *) *Unk & 0xF;
        if (kind == 2) {
            This->m_Unk12 = (s32) Unk;
            return;
        }
        if (kind == 5) {
            This->m_Unk13 = (s32) Unk;
        }
    }
}

void func_80050DB4(class_comment_input_t *This, void **Unk) {
    s32 kind;

    if (Unk != NULL) {
        kind = *(u32 *) *Unk & 0xF;
        if (kind == 2) {
            This->m_Unk12 = 0;
        } else if (kind == 5) {
            This->m_Unk13 = 0;
        }
        base_class_get_vtable()->Detach((base_class_t *) This, (base_class_t *) Unk);
    }
}

void func_80050E34(class_comment_input_t *This) {
    This->m_Unk12 = 0;
    This->m_Unk13 = 0;
    This->m_Unk17 = 0;
    base_class_get_vtable()->DetachAll((base_class_t *) This);
}

void func_80050E78(class_comment_input_t *This, void **Unk1, s32 Unk2) {
    s32 kind;

    base_class_get_vtable()->OnNotify((base_class_t *) This, (base_class_t *) Unk1, Unk2);
    kind = *(u32 *) *Unk1 & 0xF;
    if (kind == 2) {
        ((void (*)(void *, void *, s32)) This->vtable->Unk22)(This, Unk1, Unk2);
    } else if (kind == 5) {
        ((void (*)(void *, void *, s32)) This->vtable->Unk21)(This, Unk1, Unk2);
    }
}

void func_80050F28(class_comment_input_t *This, char *Unk1, s32 Unk2) {
    This->m_Unk2 = Unk2;
    This->m_Unk8 = (s32) Unk1;
    This->m_Unk5 = 0;
    This->m_Unk6 = 0;
    if (Unk2 == 1) {
        func_80040FC0(This->m_Unk9, Unk1);
        This->m_Unk3 /= 2;
    } else {
        strcpy((char *) This->m_Unk9, Unk1);
    }
}

extern s8 D_80011610[];
extern s8 D_8001161C[];
extern s8 D_8008AAE8[];
extern s8 D_8008AAF0[];
extern s32 D_80086F7C[3];
extern s8 D_8008AACC[];
extern s8 D_8008AAD4[];
extern s8 D_8008AAC8[];
extern s8 D_8008AADC[];

s8 *build_data_path(s8 *dest, s8 *arg1, s8 *arg2, s8 *arg3);

void func_80050F98(class_comment_input_t *This, void *arg1) {
    s8 buf[32];
    s8 *path_a;
    s8 *path_b;
    tim_image_t *tex;
    tim_image_t *tex2;
    sprite_node_t *panel;
    text_line_t *label;
    class_glyph_t *icon;

    if ((arg1 == NULL) || (This->m_Unk17 != 0)) {
        return;
    }
    path_a = D_8008AAE8;
    path_b = D_8008AAF0;
    tex = tim_image_create((char *) build_data_path(buf, D_80011610, path_a, path_b));
    tex->vtable->Unk14(tex);
    This->m_Unk17 = (s32) sprite_node_create((s32) tex, (s32) D_80086F7C, 0);
    tex->vtable->Destruct(tex);
    panel = (sprite_node_t *) *(s32 volatile *) &This->m_Unk17;
    panel->vtable->Unk18(panel, arg1, D_8008AACC);
    tex2 = tim_image_create((char *) build_data_path(buf, D_8001161C, path_a, path_b));
    tex2->vtable->Unk14(tex2);
    This->m_Unk16 = (s32) text_line_create((s32) tex2, This->m_Unk3, This->m_Unk9);
    This->m_Unk15 = (s32) glyph_create((s32) tex2, 0x5F);
    tex2->vtable->Destruct(tex2);
    label = (text_line_t *) *(s32 volatile *) &This->m_Unk16;
    label->vtable->Unk18(label, (s32) arg1, D_8008AAD4);
    label = (text_line_t *) *(s32 volatile *) &This->m_Unk16;
    label->vtable->Unk45(label, (char *) D_8008AAC8);
    icon = (class_glyph_t *) *(s32 volatile *) &This->m_Unk15;
    icon->vtable->Unk18(icon, arg1, D_8008AADC);
}

void func_80051174(class_comment_input_t *This) {
    s32 obj;

    obj = This->m_Unk17;
    if (obj != 0) {
        This->m_Unk17 = (*(s32(**)(s32))(*(s32 *) obj + 4))(obj);
        obj = This->m_Unk16;
        (*(void (**)(s32))(*(s32 *) obj + 4))(obj);
        obj = This->m_Unk15;
        (*(void (**)(s32))(*(s32 *) obj + 4))(obj);
    }
}

void func_80051200(class_comment_input_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    This->vtable->Attach((base_class_t *) This, (base_class_t *) Unk1);
    This->vtable->Attach((base_class_t *) This, (base_class_t *) Unk2);
    This->m_Unk14 = Unk3;
    This->m_Unk10 = 0;
    This->m_Unk7 = 0;
}

void func_80051270(class_comment_input_t *This) {
    This->vtable->Detach((base_class_t *) This, (base_class_t *) This->m_Unk12);
    This->vtable->Detach((base_class_t *) This, (base_class_t *) This->m_Unk13);
    This->m_Unk14 = 0;
}

void func_800512C8(class_comment_input_t *This, s32 arg1) {
    This->m_Unk11 = 0;
    if (arg1 < 2) {
        goto end;
    }
    if (arg1 < 4) {
        goto case_2_3;
    }
    if (arg1 == 4) {
        goto case_4;
    }
    goto end;
case_2_3:
    ((void (*)(void *, s32)) This->vtable->Detach)(This, This->m_Unk12);
    This->vtable->Unk17(This);
    This->m_Unk10 = arg1;
    goto end;
case_4:
    ((void (*)(void *, s32)) This->vtable->Notify)(This, This->m_Unk10);
end:;
}

void func_80051370(class_comment_input_t *This) {
    s32 unk10;
    s32 unk11;

    unk10 = This->m_Unk10;
    if (unk10 < 4) {
        if (!(unk10 < 2)) {
            unk11 = This->m_Unk11;
            This->m_Unk11 = unk11 + 1;
            if (unk11) {
                This->vtable->Unk20(This, 4);
            }
        }
    }
}

// Best attempt: all 147 target instructions reproduce exactly with the switch
// below. The only blocker is data placement: the compiler emits
// jtbl_80011628 into this unit's .rodata, but the 0x1E28 rodata subsegment is
// currently assembled from asm/data/1E28.rodata.s and is shared with
// select_menu (D_800116E4 "FONTICON"). Attributing 0x1E28 to menu/card/
// comment_input in config/SLPS01556.yaml is required to link this C body.
//
// void func_800513D0(class_comment_input_t *This, s32 arg1, s32 arg2) {
//     switch (arg2) {
//     case 25:
//         if (This->m_Unk2 == 1) {
//             func_80041020((u8 *)This->m_Unk8, (u8 *)This->m_Unk9);
//         } else {
//             strcpy((char *)This->m_Unk8, (char *)This->m_Unk9);
//         }
//         ((void (*)(void *, s32))This->vtable->Unk23)(This, 0x10);
//         ((void (*)(void *, s32))This->vtable->Unk20)(This, 2);
//         break;
//     case 23:
//         ((void (*)(void *, s32))This->vtable->Unk23)(This, 0x10);
//         ((void (*)(void *, s32))This->vtable->Unk20)(This, 3);
//         break;
//     case 32:
//         This->vtable->Unk39(This);
//         break;
//     case 31:
//         This->vtable->Unk38(This);
//         break;
//     case 28:
//         This->vtable->Unk37(This);
//         break;
//     case 21:
//         if (This->m_Unk7 == 0) This->vtable->Unk33(This);
//         break;
//     case 5:
//         if (This->m_Unk7 != 0) This->vtable->Unk33(This);
//         break;
//     case 20:
//         if (This->m_Unk7 == 0) This->vtable->Unk34(This);
//         break;
//     case 4:
//         if (This->m_Unk7 != 0) This->vtable->Unk34(This);
//         break;
//     case 18:
//         if (This->m_Unk7 == 0) This->vtable->Unk35(This);
//         break;
//     case 2:
//         if (This->m_Unk7 != 0) This->vtable->Unk35(This);
//         break;
//     case 19:
//         if (This->m_Unk7 == 0) This->vtable->Unk36(This);
//         break;
//     case 3:
//         if (This->m_Unk7 != 0) This->vtable->Unk36(This);
//         break;
//     }
// }
INCLUDE_ASM("asm/nonmatchings/menu/card/comment_input", func_800513D0);

void func_8005161C(class_comment_input_t *This, s32 Unk) {
    s32 m_Unk14; // $a0

    m_Unk14 = This->m_Unk14;
    if (m_Unk14) {
        (*(void (**)(s32, int, int, int))(*(s32 *) m_Unk14 + 128))(m_Unk14, Unk, 96, 96);
    }
}

void func_8005165C(class_comment_input_t *This) {
    s32 old;
    s32 neu;

    if (This->m_Unk17) {
        old = This->m_Unk5;
        neu = old + 1;
        This->m_Unk5 = neu;
        if (neu < This->m_Unk3) {
            This->vtable->Unk40(This, neu, 1);
        } else {
            This->m_Unk5 = old;
        }
    }
}

void func_800516C0(class_comment_input_t *This) {
    s32 m_Unk5; // $v0

    if (This->m_Unk17) {
        m_Unk5 = This->m_Unk5;
        This->m_Unk5 = m_Unk5 - 1;
        if (m_Unk5 - 1 >= 0) {
            This->vtable->Unk40(This, m_Unk5 - 1, 1);
        }

        else {
            This->m_Unk5 = m_Unk5;
        }
    }
}

void func_80051720(class_comment_input_t *This) {
    s32 neu;

    if (This->m_Unk17) {
        neu = This->m_Unk6 + 1;
        This->m_Unk6 = neu;
        if (neu < This->m_Unk4) {
            ((void (*)(void *, s32, s32, s32)) This->vtable->Unk41)(This, This->m_Unk5, neu, 1);
        } else {
            This->m_Unk6 = 0;
        }
    }
}

void func_80051784(class_comment_input_t *This) {
    s32 neu;

    if (This->m_Unk17) {
        neu = This->m_Unk6 - 1;
        This->m_Unk6 = neu;
        if (neu > 0) {
            ((void (*)(void *, s32, s32, s32)) This->vtable->Unk41)(This, This->m_Unk5, neu, 1);
        } else {
            This->m_Unk6 = This->m_Unk4;
        }
    }
}

void func_800517EC(class_comment_input_t *This) {
    if (This->m_Unk17) {
        This->m_Unk7 ^= 1u;
    }
}

void func_80051814(class_comment_input_t *This) {
    if (This->m_Unk17) {
        This->m_Unk6 = 0;
        ((void (*)(class_comment_input_t *, s32, s32, s32)) This->vtable->Unk41)(This, This->m_Unk5, 0, 1);
    }
}

void func_80051858(class_comment_input_t *This) {
    s32 i;

    if (This->m_Unk17 != 0) {
        i = This->m_Unk3 - 1;
        This->m_Unk6 = 0;
        if (!(i < 0)) {
            do {
                This->m_Unk5 = i;
                ((void (*)(void *, s32, s32, s32)) This->vtable->Unk41)(This, i, This->m_Unk6, 0);
                i -= 1;
            } while (i >= 0);
        }
        This->vtable->Unk40(This, This->m_Unk5, 1);
    }
}

/*
 * Best-known C (41/41 insns, byte-identical) needs D_8008AADC declared as a
 * scalar (`extern s32 D_8008AADC;`) so gcc -G8 emits `lw %gp_rel(D_8008AADC)`.
 * This TU also contains func_80050F98, whose target passes the *address* of
 * D_8008AADC as `lui/addiu` (absolute) and therefore needs the array form
 * (`extern s8 D_8008AADC[];`). gcc 2.6.3 applies one declaration per symbol per
 * TU (a block-scope `extern` in either function leaks to the whole TU), so the
 * two cannot coexist here. Matched separately in the original build (different
 * TUs). Revisit only if comment_input is split into two units.
 *
 * extern s32 D_8008AAE0;
 *
 * void func_800518F4(class_comment_input_t *This, s32 arg1, s32 arg2) {
 *     class_glyph_t *icon;
 *     s32 sp10[2];
 *
 *     if (This->m_Unk17 != 0) {
 *         sp10[1] = D_8008AAE0;
 *         sp10[0] = arg1 * 7 + D_8008AADC;
 *         icon = (class_glyph_t *)This->m_Unk15;
 *         ((void (*)(void *, void *))icon->vtable->Unk46)(icon, sp10);
 *         This->m_Unk5 = arg1;
 *         if (arg2 != 0) {
 *             ((void (*)(void *, s32))This->vtable->Unk23)(This, 0);
 *         }
 *     }
 * }
 */
INCLUDE_ASM("asm/nonmatchings/menu/card/comment_input", func_800518F4);

#include "menu/card/comment_input.h"
#include "menu/text_line.h"

extern class_comment_input_vtable_t D_80086ED0;
extern u8 *D_8008AAE4;

void func_80051998(class_comment_input_t *This, s32 arg1, s32 arg2, s32 arg3) {
    text_line_t *label;

    if (This->m_Unk17 != 0) {
        ((u8 *) This->m_Unk9)[arg1] = ((u8 *) D_8008AAE4)[arg2];
        label = (text_line_t *) This->m_Unk16;
        ((void (*)(void *, u8, s32)) label->vtable->Unk48)(label, ((u8 *) D_8008AAE4)[arg2], arg1);
        This->m_Unk5 = arg1;
        This->m_Unk6 = arg2;
        if (arg3 != 0) {
            ((void (*)(void *, s32)) This->vtable->Unk23)(This, 0);
        }
    }
}

class_comment_input_vtable_t *func_80051A4C(void) {
    return &D_80086ED0;
}
