#include "graphics/flat_light.h"
#include "base/base_class.h"

#include <psx/libgs.h>

void func_8004297C(void *, s32);
void func_800429E0(void *, s32);
void func_800429E8(void *);
void func_80042A2C(void *);

class_flat_light_vtable_t D_8006F06C = {
    0x6,
    (void (*)(void *)) base_class_destructor,
    func_8004297C,
    (void (*)(void *)) base_class_cleanup,
    (void (*)(void *)) base_class_attach,
    (void (*)(void *)) base_class_detach,
    (void (*)(void *)) base_class_detach_all,
    (void (*)(void *)) base_class_iter_children,
    (void (*)(void *)) base_class_add_parent,
    (void (*)(void *)) base_class_remove_parent,
    (void (*)(void *)) base_class_clear_parents,
    (void (*)(void *)) base_class_iter_parents,
    (void (*)(void *)) base_class_notify,
    (void (*)(void *)) base_class_nop,
    (void (*)(void *)) base_class_on_notify,
    NULL,
    func_800429E0,
    func_800429E8,
    func_80042A2C,
};

class_flat_light_t *func_8004291C(s32 Unk1) {
    class_flat_light_t *allocated = (class_flat_light_t *) memory_allocate_mem(0x20);

    if (allocated) {
        func_80042A7C()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_8004297C(class_flat_light_t *This, s32 Unk) {
    base_class_get_vtable()->Construct((base_class_t *) This);
    This->vtable = func_80042A7C();
    This->vtable->Unk15(This, Unk);
}

void func_800429E0(class_flat_light_t *This, s32 Unk) {
    This->m_Unk2 = Unk;
}

void func_800429E8(class_flat_light_t *This, s32 Unk1, s8 *Unk2) {
    if (Unk1) {
        __builtin_memcpy(&This->m_Unk6, Unk2, 3);
    }
    GsSetFlatLight(This->m_Unk2, &This->m_Unk3);
}

void func_80042A2C(class_flat_light_t *This, s32 Unk2, s16 *Unk3) {
    if (Unk2) {
        This->m_Unk3 = *Unk3;
        This->m_Unk4 = Unk3[1];
        This->m_Unk5 = Unk3[2];
    }
    GsSetFlatLight(This->m_Unk2, &This->m_Unk3);
}

class_flat_light_vtable_t *func_80042A7C() {
    return &D_8006F06C;
}
