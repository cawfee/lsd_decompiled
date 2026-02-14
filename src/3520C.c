#include "3520C.h"

extern class_3520C_vtable_t D_8006F40C;

class_3520C_t *func_80044A0C(s32 Unk1) {
    class_3520C_t *allocated = (class_3520C_t *) memory_allocate_mem(0x3C);

    if (allocated) {
        if (func_80044CC4()->Construct(allocated, Unk1)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/3520C", func_80044A7C);

void func_80044B04(class_3520C_t *This) {
    This->vtable->Unk30(This);
  (*(void ( **)(class_3520C_t *))((s32) func_800449FC() + 12))(This);
}

void func_80044B58(class_3520C_t *This) {
    This->vtable->Unk29(This);
}

INCLUDE_ASM("asm/nonmatchings/3520C", func_80044B88);

s32 func_80044C58(class_3520C_t *This) {
    s32 result = func_800183DC((s32 *)(This->m_Unk3 + 8), This->m_Unk13);
    This->m_Unk13 = 0;
    return result;
}

s32 func_80044C90(class_3520C_t *This, u32 Unk) {
    s32 m_Unk3;

  m_Unk3 = This->m_Unk3;
  if ( Unk < *(s32 *)(m_Unk3 + 4) )
    return *(s32 *)(4 * Unk + m_Unk3 + 8);
  else
    return 0;
}

class_3520C_vtable_t *func_80044CC4() {
    return &D_8006F40C;
}
