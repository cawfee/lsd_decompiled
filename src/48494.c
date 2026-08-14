#include "48494.h"

void *func_800422BC(void);

extern class_48494_vtable_t D_800879C4;

extern u8 D_80087A8C[];
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

void func_80057D10(class_48494_t *This, s32 arg1, s32 arg2, s32 arg3) {
    (*(void (**)(void *, s32, s32, void *, s32, s32))((s32)func_800422BC() + 8))(
        This, arg3, 0, &D_80087A8C[arg1 * 0xC], arg2, 0);
    This->vtable = func_80057F58();
    This->m_Unk40 = 0;
    ((void (*)(void *, s32))This->vtable->Unk15)(This, arg1);
}

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
