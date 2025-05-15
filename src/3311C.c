#include "common.h"

void *func_8004291C(s32 Unk1) {
    void *allocated = (void *) memory_allocate_mem(0x20);

    if (allocated) {
        void *vtable = func_80042A7C();
        (*((void (**)(void *, s32)) vtable + 2))(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/3311C", func_8004297C);

INCLUDE_ASM("asm/nonmatchings/3311C", func_800429E0);

INCLUDE_ASM("asm/nonmatchings/3311C", func_800429E8);

INCLUDE_ASM("asm/nonmatchings/3311C", func_80042A2C);

INCLUDE_ASM("asm/nonmatchings/3311C", func_80042A7C);
