#include "common.h"

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C508);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C5E8);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C650);

void func_8005BF68(s32);

void set_teleports_enabled(s32 arg0) {
    s32 enable = 0;

    if (arg0 == 0xB || arg0 == 3) {
        enable = 1;
    }
    func_8005BF68(enable);
}

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C714);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C76C);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C7D4);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C8AC);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C930);

s32 func_8005C9A4(s32 arg0, s8 *arg1) {
    s8 v = arg1[2];
    s32 ret = 1;

    if (v != 0) {
        arg0 = arg0 % 2 + 1;
        ret = v != arg0;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C9DC);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CAB4);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CBC8);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CD58);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CDA8);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CDF8);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CF34);
