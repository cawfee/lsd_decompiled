#include "common.h"

void *func_80056FE4() {
    void *allocated = (void *) memory_allocate_mem(0x58);

    if (allocated) {
        void *vtable = func_80057C84();
        if ((*((s32(**)(void *)) vtable + 2))(allocated)) {
            return allocated;
        }
        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057044);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800570B4);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057130);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800571A8);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800571E8);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800571F8);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057320);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057384);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800573A8);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800573CC);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057444);

INCLUDE_ASM("asm/nonmatchings/477E4", func_8005748C);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800574C4);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800574FC);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057534);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800575B0);

INCLUDE_ASM("asm/nonmatchings/477E4", func_800575E0);

void func_80057610(void) {
}

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057618);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057668);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057784);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057954);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057A18);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057B54);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057B90);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057C14);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057C6C);

void func_80057C74(void) {
}

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057C7C);

INCLUDE_ASM("asm/nonmatchings/477E4", func_80057C84);
