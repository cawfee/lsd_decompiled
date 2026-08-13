#include "32E94.h"

#include <psx/libgs.h>

#include "D294.h"
#include "3311C.h"

extern class_32E94_vtable_t **D_8006EFAC;
class_3311C_t *func_8004291C(s32 Unk1);

class_32E94_t *func_80042694() {
    class_32E94_t *allocated = (class_32E94_t *) memory_allocate_mem(0x54);

    if (allocated) {
        func_800428E4()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_800426E4(class_32E94_t *This) {
    s32 i;
    s32 *slot;
    class_3311C_t *obj;

    func_8001E57C()->Construct(This);
    This->vtable = func_800428E4();
    i = 0;
    slot = &This->m_Unk16;
    do {
        obj = func_8004291C(i);
        *slot = (s32)obj;
        This->vtable->Unk3(This, obj);
        i += 1;
        slot += 1;
    } while (i < 3);
    This->vtable->Unk15(This);
}

void func_80042790(class_32E94_t *This) {
    s32 i;
    void *obj;

    i = 0;
    do {
        obj = This->vtable->Unk45(This, i);
        i += 1;
        (*(void (**)(void *))(*(s32 *)obj + 4))(obj);
    } while (i < 3);

    func_8001E57C()->Cleanup(This);
}

void func_80042814(class_32E94_t *This) {
    *This->m_Unk4 = 0;
}

void func_80042820(void) {
}

s32 func_80042828(class_32E94_t *This, int Unk) {
    return *(&This->m_Unk16 + Unk);
}

void func_8004283C(class_32E94_t *This, s8 *RGB, s32 Swap) {
    s8 tmp[3];

    if (Swap != 0) {
        __builtin_memcpy(tmp, (s8 *)(s32)This->m_Ambient, 3);
        __builtin_memcpy(This->m_Ambient, RGB, 3);
        __builtin_memcpy(RGB, tmp, 3);
    } else {
        __builtin_memcpy(This->m_Ambient, RGB, 3);
    }
    GsSetAmbient((u8)This->m_Ambient[0] << 4, (u8)This->m_Ambient[1] << 4,
                 (u8)This->m_Ambient[2] << 4);
}

class_32E94_vtable_t *func_800428E4() {
    return &D_8006EFAC;
}
