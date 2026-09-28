#include "common.h"

void func_80034138(s16, s16);

extern u8 *ss_score[];
s32 _SsReadDeltaValue(s16, s16);

void func_8003410C(s16 arg0, s16 arg1) {
    func_80034138(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/2490C", func_80034138);

INCLUDE_ASM("asm/nonmatchings/2490C", func_8003424C);

INCLUDE_ASM("asm/nonmatchings/2490C", func_800344FC);

void func_80034614(s16 arg0, s16 arg1, s8 arg2) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;
    u8 *p = chan + chan[0x12];

    p[0x2C] = arg2;
    *(s32 *)(chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/2490C", func_80034690);

INCLUDE_ASM("asm/nonmatchings/2490C", func_800349B0);

INCLUDE_ASM("asm/nonmatchings/2490C", func_80034AEC);

INCLUDE_ASM("asm/nonmatchings/2490C", func_80034C28);

INCLUDE_ASM("asm/nonmatchings/2490C", func_80034D90);

INCLUDE_ASM("asm/nonmatchings/2490C", func_80034E5C);

INCLUDE_ASM("asm/nonmatchings/2490C", func_80034F90);

void func_800350D8(s16 arg0, s16 arg1, s8 arg2) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;

    chan[0x13] = arg2;
    chan[0x29] = chan[0x29] + 1;
    *(s32 *)(chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}

void func_80035154(s16 arg0, s16 arg1, s8 arg2) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;

    chan[0x14] = arg2;
    chan[0x29] = chan[0x29] + 1;
    *(s32 *)(chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/2490C", func_800351D0);

INCLUDE_ASM("asm/nonmatchings/2490C", func_800357B0);

INCLUDE_ASM("asm/nonmatchings/2490C", func_80035A7C);

INCLUDE_ASM("asm/nonmatchings/2490C", func_80035B2C);

INCLUDE_ASM("asm/nonmatchings/2490C", _SsReadDeltaValue);
