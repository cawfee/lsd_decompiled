#include "file/tim_list.h"

#include <psx/libgs.h>

#include "file/file_buf.h"
#include "file/tim_image.h"

void func_80043BE8(void *, s32);
void func_80043C60(void *);
void func_80043CB8(void *);
void func_80043DFC(void *);
s32 file_buf_destroy(void *);
void file_buf_release(void *);
void nullsub13(void *);

tim_list_vtable_t D_8006F1C4 = {
    0xC03,
    (void (*)(void *)) file_buf_destroy,
    func_80043BE8,
    func_80043C60,
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
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    file_buf_release,
    nullsub13,
    func_80043CB8,
    NULL,
    NULL,
    NULL,
    NULL,
    func_80043DFC,
};

s16 D_8008A934[2] = { 3, 0 };

tim_list_t *func_80043B88(s32 Unk1) {
    tim_list_t *allocated = (tim_list_t *) memory_allocate_mem(0x3C);

    if (allocated) {
        func_80043E74()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_80043BE8(tim_list_t *This, s32 Unk1) {
    (*(void (**)(void *))((s32) get_file_driver() + 8))(This);
    This->vtable = func_80043E74();
    This->m_Unk10 = 0;
    This->m_Unk11 = 0;
    This->m_Unk13 = 0;
    if (Unk1 != 0) {
        This->vtable->Unk26(This, Unk1);
    }
}

void func_80043C60(tim_list_t *This) {
    destroy_list(This->m_Unk11, This->m_Unk10);
    memory_free_mem(This->m_Unk11);
    (*(void (**)(tim_list_t *))((s32) get_file_driver() + 12))(This);
}

void func_80043CB8(tim_list_t *This) {
    gs_image_t image;
    tim_image_t **slots;
    s32 *offsets;
    s32 i;
    tim_image_t *tex;

    if ((This->m_Unk8 & 0x200) || (This->m_Unk3 != 0)) {
        This->m_Unk10 = *(s32 *) This->m_Unk3;
        This->m_Unk11 = (s32) memory_allocate_mem(*(s32 *) This->m_Unk3 * 4);
        if (This->m_Unk11 != 0) {
            slots = (tim_image_t **) This->m_Unk11;
            offsets = (s32 *) This->m_Unk3 + 1;
            for (i = 0; i < This->m_Unk10; i++, slots++) {
                tex = tim_image_create(NULL);
                *slots = tex;
                tex->m_Image = This->m_Unk3 + *offsets;
                (*slots)->unk5 = 0;
                offsets += 1;
                (*slots)->vtable->Unk23(*slots, &image);
                (*slots)->unk19 = (((image.cy - 0x1E0) >> D_8008A934[0]) * 0x10) + This->m_Unk12;
            }
            This->m_Unk13 = 1;
            (*(void (**)(void *))((s32) get_file_driver() + 0x64))(This);
        }
    }
}

void func_80043DFC(tim_list_t *This) {
    s32 i;
    tim_image_t **slots;
    tim_image_t *tex;

    slots = (tim_image_t **) This->m_Unk11;
    for (i = 0; i < This->m_Unk10; i++) {
        tex = *slots;
        slots++;
        tex->vtable->Unk14(tex);
    }
}

tim_list_vtable_t *func_80043E74(void) {
    return &D_8006F1C4;
}
