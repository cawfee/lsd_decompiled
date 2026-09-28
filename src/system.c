#include "system.h"

#include "game_flow.h"
#include "base_class.h"

static s32 g_CD_INIT = 0;
extern s32 D_8008A8E0[];


void system_construct(void *, s32);
void nullsub25(void *);
void func_8003B02C(void *, s32 *, s32);
void game_flow_init_graphics(void *, display_t *, pad_t *, u32);
void func_8003B108(void *);
void game_flow_execute_phases(void *);

system_vtable_t g_SYSTEM_VTABLE = {
    0x60,
    base_class_destructor,
    system_construct,
    nullsub25,
    base_class_attach,
    base_class_detach,
    base_class_detach_all,
    base_class_iter_children,
    base_class_add_parent,
    base_class_remove_parent,
    base_class_clear_parents,
    base_class_iter_parents,
    base_class_notify,
    base_class_nop,
    base_class_on_notify,
    NULL,
    func_8003B02C,
    game_flow_init_graphics,
    func_8003B108,
    game_flow_execute_phases,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

void system_construct(system_t *This, s32 Unk) {
    base_class_get_vtable()->Construct(This);
    This->vtable = system_get_vtable();

    if (!g_CD_INIT) {
        CdInit();
        g_CD_INIT = 1;
    }

    This->m_Unk5 = 0;
    file_driver_set_class(Unk);
    This->vtable->Unk15(This, &D_8008A8E0, 0);
}

void nullsub25(void *) {
}

void func_8003B02C(system_t *This, const s32 *src, s32 val) {
    __builtin_memcpy(&This->m_Unk2, src, 8);
    This->m_Unk4 = val;
}

void game_flow_init_graphics(game_flow_t *This, display_t *Display, pad_t *Pad) {
    if (!This->m_IsInit) {
        set_display(Display);
        Display->vtable->display_init_gs(Display, &This->m_ScreenSize, This->m_VarMode);
        func_80032368();
        GsInit3D();

        This->m_GraphicsCtx = memory_allocate_mem(0x14);
        This->m_GraphicsCtx->display = Display;
        This->m_GraphicsCtx->cls_16634 = Pad;
        This->m_GraphicsCtx->cls_32c00 = NULL;
        This->m_GraphicsCtx->cls_3acc8 = NULL;
        This->m_GraphicsCtx->cls_3da54 = NULL;
        This->m_IsInit = 1;
    }
}

void func_8003B108(void *) {
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

system_vtable_t *system_get_vtable(void) {
    return &g_SYSTEM_VTABLE;
}
