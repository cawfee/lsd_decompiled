#include "FA50.h"
#include "base_class.h"

#include <psx/libgs.h>

extern class_FA50_vtable_t g_CLASS_FA50_VTABLE;

class_FA50_t *class_FA50_create(s32 Unk1) {
    class_FA50_t *allocated = (class_FA50_t *) memory_allocate_mem(0x24);

    if (allocated) {
        class_FA50_get_vtable()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void class_FA50_construct(class_FA50_t *This, void *Unk2) {
    base_class_get_vtable()->Construct(This);
    This->vtable = class_FA50_get_vtable();

    This->m_Unk3 = Unk2;
    This->m_Unk2 = (s32) Unk2 - 12;

    func_8001F394(This);
}

void func_8001F314(class_FA50_t *This, class_FA50_t *Unk2) {
    __builtin_memcpy(&This->m_Unk4, Unk2, 16);
}

void func_8001F33C(class_FA50_t *This) {
    GsMapModelingData(This->m_Unk2 + 4);
}

s32 func_8001F360(class_FA50_t *This, s32 Unk2) {
    s32 temp = Unk2 * 28 + 12;
    return temp + This->m_Unk2;
}

void func_8001F37C(void) {
}

class_FA50_vtable_t *class_FA50_get_vtable() {
    return &g_CLASS_FA50_VTABLE;
}
