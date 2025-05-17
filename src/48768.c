#include "48768.h"
#include "2C694.h"

extern class_48768_vtable_t **D_80087AAC;

class_48768_t *func_80057F68(s32 Unk1) {
    class_48768_t *allocated = (class_48768_t *) memory_allocate_mem(0x244);

    if (allocated) {
        func_80058764()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_80057FC8(class_48768_t *This, void *Unk) {
    func_8003DFBC()->Construct(This, NULL, "ETC\\ETCSE", 0);
    This->vtable = func_80058764();
    (*(void (**)(s32, int))(*(u32 *) This->m_Unk17 + 156))(This->m_Unk17, -1);
    This->m_Unk40 = Unk;
    This->vtable->Unk53(This, 0);
    This->vtable->Unk15(This, Unk);
}

void func_80058078(class_48768_t *This) {
    This->m_Unk32 = 5;
    This->m_Unk10 = 400;
    This->vtable->Unk52(This, "ETC\\HGRAPH.TIM", 0);
    This->vtable->Unk26(This, 10);
}

void func_800580E0(class_48768_t *This, s32 Unk2, s32 Unk3) {
    void *unk;

    func_8003DFBC()->Unk22(This, Unk2, Unk3);

    if (This->m_Unk14 == 1) {
        unk = (void *) (*(int (**)(void *, u32))(*(u32 *) This->m_Unk40 + 432))(This->m_Unk40, 0);

        if (*((u32 *) unk + 1) || *((u32 *) unk + 2)) {
            (*(void (**)(s32, int))(*(u32 *) This->m_Unk41 + 96))(This->m_Unk41, This->m_Unk6 & 1);
        }
    }

    This->vtable->Unk72(This);
}

void func_800581C4(class_48768_t *This) {
    if (!This->m_Unk141) {
        This->vtable->Unk27(This, 16);
        This->vtable->Unk36(This);
    }
}

INCLUDE_ASM("asm/nonmatchings/48768", func_80058228);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058308);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058390);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058404);

INCLUDE_ASM("asm/nonmatchings/48768", func_800585B4);

INCLUDE_ASM("asm/nonmatchings/48768", func_80058694);

class_48768_vtable_t *func_80058764(void) {
    return &D_80087AAC;
}
