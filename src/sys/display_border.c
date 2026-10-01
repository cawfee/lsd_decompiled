#include "common.h"

#include "sys/display.h"

void *get_display(void);

void func_8003B624(vram_rect_t *arg0, s32 count, vram_rect_t *arg2) {
    display_t *disp;
    void (*draw)(display_t *, s16 *, s32, s32);
    vram_rect_t rect;
    s32 i;

    disp = get_display();
    draw = (void (*)(display_t *, s16 *, s32, s32))disp->vtable->Unk24;
    if (count != 0) {
        for (i = 0; i < count; i++) {
            rect.x = arg0->x + arg0->w - 1;
            rect.y = arg0->y;
            rect.w = 1;
            rect.h = arg0->h;
            draw(disp, (s16 *)&rect, arg2->x, arg2->y);
            rect.x = arg0->x;
            rect.y = arg0->y;
            rect.w = arg0->w - 1;
            rect.h = arg0->h;
            draw(disp, (s16 *)&rect, arg0->x + 1, arg0->y);
            rect.x = arg2->x;
            rect.y = arg2->y;
            rect.w = 1;
            rect.h = arg0->h;
            draw(disp, (s16 *)&rect, arg0->x, arg0->y);
        }
    }
}
