#include "dream_context.h"
#include "3A930.h"
#include "bgm.h"
#include "dream_sys.h"
#include "memory.h"
#include "texture_helper.h"
#include "utils/path_helper.h"

extern dream_context_vtable_t **g_DREAM_CONTEXT_VTABLE;

dream_context_t *dream_context_create(game_graphics_ctx_t *GraphicsCtx, dream_sys_t *DreamSys, s32 EnableSomething) {
    dream_context_t *allocated = (dream_context_t *) memory_allocate_mem(0x50);

    if (allocated) {
        dream_context_get_vtable()->Construct(allocated, GraphicsCtx, DreamSys, EnableSomething);
        return allocated;
    }

    return NULL;
}

void dream_context_construct(dream_context_t *This,
                             game_graphics_ctx_t *GraphicsCtx,
                             dream_sys_t *DreamSys,
                             s32 EnableSomething) {
    char *unk[4];

    func_8004A4B8()->Construct(This, get_se_path(0), 0);
    This->vtable = dream_context_get_vtable();

    func_8005C508();
    This->m_TextureHelper = texture_helper_create("ETC\\ETC.TIM");
    This->m_TextureHelper->vtable->Unk14(This->m_TextureHelper);
    This->m_TextureHelper->vtable->Unk7(This->m_TextureHelper);

    unk[0] = NULL;
    unk[1] = "ETC\\DREAMER.TMD";

    This->m_Unk17 = func_80043840(unk);
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

INCLUDE_ASM("asm/nonmatchings/dream_context", dream_context_cleanup);

void dream_context_on_tick(dream_context_t *This, void **Unk2, s32 Unk3) {
    s32 value;

    // unk2 could be either gshelper or 32c00?

    func_8004A4B8()->Unk13(This, Unk2, Unk3);
    value = *(s32 *) *Unk2;

    if ((value & 0xFFFF) == 0x1F34) {
        This->vtable->Unk31(This, Unk2, Unk3);
    } else if ((value & 0xFFFFF) == 0x2F230) {
        This->vtable->Unk32(This, Unk2, Unk3);
    }
}

void func_80049A14(dream_context_t *This) {
    This->m_Unk14 = 0;
}

void dream_context_execute_dream(dream_context_t *This) {
    dream_sys_t *dream_sys = This->m_DreamSys;
    dream_sys->vtable->Unk3(dream_sys, This->m_GraphicsCtx->cls_16634);
    dream_sys->vtable->Unk3(dream_sys, This->m_GraphicsCtx->cls_32c00);
    dream_sys->vtable->Unk67(dream_sys, This->m_GraphicsCtx->cls_3da54);
    func_8004A4B8()->Unk16(This, This->m_GraphicsCtx, 0);
}

void func_80049AC0(dream_context_t *This) {
    dream_sys_t *dream_sys;

    dream_sys = This->m_DreamSys;
    func_8004A4B8()->Unk17(This);
    dream_sys->vtable->Unk67(dream_sys, 0);
    dream_sys->vtable->Unk4(dream_sys, This->m_GraphicsCtx->cls_16634);
    dream_sys->vtable->Unk4(dream_sys, This->m_Unk3);
}

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049B54);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049C50);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049CA8);

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049E20);

void func_80049EA4(void) {
}

void func_80049EAC(void) {
}

INCLUDE_ASM("asm/nonmatchings/dream_context", func_80049EB4);

dream_context_vtable_t *dream_context_get_vtable(void) {
    return &g_DREAM_CONTEXT_VTABLE;
}

INCLUDE_ASM("asm/nonmatchings/dream_context", func_8004A070);
