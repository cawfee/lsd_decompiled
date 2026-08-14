#include "common.h"

static void *g_MEMORY_MANAGER = NULL;
static void *g_PAD = NULL;

void *malloc2(u32 size);
int printf(char *fmt, ...);
void memory_setup_manager(s32 *arg0);

void *memory_create_manager(u32 arg0, s32 unused) {
    u32 var_s1;
    s32 *temp_s0;

    var_s1 = arg0;
    if (var_s1 < 0x400U) {
        var_s1 = 0x400;
    }
    temp_s0 = (s32 *)malloc2(var_s1 + 0x20);
    if (temp_s0 != NULL) {
        temp_s0[0] = (s32)((u8 *)temp_s0 + 0x1C);
        temp_s0[1] = var_s1;
        memory_setup_manager(temp_s0);
    } else {
        printf("bMemPMgr = %p, poolSize = %ld in BMemPMgrInit\n", 0, var_s1);
    }
    return temp_s0;
}

void memory_set_manager(void *Manager) {
    g_MEMORY_MANAGER = Manager;
}

void func_80017AA8(void *Buffer) {
    free2(Buffer);
}

void memory_setup_manager(s32 *arg0) {
    s32 *var_a1;
    s32 *temp_a0;
    s32 *temp_v0;

    var_a1 = g_MEMORY_MANAGER;
    if (var_a1 == NULL) {
        var_a1 = arg0;
    }
    var_a1[4] = 1;
    temp_a0 = (s32 *)var_a1[0];
    var_a1[2] = (s32)temp_a0;
    var_a1[3] = (s32)temp_a0;
    *temp_a0 = var_a1[1] | 0x40000000;
    ((s32 *)var_a1[2])[1] = 0;
    ((s32 *)var_a1[3])[2] = 0;
    temp_v0 = (s32 *)((s32)temp_a0 + (*temp_a0 & 0x0FFFFFFF));
    temp_v0[-1] = (s32)temp_a0;
    temp_v0[0] = 0x80000000;
}

INCLUDE_ASM("asm/nonmatchings/memory", memory_allocate_mem);


INCLUDE_ASM("asm/nonmatchings/memory", memory_free_mem);

void nullsub3(void) {
}
