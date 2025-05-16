#include "common.h"

#include <psx/libetc.h>

#include "game_flow.h"
#include "utils/path_helper.h"
#include "2B78C.h"
#include "memory.h"

extern game_flow_vtable_t g_GAME_FLOW_VTABLE;

game_flow_t *game_flow_create(game_config_t *Config) {
    game_flow_t *allocated = (game_flow_t *) memory_allocate_mem(0x2C);

    if (allocated) {
        game_flow_get_vtable()->Construct(allocated, Config);
        return allocated;
    }

#ifdef NON_MATCHING
    return NULL;
#endif
}

void game_flow_on_construct(game_flow_t *This, game_config_t *Config) {
    u32 buffer[4];

    func_8003B20C()->Construct(This, Config->unk_flags);
    This->vtable = game_flow_get_vtable();
    This->m_Config = Config;

    func_800270AC(get_data_folder());

    buffer[0] = 0;
    buffer[1] = "ETC\\DREAME5.TMD";

    This->m_pDreamSys = New_DreamSys(func_80043840(&buffer), 0, 0);
    This->m_UnkGameMember = 0;
    This->m_pDreamSys->vtable->Unk137(This->m_pDreamSys, Config->enable_unk);
    This->vtable->GetDayBasedSeed(This);
}

s32 game_flow_get_day_rand() {
    return get_seeded_random(*(s32 *) getScratchAddr(0) % 365, 0);
}

void func_80026108(game_flow_t *This, s32 Unk2, s32 Unk3) {
    if (!This->m_IsInit) {
        func_8003B20C()->Unk16(This, Unk2, Unk3, 0);
    }
}

void game_flow_display_logo_sequence(game_flow_t *This) {
    s32 *frame_ctx = NULL;
    s32 success;
    const char *path = NULL;
    s32 process_state;

    if (This->m_Config->enable_logo) {
        frame_setup(0, 0, 0);
        game_flow_display_logo(This, "ETC\\ASMKLOGO.TIM");
    
        frame_ctx = get_frame_context(0, 0, 0, 0);
        path = get_logo_asmk_path(&success);
        process_state = get_movie_duration_maybe(success);
    
        (*(void (**)(s32, u32, s32, s32, s32))(*(u32 *) frame_ctx + 68))(frame_ctx, This->m_RegisteredObjects, path, process_state, 1);
        (*(void (**)(s32 *))(*(u32 *)frame_ctx + 4))(frame_ctx);
        
        game_flow_display_logo(This, "ETC\\OSDLOGO.TIM");
    }
}

void game_flow_display_logo(game_flow_t *This, const char *Path) {
    s32 vtable = func_8003BE94(0, 0, 0);
    (*(void (**)(s32, s32 (*)(), s32))(*(u32 *)vtable + 152))(vtable, &func_80026328, This);
    (*(void (**)(s32, u32))(*(u32 *)vtable + 108))(vtable, 0);
    (*(void (**)(s32, s32, u32))(*(u32 *)vtable + 212))(vtable, Path, 0);
    (*(void (**)(s32, u32, u32))(*(u32 *)vtable + 68))(vtable, This->m_RegisteredObjects, 0);
    (*(s32 (**)(s32))(*(u32 *)vtable + 4))(vtable);
}

void func_80026328() {
    func_8004A070(0);
}

void game_flow_play_intro_movie(game_flow_t *This) {
    s32 frame_ctx;
    s32 state;
    s32 value;
    s32 process;

    if (This->m_Config->enable_movie) {
        frame_setup(0, 0, 0);

        frame_ctx = get_frame_context(0, 0, 0, 0);
        state = func_8004913C(&value, 0);
        process = get_movie_duration_maybe(value);
        (*(void (**)(s32, void *, s32, s32, s32))(*(u32 *)frame_ctx + 68))(frame_ctx, This->m_RegisteredObjects, state, process, 1);
        (*(s32 (**)(s32))(*(u32 *)frame_ctx + 4))(frame_ctx);
    }
}

INCLUDE_ASM("asm/nonmatchings/game_flow", game_flow_execute_main_menu);

s32 func_80026518(s32 (*Callback)(s32), s32 Unk1, s32 Unk2) {
    s32 vtable = Callback(Unk1);
    s32 result = (*(s32 (**)(s32, s32, u32))(*(u32 *)vtable + 68))(vtable, Unk2, 0);
    void (*callback2)(s32) = *(void (**)(s32))(*(u32 *)vtable + 4);
    callback2(vtable);
    return result;
}

INCLUDE_ASM("asm/nonmatchings/game_flow", func_8002658C);

void nullsub12(void) { }

INCLUDE_ASM("asm/nonmatchings/game_flow", game_flow_execute_dream);

INCLUDE_ASM("asm/nonmatchings/game_flow", game_flow_play_special_day);

INCLUDE_ASM("asm/nonmatchings/game_flow", game_flow_play_ending_movie);

game_flow_vtable_t *game_flow_get_vtable(void) {
    return &g_GAME_FLOW_VTABLE;
}
