#include "30CD0.h"

extern class_30CD0_vtable_t D_8006EAC0;

class_30CD0_t *func_800404D0(u32 Unk1, u32 Unk2, u32 Unk3) {
    class_30CD0_t *allocated = (class_30CD0_t *) memory_allocate_mem(0x6C);

    if (allocated) {
        func_800408BC()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/30CD0", func_8004054C);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_800405D0);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_80040664);

s32 func_800406E4(class_30CD0_t *This, s32 Unk) {
    return func_8001EDAC(&This->m_Unk21, 31, 1, Unk == 0) == 0;
}

void func_80040714(class_30CD0_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk21, 30, 1, Unk != 0);
}

void func_80040740(class_30CD0_t *This, s32 Unk) {
    func_8001EDAC(&This->m_Unk21, 28, 2, Unk);
}

void func_8004076C(class_30CD0_t *This, s32 Unk1, s32 Unk2) {
    func_80040790(This, &This->m_Unk24, Unk2, Unk1);
}

INCLUDE_ASM("asm/nonmatchings/30CD0", func_80040790);

void func_800407F8(class_30CD0_t *This, s32 *Unk) {
    if (This->m_Unk2) {
        __builtin_memcpy(&This->m_Unk19, Unk, 8);
    }
}

void func_80040824(class_30CD0_t *This, s16 *Data) {
    if (This->m_Unk2) {
        This->m_Unk23[0] = Data[0];
        This->m_Unk23[1] = Data[2];
    }
}

void func_80040854(class_30CD0_t *This, s32 Unk2, s32 Unk3, s32 Unk4) {
    This->vtable->Unk18(This, Unk2, Unk3);
  This->m_Unk17 = 0;
  This->m_Unk18 = Unk4;
}

void func_800408A0(class_30CD0_t *This, s32 Unk) {
    This->m_Unk16 = Unk;
}

void func_800408A8(class_30CD0_t *This, s8 Unk) {
    This->m_Unk25 = (1 << Unk) - 1;
}

class_30CD0_vtable_t *func_800408BC(void) {
    return &D_8006EAC0;
}
