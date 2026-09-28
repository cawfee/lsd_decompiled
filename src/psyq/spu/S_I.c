#include "common.h"

// libspu S_I.OBJ: SPU init / hot-start entry points.
// SpuInit and SpuInitHot are thin wrappers over the internal _SpuInit;
// only _SpuInit (func_8003221C) remains unmatched here.
INCLUDE_ASM("asm/nonmatchings/psyq/spu/S_I", func_8003221C);

void func_8003221C(int);

void SpuInit(void) {
    func_8003221C(0);
}

void SpuInitHot(void) {
    func_8003221C(1);
}
