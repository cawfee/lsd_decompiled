#include "39094.h"

extern class_39094_vtable_t D_80081940;

class_39094_t *func_80048894() {
    class_39094_t *allocated = (class_39094_t *) memory_allocate_mem(0x3C);

    if (allocated) {
        func_80048CE0()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/39094", func_800488E4);

void func_80048960(class_39094_t *This) {
    This->vtable->Unk32(This);
  (*(void ( **)(class_39094_t *))((s32) func_80026CAC() + 12))(This);
}

INCLUDE_ASM("asm/nonmatchings/39094", func_800489B4);

void func_80048A68(class_39094_t *This) {
    (*(void ( **)(class_39094_t *))((s32) func_80026CAC() + 116))(This);
    This->m_Unk10_1 = 0;
    This->m_Unk10_2 = 0;
    This->m_Unk9_2 = 0;
}

INCLUDE_ASM("asm/nonmatchings/39094", func_80048AAC);

void func_80048B78(class_39094_t *This) {
    This->vtable->Unk22(This);
  This->m_Unk10_1 = 0;
  This->m_Unk11_1 = -1;
}

INCLUDE_ASM("asm/nonmatchings/39094", func_80048BC0);

void func_80048C98(class_39094_t *This) {
    This->m_Unk10_2 = 0;

    if (This->m_Unk12) {
        This->m_Unk12 = memory_free_mem(This->m_Unk12);
    }
}

void func_80048CD8(class_39094_t *This, s32 Unk) {
    This->m_Unk13 = Unk;
}

class_39094_vtable_t *func_80048CE0(void) {
    return &D_80081940;
}
