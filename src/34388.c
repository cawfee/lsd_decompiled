#include "common.h"

void *func_80043B88(s32 Unk1) {
    void *allocated = (void *) memory_allocate_mem(0x3C);

    if (allocated) {
        void *vtable = func_80043E74();
        (*((void (**)(void *, s32)) vtable + 2))(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/34388", func_80043BE8);

INCLUDE_ASM("asm/nonmatchings/34388", func_80043C60);

INCLUDE_ASM("asm/nonmatchings/34388", func_80043CB8);

INCLUDE_ASM("asm/nonmatchings/34388", func_80043DFC);

INCLUDE_ASM("asm/nonmatchings/34388", func_80043E74);
