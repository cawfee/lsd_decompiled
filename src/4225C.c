#include "4225C.h"
#include "base_class.h"

extern class_4225C_vtable_t D_80086F88;

class_4225C_t *func_80051A5C(s32 Unk1, s32 Unk2) {
    class_4225C_t *allocated = (class_4225C_t *) memory_allocate_mem(0x54);

    if (allocated) {
        func_80052B60()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051AC8);

void func_80051C74(class_4225C_t *This) {
    This->m_Unk12 = 0;
    This->m_Unk13 = 0;
    This->m_Unk19 = 0;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051C84);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051D1C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051DA0);

void func_80051E20(class_4225C_t *This) {
    This->m_Unk12 = 0;
  This->m_Unk13 = 0;
  This->m_Unk19 = 0;
  base_class_get_vtable()->Unk5(This);
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051E64);

void func_80051F14(class_4225C_t *This) {
    This->m_Unk7 = 0;
    This->m_Unk8 = 0;
    This->m_Unk9 = 0;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051F24);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800520A0);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052110);

void func_8005217C(class_4225C_t *This) {
    This->vtable->Unk4(This, This->m_Unk12);
  This->vtable->Unk4(This, This->m_Unk13);
  This->m_Unk14 = 0;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_800521D4);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005227C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800522DC);

void func_800523F0(class_4225C_t *This, s32 Unk) {
    s32 m_Unk14; // $a0

  m_Unk14 = This->m_Unk14;
  if ( m_Unk14 ) {
    (*(void ( **)(s32, int, int, int))(*(s32 *)m_Unk14 + 128))(m_Unk14, Unk, 96, 96);
  }
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052430);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052498);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800524F8);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052598);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052644);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005278C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005281C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005292C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_800529FC);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052A58);

s32 func_80052B54(class_4225C_t *This) {
    return This->m_Unk9;
}

class_4225C_vtable_t *func_80052B60(void) {
    return &D_80086F88;
}
