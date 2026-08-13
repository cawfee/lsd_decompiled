#include "359B8.h"
#include "34684.h"

extern class_359B8_vtable_t D_8006F590;

class_359B8_t *func_800451B8(s32 Unk1) {
    class_359B8_t *allocated = (class_359B8_t *) memory_allocate_mem(0x2C);

    if (allocated) {
        if (func_80045428()->Construct(allocated, Unk1)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

class_359B8_t *func_80045228(class_359B8_t *This, s32 *pDword) {
    class_34684_vtable_t *base_vtable;
    class_359B8_vtable_t *new_vtable;

    base_vtable = func_800441A4();
    base_vtable->Construct(This, pDword);

    new_vtable = func_80045428();
    This->vtable = new_vtable;

    if (*pDword != 0) {
        if (new_vtable->Unk24(This) != 0) {
            return NULL;
        }
    }

    return This;
}

void func_800452AC(class_359B8_t *This) {
    func_800183DC((s32 *)(This->m_Unk3 + 8), *(s32 *)(This->m_Unk3 + 4));
  func_800441A4()->Cleanup(This);
}

s32 func_800452FC(class_359B8_t *This) {
    s32 data[3];
    s32 i;
    s32 *entries;
    s32 count;
    s32 result;
    class_34684_t *obj;

    func_80026CE8(data, 0, 0, 1);
    i = 0;
    count = *(s32 *)(This->m_Unk3 + 4);
    entries = (s32 *)(This->m_Unk3 + 8);
    while (i < count) {
        data[0] = This->m_Unk3 + *(s32 *)(This->m_Unk3 + 8 + i * 4);
        result = (s32)func_80043E84((s32)data);
        *entries = result;
        if (result == 0) {
            if (i != 0) {
                do {
                    entries--;
                    obj = (class_34684_t *)*entries;
                    obj->vtable->Destroy(obj);
                } while (--i != 0);
            }
            return 1;
        }
        i++;
        entries++;
    }
    return 0;
}

u8 func_800453DC(class_359B8_t *This, s32 Unk2, s32 Unk3) {
    return ((u8 ( *)(class_359B8_t *, s32, s32, s32))This->vtable->Unk30)(
           This,
           Unk2,
           Unk3,
           4 * *(s32 *)(This->m_Unk3 + 4) + This->m_Unk3 + 16);
}

class_359B8_vtable_t *func_80045428(void) {
    return &D_8006F590;
}
