#include "2B78C.h"

#include "game_flow.h"
#include "base_class.h"

// static s32 g_CD_INIT = 0;
// static s32 D_8008A8E0[2] = {0x140, 0xF0};

extern class_2B78C_vtable_t D_8006E4F0;

extern s32 g_CD_INIT;
extern s32 D_8008A8E0[];

void func_8003AF8C(class_2B78C_t *This, s32 Unk) {
    base_class_get_vtable()->Construct(This);
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

void func_8003B02C(class_2B78C_t *This, const s32 *src, s32 val) {
    __builtin_memcpy(&This->m_Unk2, src, 8);
    This->m_Unk4 = val;
}

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
