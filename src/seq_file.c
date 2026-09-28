#include "seq_file.h"

#include "base_class.h"
#include "file_buf.h"

s32 file_buf_destroy(void *);
void nullsub13(void *);
void file_buf_release(void *);

void seq_file_construct(void *, s32);
void seq_file_cleanup(base_class_t *);
void seq_file_set_flag(void *);

seq_file_vtable_t g_SEQ_FILE_VTABLE = {
    0xB03,
    (base_class_t *(*)(base_class_t *))file_buf_destroy,
    seq_file_construct,
    seq_file_cleanup,
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
    seq_file_set_flag,
    NULL,
    NULL,
    NULL,
    NULL,
};

seq_file_t *seq_file_create(u32 Unk1) {
    seq_file_t *allocated = (seq_file_t *) memory_allocate_mem(0x30);

    if (allocated) {
        seq_file_get_vtable()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void seq_file_construct(seq_file_t *This, unsigned char *Str) {
    void *v3;
    unsigned char str_buf[32];

    v3 = get_file_driver();

    ((void (*)(seq_file_t *))(*((void (**)(void))((char *) v3 + 8))))(This);

    This->vtable = (seq_file_vtable_t *) seq_file_get_vtable();
    This->m_Flag = 0;

    if (Str) {
        strcpy((char *) str_buf, (char *) Str);
        ((void (*)(seq_file_t *, unsigned char *)) This->vtable->pad10)(This, str_buf);
    }
}

void seq_file_cleanup(seq_file_t *This) {
    void *v2;

    This->m_Flag = 0;
    v2 = get_file_driver();

    ((void (*)(seq_file_t *))(*((void (**)(void))((char *) v2 + 12))))(This);
}

void seq_file_set_flag(seq_file_t *This) {
    This->m_Flag = 1;
}

seq_file_vtable_t *seq_file_get_vtable(void) {
    return &g_SEQ_FILE_VTABLE;
}
