#include "16634.h"

extern class_16634_vtable_t **D_8006D370;

class_16634_t *func_80025B34(s32 Unk1, s32 Unk2) {
    class_16634_t *allocated = (class_16634_t *) memory_allocate_mem(0x20);

    if (allocated) {
        func_80025E9C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/16334", func_80025BA0);

INCLUDE_ASM("asm/nonmatchings/16334", func_80025C30);

INCLUDE_ASM("asm/nonmatchings/16334", func_80025C84);

INCLUDE_ASM("asm/nonmatchings/16334", func_80025CC4);

INCLUDE_ASM("asm/nonmatchings/16334", func_80025D10);

void func_80025E14(void) {
}

INCLUDE_ASM("asm/nonmatchings/16334", func_80025E1C);

void func_80025E94(void) {
}

class_16634_vtable_t *func_80025E9C(void) {
    return &D_8006D370;
}
