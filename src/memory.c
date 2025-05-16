#include "common.h"

static void *g_MEMORY_MANAGER = NULL;
static void *g_PAD = NULL;

INCLUDE_ASM("asm/nonmatchings/memory", memory_create_manager);

void memory_set_manager(void *Manager) {
    g_MEMORY_MANAGER = Manager;
}

void func_80017AA8(void *Buffer) {
    free2(Buffer);
}

INCLUDE_ASM("asm/nonmatchings/memory", memory_setup_manager);

INCLUDE_ASM("asm/nonmatchings/memory", memory_allocate_mem);

INCLUDE_ASM("asm/nonmatchings/memory", memory_free_mem);

void nullsub3(void) {
}
