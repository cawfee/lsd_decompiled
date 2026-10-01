#include "common.h"

#include <psx/libetc.h>

#include "base/base_class.h"
#include "memory/memory.h"
#include "dream/dream_session.h"
#include "dream/dream_session_path.h"
#include "menu/graph_screen.h"
#include "menu/main_menu.h"
#include "menu/movie_screen.h"
#include "menu/ui_screen.h"
#include "sys/game_flow.h"
#include "sys/system.h"
#include "utils/cd_paths.h"

game_flow_vtable_t g_GAME_FLOW_VTABLE = {
    0x1F60,
    base_class_destructor,
    game_flow_construct,
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
    0,
    game_flow_get_day_rand,
    game_flow_init,
    game_flow_pre_execute,
    game_flow_execute_phases,
    game_flow_display_logo_sequence,
    game_flow_play_intro_movie,
    game_flow_execute_main_menu,
    game_flow_menu_unused,
    game_flow_execute_dream,
    game_flow_play_ending_movie,
};

game_flow_t *game_flow_create(game_config_t *Config) {
    game_flow_t *allocated = memory_allocate_mem(0x2C);

    if (allocated) {
        game_flow_get_vtable()->game_flow_construct(allocated, Config);
        return allocated;
    }

#ifdef NON_MATCHING
    return NULL;
#endif
}

void game_flow_construct(game_flow_t *This, game_config_t *Config) {
    char *tmd_args[4];

    system_get_vtable()->Construct(This, Config->m_FileDriverClass);
    This->vtable = game_flow_get_vtable();
    This->m_Config = Config;

    set_data_folder(get_data_folder());

    tmd_args[0] = NULL;
    tmd_args[1] = "ETC\\DREAME5.TMD";

    This->m_DreamSys = dream_sys_create(tmd_create(&tmd_args), 0, 0);
    This->m_SkipDreamChart = 0;
    This->m_DreamSys->vtable->dream_sys_get_set_flag(This->m_DreamSys, Config->m_UnusedFlag);
    This->vtable->game_flow_get_day_rand(This);
}

s32 game_flow_get_day_rand(void *This) {
    return get_seeded_random(*(s32 *) GET_SCRATCH_ADDR(0) % 365, 0);
}

void game_flow_init(game_flow_t *This, display_t *Display, pad_t *Pad) {
    if (!This->m_IsInit) {
        system_get_vtable()->game_flow_init_graphics(This, Display, Pad, 0);
    }
}

void game_flow_display_logo_sequence(game_flow_t *This) {
    movie_screen_t *player = NULL;
    const char *path = NULL;
    s32 index;
    s32 duration;

    if (This->m_Config->m_EnableLogo) {
        frame_setup(0, 0, 0);
        game_flow_display_logo(This, "ETC\\ASMKLOGO.TIM");

        player = movie_screen_create(0, 0, 0, 0);
        path = get_logo_asmk_path(&index);
        duration = get_movie_duration_maybe(index);

        player->vtable->Play(player, This->m_GraphicsCtx, path, duration, 1);
        player->vtable->Destroy(player);

        game_flow_display_logo(This, "ETC\\OSDLOGO.TIM");
    }
}

void game_flow_display_logo(game_flow_t *This, const char *Path) {
    ui_screen_t *screen = ui_screen_create(0, 0, 0);
    screen->vtable->SetCallback(screen, &game_flow_logo_callback, This);
    screen->vtable->SetIdleTimeout(screen, 0);
    screen->vtable->SetTexture(screen, Path, 0);
    screen->vtable->Run(screen, This->m_GraphicsCtx, 0);
    screen->vtable->Destroy(screen);
}

void game_flow_logo_callback() {
    dream_session_path_advance(0);
}

void game_flow_play_intro_movie(game_flow_t *This) {
    movie_screen_t *player;
    const char *path;
    s32 index;
    s32 duration;

    if (This->m_Config->m_EnableMovie) {
        frame_setup(0, 0, 0);

        player = movie_screen_create(0, 0, 0, 0);
        path = get_random_opening_movie_path(&index, 0);
        duration = get_movie_duration_maybe(index);
        player->vtable->Play(player, This->m_GraphicsCtx, path, duration, 1);
        player->vtable->Destroy(player);
    }
}

s32 game_flow_execute_main_menu(game_flow_t *This) {
    s32 value;

    if (This->m_Config->m_EnableMainMenu) {
        frame_setup(0, 0, 0);

        if (This->m_DreamSys->vtable->get_day_number(This->m_DreamSys, 0) != 1 && !This->m_SkipDreamChart &&
            run_screen(&graph_screen_create, This->m_DreamSys, This->m_GraphicsCtx) == 2) {
            play_special_reel(This);
        }

        while (1) {
            value = run_screen(main_menu_create, This->m_DreamSys, This->m_GraphicsCtx);

            if (value != 2) {
                break;
            }

            run_screen(graph_screen_create, This->m_DreamSys, This->m_GraphicsCtx);
        }

        This->m_SkipDreamChart = 0;
        return 2 * (value == 0);
    }

    // Jump straight to game if main menu is not enabled
    return 2;
}

// Creates a screen object, runs it (vtable +0x44) with runArg, destroys it (vtable +0x04),
// and returns the value the screen's Run returned.
s32 run_screen(game_flow_screen_t *(*create)(s32), s32 createArg, s32 runArg) {
    game_flow_screen_t *screen = create(createArg);
    s32 run_result = screen->vtable->Run(screen, runArg, 0);
    screen->vtable->Destroy(screen);
    return run_result;
}

void play_special_reel(game_flow_t *This) {
    movie_screen_t *player;
    const char *path;
    u32 reel_info[3]; // [2] = total playback length in frames (written by get_special_reel_movie_path)

    if (This->m_Config->m_EnableMovie) {
        frame_setup(0, 0, 0);
        player = movie_screen_create(0, 0, 0, 0);
        path = get_special_reel_movie_path(&reel_info[2], 0, 10);
        player->vtable->SetLength(player, reel_info[2] / 0xF);
        player->vtable->Unk74(player, 0);
        player->vtable->Play(player, This->m_GraphicsCtx, path, -1, 1);
        player->vtable->Destroy(player);
    }
}

void game_flow_menu_unused(void *) {
}

s32 game_flow_execute_dream(game_flow_t *This) {
    dream_session_t *dream_ctx;
    s32 dream_result;
    s32 day;
    s32 year;
    s32 result;

    // Start the dream and cleanup
    dream_ctx = dream_session_create(This->m_GraphicsCtx, This->m_DreamSys, This->m_Config->m_FrameSyncMode);
    dream_result = dream_ctx->vtable->dream_session_execute(dream_ctx);
    dream_ctx->vtable->Destroy(dream_ctx);

    // Check if dream tells the loop that today is a special day
    switch (dream_result) {
        case 2:
            game_flow_play_special_day(This);
            break;

        case 3:
            This->m_SkipDreamChart = 1;
            break;

        default:
            break;
    }

    // Year rolls over after day 365; the ending plays on the first day of a new year
    day = This->m_DreamSys->vtable->get_day_number(This->m_DreamSys, &year);

    result = 0;

    if (year) {
        result = day == 1;
    }

    return result;
}

void game_flow_play_special_day(game_flow_t *This) {
    u16 cinematic[4];
    s32 duration[4];
    const char *movie_path;
    movie_screen_t *player;
    ui_screen_t *screen;
    dream_sys_t *dream_sys;

    dream_sys = This->m_DreamSys;
    dream_sys->vtable->dream_sys_get_cinematic(cinematic, dream_sys);

    movie_path = get_special_day_movie(duration, cinematic[0] | (cinematic[1] << 16));

    frame_setup(0, 0, 0);

    if (duration[0] != -1) {
        if (This->m_Config->m_EnableMovie) {
            player = movie_screen_create(0, 0, 0, 0);
            player->vtable->Unk74(player, 0);
            player->vtable->Play(player, This->m_GraphicsCtx, movie_path, get_movie_duration_maybe(duration[0]), 1);
        } else {
            return;
        }
    } else {
        screen = ui_screen_create(0, 0, 0);
        player = (movie_screen_t *) screen;

        screen->vtable->SetIdleTimeout(screen, 10);
        screen->vtable->SetTexture(screen, (char *) movie_path, 0);
        screen->vtable->Run(screen, This->m_GraphicsCtx, 0);
    }

    player->vtable->Destroy(player);
}

void game_flow_play_ending_movie(game_flow_t *This) {
    movie_screen_t *player;
    const char *movie_path;
    s32 duration_index;
    s32 duration;

    if (This->m_Config->m_EnableMovie) {
        frame_setup(0, 0, 0);
        player = movie_screen_create(0, 0, 0, 0);
        player->vtable->Unk74(player, 0);
        movie_path = get_ending_movie_path_2(&duration_index, 0);
        duration = get_movie_duration_maybe(duration_index);
        player->vtable->Play(player, This->m_GraphicsCtx, movie_path, duration, 1);
        player->vtable->Destroy(player);
    }
}

game_flow_vtable_t *game_flow_get_vtable(void) {
    return &g_GAME_FLOW_VTABLE;
}
