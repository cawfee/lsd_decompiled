#include "menu/ui_sprite.h"
#include "base/transform.h"
#include "menu/ui_sprite.h"

extern ui_sprite_vtable_t D_8006F2C4;
extern s8 D_8008A938[];

ui_sprite_t *func_800441B4(s32 Unk1, s32 Unk2) {
    ui_sprite_t *allocated = ALLOCATE_STRUCT(ui_sprite_t);

    if (allocated) {
        func_8004467C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void func_80044220(ui_sprite_t *This, s32 Unk2, s32 Unk3) {
    func_8001E57C()->Construct(This);
    This->vtable = func_8004467C();
    This->vtable->Unk15(This, Unk2, Unk3);
}

void func_80044294(ui_sprite_t *This, u8 *arg1, s32 arg2) {
    if (arg2 == 0) {
        This->m_Unk16 = 0x01000000;
        This->m_Unk18_0 = arg1[0x2C] * *(u16 *) (arg1 + 0x2E);
        This->m_Unk18_1 = arg1[0x2D] * *(u16 *) (arg1 + 0x30);
    } else if (arg2 == 1) {
        This->m_Unk16 = 0x02000000;
        This->m_Unk18_0 = 320;
        This->m_Unk18_1 = 240;
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

    This->m_Unk22_0 = (s16) This->m_Unk18_0 / 2;
    This->m_Unk22_1 = (s16) This->m_Unk18_1 / 2;
}

void func_80044380(ui_sprite_t *This, s32 arg1, u8 *arg2) {
    s32 num = *(s16 *) (arg2 + 8);
    s32 den = *(s16 *) (arg2 + 10);

    s32 val = ((num / den) << 12) + (((num % den) << 12) / den);

    if (arg1 != 0) {
        This->m_Unk24 = val;
    } else {
        This->m_Unk24 += val;
    }
}

INCLUDE_ASM("asm/nonmatchings/menu/ui_sprite", func_8004441C);
// Best attempt, 140/140 with two instructions swapped (lh then sll vs sll then lh).
// void func_8004441C(ui_sprite_t *This, s32 arg1, u8 *arg2) {
//     s32 neg_x;
//     s32 neg_y;
//     s32 ratio_x;
//     s32 ratio_y;
//     s32 num_x;
//     s32 den_x;
//     s32 num_y;
//     s32 den_y;
//     s32 old;
//     s32 sum;
//     s32 result;
//     s32 added;
//     s8 pad[0x10];
//
//     neg_x = 0;
//     neg_y = 0;
//     if (*(s16 *)arg2 < 0 || *(s16 *)(arg2 + 2) < 0) {
//         neg_x = 1;
//     }
//     if (*(s16 *)(arg2 + 4) < 0 || *(s16 *)(arg2 + 6) < 0) {
//         neg_y = 1;
//     }
//
//     den_x = *(s16 *)(arg2 + 2);
//     if (den_x != 0) {
//         num_x = *(s16 *)arg2;
//         ratio_x = ((num_x / den_x) << 12) + (((num_x % den_x) << 12) / den_x);
//     }
//     den_y = *(s16 *)(arg2 + 6);
//     if (den_y != 0) {
//         num_y = *(s16 *)(arg2 + 4);
//         ratio_y = ((num_y / den_y) << 12) + (((num_y % den_y) << 12) / den_y);
//     }
//
//     if (arg1 != 0) {
//         if (*(s16 *)(arg2 + 2) == 0) {
//             This->m_Unk23_0 = 0x1000;
//         } else {
//             result = (s16)ratio_x;
//             if (result >= 30001) {
//                 result = 30000;
//             }
//             This->m_Unk23_0 = result;
//         }
//         if (*(s16 *)(arg2 + 6) == 0) {
//             added = 0x1000;
//             This->m_Unk23_1 = added;
//         } else {
//             result = (s16)ratio_y;
//             if (result >= 30001) {
//                 result = 30000;
//             }
//             This->m_Unk23_1 = result;
//         }
//     } else {
//         old = This->m_Unk23_0;
//         sum = old + ratio_x - ratio_x;
//         old = old + (s16)ratio_x;
//         old = old < 30001;
//         if (old == 0) {
//             added = 1;
//             if (neg_x == 0) {
//                 added = 30000;
//             }
//         } else {
//             added = ratio_x + sum;
//         }
//         This->m_Unk23_0 = added;
//         old = This->m_Unk23_1;
//         sum = old + ratio_y - ratio_y;
//         old = old + (s16)ratio_y;
//         old = old < 30001;
//         if (old == 0) {
//             added = 1;
//             if (neg_y == 0) {
//                 added = 30000;
//             }
//         } else {
//             added = ratio_y + sum;
//         }
//         This->m_Unk23_1 = added;
//     }
// }
//
void func_8004464C(ui_sprite_t *This, s32 Unk1, s8 *Data) {
    if (Unk1) {
        __builtin_memcpy(This->m_Unk20, Data, 3);
    }
}

void func_80044674(void) {
}

ui_sprite_vtable_t *func_8004467C(void) {
    return &D_8006F2C4;
}
