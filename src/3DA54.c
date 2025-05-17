#include "3DA54.h"

extern class_3DA54_vtable_t **D_800869D8;

class_3DA54_t *func_8004D254() {
    class_3DA54_t *allocated = (class_3DA54_t *) memory_allocate_mem(0xDC);

    if (allocated) {
        func_8004D37C()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/3DA54", func_8004D2A4);

void func_8004D2F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/3DA54", func_8004D300);

void func_8004D35C(void) {
}

void func_8004D364(void) {
}

void func_8004D36C(void) {
}

void func_8004D374(void) {
}

class_3DA54_vtable_t *func_8004D37C(void) {
    return &D_800869D8;
}
