#include "common.h"

void *func_80045438(s32 Unk1, s32 Unk2, s32 Unk3) {
    void *allocated = (void *) memory_allocate_mem(0x6C);

    if (allocated) {
        void *vtable = func_80045E44();
        if (!(*((s32(**)(void *, s32, s32, s32)) vtable + 2))(allocated, Unk1, Unk2, Unk3)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/35C38", func_800454C4);

INCLUDE_ASM("asm/nonmatchings/35C38", func_800455D4);

INCLUDE_ASM("asm/nonmatchings/35C38", func_8004564C);

INCLUDE_ASM("asm/nonmatchings/35C38", func_8004575C);

INCLUDE_ASM("asm/nonmatchings/35C38", func_800457C0);

INCLUDE_ASM("asm/nonmatchings/35C38", func_800458AC);

INCLUDE_ASM("asm/nonmatchings/35C38", func_800458B8);

INCLUDE_ASM("asm/nonmatchings/35C38", func_8004593C);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045948);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045A38);

void func_80045AC8(void) {
}

void func_80045AD0(void) {
}

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045AD8);

void func_80045BC0(void) {
}

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045BC8);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045C94);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045CFC);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045DE0);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045E18);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045E3C);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045E44);
