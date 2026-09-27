#include "seq_file.h"

#include "base_class.h"
#include "file_buf.h"

s32 init_800269F0(void *);
void nullsub13(void);
void file_buf_release(void *);

void func_8004232C(seq_file_t *, unsigned char *);
void func_800423A8(seq_file_t *);
void func_800423E4(seq_file_t *);

seq_file_vtable_t D_8006EED8 = {
    0x00000B03,
    (base_class_t *(*)(base_class_t *))init_800269F0,
    (void (*)(void *, s32))func_8004232C,
    (void (*)(base_class_t *))func_800423A8,
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
    (void (*)(void *))nullsub13,
    (void (*)(void *))func_800423E4,
    NULL,
    NULL,
    NULL,
    NULL,
};

seq_file_t *func_800422CC(u32 Unk1) {
    seq_file_t *allocated = (seq_file_t *) memory_allocate_mem(0x30);

    if (allocated) {
        func_800423F0()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_8004232C(seq_file_t *This, unsigned char *Str) {
    void *v3;
    unsigned char str_buf[32];

    v3 = get_file_driver();

    ((void (*)(seq_file_t *))(*((void (**)(void))((char *) v3 + 8))))(This);

    This->vtable = (seq_file_vtable_t *) func_800423F0();
    This->m_Unk10 = 0;

    if (Str) {
        strcpy((char *) str_buf, (char *) Str);
        ((void (*)(seq_file_t *, unsigned char *)) This->vtable->pad10)(This, str_buf);
    }
}

void func_800423A8(seq_file_t *This) {
    void *v2;

    This->m_Unk10 = 0;
    v2 = get_file_driver();

    ((void (*)(seq_file_t *))(*((void (**)(void))((char *) v2 + 12))))(This);
}

void func_800423E4(seq_file_t *This) {
    This->m_Unk10 = 1;
}

seq_file_vtable_t *func_800423F0(void) {
    return &D_8006EED8;
}
