#include "dream_context.h"

extern dream_context_vtable_t **g_DREAM_CONTEXT_VTABLE;

dream_context_t *dream_context_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    dream_context_t *allocated = (dream_context_t *) memory_allocate_mem(0x50);

    if (allocated) {
        dream_context_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049684);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049830);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049958);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049A14);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049A1C);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049AC0);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049B54);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049C50);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049CA8);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049E20);

void func_80049EA4(void) {
}

void func_80049EAC(void) {
}

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049EB4);

dream_context_vtable_t *dream_context_get_vtable(void) {
    return &g_DREAM_CONTEXT_VTABLE;
}

INCLUDE_ASM("asm/nonmatchings/dream_context", func_8004A070);
