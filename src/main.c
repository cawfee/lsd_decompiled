#include "common.h"

#include <psx/kernel.h>

#include "pad.h"
#include "game_flow.h"
#include "display.h"
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
    display_t *display;

    SetMem(2);
    manager = memory_create_manager(0x166C00, 0);
    g_MEMORY_MANAGER_MAIN = manager;

    memory_set_manager(manager);
    g_GAME_FLOW = game_flow_create(&g_GAME_CONFIG);

    display = display_create();
    g_GAME_FLOW->vtable->game_flow_init(g_GAME_FLOW, display, pad_create(0, 0));
    g_GAME_FLOW->vtable->game_flow_execute_phases(g_GAME_FLOW);
}

// NOLINTBEGIN
void __main(void) {
}
// NOLINTEND

INCLUDE_ASM("asm/nonmatchings/main", start);
