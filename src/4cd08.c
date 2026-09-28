#include "common.h"
#include "dream_sys.h"

extern dream_sys_t *D_8008AC00;
extern s32 D_8008ABF8;

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

void func_8005C714(s32 arg0) {
    switch (arg0) {
    case 0x4E:
    case 0xB:
    case 0x38:
        func_8005BF68(1);
        break;
    case 0x5D:
        func_8005BF68(1);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C76C);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C7D4);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005C8AC);

s32 func_8005C930(s32 arg0, s32 arg1) {
    s32 var_s0 = arg0;
    s32 var_s1 = D_8008ABF8;

    if (var_s1 == 4 && arg1 == 0x10 &&
        D_8008AC00->vtable->dream_sys__get_dream_color(D_8008AC00) == var_s1) {
        var_s0 += 0x1E;
    }
    return var_s0;
}

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

extern s16 SPECIAL_DAYS[];

s32 func_8005CD58(s32 arg0) {
    s32 temp_s0 = ((s8 *)SPECIAL_DAYS)[0x4A + arg0];

    return temp_s0 == D_8008AC00->vtable->dream_sys__get_dream_color(D_8008AC00);
}

s32 func_8005CDA8(s32 arg0, s32 arg1) {
    s32 base = (arg0 - 1) / 30 + 1;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (base == arg1) {
            return 1;
        }
        arg1 += 3;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CDF8);

INCLUDE_ASM("asm/nonmatchings/4cd08", func_8005CF34);
