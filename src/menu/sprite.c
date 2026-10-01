#include <psx/libgpu.h>

#include "menu/sprite.h"

#include "base/transform.h"

void func_8001CBA4(base_class_t *);
void func_8001CC48(base_class_t *, base_class_t *);
void func_8001CCB4(base_class_t *, base_class_t *);
void func_8001CD20(base_class_t *);
void func_8001CD60(base_class_t *, base_class_t *, s32);
void func_8001D008(void *);
void func_8001D0EC(void *);
void func_8001D1A4(void *);
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

void func_80041F88(void *, s32, s32, s32, s32, s32);
void func_8004202C(void *, s32, s32, s32, s32, s32);
void func_80042170(void *);
s32 func_8004220C(sprite_t *, s32);
void func_8004223C(void *);
void func_80042268(void *);
void func_80042294(void *);
void func_8004229C(void *);

sprite_vtable_t D_8006EE1C = {
    0x44,
    base_class_destructor,
    func_80041F88,
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
    func_8004202C,
    func_80042170,
    func_8001D008,
    func_8001D0EC,
    func_8001D1A4,
    func_8001D204,
    func_8001D280,
    func_8001D33C,
    (void (*)(void *))func_8004220C,
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
};

sprite_t *func_80041EE8(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    sprite_t *allocated = (sprite_t *) memory_allocate_mem(0xA0);

    if (allocated) {
        func_800422BC()->Construct(allocated, Unk1, Unk2, Unk3, Unk4, Unk5);
        return allocated;
    }

    return NULL;
}

void func_80041F88(sprite_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5, s32 Unk6) {
    func_8001E57C()->Construct(This);
    This->vtable = func_800422BC();
    This->vtable->Unk15(This, Unk2, Unk3, Unk4, Unk5, Unk6);
}

void func_8004202C(sprite_t *This, s32 Unk2, s32 Unk3, s32 *Unk4) {
    This->m_Unk17 = Unk2 + 44;
    __builtin_memcpy(&This->m_Unk18, Unk4, 12);
    func_8004208C(&This->m_Unk24, Unk3, Unk4, This->m_Unk17);
    This->m_Unk21 = 0;
}

void func_8004208C(sprite_unk24_t *a1, s32 a2, u8 *a3, u8 *a4) {
    u32 v6;
    u32 v8;
    u16 v10;

    v6 = *(u32*)a4;
    a1->m_Unk25_lo = 0;
    a1->m_Unk25_hi = 0;
    v8 = v6 & 3;
    a1->m_Unk24 = v8 << 24;

    a1->m_Unk26_lo = *(u16*)(a3 + 4);
    a1->m_Unk26_hi = *(u16*)(a3 + 8);

    a1->m_Unk30_lo = a1->m_Unk26_lo >> 1;
    a1->m_Unk30_hi = a1->m_Unk26_hi >> 1;

    a1->m_Unk27_tpage = GetTPage(v8, a2, *(s16*)(a4 + 4), *(s16*)(a4 + 6));

    a1->m_Unk27_b2 = a3[0];
    a1->m_Unk27_b3 = a3[2];

    a1->m_Unk28_lo = *(u16*)(a4 + 16);
    v10 = *(u16*)(a4 + 18);

    a1->m_Unk29[2] = 0x80;
    a1->m_Unk29[1] = 0x80;
    a1->m_Unk29[0] = 0x80;

    a1->m_Unk32 = 0;
    a1->m_Unk31_lo = 0x1000;
    a1->m_Unk31_hi = 0x1000;

    a1->m_Unk28_hi = v10;
}

void func_80042170(sprite_t *This, s32 a2, u8 *a3) {
    s32 v4 = *(s16 *)(a3 + 8);
    s32 v5 = *(s16 *)(a3 + 10);
    
    v4 = ((v4 / v5) << 12) + (((v4 % v5) << 12) / v5);
    
    if (a2 != 0) {
        This->m_Unk24.m_Unk32 = v4;
    } else {
        This->m_Unk24.m_Unk32 += v4;
    }
}

s32 func_8004220C(sprite_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk24, 31, 1, Unk == 0) == 0;
}

void func_8004223C(sprite_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk24, 30, 1, Unk != 0);
}

void func_80042268(sprite_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk24, 28, 2, Unk);
}

void func_80042294(void *) {
}

void func_8004229C(sprite_t *This, s8 *Data) {
    __builtin_memcpy(This->m_Unk24.m_Unk29, Data, 3);
}

sprite_vtable_t *func_800422BC(void) {
    return &D_8006EE1C;
}
