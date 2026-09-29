#include "common.h"

#include <psx/libetc.h>

#include "base_class.h"
#include "system.h"
#include "ui_screen.h"
#include "graph_screen.h"
#include "movie_screen.h"
#include "dream_session.h"
#include "dream_session_path.h"
#include "game_flow.h"
#include "main_menu.h"
#include "memory.h"
#include "utils/cd_paths.h"


void game_flow_on_construct(void *, void *);
void nullsub25(void *);
s32 game_flow_get_day_rand(void);
void game_flow_init(void *, display_t *, pad_t *);
void func_8003B108(void *);
void game_flow_execute_phases(void *);
void game_flow_display_logo_sequence(void *);
void game_flow_play_intro_movie(void *);
s32 game_flow_execute_main_menu(void *);
void nullsub12(void *);
s32 game_flow_execute_dream(void *);
void game_flow_play_ending_movie(void *);

game_flow_vtable_t g_GAME_FLOW_VTABLE = {
    0x1F60,
    base_class_destructor,
    game_flow_on_construct,
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
    (void (*)(void *))game_flow_get_day_rand,
    game_flow_init,
    func_8003B108,
    game_flow_execute_phases,
    game_flow_display_logo_sequence,
    game_flow_play_intro_movie,
    game_flow_execute_main_menu,
    nullsub12,
    game_flow_execute_dream,
    game_flow_play_ending_movie,
};

game_flow_t *game_flow_create(game_config_t *Config) {
    game_flow_t *allocated = (game_flow_t *) memory_allocate_mem(0x2C);

    if (allocated) {
        game_flow_get_vtable()->game_flow_on_construct(allocated, Config);
        return allocated;
    }

#ifdef NON_MATCHING
    return NULL;
#endif
}

void game_flow_on_construct(game_flow_t *This, game_config_t *Config) {
    char *tmd_args[4];

    system_get_vtable()->Construct(This, Config->file_driver_class);
    This->vtable = game_flow_get_vtable();
    This->m_Config = Config;

    set_data_folder(get_data_folder());

    tmd_args[0] = NULL;
    tmd_args[1] = "ETC\\DREAME5.TMD";

    This->m_DreamSys = dream_sys_create(tmd_create(&tmd_args), 0, 0);
    This->m_SkipDreamChart = 0;
    This->m_DreamSys->vtable->dream_sys__set_unk_flag(This->m_DreamSys, Config->unused_flag);
    This->vtable->game_flow_get_day_rand(This);
}

s32 game_flow_get_day_rand() {
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

    if (This->m_Config->enable_logo) {
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
    ui_screen_t *cls = ui_screen_create(0, 0, 0);
    cls->vtable->SetCallback(cls, &game_flow_logo_callback, This);
    cls->vtable->SetIdleTimeout(cls, 0);
    cls->vtable->SetTexture(cls, Path, 0);
    cls->vtable->Run(cls, This->m_GraphicsCtx, 0);
    cls->vtable->Destroy(cls);
}

void game_flow_logo_callback() {
    dream_session_path_advance(0);
}

void game_flow_play_intro_movie(game_flow_t *This) {
    movie_screen_t *player;
    const char *path;
    s32 index;
    s32 duration;

    if (This->m_Config->enable_movie) {
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

    if (This->m_Config->enable_main_menu) {
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

// Creates a screen object, runs it (vtable +0x44) with Arg1, destroys it (vtable +0x04),
// and returns the value the screen's Run returned.
s32 run_screen(s32 (*Create)(s32), s32 Arg0, s32 Arg1) {
    s32 obj = Create(Arg0);
    s32 run_result = (*(s32(**)(s32, s32, u32))(*(u32 *) obj + 68))(obj, Arg1, 0);
    void (*destroy)(s32) = *(void (**)(s32))(*(u32 *) obj + 4);
    destroy(obj);
    return run_result;
}

void play_special_reel(game_flow_t *This) {
    movie_screen_t *player;
    const char *path;
    u32 reel_info[3]; // [2] = total playback length in frames (written by get_special_reel_movie_path)

    if (This->m_Config->enable_movie) {
        frame_setup(0, 0, 0);
        player = movie_screen_create(0, 0, 0, 0);
        path = get_special_reel_movie_path(&reel_info[2], 0, 10);
        player->vtable->SetLength(player, reel_info[2] / 0xF);
        player->vtable->Unk74(player, 0);
        player->vtable->Play(player, This->m_GraphicsCtx, path, -1, 1);
        player->vtable->Destroy(player);
    }
}

void nullsub12(void *) {
}

s32 game_flow_execute_dream(game_flow_t *This) {
    dream_session_t *dream_ctx;
    s32 dream_result;
    s32 day;
    s32 year;
    s32 result;

    // Start the dream and cleanup
    dream_ctx = dream_session_create(This->m_GraphicsCtx, This->m_DreamSys, This->m_Config->frame_sync_mode);
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
    const char *movie_name;
    movie_screen_t *player;
    ui_screen_t *cls;
    dream_sys_t *dream_sys;

    dream_sys = This->m_DreamSys;
    dream_sys->vtable->dream_sys__get_cinematic(cinematic, dream_sys);

    movie_name = get_special_day_movie(duration, cinematic[0] | (cinematic[1] << 16));

    frame_setup(0, 0, 0);

    if (duration[0] != -1) {
        if (This->m_Config->enable_movie) {
            player = movie_screen_create(0, 0, 0, 0);
            player->vtable->Unk74(player, 0);
            player->vtable->Play(player, This->m_GraphicsCtx, (char *) movie_name,
                                  get_movie_duration_maybe(duration[0]), 1);
        } else {
            return;
        }
    } else {
        cls = ui_screen_create(0, 0, 0);
        player = (movie_screen_t *) cls;

        cls->vtable->SetIdleTimeout(cls, 10);
        cls->vtable->SetTexture(cls, (char *) movie_name, 0);
        cls->vtable->Run(cls, This->m_GraphicsCtx, 0);
    }

    player->vtable->Destroy(player);
}

void game_flow_play_ending_movie(game_flow_t *This) {
    movie_screen_t *player;
    const char *movie_path;
    s32 duration_index;
    s32 duration;

    if (This->m_Config->enable_movie) {
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
