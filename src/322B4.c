#include "322B4.h"

extern class_322B4_vtable_t **D_8006EC74;

class_322B4_t *func_80041AB4(s32 Unk1, u8 Unk2) {
    class_322B4_t *allocated = (class_322B4_t *) memory_allocate_mem(0xAC);

    if (allocated) {
        func_80041C3C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/322B4", func_80041B20);

INCLUDE_ASM("asm/nonmatchings/322B4", func_80041BAC);

INCLUDE_ASM("asm/nonmatchings/322B4", func_80041BDC);

INCLUDE_ASM("asm/nonmatchings/322B4", func_80041C28);

class_322B4_vtable_t *func_80041C3C(void) {
    return &D_8006EC74;
}
