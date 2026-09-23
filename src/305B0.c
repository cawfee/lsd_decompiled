#include "305B0.h"
#include "30CD0.h"

extern class_305B0_vtable_t g_CLASS_305B0_VTABLE;

extern s32 D_8006EAA8[];
extern s32 D_8006EA90[];

class_305B0_t *class_305B0_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_305B0_t *allocated = (class_305B0_t *) memory_allocate_mem(0xA0);

    if (allocated) {
        class_305B0_get_vtable()->class_305B0_construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void class_305B0_construct(class_305B0_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    class_30CD0_vtable_t *parent;
    void *color;

    parent = func_800408BC();
    if (Unk2 != 0) {
        color = (u8 *)&D_8006EA90 + (Unk2 * 3);
    } else {
        color = &D_8006EAA8;
    }
    parent->Construct(This, Unk1, (u32)color, Unk3);
    This->vtable = class_305B0_get_vtable();
    This->vtable->Unk15(This, Unk2);
}

void func_8003FED8(class_305B0_t *This, s32 Unk2) {
    This->m_Unk27 = Unk2;
    This->m_Unk26 = 0;
    This->m_Unk28 = 10;
    This->m_Unk29 = 0;
    This->m_Unk30 = 0;
    This->vtable->Unk23(This, 0);
    This->vtable->Unk24(This, 0);
    This->m_Unk37 = 0;
}

void func_8003FF44(class_305B0_t *This, int Unk2, int Unk3) {
    if (Unk3 == 2) {
        s32 value = This->m_Unk31;

        This->m_Unk31 = value - 1;

        if (value > 0) {
            if (This->m_Unk30 != 9) {
                if ((This->m_Unk29 & 4) != 0) {
                    ((u8 *) &This->m_Unk24)[0] += (u8) This->m_Unk28;
                }

                if ((This->m_Unk29 & 2) != 0) {
                    ((u8 *) &This->m_Unk24)[1] += (u8) This->m_Unk28;
                }

                if ((This->m_Unk29 & 1) != 0) {
                    ((u8 *) &This->m_Unk24)[2] += (u8) This->m_Unk28;
                }
            }
        } else {
            This->vtable->Unk55(This, Unk2);
        }
    }
}

void func_8004001C(class_305B0_t *This, s32 Value) {
    This->m_Unk28 = Value;
}

INCLUDE_ASM("asm/nonmatchings/305B0", func_80040024);

INCLUDE_ASM("asm/nonmatchings/305B0", func_800400B0);

INCLUDE_ASM("asm/nonmatchings/305B0", func_80040154);

void func_800402F0(class_305B0_t *This, s32 arg1) {
    class_305B0_vtable_t *vt;
    s32 state;
    s32 which;

    state = This->m_Unk26;
    vt = This->vtable;
    if (state != 0) {
        if (state == 1) {
            which = 5;
            if (This->m_Unk37 == 0) {
                vt->Unk23(This, 0);
                vt->Unk24(This, 0);
            }
        } else {
            which = 6;
            if (This->m_Unk37 != 0) {
                if (This->m_Unk29 == 0xF) {
                    vt->Unk45(This, 1, D_8006EAA8);
                }
                vt->Unk24(This, 0);
            }
        }
        vt->Unk4(This, arg1);
        if (This->m_Unk28 < 0) {
            This->m_Unk28 = -This->m_Unk28;
        }
        This->m_Unk26 = 0;
        vt->Unk11(This, which);
    }
}

s32 func_800403F8(class_305B0_t *This) {
    if (This->m_Unk29 == 15) {
        return D_8006EAA8;
    }

    return (s32 *)((s8 *)D_8006EA90 + 3 * This->m_Unk29);
}

void func_8004042C(class_305B0_t *This, u16 *a, s32 *b) {
    if (This->m_Unk2 != 0) {
        This->m_Unk33 = (u16)This->m_Unk23_1;
        This->m_Unk34 = (u16)This->m_Unk23_2;
        __builtin_memcpy(&This->m_Unk35, &This->m_Unk19, 8);
        This->m_Unk23_1 = a[0];
        This->m_Unk23_2 = a[2];
        __builtin_memcpy(&This->m_Unk19, b, 8);
    }
}

void func_80040490(class_305B0_t *This) {
    __builtin_memcpy(&This->m_Unk19, &This->m_Unk35, 8);
    This->m_Unk23_1 = This->m_Unk33;
    This->m_Unk23_2 = This->m_Unk34;
}

void func_800404B4(class_305B0_t *This, s32 Unk2, s32 Unk3) {
    This->m_Unk37 = Unk2;
    This->m_Unk38 = Unk3;
}

class_305B0_vtable_t *class_305B0_get_vtable() {
    return &g_CLASS_305B0_VTABLE;
}
