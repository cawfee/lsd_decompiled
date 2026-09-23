#include "seq_file.h"

extern seq_file_vtable_t D_8006EED8;

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
