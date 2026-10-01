#include "common.h"

INCLUDE_ASM("asm/nonmatchings/psyq/snd/22D88", func_80032588);

INCLUDE_ASM("asm/nonmatchings/psyq/snd/22D88", func_80032708);

void func_80032708(int);

void func_80032998(void) {
    func_80032708(1);
}

void func_800329B8(void) {
    func_80032708(0);
}

/* Non-small .data object immediately before the D_8006DC8C cluster. The
   D_8006DC6C + offset forms below are equivalent addresses that keep GCC
   emitting absolute (non-gp) accesses under -G8 instead of CSE-ing a base. */
extern u8 D_8006DC6C[];
extern s32 D_8006DC8C[];
extern s32 D_8006DC90[];
extern s32 D_8006DC94[];
extern s32 D_8006DC9C[];
extern s32 D_8006DCA8[];
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void VSyncCallback(s32);
void InterruptCallback(s32, s32);

void func_800329D8(void) {
    s32 var_a0;
    s32 var_a1;

    if (D_8006DCA8[0] == 0) {
        D_8006DC94[0] = 0;
        EnterCriticalSection();
        if (*(s32 *) ((u8 *) D_8006DC6C + 0x20) != 0) {
            VSyncCallback(0);
            D_8006DC8C[0] = 0;
        } else {
            var_a0 = D_8006DC90[0];
            if (var_a0 != -1) {
                if (var_a0 == 0) {
                    var_a1 = D_8006DC9C[0];
                    var_a0 = 0;
                    InterruptCallback(var_a0, var_a1);
                } else {
                    var_a1 = 0;
                    InterruptCallback(var_a0, var_a1);
                }
                *(s32 *) ((u8 *) D_8006DC6C + 0x24) = -1;
            }
        }
        ExitCriticalSection();
    }
}

void SpuQuit(void);

void func_80032A7C(void) {
    SpuQuit();
}

extern s32 D_8006DCA0[];
void SsSeqCalledTbyT(void);

void func_80032A9C(void) {
    void (*fn)(void);

    fn = (void (*)(void)) D_8006DC9C[0];
    if (fn != 0) {
        fn();
    }
    SsSeqCalledTbyT();
}

void func_80032AD0(void) {
    if (*(s32 *) ((u8 *) D_8006DC6C + 0x34) == 0) {
        *(s32 *) ((u8 *) D_8006DC8C + 0x14) = 1;
    } else {
        D_8006DCA0[0] = 0;
        SsSeqCalledTbyT();
    }
}

extern s32 D_8006DCB0[];

s32 func_80032B18(s32 arg0, s16 arg1, s32 arg2) {
    s32 idx = arg0 & 0xFFFF;
    s32 base;
    s16 flags = 0x48;

    if (idx >= 3) {
        return 0;
    }
    base = D_8006DCB0[0];
    *(volatile s16 *) ((u8 *) (idx * 0x10 + base) + 4) = 0;
    *(volatile s16 *) ((u8 *) (idx * 0x10 + base) + 8) = arg1;
    if ((u32) idx < 2) {
        if (arg2 & 0x10) {
            flags = 0x49;
        }
        if (!(arg2 & 1)) {
            flags |= 0x100;
        }
    } else if (idx == 2) {
        if (!(arg2 & 1)) {
            flags = 0x248;
        }
    }
    if (arg2 & 0x1000) {
        flags |= 0x10;
    }
    *(s16 *) ((u8 *) (idx * 0x10 + *(s32 *) ((u8 *) D_8006DC6C + 0x44)) + 4) = flags;
    return 1;
}

u16 func_80032BB8(s32 arg0) {
    if ((arg0 & 0xFFFF) >= 3) {
        return 0;
    }
    return *(volatile u16 *) ((arg0 & 0xFFFF) * 0x10 + D_8006DCB0[0]);
}

extern s32 *D_8006DCAC[];
extern s32 D_8006DCB4[];

s32 func_80032BF0(s32 arg0) {
    s32 idx = arg0 & 0xFFFF;

    *(volatile s32 *) &D_8006DCAC[0][1] |= D_8006DCB4[idx];
    return idx < 3;
}

s32 func_80032C28(s32 arg0) {
    s32 idx = arg0 & 0xFFFF;

    D_8006DCAC[0][1] &= ~D_8006DCB4[idx];
    return 1;
}

s32 func_80032C60(s32 arg0) {
    if ((arg0 & 0xFFFF) >= 3) {
        return 0;
    }
    *(volatile u16 *) ((arg0 & 0xFFFF) * 0x10 + D_8006DCB0[0]) = 0;
    return 1;
}
