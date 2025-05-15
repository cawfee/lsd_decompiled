#include "common.h"

void *func_80050BA8(s32 Unk1, s32 Unk2) {
    void *allocated = (void *) memory_allocate_mem(0x4C);

    if (allocated) {
        void *vtable = func_80051A4C();
        (*((void (**)(void *, s32, s32)) vtable + 2))(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050C14);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050CD8);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050CE8);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050D30);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050DB4);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050E34);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050E78);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050F28);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050F98);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051174);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051200);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051270);

INCLUDE_ASM("asm/nonmatchings/413A8", func_800512C8);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051370);

INCLUDE_ASM("asm/nonmatchings/413A8", func_800513D0);

INCLUDE_ASM("asm/nonmatchings/413A8", func_8005161C);

INCLUDE_ASM("asm/nonmatchings/413A8", func_8005165C);

INCLUDE_ASM("asm/nonmatchings/413A8", func_800516C0);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051720);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051784);

INCLUDE_ASM("asm/nonmatchings/413A8", func_800517EC);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051814);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051858);

INCLUDE_ASM("asm/nonmatchings/413A8", func_800518F4);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051998);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051A4C);
