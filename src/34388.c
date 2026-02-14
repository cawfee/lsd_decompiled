#include "34388.h"

extern class_34388_vtable_t D_8006F1C4;

class_34388_t *func_80043B88(s32 Unk1) {
    class_34388_t *allocated = (class_34388_t *) memory_allocate_mem(0x3C);

    if (allocated) {
        func_80043E74()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/34388", func_80043BE8);

void func_80043C60(class_34388_t *This) {
    func_800183DC(This->m_Unk11, This->m_Unk10);
  memory_free_mem(This->m_Unk11);
  (*(void ( **)(class_34388_t *))((s32) func_80026CAC() + 12))(This);
}

INCLUDE_ASM("asm/nonmatchings/34388", func_80043CB8);

INCLUDE_ASM("asm/nonmatchings/34388", func_80043DFC);

class_34388_vtable_t *func_80043E74(void) {
    return &D_8006F1C4;
}
