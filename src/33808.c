#include "common.h"

void *func_80043008(s32 Unk1, s32 Unk2) {
    void *allocated = (void *) memory_allocate_mem(0x84);

    if (allocated) {
        void *vtable = func_80043830();
        (*((void (**)(void *, s32)) vtable + 2))(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/33808", func_80043068);

INCLUDE_ASM("asm/nonmatchings/33808", func_800431A8);

INCLUDE_ASM("asm/nonmatchings/33808", func_80043200);

INCLUDE_ASM("asm/nonmatchings/33808", func_800434DC);

INCLUDE_ASM("asm/nonmatchings/33808", func_80043538);

INCLUDE_ASM("asm/nonmatchings/33808", func_8004355C);

INCLUDE_ASM("asm/nonmatchings/33808", func_800435D0);

INCLUDE_ASM("asm/nonmatchings/33808", func_80043648);

INCLUDE_ASM("asm/nonmatchings/33808", func_80043830);
