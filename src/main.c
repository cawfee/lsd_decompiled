#include "common.h"

#include <psx/kernel.h>

#include "16634.h"
#include "game_flow.h"
#include "gs_helper.h"
#include "memory.h"

// data
static game_config_t g_GAME_CONFIG = {
    .unk_flags = 0x13, // 0x23 crashes
    .enable_something = 0,
    .enable_movie = 1,
    .enable_logo = 1,
    .enable_main_menu = 1,
    .enable_unk = 1,
};

// sdata
static void *g_MEMORY_MANAGER_MAIN = NULL;

// sbss
static game_flow_t *g_GAME_FLOW;

void main(int argc, const char **argv) {
    void *manager;
    void *gs_helper;

    SetMem(2);
    manager = memory_create_manager(0x166C00, 0);
    g_MEMORY_MANAGER_MAIN = manager;

    memory_set_manager(manager);
    g_GAME_FLOW = game_flow_create(&g_GAME_CONFIG);

    gs_helper = gs_helper_create();
    g_GAME_FLOW->vtable->GetUnk1(g_GAME_FLOW, gs_helper, func_80025B34(0, 0));
    g_GAME_FLOW->vtable->ExecutePhases(g_GAME_FLOW);
}

// NOLINTBEGIN
void __main(void) {
}
// NOLINTEND

INCLUDE_ASM("asm/nonmatchings/main", start);
