#include "common.h"

void func_80034138(s16, s16);

extern u8 *ss_score[];
s32 _SsReadDeltaValue(s16, s16);

void func_8003410C(s16 arg0, s16 arg1) {
    func_80034138(arg0, arg1);
}

void SsUtReverbOff(void);
void SpuVmDamperOff(void);

// Best attempt: all target operations present; target frame is 0x38 with the
// chan[0x70]/chan[0x88] loads in v0/v1 and a saved copy of chan[0x70] in $a2,
// while GCC uses a 0x30 frame, reorders the two loads, and coalesces the $a2
// copy into the load.  Tried: 2-arg vs 3-arg func_8003424C prototype, explicit
// saved-v0 local, load order, and named diff/tmp locals.
// s32 func_80034138(s16 arg0, s16 arg1) {
//     u8 *chan = ss_score[arg0] + arg1 * 0xAC;
//     s16 v0 = *(s16 *)(chan + 0x70);
//     s32 v1 = *(s32 *)(chan + 0x88);
//     s32 a0;
//     s32 a2;
//     s32 s0;
//     s32 result;
//     s16 tmp;
//     a0 = v1 - v0;
//     a2 = v0;
//     if (a0 > 0) {
//         tmp = *(s16 *)(chan + 0x6E);
//         if (tmp > 0) {
//             *(s16 *)(chan + 0x6E) = tmp - 1;
//             return tmp - 1;
//         }
//         if (tmp != 0) {
//             *(s32 *)(chan + 0x88) = a0;
//             return tmp;
//         }
//         result = *(s32 *)(chan + 0x88) - 1;
//         *(s16 *)(chan + 0x6E) = a2;
//         *(s32 *)(chan + 0x88) = result;
//         return result;
//     }
//     if (v0 < v1) {
//         return 1;
//     }
//     s0 = v1;
//     do {
//         do {
//             func_8003424C(arg0, arg1);
//             v1 = *(s32 *)(chan + 0x88);
//         } while (v1 == 0);
//         v0 = *(s16 *)(chan + 0x70);
//         s0 += v1;
//         result = s0 - v0;
//     } while (s0 < v0);
//     *(s32 *)(chan + 0x88) = result;
//     return result;
// }

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_80034138);

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_8003424C);

// Best attempt: all 70 target instructions are present in the same order with the
// same memory accesses, call sites, magic /127 sequence and return paths; only
// GCC 2.6.3 register allocation differs. Target saves raw arg0 in $t0 at entry
// (so a0 is free for the ss_score index), keeps raw arg1 in $a1, and saves raw
// arg2 into $a3 inside the flag-branch delay slot; GCC keeps arg0 in a0/$t1/$t2,
// copies arg1 to $t0/$t1, and copies arg2 to $t1. Tried: arg2/arg3 as u8 vs s32,
// named result/flag/val locals, explicit (s16) casts, key hoisted before/after
// the channel load, inline p[0x17] vs local, val computed before/after the flag
// load: none moved arg0 to $t0 with arg1 left in $a1.
// s32 func_800344FC(s16 arg0, s16 arg1, u8 arg2, u8 arg3) {
//     u8 *chan = ss_score[arg0] + arg1 * 0xAC;
//     u8 *p = chan + chan[0x12];
//     s32 val;
//     s32 result;
//     val = (arg3 & 0xFF) * *(s16 *)(chan + chan[0x12] * 2 + 0x4E) / 127;
//     result = *(u16 *)(chan + 0x74);
//     if (*(u16 *)(chan + 0x74) != 0) {
//         if ((arg3 & 0xFF) != 0) {
//             func_8002FAC4((s16)(arg0 | (arg1 << 8)), *(s16 *)(chan + 0x4C), p[0x2C],
//                           arg2, val & 0xFFFF, p[0x17]);
//             result = arg3 & 0xFF;
//             *(s16 *)(chan + 0xA8) = arg3 & 0xFF;
//         } else {
//             return func_800300D0((s16)(arg0 | (arg1 << 8)), *(s16 *)(chan + 0x4C), p[0x2C], arg2);
//         }
//     }
//     return result;
// }

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_800344FC);

void func_80034614(s16 arg0, s16 arg1, s8 arg2) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;
    u8 *p = chan + chan[0x12];

    p[0x2C] = arg2;
    *(s32 *) (chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_80034690);

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

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_800349B0);

// Prototypes used by the commented attempts below (from libsnd.h):
//   void SsUtGetProgAtr(s16, u8, u8 *);
//   void SsUtGetVagAtr(s16, u8, s16, u8 *);
//   void SsUtSetVagAtr(s16, u8, s16, u8 *);
// Best attempt: 77/79 insns match. Target frame 0x70, buffers prog@0x10 /
// vag@0x20 (u8 vag[0x20], not 0x28, to reproduce the frame), and the count is
// tested with `lbu` + `blez` (a `while (i < (s32)prog[0])` loop reproduces the
// blez, unlike `if (prog[0] > 0) do..while` which gives beqz). Only remaining
// diff is GCC 2.6.3 register allocation: target computes p into $s0, copies
// `addu s4,s0,zero` before the loop, and reuses $s0 for the (s16)i index;
// GCC puts p directly in $s4 (no copy). Key: SsUtGetProgAtr takes 3 args
// (short,short,ProgAtr*) per libsnd.h -- a 4th arg forces a3 and a larger frame.
// void func_80034AEC(s16 arg0, s16 arg1, s8 arg2) {
//     u8 *chan = ss_score[arg0] + arg1 * 0xAC;
//     u8 *p = chan + chan[0x12];
//     u8 prog[0x10];
//     u8 vag[0x20];
//     s32 i;
//
//     SsUtGetProgAtr(*(s16 *)(chan + 0x4C), p[0x2C], prog);
//     i = 0;
//     while (i < (s32)prog[0]) {
//         SsUtGetVagAtr(*(s16 *)(chan + 0x4C), p[0x2C], (s16)i, vag);
//         vag[0xB] = arg2;
//         SsUtSetVagAtr(*(s16 *)(chan + 0x4C), p[0x2C], (s16)i, vag);
//         i++;
//     }
//     *(s32 *)(chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
// }

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_80034AEC);

// Best attempt: structure/loop/frame (0x70) match; target keeps arg2 in $s4
// (saved first) and p in $s0; GCC assigns arg2 to $s0 and p to $s3. Same
// allocator tie-break as func_80034AEC. Tried arg2 types s32/s8/u8/u32/s16.
// void func_80034C28(s16 arg0, s16 arg1, s32 arg2) {
//     u8 *chan = ss_score[arg0] + arg1 * 0xAC;
//     u8 *p = chan + chan[0x12];
//     u8 prog[0x10];
//     u8 vag[0x20];
//     s32 i;
//
//     SsUtGetProgAtr(*(s16 *)(chan + 0x4C), p[0x2C], prog);
//     i = 0;
//     while (i < (s32)prog[0]) {
//         SsUtGetVagAtr(*(s16 *)(chan + 0x4C), p[0x2C], (s16)i, vag);
//         if ((arg2 & 0xFF) < 0x40) {
//             vag[1] = 2;
//         } else if (((arg2 + 0xC0) & 0xFF) < 0x40) {
//             vag[1] = 0;
//         }
//         SsUtSetVagAtr(*(s16 *)(chan + 0x4C), p[0x2C], (s16)i, vag);
//         i++;
//     }
//     *(s32 *)(chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
// }

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_80034C28);

void func_80034D90(s16 arg0, s16 arg1) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;

    SsUtReverbOff();
    SpuVmDamperOff();
    *(u8 *) (chan + chan[0x12] + 0x2C) = chan[0x12];
    chan[0x13] = 0;
    chan[0x14] = 0;
    *(s16 *) (chan + chan[0x12] * 2 + 0x4E) = 0x7F;
    *(u8 *) (chan + chan[0x12] + 0x17) = 0x40;
    *(s32 *) (chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}

extern void (*D_80090368[][16])(s16, s16, u8);

void func_80034E5C(s16 arg0, s16 arg1, s8 arg2) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;
    void (*handler)(s16, s16, u8);

    if (chan[0x27] == 1 && chan[0x10] == 0) {
        chan[0x28] = arg2;
        chan[0x10] = 1;
    } else if (chan[0x16] != 0x1E && chan[0x16] != 0x14) {
        chan[0x15] = arg2;
        chan[0x2A] = chan[0x2A] + 1;
    }
    if (chan[0x16] == 0x28) {
        handler = D_80090368[arg0][arg1];
        if (handler != 0) {
            handler(arg0, arg1, arg2);
        }
    }
    *(s32 *) (chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}

void func_80034F90(s16 arg0, s16 arg1, u8 arg2) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;

    switch (arg2) {
        case 0x14:
            chan[0x16] = arg2;
            chan[0x27] = 1;
            *(s32 *) (chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
            *(s32 *) (chan + 0xC) = *(s32 *) (chan + 4);
            break;
        case 0x1E:
            chan[0x16] = arg2;
            if (chan[0x28] == 0) {
                chan[0x10] = 0;
                *(s32 *) (chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
            } else if (chan[0x28] < 0x7F) {
                chan[0x28] = --chan[0x28];
                *(s32 *) (chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
                if (chan[0x28] != 0) {
                    *(s32 *) (chan + 4) = *(s32 *) (chan + 0xC);
                } else {
                    chan[0x10] = 0;
                }
            } else {
                _SsReadDeltaValue(arg0, arg1);
                *(s32 *) (chan + 0x88) = 0;
                *(s32 *) (chan + 4) = *(s32 *) (chan + 0xC);
            }
            break;
        default:
            chan[0x16] = arg2;
            chan[0x2A] = chan[0x2A] + 1;
            *(s32 *) (chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
            break;
    }
}

void func_800350D8(s16 arg0, s16 arg1, s8 arg2) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;

    chan[0x13] = arg2;
    chan[0x29] = chan[0x29] + 1;
    *(s32 *) (chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}

void func_80035154(s16 arg0, s16 arg1, s8 arg2) {
    u8 *chan = ss_score[arg0] + arg1 * 0xAC;

    chan[0x14] = arg2;
    chan[0x29] = chan[0x29] + 1;
    *(s32 *) (chan + 0x88) = _SsReadDeltaValue(arg0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_800351D0);

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_800357B0);

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_80035A7C);
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

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", func_80035B2C);

INCLUDE_ASM("asm/nonmatchings/psyq/sound/_SsReadDeltaValue", _SsReadDeltaValue);
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
