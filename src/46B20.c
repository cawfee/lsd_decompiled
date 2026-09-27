#include "46B20.h"
#include "477E4.h"

extern class_46B20_vtable_t D_800876FC;

class_46B20_t *func_80056320(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    class_46B20_t *allocated = (class_46B20_t *) memory_allocate_mem(0x98);

    if (allocated) {
        class_46B20_vtable_t *vtable = func_80056F4C();

        if (vtable->Construct(allocated, Unk1, Unk2, Unk3, Unk4)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

void *func_800563C0(class_46B20_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    class_46B20_vtable_t *vtable;

    if (func_80057C84()->Construct(This)) {
        This->vtable = func_80056F4C();

        This->m_Unk16 = 0;
        This->m_Unk20 = Unk1;
        This->vtable->Unk15(This, Unk2);

        func_80056520(This, Unk3, Unk4);
        return This;
    }

    return NULL;
}

void func_80056464(class_46B20_t *This) {
    func_80056718();
    func_80057C84()->Cleanup(This);
}

void func_800564A4(class_46B20_t *This, s32 *Unk) {
    __builtin_memcpy(&This->m_Unk21, Unk, 36);
    This->m_Unk8 = 0;
}

void func_800564F4(class_46B20_t *This, s32 Unk1) {
    ++This->m_Unk8;
    func_80056640(This, Unk1);
}
