#include "common.h"

#include <psx/kernel.h>

#include "base_class.h"
#include "memory_card.h"

extern memory_card_vtable_t *g_MEMORY_CARD_VTABLE;
extern s32 D_80086E78;

memory_card_t *memory_card_create(u32 Unk1, u32 Unk2) {
    memory_card_t *allocated = (memory_card_t *) memory_allocate_mem(0x84);

    if (allocated) {
        memory_card_get_vtable()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/memory_card", memory_card_on_construct);

void memory_card_state_reset(memory_card_t *This) {
    This->m_Unk23 = 0;
    This->m_Unk24 = 0;
    This->m_Unk25 = 0;
    This->m_Unk29 = 0;
    This->m_Unk30 = 0;
}

void func_8004E40C(memory_card_t *This) {
    base_class_get_vtable()->Cleanup(This);
}

void func_8004E444(memory_card_t *This, void *Unk) {
    s32 unk;

    if (Unk) {
        base_class_get_vtable()->Unk3(This, Unk);

        unk = **(s32 **) Unk;

        if ((unk & 0xF) == 2) {
            This->m_Unk23 = Unk;
        } else {
            if ((unk & 0xF) == 5) {
                This->m_Unk24 = Unk;
            } else {
                if ((unk & 0xFF) == 16) {
                    This->m_Unk29 = Unk;
                } else if ((unk & 0xFF) == 32) {
                    This->m_Unk30 = Unk;
                }
            }
        }
    }
}

void func_8004E4E8(memory_card_t *This, void *Unk) {
    s32 unk;

    if (Unk) {
        unk = **(s32 **) Unk;

        if ((unk & 0xF) == 2) {
            This->m_Unk23 = NULL;
        } else {
            if ((unk & 0xF) == 5) {
                This->m_Unk24 = NULL;
            } else {
                if ((unk & 0xFF) == 16) {
                    This->m_Unk29 = NULL;
                } else if ((unk & 0xFF) == 32) {
                    This->m_Unk30 = NULL;
                }
            }
        }

        base_class_get_vtable()->Unk4(This, Unk);
    }
}

void func_8004E588(memory_card_t *This) {
    This->m_Unk23 = 0;
    This->m_Unk24 = 0;
    This->m_Unk25 = 0;
    This->m_Unk29 = 0;
    This->m_Unk30 = 0;
    base_class_get_vtable()->Unk5(This);
}

void func_8004E5D4(memory_card_t *This, s32 Count) {
    This->m_Unk2 = Count;
    This->m_Unk3 = 16 * Count;
}

s32 func_8004E5E4(memory_card_t *arg0) {
    s32 temp_a1;
    s32 var_s2;
    s32 *var_s0 = NULL;
    memory_card_t *var_s1 = NULL;

    EnterCriticalSection();
    var_s2 = 0;
    var_s1 = arg0;
    var_s0 = &D_80086E78;
    do {
        temp_a1 = *var_s0;
        var_s1->m_Unk4 = OpenEvent(0xF4000001, temp_a1, 0x2000, 0);
        var_s0 += 1;
        var_s2 += 1;
        var_s1 = (memory_card_t *) ((u32) var_s1 + 4);
    } while (var_s2 < 4);
    ExitCriticalSection();
    func_8004F394(arg0);
    return 1;
}

int func_8004E678(memory_card_t *This) {
    func_8004F3BC(This);
    func_8004F40C(This, CloseEvent, 1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004E6B8);

void func_8004E77C(void *arg0, u32 *arg1, u32 *arg2, u32 *arg3) {
    if (func_8004E7D0(arg0, arg1, arg2) != 0) {
        func_8004E890(arg0, arg1, arg3);
    }
}

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004E7D0);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004E890);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004E940);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004E9AC);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004EA38);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004EADC);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004EB88);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004EC5C);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004ECCC);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004ED40);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004EDC0);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004EEA0);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004EF6C);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F32C);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F394);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F3BC);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F3E4);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F40C);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F4A4);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F4C8);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F55C);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F5DC);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F638);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F704);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F784);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F810);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F8A4);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004F9D8);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004FB04);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004FBE4);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004FE24);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004FF40);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004FF90);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_8004FFF4);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_80050034);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_800501F0);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_80050280);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_80050340);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_80050410);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_800504D0);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_800505A8);

INCLUDE_ASM("asm/nonmatchings/memory_card", func_80050670);

void func_80050730(memory_card_t *This, void *UnkClass, s32 Unk) {
    switch (Unk) {
        case 2:
            This->m_Unk31 = (*(s32(**)(void *))(*(u32 *) UnkClass + 156))(UnkClass);
            This->vtable->Unk42(This);
            This->vtable->Unk30(This, 14);
            break;

        case 3:
            This->vtable->Unk42(This);
            This->vtable->Unk30(This, 23);
            break;

        default:
            break;
    }
}

memory_card_vtable_t *memory_card_get_vtable(void) {
    return &g_MEMORY_CARD_VTABLE;
}
