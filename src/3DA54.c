#include "3DA54.h"
#include "base_class.h"
#include "renderer.h"

void func_8004D2A4(void *);
void func_8003E6CC(void *);
void func_8003E770(void *);
void func_8003E7F4(void *);
void func_8003E874(void *);
void func_8003E8B8(void *);
void func_8004D2F8(void *);
void func_8003EA0C(void *);
void func_8003EA24(void *);
void func_8003EA2C(void *);
void func_8003EA48(void *);
void func_8003EA64(void *);
void func_8003EA6C(void *);
void func_8003EA74(void *);
void func_8003EA7C(void *);
void func_8003EA84(void *);
void func_8003EAA4(void *);
void func_8003EAC4(void *);
void func_8003EACC(void *);
void func_8003EB84(void *);
void func_8003EBC4(void *);
void func_8003EBF8(void *);
void func_8003EC2C(void *);
void func_8003ECC0(void *);
void func_8003ECC8(void *);
void func_8003ECD0(void *);
void func_8003EDF4(void *);
void func_8003EE40(void *);
void func_8003EE88(void *);
void func_8004D300(void *);
void func_80012064(void *);
void func_8003F04C(void *);
void func_8003F1A8(void *);
void func_8003F230(void *);
void func_8003F23C(void *);
void func_8003F244(void *);
void func_8004D35C(void *);
void func_8004D364(void *);
void func_8004D36C(void *);
void func_8004D374(void *);

class_3DA54_vtable_t D_800869D8 = {
    0x17,
    base_class_destructor,
    func_8004D2A4,
    func_8003E6CC,
    func_8003E770,
    func_8003E7F4,
    func_8003E874,
    base_class_iter_children,
    base_class_add_parent,
    base_class_remove_parent,
    base_class_clear_parents,
    base_class_iter_parents,
    base_class_notify,
    base_class_nop,
    func_8003E8B8,
    NULL,
    func_8004D2F8,
    func_8003EA0C,
    func_8003EA24,
    func_8003EA2C,
    func_8003EA48,
    func_8003EA64,
    func_8003EA6C,
    func_8003EA74,
    func_8003EA7C,
    func_8003EA84,
    func_8003EAA4,
    func_8003EAC4,
    func_8003EACC,
    func_8003EB84,
    func_8003EBC4,
    func_8003EBF8,
    func_8003EC2C,
    func_8003ECC0,
    func_8003ECC8,
    func_8003ECD0,
    func_8003EDF4,
    func_8003EE40,
    func_8003EE88,
    func_8004D300,
    func_80012064,
    func_8003F04C,
    func_8003F1A8,
    func_8003F230,
    func_8003F23C,
    func_8003F244,
    func_8004D35C,
    func_8004D364,
    func_8004D36C,
    func_8004D374,
};

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

void func_8004D2F8(void *) {
}

void func_8004D300(class_3DA54_t *This) {
if ( This->m_Unk3 && This->m_Unk27 )
  {
    renderer_get_vtable()->Unk38(This);
  }
}

void func_8004D35C(void *) {
}

void func_8004D364(void *) {
}

void func_8004D36C(void *) {
}

void func_8004D374(void *) {
}

class_3DA54_vtable_t *func_8004D37C(void) {
    return &D_800869D8;
}
