#include "common.h"

void *func_8003FDB0(s32 Unk1, s32 Unk2, s32 Unk3) {
    void *allocated = (void *) memory_allocate_mem(0xA0);

    if (allocated) {
        void *vtable = func_800404C0();
        (*((s32(**)(void *, s32, s32, s32)) vtable + 2))(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/305B0", func_8003FE2C);

INCLUDE_ASM("asm/nonmatchings/305B0", func_8003FED8);

INCLUDE_ASM("asm/nonmatchings/305B0", func_8003FF44);

INCLUDE_ASM("asm/nonmatchings/305B0", func_8004001C);

INCLUDE_ASM("asm/nonmatchings/305B0", func_80040024);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800400B0);

INCLUDE_ASM("asm/nonmatchings/305B0", func_80040154);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800402F0);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800403F8);

INCLUDE_ASM("asm/nonmatchings/305B0", func_8004042C);

INCLUDE_ASM("asm/nonmatchings/305B0", func_80040490);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800404B4);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800404C0);
