#include "32ACC.h"

extern class_32ACC_vtable_t **D_8006EED8;

class_32ACC_t *func_800422CC(u32 Unk1) {
    class_32ACC_t *allocated = (class_32ACC_t *) memory_allocate_mem(0x30);

    if (allocated) {
        func_800423F0()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/32ACC", func_8004232C);

INCLUDE_ASM("asm/nonmatchings/32ACC", func_800423A8);

void func_800423E4(class_32ACC_t *This) {
    This->m_Unk10 = 1;
}

class_32ACC_vtable_t *func_800423F0(void) {
    return &D_8006EED8;
}
