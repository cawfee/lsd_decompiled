#include <psx/libgs.h>

#include "texture_helper.h"

#include "171F0.h"
#include "memory.h"

extern texture_helper_t *g_TEXTURE_HELPER_VTABLE;

texture_helper_t *texture_helper_create(const char *Unk1) {
    texture_helper_t *allocated = (texture_helper_t *) memory_allocate_mem(0x50);

    if (allocated) {
        texture_helper_get_vtable()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_8003B3FC(texture_helper_t *This, s32 Unk) {
    void *unk_class = func_80026CAC();
    (*(void (**)(texture_helper_t *))(unk_class + 8))(This);

    This->vtable = texture_helper_get_vtable();
    This->m_MaybeLoaded = 0;
    This->unk19 = 0;

    if (Unk) {
        This->vtable->Unk11(This, Unk);
    }
}

void func_8003B470(texture_helper_t *This) {
    void *unk = func_80026CAC();
    (*(void (**)(texture_helper_t *))(unk + 12))(This);
}

INCLUDE_ASM("asm/nonmatchings/texture_helper", func_8003B4A8);

void func_8003B5AC(void) {
}

void func_8003B5B4(void) {
}

void func_8003B5BC(void) {
}

void func_8003B5C4(void) {
}

void func_8003B5CC(void) {
}

void func_8003B5D4(void) {
}

void func_8003B5DC(void) {
}

void texture_helper_set_loaded(texture_helper_t *This) {
    This->m_MaybeLoaded = 1;
}

// Helper for GsGetTimInfo?
void texture_helper_get_tim_info(texture_helper_t *This, void *TIMData) {
    GsGetTimInfo((unsigned long *) (This->m_Image + 4), TIMData);
}

texture_helper_vtable_t *texture_helper_get_vtable(void) {
    return &g_TEXTURE_HELPER_VTABLE;
}
