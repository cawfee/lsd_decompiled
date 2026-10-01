#include "graphics/effect_base.h"

#include "base/transform.h"

extern effect_base_vtable_t D_8006EAC0;
extern s8 D_8008A924[];

effect_base_t *effect_base_create(u32 Unk1, u32 Unk2, u32 Unk3) {
    effect_base_t *allocated = (effect_base_t *) memory_allocate_mem(0x6C);

    if (allocated) {
        func_800408BC()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_8004054C(effect_base_t *This, u32 Unk1, u32 Unk2, u32 Unk3) {
    func_8001E57C()->Construct(This);
    This->vtable = func_800408BC();
    This->vtable->Unk15(This, Unk1, Unk2, Unk3);
}

void func_800405D0(effect_base_t *This, u16 *Data, s8 *Color, s32 Unk3) {
    effect_base_vtable_t *vtable;

    This->m_Unk16 = Unk3;
    This->m_Unk17 = 1;
    This->m_Unk18 = 0;
    This->m_Unk21 = 0;
    This->m_Unk22[0] = 0;
    This->m_Unk22[1] = 0;
    This->m_Unk23[0] = Data[0];
    This->m_Unk23[1] = Data[2];
    vtable = This->vtable;
    if (Color == NULL) {
        Color = D_8008A924;
    }
    vtable->set_color(This, 1, Color);
    This->vtable->Unk50(This, 0xD);
}

void func_80040664(effect_base_t *This, s32 Unk1, s32 Unk2) {
    if (This->m_Unk2 == 0) {
        ((void (*)(void *, s32, s32)) func_8001E57C()->Unk18)(This, Unk1, 0);
        This->vtable->set_offset(This, Unk2);
    }
}

s32 func_800406E4(effect_base_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk21, 31, 1, Unk == 0) == 0;
}

void func_80040714(effect_base_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk21, 30, 1, Unk != 0);
}

void func_80040740(effect_base_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk21, 28, 2, Unk);
}

void func_8004076C(effect_base_t *This, s32 Unk1, s32 Unk2) {
    func_80040790(This, (s8 *) &This->m_Unk24, (s8 *) Unk2, Unk1);
}

void func_80040790(effect_base_t *This, s8 *dst, s8 *src, s32 set) {
    s8 *out;

    out = dst;
    if (set) {
        __builtin_memcpy(out, src, 3);
    } else {
        ((u8 *) out)[0] += ((u8 *) src)[0];
        ((u8 *) out)[1] += ((u8 *) src)[1];
        ((u8 *) out)[2] += ((u8 *) src)[2];
    }
}

void func_800407F8(effect_base_t *This, s32 *Unk) {
    if (This->m_Unk2) {
        __builtin_memcpy(&This->m_Unk19, Unk, 8);
    }
}

void func_80040824(effect_base_t *This, s16 *Data) {
    if (This->m_Unk2) {
        This->m_Unk23[0] = Data[0];
        This->m_Unk23[1] = Data[2];
    }
}

void func_80040854(effect_base_t *This, s32 Unk2, s32 Unk3, s32 Unk4) {
    This->vtable->attach_to(This, Unk2, Unk3);
    This->m_Unk17 = 0;
    This->m_Unk18 = Unk4;
}

void func_800408A0(effect_base_t *This, s32 Unk) {
    This->m_Unk16 = Unk;
}

void func_800408A8(effect_base_t *This, s8 Unk) {
    This->m_Unk25 = (1 << Unk) - 1;
}

effect_base_vtable_t *func_800408BC(void) {
    return &D_8006EAC0;
}
