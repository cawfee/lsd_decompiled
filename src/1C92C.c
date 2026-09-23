#include "common.h"

#include "1C92C.h"

extern class_1C92C_vtable_t g_CLASS_1C92C_VTABLE;

class_1C92C_t *class_1C92C_create(u32 Unk1) {
    class_1C92C_t *allocated = (class_1C92C_t *) memory_allocate_mem(0x34);

    if (allocated) {
        class_1C92C_get_vtable()->class_1C92C_construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void class_1C92C_construct(class_1C92C_t *This, s32 Unk) {
    void *base;

    base = get_file_driver();
    (*(void (**)(void *))((s32)base + 8))(This);

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
    (*(void (**)(void *))((s32)base + 0xC))(This);
}

void class_1C92C_unk24(class_1C92C_t *This) {
    void (**base)(void *);

    This->m_Unk11 = 1;
    base = (void (**)(void *)) get_file_driver();
    base[25](This);
}

INCLUDE_ASM("asm/nonmatchings/1C92C", class_1C92C_unk29);

class_1C92C_vtable_t *class_1C92C_get_vtable(void) {
    return &g_CLASS_1C92C_VTABLE;
}
