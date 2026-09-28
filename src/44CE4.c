#include "common.h"

INCLUDE_ASM("asm/nonmatchings/44CE4", func_800544E4);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054558);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_800545FC);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054660);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054714);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054758);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054850);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_800549A8);

void func_80054B1C(u8 *arg0, u8 *arg1, s32 arg2) {
    arg0[0] = arg1[0] - arg2;
    arg0[1] = arg1[1] - arg2;
    arg0[2] = arg1[2] + arg2;
}

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054B50);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054B84);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054C74);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054CFC);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054D30);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054DA4);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054F30);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054FD8);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_8005511C);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055258);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055410);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_8005556C);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055620);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_800557DC);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_8005582C);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055874);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_800558F0);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055A24);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055A88);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055B10);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055B6C);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055BC8);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055CA8);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055DB4);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055E94);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055EF0);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055F74);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055FE8);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80056054);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_800560E4);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80056194);

s32 func_8005627C(void);

void func_80056238(void *arg0, void *arg1) {
    s32 *p = (s32 *)arg1;

    p[4] = func_8005627C();
    if (p[1] == 0) {
        p[7] = 0x18;
        p[8] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/44CE4", func_8005627C);

extern s32 D_8008AC80;

s32 func_8005630C(void) {
    return (D_8008AC80 & 1) ^ 1;
}
