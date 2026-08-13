#include "3249C.h"

#include "326E8.h"

extern class_3249C_vtable_t **D_8006ED4C;
extern s32 D_8006EE10;

class_3249C_t *func_80041C9C(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_3249C_t *allocated = (class_3249C_t *) memory_allocate_mem(0xA8);

    if (allocated) {
        func_80041ED8()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_80041D18(class_3249C_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    func_800422BC()->Construct(This, Unk1, 0, Unk2, 0, Unk3);
    This->vtable = func_80041ED8();
    This->vtable->Unk15(This);
}

void func_80041DA4(void) {
}

void func_80041DAC(class_3249C_t *This, s32 Unk1, s32 Unk2) {
    if (This->m_Unk2 == 0) {
        ((void (*)(void *, s32, s32 *))func_800422BC()->Unk18)(This, Unk1, &D_8006EE10);
        ((void (*)(void *, s32))This->vtable->Unk46)(This, Unk2);
    }
}

void func_80041E2C(class_3249C_t *This, s32 *Unk) {
    if (This->m_Unk2) {
        __builtin_memcpy(&This->m_Unk39, Unk, 8);
    }
}

void func_80041E58(class_3249C_t *This, u32 Unk) {
    if (This->m_Unk2 != 0 && Unk < 5) {
        switch (Unk) {
        case 0:
            This->m_Unk30_0 = This->m_Unk26_0 >> 1;
            This->m_Unk30_1 = This->m_Unk26_1 >> 1;
            break;
        case 1:
            This->m_Unk30_0 = 0;
            break;
        case 2:
            This->m_Unk30_0 = This->m_Unk26_0;
            break;
        case 3:
            This->m_Unk30_1 = 0;
            break;
        case 4:
            This->m_Unk30_1 = This->m_Unk26_1;
            break;
        }
    }
}

class_3249C_vtable_t *func_80041ED8(void) {
    return &D_8006ED4C;
}
