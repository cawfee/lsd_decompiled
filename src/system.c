#include "system.h"

#include "game_flow.h"
#include "base_class.h"

// static s32 g_CD_INIT = 0;
// static s32 D_8008A8E0[2] = {0x140, 0xF0};

extern system_vtable_t D_8006E4F0;

extern s32 g_CD_INIT;
extern s32 D_8008A8E0[];

void func_8003AF8C(system_t *This, s32 Unk) {
    base_class_get_vtable()->base_class_construct(This);
    This->vtable = func_8003B20C();

    if (!g_CD_INIT) {
        CdInit();
        g_CD_INIT = 1;
    }

    This->m_Unk5 = 0;
    func_80026CFC(Unk);
    This->vtable->Unk15(This, &D_8008A8E0, 0);
}

void nullsub25(void) {
}

void func_8003B02C(system_t *This, const s32 *src, s32 val) {
    __builtin_memcpy(&This->m_Unk2, src, 8);
    This->m_Unk4 = val;
}

void game_flow_init_graphics(game_flow_t *This, display_t *GsHelper, pad_t *Cls16634) {
    if (!This->m_IsInit) {
        set_display(GsHelper);
        GsHelper->vtable->display_init_gs(GsHelper, &This->unk1, This->unk5);
        func_80032368();
        GsInit3D();

        This->m_GraphicsCtx = memory_allocate_mem(0x14);
        This->m_GraphicsCtx->display = GsHelper;
        This->m_GraphicsCtx->cls_16634 = Cls16634;
        This->m_GraphicsCtx->cls_32c00 = NULL;
        This->m_GraphicsCtx->cls_3acc8 = NULL;
        This->m_GraphicsCtx->cls_3da54 = NULL;
        This->m_IsInit = 1;
    }
}

void func_8003B108(void) {
}

// The main game loop
void game_flow_execute_phases(game_flow_t *This) {
    s32 status;

    if (This->m_IsInit) {
        // Show the intro logos
        This->vtable->game_flow_display_logo_sequence(This);

        while (1) {
            // Play the game movie
            This->vtable->game_flow_play_intro_movie(This);

            do {
                while (1) {
                    // Handle main menu actions
                    status = This->vtable->game_flow_execute_main_menu(This);

                    if (status != 1) {
                        break;
                    }

                    // Debug left over? Empty function
                    This->vtable->Menu_Unused(This);
                }

                // Play the game itself
                if (status == 2) {
                    // Run the dream
                    if (This->vtable->game_flow_execute_dream(This)) {
                        // Will play the ending movie if returns true
                        This->vtable->game_flow_play_ending_movie(This);
                    }
                }
            } while (status);
        }
    }
}

system_vtable_t *func_8003B20C(void) {
    return &D_8006E4F0;
}
