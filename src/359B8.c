#include "common.h"

void *func_800451B8(s32 Unk1) {
    void *allocated = (void *) memory_allocate_mem(0x2C);

    if (allocated) {
        void *vtable = func_80045428();
        if ((*((s32 (**)(void *, s32)) vtable + 2))(allocated, Unk1)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/359B8", func_80045228);

INCLUDE_ASM("asm/nonmatchings/359B8", func_800452AC);

INCLUDE_ASM("asm/nonmatchings/359B8", func_800452FC);

INCLUDE_ASM("asm/nonmatchings/359B8", func_800453DC);

INCLUDE_ASM("asm/nonmatchings/359B8", func_80045428);
