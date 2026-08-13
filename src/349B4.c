#include "349B4.h"
#include "D294.h"
#include "349B4.h"

extern class_349B4_vtable_t D_8006F2C4;
extern s8 D_8008A938[];

class_349B4_t *func_800441B4(s32 Unk1, s32 Unk2) {
    class_349B4_t *allocated = (class_349B4_t *) memory_allocate_mem(0x68);

    if (allocated) {
        func_8004467C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void func_80044220(class_349B4_t *This, s32 Unk2, s32 Unk3) {
    func_8001E57C()->Construct(This);
    This->vtable = func_8004467C();
    This->vtable->Unk15(This, Unk2, Unk3);
}

void func_80044294(class_349B4_t *This, u8 *arg1, s32 arg2) {
    if (arg2 == 0) {
        This->m_Unk16 = 0x01000000;
        This->m_Unk18_0 = arg1[0x2C] * *(u16*)(arg1 + 0x2E);
        This->m_Unk18_1 = arg1[0x2D] * *(u16*)(arg1 + 0x30);
    } else if (arg2 == 1) {
        This->m_Unk16 = 0x02000000;
        This->m_Unk18_0 = 0x140;
        This->m_Unk18_1 = 0xF0;
    }

    This->m_Unk17_0 = 0;
    This->m_Unk17_1 = 0;
    This->m_Unk19_0 = 0;
    This->m_Unk19_1 = 0;

    __builtin_memcpy(&This->m_Unk20, &D_8008A938, 3);

    This->m_Unk21 = arg1 + 0x2C;
    This->m_Unk23_0 = 0x1000;
    This->m_Unk23_1 = 0x1000;
    This->m_Unk24 = 0;

    This->m_Unk22_0 = (s16)This->m_Unk18_0 / 2;
    This->m_Unk22_1 = (s16)This->m_Unk18_1 / 2;
}

void func_80044380(class_349B4_t *This, s32 arg1, u8 *arg2) {
    s32 num = *(s16 *)(arg2 + 8);
    s32 den = *(s16 *)(arg2 + 10);

    s32 val = ((num / den) << 12) + (((num % den) << 12) / den);
    
    if (arg1 != 0) {
        This->m_Unk24 = val;
    } else {
        This->m_Unk24 += val;
    }
}

INCLUDE_ASM("asm/nonmatchings/349B4", func_8004441C);
// 90%
// void func_8004441C(class_349B4_t *This, s32 a1, s16 *a2) {
//     s32 v3;
//     s32 v4;
//     s32 v6 = 0;
//     s32 v7 = 0;

//     if (a2[0] < 0 || a2[1] < 0) {
//         v6 = 1;
//     }
//     if (a2[2] < 0 || a2[3] < 0) {
//         v7 = 1;
//     }

//     if (a2[1] != 0) {
//         v3 = ((a2[0] / a2[1]) << 12) + (((a2[0] % a2[1]) << 12) / a2[1]);
//     }

//     if (a2[3] != 0) {
//         v4 = ((a2[2] / a2[3]) << 12) + (((a2[2] % a2[3]) << 12) / a2[3]);
//     }

//     if (a1 != 0) {
//         if (a2[1] == 0) {
//             This->m_Unk23_0 = 4096;
//         } else {
//             s16 val = v3;
//             if (val >= 30001) {
//                 val = 30000;
//             }
//             This->m_Unk23_0 = val;
//         }

//         if (a2[3] == 0) {
//             This->m_Unk23_1 = 4096;
//         } else {
//             s16 val = v4;
//             if (val >= 30001) {
//                 val = 30000;
//             }
//             This->m_Unk23_1 = val;
//         }
//     } else {
//         if (This->m_Unk23_0 + (s16)v3 < 30001) {
//             This->m_Unk23_0 = This->m_Unk23_0 + v3;
//         } else {
//             s16 val = 1;
//             if (v6 == 0) {
//                 val = 30000;
//             }
//             This->m_Unk23_0 = val;
//         }

//         if (This->m_Unk23_1 + (s16)v4 < 30001) {
//             This->m_Unk23_1 = This->m_Unk23_1 + v4;
//         } else {
//             s16 val = 1;
//             if (v7 == 0) {
//                 val = 30000;
//             }
//             This->m_Unk23_1 = val;
//         }
//     }
// }

void func_8004464C(class_349B4_t *This, s32 Unk1, s8 *Data) {
    if (Unk1) {
        __builtin_memcpy(This->m_Unk20, Data, 3);
    }
}

void func_80044674(void) {
}

class_349B4_vtable_t *func_8004467C(void) {
    return &D_8006F2C4;
}
