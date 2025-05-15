#include "common.h"

void *func_8004D254() {
    void *allocated = (void *) memory_allocate_mem(0xDC);

    if (allocated) {
        void *vtable = func_8004D37C();
        (*((void (**)(void *)) vtable + 2))(allocated);
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

INCLUDE_ASM("asm/nonmatchings/3DA54", func_8004D37C);
