#include "3ACC8.h"
#include "transform.h"

extern class_3ACC8_vtable_t D_800866E8;

extern s8 D_800868FC[];
extern s32 D_8008688C[];
extern s32 D_800868A8[];
extern s32 D_80086974[];
extern s32 D_800869CC[];
extern s32 D_80086904[];
extern s32 D_80086990[3];
extern s32 D_8008699C[3];
extern s32 D_800869A8[3];
extern s32 D_800869B4[3];
extern s32 D_800869C0[3];
extern s32 D_8008A980;

s32 func_8004BCE0(class_3ACC8_t *This);
void func_8004D0D0(class_3ACC8_t *This, s32 *Unk);
void func_8004D140(class_3ACC8_t *This, void (*arg1)(s32, s32), void (*arg2)(s32, s32));

class_3ACC8_t *func_8004A4C8(u32 Unk1, u32 Unk2) {
    class_3ACC8_t *allocated = (class_3ACC8_t *) memory_allocate_mem(0x1E8);

    if (allocated) {
        func_8004D244()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004A534);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004A7C0);

void func_8004A984(class_3ACC8_t *This, s32 **Unk2, s32 Unk3) {
    func_8001E57C()->OnNotify(This, Unk2, Unk3);

    if ((**Unk2 & 0xF) == 1) {
        This->vtable->Unk63(This, Unk2, Unk3);
    }
}

void func_8004AA10(class_3ACC8_t *This) {
    This->m_Unk25 = 0;
    This->m_Unk57 = 0;
    This->m_Unk33 = 0;
    This->vtable->Unk54(This, D_8008A980);
    This->m_Unk114 = -1;
    This->m_Unk115 = -1;
    This->m_Unk116 = -1;
    This->m_Unk117 = -1;
}

void func_8004AA6C(class_3ACC8_t *This, s32 arg1, void *arg2) {
    void *obj;

    ((void (*)(void *, s32))func_8001E57C()->Unk33)(This, arg1);
    switch (arg1) {
    case 6:
        obj = *(void **)((u8 *)arg2 + 0x14);
        if (obj != NULL) {
            *(void **)((u8 *)arg2 + 0x14) =
                (*(void *(**)(void *))(*(s32 *)obj + 4))(obj);
        }
        /* fallthrough */
    case 7:
        This->m_Unk110 = (s32)arg2;
        ((void (*)(void *, s32))This->vtable->Notify)(This, arg1);
        break;
    }
}

void func_8004AB24(class_3ACC8_t *This) {
    if (This->m_Unk27) {
        This->vtable->Unk60(This);
        This->vtable->Unk78(This);
    }
}

void func_8004AB88(class_3ACC8_t *This, u8 **Unk) {
    if (**Unk == 52) {
        This->vtable->Unk51(This);
    }
}

typedef struct {
    u8 m_Pad[0x74];
    void (*Unk29)(void *);
    u8 m_Pad2[4];
    void (*Unk30)(void *);
    u8 m_Pad3[4];
    void (*Unk33)(void *);
} class_3ACC8_slot_obj_vtable_t;

typedef struct class_3ACC8_slot_obj {
    class_3ACC8_slot_obj_vtable_t *vtable;
    u8 m_Pad[0x2C];
    s16 m_Unk30_1;
} class_3ACC8_slot_obj_t;

typedef struct {
    void *m_Pad;
    s32 (*Destroy)(void *);
} class_3ACC8_slot_child_vtable_t;

typedef struct class_3ACC8_slot_child {
    class_3ACC8_slot_child_vtable_t *vtable;
} class_3ACC8_slot_child_t;

typedef struct {
    u8 m_Pad[0x2C];
    class_3ACC8_slot_child_t *m_Child;
} class_3ACC8_slot_link_t;

typedef struct class_3ACC8_slot_item {
    void *m_Unk0;
    u8 m_Pad[0xC];
    u32 m_Flags;
    s32 m_Unk5;
    s32 m_Unk6;
    s32 m_Unk7;
    s32 m_Unk8;
} class_3ACC8_slot_item_t;

typedef struct {
    s16 m_Flag;
    s16 m_Pad;
    class_3ACC8_slot_obj_t *m_Obj;
    class_3ACC8_slot_link_t *m_Link;
    u8 m_UnkC[4];
    class_3ACC8_slot_item_t **m_Items;
    u8 m_Rest[8];
} class_3ACC8_slot_t;

void func_8004ABD0(class_3ACC8_t *This) {
    s32 index;
    s32 offset;
    class_3ACC8_slot_t *slot;
    class_3ACC8_slot_link_t *link;
    class_3ACC8_slot_child_t *child;

    index = 0;
    offset = 0xEC;
    do {
        slot = (class_3ACC8_slot_t *)((u8 *)This + offset);
        slot->m_Obj->vtable->Unk29(slot->m_Obj);
        slot->m_Flag = 0;
        This->vtable->Unk65(This, slot);
        link = slot->m_Link;
        child = link->m_Child;
        if (child != 0) {
            link->m_Child = (class_3ACC8_slot_child_t *)child->vtable->Destroy(child);
        }
        offset += 0x1C;
        This->vtable->Unk33(This, 6, slot, index);
        slot->m_Obj->vtable->Unk33(slot->m_Obj);
        index += 1;
    } while (index < 7);
    This->m_Unk109 = 0;
    *(s16 *)&This->m_Unk108 = 0;
    This->vtable->Unk79(This);
}

typedef struct acf8_obj_vtable {
    /* 0x00 */ u8 pad[0x44];
    /* 0x44 */ void (*Unk16)(void *, s32, void *);
    /* 0x48 */ void (*Unk17)(void *, s32, void *);
} acf8_obj_vtable_t;

typedef struct acf8_obj {
    /* 0x00 */ acf8_obj_vtable_t *vtable;
} acf8_obj_t;

void func_8004ACF8(class_3ACC8_t *This, s32 count, void *arg2, void *arg3) {
    s32 i;
    acf8_obj_t *obj;

    for (i = 0; i < count; i++) {
        obj = This->vtable->Unk45(This, i);
        obj->vtable->Unk16(obj, 1, arg3);
        arg3 = (u8 *)arg3 + 3;
        obj->vtable->Unk17(obj, 1, arg2);
        arg2 = (u8 *)arg2 + 6;
    }
}

void func_8004ADC4(class_3ACC8_t *This, s32 Unk2, s32 Unk3) {
    This->m_Unk23 = Unk2;
    This->m_Unk24 = Unk3;
}

void func_8004ADD0(class_3ACC8_t *This, s32 Value) {
    This->m_Unk57 = Value;
}

void func_8004ADD8(class_3ACC8_t *This, s32 **arg1, s32 arg2) {
    char dummy_stack_padding[24];
    s32 *p;

    if (&dummy_stack_padding[0] == &dummy_stack_padding[23]) {}

    switch (arg2) {
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
        p = This->m_Unk57;
        if (p != NULL && *p != 0) {
            do {
                if (*p == **arg1) {
                    This->vtable->Unk74(This, arg1, arg2);
                }
                p++;
            } while (*p != 0);
        }
        break;
    }
}

typedef struct aea4_arg {
    /* 0x00 */ s32 pad0[3];
    /* 0x0C */ s32 unk_c;
    /* 0x10 */ s32 pad1;
    /* 0x14 */ s32 unk_14;
} aea4_arg_t;

typedef struct {
    s32 w[12];
} blk30_t;

void func_8004AFE0(class_3ACC8_t *This, s32 *Unk1, s32 Unk2);
void func_8004B030(class_3ACC8_t *This, s8 *arg1, s32 arg2);
void func_8004B100(class_3ACC8_t *This, aea4_arg_t *arg1, s32 arg2);

void func_8004AEA4(class_3ACC8_t *This, aea4_arg_t *arg1, s32 arg2) {
    blk30_t saved;
    blk30_t out;
    s32 extra;
    s32 keep;
    s32 *gate;

    if (arg1->unk_c != 0) {
        extra = arg1->unk_14 + 0x38;
    } else {
        extra = 0;
    }
    if (This->vtable->Unk67(This, &out, extra) != 0) {
        return;
    }
    keep = This->m_Unk33;
    saved = *(blk30_t *)&This->m_Unk34;
    gate = (s32 *)This->m_Unk25;
    if (gate[1] == 0) {
        func_8004AFE0(This, (s32 *)&out, 3);
    } else {
        func_8004B030(This, (s8 *)&out, 3);
    }
    func_8004B100(This, arg1, arg2);
    This->m_Unk33 = keep;
    *(blk30_t *)&This->m_Unk34 = saved;
}

void func_8004AFE0(class_3ACC8_t *This, s32 *Unk1, s32 Unk2) {
    s8 v3;

  This->m_Unk30_1 = *((s8 *)Unk1 + 2) - 1;
  v3 = *((s8 *)Unk1 + 3);
  This->m_Unk31 = Unk2;
  This->m_Unk32 = Unk2;
  This->m_Unk30_2 = v3 - 1;
  func_8004C93C(This);
}


void func_8004B030(class_3ACC8_t *This, s8 *arg1, s32 arg2) {
    s32 b2;
    s32 b3;
    s32 orig2;
    s32 orig3;
    s32 adj2;
    s32 adj3;

    b2 = arg1[2];
    b3 = arg1[3];
    orig2 = b2;
    orig3 = b3;
    adj2 = arg2;
    adj3 = adj2;
    if (b2 == 0) {
        adj2 = adj3 - 1;
    } else {
        b2--;
    }
    if (orig2 == 0x13) {
        adj2--;
    }
    if (orig3 == 0) {
        adj3--;
    } else {
        b3--;
    }
    if (orig3 == 0x13) {
        adj3--;
    }
    This->m_Unk33 = 1;
    This->m_Unk34 = This->vtable->Unk72(This, *(s32 *)(arg1 + 0x28));
    This->m_Unk35_1 = b2;
    This->m_Unk35_2 = b3;
    This->m_Unk36_1 = adj2;
    This->m_Unk36_2 = adj3;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B100);

void func_8004B2D4(class_3ACC8_t *This) {
    if (This && (This->m_Unk12_2 & 0x80) != 0) {
        This->vtable->OnNotify(This);
    }
}

s32 *func_8004B31C(class_3ACC8_t *This) {
    return &This->m_Unk111;
}

void func_8004B324(void) {
}

void func_8004B32C(class_3ACC8_t *This, s32 Value) {
    This->m_Unk28 = Value;
    This->m_Unk29_2 = Value >> 11;
    This->m_Unk29_1 = Value >> 12;
}

void func_8004B344(class_3ACC8_t *This, s32 Unk) {
    This->vtable->Unk15(This);
  This->m_Unk25 = Unk;
}

s32 func_8004B44C(void *, void *, s32, void *, void *);

typedef struct {
    u8 m_data[8];
    s16 m_hi;
} func_8004B38C_pkt_t;

s32 func_8004B38C(class_3ACC8_t *This, void *arg1, s32 arg2, void *arg3) {
    s8 sp18[0x10];

    This->m_Unk26 = arg2;
    *(func_8004B38C_pkt_t *)&This->m_Unk46 = *(func_8004B38C_pkt_t *)arg3;
    return ((s32 (*)(void *, s32, void *, void *))This->vtable->Unk61)(
        This,
        func_8004B44C(arg1, sp18, This->m_Unk25, &This->m_Unk20, arg3),
        sp18,
        D_80086904);
}

void func_8004B418(class_3ACC8_t *This, s32 Unk2, s32 Unk3) {
    s8 unk[16];

    func_8004B44C(Unk2, unk, This->m_Unk25, &This->m_Unk20, Unk3);
}

typedef struct {
    /* 0x0 */ s16 m_Width;
    /* 0x2 */ s16 m_Height;
    /* 0x4 */ s32 m_Mode;
} func_8004B44C_grid_t;

typedef struct {
    /* 0x0 */ s8 m_Unk0;
    /* 0x1 */ s8 m_Unk1;
    /* 0x2 */ s8 m_Unk2;
    /* 0x3 */ s8 m_Unk3;
    /* 0x4 */ s16 m_Unk4;
    /* 0x6 */ s16 m_Unk6;
    /* 0x8 */ s16 m_Unk8;
} func_8004B44C_info_t;

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B44C);

/*
 * Near match (semantics exact, 73/73 insns, 4 residual insns). Best C below.
 * Residual: the target schedules the src->y load one slot later (after the
 * outB->z add) and therefore keeps y in $v1 across the outB->x load, forcing
 * $a0 for outB->x/outB->z; gcc keeps y in $v1 only until its store and reloads
 * outB->x into $v1. This also makes gcc fold the `+0x400` into the accumulator
 * (addiu v0,v0,0x400) instead of into the info[4] operand
 * (addiu v1,v1,0x400). Tried: y/bx/zbase temporaries, all 24 permutations of
 * the (y, bx, outB->z, outB->y) statements, direct vs cached outB->x, and three
 * groupings of the +0x400 sum; all yield the same 73-insn schedule.
 *
 * s32 func_8004B44C(void *arg0, void *arg1, s32 arg2, void *arg3, void *arg4) {
 *     s32 t4;
 *     s32 t1;
 *     s32 t0;
 *     s32 tmp;
 *     s32 zbase;
 *     s32 y;
 *     s32 bx;
 *
 *     if (((func_8004B44C_grid_t *)arg2)->m_Mode == 0) {
 *         t0 = ((func_8004B44C_info_t *)arg4)->m_Unk1;
 *         t1 = ((func_8004B44C_grid_t *)arg2)->m_Height;
 *         t4 = ((func_8004B44C_info_t *)arg4)->m_Unk0 +
 *              (((func_8004B44C_grid_t *)arg2)->m_Width * t0);
 *     } else {
 *         t1 = 1;
 *         t0 = 0;
 *         t4 = 0;
 *     }
 *     tmp = (((vec3d_t *)arg3)->x - (((func_8004B44C_grid_t *)arg2)->m_Width * 0x5000)) +
 *           (((func_8004B44C_info_t *)arg4)->m_Unk0 * 0xA000);
 *     zbase = ((vec3d_t *)arg3)->z - (t1 * 0x5000);
 *     ((vec3d_t *)arg1)->x = tmp;
 *     if (t0 & 1) {
 *         ((vec3d_t *)arg1)->x = tmp - 0x5000;
 *     }
 *     y = ((vec3d_t *)arg3)->y;
 *     bx = ((vec3d_t *)arg1)->x;
 *     ((vec3d_t *)arg1)->z = zbase + (t0 * 0xA000);
 *     ((vec3d_t *)arg1)->y = y;
 *     ((vec3d_t *)arg0)->x = (((func_8004B44C_info_t *)arg4)->m_Unk2 << 11) + bx +
 *                            (((func_8004B44C_info_t *)arg4)->m_Unk4 + 0x400);
 *     ((vec3d_t *)arg0)->y = ((func_8004B44C_info_t *)arg4)->m_Unk6 + ((vec3d_t *)arg1)->y;
 *     ((vec3d_t *)arg0)->z = (((func_8004B44C_info_t *)arg4)->m_Unk3 << 11) +
 *                            ((vec3d_t *)arg1)->z +
 *                            (((func_8004B44C_info_t *)arg4)->m_Unk8 + 0x400);
 *     ((vec3d_t *)arg1)->x += 0x5000;
 *     ((vec3d_t *)arg1)->z += 0x5000;
 *     return t4;
 * }
 */

void func_8004B570(class_3ACC8_t *This) {
    This->m_Unk27 = 1;
}

void func_8004B57C(class_3ACC8_t *This) {
    This->vtable->Unk47(This);
    This->m_Unk27 = 0;
}

typedef struct {
    /* 0x00 */ s16 first;
    /* 0x02 */ s16 pad0;
    /* 0x04 */ s32 pad1;
    /* 0x08 */ s32 pad2;
    /* 0x0C */ s32 at_c;
    /* 0x10 */ s32 pad4;
    /* 0x14 */ s32 pad5;
    /* 0x18 */ s32 pad6;
    /* 0x1C */ s32 pad7;
    /* 0x20 */ s32 pad8;
    /* 0x24 */ void *obj;
    /* 0x28 */ s32 value;
} func_8004B5BC_buf_t;

s32 func_8004B5BC(class_3ACC8_t *This) {
    func_8004B5BC_buf_t buf;
    u16 old;
    void *inner;
    s32 index;
    s32 kind;

    if (This->vtable->Unk66(This, &buf, 0) == 0) {
        return 0;
    }
    inner = *(void **)((u8 *)buf.obj + 4);
    index = *(s16 *)((u8 *)inner + 0x32);
    kind = D_800868FC[index];
    if (*(s32 *)(This->m_Unk25 + 4) == 0) {
        This->vtable->Unk61(This, buf.value, &buf.at_c, D_80086974[kind]);
    }
    This->vtable->Unk73(This);
    old = *(u16 *)&This->m_Unk46;
    *(func_8004B5BC_buf_t *)&This->m_Unk46 = buf;
    if ((s16)old != buf.first) {
        This->vtable->Notify(This, 5);
    }
    return kind;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B700);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B930);

/*
 * Near match (semantics exact, 65/68 insns): only the target's unused 8-byte
 * stack frame (addiu sp,sp,-8 in the mode-test delay slot, addiu sp,sp,8 before
 * jr) and one duplicated `nor v0,zero,a0` in the second modulo branch delay are
 * missing. No source-level scalar/array/struct/union/alloca/address-taken-local
 * construct reproduced a frame without also emitting sp-relative lw/sw; the
 * frame has no sp operand anywhere in the target, so it is not a normal local.
 *
 * s32 func_8004B930(class_3ACC8_t *This, s32 index, s32 parity) {
 *     s32 width = *(s16 *)(This->m_Unk25 + 0);
 *     s32 mode = *(s32 *)(This->m_Unk25 + 4);
 *     s32 height = *(s16 *)(This->m_Unk25 + 2);
 *     s32 result;
 *
 *     if (mode == 0) {
 *         result = 0;
 *         if (index < width) result |= 3;
 *         if (index >= width * (height - 1)) result |= 0x60;
 *         if (index % width == 0) {
 *             if (parity != 0) result |= 0x25; else result |= 4;
 *         }
 *         if ((index + 1) % width == 0) {
 *             if (parity != 0) result |= 0x10; else result |= 0x52;
 *         }
 *     } else {
 *         result = -1;
 *         if (height > 0) {
 *             s32 i = 0;
 *             do { i++; result <<= 1; } while (i < height);
 *         }
 *     }
 *     return ~result;
 * }
 */

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BA40);

/*
 * Near match (semantics exact, 63/63 insns). Residual: target allocates the
 * 5th arg (base) to $a1 and result/v to $v0, and saves $s1 before $s0; gcc
 * allocates base to $t0 and result/v to $a1 (and saves $s0 first). Tried
 * if/else vs early-return, inlined out[1] writes, `v` before/after result,
 * declaration order, and a base copy; all give base in $t0. This is a
 * local-alloc priority tie, not a semantics/type issue.
 *
 * s32 func_8004BA40(class_3ACC8_t *This, s32 *out, s32 col, s32 parity, s32 base, s32 mask, s32 dir) {
 *     s32 result;
 *     s32 v;
 *     s32 *tbl;
 *     s32 t0;
 *     s32 prod;
 *
 *     result = 0;
 *     if (mask & D_8008688C[dir]) {
 *         v = base + dir;
 *         if (*(s32 *)(This->m_Unk25 + 4) == 0) {
 *             tbl = &D_800868A8[dir * 3];
 *             t0 = tbl[0];
 *             if (t0 == 0) {
 *                 v = base + tbl[1];
 *             } else {
 *                 prod = col * t0;
 *                 if (parity != 0) {
 *                     v = base + (prod + tbl[1]);
 *                 } else {
 *                     v = base + (prod + tbl[2]);
 *                 }
 *             }
 *         }
 *         out[1] = v;
 *         out[0] = ((s32(*)(s32, s32, s32, s32))This->m_Unk23)(This->m_Unk24, out[1], 0, 0);
 *         result = 1;
 *     } else {
 *         out[0] = 0;
 *     }
 *     out[2] = dir;
 *     return result;
 * }
 */

typedef struct func_8004BB3C_inner func_8004BB3C_inner_t;

typedef struct func_8004BB3C_inner_vtable {
    /* 0x00 */ u8 pad[0x74];
    /* 0x74 */ void (*Unk28)(func_8004BB3C_inner_t *);
    /* 0x78 */ void (*Unk29)(func_8004BB3C_inner_t *, s32);
} func_8004BB3C_inner_vtable_t;

typedef struct func_8004BB3C_inner {
    /* 0x00 */ func_8004BB3C_inner_vtable_t *vtable;
    /* 0x04 */ u8 pad[0x26];
    /* 0x2A */ u16 field_2a;
    /* 0x2C */ s16 field_2c;
    /* 0x2E */ u16 pad_2e;
    /* 0x30 */ u16 field_30;
} func_8004BB3C_inner_t;

typedef struct func_8004BB3C_slot {
    /* 0x00 */ s16 flag;
    /* 0x02 */ s16 pad;
    /* 0x04 */ func_8004BB3C_inner_t *obj;
} func_8004BB3C_slot_t;

typedef struct func_8004BB3C_ent {
    /* 0x00 */ s32 id;
    /* 0x04 */ u16 half;
    /* 0x06 */ u16 pad;
    /* 0x08 */ s32 arg;
} func_8004BB3C_ent_t;

void func_8004BB3C(class_3ACC8_t *This, func_8004BB3C_ent_t *ents, s32 count) {
    s32 i;
    s32 one;
    func_8004BB3C_slot_t *slot;
    func_8004BB3C_inner_t *obj;

    for (i = 0; i < count; i += 1) {
            one = 1;
            slot = This->vtable->Unk69(This, ents->arg);
            This->vtable->Unk33(This, 6, slot, i);
            if (ents->id != 0) {
                if (slot->obj->field_2c != 0) {
                    This->vtable->Unk65(This, slot);
                }
                slot->obj->field_30 = ents->half;
                slot->obj->vtable->Unk29(slot->obj, ents->id);
                slot->flag = one;
                This->m_Unk107 = one;
            } else {
                if (slot->obj->field_2c != 0) {
                    This->vtable->Unk65(This, slot);
                }
                obj = slot->obj;
                if (obj->field_2a != 0) {
                    obj->vtable->Unk28(obj);
                    slot->flag = 0;
                }
            }
            ents += 1;
        }
    *(s16 *)&This->m_Unk108 = func_8004BCE0(This);
}

s32 func_8004BCE0(class_3ACC8_t *This) {
    s32 count = 0;
    s32 i = 0;

loop:
    if (This->m_Unk58_1 != 0) {
        count++;
    }
    This = (class_3ACC8_t *)((char *)This + 0x1C);
    i++;
    if (i < 7) {
        goto loop;
    }

    return count;
}

/*
 * Near match (semantics exact, 81/80 insns). The target keeps the byte offset
 * in $s4 (`ori s4,zero,0xEC`, `addiu s4,s4,0x1C` in the loop-back delay) and
 * recomputes the slot address at the loop head (`addu s0,s1,s4`). With the
 * natural offset increment at the loop bottom gcc 2.6.3 strength-reduces the
 * slot pointer into `addiu s0,s0,0x1C` (77 insns). Moving the increment into the
 * loop body keeps $s4 but makes gcc peel a copy of the address computation into
 * the preheader (81 insns vs target 80), so the first instruction difference is
 * the missing/extra head `addu`. Also needs the widened vtable Unk64. Best C:
 *
 * void func_8004BD14(class_3ACC8_t *This, s32 unused, s32 arg2) {
 *     s32 offset;
 *     s32 i;
 *     s32 state;
 *     u16 count;
 *
 *     if (arg2 == 2) {
 *         i = 0;
 *         offset = 0xEC;
 *         do {
 *             fast_slot_t *slot = (fast_slot_t *)((u8 *)This + offset);
 *             if (slot->m_Obj->m_Unk2E != 0) {
 *                 slot->m_Obj->m_Unk2E = 0;
 *                 This->vtable->Unk33(This, 7, slot, i);
 *             }
 *             state = This->m_Unk107;
 *             offset += 0x1C;
 *             if (state == 1 && slot->m_Flag != 0) {
 *                 if (slot->m_Obj->m_Unk2C != 0) {
 *                     This->vtable->Unk64(This, slot);
 *                     slot->m_Obj->m_Unk2C = 2;
 *                     slot->m_Flag = 0;
 *                     count = *(u16 *)&This->m_Unk108 - 1;
 *                     *(u16 *)&This->m_Unk108 = count;
 *                     if (count == 0) {
 *                         *(u16 *)&This->m_Unk108 = 0;
 *                         This->m_Unk107 = 0;
 *                         This->m_Unk109 = state;
 *                     }
 *                 } else if (slot->m_Obj->m_Unk2A == 0) {
 *                     slot->m_Flag = 0;
 *                 }
 *             }
 *             i += 1;
 *         } while (i < 7);
 *     }
 * }
 */

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BD14);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BE54);

void func_8004C0AC(class_3ACC8_t *This, class_3ACC8_slot_t *slot) {
    class_3ACC8_slot_obj_t *obj;
    class_3ACC8_slot_item_t **start;
    class_3ACC8_slot_item_t **end;
    class_3ACC8_slot_item_t **cursor;

    obj = slot->m_Obj;
    if (obj->m_Unk30_1 >= 0) {
        obj->vtable->Unk30(obj);
        start = slot->m_Items;
        end = (class_3ACC8_slot_item_t **)((u8 *)start + 0x668);
        cursor = start;
        while (cursor < end) {
            (*cursor)->m_Flags |= 0x80000000;
            (*cursor)->m_Unk8 = 0;
            (*cursor)->m_Unk6 = 0;
            cursor++;
        }
    }
}

void *func_8004C158(class_3ACC8_t *This, s32 arg1, s32 *arg2) {
    s32 temp_v1;
    void *var_v0;

    temp_v1 = *(s32 *)(This->m_Unk26 + 0x14) + 0x18;
    if (arg2 != NULL) {
        *arg2 = temp_v1;
    }
    if ((arg1 == 0) ||
        (((s32(*)(void *, s32, s32))This->vtable->Unk67)(This, arg1, temp_v1) == 0)) {
        var_v0 = (u8 *)This + 0xBC;
    } else {
        var_v0 = NULL;
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C1C0);
// Best match: 106/106 insns, same length. Residual: (1) GCC local_alloc
// keeps the second coord pointer in $a3 where the target uses $a1;
// (2) GCC cse-hoists the -0x400 constant into $a2 (li a2,0xfc00) and emits
// addu instead of the target's addiu; (3) tail scheduling of out->y/out->obj
// differs. All operand shapes and the lb/sll<->lbu/sll24/sra13 shift form match.
// typedef struct func_8004C1C0_out {
//     /* 0x00 */ s8 b0;
//     /* 0x01 */ s8 b1;
//     /* 0x02 */ s8 dx;
//     /* 0x03 */ s8 dz;
//     /* 0x04 */ s16 x;
//     /* 0x06 */ u16 y;
//     /* 0x08 */ s16 z;
//     /* 0x0C */ s32 vx;
//     /* 0x10 */ s32 vy;
//     /* 0x14 */ s32 vz;
//     /* 0x18 */ s32 rx;
//     /* 0x1C */ s32 ry;
//     /* 0x20 */ s32 rz;
//     /* 0x24 */ void *obj;
//     /* 0x28 */ s32 divisor;
// } func_8004C1C0_out_t;
//
// typedef struct func_8004C1C0_pos {
//     /* 0x00 */ s32 x;
//     /* 0x04 */ s32 y;
//     /* 0x08 */ s32 z;
// } func_8004C1C0_pos_t;
//
// s32 func_8004C1C0(class_3ACC8_t *This, func_8004C1C0_out_t *out, func_8004C1C0_pos_t *pos) {
//     void *obj;
//     s32 *coordB;
//     s32 *coordA;
//     s16 val;
//
//     obj = This->vtable->Unk70(This, pos);
//     if (obj != NULL) {
//         val = *(s16 *)((u8 *)(*(s32 **)((u8 *)obj + 4)) + 0x30);
//         out->divisor = val;
//         func_8004C368(This, (s8 *)out, val);
//         coordA = *(s32 **)((u8 *)(*(s32 **)((u8 *)This->vtable->Unk69(
//                      This, *(s16 *)((u8 *)(*(s32 **)((u8 *)obj + 4)) + 0x32)) + 0xC)) + 0x14);
//         out->vx = coordA[0x18 / 4] + 0x5000;
//         out->vy = coordA[0x1C / 4];
//         out->vz = coordA[0x20 / 4] + 0x5000;
//         coordB = *(s32 **)((u8 *)(*(s32 **)((u8 *)obj + 0xC)) + 0x14);
//         out->rx = pos->x - out->vx;
//         out->ry = pos->y;
//         out->rz = pos->z - out->vz;
//         out->dx = (pos->x - coordB[0x18 / 4]) / 2048;
//         out->dz = (pos->z - coordB[0x20 / 4]) / 2048;
//         out->x = ((u16)pos->x - 0x400) - ((u16)coordB[0x18 / 4] + (out->dx * 2048));
//         out->y = (u16)pos->y;
//         out->obj = obj;
//         out->z = ((u16)pos->z - 0x400) - ((u16)coordB[0x20 / 4] + (out->dz * 2048));
//         return 0;
//     }
//     return 1;
// }
//

s16 func_8004C368(class_3ACC8_t *This, s8 *out, s32 val) {
    s16 d;

    d = *(s16 *)This->m_Unk25;
    *out = val % d;
    d = *(s16 *)This->m_Unk25;
    out[1] = val / d;
    return d;
}

s32 func_8004C3F0(class_3ACC8_t *This, s8 *Unk) {
    func_8004C368(This, Unk, *(s16 *)(*(s32 *)(This->m_Unk110 + 4) + 48));
  return This->m_Unk110;
}

s32 func_8004C434(class_3ACC8_t *This, int Unk) {
    s32 i = 0;
    s32 offset = 0xEC;
    char *ptr;
    s32 result;

    do {
        ptr = (char *)This + offset;
        
        if (*(s16 *)(*(s32 *)(ptr + 4) + 0x32) == Unk) {
            result = (s32)ptr;
            goto exit;
        }

        i++;
        result = i < 7;
        offset += 0x1C;
    } while (result);

exit:
    return result;
}

typedef struct {
    /* 0x00 */ s32 field0;
    /* 0x04 */ s32 field4;
    /* 0x08 */ s32 field8;
} func_8004C470_probe_t;

void *func_8004C470(class_3ACC8_t *This, func_8004C470_probe_t *arg1) {
    void *result;
    u8 *inner;
    s32 *coords;
    s32 i = 0;
    s32 range = 0xA000;
    s32 offset = 0;
    s32 c6;
    s32 c8;

    for (; i < 7; i += 1, offset -= 0x800) {
        result = This->vtable->Unk69(This, i);
        inner = *(u8 **)((u8 *)result + 0xC);
        coords = *(s32 **)((inner + 0x14));
        if ((c6 = coords[6], arg1->field0 >= c6) && arg1->field0 < c6 + range &&
            arg1->field8 >= coords[8] && arg1->field8 < (c8 = coords[8]) + range) {
            if (*(s32 *)(This->m_Unk25 + 4) == 0) {
                return result;
            }
            if (offset >= arg1->field4 && offset - 0x800 < arg1->field4) {
                return result;
            }
        }
    }
    return NULL;
}
s32 func_8004C588(class_3ACC8_t *This, s32 Unk) {
    s32 ret = 0;
    s32 i = 0;
    s32 offset = 0xEC;

    do {
        u8 *ptr = *(u8 **)((u8 *)This + offset + 4);

        if (*(s16 *)(ptr + 0x32) == Unk) {
            ret = i;
            break;
        }

        i++;
        offset += 0x1C;
    } while (i < 7);

    return ret;
}

s32 func_8004C5D0(class_3ACC8_t *This, s32 Unk) {
    s32 i;
    s32 offset;
    char *ptr;

    i = 0;
    offset = 0xEC;
    do {
        ptr = *(char**)((u8*)This + offset + 4);
        if (*(s16*)(ptr + 0x30) == Unk) {
            if (*(s16*)(ptr + 0x2C) != 0) {
                return i;
            }
        }
        i++;
        offset += 0x1C;
    } while (i < 7);

    return -1;
}

void func_8004C6A8(class_3ACC8_t *, s32, s16);
void func_8004CC74(class_3ACC8_t *);
void func_8004CE24(class_3ACC8_t *, s32);

void func_8004C620(class_3ACC8_t *This) {
    s32 doubled;

    if (This->m_Unk109 != 0) {
        doubled = This->m_Unk29_1 * 2;
        func_8004CE24(This, 0);
        if (*(s32 *)(This->m_Unk25 + 4) == 0) {
            func_8004C6A8(This, doubled, This->m_Unk29_2);
        } else {
            func_8004CC74(This);
        }
        func_8004CE24(This, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C6A8);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C93C);

/*
 * Near match (semantics exact, 91/97 insns, same opcode stream). The target
 * keeps This in $s1 and the line record in $s0 (reused as $s0=entry after the
 * wrap), with the entry base `count*12 + 0x8C` folded into one addu; gcc 2.6.3
 * here assigns This to $s4 and defers +0x8C into the first access
 * (`addu s1,s4,v0` / `addiu s0,s1,0x8C`), and leaves the line record in $a1.
 * Needs widened vtable Unk71 (s32 (*)(void*, s32), called with 2 args and the
 * result stored). Best C (8-arg wrap-to-12-byte-record formatter):
 *
 * s32 func_8004CAF0(class_3ACC8_t *arg0, line_t *arg1, s32 arg2, s32 arg3,
 *                   s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
 *     entry_t *entry;
 *     s32 count = arg2;
 *     s32 wrapped, start, total, next;
 *
 *     if (arg5 + arg7 >= 0x15) {
 *         wrapped = arg5 + arg7 - 0x14;
 *         arg1->m_UnkA = arg7 - wrapped;
 *         count += 1;
 *         entry = (entry_t *)((u8 *)arg0 + count * 0xC + 0x8C);
 *         if (arg4 < 0xA) { start = arg3 + 2; entry->m_Unk0 = Unk71(arg0, start); total = arg4 + 0xA; }
 *         else            { start = arg3 + 3; entry->m_Unk0 = Unk71(arg0, start); total = arg4 - 0xA; }
 *         entry->m_Unk4 = total;
 *         entry->m_UnkA = wrapped;
 *         next = entry->m_Unk4 + arg6;
 *         entry->m_Unk6 = 0;
 *         if (next >= 0x15) {
 *             count += 1;
 *             entry->m_Unk8 = (arg6 + 0x14) - next;
 *             entry = (entry_t *)((u8 *)arg0 + count * 0xC + 0x8C);
 *             entry->m_Unk0 = Unk71(arg0, start + 1);
 *             entry->m_Unk4 = 0; entry->m_Unk6 = 0;
 *             entry->m_Unk8 = next - 0x14; entry->m_UnkA = wrapped;
 *         } else {
 *             entry->m_Unk8 = arg6;
 *         }
 *     } else {
 *         arg1->m_UnkA = arg7;
 *     }
 *     return count;
 * }
 */

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CAF0);

typedef struct {
    /* 0x00 */ u8 pad[0x28];
    /* 0x28 */ s32 value;
    /* 0x2C */ s32 pad2;
} cc74_buf_t;

s32 func_8004CD38(s32 arg0, void *arg1);

void func_8004CC74(class_3ACC8_t *This) {
    cc74_buf_t buf;
    s32 unused;
    s32 next;

    This->vtable->Unk66(This, &buf, 0);
    This->m_Unk33 = 0;
    next = func_8004CDA4(This, unused, 0, buf.value);
    This->m_Unk33 = next;
    if (func_8004CD38(This->m_Unk118, &buf.pad[2]) != 0) {
        next = buf.value + 1;
        if (next < ((s16 *)This->m_Unk25)[1]) {
            This->m_Unk33 = func_8004CDA4(This, unused, This->m_Unk33, next);
        }
    }
    next = buf.value - 1;
    if (next >= 0) {
        This->m_Unk33 = func_8004CDA4(This, unused, This->m_Unk33, next);
    }
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CD38);

/*
 * Near match (semantics correct, wrong register allocation): the target begins
 * with `addu a2,a0,zero` and uses $a2 for the object pointer while $a0 is a
 * temp; gcc 2.6.3 here coalesces the pointer into $a0 and uses $v1 for the
 * `lh`. Tried local s16 / s32 / u8 pointer forms, m2c u8 temporaries, struct fields,
 * guarded/early-return/else-if and reversed comparisons: all compile to the
 * same 26-insn sequence without the $a2 copy (~20 variants).
 *
 * s32 func_8004CD38(s32 arg0, void *arg1) {
 *     s8 *q = (s8 *)arg1;
 *     s32 var_v0 = 1;
 *     if (arg0 != 0) {
 *         if (q[0] >= *(s16 *)arg0 && *(s32 *)(arg0 + 4) >= q[0]) {
 *             if (q[1] >= *(s16 *)(arg0 + 2)) {
 *                 var_v0 = *(s32 *)(arg0 + 8) < q[1];
 *             }
 *         }
 *     }
 *     return var_v0;
 * }
 */

s32 func_8004CDA4(class_3ACC8_t *This, s32 unused, s32 index, s32 arg3) {
    s32 *dest;
    s32 off;

    off = (index * 12) + 0x8C;
    dest = (s32 *)((u8 *)This + off);
    __builtin_memcpy(dest, D_80086990, 0xC);
    *dest = ((s32(*)(class_3ACC8_t *, s32))This->vtable->Unk72)(This, arg3);
    return index + 1;
}

void func_8004CE24(class_3ACC8_t *This, s32 arg1) {
    u8 *rec;
    u8 *sl;
    u8 *grid;
    u8 *q;
    s32 i;
    s32 j;
    s32 k;

    rec = (u8 *)This + 0x8C;
    for (i = 0; i < This->m_Unk33; i++) {
        sl = (u8 *)This + (*(s32 *)rec * 0x1C + 0xEC);
        if (*(s16 *)(*(u8 **)(sl + 4) + 0x2C) != 0) {
            grid = *(u8 **)(sl + 0x10) + *(s16 *)(rec + 4) * 4 + *(s16 *)(rec + 6) * 0x50;
            for (j = 0; j < *(s16 *)(rec + 0xA); j++) {
                for (k = 0; k < *(s16 *)(rec + 8); k++) {
                    if (arg1 != 0) {
                        *(s32 *)(*(u8 **)grid + 0x10) &= 0x7FFFFFFF;
                    } else {
                        *(s32 *)(*(u8 **)grid + 0x10) |= 0x80000000;
                    }
                    q = *(u8 **)(*(u8 **)grid + 0x38);
                    while (q != 0) {
                        if (arg1 != 0) {
                            *(s32 *)(q + 0x10) &= 0x7FFFFFFF;
                        } else {
                            *(s32 *)(q + 0x10) |= 0x80000000;
                        }
                        q = *(u8 **)(q + 0x38);
                    }
                    grid += 4;
                }
                grid += (0x14 - *(s16 *)(rec + 8)) * 4;
            }
        }
        rec += 0xC;
    }
}

void *func_8004CFA8(class_3ACC8_t *This) {
    return &This->m_Unk114;
}

void func_8004CFB0(class_3ACC8_t *This, s32 Unk) {
    This->m_Unk118 = Unk;
}

typedef struct scale_row {
    s16 unk0;
    s16 unk1;
    s16 unk2;
    s16 scale;
} scale_row_t;

void func_8004CFB8(class_3ACC8_t *This, s32 arg1, s32 arg2) {
    scale_row_t *table;
    scale_row_t *row;
    s32 scale;
    s32 prod;

    if (arg1 > 0) {
        table = (scale_row_t *)D_8008699C;
        if (arg2 != 0) {
            This->m_Unk120 = (s32)D_800869A8;
            goto use;
        }
    } else {
        table = (scale_row_t *)D_800869B4;
        if (arg2 != 0) {
            table = (scale_row_t *)D_800869C0;
        }
    }
    This->m_Unk120 = (s32)table;
use:
    row = (scale_row_t *)This->m_Unk120;
    scale = row->scale;
    if (arg1 < 0) {
        prod = scale * (~arg1 + 1);
    } else {
        prod = scale * arg1;
    }
    This->m_Unk119 = prod;
}

void func_8004D028(class_3ACC8_t *This) {
    s32 temp_v0;

    if (This->m_Unk119 > 0) {
        func_8004D140(This, func_8004D0D0, 0);
        temp_v0 = This->m_Unk119 - 1;
        This->m_Unk119 = temp_v0;
        if (temp_v0 == 0) {
            This->m_Unk119 = -1;
        }
    }
}

void func_8004D088(class_3ACC8_t *This) {
    if ( This->m_Unk119 )
  {
    func_8004D140(This, func_8004D108, 0);
    This->m_Unk119 = 0;
  }
}

void func_8004D0D0(class_3ACC8_t *This, s32 *Unk) {
    (*(void ( **)(s32 *, s32, s32))(*Unk + 72))(Unk, 0, This->m_Unk120);
}

// INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D108);
void func_8004D108(class_3ACC8_t *This, s32 *Unk) {
    (*(void ( **)(s32 *, s32, s32 *))(*Unk + 72))(Unk, 1, & D_800869CC);
}

void func_8004D1D0(class_3ACC8_t *This, void (*arg1)(class_3ACC8_t *, s32), void *arg2);

void func_8004D140(class_3ACC8_t *This, void (*arg1)(s32, s32), void (*arg2)(s32, s32)) {
    s32 i;
    s32 off;
    s32 ptr;

    i = 0;
    off = 0xEC;
    do {
        ptr = (s32)This + off;
        if (arg2 != NULL) {
            arg2((s32)This, ptr);
        }
        func_8004D1D0(This, arg1, (void *)ptr);
        i += 1;
        off += 0x1C;
    } while (i < 7);
}

void func_8004D1D0(class_3ACC8_t *This, void (*arg1)(class_3ACC8_t *, s32), void *arg2) {
    s32 *start;
    s32 *cursor;
    s32 *end;

    start = *(s32 **)((u8 *)arg2 + 0x10);
    end = (s32 *)((u8 *)start + 0x668);
    cursor = start;
    while (cursor < end) {
        arg1(This, *cursor++);
    }
}

class_3ACC8_vtable_t *func_8004D244(void) {
    return &D_800866E8;
}
