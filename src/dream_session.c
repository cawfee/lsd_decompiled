#include "dream_session.h"
#include "scene.h"
#include "map_scene.h"
#include "tmd_model.h"
#include "bgm.h"
#include "dream_sys.h"
#include "memory.h"
#include "tim_image.h"
#include "utils/cd_paths.h"

extern dream_session_vtable_t **g_DREAM_SESSION_VTABLE;
extern s32 D_80086650;
extern s32 D_8008665C;

dream_session_t *dream_session_create(game_graphics_ctx_t *GraphicsCtx, dream_sys_t *DreamSys, s32 EnableSomething) {
    dream_session_t *allocated = (dream_session_t *) memory_allocate_mem(0x50);

    if (allocated) {
        dream_session_get_vtable()->dream_session_construct(allocated, GraphicsCtx, DreamSys, EnableSomething);
        return allocated;
    }

    return NULL;
}

void dream_session_construct(dream_session_t *This,
                             game_graphics_ctx_t *GraphicsCtx,
                             dream_sys_t *DreamSys,
                             s32 EnableSomething) {
    char *unk[4];

    func_8004A4B8()->Construct(This, get_se_path(0), 0);
    This->vtable = dream_session_get_vtable();

    func_8005C508();
    This->m_TextureHelper = tim_image_create("ETC\\ETC.TIM");
    This->m_TextureHelper->vtable->Unk14(This->m_TextureHelper);
    This->m_TextureHelper->vtable->Unk7(This->m_TextureHelper);

    unk[0] = NULL;
    unk[1] = "ETC\\DREAMER.TMD";

    This->m_Unk17 = tmd_create(unk);
    This->m_Unk15 = bgm_create(get_random_sound_type(NULL), 0, 1);

    func_8004A070(1);
    frame_setup(EnableSomething == 0, 1, 1);

    This->m_GraphicsCtx = GraphicsCtx;
    GraphicsCtx->cls_3da54 = func_8004D254();
    GraphicsCtx->cls_32c00 = func_80042400();
    GraphicsCtx->cls_3acc8 = func_8004A4C8(0, 1);

    This->m_DreamSys = DreamSys;
    This->vtable->Unk3(This, DreamSys);
    DreamSys->vtable->Unk66(DreamSys, This->m_Unk12);
    DreamSys->vtable->Unk68(DreamSys, This->m_TextureHelper);
    This->vtable->Unk15(This);
}

void func_8005C5E8(void);

void dream_session_cleanup(dream_session_t *This) {
    game_graphics_ctx_t *gfx;
    bgm_t *bgm;
    tmd_model_t *model;

    gfx = This->m_GraphicsCtx;
    This->vtable->Unk4(This, This->m_DreamSys);
    gfx->cls_3acc8 = gfx->cls_3acc8->vtable->base_class_destructor(gfx->cls_3acc8);
    gfx->cls_32c00 = gfx->cls_32c00->vtable->base_class_destructor(gfx->cls_32c00);
    gfx->cls_3da54 = gfx->cls_3da54->vtable->base_class_destructor(gfx->cls_3da54);
    bgm = (bgm_t *)This->m_Unk15;
    bgm->vtable->base_class_destructor(bgm);
    model = (tmd_model_t *)This->m_Unk17;
    model->vtable->init_800269F0(model);
    This->m_TextureHelper->vtable->Destruct(This->m_TextureHelper);
    func_8005C5E8();
    func_8004A4B8()->Cleanup(This);
}

void dream_session_on_tick(dream_session_t *This, void **Unk2, s32 Unk3) {
    s32 value;

    // unk2 could be either gshelper or 32c00?

    func_8004A4B8()->Unk13(This, Unk2, Unk3);
    value = *(s32 *) *Unk2;

    if ((value & 0xFFFF) == 0x1F34) {
        This->vtable->Unk31(This, Unk2, Unk3);
    } else if ((value & 0xFFFFF) == 0x2F230) {
        This->vtable->on_link_code(This, Unk2, Unk3);
    }
}

void func_80049A14(dream_session_t *This) {
    This->m_Unk14 = 0;
}

void dream_session_execute(dream_session_t *This) {
    dream_sys_t *dream_sys = This->m_DreamSys;
    dream_sys->vtable->Unk3(dream_sys, This->m_GraphicsCtx->cls_16634);
    dream_sys->vtable->Unk3(dream_sys, This->m_GraphicsCtx->cls_32c00);
    dream_sys->vtable->Unk67(dream_sys, This->m_GraphicsCtx->cls_3da54);
    func_8004A4B8()->scene_run(This, This->m_GraphicsCtx, 0);
}

void func_80049AC0(dream_session_t *This) {
    dream_sys_t *dream_sys;

    dream_sys = This->m_DreamSys;
    func_8004A4B8()->Unk17(This);
    dream_sys->vtable->Unk67(dream_sys, 0);
    dream_sys->vtable->Unk4(dream_sys, This->m_GraphicsCtx->cls_16634);
    dream_sys->vtable->Unk4(dream_sys, This->m_Unk3);
}

typedef struct dream_ctx_actor_vtable dream_ctx_actor_vtable_t;
typedef struct dream_ctx_child_vtable dream_ctx_child_vtable_t;

typedef struct dream_ctx_child {
    dream_ctx_child_vtable_t *vtable;
} dream_ctx_child_t;

typedef struct dream_ctx_actor {
    dream_ctx_actor_vtable_t *vtable;
} dream_ctx_actor_t;

typedef struct dream_ctx_child_vtable {
    u32 pad[0x18];
    void (*Unk23)(dream_ctx_child_t *, s32);
} dream_ctx_child_vtable_t;

typedef struct dream_ctx_actor_vtable {
    u32 pad0[0x11];
    void (*Unk16)(dream_ctx_actor_t *, void *);
    u32 pad1;
    void (*Unk18)(dream_ctx_actor_t *, s32);
    u32 pad2[8];
    void (*Unk27)(dream_ctx_actor_t *, dream_sys_t *, s32 *, s32 *, s32);
    u32 pad3[6];
    void (*Unk34)(dream_ctx_actor_t *);
    u32 pad4[7];
    dream_ctx_child_t *(*Unk42)(dream_ctx_actor_t *);
} dream_ctx_actor_vtable_t;

void func_80049B54(dream_session_t *This) {
    display_t *gs;
    dream_ctx_actor_t *actor;
    dream_ctx_child_t *child;
    void *screen;

    gs = This->m_GraphicsCtx->display;
    actor = (dream_ctx_actor_t *)This->m_Unk5;
    screen = gs->vtable->display_get_screen_size(gs, 0);
    actor->vtable->Unk16(actor, screen);
    child = actor->vtable->Unk42(actor);
    child->vtable->Unk23(child, 1);
    actor->vtable->Unk18(actor, 0x4B0);
    actor->vtable->Unk27(actor, This->m_DreamSys, &D_80086650, &D_8008665C, 0);
    actor->vtable->Unk34(actor);
    This->m_Unk14 = 1;
}

void func_80049C50(dream_session_t *This) {
    s32 m_Unk5; // $s0

  m_Unk5 = This->m_Unk5;
  (*(void ( **)(s32))(*(s32 *)m_Unk5 + 144))(m_Unk5);
  (*(void ( **)(s32))(*(s32 *)m_Unk5 + 116))(m_Unk5);
}

void open_map(dream_session_t *This, s32 Unk);

void func_80049CA8(dream_session_t *This, void *arg1, s32 arg2) {
    s32 state;
    s32 result;
    map_scene_t *obj;

    func_8004A4B8()->Unk20(This, arg1, arg2);
    if (arg2 != 2) {
        return;
    }
    state = This->m_Unk14;
    if (state == arg2) {
        return;
    }
    if (state < 3) {
        if (state == 1) {
            goto state1;
        }
        return;
    }
    if (state == 3) {
        goto state3;
    }
    return;
state1:
    result = This->m_DreamSys->vtable->dream_sys__start_day(This->m_DreamSys);
    if (result >= 0) {
        open_map(This, result);
        return;
    }
    This->m_DreamSys->vtable->dream_sys__end_day(This->m_DreamSys, 0);
    This->m_Unk9 = arg2;
    This->vtable->Unk23(This, 3);
    return;
state3:
    obj = (map_scene_t *)This->m_Unk18;
    ((void (*)(map_scene_t *))obj->vtable->Unk17)(obj);
    obj = (map_scene_t *)This->m_Unk18;
    obj->vtable->base_class_destructor(obj);
    open_map(This, This->m_DreamSys->vtable->Unk119(This->m_DreamSys));
}

void open_map(dream_session_t *This, s32 Unk) {
    void **obj;

    This->m_Unk18 = (s32)map_scene_create(This->m_Unk12, This->m_Unk15, (s32)This->m_TextureHelper,
                                         This->m_Unk17, Unk);
    This->vtable->Unk3(This, This->m_Unk18);
    obj = (void **)This->m_Unk18;
    (*(void (**)(void **, void *, void *))(*(u32 *)obj + 0x44))(obj, This->m_GraphicsCtx, This->m_DreamSys);
    This->m_Unk14 = 2;
}

void func_80049EA4(void) {
}

void func_80049EAC(void) {
}

void on_link_code(dream_session_t *This, s32 Unk2, s32 Unk3) {
    s32 unk;
    s32 unk4;
    s16 sp10[4];
    dream_sys_t *dream_sys;
    dream_sys_vtable_t *vtable;

    switch (Unk3) {
        case 4:
            (*(void (**)(s32, s32))(*(s32 *) This->m_Unk18 + 0x48))(This->m_Unk18, Unk2);
            (*(void (**)(s32))(*(s32 *) This->m_Unk18 + 4))(This->m_Unk18);
            if (This->m_DreamSys->vtable->dream_sys__end_day(This->m_DreamSys, 0) == 0) {
                This->m_DreamSys->vtable->dream_sys__get_cinematic(sp10, This->m_DreamSys);
                unk4 = 2;
                if (sp10[1] < 0) {
                    unk4 = 1;
                }
                This->m_Unk9 = unk4;
                goto block_4_join;
            }
            This->m_Unk9 = 3;
        block_4_join:
            This->vtable->Unk23(This, 3);
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
            This->m_Unk14 = 3;
            break;
        case 12:
        case 13:
            (*(void (**)(s32, s32))(*(s32 *) This->m_Unk18 + 0x48))(This->m_Unk18, Unk2);
            (*(void (**)(s32))(*(s32 *) This->m_Unk18 + 4))(This->m_Unk18);
            dream_sys = This->m_DreamSys;
            vtable = dream_sys->vtable;
            unk = 1;
            if (Unk3 != 12) {
                unk = 2;
            }
            vtable->dream_sys__end_day(dream_sys, unk);
            This->m_Unk9 = 3;
            This->vtable->Unk23(This, 3);
            break;
    }
}

dream_session_vtable_t *dream_session_get_vtable(void) {
    return &g_DREAM_SESSION_VTABLE;
}

INCLUDE_ASM("asm/nonmatchings/dream_session", func_8004A070);
