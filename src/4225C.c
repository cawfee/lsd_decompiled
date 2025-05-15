#include "common.h"

void *func_80051A5C(s32 Unk1, s32 Unk2) {
    void *allocated = (void *) memory_allocate_mem(0x54);

    if (allocated) {
        void *vtable = func_80052B60();
        (*((void (**)(void *, s32, s32)) vtable + 2))(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051AC8);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051C74);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051C84);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051D1C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051DA0);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051E20);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051E64);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051F14);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051F24);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800520A0);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052110);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005217C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800521D4);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005227C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800522DC);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800523F0);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052430);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052498);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800524F8);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052598);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052644);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005278C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005281C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005292C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800529FC);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052A58);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052B54);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052B60);
