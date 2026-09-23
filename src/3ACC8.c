#include "3ACC8.h"
#include "D294.h"

extern class_3ACC8_vtable_t D_800866E8;

extern s8 D_800868FC[];
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
    func_8001E57C()->Unk13(This, Unk2, Unk3);

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
        ((void (*)(void *, s32))This->vtable->Unk11)(This, arg1);
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
    u8 m_Pad2[0xC];
    void (*Unk33)(void *);
} class_3ACC8_slot_obj_vtable_t;

typedef struct class_3ACC8_slot_obj {
    class_3ACC8_slot_obj_vtable_t *vtable;
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

typedef struct {
    s16 m_Flag;
    s16 m_Pad;
    class_3ACC8_slot_obj_t *m_Obj;
    class_3ACC8_slot_link_t *m_Link;
    u8 m_Rest[0x10];
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
        p = (s32 *)This->m_Unk57;
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
        This->vtable->Unk13(This);
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

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B44C);

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
        This->vtable->Unk11(This, 5);
    }
    return kind;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B700);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B930);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BA40);

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

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BD14);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BE54);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C0AC);

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

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C470);

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

s32 func_8004CDA4(class_3ACC8_t *This, s32 unused, s32 index, s32 arg3) {
    s32 *dest;
    s32 off;

    off = (index * 12) + 0x8C;
    dest = (s32 *)((u8 *)This + off);
    __builtin_memcpy(dest, D_80086990, 0xC);
    *dest = ((s32(*)(class_3ACC8_t *, s32))This->vtable->Unk72)(This, arg3);
    return index + 1;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CE24);

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
