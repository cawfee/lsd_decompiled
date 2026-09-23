#include "tmd_model.h"

#include <psx/libgs.h>

extern void *get_file_driver(void);

extern tmd_model_vtable_t D_8006F13C;

tmd_model_t *tmd_create(s32 Unk1) {
    tmd_model_t *allocated = (tmd_model_t *) memory_allocate_mem(0x30);

    if (allocated) {
        if (func_80043B78()->Construct(allocated, Unk1)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/tmd_model", func_800438B0);

void func_80043954(tmd_model_t *This) {
    void ***var_s0;
    void **temp_a0;

    var_s0 = (void ***)This->m_Unk10;
    if (*var_s0 != NULL) {
        do {
            temp_a0 = *var_s0;
            var_s0 = (void ***)((u8 *)var_s0 + 4);
            (*(void (**)(void *))(*(s32 *)temp_a0 + 4))(temp_a0);
        } while (*var_s0 != NULL);
    }
    memory_free_mem((void *)This->m_Unk10);
    (*(void (**)(void *))((s32)get_file_driver() + 0xC))(This);
}

INCLUDE_ASM("asm/nonmatchings/tmd_model", func_800439EC);

void tmd_map(tmd_model_t *This) {
    GsMapModelingData(This->m_Unk3 + 4);
}

s32 func_80043B3C(tmd_model_t *This, s32 Offset) {
    return 12 + This->m_Unk3 + (28 * Offset);
}

s32 func_80043B58(tmd_model_t *This, s32 Unk) {
    return *(s32 *) (4 * Unk + This->m_Unk10);
}

void func_80043B70(void) {
}

tmd_model_vtable_t *func_80043B78(void) {
    return &D_8006F13C;
}
