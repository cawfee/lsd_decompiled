#include "common.h"

void *func_800655D4(s32 Unk1, s32 Unk2) {
    void *allocated = (void *) memory_allocate_mem(0x98);

    if (allocated) {
        void *vtable = func_80066818();
        if ((*((s32(**)(void *, s32, s32, s32, s32)) vtable + 2))(allocated, Unk1, Unk2)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065650);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_8006573C);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065790);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065830);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065918);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_800659D0);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065A5C);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065AE0);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065B80);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065BF4);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065BFC);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065C2C);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065C5C);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065CEC);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065D64);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065DBC);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065DEC);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065E1C);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065F2C);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80065FD8);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_800660BC);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_8006613C);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80066148);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80066150);

void func_800661C4(void) {
}

void func_800661CC(void) {
}

INCLUDE_ASM("asm/nonmatchings/55DD4", func_800661D4);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80066214);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_800662A8);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_800662B4);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_800662BC);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80066340);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80066748);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_800667B0);

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80066818);
