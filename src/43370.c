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
    value = *(s32 *)*Unk2;
    
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

INCLUDE_ASM("asm/nonmatchings/43370", func_80052E7C);

INCLUDE_ASM("asm/nonmatchings/43370", func_80052EBC);

INCLUDE_ASM("asm/nonmatchings/43370", func_80052F10);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053134);

INCLUDE_ASM("asm/nonmatchings/43370", func_800531A0);

INCLUDE_ASM("asm/nonmatchings/43370", func_800531CC);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053358);

INCLUDE_ASM("asm/nonmatchings/43370", func_800533F0);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053458);

void func_800534C0(void) {
}

INCLUDE_ASM("asm/nonmatchings/43370", func_800534C8);

INCLUDE_ASM("asm/nonmatchings/43370", func_800536B0);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053764);

INCLUDE_ASM("asm/nonmatchings/43370", func_8005393C);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053984);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053ACC);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053BE8);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053C94);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053D18);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053D9C);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053E00);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053E84);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053EB4);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053F84);

INCLUDE_ASM("asm/nonmatchings/43370", func_800540E8);

INCLUDE_ASM("asm/nonmatchings/43370", func_80054120);

void func_800541CC(void) {
}

INCLUDE_ASM("asm/nonmatchings/43370", func_800541D4);

INCLUDE_ASM("asm/nonmatchings/43370", func_80054200);

INCLUDE_ASM("asm/nonmatchings/43370", func_80054208);

INCLUDE_ASM("asm/nonmatchings/43370", func_8005426C);

INCLUDE_ASM("asm/nonmatchings/43370", func_800542D0);

INCLUDE_ASM("asm/nonmatchings/43370", func_800543FC);

class_43370_vtable_t *func_800544D4(void) {
    return &D_80087034;
}
