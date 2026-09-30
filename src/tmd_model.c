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

tmd_model_t *func_800438B0(tmd_model_t *This, s32 *Unk) {
    (*(void (**)(void *))((s32)get_file_driver() + 8))(This);
    This->vtable = func_80043B78();
    if (Unk == NULL) {
        return This;
    }
    if (*Unk != 0) {
        This->m_Unk3 = *Unk;
        This->m_Unk4 = 0;
        if (This->vtable->Unk24(This) != 0) {
            goto fail;
        }
        return This;
    }
    This->vtable->Unk26(This, Unk[1]);
    return This;
fail:
    return NULL;
}

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
    memory_free_mem(This->m_Unk10);
    (*(void (**)(void *))((s32)get_file_driver() + 0xC))(This);
}

/*
 * Best attempt (not matching: compiled 76-77 insns / frame 0x28 vs target 75 /
 * frame 0x30. gcc keeps the object array in $s0 and the loop index in $s1;
 * target has array=$s1, index=$s0 and reserves 8 extra frame bytes. Body,
 * allocation size, tmd_map call, build loop, failure cleanup loop, and
 * epilogue otherwise match. Tried declaration reorder and pre-initialising
 * the index.)
 *
 * s32 func_800439EC(tmd_model_t *This) {
 *     tmd_prim_t **array;
 *     tmd_prim_t **p;
 *     u32 i;
 *     s32 off;
 *
 *     array = (tmd_prim_t **)memory_allocate_mem((*(u32 *)(This->m_Unk3 + 8) + 1) * 4);
 *     if (array == NULL) {
 *         return 1;
 *     }
 *     This->m_Unk10 = (s32)array;
 *     This->vtable->tmd_map(This);
 *     if (*(u32 *)(This->m_Unk3 + 8) != 0) {
 *         i = 0;
 *         off = 0xC;
 *         do {
 *             *array = class_FA50_create(This->m_Unk3 + off);
 *             if (*array == NULL) {
 *                 if (i != 0) {
 *                     p = array - 1;
 *                     do {
 *                         i--;
 *                         (*p)->vtable->Destroy((base_class_t *)*p);
 *                         p--;
 *                     } while (i != 0);
 *                     array = p + 1;
 *                 }
 *                 memory_free_mem(array);
 *                 return 1;
 *             }
 *             array++;
 *             i++;
 *             off += 0x1C;
 *         } while (i < *(u32 *)(This->m_Unk3 + 8));
 *     }
 *     *array = NULL;
 *     (*(void (**)(void *))((s32)get_file_driver() + 0x64))(This);
 *     return 0;
 * }
 */
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
