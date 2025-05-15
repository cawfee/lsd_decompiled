#include "common.h"

void *func_80042694() {
    void *allocated = (void *) memory_allocate_mem(0x54);

    if (allocated) {
        void *vtable = func_800428E4();
        (*((void (**)(void *)) vtable + 2))(allocated);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/32E94", func_800426E4);

INCLUDE_ASM("asm/nonmatchings/32E94", func_80042790);

INCLUDE_ASM("asm/nonmatchings/32E94", func_80042814);

void func_80042820(void) {
}

INCLUDE_ASM("asm/nonmatchings/32E94", func_80042828);

INCLUDE_ASM("asm/nonmatchings/32E94", func_8004283C);

INCLUDE_ASM("asm/nonmatchings/32E94", func_800428E4);
