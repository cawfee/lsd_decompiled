#include "305B0.h"

extern class_305B0_vtable_t g_CLASS_305B0_VTABLE;

class_305B0_t *class_305B0_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_305B0_t *allocated = (class_305B0_t *) memory_allocate_mem(0xA0);

    if (allocated) {
        class_305B0_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/305B0", class_305B0_construct);

void func_8003FED8(class_305B0_t *This, s32 Unk2) {
    This->m_Unk27 = Unk2;
    This->m_Unk26 = 0;
    This->m_Unk28 = 10;
    This->m_Unk29 = 0;
    This->m_Unk30 = 0;
    This->vtable->Unk23(This, 0);
    This->vtable->Unk24(This, 0);
    This->m_Unk37 = 0;
}

void func_8003FF44(class_305B0_t *This, int Unk2, int Unk3) {
    if (Unk3 == 2) {
        s32 value = This->m_Unk31;

        This->m_Unk31 = value - 1;

        if (value > 0) {
            if (This->m_Unk30 != 9) {
                if ((This->m_Unk29 & 4) != 0) {
                    ((u8 *)&This->m_Unk24)[0] += (u8)This->m_Unk28;
                }

                if ((This->m_Unk29 & 2) != 0) {
                    ((u8 *)&This->m_Unk24)[1] += (u8)This->m_Unk28;
                }

                if ((This->m_Unk29 & 1) != 0) {
                    ((u8 *)&This->m_Unk24)[2] += (u8)This->m_Unk28;
                }
            }
        } else {
            This->vtable->Unk55(This, Unk2);
        }
    }
}

void func_8004001C(class_305B0_t *This, s32 Value) {
    This->m_Unk28 = Value;
}

INCLUDE_ASM("asm/nonmatchings/305B0", func_80040024);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800400B0);

INCLUDE_ASM("asm/nonmatchings/305B0", func_80040154);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800402F0);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800403F8);

INCLUDE_ASM("asm/nonmatchings/305B0", func_8004042C);

INCLUDE_ASM("asm/nonmatchings/305B0", func_80040490);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800404B4);

class_305B0_vtable_t *class_305B0_get_vtable() {
    return &g_CLASS_305B0_VTABLE;
}
