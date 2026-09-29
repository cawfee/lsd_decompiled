#include "common.h"

extern s32 GsCLIP3near;
extern s32 GsOUT_PACKET_P;

void func_8003FB0C(s32 arg0) {
    GsCLIP3near = arg0;
}

#if 0
/* Best match: 50/51 insns, identical copy/store shape, but GCC 2.6.3 allocates
 * m to $t0 and the D_8008E98C address to $a1 (saving $a1 in $t1); the target
 * keeps m in $t1 and materializes D_8008E98C into $t0, leaving $a1 live.  Tried
 * struct copy, __builtin_memcpy, s32*/s16* forms, an element loop, a source
 * local, a destination local, and register locals: all use $a1 for the source
 * address and save $a1.  The memcpy form with s16 types emits lwl/lwr, so the
 * 8-word struct copy is required. */
extern s32 D_8008E98C[8];
typedef struct { s32 w[8]; } mat32_t;

void Gssub_make_matrix(s16 *m, s32 a1, s32 a2, s32 mode) {
    *(mat32_t *)m = *(mat32_t *)D_8008E98C;
    switch ((u8)mode) {
    case 0x58:
    case 0x78:
        m[4] = a2;
        m[8] = a2;
        m[5] = -a1;
        m[7] = a1;
        break;
    case 0x59:
    case 0x79:
        m[0] = a2;
        m[8] = a2;
        m[2] = a1;
        m[6] = -a1;
        break;
    case 0x5A:
    case 0x7A:
        m[0] = a2;
        m[4] = a2;
        m[1] = -a1;
        m[3] = a1;
        break;
    }
}
#endif

INCLUDE_ASM("asm/nonmatchings/3030C", Gssub_make_matrix);

void func_8003FBE4(s32 arg0) {
    GsOUT_PACKET_P = arg0;
}
