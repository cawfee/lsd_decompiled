#include "D294.h"

#include "base_class.h"

extern s32 func_8001F3A4(s32);

extern void *RotMatrix(s16 *, void *);

extern void GsInitCoordinate2(void *, void *);

extern void MulMatrix2(void *src, void *dst);

void func_8001EE04(void *arg0, void *arg1, s32 arg2, void *arg3);


// Maybe pad handling? unchecked

extern class_D294_vtable_t **D_8006B5CC;
extern s32 D_8006B684;
extern s32 D_8006B690;

class_D294_t *func_8001CA94() {
    class_D294_t *allocated = (class_D294_t *) memory_allocate_mem(0x44);

    if (allocated) {
        if (func_8001E57C()->Construct(allocated)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

void *func_8001CAF4(class_D294_t *This) {
    void *buffer;
    This->m_Unk4 = memory_allocate_mem(0x50);

    if (This->m_Unk4) {
        buffer = memory_allocate_mem(0x28);
        *((u32 *) This->m_Unk4 + 17) = buffer;

        if (buffer) {
            base_class_get_vtable()->base_class_construct(This);
            This->vtable = func_8001E57C();
            This->m_Unk7 = 0;
            This->m_Unk5 = 0;
            This->m_Unk2 = 0;
            *((u32 *) This->m_Unk4 + 18) = 0;
            This->vtable->Unk15(This);
            return This;
        }

        memory_free_mem(This->m_Unk4);
    }

    return NULL;
}

void func_8001CBA4(class_D294_t *This) {
    This->vtable->Unk19(This);
    This->vtable->Unk20(This);
    This->vtable->Unk22(This, 0);
    memory_free_mem(*((void **) This->m_Unk4 + 17));
    memory_free_mem(This->m_Unk4);
    base_class_get_vtable()->base_class_cleanup(This);
}

void func_8001CC48(class_D294_t *This, void **Unk) {
    base_class_get_vtable()->Unk3(This, Unk);

    if ((*(u32 *) *Unk & 0xF) == 9) {
        func_8001E770(This, Unk);
    }
}

void func_8001CCB4(class_D294_t *This, void **Unk) {
    if ((*(u32 *) *Unk & 0xF) == 9) {
        func_8001E7B0(This);
    }

    base_class_get_vtable()->Unk4(This, Unk);
}

void func_8001CD20(class_D294_t *This) {
    func_8001E7B0(This);
    base_class_get_vtable()->Unk5(This);
}

void func_8001CD60(class_D294_t *This, void **Unk2, s32 Unk3) {
    u32 value;
    base_class_get_vtable()->Unk13(This, Unk2, Unk3);

    value = *(u32 *) *Unk2 & 0xF;

    if (value == 2) {
        // Update buttons?
        This->vtable->Unk36(This, Unk2, Unk3);
    } else if (value == 5) {
        This->vtable->Unk37(This, Unk2, Unk3);
    } else if (value == 4) {
        This->vtable->Unk38(This, Unk2, Unk3);
    }
}

s32 func_8001CE30(class_D294_t *This) {
    This->m_Unk8 = 0;
    This->m_Unk3 = 0;
    GsInitCoordinate2(NULL, This->m_Unk4);
    This->vtable->Unk16(This, 1, &D_8006B684);
    This->vtable->Unk17(This, 1, &D_8006B690);
    *(s32 *)This->m_Unk4 = 1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/D294", func_8001CEB4);

s32 func_8001EC84(void *arg0);

void func_8001D008(class_D294_t *This, s32 mode, void *src) {
    s32 a;
    s32 b;
    s32 c;
    void *obj;
    s32 *dest;

    a = func_8001EC84(src);
    b = func_8001EC84((u8 *)src + 4);
    c = func_8001EC84((u8 *)src + 8);
    obj = This->m_Unk4;
    dest = *(s32 **)((u8 *)obj + 0x44);
    if (mode != 0) {
        dest[0] = (s16)a;
        dest[1] = (s16)b;
        dest[2] = (s16)c;
    } else {
        dest[0] += (s16)a;
        dest[1] += (s16)b;
        dest[2] += (s16)c;
    }
    *(s32 *)This->m_Unk4 = 0;
}

class_D294_t *func_8001D0EC(class_D294_t *This, void *arg1, s32 *arg2) {
    void *buf;

    if (This->m_Unk2 == 0) {
        buf = This->m_Unk4;
        This->m_Unk2 = (s32)arg1;
        *(s32 *)((u8 *)buf + 0x48) = *(s32 *)((u8 *)arg1 + 0x14);
        (*(void (**)(void *, void *))(*(s32 *)arg1 + 0x10))(arg1, This);
        buf = This->m_Unk4;
        if (arg2 != NULL) {
            *(s32 *)((u8 *)buf + 0x18) = arg2[0];
            *(s32 *)((u8 *)buf + 0x1C) = arg2[1];
            *(s32 *)((u8 *)buf + 0x20) = arg2[2];
        } else {
            *(s32 *)((u8 *)buf + 0x18) = 0;
            *(s32 *)((u8 *)buf + 0x1C) = 0;
            *(s32 *)((u8 *)buf + 0x20) = 0;
        }
        *(s32 *)This->m_Unk4 = 0;
    }
    return This;
}

class_D294_t *func_8001D1A4(class_D294_t *This) {
    void *obj;

    obj = (void *)This->m_Unk2;
    if (obj) {
        (*(void (**)(void *, class_D294_t *))(*(s32 *)obj + 0x14))(obj, This);
        *(s32 *)((u8 *)This->m_Unk4 + 0x48) = 0;
        This->m_Unk2 = 0;
    }
    return This;
}

void func_8001D204(class_D294_t *This) {
    void *obj;
    s32 cont;

    obj = NULL;
    do {
        This->vtable->Unk21(This, &obj, &cont);
        if (obj != NULL) {
            (*(void (**)(void *))(*(u32 *)obj + 0x50))(obj);
        }
    } while (cont != 0);
}

void func_8001D280(class_D294_t *This, void **arg1, s32 *arg2) {
    void *temp;

    do {
        if (*arg1 == NULL) {
            *arg2 = This->m_Unk0;
        }
        func_800183A0(arg1, (void **)arg2);
        temp = *arg1;
        if (temp != NULL && ((**(u32 **)temp) & 0xF) == 4 && *(void **)((u8 *)temp + 0xC) == This) {
            break;
        }
        if (*arg2 == 0) {
            *arg1 = NULL;
            break;
        }
    } while (1);
}

void func_8001D33C(void) {
}

s32 func_8001D344(class_D294_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk3, 31, 1, Unk == 0) == 0;
}

void func_8001D374(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 30, 1, Unk != 0);
}

void func_8001D3A0(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 28, 2, Unk);
}

void func_8001D3CC(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 6, 1, Unk == 0);
}

void func_8001D3F8(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 3, 3, Unk);
}

void func_8001D424(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 0, 3, Unk);
}

s32 func_8001D450(class_D294_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk3, 7, 1, Unk == 0) == 0;
}

void func_8001D480(class_D294_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk3, 9, 3, Unk);
}

s32 func_8001D4AC(class_D294_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk3, 8, 1, Unk == 0) == 0;
}

void *func_8001D4DC(class_D294_t *This, void *mtx, s32 negate) {
    s16 ang[4];
    u16 *src;

    src = *(u16 **)((u8 *)This->m_Unk4 + 0x44);
    if (negate != 0) {
        ang[0] = -src[8];
        ang[1] = -src[9];
        ang[2] = -src[10];
    } else {
        __builtin_memcpy(ang, src + 8, 8);
    }
    return RotMatrix(ang, mtx);
}

s32 func_8001D568(class_D294_t *This, s32 arg1) {
    u8 buf[0x38];

    if (arg1 < 4) {
        if (arg1 >= 2) {
            if (This->m_Unk7 != 0) {
                if (func_8001F3A4(This->m_Unk7) != 0) {
                    This->vtable->Unk34(This, buf);
                    return This->vtable->Unk35(This, buf, arg1);
                }
            }
        }
    }
#ifdef NON_MATCHING
    return 0;
#endif
}

void func_8001D600(class_D294_t *This, s32 Unk) {
    func_8001F51C(This->m_Unk7, Unk);
}

void func_8001D624(class_D294_t *This, s32 *arg1, s32 arg2) {
    void *p;
    class_D294_vtable_t *vt;

    p = arg1 + 1;
    func_8001EE04(p, p, *arg1 * 8, (u8 *)This->m_Unk4 + 0x24);
    vt = This->vtable;
    This->m_Unk9 = 0;
    This->m_Unk10 = 0;
    This->m_Unk11 = (s32)arg1;
    vt->Unk11(This, arg2);
    This->m_Unk11 = 0;
}

void func_8001D6A4(void) {
}

void func_8001D6AC(void) {
}

void func_8001D6B4(class_D294_t *This, s32 Unk1, s32 Unk2) {
    switch (Unk2) {
        case 2:
        case 3:
            This->vtable->Unk39(This, Unk1);
            break;
        
        case 4:
            This->m_Unk9 = Unk1;
            break;
        
        default:
            break;
    }
}


INCLUDE_ASM("asm/nonmatchings/D294", func_8001D714);

void func_8001D950(class_D294_t *This, void *arg1, void *arg2, void *arg3, s32 arg4) {
    u8 child_mtx[0x20];
    u8 mtx[0x20];
    class_D294_t *child;

    This->vtable->Unk32(This, mtx, 1);
    child = (class_D294_t *)This->m_Unk2;
    while (child != NULL) {
        child->vtable->Unk32(child, child_mtx, 1);
        MulMatrix2(child_mtx, mtx);
        child = (class_D294_t *)child->m_Unk2;
    }
    func_8001EE04(arg2, arg3, arg4, mtx);
    if (arg1 != NULL) {
        func_8001EE04(arg1, arg1, 1, mtx);
    }
}

INCLUDE_ASM("asm/nonmatchings/D294", func_8001DA28);

INCLUDE_ASM("asm/nonmatchings/D294", func_8001DDF4);

typedef struct func_8001E2E8_pt {
    s16 x;
    s16 y;
    s16 z;
} func_8001E2E8_pt_t;

typedef struct func_8001E2E8_box {
    s16 min_x;
    s16 min_y;
    s16 min_z;
    s16 max_x;
    s16 max_y;
    s16 max_z;
} func_8001E2E8_box_t;

s32 func_8001ECFC(func_8001E2E8_box_t *box, func_8001E2E8_pt_t *pt);
void func_8001E2E8(func_8001E2E8_pt_t *mid, func_8001E2E8_box_t *box, func_8001E2E8_pt_t *a, func_8001E2E8_pt_t *b);

s32 func_8001E110(func_8001E2E8_pt_t *mid, func_8001E2E8_box_t *box, func_8001E2E8_pt_t *a, func_8001E2E8_pt_t *b) {
    func_8001E2E8_pt_t half;
    s32 fa;
    s32 fb;
    s32 split;

    fa = func_8001ECFC(box, a);
    fb = func_8001ECFC(box, b);
    if ((fa & 0xFF) == 0) {
        if ((fb & 0xFF) == 0) {
            return 1;
        }
    } else if ((fb & 0xFF) == 0) {
        if (mid != NULL) {
            func_8001E2E8(mid, box, b, a);
        }
        return 3;
    }
    if ((fa & 0xFF) != 0) {
        goto func_8001E110_both;
    }
    if (mid != NULL) {
        func_8001E2E8(mid, box, a, b);
    }
    return 2;
func_8001E110_both:
    if (((fa & fb) & 0xFF) != 0) {
        return 0;
    }
    half.x = (a->x + b->x) >> 1;
    half.y = (a->y + b->y) >> 1;
    half.z = (a->z + b->z) >> 1;
    if ((a->x == half.x) && (a->y == half.y) && (a->z == half.z)) {
        return 0;
    }
    if (b->x != half.x) {
        goto func_8001E110_split;
    }
    if (b->y != half.y) {
        goto func_8001E110_split;
    }
    if (b->z == half.z) {
        goto func_8001E110_zero;
    }
func_8001E110_split:
    split = func_8001E110(mid, box, a, &half);
    if (split != 0) {
        return split;
    }
    split = func_8001E110(mid, box, &half, b);
    if (split != 0) {
        return split;
    }
func_8001E110_zero:
    return 0;
}

void func_8001E2E8(func_8001E2E8_pt_t *mid, func_8001E2E8_box_t *box, func_8001E2E8_pt_t *a, func_8001E2E8_pt_t *b) {
    func_8001E2E8_pt_t saved_a;
    func_8001E2E8_pt_t saved_b;
    func_8001E2E8_pt_t *slot;
    s32 flags;

    while (1) {
        mid->x = (a->x + b->x) >> 1;
        mid->y = (a->y + b->y) >> 1;
        mid->z = (a->z + b->z) >> 1;
        if ((mid->x == a->x) && (mid->y == a->y) && (mid->z == a->z)) {
            return;
        }
        if ((mid->x == b->x) && (mid->y == b->y) && (mid->z == b->z)) {
            return;
        }
        flags = 0;
        if (box->max_x < mid->x) {
            flags = 8;
        } else if (mid->x < box->min_x) {
            flags = 4;
        }
        if (box->max_y < mid->y) {
            flags |= 2;
        } else if (mid->y < box->min_y) {
            flags |= 1;
        }
        if (box->max_z < mid->z) {
            flags |= 0x20;
        } else if (mid->z < box->min_z) {
            flags |= 0x10;
        }
        slot = &saved_b;
        if ((flags & 0xFF) == 0) {
            goto func_8001E2E8_use_a;
        }
        b = slot;
        goto func_8001E2E8_copy;
    func_8001E2E8_use_a:
        slot = &saved_a;
        a = &saved_a;
    func_8001E2E8_copy:
        *slot = *mid;
    }
}

void func_8001E49C(void) {
}

INCLUDE_ASM("asm/nonmatchings/D294", func_8001E4A4);

class_D294_vtable_t *func_8001E57C(void) {
    return &D_8006B5CC;
}
