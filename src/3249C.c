#include "3249C.h"

extern class_3249C_vtable_t **D_8006ED4C;

class_3249C_t *func_80041C9C(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_3249C_t *allocated = (class_3249C_t *) memory_allocate_mem(0xA8);

    if (allocated) {
        func_80041ED8()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/3249C", func_80041D18);

void func_80041DA4(void) {
}

INCLUDE_ASM("asm/nonmatchings/3249C", func_80041DAC);

void func_80041E2C(class_3249C_t *This, s32 *Unk) {
    if (This->m_Unk2) {
        __builtin_memcpy(&This->m_Unk39, Unk, 8);
    }
}

INCLUDE_ASM("asm/nonmatchings/3249C", func_80041E58);

class_3249C_vtable_t *func_80041ED8(void) {
    return &D_8006ED4C;
}
