#include "34684.h"

extern class_34684_vtable_t D_8006F240;

class_34684_t *func_80043E84(s32 Unk1) {
    class_34684_t *allocated = (class_34684_t *) memory_allocate_mem(0x2C);

    if (allocated) {
        func_800441A4()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_80043EE4(class_34684_t *This, s32 *Unk) {
    void *unk_class = func_80026CAC();
    (*(void (**)(class_34684_t *))(unk_class + 8))(This);

    This->vtable = func_800441A4();

    if (*Unk) {
        This->m_Unk3 = *Unk;
        This->m_Unk4 = 0;
        This->vtable->Unk24(This);
    } else {
        This->vtable->Unk26(This, Unk[1]);
    }
}

void func_80043F78(class_34684_t *This) {
    void *unk = func_80026CAC();
    (*(void (**)(class_34684_t *))(unk + 12))(This);
}

u8 func_80043FB0(class_34684_t *This, s32 Unk1, s32 Unk2) {
    return This->vtable->Unk30(This, Unk1, Unk2, This->m_Unk3 + 8);
}

INCLUDE_ASM("asm/nonmatchings/34684", func_80043FE4);

u32 *func_8004416C(class_34684_t *This, u32 *Src, u8 *dst1, u8 *dst2, u8 *dst3, u8 *dst4) {
    u32 val;

    val = *Src;
    *dst1 = val;
    *dst2 = (val >> 16) & 0xF;
    *dst3 = (val >> 20) & 0xF;
    *dst4 = val >> 24;
    return Src + 1;
}

class_34684_vtable_t *func_800441A4(void) {
    return &D_8006F240;
}
