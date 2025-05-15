#include "common.h"

void *func_80056320(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    void *allocated = (void *) memory_allocate_mem(0x98);

    if (allocated) {
        void *vtable = func_80056F4C();
        if ((*((s32 (**)(void *, s32, s32, s32, s32)) vtable + 2))(allocated, Unk1, Unk2, Unk3, Unk4)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/46B20", func_800563C0);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056464);

INCLUDE_ASM("asm/nonmatchings/46B20", func_800564A4);

INCLUDE_ASM("asm/nonmatchings/46B20", func_800564F4);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056520);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056640);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056718);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056794);

INCLUDE_ASM("asm/nonmatchings/46B20", func_800567D4);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056858);

INCLUDE_ASM("asm/nonmatchings/46B20", func_800569A8);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056B8C);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056BBC);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056D18);

void func_80056DF0(void) {
}

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056DF8);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056E1C);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056E44);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056F28);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056F4C);
