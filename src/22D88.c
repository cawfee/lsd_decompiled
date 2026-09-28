#include "common.h"

INCLUDE_ASM("asm/nonmatchings/22D88", func_80032588);

INCLUDE_ASM("asm/nonmatchings/22D88", func_80032708);

void func_80032708(int);

void func_80032998(void) {
    func_80032708(1);
}

void func_800329B8(void) {
    func_80032708(0);
}

extern s32 D_8006DC8C;
extern s32 D_8006DC90;
extern s32 D_8006DC94;
extern s32 D_8006DC9C;
extern s32 D_8006DCA8;
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void VSyncCallback(s32);
void InterruptCallback(s32, s32);

void func_800329D8(void) {
    s32 var_a0;
    s32 var_a1;

    if (D_8006DCA8 == 0) {
        D_8006DC94 = 0;
        EnterCriticalSection();
        if (D_8006DC8C != 0) {
            VSyncCallback(0);
            D_8006DC8C = 0;
        } else {
            var_a0 = D_8006DC90;
            if (var_a0 != -1) {
                if (var_a0 == 0) {
                    var_a1 = D_8006DC9C;
                    var_a0 = 0;
                    InterruptCallback(var_a0, var_a1);
                } else {
                    var_a1 = 0;
                    InterruptCallback(var_a0, var_a1);
                }
                D_8006DC90 = -1;
            }
        }
        ExitCriticalSection();
    }
}

void SpuQuit(void);

void func_80032A7C(void) {
    SpuQuit();
}

extern s32 D_8006DCA0;
void SsSeqCalledTbyT(void);

void func_80032A9C(void) {
    void (*fn)(void);

    fn = (void (*)(void))D_8006DC9C;
    if (fn != 0) {
        fn();
    }
    SsSeqCalledTbyT();
}

void func_80032AD0(void) {
    if (D_8006DCA0 == 0) {
        D_8006DCA0 = 1;
    } else {
        D_8006DCA0 = 0;
        SsSeqCalledTbyT();
    }
}

INCLUDE_ASM("asm/nonmatchings/22D88", func_80032B18);

INCLUDE_ASM("asm/nonmatchings/22D88", func_80032BB8);

INCLUDE_ASM("asm/nonmatchings/22D88", func_80032BF0);

INCLUDE_ASM("asm/nonmatchings/22D88", func_80032C28);

INCLUDE_ASM("asm/nonmatchings/22D88", func_80032C60);
