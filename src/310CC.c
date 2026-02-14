#include "310CC.h"
#include "322B4.h"

extern class_310CC_vtable_t D_8006EB90;

class_310CC_t *func_800408CC(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_310CC_t *allocated = (class_310CC_t *) memory_allocate_mem(0xB8);

    if (allocated) {
        func_80040FB0()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040948);

void func_80040A30(class_310CC_t *This) {
    func_800183DC(This->m_Unk44, This->m_Unk41_2);
    This->m_Unk44 = memory_free_mem(This->m_Unk44);
    func_80041C3C()->Cleanup(This);
}

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040A88);

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040AE8);

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040C00);

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040CD0);

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040D74);

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040E14);

s32 func_80040EDC(class_310CC_t *This, u8 Unk2, s32 Unk3) {
    return (*(int ( **)(s32, s32))(**((s32 **)This->m_Unk44 + Unk3) + 196))(
           *((s32 *)This->m_Unk44 + Unk3),
           Unk2);
}

void func_80040F20(void) {
}

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040F28);

void func_80040FA0(void) {
}

void func_80040FA8(class_310CC_t *This, s32 Unk) {
    This->m_Unk43 = Unk;
}

class_310CC_vtable_t *func_80040FB0(void) {
    return &D_8006EB90;
}
