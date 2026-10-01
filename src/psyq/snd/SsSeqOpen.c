#include "common.h"

INCLUDE_ASM("asm/nonmatchings/psyq/snd/SsSeqOpen", _SsInitSoundSeq);

INCLUDE_ASM("asm/nonmatchings/psyq/snd/SsSeqOpen", SsSeqOpen);

/*
 * Near match (semantics likely exact, 50/51 insns). Blocker: the target emits
 * `ori t1,zero,1; sllv v0,t1,v1; and v0,v0,a3` for the free-slot test, but
 * gcc 2.6.3 strength-reduces `flags & (1 << i)` to `srav v0,a3,v1; andi v0,1`
 * (one insn shorter). The rest (printf guard, |= 1<<slot, _SsInitSoundSeq call
 * and -1 check) matches. Note snd_openflag/D_80011054 are absolute (G0) here.
 *
 * s32 printf(const char *, ...);
 * s16 _SsInitSoundSeq(s16, s16, u8 *);
 * extern s32 snd_openflag;
 * extern u8 D_80011054[];
 *
 * s16 SsSeqOpen(u8 *addr, s16 vabid) {
 *     s32 flags = snd_openflag;
 *     s32 i;
 *     u8 found;
 *     s16 slot;
 *
 *     if (flags == -1) {
 *         printf(D_80011054);
 *         return -1;
 *     }
 *     i = 0;
 *     found = 0;
 *     while (found == 0) {
 *         if ((flags & (1 << i)) == 0) {
 *             slot = i;
 *             found = 1;
 *         }
 *         i++;
 *     }
 *     snd_openflag |= (1 << slot);
 *     if (_SsInitSoundSeq(slot, vabid, addr) == -1) {
 *         return -1;
 *     }
 *     return slot;
 * }
 */
