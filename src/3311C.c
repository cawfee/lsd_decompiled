#include "3311C.h"
#include "base_class.h"

#include <psx/libgs.h>

extern class_3311C_vtable_t D_8006F06C;

class_3311C_t *func_8004291C(s32 Unk1) {
    class_3311C_t *allocated = (class_3311C_t *) memory_allocate_mem(0x20);

    if (allocated) {
        func_80042A7C()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_8004297C(class_3311C_t *This, s32 Unk) {
    base_class_get_vtable()->Construct(This);
    This->vtable = func_80042A7C();
    This->vtable->Unk15(This, Unk);
}

void func_800429E0(class_3311C_t *This, s32 Unk) {
    This->m_Unk2 = Unk;
}

void func_800429E8(class_3311C_t *This, s32 Unk1, s8 *Unk2) {
    if ( Unk1 )
  {
    __builtin_memcpy(&This->m_Unk6, Unk2, 3);
  }
  GsSetFlatLight(This->m_Unk2, &This->m_Unk3);
}

void func_80042A2C(class_3311C_t *This, s32 Unk2, s16 *Unk3) {
    if ( Unk2 )
  {
    This->m_Unk3 = *Unk3;
    This->m_Unk4 = Unk3[1];
    This->m_Unk5 = Unk3[2];
  }
  GsSetFlatLight(This->m_Unk2, &This->m_Unk3);
}

class_3311C_vtable_t *func_80042A7C() {
    return &D_8006F06C;
}
