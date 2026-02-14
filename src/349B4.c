#include "349B4.h"

extern class_349B4_vtable_t **D_8006F2C4;

class_349B4_t *func_800441B4(s32 Unk1, s32 Unk2) {
    class_349B4_t *allocated = (class_349B4_t *) memory_allocate_mem(0x68);

    if (allocated) {
        func_8004467C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/349B4", func_80044220);

INCLUDE_ASM("asm/nonmatchings/349B4", func_80044294);

INCLUDE_ASM("asm/nonmatchings/349B4", func_80044380);

INCLUDE_ASM("asm/nonmatchings/349B4", func_8004441C);

void func_8004464C(class_349B4_t *This, s32 Unk1, s8 *Data) {
    if (Unk1) {
        __builtin_memcpy(This->m_Unk20, Data, 3);
    }
}

void func_80044674(void) {
}

class_349B4_vtable_t *func_8004467C(void) {
    return &D_8006F2C4;
}
