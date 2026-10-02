#include "file/tmd_prim.h"
#include "base/base.h"

#include <psx/libgs.h>

void class_FA50_construct(void *, s32);
void func_8001F314(void *);
void func_8001F33C(void *);
s32 func_8001F360(tmd_prim_t *, s32);
void func_8001F37C(void *);
void class_FA50_reset_flag(tmd_prim_t *);

tmd_prim_vtable_t g_CLASS_FA50_VTABLE = {
    0x9,
    base_class_destructor,
    class_FA50_construct,
    base_class_cleanup,
    base_class_attach,
    base_class_detach,
    base_class_detach_all,
    base_class_iter_children,
    base_class_add_parent,
    base_class_remove_parent,
    base_class_clear_parents,
    base_class_iter_parents,
    base_class_notify,
    base_class_nop,
    base_class_on_notify,
    0,
    func_8001F314,
    func_8001F33C,
    (void (*)(void *)) func_8001F360,
    func_8001F37C,
};

tmd_prim_t *class_FA50_create(s32 Unk1) {
    tmd_prim_t *allocated = (tmd_prim_t *) memory_allocate_mem(0x24);

    if (allocated) {
        class_FA50_get_vtable()->class_FA50_construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void class_FA50_construct(tmd_prim_t *This, void *Unk2) {
    base_class_get_vtable()->Construct(This);
    This->vtable = class_FA50_get_vtable();

    This->m_Unk3 = Unk2;
    This->m_Unk2 = (s32) Unk2 - 12;

    class_FA50_reset_flag(This);
}

void func_8001F314(tmd_prim_t *This, tmd_prim_t *Unk2) {
    __builtin_memcpy(&This->m_Unk4, Unk2, 16);
}

void func_8001F33C(tmd_prim_t *This) {
    GsMapModelingData(This->m_Unk2 + 4);
}

s32 func_8001F360(tmd_prim_t *This, s32 Unk2) {
    s32 temp = Unk2 * 28 + 12;
    return temp + This->m_Unk2;
}

void func_8001F37C(void *) {
}

tmd_prim_vtable_t *class_FA50_get_vtable() {
    return &g_CLASS_FA50_VTABLE;
}
