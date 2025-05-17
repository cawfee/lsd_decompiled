#include <psx/libcd.h>
#include <psx/libspu.h>

#include "3770C.h"
#include "base_class.h"

// CD related class?

extern class_3770C_vtable_t **D_800817E0;

class_3770C_t *func_80046F0C(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_3770C_t *allocated = (class_3770C_t *) memory_allocate_mem(0x5C);

    if (allocated) {
        func_80047900()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_80046F88(class_3770C_t *This, u32 Unk2, s32 Unk3, s32 Unk4) {
    base_class_get_vtable()->Construct(This);
    This->vtable = func_80047900();
    This->m_Unk12 = Unk2;

    This->m_Unk11 = 0;

    if (Unk2 < 4) {
        This->m_Unk13 = 2054 * (300 / Unk3 / 2);
    } else {
        This->m_Unk13 = 2054 * (150 / Unk3 / 2);
    }

    This->m_Unk14 = Unk4;
    This->m_Unk19 = 0;
    This->m_Unk18 = 0;
    This->m_Unk17 = 0;
    This->m_Unk20 = 0;
    This->m_Unk10 = 0;
}

void func_80047074(class_3770C_t *This) {
    This->vtable->Unk17(This);
    base_class_get_vtable()->Cleanup(This);
}

void func_800470C8(class_3770C_t *This, s32 Unk2, u32 Unk3) {
    if (!This->m_Unk10) {
        StSetRing(Unk2, Unk3 >> 11);
        This->m_Unk19 = Unk2;
    }
}

INCLUDE_ASM("asm/nonmatchings/3770C", func_80047114);

s32 func_80047240(class_3770C_t *This) {
    spu_common_attr_t attributes;
    attributes.mask = (SPU_COMMON_MVOLL | SPU_COMMON_MVOLR | SPU_COMMON_CDVOLL | SPU_COMMON_CDVOLR | SPU_COMMON_CDMIX);

    attributes.m_vol.left = 0x3FFF;
    attributes.m_vol.right = 0x3FFF;

    attributes.cd.volume.left = 0x7FFF;
    attributes.cd.volume.right = 0x7FFF;

    attributes.cd.mix = SPU_ON;

    SpuSetCommonAttr(&attributes);
    return 1;
}

// gp
INCLUDE_ASM("asm/nonmatchings/3770C", func_8004728C);

// gp
INCLUDE_ASM("asm/nonmatchings/3770C", func_800472EC);

// gp
INCLUDE_ASM("asm/nonmatchings/3770C", func_80047388);

// gp
INCLUDE_ASM("asm/nonmatchings/3770C", func_800473E4);

// gp
INCLUDE_ASM("asm/nonmatchings/3770C", func_800474C8);

// gp
INCLUDE_ASM("asm/nonmatchings/3770C", func_80047574);

void func_800475C8(void) {
}

void func_800475D0(void) {
}

INCLUDE_ASM("asm/nonmatchings/3770C", func_800475D8);

INCLUDE_ASM("asm/nonmatchings/3770C", func_80047638);

INCLUDE_ASM("asm/nonmatchings/3770C", func_80047694);

INCLUDE_ASM("asm/nonmatchings/3770C", func_800477B0);

INCLUDE_ASM("asm/nonmatchings/3770C", func_80047810);

INCLUDE_ASM("asm/nonmatchings/3770C", func_80047870);
// unsigned long func_80047870(class_3770C_t *This) {
//     return StFreeRing();
// }

void func_80047890() {
    StUnSetRing();
}

INCLUDE_ASM("asm/nonmatchings/3770C", func_800478B0);

INCLUDE_ASM("asm/nonmatchings/3770C", func_800478D0);

void func_800478F8(void) {
}

class_3770C_vtable_t *func_80047900(void) {
    return &D_800817E0;
}
