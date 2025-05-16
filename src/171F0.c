#include "171F0.h"

#include "base_class.h"
#include "memory.h"

extern class_171F0_vtable_t **D_8006D430;
static s32 D_8008A84C = 0x13;

s32 init_800269F0(class_171F0_t *This) {
    This->m_Unk7_1 = 0;
    This->vtable->Cleanup();
    base_class_get_vtable()->Cleanup(This);
    memory_free_mem(This);
    return 0;
}

void func_80026A50(class_171F0_t *This) {
    base_class_get_vtable()->Construct(This);
    This->vtable = func_80026C9C();
    This->m_Unk2 = 0;
    This->m_Buffer = NULL;
    This->m_Unk4 = 0;
    This->m_Unk7_1 = 0;
    This->m_Unk7_2 = 0;
    This->m_Unk8 = 0;
    This->m_Unk9 = 0;
    This->m_Unk10 = 0;
}

void func_80026AB4(class_171F0_t *This) {
    This->vtable->Unk17(This);
    This->vtable->Unk22(This);
}

void func_80026B08(class_171F0_t *This, s32 Unk) {
    s32 size;
    s32 old_unk;
    void *mem;

    if (!This->m_Buffer) {
        old_unk = This->m_Unk2;
        This->m_Unk2 = 0;

        This->vtable->Unk16(This, Unk, 1, 0);
        size = This->vtable->Unk18(This, 0, 2);

        mem = memory_allocate_mem(size);

        if (mem) {
            This->vtable->Unk18(This, 0, 0);
            This->vtable->Unk20(This, mem, size);
            This->vtable->Unk17(This);
            This->m_Buffer = mem;
            This->m_Unk4 = size;
            This->m_Unk2 = old_unk;
        } else {
            memory_free_mem(NULL);
            This->vtable->Unk17(This);
        }
    }
}

void func_80026C20(class_171F0_t *This) {
    if (This->m_Buffer && This->m_Unk4 && !This->m_Unk7_1) {
        memory_free_mem(This->m_Buffer);
        This->m_Buffer = 0;
    }
}

void nullsub13(void) {
}

void func_80026C88(class_171F0_t *This) {
    This->m_Unk8 |= 1;
}

class_171F0_vtable_t *func_80026C9C(void) {
#ifndef CCG8
    return &D_8006D430;
#else
    // G8 hack
    class_171F0_vtable_t *result;

    __asm__ (
        "lui     %0, %%hi(%1)\n\t"
        "addiu   %0, %0, %%lo(%1)"
        : "=r"(result)
        : "i"(&D_8006D430)
    );

    return result;
#endif
}

void *func_80026CAC() {
    if (D_8008A84C == 0x23) {
        return func_8002C438();
    } else {
        return func_80027E68();
    }
}

s32 *func_80026CE8(s32 *Data, s32 Unk1, s32 Unk2, s32 Unk3) {
    Data[0] = Unk1;
    Data[1] = Unk2;
    Data[2] = Unk3;
    return Data;
}

INCLUDE_ASM("asm/nonmatchings/171F0", func_80026CFC);

void func_80026D88(s32 *Dest, s32 *Src) {
    Dest[16] = Src[16];
    Dest[17] = Src[17];
    Dest[18] = Src[18];
    Dest[19] = Src[19];
    Dest[20] = Src[20];
    Dest[21] = Src[21];
    Dest[22] = Src[22];
    Dest[26] = Src[26];
    Dest[27] = Src[27];
    Dest[28] = Src[28];
    Dest[29] = Src[29];
}

void func_80026E0C(void) {
    if (D_8008A84C == 0x13) {
        func_800280D0();
    }
}

void func_80026E38(void) {
    if (D_8008A84C == 0x13) {
        func_800280E0();
    }
}

s32 func_80026E64(void) {
    if (D_8008A84C == 0x13) {
        return func_80027EC8();
    }

    return 0;
}

s32 func_80026E98(void) {
    if (D_8008A84C == 0x13) {
        return func_80027ED4();
    }

    return 1;
}

s32 func_80026ECC(void) {
    if (D_8008A84C == 0x13) {
        return func_80027EE0();
    }

    return 0;
}

s32 func_80026F00(void) {
    if (D_8008A84C == 0x13) {
        return func_80027EEC();
    }

    return 0;
}

INCLUDE_ASM("asm/nonmatchings/171F0", frame_setup);
// void frame_setup(s32 Unk1, s32 Unk2, s32 Unk3) {
//     s32 result;
//     s32 unk;
//     s32 (*callback)(s32, s32, s32);

//     unk = Unk1;
//     callback = func_8002C468;

//     if (D_8008A84C == 0x13) {
//         callback = func_80027F18;
//     }

//     do {
//         result = callback(Unk1, Unk2, Unk3);
//         Unk1 = unk;
//     } while (!result);
// }

s32 func_80026FAC(void) {
    if (D_8008A84C == 0x13) {
        return func_80027EF8();
    }

    return func_8002C448();
}

s32 func_80026FE8(void) {
    if (D_8008A84C == 0x13) {
        return func_80028B6C();
    }

    return func_8002C478();
}

INCLUDE_ASM("asm/nonmatchings/171F0", func_80027024);

INCLUDE_ASM("asm/nonmatchings/171F0", set_data_folder);

INCLUDE_ASM("asm/nonmatchings/171F0", func_800270B8);

INCLUDE_ASM("asm/nonmatchings/171F0", func_800270C4);
