#include "common.h"

void *func_800404D0(u32 Unk1, u32 Unk2, u32 Unk3) {
    void *allocated = (void *) memory_allocate_mem(0x6C);

    if (allocated) {
        void *vtable = func_800408BC();
        (*((void (**)(u32 *, s32, s32, s32)) vtable + 2))(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/30CD0", func_8004054C);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_800405D0);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_80040664);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_800406E4);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_80040714);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_80040740);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_8004076C);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_80040790);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_800407F8);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_80040824);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_80040854);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_800408A0);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_800408A8);

INCLUDE_ASM("asm/nonmatchings/30CD0", func_800408BC);
