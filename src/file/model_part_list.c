#include "file/model_part_list.h"
#include "file/model_part.h"

model_part_list_t *func_80045228(model_part_list_t *, s32 *);
void func_800452AC(base_class_t *);
s32 func_800452FC(void *);
u8 func_800453DC(model_part_list_t *, s32, s32);
s32 file_buf_destroy(void *);
void file_buf_release(void *);
void nullsub13(void *);
void func_80043FE4(void *);
void func_8004416C(void *);

model_part_list_vtable_t D_8006F590 = {
    0x14F03,
    (base_class_t * (*) (base_class_t *) ) file_buf_destroy,
    (s32(*)(void *, s32 *)) func_80045228,
    func_800452AC,
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
    func_800452FC,
    NULL,
    NULL,
    NULL,
    NULL,
    (void (*)(void *)) func_800453DC,
    func_80043FE4,
    func_8004416C,
};

model_part_list_t *func_800451B8(s32 Unk1) {
    model_part_list_t *allocated = ALLOCATE_STRUCT(model_part_list_t);

    if (allocated) {
        if (func_80045428()->Construct(allocated, Unk1)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

model_part_list_t *func_80045228(model_part_list_t *This, s32 *pDword) {
    model_part_vtable_t *base_vtable;
    model_part_list_vtable_t *new_vtable;

    base_vtable = func_800441A4();
    base_vtable->Construct(This, pDword);

    new_vtable = func_80045428();
    This->vtable = new_vtable;

    if (*pDword != 0) {
        if (new_vtable->Unk24(This) != 0) {
            return NULL;
        }
    }

    return This;
}

void func_800452AC(model_part_list_t *This) {
    destroy_list((s32 *) (This->m_Unk3 + 8), *(s32 *) (This->m_Unk3 + 4));
    func_800441A4()->Cleanup(This);
}

s32 func_800452FC(model_part_list_t *This) {
    s32 data[3];
    s32 i;
    s32 *entries;
    s32 count;
    s32 result;
    model_part_t *obj;

    file_buf_set_triple(data, 0, 0, 1);
    i = 0;
    count = *(s32 *) (This->m_Unk3 + 4);
    entries = (s32 *) (This->m_Unk3 + 8);
    while (i < count) {
        data[0] = This->m_Unk3 + *(s32 *) (This->m_Unk3 + 8 + i * 4);
        result = (s32) func_80043E84((s32) data);
        *entries = result;
        if (result == 0) {
            if (i != 0) {
                do {
                    entries--;
                    obj = (model_part_t *) *entries;
                    obj->vtable->Destroy(obj);
                } while (--i != 0);
            }
            return 1;
        }
        i++;
        entries++;
    }
    return 0;
}

u8 func_800453DC(model_part_list_t *This, s32 Unk2, s32 Unk3) {
    return ((u8(*)(model_part_list_t *, s32, s32, s32)) This->vtable->Unk30)(
        This, Unk2, Unk3, 4 * *(s32 *) (This->m_Unk3 + 4) + This->m_Unk3 + 16);
}

model_part_list_vtable_t *func_80045428(void) {
    return &D_8006F590;
}
