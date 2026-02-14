#include "359B8.h"
#include "34684.h"

extern class_359B8_vtable_t D_8006F590;

class_359B8_t *func_800451B8(s32 Unk1) {
    class_359B8_t *allocated = (class_359B8_t *) memory_allocate_mem(0x2C);

    if (allocated) {
        if (func_80045428()->Construct(allocated, Unk1)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/359B8", func_80045228);

void func_800452AC(class_359B8_t *This) {
    func_800183DC((s32 *)(This->m_Unk3 + 8), *(s32 *)(This->m_Unk3 + 4));
  func_800441A4()->Cleanup(This);
}

INCLUDE_ASM("asm/nonmatchings/359B8", func_800452FC);

u8 func_800453DC(class_359B8_t *This, s32 Unk2, s32 Unk3) {
    return ((u8 ( *)(class_359B8_t *, s32, s32, s32))This->vtable->Unk30)(
           This,
           Unk2,
           Unk3,
           4 * *(s32 *)(This->m_Unk3 + 4) + This->m_Unk3 + 16);
}

class_359B8_vtable_t *func_80045428(void) {
    return &D_8006F590;
}
