#include "46B20.h"
#include "48494.h"

extern s32 D_8008ACA8;

void func_80056D18(class_46B20_t *This, s32 unused, s32 arg2, s32 arg3) {
    class_48494_t **slot;
    s32 i;

    slot = (class_48494_t **)&This->m_Unk32;
    i = 0;
    do {
        *slot = func_80057C94(arg2, 0, D_8008ACA8);
        ((void (*)(void *, void *, s32))(*slot)->vtable->Unk18)(*slot, This, 0);
        ((void (*)(void *, s32))(*slot)->vtable->Unk45)(*slot, This->m_Unk28);
        if (arg3 != 0) {
            ((void (*)(void *, s32, s32))(*slot)->vtable->Unk17)(*slot, 1, arg3);
        }
        i += 1;
        slot += 1;
    } while (i < 5);
}
