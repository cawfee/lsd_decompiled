#include "common.h"

extern s16 D_8008E84C;

void SpuVmDamperOff(void) {
    D_8008E84C = 0;
}

INCLUDE_ASM("asm/nonmatchings/psyq/spu/SpuVmDamperOff", func_80036528);
