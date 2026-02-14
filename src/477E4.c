#include "477E4.h"
#include "D294.h"

extern class_477E4_vtable_t D_800878D4;

extern s32 D_8008ABA4[];
extern s32 D_8008ABA8[];

class_477E4_t *func_80056FE4() {
    class_477E4_t *allocated = (class_477E4_t *) memory_allocate_mem(0x58);

    if (allocated) {
        if (func_80057C84()->Construct(allocated)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

void *func_80057044(class_477E4_t *This) {
    if (func_8001E57C()->Construct(This)) {
        This->vtable = func_80057C84();
        This->m_Unk16 = 0;
        This->m_Unk18 = 0;
        This->m_Unk19 = 0;
        This->vtable->Unk15(This);
        return This;
    }

    return NULL;
}

void func_800570B4(class_477E4_t *This, void **Unk) {
    s32 value;

    func_8001E57C()->Unk3(This, Unk);

    value = *(u32 *) *Unk;

    if ((value & 0xFFF) == 0x114) {
        This->m_Unk18 = Unk;
    } else if ((value & 0xF) == 5) {
        This->m_Unk19 = Unk;
    }
}

void func_80057130(class_477E4_t *This, void **Unk) {
    s32 value;

    value = *(u32 *) *Unk;

    if ((value & 0xFFF) == 0x114) {
        This->m_Unk18 = 0;
    } else if ((value & 0xF) == 5) {
        This->m_Unk19 = 0;
    }

    func_8001E57C()->Unk4(This, Unk);
}

void func_800571A8(class_477E4_t *This) {
    This->m_Unk18 = 0;
    This->m_Unk19 = 0;
    func_8001E57C()->Unk5(This);
}

void func_800571E8(class_477E4_t *This) {
    This->m_Unk17_1 = 300;
    This->m_Unk20 = 0;
}

INCLUDE_ASM("asm/nonmatchings/477E4", func_800571F8);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057320);

void func_80057384(class_477E4_t *This, void *Unk) {
    func_800573CC(This, 1, Unk);
}

void func_800573A8(class_477E4_t *This, void *Unk) {
    func_800573CC(This, 0, Unk);
}

INCLUDE_ASM("asm/nonmatchings/477E4", func_800573CC);

void func_80057444(class_477E4_t *This, s16 *Unk) {
    s32 unk_struct[4];

    func_8001E58C(This, unk_struct, Unk);
    This->vtable->Unk46(This, unk_struct);
}

void func_8005748C(class_477E4_t *This, s32 Unk1, s32 Unk2) {
    func_80057534(This, D_8008ABA8, Unk1, Unk2, 6);
}

void func_800574C4(class_477E4_t *This, s32 Unk1, s32 Unk2) {
    func_80057534(This, D_8008ABA4, Unk1, Unk2, 7);
}

void func_800574FC(class_477E4_t *This, s32 Unk1, s32 Unk2) {
    func_80057534(This, (char *) D_8008ABA4 + 2, Unk1, Unk2, 8);
}

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057534);

void func_800575B0(class_477E4_t *This, s32 Unk1, s32 Unk2) {
func_80057618(This, This->vtable->Unk48, Unk1, Unk2);
}

void func_800575E0(class_477E4_t *This, s32 Unk1, s32 Unk2) {
    func_80057618(This, This->vtable->Unk49, Unk1, Unk2);
}

void func_80057610(void) {
}

void func_80057618(class_477E4_t *This, void (*Fnc)(s32, s32, s32), s32 Unk1, s32 Unk2) {
    This->m_Unk9 = 0;
  Fnc(This, Unk1, Unk2);
  if ( !This->m_Unk9 )
    func_80057668(This);
}

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057668);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057784);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057954);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057A18);

class_477E4_t *func_80057B54(class_477E4_t *This, s32 Unk1, s16 *Unk2) {
    if (This && func_8001E7BC(This, Unk1, Unk2)) {
        return This;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057B90);

void func_80057C14(class_477E4_t *This, s32 Unk2, s32 Unk3) {
    func_8001E57C()->Unk38(This, Unk2, Unk3);
}

void func_80057C6C(class_477E4_t *This, s16 Unk) {
    This->m_Unk17_1 = Unk;
}

void func_80057C74(void) {
}

void func_80057C7C(class_477E4_t *This, s32 Unk) {
    This->m_Unk20 = Unk;
}

class_477E4_vtable_t *func_80057C84(void) {
    return &D_800878D4;
}
