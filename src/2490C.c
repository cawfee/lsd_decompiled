#include "common.h"

void func_80034138(s16, s16);

extern u8 *ss_score[];
s32 _SsReadDeltaValue(s16, s16);

void func_8003410C(s16 arg0, s16 arg1) {
    func_80034138(arg0, arg1);
}

void SsUtReverbOff(void);
void SpuVmDamperOff(void);

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

#if 0
/* Best match: 79/79 insns with identical structure; only GCC 2.6.3 register
 * allocation differs.  Target saves arg0 raw in $a3 and computes the ss_score
 * index as `sll a0,a3,16 / sra a0,a0,14` (fused s16->s32 *4), and tests the
 * count with `blez`; gcc materializes the sign-extended arg0 in $a3, indexes
 * with `sra/a3,16 / sll a0,a3,2`, and emits `beqz`.  Tried 4th-arg types
 * s16/s32/u16/u8, explicit (s16)/(s32) casts on the index and the arg, an
 * s32 index local, a tbl local, and an s16 arg copy: all keep the sign-extended
 * form in $a3. */
void func_800349B0(s16 arg0, s16 arg1, s8 arg2) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;
    u8 *p = chan + chan[0x12];
    u8 prog[0x10];
    u8 vag[0x28];
    s32 i;

    SsUtGetProgAtr(*(s16 *)(chan + 0x4C), p[0x2C], prog, arg0);
    i = 0;
    if ((s32)prog[0] > 0) {
        do {
            SsUtGetVagAtr(*(s16 *)(chan + 0x4C), p[0x2C], (s16)i, vag);
            vag[8] = arg2;
            SsUtSetVagAtr(*(s16 *)(chan + 0x4C), p[0x2C], (s16)i, vag);
            i++;
        } while (i < (s32)prog[0]);
    }
    *(s32 *)(chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}
#endif

INCLUDE_ASM("asm/nonmatchings/2490C", func_800349B0);

INCLUDE_ASM("asm/nonmatchings/2490C", func_80034AEC);

INCLUDE_ASM("asm/nonmatchings/2490C", func_80034C28);

void func_80034D90(s16 arg0, s16 arg1) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;

    SsUtReverbOff();
    SpuVmDamperOff();
    *(u8 *)(chan + chan[0x12] + 0x2C) = chan[0x12];
    chan[0x13] = 0;
    chan[0x14] = 0;
    *(s16 *)(chan + chan[0x12] * 2 + 0x4E) = 0x7F;
    *(u8 *)(chan + chan[0x12] + 0x17) = 0x40;
    *(s32 *)(chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}

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
// Best attempt: 44/44 insns present; every memory access and call operand matches.
// First difference is scheduling: target issues `sll v0,s2,2` (ss_score[arg0]
// index) right after sign-extending arg0 and places `sll a0,s1,8` (call arg 0)
// after the ss_score load (`lw v0,0(at)`); GCC 2.6.3 hoists `sll a0,s1,8` up to
// just after arg1's sign-extension and defers `sll v0,s2,2`.
// Tried: inline `(arg1 << 8) | arg0`, `arg0 | (arg1 << 8)`, explicit idx/val
// locals for the 3rd/4th call args, and a separate `u8 *base = ss_score[arg0]`
// local. None move the first difference.
// void func_80035A7C(s16 arg0, s16 arg1) {
//     u8 *chan = ss_score[arg0] + arg1 * 0xAC;
//     u8 *p = *(u8 **)(chan + 4);
//     s32 field4C = *(s16 *)(chan + 0x4C);
//     *(u8 **)(chan + 4) = p + 1;
//     func_8002F610((arg1 << 8) | arg0, field4C, chan[chan[0x12] + 0x2C], *p);
//     *(s32 *)(chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
// }

INCLUDE_ASM("asm/nonmatchings/2490C", func_80035B2C);

INCLUDE_ASM("asm/nonmatchings/2490C", _SsReadDeltaValue);
// Best attempt: 48/47 insns; one extra `move v0,a1`. Target keeps the channel
// pointer in $a1 and `scaled` in $v0; GCC 2.6.3 allocates the channel pointer to
// $a2, forcing `scaled` into $a1 and a final `move v0,a1` before the return.
// Tried: channel-first/p-first declaration order, `off = arg1*0xAC` local,
// two-step base local, `arg1*0xAC + ss_score[arg0]` operand order, and splitting
// `(scaled+val)*2` into two statements. All keep chan in $a2.
// s32 _SsReadDeltaValue(s16 arg0, s16 arg1) {
//     u8 *chan = ss_score[arg0] + arg1 * 0xAC;
//     u8 *p = *(u8 **)(chan + 4);
//     s32 val;
//     s32 c;
//     s32 scaled;
//     *(u8 **)(chan + 4) = p + 1;
//     val = *p;
//     if (val == 0) {
//         return 0;
//     }
//     scaled = val * 4;
//     if (val & 0x80) {
//         val &= 0x7F;
//         do {
//             p = *(u8 **)(chan + 4);
//             *(u8 **)(chan + 4) = p + 1;
//             c = *p;
//             val = (val << 7) + (c & 0x7F);
//         } while (c & 0x80);
//         scaled = val * 4;
//     }
//     scaled = (scaled + val) * 2;
//     *(s32 *)(chan + 0x80) += scaled;
//     return scaled;
// }
