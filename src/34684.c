#include "common.h"

void *func_80043E84(s32 Unk1) {
    void *allocated = (void *) memory_allocate_mem(0x2C);

    if (allocated) {
        void *vtable = func_800441A4();
        (*((void (**)(void *, s32)) vtable + 2))(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/34684", func_80043EE4);

INCLUDE_ASM("asm/nonmatchings/34684", func_80043F78);

INCLUDE_ASM("asm/nonmatchings/34684", func_80043FB0);

INCLUDE_ASM("asm/nonmatchings/34684", func_80043FE4);

INCLUDE_ASM("asm/nonmatchings/34684", func_8004416C);

INCLUDE_ASM("asm/nonmatchings/34684", func_800441A4);
