#include "sys/pad.h"
#include "base/base.h"

extern s32 g_PadInitRefCount;
extern s32 g_PadState[];
extern s32 D_80010764[];

extern pad_vtable_t g_PAD_VTABLE;

pad_t *pad_create(s32 Unk1, s32 Unk2) {
    pad_t *allocated = ALLOCATE_STRUCT(pad_t);

    if (allocated) {
        pad_get_vtable()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void pad_construct(pad_t *This, s32 arg1, s32 arg2) {
    base_class_get_vtable()->Construct(This);
    This->vtable = pad_get_vtable();
    if (g_PadInitRefCount++ == 0) {
        PadInit(arg1);
    }
    ((void (*)(void *, s32)) This->vtable->Unk15)(This, arg2);
}

void pad_cleanup(pad_t *This) {
    g_PadInitRefCount--;

    if (!g_PadInitRefCount) {
        PadStop();
    }

    base_class_get_vtable()->Cleanup(This);
}

void pad_set_port(pad_t *This, s32 Unk) {
    This->m_Port = Unk != 0;
    This->m_Buttons = 0;
    This->m_Released = 0;
    This->m_Pressed = 0;
    This->vtable->Unk19();
}

void pad_poll(pad_t *This) {
    s32 v2;          // $v0
    s32 old_buttons; // $a0

    v2 = PadRead(This->m_Port);
    old_buttons = This->m_Buttons;
    This->m_Buttons = v2;
    This->m_Released = (v2 ^ old_buttons) & old_buttons;
    This->m_Pressed = (v2 ^ old_buttons) & v2;
}

void func_80025D10(pad_t *This) {
    s32 buf[0x10];
    s32 *p;
    s32 i;
    s32 buttons;
    s32 released;
    s32 pressed;
    void (*notify)(base_class_t *, s32);

    buttons = This->m_Buttons;
    released = This->m_Released;
    pressed = This->m_Pressed;

    if (buttons != 0 || released != 0 || pressed != 0) {
        p = buf;
        i = 0;
        do {
            s32 code = -1;
            s32 state = g_PadState[i];

            if (released & state) {
                code = 0x22;
            } else if (pressed & state) {
                code = 0x12;
            } else if (buttons & state) {
                code = 2;
            }
            if (code >= 0) {
                *p++ = code + i;
            }
            i++;
        } while (i < 0x10);

        p--;
        notify = This->vtable->Notify;
        if ((u32) p >= (u32) buf) {
            do {
                notify((base_class_t *) This, *p);
                p--;
            } while ((u32) p >= (u32) buf);
        }
    }
}

void func_80025E14(void) {
}

void pad_load_default_table(void) {
    s32 sp[0x10];
    s32 *out;
    s32 *src;
    s32 i;

    out = g_PadState;
    __builtin_memcpy(sp, D_80010764, 0x40);
    i = 0;
    src = sp;
    do {
        s32 v = *src;
        src += 1;
        i += 1;
        *out = v;
        out += 1;
    } while (i < 0x10);
}

void func_80025E94(void) {
}

pad_vtable_t *pad_get_vtable(void) {
    return &g_PAD_VTABLE;
}
