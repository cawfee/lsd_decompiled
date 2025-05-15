#include "common.h"

void *func_80057C94(s32 Unk1, s32 Unk2, s32 Unk3) {
    void *allocated = (void *) memory_allocate_mem(0xA8);

    if (allocated) {
        void *vtable = func_80057F58();
        (*((void (**)(void *, s32, s32, s32)) vtable + 2))(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/48494", func_80057D10);

INCLUDE_ASM("asm/nonmatchings/48494", func_80057DBC);

INCLUDE_ASM("asm/nonmatchings/48494", func_80057DF4);

void func_80057F38(void) {
}

void func_80057F40(void) {
}

void func_80057F48(void) {
}

void func_80057F50(void) {
}

INCLUDE_ASM("asm/nonmatchings/48494", func_80057F58);
