#include "33808.h"

extern class_33808_vtable_t D_8006F0B8;

class_33808_t *func_80043008(s32 Unk1, s32 Unk2) {
    class_33808_t *allocated = (class_33808_t *) memory_allocate_mem(0x84);

    if (allocated) {
        func_80043830()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/33808", func_80043068);

void func_800431A8(class_33808_t *This) {
    func_800183DC(This->m_Unk11, This->m_Unk10);
  memory_free_mem(This->m_Unk11);
  (*(void ( **)(class_33808_t *))((s32) func_80026CAC() + 12))(This);
}

INCLUDE_ASM("asm/nonmatchings/33808", func_80043200);

INCLUDE_ASM("asm/nonmatchings/33808", func_800434DC);

void func_80043538(class_33808_t *This, s32 a2, s16 a3) {
    u16 *ptr;

    ptr = (u16 *) ((u8 *) This + ((a2 * 0x10) + 0x40));
    *ptr = a3;
    ptr[1] = 1 << *ptr;
}

INCLUDE_ASM("asm/nonmatchings/33808", func_8004355C);

INCLUDE_ASM("asm/nonmatchings/33808", func_800435D0);

INCLUDE_ASM("asm/nonmatchings/33808", func_80043648);

class_33808_vtable_t *func_80043830(void) {
    return &D_8006F0B8;
}
