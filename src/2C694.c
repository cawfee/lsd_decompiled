#include "2C694.h"

#include "timer.h"

// Unknown class
// Owns main_menu?

extern void **D_8006E854;
extern class_2C694_vtable_t **D_8006E730;

class_2C694_t *func_8003BE94(u32 Unk1, u32 Unk2, u32 Unk3) {
    class_2C694_t *allocated = (class_2C694_t *) memory_allocate_mem(0xA4);

    if (allocated) {
        func_8003DFBC()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_8003BF10(class_2C694_t *This, s32 Unk2, s32 Unk3, sound_engine_t *Unk4) {
    timer_get_vtable()->Construct(This);
    This->vtable = func_8003DFBC();
    This->vtable->Unk53(This, Unk2);

    if (Unk3) {
        This->m_Unk17 = sound_engine_create(Unk3);
    } else {
        This->m_Unk17 = Unk4;
    }

    This->m_Unk16 = Unk3;
    This->vtable->Unk52(This, 0, 0);
    This->m_Unk31 = func_80044F30(0);
    This->m_Unk30 = func_80044CD4(0, This->m_Unk31);
    This->m_Unk29 = func_800441B4(This->m_Unk30, 1);
    This->vtable->Unk15(This);
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C008);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C11C);

s32 func_8003C1DC(class_2C694_t *This, s32 Unk2, s32 Unk3) {
    timer_get_vtable()->Unk16(This, Unk2, Unk3);
    return This->m_Unk13;
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C238);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C3D0);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C48C);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C51C);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C63C);

void func_8003C794(class_2C694_t *This, s32 Unk2) {
    This->m_TimeoutIdleTime = Unk2;

    if (Unk2 >= 0) {
        This->m_TimeoutIdleTime = 20 * Unk2;
    }
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C7B4);

void func_8003C7F4(class_2C694_t *This) {
    if (This->m_Unk18) {
        This->vtable->Unk27(This, 16);
        This->vtable->Unk23(This, 10);
    }
}

void func_8003C858(class_2C694_t *This) {
    s32 value;

    if (This->m_Unk18) {
        This->vtable->Unk27(This, 16);

        value = 15;

        if (This->m_HasIdleTimeout == 1) {
            value = 11;
        }

        This->vtable->Unk23(This, value);
    }
}

void func_8003C8D0(class_2C694_t *This) {
    if (This->m_Unk18) {
        if (This->m_HasIdleTimeout != 1) {
            This->vtable->Unk27(This, 16);
            This->vtable->Unk23(This, 17);
        }
    }
}

void func_8003C944(class_2C694_t *This) {
    void (*callback)(void);

    if (This->m_Unk18) {
        if (This->m_HasIdleTimeout == 1) {
            callback = This->vtable->Unk58;
        } else {
            if (This->m_HasIdleTimeout != 2) {
                return;
            }

            callback = This->vtable->Unk69;
        }

        callback();
    }
}

void func_8003C9B0(class_2C694_t *This) {
    void (*callback)(void);

    if (This->m_Unk18) {
        if (This->m_HasIdleTimeout == 1) {
            callback = This->vtable->Unk57;
        } else {
            if (This->m_HasIdleTimeout != 2) {
                return;
            }

            callback = This->vtable->Unk68;
        }

        callback();
    }
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CA1C);

void func_8003CA94(class_2C694_t *This) {
    if (This->m_Unk38) {
        This->m_Unk38(This->m_Unk39);
    }

    This->vtable->Unk23(This, 7);
}

void func_8003CAEC(class_2C694_t *This, void (*Callback)(void *), s32 Arg) {
    This->m_Unk38 = Callback;
    This->m_Unk39 = Arg;
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CAF8);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CB30);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CB68);

void func_8003CBB8(class_2C694_t *This, s32 Unk) {
    This->m_Unk32 = Unk;
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CBC0);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CC2C);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CCDC);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CD48);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CDE0);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CE98);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D050);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D194);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D2CC);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D3B0);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D444);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D4DC);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D5C0);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D5CC);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D6D4);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D73C);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D980);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003DA10);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003DAD4);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003DCAC);

void func_8003DDC8(class_2C694_t *This) {
    s32 value;

    value = This->m_Unk23[This->m_Unk21];
    value++;

    if (value >= This->m_Unk22[This->m_Unk21]) {
        value = 0;
    }

    This->vtable->Unk70(This, value, 1);
}

void func_8003DE30(class_2C694_t *This) {
    s32 value;

    value = This->m_Unk23[This->m_Unk21];
    value--;

    if (value < 0) {
        value = This->m_Unk22[This->m_Unk21] - 1;
    }

    This->vtable->Unk70(This, value, 1);
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003DE9C);

s32 func_8003DFA0(class_2C694_t *This) {
    return This->m_Unk23[This->m_Unk21];
}

class_2C694_vtable_t *func_8003DFBC(void) {
    return &D_8006E730;
}

void *func_8003DFCC(void) {
    return &D_8006E854;
}
