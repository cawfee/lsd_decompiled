#include "common.h"

void *func_80048894() {
    void *allocated = (void *) memory_allocate_mem(0x3C);

    if (allocated) {
        void *vtable = func_80048CE0();
        (*((void (**)(void *)) vtable + 2))(allocated);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/39094", func_800488E4);

INCLUDE_ASM("asm/nonmatchings/39094", func_80048960);

INCLUDE_ASM("asm/nonmatchings/39094", func_800489B4);

INCLUDE_ASM("asm/nonmatchings/39094", func_80048A68);

INCLUDE_ASM("asm/nonmatchings/39094", func_80048AAC);

INCLUDE_ASM("asm/nonmatchings/39094", func_80048B78);

INCLUDE_ASM("asm/nonmatchings/39094", func_80048BC0);

INCLUDE_ASM("asm/nonmatchings/39094", func_80048C98);

INCLUDE_ASM("asm/nonmatchings/39094", func_80048CD8);

INCLUDE_ASM("asm/nonmatchings/39094", func_80048CE0);
