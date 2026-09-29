#include "common.h"

extern s16 D_8008E84C;

void SpuVmDamperOn(void) {
    D_8008E84C = 2;
}
