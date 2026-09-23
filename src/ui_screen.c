#include "ui_screen.h"

#include "text_line.h"
#include "timer.h"

// Unknown class
// Owns main_menu?

extern void **D_8006E854;
extern ui_screen_vtable_t D_8006E730;

ui_screen_t *func_8003BE94(u32 Unk1, u32 Unk2, u32 Unk3) {
    ui_screen_t *allocated = (ui_screen_t *) memory_allocate_mem(0xA4);

    if (allocated) {
        func_8003DFBC()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_8003BF10(ui_screen_t *This, s32 Unk2, s32 Unk3, sound_t *Unk4) {
    timer_get_vtable()->timer_create(This);
    This->vtable = func_8003DFBC();
    This->vtable->Unk53(This, Unk2);

    if (Unk3) {
        This->m_Unk17 = sound_create(Unk3);
    } else {
        This->m_Unk17 = Unk4;
    }

    This->m_Unk16 = Unk3;
    This->vtable->Unk52(This, 0, 0);
    This->m_Unk31 = func_80044F30(0);
    This->m_Unk30 = func_80044CD4(0, This->m_Unk31);
    This->m_Unk29 = func_800441B4(This->m_Unk30, 1);
    This->vtable->Unk15(This);
}

void func_8003C008(ui_screen_t *This) {
    This->m_Unk29->vtable->base_class_destructor(This->m_Unk29);
    This->m_Unk30->vtable->init_800269F0(This->m_Unk30);
    This->m_Unk31->vtable->init_800269F0(This->m_Unk31);
    if (This->m_Unk16) {
        This->m_Unk17->vtable->init_800269F0(This->m_Unk17);
    }
    if (This->m_Unk27) {
        This->m_Unk28->vtable->Destruct(This->m_Unk28);
    }
    This->vtable->Unk54(This);
    timer_get_vtable()->base_class_cleanup(This);
}

extern char D_8006E860[];

void func_8003C11C(ui_screen_t *This) {
    ui_screen_vtable_t *vt;

    vt = This->vtable;
    vt->Unk26(This, -1);
    vt->Unk40(This, D_8006E860, D_8006E860 + 3, D_8006E860 + 6);
    vt->Unk38(This, 1);
    vt->Unk39(This, 1);
    This->m_Unk32 = 9;
    This->m_Unk9 = 3;
    This->m_Unk10 = 0x12C;
    This->m_Unk11 = 0x40;
    This->m_Unk38 = NULL;
    This->m_Unk39 = NULL;
    This->m_Unk12 = 1;
    This->m_HasIdleTimeout = 0;
}

s32 func_8003C1DC(ui_screen_t *This, s32 Unk2, s32 Unk3) {
    timer_get_vtable()->Unk16(This, Unk2, Unk3);
    return This->m_Unk13;
}

typedef struct func_8003C238_actor func_8003C238_actor_t;

typedef struct func_8003C238_actor_vtable {
    /* 0x00 */ u32 pad0[0x12];
    /* 0x48 */ void (*Unk17)(func_8003C238_actor_t *, s32);
    /* 0x4C */ void (*Unk18)(func_8003C238_actor_t *, s32);
    /* 0x50 */ void (*Unk19)(func_8003C238_actor_t *, s32);
    /* 0x54 */ u32 pad1[7];
    /* 0x70 */ void (*Unk27)(func_8003C238_actor_t *, s32, void *, void *, s32);
    /* 0x74 */ u32 pad2[6];
    /* 0x8C */ void (*Unk34)(func_8003C238_actor_t *);
} func_8003C238_actor_vtable_t;

struct func_8003C238_actor {
    func_8003C238_actor_vtable_t *vtable;
};

typedef struct func_8003C238_link_vtable {
    /* 0x00 */ u32 pad[0x1E];
    /* 0x78 */ void (*Unk29)(void *, void *, void *);
} func_8003C238_link_vtable_t;

typedef struct func_8003C238_link {
    func_8003C238_link_vtable_t *vtable;
} func_8003C238_link_t;

extern s32 D_8006E86C;

void func_8003C238(ui_screen_t *This) {
    func_8003C238_actor_t *actor;
    func_8003C238_actor_vtable_t *avt;
    func_8003C238_link_t *link;
    void *sym;

    actor = (func_8003C238_actor_t *)This->m_Unk5;
    avt = actor->vtable;
    This->vtable->Unk55(This, This->m_Unk4);
    This->m_Unk29->vtable->Unk18(This->m_Unk29, This->m_Unk4, 0);
    if (This->m_Unk33 != 0) {
        This->vtable->Unk56(This, (char *)&This->m_Unk35);
        This->m_Unk29->vtable->Unk45(This->m_Unk29, 1, (u8 *)&This->m_Unk35);
    }
    if (This->m_Unk28 == 0) {
        link = *(func_8003C238_link_t **)This->m_Unk2;
        link->vtable->Unk29(link, &This->m_Unk35, &D_8006E854);
    }
    link = *(func_8003C238_link_t **)This->m_Unk2;
    link->vtable->Unk29(link, &This->m_Unk35, 0);
    avt->Unk17(actor, This->m_Unk9);
    avt->Unk18(actor, This->m_Unk10);
    avt->Unk19(actor, This->m_Unk11);
    sym = &D_8006E86C;
    avt->Unk27(actor, This->m_Unk4, sym, sym, 0);
    avt->Unk34(actor);
    This->m_Unk13 = 0;
}

void func_8003C3D0(ui_screen_t *This) {
    s32 m_Unk5; // $s0

    m_Unk5 = This->m_Unk5;
    (*(void (**)(s32))(*(s32 *) m_Unk5 + 144))(m_Unk5);
    (*(void (**)(s32))(*(s32 *) m_Unk5 + 116))(m_Unk5);
    This->m_Unk29->vtable->Unk19(This->m_Unk29);
    if (This->m_Unk12) {
        (*(void (**)(s32, char *, s32))(**(s32 **) This->m_Unk2 + 120))(*(s32 *) This->m_Unk2,
                                                                        (char *) &This->m_Unk35 + 3, 0);
    }
}

// jump table
void func_8003C48C(ui_screen_t *This, s32 Unk2, s32 Unk3) {
    ui_screen_vtable_t *vtable;
    void (*fn)(void *);

    vtable = This->vtable;
    if (This->m_HasIdleTimeout) {
        switch (Unk3) {
            case 18:
                fn = vtable->Unk31;
                goto do_call;
            case 19:
                fn = vtable->Unk32;
                goto do_call;
            case 33:
                fn = vtable->Unk28;
                goto do_call;
            case 23:
                fn = vtable->Unk30;
                goto do_call;
            case 25:
                fn = vtable->Unk29;
            do_call:
                fn(This);
                break;
        }
    }
}

void func_8003C51C(ui_screen_t *This, void **Unk2, s32 Unk3) {
    ui_screen_vtable_t *vtable;

    vtable = This->vtable;
    timer_get_vtable()->timer_increment(This, Unk2, Unk3);

    if (This->m_HasIdleTimeout && This->m_TicksPassed > This->m_TimeoutIdleTime) {
        vtable->Unk23(This, 6);
    }

    switch (This->m_Unk7) {
        case 2:
            vtable->Unk23(This, 4);
            break;

        case 4:
            vtable->Unk42(This);
            break;

        case 7:
            vtable->Unk47(This);
            break;

        case 8:
            vtable->Unk23(This, 3);
            break;

        default:
            break;
    }
}

void func_8003C63C(ui_screen_t *This, s32 Unk2) {
    ui_screen_vtable_t *vtable;
    void (*fn)(void *);

    vtable = This->vtable;
    timer_get_vtable()->Unk23(This, Unk2);

    switch (Unk2) {
        case 5:
            vtable->Unk56(This, (char *)(This->m_Unk18 + 16));
            vtable->Unk59(This, *(s32 *)(This->m_Unk18 + 8), 0);
            This->m_TicksPassed = 0;
            This->m_HasIdleTimeout = 1;
            break;

        case 6:
            This->m_Unk13 = 1;
            fn = vtable->Unk36;
            goto do_call;

        case 4:
        case 7:
            This->m_TicksPassed = 0;
            This->m_HasIdleTimeout = 0;
            break;

        case 8:
            This->m_TicksPassed = 0;
            break;

        case 9:
        case 10:
        case 11:
        case 14:
        case 15:
        case 16:
        case 17:
            This->m_Unk7 = 5;
            This->m_TicksPassed = 0;
            if (Unk2 == 15) {
                goto do15;
            }
            if (Unk2 < 16) {
                if (Unk2 == 11) {
                    goto do11;
                }
            } else if (Unk2 == 17) {
                goto do17;
            }
            break;
        do11:
            fn = vtable->Unk35;
            goto do_call;
        do15:
            fn = vtable->Unk66;
            goto do_call;
        do17:
            fn = vtable->Unk67;
        do_call:
            fn(This);
            break;
    }
}

void func_8003C794(ui_screen_t *This, s32 Unk2) {
    This->m_TimeoutIdleTime = Unk2;

    if (Unk2 >= 0) {
        This->m_TimeoutIdleTime = 20 * Unk2;
    }
}

void func_8003C7B4(ui_screen_t *This, int Unk2) {
    if (This->m_Unk17) {
        This->m_Unk17->vtable->func_8002CA3C(This->m_Unk17, Unk2, 96, 96);
    }
}

void func_8003C7F4(ui_screen_t *This) {
    if (This->m_Unk18) {
        This->vtable->Unk27(This, 16);
        This->vtable->Unk23(This, 10);
    }
}

void func_8003C858(ui_screen_t *This) {
    s32 value;

    if (This->m_Unk18) {
        This->vtable->Unk27(This, 16);

        value = 15;

        if (This->m_HasIdleTimeout == 1) {
            value = 11;
        }

        This->vtable->Unk23(This, value);
    }
}

void func_8003C8D0(ui_screen_t *This) {
    if (This->m_Unk18) {
        if (This->m_HasIdleTimeout != 1) {
            This->vtable->Unk27(This, 16);
            This->vtable->Unk23(This, 17);
        }
    }
}

void func_8003C944(ui_screen_t *This) {
    void (*callback)(void);

    if (This->m_Unk18) {
        if (This->m_HasIdleTimeout == 1) {
            callback = This->vtable->Unk58;
        } else {
            if (This->m_HasIdleTimeout != 2) {
                return;
            }

            callback = This->vtable->Unk69;
        }

        callback();
    }
}

void func_8003C9B0(ui_screen_t *This) {
    void (*callback)(void);

    if (This->m_Unk18) {
        if (This->m_HasIdleTimeout == 1) {
            callback = This->vtable->Unk57;
        } else {
            if (This->m_HasIdleTimeout != 2) {
                return;
            }

            callback = This->vtable->Unk68;
        }

        callback();
    }
}

void func_8003CA1C(ui_screen_t *This) {
    void *ptr1;
    s32 index;
    void (*func_to_call)(ui_screen_t *, void *, s32);

    ptr1 = This->m_Unk18;
    index = This->m_Unk21;

    if (*(int *) (*(char **) ((char *) ptr1 + 0x24) + index * 4) != 0) {
        func_to_call = (void (*)(ui_screen_t *, void *, s32)) This->vtable->Unk65;
    } else {
        if (index != *(s32 *) ((char *) ptr1 + 0x0C)) {
            return;
        }
        func_to_call = (void (*)(ui_screen_t *, void *, s32)) This->vtable->Unk36;
    }

    func_to_call(This, ptr1, index);
}

void func_8003CA94(ui_screen_t *This) {
    if (This->m_Unk38) {
        This->m_Unk38(This->m_Unk39);
    }

    This->vtable->Unk23(This, 7);
}

void func_8003CAEC(ui_screen_t *This, void (*Callback)(void *), s32 Arg) {
    This->m_Unk38 = Callback;
    This->m_Unk39 = Arg;
}

void func_8003CAF8(ui_screen_t *This, s32 Unk) {
    ui_screen_vtable_t *vtable = This->vtable;

    switch (Unk) {
        case 0:
            This->m_Unk33 = NULL;
            break;

        case 1:
            This->m_Unk33 = vtable->Unk43;
            break;
    }
}

void func_8003CB30(ui_screen_t *This, s32 Unk) {
    ui_screen_vtable_t *vtable = This->vtable;

    switch (Unk) {
        case 0:
            This->m_Unk34 = 0;
            break;

        case 1:
            This->m_Unk34 = vtable->Unk48;
            break;
    }
}

void func_8003CB68(ui_screen_t *This, s8 *Unk2, s8 *Unk3, s8 *Unk4) {
    __builtin_memcpy((s8 *)&This->m_Unk35 + 0, Unk2, 3);
    __builtin_memcpy((s8 *)&This->m_Unk35 + 3, Unk3, 3);
    __builtin_memcpy((s8 *)&This->m_Unk35 + 6, Unk4, 3);
}

void func_8003CBB8(ui_screen_t *This, s32 Unk) {
    This->m_Unk32 = Unk;
}

s32 func_8003CBC0(ui_screen_t *This) {
    s32 (*callback)();
    s32 to_call;

    callback = This->m_Unk33;
    to_call = 1;
    if (callback) {
        to_call = callback();
    }
    if (to_call) {
        This->vtable->Unk23(This, 5);
    }
    return to_call;
}

s32 func_8003CC2C(ui_screen_t *This) {
    u8 buf[8];
    u32 v;
    u8 *c;

    v = This->m_TicksPassed * This->m_Unk32;
    c = (u8 *)&This->m_Unk35;
    buf[0] = v + c[0];
    buf[1] = v + c[1];
    buf[2] = v + c[2];
    This->vtable->Unk56(This, (char *)buf);
    This->m_Unk29->vtable->Unk45(This->m_Unk29, 1, buf);
    return ((u8)v >= 0x81u);
}

s32 func_8003CCDC(ui_screen_t *This) {
    s32 (*fp)(void);
    s32 v3;

    fp = This->m_Unk34;
    v3 = 1;

    if (fp == NULL || (v3 = fp(), v3 != 0)) {
        This->vtable->Unk23(This, 8);
    }

    return v3;
}

s32 func_8003CD48(ui_screen_t *This) {
    s32 v2;
    s8 v4[8];

    v2 = 128 - (This->m_TicksPassed * This->m_Unk32);

    v4[0] = v2;
    v4[1] = v2;
    v4[2] = v2;

    This->vtable->Unk56(This, v4);

    This->m_Unk29->vtable->Unk45(This->m_Unk29, 1, v4);

    return (u8) v2 >= 0x81;
}

void func_8003CDE0(ui_screen_t *This, s8 *Unk2, s32 Unk3) {
    if (Unk2 != NULL) {
        tim_image_t *new_texture_handle;

        if (This->m_Unk27 != NULL) {
            This->m_Unk28->vtable->Destruct(This->m_Unk28);
        }

        new_texture_handle = tim_image_create(Unk2);
        This->m_Unk28 = new_texture_handle;

        new_texture_handle->vtable->Unk14(new_texture_handle);
        This->m_Unk28->vtable->Unk7(This->m_Unk28);
    } else {
        This->m_Unk28 = (tim_image_t *)Unk3;
    }

    This->m_Unk27 = Unk2;
}

extern s32 D_8008A8E8[];
extern char D_8008A8F0[];
extern void *func_800404D0(u32, u32, u32);
extern int strlen(char *);

typedef struct func_8003CE98_arg {
    /* 0x00 */ char *path;
    /* 0x04 */ tim_image_t *tex;
    /* 0x08 */ u8 pad[0x14];
    /* 0x1C */ char **strings;
    /* 0x20 */ s32 pad2;
    /* 0x24 */ void **table;
} func_8003CE98_arg_t;

void func_8003CE98(ui_screen_t *This, func_8003CE98_arg_t *arg) {
    char **cursor;
    s32 n;
    s32 bytes;
    text_line_t **out;
    tim_image_t *tex;
    s32 i;
    void *entry;
    s32 len;

    This->m_Unk18 = (s32)arg;
    if (arg == NULL) {
        return;
    }
    cursor = arg->strings;
    n = 0;
    goto func_8003CE98_count;
func_8003CE98_more:
    n += 1;
func_8003CE98_count:
    if (*cursor != NULL) {
        cursor += 1;
        goto func_8003CE98_more;
    }
    bytes = n * 4;
    out = memory_allocate_mem(bytes);
    This->m_Unk20 = (s32)out;
    This->m_Unk22 = memory_allocate_mem(bytes);
    This->m_Unk23 = memory_allocate_mem(bytes);
    This->m_Unk24 = memory_allocate_mem(bytes);
    This->m_Unk19 = n;
    if (arg->path != NULL) {
        tex = tim_image_create(arg->path);
        tex->vtable->Unk14(tex);
        tex->vtable->Unk7(tex);
    } else {
        tex = arg->tex;
    }
    cursor = arg->strings;
    i = 0;
    if (*cursor != NULL) {
        do {
            entry = arg->table[i];
            len = strlen(*cursor);
            *out = func_800408CC((s32)tex, len, (s32)*cursor);
            out += 1;
            if (entry != NULL) {
                This->m_Unk21 = i;
                This->vtable->Unk61(This, entry, tex);
            }
            cursor += 1;
            i += 1;
        } while (*cursor != NULL);
    }
    This->m_Unk25 = (s32)func_800404D0((u32)D_8008A8E8, (u32)D_8008A8F0, 0);
    arg->tex = tex;
}

void func_8003D050(ui_screen_t *This) {
    void *unk18;
    int s1;
    void **s2;
    int unk19;
    void *unk18_member0;
    void *unk18_member4_arg;
    void *unk25_arg;
    void *loop_arg;
    char unused_stack_padding[8];

    (void) unused_stack_padding;

    unk18 = (void *) This->m_Unk18;
    if (unk18) {
        unk18_member0 = *(void **) unk18;
        if (unk18_member0) {
            unk18_member4_arg = *(void **) ((char *) unk18 + 4);
            (*(void (**)(void *))((char *) *(void **) unk18_member4_arg + 4))(unk18_member4_arg);
        }

        unk25_arg = (void *) This->m_Unk25;
        (*(void (**)(void *))((char *) *(void **) unk25_arg + 4))(unk25_arg);

        s1 = 0;

        unk19 = This->m_Unk19;
        s2 = (void **) This->m_Unk20;

        if (unk19 > 0) {
            do {
                if (*(void **) ((char *) *(void **) ((char *) (void *) This->m_Unk18 + 0x24) + s1 * 4)) {
                    This->m_Unk21 = s1;
                    This->vtable->Unk62(This);
                }

                loop_arg = *s2;
                (*(void (**)(void *))((char *) *(void **) loop_arg + 4))(loop_arg);

                s1++;
                s2++;
            } while (s1 < This->m_Unk19);
        }

        memory_free_mem(This->m_Unk24);
        memory_free_mem(This->m_Unk23);
        memory_free_mem(This->m_Unk22);
        memory_free_mem((void *) This->m_Unk20);
    }
}

void func_8003D194(void *this, s32 arg1) {
    char dummy_stack_padding[8];
    void *pUnk4C;
    s32 count;
    void **ppUnk54;
    s32 loop_var_s4;
    s32 i;
    int *pArray18;
    int *pArray24;
    void *pOther;
    void **vtable;

    if (&dummy_stack_padding[0] == &dummy_stack_padding[7]) {
    }

    pUnk4C = *(void **) ((char *) this + 0x4C);
    if (pUnk4C == NULL) {
        return;
    }

    ppUnk54 = *(void ***) ((char *) this + 0x54);
    count = *(s32 *) ((char *) this + 0x50);
    loop_var_s4 = *(s32 *) ((char *) pUnk4C + 0x20);

    if (count <= 0) {
        return;
    }

    i = 0;

    do {
        pArray18 = *(int **) ((char *) *(void **) ((char *) this + 0x4C) + 0x18);
        if (pArray18[i] == 0) {
            pOther = *ppUnk54;
            vtable = *(void ***) pOther;
            ((void (*)(void *, s32, s32)) vtable[0x4C / 4])(pOther, arg1, loop_var_s4);

            pArray24 = *(int **) ((char *) *(void **) ((char *) this + 0x4C) + 0x24);
            if (pArray24[i] != 0) {
                *(s32 *) ((char *) this + 0x58) = i;
                vtable = *(void ***) this;
                ((void (*)(void *, s32, s32)) vtable[0x100 / 4])(this, arg1, 0);
                goto if_path_updates;
            }
        } else {
            pOther = *ppUnk54;
            vtable = *(void ***) pOther;
            ((void (*)(void *)) vtable[0x50 / 4])(pOther);
        }

    if_path_updates:
        i++;
        ppUnk54++;
        loop_var_s4 += 8;

        count = *(s32 *) ((char *) this + 0x50);
    } while (i < count);
}

INCLUDE_ASM("asm/nonmatchings/ui_screen", func_8003D2CC);

void func_8003D3B0(ui_screen_t *This) {
    s32 v1;
    s32 n;

    if (This->m_Unk18) {
        v1 = This->m_Unk21;
        n = This->m_Unk19;
        v1 += 1;
        while (1) {
            if (v1 >= n) {
                v1 = 0;
            }
            if (v1 == This->m_Unk21) {
                break;
            }
            if (!(*(s32 **)((char *)This->m_Unk18 + 0x18))[v1++]) {
                v1 -= 1;
                break;
            }
        }
        This->vtable->Unk59(This, v1, 1);
    }
}

void func_8003D444(ui_screen_t *This) {
    s32 v1;

    if (This->m_Unk18) {
        v1 = This->m_Unk21;
        v1 -= 1;
        while (1) {
            if (v1 < 0) {
                v1 = This->m_Unk19 - 1;
            }
            if (v1 == This->m_Unk21) {
                break;
            }
            if (!(*(s32 **)((char *)This->m_Unk18 + 0x18))[v1--]) {
                v1 += 1;
                break;
            }
        }
        This->vtable->Unk59(This, v1, 1);
    }
}

void func_8003D4DC(ui_screen_t *This, s32 arg1, s32 arg2) {
    void *cur_obj;
    void *new_obj;

    if (This->m_Unk18) {
        cur_obj = ((void **)This->m_Unk20)[This->m_Unk21];
        new_obj = ((void **)This->m_Unk20)[arg1];
        if (This->m_Unk21 >= 0) {
            (*(void (**)(void *, char *))(*(u32 *)cur_obj + 0xB8))(
                cur_obj, (char *)This->m_Unk18 + 0x10);
        }
        (*(void (**)(void *, char *))(*(u32 *)new_obj + 0xB8))(
            new_obj, (char *)This->m_Unk18 + 0x13);
        This->m_Unk21 = arg1;
        if (arg2) {
            This->vtable->Unk27(This, 0);
        }
        This->vtable->Unk23(This, 9);
    }
}

s32 func_8003D5C0(ui_screen_t *This) {
    return This->m_Unk21;
}

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 index;
    /* 0x08 */ s32 pad[4];
    /* 0x18 */ char **names;
} ui_screen_name_list_t;

void func_8003D5CC(ui_screen_t *This, ui_screen_name_list_t *list, s32 ctx) {
    char **cursor;
    s32 count;
    s32 idx;
    text_line_t **dest;
    s32 len;

    idx = This->m_Unk21;
    cursor = list->names;
    count = 0;
    while (*cursor++ != 0) {
        count++;
    }
    dest = memory_allocate_mem(count * 4);
    This->m_Unk24[idx] = (s32)dest;
    This->m_Unk23[idx] = list->index;
    This->m_Unk22[idx] = count;
    cursor = list->names;
    if (*cursor != 0) {
        do {
            len = strlen(*cursor);
            *dest = func_800408CC(ctx, len, (s32)*cursor);
            cursor += 1;
            dest += 1;
        } while (*cursor != 0);
    }
}

void func_8003D6D4(ui_screen_t *This) {
    destroy_list(This->m_Unk24[This->m_Unk21], This->m_Unk22[This->m_Unk21]);
    memory_free_mem((void *)This->m_Unk24[This->m_Unk21]);
}

INCLUDE_ASM("asm/nonmatchings/ui_screen", func_8003D73C);

void func_8003D980(ui_screen_t *This, char *arg1) {
    s32 count;
    text_line_t **list;
    s32 i;
    text_line_t *obj;

    list = (text_line_t **)This->m_Unk24[This->m_Unk21];
    count = This->m_Unk22[This->m_Unk21];
    for (i = 0; i < count; i++) {
        obj = *list++;
        obj->vtable->Unk45(obj, arg1);
    }
}

void func_8003DA10(ui_screen_t *This) {
    s32 idx;
    void *obj;
    s32 *table;

    if (This->m_HasIdleTimeout == 1) {
        idx = This->m_Unk21;
        This->vtable->Unk63(This, This->m_Unk4, 1);
        obj = ((void **)This->m_Unk24[idx])[This->m_Unk23[idx]];
        table = *(s32 **)((char *)This->m_Unk18 + 0x24);
        (*(void (**)(void *, char *))(*(u32 *)obj + 0xB8))(
            obj, (char *)table[idx] + 8);
        This->m_HasIdleTimeout = 2;
        This->vtable->Unk23(This, 0xE);
    }
}

INCLUDE_ASM("asm/nonmatchings/ui_screen", func_8003DAD4);

void func_8003DCAC(ui_screen_t *This) {
    s32 idx;
    s32 sel;
    text_line_t **row;
    text_line_t *obj;
    s32 *words;
    s32 next;

    if (This->m_HasIdleTimeout != 2) {
        return;
    }
    idx = This->m_Unk21;
    sel = This->m_Unk23[idx];
    This->vtable->Unk63(This, This->m_Unk4, 0);
    row = (text_line_t **)This->m_Unk24[idx];
    obj = row[sel];
    obj->vtable->Unk45(obj, (char *)This->m_Unk18 + 0x10);
    words = *(s32 **)((char *)This->m_Unk18 + 0x24);
    next = ((s32 *)words[idx])[1];
    This->m_Unk23[idx] = next;
    obj = row[next];
    obj->vtable->Unk23(obj, 1);
    This->m_HasIdleTimeout = 1;
    This->vtable->Unk23(This, 0x11);
}

void func_8003DDC8(ui_screen_t *This) {
    s32 value;

    value = This->m_Unk23[This->m_Unk21];
    value++;

    if (value >= This->m_Unk22[This->m_Unk21]) {
        value = 0;
    }

    This->vtable->Unk70(This, value, 1);
}

void func_8003DE30(ui_screen_t *This) {
    s32 value;

    value = This->m_Unk23[This->m_Unk21];
    value--;

    if (value < 0) {
        value = This->m_Unk22[This->m_Unk21] - 1;
    }

    This->vtable->Unk70(This, value, 1);
}

void func_8003DE9C(ui_screen_t *This, s32 arg1, s32 arg2) {
    s32 idx;
    s32 sel;
    text_line_t **row;
    text_line_t *cur;
    text_line_t *other;
    s32 *words;

    idx = This->m_Unk21;
    sel = This->m_Unk23[idx];
    row = (text_line_t **)This->m_Unk24[idx];
    cur = row[sel];
    other = row[arg1];
    cur->vtable->Unk45(cur, (char *)This->m_Unk18 + 0x10);
    words = *(s32 **)((char *)This->m_Unk18 + 0x24);
    other->vtable->Unk45(other, (char *)words[idx] + 8);
    This->m_Unk23[idx] = arg1;
    if (arg2 != 0) {
        This->vtable->Unk27(This, 0);
    }
    This->vtable->Unk23(This, 9);
}

s32 func_8003DFA0(ui_screen_t *This) {
    return This->m_Unk23[This->m_Unk21];
}

ui_screen_vtable_t *func_8003DFBC(void) {
    return &D_8006E730;
}

void *func_8003DFCC(void) {
    return &D_8006E854;
}
