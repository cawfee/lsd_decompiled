#include <psx/libgs.h>
#include "file/tim_image.h"
#include "file/file_buf.h"
#include "sys/display.h"
#include "base/memory.h"
extern tim_image_vtable_t g_TIM_IMAGE_VTABLE;
extern display_t *get_display(void);
tim_image_t *tim_image_create(const char *Unk1) {
    tim_image_t *allocated = (tim_image_t *) memory_allocate_mem(0x50);
    if (allocated) {
        tim_image_get_vtable()->Construct(allocated, Unk1);
        return allocated;
    }
    return NULL;
}
void tim_construct(tim_image_t *This, s32 Unk) {
    void *unk_class = get_file_driver();
    (*(void (**)(tim_image_t *))(unk_class + 8))(This);
    This->vtable = tim_image_get_vtable();
    This->m_MaybeLoaded = 0;
    This->unk19 = 0;
    if (Unk) {
        This->vtable->Unk11(This, Unk);
    }
}
void func_8003B470(tim_image_t *This) {
    void *unk = get_file_driver();
    (*(void (**)(tim_image_t *))(unk + 12))(This);
}

/*
 * vtable slot 0x78 (Unk14): parse the TIM via slot 0x9C (tim_get_info ->
 * GsGetTimInfo) into This->m_TimInfo, then upload the image rect and, when
 * pmode bit 3 is set, the clut rect to VRAM through display vtable slot 0x58
 * (display_load_image).
 */
void func_8003B4A8(tim_image_t *This) {
    display_t *display = get_display();
    vram_rect_t rect;
    gs_image_t *info = &This->m_TimInfo;

    if (This->m_Image != 0) {
        This->vtable->Unk23(This, info);
        rect.x = This->m_TimInfo.px;
        rect.y = This->m_TimInfo.py;
        rect.w = This->m_TimInfo.pw;
        rect.h = This->m_TimInfo.ph;
        display->vtable->display_load_image(display, (s16 *)&rect, (s32)This->m_TimInfo.pixel);
        if ((This->m_TimInfo.pmode >> 3) & 1) {
            rect.x = This->m_TimInfo.cx;
            rect.y = This->m_TimInfo.cy;
            rect.w = This->m_TimInfo.cw;
            rect.h = This->m_TimInfo.ch;
            display->vtable->display_load_image(display, (s16 *)&rect, (s32)This->m_TimInfo.clut);
        }
    }
}

void func_8003B5AC(void) {}
void func_8003B5B4(void) {}
void func_8003B5BC(void) {}
void func_8003B5C4(void) {}
void func_8003B5CC(void) {}
void func_8003B5D4(void) {}
void func_8003B5DC(void) {}
void tim_image_set_loaded(tim_image_t *This) { This->m_MaybeLoaded = 1; }
void tim_get_info(tim_image_t *This, void *TIMData) {
    GsGetTimInfo((unsigned long *) (This->m_Image + 4), TIMData);
}
tim_image_vtable_t *tim_image_get_vtable(void) { return &g_TIM_IMAGE_VTABLE; }
