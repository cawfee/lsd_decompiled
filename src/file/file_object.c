#include "common.h"

#include "file/file_object.h"

extern file_object_vtable_t g_CLASS_1C92C_VTABLE;

file_object_t *class_1C92C_create(u32 Unk1) {
    file_object_t *allocated = ALLOCATE_STRUCT(file_object_t);

    if (allocated) {
        class_1C92C_get_vtable()->class_1C92C_construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void class_1C92C_construct(file_object_t *This, s32 Unk) {
    void *base;

    base = get_file_driver();
    (*(void (**)(void *))((s32) base + 8))(This);

    This->vtable = class_1C92C_get_vtable();
    This->m_Unk10 = 0;
    This->m_Unk11 = 0;

    if (Unk) {
        This->vtable->Unk26(This, Unk);
    }
}

void class_1C92C_cleanup(void *This) {
    void *base;

    base = get_file_driver();
    (*(void (**)(void *))((s32) base + 0xC))(This);
}

void class_1C92C_unk24(file_object_t *This) {
    void (**base)(void *);

    This->m_Unk11 = 1;
    base = (void (**)(void *)) get_file_driver();
    base[25](This);
}

/*
 * Best attempt (not matching: 76/76 insns equal but register assignment
 * differs. Target copies the output-struct arg from $a1 to $a3 at entry
 * (`addu a3,a1,zero`) and reuses $a1 for the entry temp/var/u16; gcc 2.6.3
 * keeps the arg in $a1 and uses $v1/$a3 as scratch, so the two streams are a
 * register-number permutation. Tried: direct arg1, local alias `out = arg1`,
 * temp/var declaration orders, early-return vs body-first (body-first matches
 * the branch layout). Needs a source binding that makes $a1's live range
 * conflict with the parameter copy.)
 *
 * s32 class_1C92C_unk29(file_object_t *This, u8 *arg1, s32 arg2) {
 *     s32 temp;
 *     u8 *var;
 *     void *obj;
 *
 *     if (arg2 < 0x190) {
 *         temp = *(s32 *)(arg1 + 0x34);
 *         if (temp != 0) {
 *             *(s32 *)(arg1 + 0x30) = 1;
 *             var = (u8 *)This->m_Unk3 + temp;
 *         } else {
 *             *(s32 *)(arg1 + 0x30) = 0;
 *             var = (u8 *)This->m_Unk3 + arg2 * 0xC + 8;
 *         }
 *
 *         *(s32 *)(arg1 + 0x34) = *(s32 *)(var + 8);
 *         if (*(u8 *)var == 0) {
 *             return -1;
 *         }
 *
 *         *(s32 *)(arg1 + 0xC) = ((arg2 % 20) << 11) + 0x400;
 *         *(s32 *)(arg1 + 0x14) = ((arg2 / 20) << 11) + 0x400;
 *         *(s32 *)(arg1 + 0x10) = *(s16 *)(var + 6) << 11;
 *         *(s16 *)(arg1 + 0x1A) = *(u8 *)(var + 5) << 10;
 *         *(s16 *)(arg1 + 0x2C) = *(u8 *)(var + 1);
 *         *(s16 *)(arg1 + 0x2E) = *(u8 *)(var + 4);
 *         *(s32 *)(arg1 + 0x38) = *(u16 *)(var + 2);
 *
 *         obj = (void *)This->m_Unk10;
 *         return (*(s32 (**)(void *, s32, s32))((u8 *)*(void **)obj + 0x80))(
 *             obj, (s32)*(u16 *)(var + 2), arg2);
 *     }
 *
 *     return 0;
 * }
 */
INCLUDE_ASM("asm/nonmatchings/file/file_object", class_1C92C_unk29);

file_object_vtable_t *class_1C92C_get_vtable(void) {
    return &g_CLASS_1C92C_VTABLE;
}
