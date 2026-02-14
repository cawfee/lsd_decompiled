#include "32E94.h"
#include <psx/libgs.h>

extern class_32E94_vtable_t **D_8006EFAC;

class_32E94_t *func_80042694() {
    class_32E94_t *allocated = (class_32E94_t *) memory_allocate_mem(0x54);

    if (allocated) {
        func_800428E4()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/32E94", func_800426E4);

INCLUDE_ASM("asm/nonmatchings/32E94", func_80042790);

void func_80042814(class_32E94_t *This) {
    *This->m_Unk4 = 0;
}

void func_80042820(void) {
}

s32 func_80042828(class_32E94_t *This, int Unk) {
    return *(&This->m_Unk16 + Unk);
}

INCLUDE_ASM("asm/nonmatchings/32E94", func_8004283C);

class_32E94_vtable_t *func_800428E4() {
    return &D_8006EFAC;
}
