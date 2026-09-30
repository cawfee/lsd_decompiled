#include "text_line.h"
#include "glyph.h"

#include "base_class.h"

void func_8001CC48(base_class_t *, base_class_t *);
void func_8001CCB4(base_class_t *, base_class_t *);
void func_8001CD20(base_class_t *);
void func_8001CD60(base_class_t *, base_class_t *, s32);
void func_8001D008(void *);
void func_8001D204(void *);
void func_8001D280(void *);
void func_8001D33C(void *);
void func_8001D3CC(void *);
void func_8001D3F8(void *);
void func_8001D424(void *);
void func_8001D450(void *);
void func_8001D480(void *);
void func_8001D4AC(void *);
void func_8001D4DC(void *);
void func_8001D568(void *);
void func_8001D600(void *);
void func_8001D624(void *);
void func_8001D6A4(void *);
void func_8001D6B4(void *);
void func_8001D714(void *);
void func_8001D950(void *);
void func_8001DA28(void *);
void func_8001DDF4(void *);
void func_8001E49C(void *);
void func_8001E4A4(void *);
void sprite_node_set_anchor(void *);
void func_80042170(void *);
void func_8004223C(void *);
void func_80042268(void *);
void func_80042294(void *);

void text_line_construct(void *, s32, s32, s32);
void text_line_cleanup(base_class_t *);
void func_80040A88(void *, s32);
void func_80040AE8(void *, s32, void *);
void func_80040C00(void *);
s32 func_80040CD0(text_line_t *, s32, s32);
void func_80040D74(void *, char *);
void func_80040E14(void *);
s32 func_80040EDC(text_line_t *, u8, s32);
void func_80040F20(void *);
void text_line_set_string(void *, char *);
void func_80040FA0(void *);
void text_line_set_spacing(void *);
s8 *itoa(s32);
char *strcpy(char *, char *);
s32 strlen(char *);
void *memset(void *, s32, u32);

text_line_vtable_t g_TEXT_LINE_VTABLE = {
    0x11144,
    base_class_destructor,
    text_line_construct,
    text_line_cleanup,
    func_8001CC48,
    func_8001CCB4,
    func_8001CD20,
    base_class_iter_children,
    base_class_add_parent,
    base_class_remove_parent,
    base_class_clear_parents,
    base_class_iter_parents,
    base_class_notify,
    base_class_nop,
    func_8001CD60,
    NULL,
    func_80040A88,
    func_80042170,
    func_8001D008,
    func_80040AE8,
    func_80040C00,
    func_8001D204,
    func_8001D280,
    func_8001D33C,
    (void (*)(void *, s32))func_80040CD0,
    func_8004223C,
    func_80042268,
    func_8001D3CC,
    func_8001D3F8,
    func_8001D424,
    func_8001D450,
    func_8001D480,
    func_8001D4AC,
    func_8001D4DC,
    func_8001D568,
    func_8001D600,
    func_8001D624,
    func_8001D6A4,
    func_80042294,
    func_8001D6B4,
    func_8001D714,
    func_8001D950,
    func_8001DA28,
    func_8001DDF4,
    func_8001E49C,
    func_8001E4A4,
    func_80040D74,
    func_80040E14,
    sprite_node_set_anchor,
    (void (*)(void *))func_80040EDC,
    func_80040F20,
    text_line_set_string,
    func_80040FA0,
    text_line_set_spacing,
};

text_line_t *text_line_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    text_line_t *allocated = (text_line_t *) memory_allocate_mem(0xB8);

    if (allocated) {
        text_line_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void text_line_construct(text_line_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    s32 i;
    s32 *arr;

    glyph_get_vtable()->Construct(This, Unk1, 0x20);
    This->vtable = text_line_get_vtable();
    This->m_GlyphCount = Unk2;
    This->m_Length = Unk2;
    This->m_StartIndex = 0;
    This->m_GapPosition = 0;
    arr = memory_allocate_mem(Unk2 * 4);
    if (arr != NULL) {
        This->m_Glyphs = arr;
        for (i = 0; i < Unk2; i++) {
            *arr = (s32)glyph_create(Unk1, 0x20);
            arr += 1;
        }
        This->vtable->Unk15(This, Unk3);
    }
}

void text_line_cleanup(text_line_t *This) {
    destroy_list(This->m_Glyphs, This->m_GlyphCount);
    This->m_Glyphs = memory_free_mem(This->m_Glyphs);
    glyph_get_vtable()->Cleanup(This);
}

void func_80040A88(text_line_t *This, s32 Unk) {
    ((void (*)(void *, s32))This->vtable->Unk52)(This, 7);
    ((void (*)(void *, s32))This->vtable->Unk50)(This, Unk);
}

void func_80040AE8(text_line_t *This, s32 arg1, s32 *arg2) {
    s32 pos[2];
    u8 start;
    class_glyph_t **p;
    s32 i;
    class_glyph_t *obj;

    if (This->m_Visible == 0) {
        ((void (*)(void *, s32, s32 *))glyph_get_vtable()->Unk18)(This, arg1, arg2);
        __builtin_memcpy(pos, arg2, 8);
        start = (u8)This->m_StartIndex;
        p = (class_glyph_t **)((u8 *)This->m_Glyphs + (start * 4));
        i = start;
        if (i < (s32)(start + (u8)This->m_Length)) {
            do {
                if ((u8)This->m_GapPosition != 0 && i == (u8)This->m_GapPosition) {
                    pos[0] += 0x10;
                }
                obj = *p;
                ((void (*)(void *, void *, s32 *))obj->vtable->Unk18)(obj, This, pos);
                pos[0] += This->m_Spacing;
                p++;
            } while (++i < (s32)((u8)This->m_StartIndex + (u8)This->m_Length));
        }
    }
}

void func_80040C00(text_line_t *This) {
    u8 start;
    void **p;
    s32 i;
    void *obj;

    if (This->m_Visible != 0) {
        if (This->m_Glyphs != 0) {
            start = (u8)This->m_StartIndex;
            p = (void **)((u8 *)This->m_Glyphs + (start * 4));
            i = start;
            if (i < (s32)(start + (u8)This->m_Length)) {
                do {
                    obj = *p;
                    p++;
                    (*(void (**)(void *))(*(u32 *)obj + 0x50))(obj);
                    i++;
                } while (i < (s32)((u8)This->m_StartIndex + (u8)This->m_Length));
            }
        }
        ((void (*)(void *))glyph_get_vtable()->Unk19)(This);
    }
}

s32 func_80040CD0(text_line_t *This, s32 arg1, s32 arg2) {
    u8 start;
    void **p;
    s32 i;

    start = (u8)This->m_StartIndex;
    p = (void **)((u8 *)This->m_Glyphs + (start * 4));
    i = start;
    if (i < (s32)(start + (u8)This->m_Length)) {
        do {
            void *obj = *p;
            p++;
            i++;
            arg2 = (*(s32 (**)(void *, s32))(*(u32 *)obj + 0x60))(obj, arg1);
        } while (i < (s32)((u8)This->m_StartIndex + (u8)This->m_Length));
    }
    return arg2;
}

void func_80040D74(text_line_t *This, s32 arg) {
    u8 start;
    void **p;
    s32 i;

    start = (u8)This->m_StartIndex;
    p = (void **)((u8 *)This->m_Glyphs + (start * 4));
    i = start;
    if (i < (s32)(start + (u8)This->m_Length)) {
        do {
            void *obj = *p;
            p++;
            (*(void (**)(void *, s32))(*(u32 *)obj + 0xB8))(obj, arg);
            i++;
        } while (i < (s32)((u8)This->m_StartIndex + (u8)This->m_Length));
    }
}

void func_80040E14(text_line_t *This, s32 *arg1) {
    s32 pos[2];
    class_glyph_t **p;
    s32 i;
    class_glyph_t *obj;

    if (This->m_Visible != 0) {
        i = 0;
        ((void (*)(void *, s32 *))glyph_get_vtable()->Unk46)(This, arg1);
        __builtin_memcpy(pos, arg1, 8);
        p = (class_glyph_t **)This->m_Glyphs;
        if (i < (s32)This->m_GlyphCount) {
            do {
                obj = *p;
                ((void (*)(void *, s32 *))obj->vtable->Unk46)(obj, pos);
                pos[0] += This->m_Spacing;
                p++;
            } while (++i < (s32)This->m_GlyphCount);
        }
    }
}

s32 func_80040EDC(text_line_t *This, u8 Unk2, s32 Unk3) {
    return (*(int ( **)(s32, s32))(**((s32 **)This->m_Glyphs + Unk3) + 196))(
           *((s32 *)This->m_Glyphs + Unk3),
           Unk2);
}

void func_80040F20(void *) {
}

void text_line_set_string(text_line_t *This, u8 *Str) {
    void **arr;

    arr = This->m_Glyphs;
    if (Str != NULL && *Str != 0) {
        do {
            void **obj = *arr;
            (*(void (**)(void **, u8))(*(u32 *)obj + 0xC4))(obj, *Str);
            Str += 1;
            arr += 1;
        } while (*Str != 0);
    }
}

void func_80040FA0(void *) {
}

void text_line_set_spacing(text_line_t *This, s32 Unk) {
    This->m_Spacing = Unk;
}

text_line_vtable_t *text_line_get_vtable(void) {
    return &g_TEXT_LINE_VTABLE;
}

s8 *func_80040FC0(s8 *arg0, u8 *arg1) {
    u32 c;
    s8 *out;
    u8 *p;

    p = arg1 + 1;
    if (arg1[0] != 0) {
        u32 forty;

        forty = 0x40;
        out = arg0;
        for (;;) {
            out++;
            c = p[0];
            arg0++;
            out[-1] = (c >= 0x80 || c == forty) ? c - 0x20 : c - 0x1F;
            p++;
            if (*p++ == 0) {
                break;
            }
        }
    }
    *arg0 = 0;
    return arg0;
}

u8 *func_80041020(u8 *arg0, u8 *arg1) {
    u32 c;

    if (*arg1 != 0) {
        do {
            *arg0++ = (*arg1 >= 0x30) ? 0x82 : 0x81;
            c = *arg1;
            *arg0++ = (c >= 0x60 || c == 0x20) ? c + 0x20 : c + 0x1F;
            arg1++;
        } while (*arg1 != 0);
    }
    *arg0 = 0;
    return arg0;
}

/*
 * Best-known C (byte-identical except register allocation of buf/len):
 * target uses buf=$s3, pad=$s1, len=$s0; gcc 2.6.3 assigns buf=$s0,
 * pad=$s1, len=$s3 for every source ordering tried (declaration order,
 * nested strcpy, pointer aliases, named/nested len, VLA size via len).
 *
 * u8 *func_8004109C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
 *     s32 len;
 *     char buf[arg2 + 1];
 *     char pad[arg2 + 1];
 *
 *     len = arg2 - strlen(strcpy(buf, (char *)itoa(arg1)));
 *     if (arg3 == 0) {
 *         memset(pad, '0', arg2);
 *         strcpy(pad + len, buf);
 *     }
 *     return func_80041020(arg0, (u8 *)(arg3 == 0 ? pad : buf));
 * }
 */
INCLUDE_ASM("asm/nonmatchings/text_line", func_8004109C);
