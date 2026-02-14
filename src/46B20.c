#include "46B20.h"
#include "477E4.h"

extern class_46B20_vtable_t D_800876FC;

class_46B20_t *func_80056320(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    class_46B20_t *allocated = (class_46B20_t *) memory_allocate_mem(0x98);

    if (allocated) {
        class_46B20_vtable_t *vtable = func_80056F4C();

        if (vtable->Construct(allocated, Unk1, Unk2, Unk3, Unk4)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

void *func_800563C0(class_46B20_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    class_46B20_vtable_t *vtable;

    if (func_80057C84()->Construct(This)) {
        This->vtable = func_80056F4C();

        This->m_Unk16 = 0;
        This->m_Unk20 = Unk1;
        This->vtable->Unk15(This, Unk2);

        func_80056520(This, Unk3, Unk4);
        return This;
    }

    return NULL;
}

void func_80056464(class_46B20_t *This) {
    func_80056718();
    func_80057C84()->Cleanup(This);
}

void func_800564A4(class_46B20_t *This, s32 *Unk) {
    __builtin_memcpy(&This->m_Unk21, Unk, 36);
    This->m_Unk8 = 0;
}

void func_800564F4(class_46B20_t *This, s32 Unk1) {
    ++This->m_Unk8;
    func_80056640(This, Unk1);
}

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056520);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056640);

void func_80056718(class_46B20_t *This) {
    switch (This->m_Unk20) {
        case 0:
            func_80056B8C(This);
            break;

        case 2:
            func_80056DF8(This);
            return;

        case 3:
            func_80056F28(This);
            return;

        default:
            break;
    }
}

void func_80056794(class_46B20_t *This, s32 *Unk1, s32 *Unk2) {
    This->vtable = (class_46B20_vtable_t *) (*Unk1 + *Unk2);
    This->m_Unk0 = Unk1[1] + Unk2[1];
    This->m_Unk1 = Unk1[2] + Unk2[2];
}

void func_800567D4(class_46B20_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    This->vtable->Unk18(This, Unk1, Unk2);
    This->vtable->Unk16(This, 1, Unk3);
    This->vtable->Unk17(This, 1, Unk4);
}

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056858);

INCLUDE_ASM("asm/nonmatchings/46B20", func_800569A8);

void func_80056B8C(class_46B20_t *This) {
    s32 m_Unk26;
    s32 *p_m_Unk30;

    m_Unk26 = This->m_Unk26;
    p_m_Unk30 = &This->m_Unk30;
    if (m_Unk26) {
        func_800183DC(p_m_Unk30, 2);
    }
}

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056BBC);

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056D18);

void func_80056DF0(void) {
}

void func_80056DF8(class_46B20_t *This) {
    func_800183DC(&This->m_Unk32, 5);
}

void func_80056E1C(class_46B20_t *This) {
    func_80056D18(This, 0, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/46B20", func_80056E44);

void func_80056F28(class_46B20_t *This) {
    func_800183DC(&This->m_Unk32, 5);
}

class_46B20_vtable_t *func_80056F4C(void) {
    return &D_800876FC;
}
