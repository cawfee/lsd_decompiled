#include "413A8.h"
#include "text_line.h"

extern class_413A8_vtable_t D_80086ED0;
extern u8 *D_8008AAE4;

void func_80051998(class_413A8_t *This, s32 arg1, s32 arg2, s32 arg3) {
    text_line_t *label;

    if (This->m_Unk17 != 0) {
        ((u8 *)This->m_Unk9)[arg1] = ((u8 *)D_8008AAE4)[arg2];
        label = (text_line_t *)This->m_Unk16;
        ((void (*)(void *, u8, s32))label->vtable->Unk48)(label, ((u8 *)D_8008AAE4)[arg2], arg1);
        This->m_Unk5 = arg1;
        This->m_Unk6 = arg2;
        if (arg3 != 0) {
            ((void (*)(void *, s32))This->vtable->Unk23)(This, 0);
        }
    }
}

class_413A8_vtable_t *func_80051A4C(void) {
    return &D_80086ED0;
}
