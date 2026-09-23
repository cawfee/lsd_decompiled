#include "display.h"

#include <psx/libetc.h>
#include <psx/libgs.h>

#include "base_class.h"
#include <common.h>

extern display_vtable_t **g_DISPLAY_VTABLE;

display_t *display_create() {
    display_t *allocated = (display_t *) memory_allocate_mem(0x34);

    if (allocated) {
        display_vtable_t *vtable = display_get_vtable();
        vtable->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_80020730(display_t *This) {
    base_class_get_vtable()->base_class_construct(This);
    This->vtable = display_get_vtable();
    This->vtable->display_reset(This);
}

void display_reset(display_t *This) {
    This->m_VSyncCount = 0;
    This->vtable->display_set_vblanks(This, 3);
    This->vtable->Unk31(This, 1);
    This->m_VsyncCallback = NULL;
}

void display_init_gs(display_t *This, vec2d_t *ScreenSize, s32 VarMode) {
    GsInitGraph(ScreenSize->x, ScreenSize->y, 0, 1, VarMode);
    GsDefDispBuff(0, 0, 0, ScreenSize->y);

    This->m_ScreenSize = *ScreenSize;
    This->m_VarMode = VarMode;
}

void display_do_vsync(display_t *This) {
    if (!This->m_VSyncCount) {
        This->m_VSyncCount = 1;

        This->vtable->display_do_vsync_internal(This);
    }
}

void display_reset_vsync_count(display_t *This) {
    if (This->m_VSyncCount) {
        This->m_VSyncCount = 0;
    }
}

void display_swap_disp_buffer(display_t *This) {
    UNUSED(This);
    GsSwapDispBuff();
}

s32 display_get_active_buffer(display_t *This) {
    UNUSED(This);
    return GsGetActiveBuff();
}

void display_load_image(display_t *This, s16 *Unk2, s32 Unk3) {
    s16 unk_struct[4];

    if (!This->m_VSyncCount || This->m_Unk9) {
        display_copy_unk(unk_struct, Unk2);
        LoadImage(unk_struct, Unk3);
        if (This->m_Unk9) {
            DrawSync(0);
        }
    }
}

// Copy something to something, not on the vtable
void display_copy_unk(void *This, void *CopyFrom) {
    *(u16 *) ((u8 *) This + 0) = *(u16 *) ((u8 *) CopyFrom + 0);
    *(u16 *) ((u8 *) This + 2) = *(u16 *) ((u8 *) CopyFrom + 2);
    *(u16 *) ((u8 *) This + 4) = *(u16 *) ((u8 *) CopyFrom + 4);
    *(u16 *) ((u8 *) This + 6) = *(u16 *) ((u8 *) CopyFrom + 8);
}

void display_store_image(display_t *This, s32 Unk2, s16 *Unk3) {
    s16 unk_struct[4];

    if (!This->m_VSyncCount || This->m_Unk9) {
        display_copy_unk(unk_struct, Unk3);
        StoreImage(unk_struct, Unk2);
        if (This->m_Unk9) {
            DrawSync(0);
        }
    }
}

s32 func_80020A1C(display_t *This) {
    UNUSED(This);
    return 0;
}

void func_80020A24(display_t *This, s16 *Unk1, s16 Unk2, s16 Unk3) {
    s16 unk_struct[4];

    display_copy_unk((s16 *) &unk_struct, (s16 *) Unk1);
    MoveImage((s16 *) &unk_struct, (s16) Unk2, (s16) Unk3);
}

void display_do_vsync_internal(display_t *This) {
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

void func_80020AF4(display_t *This) {
    UNUSED(This);

    void *struct_data;
    int unk;
    int unk2;

    struct_data = get_display();
    unk = *((u32 *) struct_data + 8);
    unk2 = *((u32 *) struct_data + 9) + 1;
    *((u32 *) struct_data + 9) = unk2;
    if (unk2 >= unk && !*((u32 *) struct_data + 3)) {
        *((u32 *) struct_data + 3) = 1;
        *((u32 *) struct_data + 9) = 0;
    }
}

// Set the amount of vblanks to be waited for
void display_set_vblanks(display_t *This, s32 VideoMode) {
    if (!This->m_VSyncCount) {
        This->m_NextVBlank = VideoMode;
    }
}

// Get the amount of vblanks to be waited for?
s32 display_get_vblanks(display_t *This) {
    return This->m_NextVBlank;
}

void func_80020B74(display_t *This, unsigned char *UnkData, s32 Unk3) {
    char unk_buffer1[16];
    char unk_buffer2[4];

    if (!Unk3) {
        This->vtable->display_get_screen_size(This, (s32) unk_buffer1);
        This->vtable->Unk29(This, UnkData, unk_buffer1);
    } else {
        display_copy_unk(unk_buffer2, Unk3);
        ClearImage((int) unk_buffer2, *UnkData, UnkData[1], UnkData[2]);
    }
}

void *display_get_screen_size(display_t *This, void *Unk) {
    if (Unk) {
        *(u16 *) Unk = 0;
        *((u16 *) Unk + 1) = 0;
        *((u32 *) Unk + 1) = This->m_ScreenSize.x;
        *((u32 *) Unk + 2) = 2 * This->m_ScreenSize.y;
    }
    return &This->m_ScreenSize;
}

void func_80020C3C(display_t *This, s32 Unk) {
    This->m_Unk9 = Unk;
}

void display_set_vsync_callback(display_t *This, void (*Callback)()) {
    This->m_VsyncCallback = Callback;
}

display_vtable_t *display_get_vtable(void) {
    return &g_DISPLAY_VTABLE;
}
