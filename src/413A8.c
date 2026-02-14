#include "413A8.h"
#include "base_class.h"
#include "memory.h"

extern class_413A8_vtable_t D_80086ED0;

class_413A8_t *func_80050BA8(char *Unk1, s32 Unk2) {
    class_413A8_t *allocated = (class_413A8_t *) memory_allocate_mem(0x4C);

    if (allocated) {
        func_80051A4C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050C14);

void func_80050CD8(class_413A8_t *This) {
    This->m_Unk12 = 0;
    This->m_Unk13 = 0;
    This->m_Unk17 = 0;
}

void func_80050CE8(class_413A8_t *This) {
    memory_free_mem(This->m_Unk9);
    base_class_get_vtable()->Cleanup(This);
}

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050D30);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050DB4);

void func_80050E34(class_413A8_t *This) {
    This->m_Unk12 = 0;
    This->m_Unk13 = 0;
    This->m_Unk17 = 0;
    base_class_get_vtable()->Unk5(This);
}

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050E78);

void func_80050F28(class_413A8_t *This, char *Unk1, s32 Unk2) {
    This->m_Unk2 = Unk2;
    This->m_Unk8 = (s32) Unk1;
    This->m_Unk5 = 0;
    This->m_Unk6 = 0;
    if (Unk2 == 1) {
        func_80040FC0(This->m_Unk9, Unk1);
        This->m_Unk3 /= 2;
    } else {
        strcpy((char *) This->m_Unk9, Unk1);
    }
}

INCLUDE_ASM("asm/nonmatchings/413A8", func_80050F98);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051174);

void func_80051200(class_413A8_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    This->vtable->Unk3(This, Unk1);
    This->vtable->Unk3(This, Unk2);
    This->m_Unk14 = Unk3;
    This->m_Unk10 = 0;
    This->m_Unk7 = 0;
}

void func_80051270(class_413A8_t *This) {
    This->vtable->Unk4(This, This->m_Unk12);
    This->vtable->Unk4(This, This->m_Unk13);
    This->m_Unk14 = 0;
}

INCLUDE_ASM("asm/nonmatchings/413A8", func_800512C8);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051370);

INCLUDE_ASM("asm/nonmatchings/413A8", func_800513D0);

void func_8005161C(class_413A8_t *This, s32 Unk) {
    s32 m_Unk14; // $a0

  m_Unk14 = This->m_Unk14;
  if ( m_Unk14 ) {
    (*(void ( **)(s32, int, int, int))(*(s32 *)m_Unk14 + 128))(m_Unk14, Unk, 96, 96);
  }
}

INCLUDE_ASM("asm/nonmatchings/413A8", func_8005165C);

void func_800516C0(class_413A8_t *This) {
    s32 m_Unk5; // $v0

  if ( This->m_Unk17 )
  {
    m_Unk5 = This->m_Unk5;
    This->m_Unk5 = m_Unk5 - 1;
    if ( m_Unk5 - 1 >= 0 )
        This->vtable->Unk40(This, m_Unk5 - 1, 1);
      
    else
      This->m_Unk5 = m_Unk5;
}
}

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051720);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051784);

void func_800517EC(class_413A8_t *This) {
    if (This->m_Unk17) {
        This->m_Unk7 ^= 1u;
    }
}

void func_80051814(class_413A8_t *This) {
    if ( This->m_Unk17 )
  {
    This->m_Unk6 = 0;
    ((void ( *)(class_413A8_t *, s32, s32, s32))This->vtable->Unk41)(This, This->m_Unk5, 0, 1);
  }
}

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051858);

INCLUDE_ASM("asm/nonmatchings/413A8", func_800518F4);

INCLUDE_ASM("asm/nonmatchings/413A8", func_80051998);

class_413A8_vtable_t *func_80051A4C(void) {
    return &D_80086ED0;
}
