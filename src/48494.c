#include "48494.h"

extern class_48494_vtable_t D_800879C4;

extern s16 D_80087AA4[];
extern s32 D_80087AA6[];

class_48494_t *func_80057C94(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_48494_t *allocated = (class_48494_t *) memory_allocate_mem(0xA8);

    if (allocated) {
        func_80057F58()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/48494", func_80057D10);

void func_80057DBC(class_48494_t *This, s32 Unk) {
    This->m_Unk39 = Unk;
    This->m_Unk28_1 = D_80087AA4[Unk * 2];
    This->m_Unk28_2 = D_80087AA6[Unk];
}

INCLUDE_ASM("asm/nonmatchings/48494", func_80057DF4);

void func_80057F38(void) {
}

void func_80057F40(void) {
}

void func_80057F48(void) {
}

void func_80057F50(void) {
}

class_48494_vtable_t *func_80057F58(void) {
    return &D_800879C4;
}
