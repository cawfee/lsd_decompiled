#include "common.h"

#include <psx/libetc.h>

#include "system.h"
#include "ui_screen.h"
#include "graph_screen.h"
#include "movie_screen.h"
#include "dream_session.h"
#include "game_flow.h"
#include "main_menu.h"
#include "memory.h"
#include "utils/cd_paths.h"

extern game_flow_vtable_t g_GAME_FLOW_VTABLE;

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
    char *buffer[4];

    func_8003B20C()->Construct(This, Config->unk_flags);
    This->vtable = game_flow_get_vtable();
    This->m_Config = Config;

    set_data_folder(get_data_folder());

    buffer[0] = NULL;
    buffer[1] = "ETC\\DREAME5.TMD";

    This->m_pDreamSys = dream_sys_create(tmd_create(&buffer), 0, 0);
    This->m_UnkGameMember = 0;
    This->m_pDreamSys->vtable->Unk137(This->m_pDreamSys, Config->enable_unk);
    This->vtable->game_flow_get_day_rand(This);
}

s32 game_flow_get_day_rand() {
    return get_seeded_random(*(s32 *) GET_SCRATCH_ADDR(0) % 365, 0);
}

void game_flow_init(game_flow_t *This, display_t *GsHelper, pad_t *Unk3) {
    if (!This->m_IsInit) {
        func_8003B20C()->game_flow_init_graphics(This, GsHelper, Unk3, 0);
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
        player->vtable->base_class_destructor(player);

        game_flow_display_logo(This, "ETC\\OSDLOGO.TIM");
    }
}

void game_flow_display_logo(game_flow_t *This, const char *Path) {
    ui_screen_t *cls = func_8003BE94(0, 0, 0);
    cls->vtable->Unk37(cls, &game_flow_callback, This);
    cls->vtable->Unk26(cls, 0);
    cls->vtable->Unk52(cls, Path, 0);
    cls->vtable->Run(cls, This->m_GraphicsCtx, 0);
    cls->vtable->base_class_destructor(cls);
}

void game_flow_callback() {
    func_8004A070(0);
}

void game_flow_play_intro_movie(game_flow_t *This) {
    movie_screen_t *player;
    char *path;
    s32 index;
    s32 duration;

    if (This->m_Config->enable_movie) {
        frame_setup(0, 0, 0);

        player = movie_screen_create(0, 0, 0, 0);
        path = func_8004913C(&index, 0);
        duration = get_movie_duration_maybe(index);
        player->vtable->Play(player, This->m_GraphicsCtx, path, duration, 1);
        player->vtable->base_class_destructor(player);
    }
}

s32 game_flow_execute_main_menu(game_flow_t *This) {
    s32 value;

    if (This->m_Config->enable_main_menu) {
        frame_setup(0, 0, 0);

        if (This->m_pDreamSys->vtable->get_day_number(This->m_pDreamSys, 0) != 1 && !This->m_UnkGameMember &&
            run_screen(&graph_screen_create, This->m_pDreamSys, This->m_GraphicsCtx) == 2) {
            play_special_reel(This);
        }

        while (1) {
            value = run_screen(main_menu_create, This->m_pDreamSys, This->m_GraphicsCtx);

            if (value != 2) {
                break;
            }

            run_screen(graph_screen_create, This->m_pDreamSys, This->m_GraphicsCtx);
        }

        This->m_UnkGameMember = 0;
        return 2 * (value == 0);
    }

    // Jump straight to game if main menu is not enabled
    return 2;
}

s32 run_screen(s32 (*Callback)(s32), s32 Unk1, s32 Unk2) {
    s32 vtable = Callback(Unk1);
    s32 result = (*(s32(**)(s32, s32, u32))(*(u32 *) vtable + 68))(vtable, Unk2, 0);
    void (*callback2)(s32) = *(void (**)(s32))(*(u32 *) vtable + 4);
    callback2(vtable);
    return result;
}

void play_special_reel(game_flow_t *This) {
    movie_screen_t *player;
    char *path;
    u32 unk[3]; // TODO unk struct

    if (This->m_Config->enable_movie) {
        frame_setup(0, 0, 0);
        player = movie_screen_create(0, 0, 0, 0);
        path = func_800493E4(&unk[2], 0, 10);
        player->vtable->Unk26(player, unk[2] / 0xF);
        player->vtable->Unk74(player, 0);
        player->vtable->Play(player, This->m_GraphicsCtx, path, -1, 1);
        player->vtable->base_class_destructor(player);
    }
}

void nullsub12(void) {
}

s32 game_flow_execute_dream(game_flow_t *This) {
    dream_session_t *dream_ctx;
    s32 dream_result;
    s32 unk;
    s32 unk2;
    s32 result;

    // Start the dream and cleanup
    dream_ctx = dream_session_create(This->m_GraphicsCtx, This->m_pDreamSys, This->m_Config->enable_something);
    dream_result = dream_ctx->vtable->dream_session_execute(dream_ctx);
    dream_ctx->vtable->base_class_destructor(dream_ctx);

    // Check if dream tells the loop that today is a special day
    switch (dream_result) {
        case 2:
            game_flow_play_special_day(This);
            break;

        case 3:
            This->m_UnkGameMember = 1;
            break;

        default:
            break;
    }

    // TODO Unchecked
    unk = This->m_pDreamSys->vtable->get_day_number(This->m_pDreamSys, &unk2);

    result = 0;

    if (unk2) {
        result = unk == 1;
    }

    return result;
}

void game_flow_play_special_day(game_flow_t *This) {
    u16 day[4];
    s32 duration[4];
    s8 *movie_name;
    movie_screen_t *player;
    ui_screen_t *cls;
    dream_sys_t *dream_sys;

    dream_sys = This->m_pDreamSys;
    dream_sys->vtable->dream_sys__get_cinematic(day, dream_sys);

    movie_name = get_special_day_movie(duration, day[0] | (day[1] << 16));

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
        cls = func_8003BE94(0, 0, 0);
        player = (movie_screen_t *) cls;

        cls->vtable->Unk26(cls, 10);
        cls->vtable->Unk52(cls, (char *) movie_name, 0);
        cls->vtable->Run(cls, This->m_GraphicsCtx, 0);
    }

    player->vtable->base_class_destructor(player);
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
        player->vtable->base_class_destructor(player);
    }
}

game_flow_vtable_t *game_flow_get_vtable(void) {
    return &g_GAME_FLOW_VTABLE;
}
