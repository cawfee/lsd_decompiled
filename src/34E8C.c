#include "common.h"

void *func_8004468C(s32 Unk1) {
    void *allocated = (void *) memory_allocate_mem(0x38);

    if (allocated) {
        void *vtable = func_800449FC();
        if ((*((s32 (**)(void *, s32, s32)) vtable + 2))(allocated, Unk1, 1)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/34E8C", func_800446FC);

INCLUDE_ASM("asm/nonmatchings/34E8C", func_800447B4);

INCLUDE_ASM("asm/nonmatchings/34E8C", func_80044808);

INCLUDE_ASM("asm/nonmatchings/34E8C", func_80044858);

INCLUDE_ASM("asm/nonmatchings/34E8C", func_800448F8);

INCLUDE_ASM("asm/nonmatchings/34E8C", func_8004497C);

INCLUDE_ASM("asm/nonmatchings/34E8C", func_800449B8);

INCLUDE_ASM("asm/nonmatchings/34E8C", func_800449FC);
