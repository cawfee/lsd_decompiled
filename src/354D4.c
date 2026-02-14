#include "354D4.h"

extern class_354D4_vtable_t **D_8006F498;

class_354D4_t *func_80044CD4(s32 Unk1, void *Unk2) {
    class_354D4_t *allocated = (class_354D4_t *) memory_allocate_mem(0x44);

    if (allocated) {
        func_80044F20()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/354D4", func_80044D40);

void func_80044DC8(class_354D4_t *This) {
    memory_free_mem(This->m_Unk13);
  (*(void ( **)(class_354D4_t *))((s32) func_80026CAC() + 12))(This);
}

void func_80044E10(class_354D4_t *This) {
    if ( !This->m_Unk9_2 )
  {
    This->vtable->Unk29(This);
    This->m_Unk15_2 = 1;
  }
}

INCLUDE_ASM("asm/nonmatchings/354D4", func_80044E64);

class_354D4_vtable_t *func_80044F20(void) {
    return &D_8006F498;
}
