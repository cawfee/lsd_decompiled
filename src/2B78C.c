#include "2B78C.h"

#include "game_flow.h"

// Unsure how this class is structured

// static bool g_CD_INIT = false;

extern class_2B78C_vtable_t **D_8006E4F0;

INCLUDE_ASM("asm/nonmatchings/2B78C", func_8003AF8C);

void nullsub25(void) {
}

INCLUDE_ASM("asm/nonmatchings/2B78C", func_8003B02C);

void game_flow_init_graphics(game_flow_t *This, gs_helper_t *GsHelper, class_16634_t *Cls16634) {
    if (!This->m_IsInit) {
        func_80020C68(GsHelper);
        GsHelper->vtable->InitGS(GsHelper, &This->unk1, This->unk5);
        func_80032368();
        GsInit3D();

        This->m_GraphicsCtx = memory_allocate_mem(0x14);
        This->m_GraphicsCtx->gs_helper = GsHelper;
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
        This->vtable->DisplayLogoSequence(This);

        while (1) {
            // Play the game movie
            This->vtable->PlayIntroMovie(This);

            do {
                while (1) {
                    // Handle main menu actions
                    status = This->vtable->ExecMainMenu(This);

                    if (status != 1) {
                        break;
                    }

                    // Debug left over? Empty function
                    This->vtable->Menu_Unused(This);
                }

                // Play the game itself
                if (status == 2) {
                    // Run the dream
                    if (This->vtable->ExecDreamSession(This)) {
                        // Will play the ending movie if returns true
                        This->vtable->PlayEndingMovie(This);
                    }
                }
            } while (status);
        }
    }
}

class_2B78C_vtable_t *func_8003B20C(void) {
    return &D_8006E4F0;
}
