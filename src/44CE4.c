#include "common.h"
#include "30CD0.h"

extern u8 D_800872C4[];
extern s32 D_8008730C[];

INCLUDE_ASM("asm/nonmatchings/44CE4", func_800544E4);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054558);

void func_800545FC(u8 *arg0, s8 *arg1) {
    *(void **)(arg0 + 0xC) = (u8 *)&D_800872C4 + arg1[3] * 3;
    *(void **)(arg0 + 0x18) = (u8 *)&D_800872C4 + arg1[2] * 3;
    *(s32 *)(arg0 + 0x1C) = D_8008730C[arg1[1]];
    *(s32 *)(arg0 + 0x14) = arg1[0];
}

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80054660);

extern s32 D_8008AB54;
extern class_30CD0_t *D_8008AC94;

void func_80054714(void) {
    if (D_8008AB54 != 0) {
        D_8008AC94->vtable->Destroy(D_8008AC94);
        D_8008AB54 = 0;
    }
}

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

extern s32 *D_8008AC7C;

void sound_update_entity(s32, s32 *);

s32 func_800557DC(s32 *arg0) {
    u8 *temp_v1;

    sound_update_entity(*D_8008AC7C, (s32 *)arg0 + 5);
    temp_v1 = (u8 *)*arg0;
    temp_v1[6] = -temp_v1[6];
    return 0;
}

void helper_1_update_entity(s32, s32 *);
s32 func_80055874();

s32 func_8005582C(s32 arg0) {
    if (func_80055874() != 0) {
        helper_1_update_entity(*D_8008AC7C, (s32 *)(arg0 + 0x14));
        return 1;
    }

    return 0;
}

extern s32 D_80087474[];

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055874);
// Best attempt: 28/31 insns; everything matches except the final boolean
// materialization. Target keeps a branchy form:
//   slt v0,a1,v0 ; bnez v0,end ; ori v0,1 ; addu v0,0
// GCC 2.6.3 folds `result = dist < table` into a direct `slt v0,...; jr ra`.
// Also fixed: the early negation uses nor/addiu (~diff + 1), not negu.
// Tried: plain result var, if/else, ?:, early returns, separate limit temp,
// phi assignment in both arms, >= vs <, signed/unsigned result; all fold.
// s32 func_80055874(s32 *arg0, s32 *arg1) {
//     s32 diff;
//     s32 temp;
//     s32 dist;
//     s32 result;
//     if (arg1 == NULL) {
//         result = 0;
//     } else {
//         diff = arg0[1] - arg1[0];
//         if (diff < 0) diff = ~diff + 1;
//         temp = arg0[3] - arg1[2];
//         if (temp < 0) dist = diff - temp; else dist = diff + temp;
//         arg0[4] = dist;
//         result = dist < D_80087474[-((s8 *)*arg0)[6]];
//     }
//     return result;
// }

INCLUDE_ASM("asm/nonmatchings/44CE4", func_800558F0);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055A24);

INCLUDE_ASM("asm/nonmatchings/44CE4", func_80055A88);

s32 func_8005627C(void);

void func_80055B10(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] == 0) {
        arg1[7] = 0x18;
        arg1[8] = -2;
        return;
    }
    if (arg1[1] >= 0x401) {
        arg1[1] = -1;
    }
}

void func_80055B6C(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] == 0) {
        arg1[7] = 0xC;
        arg1[8] = 2;
        return;
    }
    if (arg1[1] >= 5) {
        arg1[1] = -1;
    }
}

void func_80055BC8(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] % 20 == 0) {
        arg1[7] = 0x1E;
        arg1[9] = 0x20;
        arg1[8] = 0;
        arg1[10] = 0xA;
    }
    if (arg1[1] % 400 == 0) {
        arg1[12] = 0x1E;
        arg1[13] = 0;
    }
    arg1[17] = 6;
    arg1[19] = 0x20;
    arg1[18] = 0;
    arg1[20] = 0xA;
}

void func_80055CA8(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] % 3 == 0) {
        arg1[7] = 0x1E;
        arg1[8] = 0;
    }
    if (arg1[1] % 5 == 0) {
        arg1[12] = 0x1E;
        arg1[13] = 0;
        arg1[14] = 0x18;
        arg1[15] = 0x18;
    }
    if (arg1[1] % 7 == 0) {
        arg1[7] = 0x1E;
        arg1[8] = 0;
    }
    arg1[17] = 6;
    arg1[18] = 1;
    arg1[19] = 0x2A;
    arg1[20] = 0xA;
}

void func_80055DB4(void *arg0, s32 *arg1) {
    s32 temp;
    s32 v;

    arg1[4] = func_8005627C();
    temp = arg1[1];
    if (temp == 0) {
        arg1[7] = 0x1E;
        arg1[8] = -1;
        return;
    }
    if (temp < 0x32 && (temp / 5) * 5 == temp - 4) {
        arg1[12] = 0x1E;
        arg1[13] = 0;
        v = arg1[14] - arg1[1] * 2;
        arg1[14] = v;
        arg1[15] = v;
        return;
    }
    v = arg1[1];
    if ((u32)(v - 0x65) < 9U) {
        arg1[17] = 0xD;
        arg1[18] = 1;
        return;
    }
    if (v >= 0xC9) {
        arg1[1] = -1;
    }
}

void func_80055E94(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] == 0) {
        arg1[7] = 7;
        arg1[8] = 2;
        return;
    }
    if (arg1[1] >= 0x1B) {
        arg1[1] = -1;
    }
}

void func_80055EF0(void *arg0, s32 *arg1) {
    s32 temp;

    arg1[4] = func_8005627C();
    temp = arg1[1];
    if (temp == 0) {
        arg1[7] = 0x14;
        arg1[8] = 1;
        return;
    }
    if (temp == 3) {
        arg1[8] = 2;
        arg1[9] = 0x18;
        arg1[7] = temp;
        arg1[10] = 0x14;
        return;
    }
    if (temp >= 0x33) {
        arg1[1] = -1;
    }
}

void func_80055F74(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] % 20 == 0) {
        arg1[7] = 9;
        arg1[8] = 0;
        arg1[9] = 0x40;
        arg1[10] = 0x40;
    }
}

void func_80055FE8(void *arg0, s32 *arg1) {
    arg1[4] = func_8005627C();
    if (arg1[1] % 20 == 0) {
        arg1[7] = 9;
        arg1[8] = -2;
    }
}

void func_80056054(void *arg0, s32 *arg1) {
    s32 temp;

    arg1[4] = func_8005627C();
    temp = arg1[1] % 20;
    if (temp == 1) {
        arg1[7] = 9;
        arg1[8] = -2;
        return;
    }
    if (temp == 0x10) {
        arg1[12] = 9;
        arg1[13] = -2;
    }
}

void func_800560E4(void *arg0, s32 *arg1) {
    s32 temp;

    func_80056054();
    temp = arg1[1] % 70;
    if (temp == 0x32) {
        arg1[17] = 0x14;
        arg1[18] = 1;
    } else if ((u32)(temp - 0x36) < 5U) {
        arg1[17] = 0xD;
        arg1[18] = 1;
    } else if (temp == 0x3D) {
        arg1[17] = 9;
        arg1[18] = -1;
    }
}

void func_80056194(void *arg0, s32 *arg1) {
    s32 temp;

    arg1[4] = func_8005627C();
    temp = arg1[1];
    if (temp == 0) {
        arg1[7] = 0x14;
        arg1[8] = -2;
        arg1[12] = 0x14;
        arg1[13] = -2;
        return;
    }
    if (temp == 4) {
        arg1[12] = 0x14;
        arg1[13] = -2;
        return;
    }
    if (temp == 0x14) {
        arg1[7] = 0x10;
        arg1[8] = -2;
        arg1[12] = 0x12;
        arg1[13] = -2;
        return;
    }
    if (temp >= 0xC9) {
        arg1[1] = -1;
    }
}

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
