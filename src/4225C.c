#include "4225C.h"
#include "base_class.h"

extern class_4225C_vtable_t D_80086F88;

class_4225C_t *func_80051A5C(s32 Unk1, s32 Unk2) {
    class_4225C_t *allocated = (class_4225C_t *) memory_allocate_mem(0x54);

    if (allocated) {
        func_80052B60()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051AC8);

void func_80051C74(class_4225C_t *This) {
    This->m_Unk12 = 0;
    This->m_Unk13 = 0;
    This->m_Unk19 = 0;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051C84);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051D1C);

void func_80051DA0(class_4225C_t *This, void **Unk) {
    s32 kind;

    if (Unk != NULL) {
        kind = *(u32 *)*Unk & 0xF;
        if (kind == 2) {
            This->m_Unk12 = 0;
        } else if (kind == 5) {
            This->m_Unk13 = 0;
        }
        base_class_get_vtable()->Unk4(This, Unk);
    }
}

void func_80051E20(class_4225C_t *This) {
    This->m_Unk12 = 0;
  This->m_Unk13 = 0;
  This->m_Unk19 = 0;
  base_class_get_vtable()->Unk5(This);
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051E64);

void func_80051F14(class_4225C_t *This) {
    This->m_Unk7 = 0;
    This->m_Unk8 = 0;
    This->m_Unk9 = 0;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051F24);

void func_800520A0(class_4225C_t *This) {
    if (This->m_Unk19) {
        ((void (*)(void *))This->vtable->Unk35)(This);
        This->m_Unk19 = (*(s32 (**)(s32))(*(s32 *)This->m_Unk19 + 4))(This->m_Unk19);
    }
}

void func_80052110(class_4225C_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    ((void (*)(void *, s32))This->vtable->Unk3)(This, Unk1);
    ((void (*)(void *, s32))This->vtable->Unk3)(This, Unk2);
    This->m_Unk14 = Unk3;
    This->m_Unk10 = 0;
}

void func_8005217C(class_4225C_t *This) {
    This->vtable->Unk4(This, This->m_Unk12);
  This->vtable->Unk4(This, This->m_Unk13);
  This->m_Unk14 = 0;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_800521D4);

void func_8005227C(class_4225C_t *This) {
    s32 unk10;
    s32 unk11;

    unk10 = This->m_Unk10;
    if (unk10 < 4) {
        if (!(unk10 < 2)) {
            unk11 = This->m_Unk11;
            This->m_Unk11 = unk11 + 1;
            if (unk11) {
                ((void (*)(void *, s32))This->vtable->Unk20)(This, 4);
            }
        }
    }
}

void func_800522DC(class_4225C_t *This, s32 Unk2, s32 Unk3) {
    void (*fn)(void *);

    switch (Unk3) {
        case 25:
            ((void (*)(void *, s32))This->vtable->Unk23)(This, 0x10);
            ((void (*)(void *, s32))This->vtable->Unk20)(This, 2);
            break;
        case 23:
            ((void (*)(void *, s32))This->vtable->Unk23)(This, 0x10);
            ((void (*)(void *, s32))This->vtable->Unk20)(This, 3);
            break;
        case 5:
            fn = This->vtable->Unk30;
            goto do_call;
        case 4:
            fn = This->vtable->Unk31;
            goto do_call;
        case 18:
            fn = This->vtable->Unk32;
            goto do_call;
        case 19:
            fn = This->vtable->Unk33;
        do_call:
            fn(This);
            break;
    }
}

void func_800523F0(class_4225C_t *This, s32 Unk) {
    s32 m_Unk14; // $a0

  m_Unk14 = This->m_Unk14;
  if ( m_Unk14 ) {
    (*(void ( **)(s32, int, int, int))(*(s32 *)m_Unk14 + 128))(m_Unk14, Unk, 96, 96);
  }
}

void func_80052430(class_4225C_t *This) {
    s32 cur;
    s32 neu;
    s32 flag;

    if (This->m_Unk19) {
        cur = This->m_Unk8;
        if (cur + 0x1A < This->m_Unk4) {
            neu = cur + 1;
            flag = 1;
            This->m_Unk8 = neu;
            ((void (*)(void *, s32, s32, s32, s32))This->vtable->Unk36)(
                This, This->m_Unk7, neu, This->m_Unk9, flag);
        }
    }
}

void func_80052498(class_4225C_t *This) {
    s32 neu;

    if (This->m_Unk19) {
        neu = This->m_Unk8 - 1;
        if (neu >= 0) {
            This->m_Unk8 = neu;
            ((void (*)(void *, s32, s32, s32, s32))This->vtable->Unk36)(
                This, This->m_Unk7, neu, This->m_Unk9, 1);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_800524F8);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052598);

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052644);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005278C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005281C);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005292C);

extern s32 D_8008AB10;

void func_800529FC(class_4225C_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    s32 flag;
    s32 obj;

    flag = Unk4;
    This->m_Unk7 = Unk1;
    This->m_Unk8 = Unk2;
    This->m_Unk9 = Unk3;
    if (flag != 0) {
        Unk3 = Unk3 - Unk1;
        obj = *(s32 *)((u8 *)This + 0x40 + (Unk3 * 4));
        (*(void (**)(s32, s32 *))(*(s32 *)obj + 0xB8))(obj, &D_8008AB10);
    }
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052A58);

s32 func_80052B54(class_4225C_t *This) {
    return This->m_Unk9;
}

class_4225C_vtable_t *func_80052B60(void) {
    return &D_80086F88;
}
