#include "35730.h"

extern class_35730_vtable_t **D_8006F514;

class_35730_t *func_80044F30(u32 Unk1) {
    class_35730_t *allocated = (class_35730_t *) memory_allocate_mem(0x38);

    if (allocated) {
        func_800451A8()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/35730", func_80044F90);

void func_8004500C(class_35730_t *This) {
    memory_free_mem(This->m_Unk12);
  memory_free_mem(This->m_Unk10);
  (*(void ( **)(class_35730_t *))((s32) func_80026CAC() + 12))(This);
}

void func_80045060(class_35730_t *This) {
    s8 pad[0x20];
    
    if ( !This->m_Unk9_2 )
  {
    This->vtable->Unk29(This);
    This->m_Unk11_2 = 1;
  }
}

INCLUDE_ASM("asm/nonmatchings/35730", func_800450B4);

class_35730_vtable_t *func_800451A8(void) {
    return &D_8006F514;
}
