#include "3ACC8.h"

extern class_3ACC8_vtable_t **D_800866E8;

class_3ACC8_t *func_8004A4C8(u32 Unk1, u32 Unk2) {
    class_3ACC8_t *allocated = (class_3ACC8_t *) memory_allocate_mem(0x1E8);

    if (allocated) {
        func_8004D244()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004A534);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004A7C0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004A984);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004AA10);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004AA6C);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004AB24);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004AB88);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004ABD0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004ACF8);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004ADC4);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004ADD0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004ADD8);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004AEA4);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004AFE0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B030);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B100);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B2D4);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B31C);

void func_8004B324(void) {
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B32C);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B344);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B38C);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B418);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B44C);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B570);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B57C);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B5BC);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B700);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B930);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BA40);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BB3C);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BCE0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BD14);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BE54);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C0AC);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C158);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C1C0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C368);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C3F0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C434);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C470);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C588);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C5D0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C620);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C6A8);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C93C);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CAF0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CC74);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CD38);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CDA4);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CE24);

void *func_8004CFA8(class_3ACC8_t *This) {
    return &This->m_Unk114;
}

void func_8004CFB0(class_3ACC8_t *This, s32 Unk) {
    This->m_Unk118 = Unk;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CFB8);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D028);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D088);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D0D0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D108);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D140);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D1D0);

class_3ACC8_vtable_t *func_8004D244(void) {
    return &D_800866E8;
}
