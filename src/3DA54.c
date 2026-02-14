#include "3DA54.h"
#include "renderer.h"

extern class_3DA54_vtable_t D_800869D8;

class_3DA54_t *func_8004D254() {
    class_3DA54_t *allocated = (class_3DA54_t *) memory_allocate_mem(0xDC);

    if (allocated) {
        func_8004D37C()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_8004D2A4(class_3DA54_t *This) {
    renderer_get_vtable()->Construct(This);
    This->vtable = func_8004D37C();
    This->vtable->Unk15(This);
}

void func_8004D2F8(void) {
}

void func_8004D300(class_3DA54_t *This) {
if ( This->m_Unk3 && This->m_Unk27 )
  {
    renderer_get_vtable()->Unk38(This);
  }
}

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
