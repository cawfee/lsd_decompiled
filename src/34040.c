#include "34040.h"

#include <psx/libgs.h>

extern class_34040_vtable_t D_8006F13C;

class_34040_t *func_80043840(s32 Unk1) {
    class_34040_t *allocated = (class_34040_t *) memory_allocate_mem(0x30);

    if (allocated) {
        if (func_80043B78()->Construct(allocated, Unk1)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/34040", func_800438B0);

INCLUDE_ASM("asm/nonmatchings/34040", func_80043954);

INCLUDE_ASM("asm/nonmatchings/34040", func_800439EC);

void func_80043B18(class_34040_t *This) {
    GsMapModelingData(This->m_Unk3 + 4);
}

s32 func_80043B3C(class_34040_t *This, s32 Offset) {
    return 12 + This->m_Unk3 + (28 * Offset);
}

s32 func_80043B58(class_34040_t *This, s32 Unk) {
    return *(s32 *) (4 * Unk + This->m_Unk10);
}

void func_80043B70(void) {
}

class_34040_vtable_t *func_80043B78(void) {
    return &D_8006F13C;
}
