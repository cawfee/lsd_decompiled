#include "common.h"

#include <psx/kernel.h>

#include "base/base.h"
#include "graphics/display.h"
#include "sys/game_flow.h"
#include "sys/pad.h"

// data
static game_config_t g_GAME_CONFIG = {
    .m_FileDriverClass = LSD_FILE_DRIVER_CD, // 0x23 selects the null driver and crashes
    .m_FrameSyncMode = 0,
    .m_EnableMovie = 1,
    .m_EnableLogo = 1,
    .m_EnableMainMenu = 1,
    .m_UnusedFlag = 1,
};

// sdata
static memory_manager_t *g_MEMORY_MANAGER_MAIN = NULL;

// sbss
static game_flow_t *g_GAME_FLOW;

void main(int argc, const char **argv) {
    memory_manager_t *manager;
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
