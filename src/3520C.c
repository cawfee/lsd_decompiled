#include "common.h"

void *func_80044A0C(s32 Unk1) {
    void *allocated = (void *) memory_allocate_mem(0x3C);

    if (allocated) {
        void *vtable = func_80044CC4();
        if ((*((s32(**)(void *, s32)) vtable + 2))(allocated, Unk1)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/3520C", func_80044A7C);

INCLUDE_ASM("asm/nonmatchings/3520C", func_80044B04);

INCLUDE_ASM("asm/nonmatchings/3520C", func_80044B58);

INCLUDE_ASM("asm/nonmatchings/3520C", func_80044B88);

INCLUDE_ASM("asm/nonmatchings/3520C", func_80044C58);

INCLUDE_ASM("asm/nonmatchings/3520C", func_80044C90);

INCLUDE_ASM("asm/nonmatchings/3520C", func_80044CC4);
