#include "43370.h"
#include "3A930.h"

extern class_43370_vtable_t **D_80087034;

void func_80053EB4(class_43370_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4);
void func_8005C76C(void);
void func_80054D30(void);

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

void func_80053134(class_43370_t *This) {
    This->vtable->Unk32(This);
    func_8005C76C();
    func_80054D30();
    (*(void (**)(s32))(*(s32 *)This->m_Unk20 + 0x48))(This->m_Unk20);
}

void func_800531A0(class_43370_t *This, s32 Unk1, s32 Unk2) {
    if (Unk2 == 2) {
        func_800531CC(This, This->m_Unk21);
    }
}

INCLUDE_ASM("asm/nonmatchings/43370", func_800531CC);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053358);

void func_800533F0(class_43370_t *This) {
    if (This->m_Unk25) {
        This->m_Unk6++;
        if (This->m_Unk31) {
            This->vtable->Unk51(This);
        } else {
            This->vtable->Unk34(This);
        }
    }
}

void func_80053458(class_43370_t *This) {
    class_43370_vtable_t *vt;

    vt = This->vtable;
    if (This->m_Unk31) {
        vt->Unk48(This);
        vt->Unk52(This);
    } else {
        vt->Unk51(This);
    }
}

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

void func_80053984(class_43370_t *This, s32 Unk2, s32 Unk3) {
    if (This->m_Unk7 == 0) {
        switch (Unk3) {
            case 10:
                This->vtable->Unk36(This);
                break;
            case 12:
                This->vtable->Unk37(This);
                break;
            case 13:
                This->vtable->Unk38(This);
                break;
            case 14:
                This->vtable->Unk39(This);
                break;
            case 15:
                This->vtable->Unk40(This);
                break;
            case 16:
                This->vtable->Unk41(This);
                break;
            case 17:
                This->vtable->Unk42(This);
                break;
        }
    } else if (Unk3 >= 9) {
        *(s32 *)(This->m_Unk14 + 0x44) = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/43370", func_80053ACC);

INCLUDE_ASM("asm/nonmatchings/43370", func_80053BE8);

void func_80053C94(class_43370_t *This) {
    This->m_Unk7 = 6;
    func_80053EB4(This, (*(s32 (**)(s32))(*(s32 *)This->m_Unk14 + 0x200))(This->m_Unk14), 0, 0x1E, 1);
    (*(void (**)(s32))(*(s32 *)This->m_Unk14 + 0xFC))(This->m_Unk14);
}

void func_80053D18(class_43370_t *This) {
    s32 sp18;

    This->m_Unk7 = 7;
    (*(void (**)(s32, s32 *, s32))(*(s32 *)This->m_Unk14 + 0xF0))(This->m_Unk14, &sp18, -1);
    func_80053EB4(This, sp18, 0, 5, 1);
    (*(void (**)(s32))(*(s32 *)This->m_Unk14 + 0xFC))(This->m_Unk14);
}

void func_80053D9C(class_43370_t *This) {
    This->m_Unk7 = 8;
    func_80053EB4(This, 0, 0, 6, 1);
    (*(void (**)(s32, s32))(*(s32 *)This->m_Unk14 + 0xF4))(This->m_Unk14, 1);
}

void func_80053E00(class_43370_t *This) {
    This->m_Unk7 = 0xA;
    func_80053EB4(This, 0, 0, 6, 1);
    (*(void (**)(s32, s32))(*(s32 *)This->m_Unk14 + 0x13C))(This->m_Unk14, 2);
    (*(void (**)(s32, s32))(*(s32 *)This->m_Unk14 + 0xF4))(This->m_Unk14, 2);
}

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

void func_80054208(class_43370_t *This) {
    if (This->m_Unk32) {
        This->vtable->Unk52(This);
        This->vtable->Unk11(This, 0xD);
    }
}

void func_8005426C(class_43370_t *This) {
    if (This->m_Unk32) {
        This->vtable->Unk52(This);
        This->vtable->Unk11(This, 0xC);
    }
}

INCLUDE_ASM("asm/nonmatchings/43370", func_800542D0);

INCLUDE_ASM("asm/nonmatchings/43370", func_800543FC);

class_43370_vtable_t *func_800544D4(void) {
    return &D_80087034;
}
