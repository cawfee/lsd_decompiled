#include <common.h>
#include <psx/memory.h>

u8 *bcopy(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 var_a2;
    u8 temp_v0;
    u8* temp_v1;
    u8* var_a0;
    u8* var_a1;
    u8* var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    var_v0 = NULL;
    if (var_a0 != NULL) {
        temp_v1 = var_a0;
        if (var_a2 > 0) {
            do {
                temp_v0 = *var_a0;
                var_a0 += 1;
                var_a2 -= 1;
                *var_a1 = temp_v0;
                var_a1 += 1;
            } while (var_a2 > 0);
        }
        var_v0 = temp_v1;
    }
    return var_v0;
}

s8 *bzero(s8 *arg0, s32 arg1) {
    s32 var_a1;
    s8* var_a0;
    s8* var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v0 = NULL;
    if ((var_a0 != NULL) && (var_a1 > 0)) {
        var_v0 = var_a0;
        do {
            *var_a0 = 0;
            var_a1 -= 1;
            var_a0 += 1;
        } while (var_a1 > 0);
    }
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/psx/memory", memcmp);
