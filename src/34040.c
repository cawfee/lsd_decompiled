#include "common.h"

void *func_80043840(s32 Unk1) {
    void *allocated = (void *) memory_allocate_mem(0x30);

    if (allocated) {
        void *vtable = func_80043B78();
        if ((*((s32 (**)(void *, s32)) vtable + 2))(allocated, Unk1)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/34040", func_800438B0);

INCLUDE_ASM("asm/nonmatchings/34040", func_80043954);

INCLUDE_ASM("asm/nonmatchings/34040", func_800439EC);

INCLUDE_ASM("asm/nonmatchings/34040", func_80043B18);

INCLUDE_ASM("asm/nonmatchings/34040", func_80043B3C);

INCLUDE_ASM("asm/nonmatchings/34040", func_80043B58);

void func_80043B70(void) {
}

INCLUDE_ASM("asm/nonmatchings/34040", func_80043B78);
