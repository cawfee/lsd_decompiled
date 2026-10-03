#include "graphics/display.h"

#include <psx/libetc.h>
#include <psx/libgs.h>

#include "base/base.h"

display_vtable_t g_DISPLAY_VTABLE = {
    1,
    base_class_destructor,
    display_construct,
    base_class_cleanup,
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
    display_reset,
    display_init_gs,
    display_do_vsync,
    display_reset_vsync_count,
    display_swap_disp_buffer,
    display_get_active_buffer,
    display_load_image,
    display_store_image,
    display_get_status,
    display_move_image,
    display_do_vsync_internal,
    display_update_timer,
    display_set_vblanks,
    display_get_vblanks,
    display_clear_image,
    display_get_screen_size,
    display_set_sync_mode,
    display_set_vsync_callback,
};

display_t *display_create(void) {
    display_t *allocated = ALLOCATE_STRUCT(display_t);

    if (allocated) {
        display_vtable_t *vtable = display_get_vtable();
        vtable->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void display_construct(display_t *This) {
    base_class_get_vtable()->Construct(This);
    This->vtable = display_get_vtable();
    This->vtable->display_reset(This);
}

void display_reset(display_t *This) {
    This->m_VSyncCount = 0;
    This->vtable->display_set_vblanks(This, 3);
    This->vtable->display_set_sync_mode(This, 1);
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
    GsSwapDispBuff();
}

s32 display_get_active_buffer(display_t *This) {
    return GsGetActiveBuff();
}

void display_load_image(display_t *This, s16 *Rect, s32 VramAddr) {
    u16 rect[4];

    if (!This->m_VSyncCount || This->m_SyncMode) {
        display_copy_rect(rect, Rect);
        LoadImage(rect, VramAddr);
        if (This->m_SyncMode) {
            DrawSync(0);
        }
    }
}

// Copy something to something, not on the vtable
void display_copy_rect(u16 *Dest, void *Src) {
    u16 *src;

    src = Src;
    Dest[0] = src[0];
    Dest[1] = src[1];
    Dest[2] = src[2];
    Dest[3] = src[4];
}

void display_store_image(display_t *This, s32 VramAddr, s16 *Rect) {
    u16 rect[4];

    if (!This->m_VSyncCount || This->m_SyncMode) {
        display_copy_rect(rect, Rect);
        StoreImage(rect, VramAddr);
        if (This->m_SyncMode) {
            DrawSync(0);
        }
    }
}

s32 display_get_status(display_t *This) {
    return 0;
}

void display_move_image(display_t *This, s16 *Rect, s16 X, s16 Y) {
    u16 rect[4];

    display_copy_rect(rect, Rect);
    MoveImage(rect, X, Y);
}

void display_do_vsync_internal(display_t *This) {
    void (*vsync_callback)();

    while (This->m_VSyncCount) {
        VSync(This->m_NextVBlank);
        vsync_callback = This->m_VsyncCallback;
        if (vsync_callback) {
            vsync_callback();
        }
        This->vtable->Notify(This, 2);
    }
}

// Advance the vblank timer and flag it once it has run for m_NextVBlank frames
void display_update_timer(display_t *This) {
    display_t *disp;
    s32 limit;
    s32 count;

    disp = get_display();
    limit = disp->m_NextVBlank;
    count = disp->m_TimerCount + 1;
    disp->m_TimerCount = count;
    if (count >= limit && !disp->m_TimerExpired) {
        disp->m_TimerExpired = 1;
        disp->m_TimerCount = 0;
    }
}

// Set the amount of vblanks to be waited for
void display_set_vblanks(display_t *This, s32 Count) {
    if (!This->m_VSyncCount) {
        This->m_NextVBlank = Count;
    }
}

// Get the amount of vblanks to be waited for?
s32 display_get_vblanks(display_t *This) {
    return This->m_NextVBlank;
}

void display_clear_image(display_t *This, unsigned char *Color, void *Rect) {
    unsigned char screen_rect[16];
    u16 clear_rect[4];

    if (!Rect) {
        This->vtable->display_get_screen_size(This, screen_rect);
        This->vtable->display_clear_image(This, Color, screen_rect);
    } else {
        display_copy_rect(clear_rect, Rect);
        ClearImage(clear_rect, *Color, Color[1], Color[2]);
    }
}

void *display_get_screen_size(display_t *This, void *OutRect) {
    vram_rect_t *out;

    if (OutRect) {
        out = OutRect;
        out->x = 0;
        out->y = 0;
        out->w = This->m_ScreenSize.x;
        out->h = 2 * This->m_ScreenSize.y;
    }
    return &This->m_ScreenSize;
}

void display_set_sync_mode(display_t *This, s32 Mode) {
    This->m_SyncMode = Mode;
}

void display_set_vsync_callback(display_t *This, void (*Callback)()) {
    This->m_VsyncCallback = Callback;
}

display_vtable_t *display_get_vtable(void) {
    return &g_DISPLAY_VTABLE;
}
