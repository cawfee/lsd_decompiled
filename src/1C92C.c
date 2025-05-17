#include "common.h"

#include "1C92C.h"

// TODO vtable struct
// TODO unknown class

// vtable
extern class_1C92C_vtable_t **D_8006D940;

class_1C92C_t *func_8002C12C(u32 Unk1, u32 Unk2) {
    class_1C92C_t *allocated = (class_1C92C_t *) memory_allocate_mem(0x34);

    if (allocated) {
        func_8002C3A8()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_8002C18C(class_1C92C_t *This, s32 Unk) {
    void *unk_class = func_80026CAC();
    (*(void (**)(void *))(unk_class + 8))(This);

    This->vtable = func_8002C3A8();
    This->m_Unk10 = 0;
    This->m_Unk11 = 0;

    if (Unk) {
        This->vtable->Unk26(This, Unk);
    }
}

void func_8002C200(void *This) {
    void *table = func_80026CAC();
    (*((void (**)(void *)) table + 3))(This);
}

void func_8002C238(class_1C92C_t *This) {
    void (**unk)(void *);
    This->m_Unk11 = 1;

    unk = (void (**)(void *)) func_80026CAC();
    unk[25](This);
}

INCLUDE_ASM("asm/nonmatchings/1C92C", func_8002C278);

// Get vtable
class_1C92C_vtable_t *func_8002C3A8(void) {
    return &D_8006D940;
}
