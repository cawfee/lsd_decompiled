#include "322B4.h"

#include "3249C.h"

extern class_322B4_vtable_t **D_8006EC74;

void func_80041C4C(s8 *, s32);

class_322B4_t *func_80041AB4(s32 Unk1, u8 Unk2) {
    class_322B4_t *allocated = (class_322B4_t *) memory_allocate_mem(0xAC);

    if (allocated) {
        func_80041C3C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void func_80041B20(class_322B4_t *This, s32 Unk1, u8 Unk2) {
    s8 v3[16];

    func_80041C4C(v3, 0x20);
    func_80041ED8()->Construct(This, Unk1, (s32)v3, 0);
    This->vtable = func_80041C3C();
    This->vtable->Unk15(This, Unk2);
}

void func_80041BAC(class_322B4_t *This, u8 Unk) {
    This->vtable->Unk48(This, Unk);
}

void func_80041BDC(class_322B4_t *This, u8 Unk) {
    s8 v3[16];

  This->m_Unk41_1 = Unk;
  func_80041C4C(v3, Unk);
  This->m_Unk27[2] = v3[0];
  This->m_Unk27[3] = v3[2];
}

u8 func_80041C28(class_322B4_t *This) {
    s8 pad[0x10];

    return This->m_Unk41_1;
}

class_322B4_vtable_t *func_80041C3C(void) {
    return &D_8006EC74;
}
