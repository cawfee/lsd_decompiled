#include "32ACC.h"

extern class_32ACC_vtable_t D_8006EED8;

class_32ACC_t *func_800422CC(u32 Unk1) {
    class_32ACC_t *allocated = (class_32ACC_t *) memory_allocate_mem(0x30);

    if (allocated) {
        func_800423F0()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_8004232C(class_32ACC_t *This, unsigned char *Str) {
    void *v3;
    unsigned char str_buf[32];

    v3 = func_80026CAC();

    ((void (*)(class_32ACC_t *))(*((void (**)(void))((char *) v3 + 8))))(This);

    This->vtable = (class_32ACC_vtable_t *) func_800423F0();
    This->m_Unk10 = 0;

    if (Str) {
        strcpy((char *) str_buf, (char *) Str);
        ((void (*)(class_32ACC_t *, unsigned char *)) This->vtable->pad10)(This, str_buf);
    }
}

void func_800423A8(class_32ACC_t *This) {
    void *v2;

    This->m_Unk10 = 0;
    v2 = func_80026CAC();

    ((void (*)(class_32ACC_t *))(*((void (**)(void))((char *) v2 + 12))))(This);
}

void func_800423E4(class_32ACC_t *This) {
    This->m_Unk10 = 1;
}

class_32ACC_vtable_t *func_800423F0(void) {
    return &D_8006EED8;
}
