#include "43370.h"
#include "3A930.h"

extern class_43370_vtable_t **D_80087034;

class_43370_t *func_80052B70(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    class_43370_t *allocated = (class_43370_t *) memory_allocate_mem(0x88);

    if (allocated) {
        func_800544D4()->Construct(allocated, Unk1, Unk2, Unk3, Unk4, Unk5);
        return allocated;
    }

    return NULL;
}

void func_80052C10(class_43370_t *This, int Unk2, int Unk3, int Unk4, int Unk5, int Unk6) {
    func_8004A4B8()->Construct(This, 0, Unk2);
    This->vtable = func_800544D4();
    This->m_Unk24 = 0;
    This->m_Unk25 = 0;
    This->m_Unk23 = 1;
    This->m_Unk20 = Unk3;
    This->m_Unk13 = Unk6;
    This->m_Unk26 = Unk2;
    This->m_Unk28 = Unk4;
    This->m_Unk27 = Unk5;
    This->m_Unk31 = 0;
    This->m_Unk32 = 0;
    This->vtable->Unk15(This);
}

void func_80052CD8(class_43370_t *This) {
    func_8004A4B8()->Cleanup(This);
}

void func_80052D10(class_43370_t *This, void **Unk2, s32 Unk3) {
    s32 value;

    func_8004A4B8()->Unk13(This, Unk2, Unk3);
    value = *(s32 *) *Unk2;

    if ((value & 0xFFF) == 0x114) {
        This->vtable->Unk44(This, Unk2, Unk3);
    } else if ((value & 0xFFF) == 0x164) {
        This->vtable->Unk43(This, Unk2, Unk3);
    } else if ((value & 0xFFFF) == 0x1F34) {
        This->vtable->Unk35(This, Unk2, Unk3);
    }
}

void func_80052DE0(void) {
}

INCLUDE_ASM("asm/nonmatchings/43370", func_80052DE8);

s32 func_80052E7C(class_43370_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
if ( Unk1 < 0 )
    return func_80049098(This->m_Unk13, Unk2, Unk3);
  else
    return func_80049060(This->m_Unk13, Unk1);
}

void func_80052EBC(class_43370_t *This) {
    This->vtable->Unk4(This, This->m_Unk14);
  func_8004A4B8()->Unk17(This);
}

INCLUDE_ASM("asm/nonmatchings/43370", func_80052F10);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053134);

void func_800531A0(class_43370_t *This, s32 Unk1, s32 Unk2) {
    if (Unk2 == 2) {
        func_800531CC(This, This->m_Unk21);
    }
}

INCLUDE_ASM("asm/nonmatchings/43370", func_800531CC);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053358);

INCLUDE_ASM("asm/nonmatchings/43370", func_800533F0);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053458);

void func_800534C0(void) {
}

INCLUDE_ASM("asm/nonmatchings/43370", func_800534C8);

INCLUDE_ASM("asm/nonmatchings/43370", func_800536B0);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053764);

s32 func_8005393C(class_43370_t *This) {
    s32 v1; // $v0

  v1 = (*(s32 ( **)(s32, s32, s32))(*(s32 *)This->m_Unk4 + 268))(This->m_Unk4, 0, 0);
  return func_800558F0(v1, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/43370", func_80053984);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053ACC);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053BE8);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053C94);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053D18);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053D9C);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053E00);

void func_80053E84(class_43370_t *This) {
    This->vtable->Unk11(This, 11);
}

INCLUDE_ASM("asm/nonmatchings/43370", func_80053EB4);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053F84);

void func_800540E8(class_43370_t *This, s32 Unk1, s32 Unk2) {
    if (Unk2 == 7) {
        This->vtable->Unk45(This, Unk1);
    }
}

INCLUDE_ASM("asm/nonmatchings/43370", func_80054120);

void func_800541CC(void) {
}

void func_800541D4(class_43370_t *This) {
    if (This->m_Unk31) {
        if (!This->m_Unk7) {
            This->m_Unk32 = 1;
        }
    }
}

void func_80054200(class_43370_t *This) {
    This->m_Unk32 = 0;
}

INCLUDE_ASM("asm/nonmatchings/43370", func_80054208);

INCLUDE_ASM("asm/nonmatchings/43370", func_8005426C);

INCLUDE_ASM("asm/nonmatchings/43370", func_800542D0);

INCLUDE_ASM("asm/nonmatchings/43370", func_800543FC);

class_43370_vtable_t *func_800544D4(void) {
    return &D_80087034;
}
