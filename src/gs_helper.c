#include "gs_helper.h"

#include <psx/libetc.h>
#include <psx/libgs.h>

#include "base_class.h"
#include "common.h"

extern gs_helper_vtable_t **g_GS_HELPER_VTABLE;

gs_helper_t *gs_helper_create() {
    gs_helper_t *allocated = (gs_helper_t *) memory_allocate_mem(0x34);

    if (allocated) {
        gs_helper_vtable_t *vtable = gs_helper_get_vtable();
        vtable->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_80020730(gs_helper_t *This) {
    base_class_get_vtable()->Construct(This);
    This->vtable = gs_helper_get_vtable();
    This->vtable->Reset(This);
}

void gs_helper_reset(gs_helper_t *This) {
    This->m_VSyncCount = 0;
    This->vtable->SetVBlanks(This, 3);
    This->vtable->Unk31(This, 1);
    This->m_VsyncCallback = NULL;
}

void gs_helper_init_gs(gs_helper_t *This, vec2d_t *ScreenSize, s32 VarMode) {
    GsInitGraph(ScreenSize->x, ScreenSize->y, 0, 1, VarMode);
    GsDefDispBuff(0, 0, 0, ScreenSize->y);

    This->m_ScreenSize = *ScreenSize;
    This->m_VarMode = VarMode;
}

void gs_helper_do_vsync(gs_helper_t *This) {
    if (!This->m_VSyncCount) {
        This->m_VSyncCount = 1;

        This->vtable->VSync(This);
    }
}

void gs_helper_reset_vsync_count(gs_helper_t *This) {
    if (This->m_VSyncCount) {
        This->m_VSyncCount = 0;
    }
}

void gs_helper_swap_disp_buffer(gs_helper_t *This) {
    UNUSED(This);
    GsSwapDispBuff();
}

s32 gs_helper_get_active_buffer(gs_helper_t *This) {
    UNUSED(This);
    return GsGetActiveBuff();
}

void func_800208F8(gs_helper_t *This, s16 *Unk2, s32 Unk3) {
    s16 unk_struct[4];

    if (!This->m_VSyncCount || This->m_Unk9) {
        gs_helper_copy_unk(unk_struct, Unk2);
        func_8002133C(unk_struct, Unk3);
        if (This->m_Unk9) {
            func_80021114(0);
        }
    }
}

// Copy something to something, not on the vtable
void gs_helper_copy_unk(void *This, void *CopyFrom) {
    *(u16 *) ((u8 *) This + 0) = *(u16 *) ((u8 *) CopyFrom + 0);
    *(u16 *) ((u8 *) This + 2) = *(u16 *) ((u8 *) CopyFrom + 2);
    *(u16 *) ((u8 *) This + 4) = *(u16 *) ((u8 *) CopyFrom + 4);
    *(u16 *) ((u8 *) This + 6) = *(u16 *) ((u8 *) CopyFrom + 8);
}

void func_800209A0(gs_helper_t *This, s32 Unk2, s16 *Unk3) {
    s16 unk_struct[4];

    if (!This->m_VSyncCount || This->m_Unk9) {
        gs_helper_copy_unk(unk_struct, Unk3);
        func_800213A0(unk_struct, Unk2);
        if (This->m_Unk9) {
            func_80021114(0);
        }
    }
}

s32 func_80020A1C(gs_helper_t *This) {
    UNUSED(This);
    return 0;
}

void func_80020A24(gs_helper_t *This, s16 *Unk1, s16 Unk2, s16 Unk3) {
    s16 unk_struct[4];

    gs_helper_copy_unk((s16 *) &unk_struct, (s16 *) Unk1);
    func_80021404((s16 *) &unk_struct, (s16) Unk2, (s16) Unk3);
}

void gs_helper_do_vsync_internal(gs_helper_t *This) {
    void (*vsync_callback)();

    while (This->m_VSyncCount) {
        VSync(This->m_NextVBlank);
        vsync_callback = This->m_VsyncCallback;
        if (vsync_callback) {
            vsync_callback();
        }
        This->vtable->Unk11(This, 2);
    }
}

void func_80020AF4(gs_helper_t *This) {
    UNUSED(This);

    void *struct_data; // $a0
    int unk;           // $v1
    int unk2;          // $v0

    struct_data = func_80020C5C();
    unk = *((u32 *) struct_data + 8);
    unk2 = *((u32 *) struct_data + 9) + 1;
    *((u32 *) struct_data + 9) = unk2;
    if (unk2 >= unk && !*((u32 *) struct_data + 3)) {
        *((u32 *) struct_data + 3) = 1;
        *((u32 *) struct_data + 9) = 0;
    }
}

// Set the amount of vblanks to be waited for
void gs_helper_set_vblanks(gs_helper_t *This, s32 VideoMode) {
    if (!This->m_VSyncCount) {
        This->m_NextVBlank = VideoMode;
    }
}

// Get the amount of vblanks to be waited for?
s32 gs_helper_get_vblanks(gs_helper_t *This) {
    return This->m_NextVBlank;
}

void func_80020B74(gs_helper_t *This, unsigned char *UnkData, s32 Unk3) {
    char unk_buffer1[16];
    char unk_buffer2[4];

    if (!Unk3) {
        This->vtable->GetScreenSize(This, (s32) unk_buffer1);
        This->vtable->Unk29(This, UnkData, unk_buffer1);
    } else {
        gs_helper_copy_unk(unk_buffer2, Unk3);
        func_800212A8((int) unk_buffer2, *UnkData, UnkData[1], UnkData[2]);
    }
}

void *func_80020C08(gs_helper_t *This, void *Unk) {
    if (Unk) {
        *(u16 *) Unk = 0;
        *((u16 *) Unk + 1) = 0;
        *((u32 *) Unk + 1) = This->m_ScreenSize.x;
        *((u32 *) Unk + 2) = 2 * This->m_ScreenSize.y;
    }
    return &This->m_ScreenSize;
}

void func_80020C3C(gs_helper_t *This, s32 Unk) {
    This->m_Unk9 = Unk;
}

void gs_helper_set_vsync_callback(gs_helper_t *This, void (*Callback)()) {
    This->m_VsyncCallback = Callback;
}

gs_helper_vtable_t *gs_helper_get_vtable(void) {
    return &g_GS_HELPER_VTABLE;
}
