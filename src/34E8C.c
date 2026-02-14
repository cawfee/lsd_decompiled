#include "34E8C.h"

extern class_34E8C_vtable_t D_8006F384;

class_34E8C_t *func_8004468C(s32 Unk1) {
    class_34E8C_t *allocated = (class_34E8C_t *) memory_allocate_mem(0x38);

    if (allocated) {
        if (func_800449FC()->Construct(allocated, Unk1, 1)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/34E8C", func_800446FC);

void func_800447B4(class_34E8C_t *This) {
    This->vtable->Unk30(This);
  (*(void ( **)(class_34E8C_t *))((s32) func_80026CAC() + 12))(This);
}

void func_80044808(class_34E8C_t *This) {
  (*(void ( **)(class_34E8C_t *))((s32) func_80026CAC() + 100))(This);
  This->vtable->Unk29(This);
}

INCLUDE_ASM("asm/nonmatchings/34E8C", func_80044858);

INCLUDE_ASM("asm/nonmatchings/34E8C", func_800448F8);

s32 func_8004497C(class_34E8C_t *This) {
    return (*(s32 ( **)(s32))(*(s32 *)This->m_Unk11 + 120))(This->m_Unk11) & 0xFF;
}

void func_800449B8(class_34E8C_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    (*(void ( **)(s32, s32, s32, s32, s32, s32))(*(s32 *)This->m_Unk11 + 128))(This->m_Unk11, Unk1, Unk2, Unk3, Unk4, Unk5);
}

class_34E8C_vtable_t *func_800449FC(void) {
    return &D_8006F384;
}
