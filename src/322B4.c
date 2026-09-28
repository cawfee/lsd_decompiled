#include "322B4.h"

#include "3249C.h"

#include "base_class.h"

void func_8001CBA4(base_class_t *);
void func_8001CC48(base_class_t *, base_class_t *);
void func_8001CCB4(base_class_t *, base_class_t *);
void func_8001CD20(base_class_t *);
void func_8001CD60(base_class_t *, base_class_t *, s32);
void func_80042170(void *);
void func_8001D008(void *);
void class_3249C_run(void *, void *, void *);
void func_8001D1A4(void *);
void func_8001D204(void *);
void func_8001D280(void *);
void func_8001D33C(void *);
void func_8004220C(void *);
void func_8004223C(void *);
void func_80042268(void *);
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
void func_80042294(void *);
void func_8001D6B4(void *);
void func_8001D714(void *);
void func_8001D950(void *);
void func_8001DA28(void *);
void func_8001DDF4(void *);
void func_8001E49C(void *);
void func_8001E4A4(void *);
void func_8004229C(void *);
void class_3249C_set_offset(void *);
void class_3249C_set_anchor(void *);

void func_80041C4C(s8 *, s32);

void glyph_construct(void *, s32, u8);
void glyph_set_mode(void *, u8);
void glyph_set_char(void *, u8);
u8 glyph_get_char(class_322B4_t *);

class_322B4_vtable_t g_GLYPH_VTABLE = {
    0x1144,
    base_class_destructor,
    glyph_construct,
    func_8001CBA4,
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
    glyph_set_mode,
    func_80042170,
    func_8001D008,
    class_3249C_run,
    func_8001D1A4,
    func_8001D204,
    func_8001D280,
    func_8001D33C,
    func_8004220C,
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
    func_8004229C,
    class_3249C_set_offset,
    class_3249C_set_anchor,
    glyph_set_char,
    (void (*)(void *))glyph_get_char,
};

class_322B4_t *glyph_create(s32 Unk1, u8 Unk2) {
    class_322B4_t *allocated = (class_322B4_t *) memory_allocate_mem(0xAC);

    if (allocated) {
        glyph_get_vtable()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void glyph_construct(class_322B4_t *This, s32 Unk1, u8 Unk2) {
    s8 v3[16];

    func_80041C4C(v3, 0x20);
    class_3249C_get_vtable()->Construct(This, Unk1, (s32)v3, 0);
    This->vtable = glyph_get_vtable();
    This->vtable->Unk15(This, Unk2);
}

void glyph_set_mode(class_322B4_t *This, u8 Unk) {
    This->vtable->Unk48(This, Unk);
}

void glyph_set_char(class_322B4_t *This, u8 Unk) {
    s8 v3[16];

  This->m_Char = Unk;
  func_80041C4C(v3, Unk);
  This->m_Unk27[2] = v3[0];
  This->m_Unk27[3] = v3[2];
}

u8 glyph_get_char(class_322B4_t *This) {
    s8 pad[0x10];

    return This->m_Char;
}

class_322B4_vtable_t *glyph_get_vtable(void) {
    return &g_GLYPH_VTABLE;
}

extern s32 D_8006ED40[3];

void func_80041C4C(s8 *arg0, s32 arg1) {
    s32 *dest;

    dest = (s32 *)arg0;
    __builtin_memcpy(dest, D_8006ED40, 12);
    arg1 &= 0xFF;
    *(u16 *)(arg0 + 0) = *(u16 *)(arg0 + 0) + (arg1 & 0x1F) * 8;
    *(u16 *)(arg0 + 2) = *(u16 *)(arg0 + 2) + ((u32)arg1 >> 5) * 8;
}
