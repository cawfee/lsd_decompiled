#include "scene/scene_node.h"
#include "base/transform.h"

extern scene_node_vtable_t D_800878D4;

extern s32 D_8008ABA4[];
extern s32 D_8008ABA8[];

void func_800573CC(scene_node_t *This, s32 set, void *Unk);
scene_node_t *func_80057B54(scene_node_t *This, s32 Unk1, s16 *Unk2);
s32 func_80057784(scene_node_t *This, void *a, void *b, void *c, s32 d);
s32 func_80057954(scene_node_t *This, void *a, s32 b, s32 c, void *d, void *e);
s32 func_80057A18(scene_node_t *This, void *a, void *b, void *c, void *d);

scene_node_t *func_80056FE4() {
    scene_node_t *allocated = ALLOCATE_STRUCT(scene_node_t);

    if (allocated) {
        if (scene_node_get_vtable()->Construct(allocated)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

void *func_80057044(scene_node_t *This) {
    if (func_8001E57C()->Construct(This)) {
        This->vtable = scene_node_get_vtable();
        This->m_Unk16 = 0;
        This->m_Unk18 = 0;
        This->m_Unk19 = 0;
        This->vtable->Unk15(This);
        return This;
    }

    return NULL;
}

void func_800570B4(scene_node_t *This, void **Unk) {
    s32 value;

    func_8001E57C()->Attach(This, Unk);

    value = *(u32 *) *Unk;

    if ((value & 0xFFF) == 0x114) {
        This->m_Unk18 = Unk;
    } else if ((value & 0xF) == 5) {
        This->m_Unk19 = Unk;
    }
}

void func_80057130(scene_node_t *This, void **Unk) {
    s32 value;

    value = *(u32 *) *Unk;

    if ((value & 0xFFF) == 0x114) {
        This->m_Unk18 = 0;
    } else if ((value & 0xF) == 5) {
        This->m_Unk19 = 0;
    }

    func_8001E57C()->Detach(This, Unk);
}

void func_800571A8(scene_node_t *This) {
    This->m_Unk18 = 0;
    This->m_Unk19 = 0;
    func_8001E57C()->DetachAll(This);
}

void func_800571E8(scene_node_t *This) {
    This->m_Unk17_1 = 300;
    This->m_Unk20 = 0;
}

extern s32 class_FA50_is_active(s32);
extern void func_8001F66C(void *, s32, s32, s32);

void func_800571F8(scene_node_t *This, s32 arg1) {
    u8 buf[0x38];
    s32 height;
    s32 nonneg;
    s32 adjusted;
    void **obj;

    ((void (*)(void *, s32)) func_8001E57C()->Unk33)(This, arg1);
    if (arg1 >= 9) {
        return;
    }
    if (arg1 < 5) {
        return;
    }
    if (This->m_Unk7 == 0) {
        return;
    }
    if (class_FA50_is_active(This->m_Unk7) == 0) {
        return;
    }
    This->vtable->Unk34(This, buf);
    if (arg1 != 5) {
        s32 same;
        same = arg1 == 7;
        height = This->m_Unk17_1;
        nonneg = ~height;
        nonneg = (u32) nonneg >> 31;
        if (height >= 0) {
            adjusted = height + This->m_Unk20;
        } else {
            adjusted = height - This->m_Unk20;
        }
        func_8001F66C(buf, same, nonneg, adjusted);
    }
    This->vtable->Unk35(This, buf, arg1);
    obj = (void **) This->m_Unk9;
    if (obj == 0) {
        return;
    }
    if (*(u8 *) obj[0] != 0x34) {
        return;
    }
    ((void (*)(void **))(*(void **) ((u8 *) obj[0] + 0xE8)))(obj);
}

void func_80057320(scene_node_t *This, u8 **Unk) {
    u8 kind;

    kind = **Unk;
    if (kind == 0x34) {
        ((void (*)(void *)) This->vtable->Unk54)(This);
    } else if (kind == 0x24) {
        This->vtable->Unk55(This);
    }
}

void func_80057384(scene_node_t *This, void *Unk) {
    func_800573CC(This, 1, Unk);
}

void func_800573A8(scene_node_t *This, void *Unk) {
    func_800573CC(This, 0, Unk);
}

void func_800573CC(scene_node_t *This, s32 set, void *Unk) {
    s32 *obj;
    s32 *vec;

    obj = (s32 *) This->m_Unk4;
    vec = (s32 *) Unk;
    if (set != 0) {
        __builtin_memcpy(obj + 6, vec, 0xC);
    } else {
        obj[6] += vec[0];
        obj[7] += vec[1];
        obj[8] += vec[2];
    }
    *(s32 *) This->m_Unk4 = 0;
}

void func_80057444(scene_node_t *This, s16 *Unk) {
    s32 unk_struct[4];

    func_8001E58C(This, unk_struct, Unk);
    This->vtable->Unk46(This, unk_struct);
}

void func_8005748C(scene_node_t *This, s32 Unk1, s32 Unk2) {
    func_80057534(This, D_8008ABA8, Unk1, Unk2, 6);
}

void func_800574C4(scene_node_t *This, s32 Unk1, s32 Unk2) {
    func_80057534(This, D_8008ABA4, Unk1, Unk2, 7);
}

void func_800574FC(scene_node_t *This, s32 Unk1, s32 Unk2) {
    func_80057534(This, (char *) D_8008ABA4 + 2, Unk1, Unk2, 8);
}

void func_80057534(scene_node_t *This, s16 *out, s16 val, s32 flag, s32 mode) {
    s32 *mode_p;

    mode_p = &mode;
    *out = val;
    This->m_Unk17_1 = val;
    ((void (*)(void *, void *)) This->vtable->Unk47)(This, D_8008ABA4);
    *out = 0;
    if (flag != 0) {
        ((void (*)(void *, s32)) This->vtable->Unk33)(This, *mode_p);
    }
}

void func_800575B0(scene_node_t *This, s32 Unk1, s32 Unk2) {
    func_80057618(This, This->vtable->Unk48, Unk1, Unk2);
}

void func_800575E0(scene_node_t *This, s32 Unk1, s32 Unk2) {
    func_80057618(This, This->vtable->Unk49, Unk1, Unk2);
}

void func_80057610(void) {
}

void func_80057618(scene_node_t *This, void (*Fnc)(s32, s32, s32), s32 Unk1, s32 Unk2) {
    This->m_Unk9 = 0;
    Fnc(This, Unk1, Unk2);
    if (!This->m_Unk9) {
        func_80057668(This);
    }
}

s32 func_80057668(scene_node_t *This) {
    u8 sp18[0x30];
    u8 sp48[0x30];
    u8 sp78[0x10];
    u8 sp88[0x10];
    void *obj;
    s32 pos;
    s32 found;

    obj = This->m_Unk18;
    if (obj != NULL) {
        pos = This->m_Unk4 + 0x18;
        if (((s32(*)(void *, void *, s32))(*(u32 *) (*(u32 *) obj + 0x110)))(obj, sp18, pos) == 0) {
            found = func_80057954(This, sp88, pos, func_80057784(This, sp48, sp78, sp18, 1), sp48, sp78);
            This->m_Unk9 = found;
            if (found != 0) {
                This->vtable->Unk46(This, sp88);
                ((void (*)(void *, s32)) This->vtable->Unk33)(This, -1);
                return 1;
            }
            ((void (*)(void *, s32)) This->vtable->Unk33)(This, -2);
            return 0;
        }
    }
    return 0;
}

typedef struct scene_node_dir {
    s16 m_Unk0;
    s16 m_Unk2;
    s32 m_Unk4;
    s32 m_Unk8;
} scene_node_dir_t;

s32 func_80057784(scene_node_t *This, scene_node_dir_t *arg1, void **arg2, u8 *arg3, s32 arg4) {
    s32 x;
    s32 y;
    s32 v10;
    s32 v11;
    s32 v12;
    s32 v13;
    s32 v14;
    void *p;
    void *obj;
    void *v1;
    s32 s3;

    x = *(s8 *) (arg3 + 2);
    y = *(s8 *) (arg3 + 3);
    if ((arg4 & 1) == 0) {
        v10 = arg4 + 1;
        arg4 = v10;
    } else {
        v10 = arg4;
    }
    v11 = v10;
    v12 = x;
    v13 = 1;
    v14 = y;
    if (arg4 == 1) {
        arg1[0].m_Unk0 = x;
        arg1[0].m_Unk2 = y;
        arg1[0].m_Unk4 = v10;
        arg1[0].m_Unk8 = v10;
        p = *(void **) (arg3 + 0x24);
        arg2[0] = p;
        obj = (void *) This->m_Unk18;
        v1 = *(void **) ((u8 *) obj + 0x68);
        if (*(s32 *) ((u8 *) v1 + 4) == 1) {
            s3 = *(s16 *) (*(s32 *) ((u8 *) p + 4) + 0x32);
            if (s3 + 1 < *(s16 *) ((u8 *) v1 + 2)) {
                arg2[1] = (void *) ((s32(*)())(*(s32 *) (*(u32 *) obj + 0x118)))(obj, s3 + 1, y, p);
                v13 = 2;
                arg1[1] = arg1[0];
            }
            if (s3 - 1 >= 0) {
                arg2[v13] = (void *) ((s32(*)())(*(s32 *) (*(u32 *) obj + 0x118)))(obj, s3 - 1);
                arg1[v13] = arg1[0];
                v13++;
            }
            return v13;
        }
        return 1;
    }
    if (x == 0) {
        v11 = v10 - 1;
    } else {
        v12 = x - 1;
    }
    if (x == 0x13) {
        v11--;
    }
    if (y == 0x13) {
        v10--;
    } else {
        v14++;
    }
    arg1[0].m_Unk0 = v12;
    if (y == 0) {
        v10--;
    }
    arg1[0].m_Unk2 = v14;
    arg1[0].m_Unk4 = v11;
    arg1[0].m_Unk8 = v10;
    arg2[0] = *(void **) (arg3 + 0x24);
    return 1;
}

s32 func_80057954(scene_node_t *This, void *arg1, s32 arg2, s32 count, void *arg4, void *arg5) {
    s32 i;
    void **list;
    u8 *rec;
    void *obj;
    s32 result;

    i = 0;
    rec = arg4;
    list = (void **) arg5;
    while (i < count) {
        obj = *list;
        i++;
        if (*(s16 *) (*(s32 *) ((u8 *) obj + 4) + 0x2C) != 0) {
            result = func_80057A18(This, arg1, (void *) arg2, rec, obj);
            if (result != 0) {
                return result;
            }
        }
        rec += 0xC;
        list++;
    }
    return 0;
}

s32 func_80057A18(scene_node_t *This, void *a, void *b, void *c, void *d) {
    s32 *grid;
    s32 i;
    s32 j;
    s32 next;

    grid = (s32 *) (*(s32 *) ((u8 *) d + 0x10) + *(s16 *) ((u8 *) c + 2) * 0x50 + *(s16 *) ((u8 *) c + 0) * 4);
    for (i = 0; i < *(s32 *) ((u8 *) c + 8); i++) {
        for (j = 0; j < *(s32 *) ((u8 *) c + 4); j++) {
            if (func_80057B54((scene_node_t *) *grid, (s32) a, (s16 *) b) != 0) {
                return *grid;
            }
            next = *(s32 *) ((u8 *) *grid + 0x38);
            if (next != 0) {
                do {
                    if (func_80057B54((scene_node_t *) next, (s32) a, (s16 *) b) != 0) {
                        return next;
                    }
                    next = *(s32 *) ((u8 *) next + 0x38);
                } while (next != 0);
            }
            grid++;
        }
        grid = (s32 *) ((u8 *) grid - (*(s32 *) ((u8 *) c + 4) * 4 + 0x50));
    }
    return 0;
}

scene_node_t *func_80057B54(scene_node_t *This, s32 Unk1, s16 *Unk2) {
    if (This && func_8001E7BC(This, Unk1, Unk2)) {
        return This;
    }
    return 0;
}

void func_80057B90(scene_node_t *This, void **Unk2, s32 Unk3) {
    func_8001E57C()->Unk38(This, Unk2, Unk3);
    if (Unk3 < 9) {
        if (Unk3 >= 5) {
            ((void (*)(void *, void **, s32)) This->vtable->Unk39)(This, Unk2, Unk3);
        }
    }
}

void func_80057C14(scene_node_t *This, s32 Unk2, s32 Unk3) {
    func_8001E57C()->Unk38(This, Unk2, Unk3);
}

void func_80057C6C(scene_node_t *This, s16 Unk) {
    This->m_Unk17_1 = Unk;
}

void func_80057C74(void) {
}

void func_80057C7C(scene_node_t *This, s32 Unk) {
    This->m_Unk20 = Unk;
}

scene_node_vtable_t *scene_node_get_vtable(void) {
    return &D_800878D4;
}
