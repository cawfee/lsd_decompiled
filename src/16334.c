#include "16634.h"
#include "base_class.h"

extern s32 D_8008A848;

extern class_16634_vtable_t D_8006D370;

class_16634_t *func_80025B34(s32 Unk1, s32 Unk2) {
    class_16634_t *allocated = (class_16634_t *) memory_allocate_mem(0x20);

    if (allocated) {
        func_80025E9C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/16334", func_80025BA0);

void func_80025C30(class_16634_t *This) {
    D_8008A848--;

    if (!D_8008A848) {
        PadStop();
    }

    base_class_get_vtable()->Cleanup(This);
}

void func_80025C84(class_16634_t *This, s32 Unk) {
    This->m_Unk2_1 = Unk != 0;
    This->m_Unk3 = 0;
  This->m_Unk4 = 0;
  This->m_Unk5 = 0;
  This->vtable->Unk19();
}

void func_80025CC4(class_16634_t *This) {
    s32 v2; // $v0
  s32 m_Unk3; // $a0

  v2 = PadRead(This->m_Unk2_1);
  m_Unk3 = This->m_Unk3;
  This->m_Unk3 = v2;
  This->m_Unk4 = (v2 ^ m_Unk3) & m_Unk3;
  This->m_Unk5 = (v2 ^ m_Unk3) & v2;
}

INCLUDE_ASM("asm/nonmatchings/16334", func_80025D10);

void func_80025E14(void) {
}

INCLUDE_ASM("asm/nonmatchings/16334", func_80025E1C);

void func_80025E94(void) {
}

class_16634_vtable_t *func_80025E9C(void) {
    return &D_8006D370;
}
