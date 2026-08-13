#include <psx/libgpu.h>

#include "326E8.h"

#include "D294.h"

extern class_326E8_vtable_t D_8006EE1C;

class_326E8_t *func_80041EE8(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    class_326E8_t *allocated = (class_326E8_t *) memory_allocate_mem(0xA0);

    if (allocated) {
        func_800422BC()->Construct(allocated, Unk1, Unk2, Unk3, Unk4, Unk5);
        return allocated;
    }

    return NULL;
}

void func_80041F88(class_326E8_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5, s32 Unk6) {
    func_8001E57C()->Construct(This);
    This->vtable = func_800422BC();
    This->vtable->Unk15(This, Unk2, Unk3, Unk4, Unk5, Unk6);
}

void func_8004202C(class_326E8_t *This, s32 Unk2, s32 Unk3, s32 *Unk4) {
    This->m_Unk17 = Unk2 + 44;
    __builtin_memcpy(&This->m_Unk18, Unk4, 12);
    func_8004208C(&This->m_Unk24, Unk3, Unk4, This->m_Unk17);
    This->m_Unk21 = 0;
}

void func_8004208C(class_326E8_unk24_t *a1, s32 a2, u8 *a3, u8 *a4) {
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

void func_80042170(class_326E8_t *This, s32 a2, u8 *a3) {
    s32 v4 = *(s16 *)(a3 + 8);
    s32 v5 = *(s16 *)(a3 + 10);
    
    v4 = ((v4 / v5) << 12) + (((v4 % v5) << 12) / v5);
    
    if (a2 != 0) {
        This->m_Unk24.m_Unk32 = v4;
    } else {
        This->m_Unk24.m_Unk32 += v4;
    }
}

s32 func_8004220C(class_326E8_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk24, 31, 1, Unk == 0) == 0;
}

void func_8004223C(class_326E8_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk24, 30, 1, Unk != 0);
}

void func_80042268(class_326E8_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk24, 28, 2, Unk);
}

void func_80042294(void) {
}

void func_8004229C(class_326E8_t *This, s8 *Data) {
    __builtin_memcpy(This->m_Unk24.m_Unk29, Data, 3);
}

class_326E8_vtable_t *func_800422BC(void) {
    return &D_8006EE1C;
}
