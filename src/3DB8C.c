#include "3DB8C.h"

#include "D294.h"

extern class_3DB8C_vtable_t **D_80086AA0;

class_3DB8C_t *func_8004D38C() {
    class_3DB8C_t *allocated = (class_3DB8C_t *) memory_allocate_mem(0x3C);

    if (allocated) {
        func_8004D508()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_8004D3DC(class_3DB8C_t *This) {
    func_8001E57C()->Construct(This);
    This->vtable = func_8004D508();
    This->m_Unk12_1 = 0;
    This->m_Unk12_2 = 0;
    This->m_Unk13 = 0;
}

void func_8004D42C(void) {
}

void func_8004D434(class_3DB8C_t *This, void **Unk) {
    if (*(u8 *)*Unk == 52) {
        This->vtable->Unk45(This);
    }
}

void func_8004D47C(class_3DB8C_t *This, void **Unk2, s32 Unk3) {
    func_8001E57C()->Unk38(This, Unk2, Unk3);

    if (Unk3 < 9) {
        if (Unk3 >= 5) {
            This->vtable->Unk39(This, Unk2, Unk3);
        }
    }
}

class_3DB8C_t *func_8004D500(class_3DB8C_t *This) {
    return This;
}

class_3DB8C_vtable_t *func_8004D508(void) {
    return &D_80086AA0;
}
