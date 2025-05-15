#include "48768.h"

extern class_48768_vtable_t **D_80087AAC;

class_48768_t *func_80057F68(s32 Unk1) {
    class_48768_t *allocated = (class_48768_t *) memory_allocate_mem(0x244);

    if (allocated) {
        func_80058764()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/48768", func_80057FC8);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058078);

INCLUDE_ASM("asm/nonmatchings/48768", func_800580E0);

INCLUDE_ASM("asm/nonmatchings/48768", func_800581C4);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058228);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058308);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058390);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058404);

INCLUDE_ASM("asm/nonmatchings/48768", func_800585B4);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058694);

class_48768_vtable_t *func_80058764(void) {
    return &D_80087AAC;
}
