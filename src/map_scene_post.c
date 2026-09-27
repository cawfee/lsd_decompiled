#include "map_scene.h"
#include "scene.h"
#include "text_line.h"
#include "dream_sys.h"

extern map_scene_vtable_t **D_80087034;

extern s32 D_8008AB38;
extern s32 D_8008AB40;
extern char D_8008AB44[];

void func_80053EB4(map_scene_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4);
void func_8005C76C(void);
void func_80054D30(void);
s32 func_80052E7C(map_scene_t *This, s32 Unk1, s32 Unk2, s32 Unk3);

void func_800536B0(map_scene_t *This) {
    dream_sys_t *dream_sys;

    This->vtable->Unk52(This);
    dream_sys = This->m_Unk14;
    dream_sys->vtable->Unk62(dream_sys);
    dream_sys = This->m_Unk14;
    dream_sys->vtable->Unk19(dream_sys);
    (*(void (**)(void *))(*(s32 *)This->m_Unk5 + 0x74))(This->m_Unk5);
    This->vtable->Detach(This, This->m_Unk4);
}

void func_80053764(map_scene_t *This) {
    s32 sp10;
    void *obj5;
    s32 *link;
    s32 pick;
    void *created;
    s32 ret;
    s32 arg2;

    This->m_Unk25 = 1;
    This->m_Unk14->vtable->reset_motion_for_link(This->m_Unk14, This->m_Unk16, This->m_Unk15);
    (*(void (**)(void *))(*(s32 *)This->m_Unk4 + 0xEC))(This->m_Unk4);
    obj5 = This->m_Unk5;
    link = (s32 *)This->m_Unk19;
    (*(void (**)(void *, s32))(*(s32 *)obj5 + 0x60))(obj5, 1);
    (*(void (**)(void *, s32))(*(s32 *)obj5 + 0x64))(obj5, link[3]);
    (*(void (**)(void *, s32))(*(s32 *)obj5 + 0x6C))(obj5, link[7]);
    {
        s32 *vt;

        vt = *(s32 **)obj5;
        if (link[5] != 1) {
            pick = link[6];
        } else {
            pick = link[3];
        }
        (*(void (**)(void *, s32))((u8 *)vt + 0x68))(obj5, pick);
    }
    (*(void (**)(void *, s32))(*(s32 *)obj5 + 0xB0))(obj5, 0);
    (*(void (**)(void *, s32))(*(s32 *)obj5 + 0xB4))(obj5, 1);
    This->vtable->Attach(
        This, created = (*(void *(**)(void *))(*(s32 *)obj5 + 0xAC))(obj5));
    ret = This->m_Unk14->vtable->Unk59(This->m_Unk14, &sp10, -1);
    (*(void (**)(void *, s32, s32))(*(s32 *)created + 0xF0))(
        created, ret, -(ret != 0) & 3);
    {
        void *cvt;

        cvt = *(void **)created;
        arg2 = -1;
        if (ret != 0) {
            arg2 = sp10;
        }
        (*(void (**)(void *, void *, s32, s32))((u8 *)cvt + 0xD4))(
            created, This->m_Unk3, arg2, 0);
    }
}

s32 func_8005393C(map_scene_t *This) {
    s32 v1;

    v1 = (*(s32 (**)(void *, s32, s32))(*(s32 *)This->m_Unk4 + 0x10C))(This->m_Unk4, 0, 0);
    return func_800558F0(v1, 0, 0);
}

void func_80053984(map_scene_t *This, s32 Unk2, s32 Unk3) {
    if (This->m_Unk7 == 0) {
        switch (Unk3) {
        case 10:
            This->vtable->Unk36(This);
            break;
        case 12:
            This->vtable->Unk37(This);
            break;
        case 13:
            This->vtable->Unk38(This);
            break;
        case 14:
            This->vtable->Unk39(This);
            break;
        case 15:
            This->vtable->Unk40(This);
            break;
        case 16:
            This->vtable->Unk41(This);
            break;
        case 17:
            This->vtable->Unk42(This);
            break;
        }
    } else if (Unk3 >= 9) {
        This->m_Unk14->m_Unk16 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/map_scene_post", func_80053ACC);

void func_80053BE8(map_scene_t *This) {
    void (*callback)(void *);
    dream_sys_t *dream_sys;
    s32 v;

    if (This->m_Unk14->m_NextMap < 0) {
        callback = This->vtable->Unk38;
        callback(This);
    } else {
        This->m_Unk7 = 5;
        dream_sys = This->m_Unk14;
        v = dream_sys->vtable->dream_sys__get_dream_color(dream_sys);
        func_80053EB4(This, v, 0, 0xA, 1);
        dream_sys = This->m_Unk14;
        dream_sys->vtable->Unk62(dream_sys);
    }
}

void func_80053C94(map_scene_t *This) {
    dream_sys_t *dream_sys;

    This->m_Unk7 = 6;
    dream_sys = This->m_Unk14;
    func_80053EB4(This, dream_sys->vtable->dream_sys__get_dream_color(dream_sys), 0, 0x1E, 1);
    dream_sys = This->m_Unk14;
    dream_sys->vtable->Unk62(dream_sys);
}

void func_80053D18(map_scene_t *This) {
    s32 sp18;
    dream_sys_t *dream_sys;

    This->m_Unk7 = 7;
    dream_sys = This->m_Unk14;
    dream_sys->vtable->Unk59(dream_sys, &sp18, -1);
    func_80053EB4(This, sp18, 0, 5, 1);
    dream_sys = This->m_Unk14;
    dream_sys->vtable->Unk62(dream_sys);
}

void func_80053D9C(map_scene_t *This) {
    This->m_Unk7 = 8;
    func_80053EB4(This, 0, 0, 6, 1);
    This->m_Unk14->vtable->Unk60(This->m_Unk14, 1);
}

void func_80053E00(map_scene_t *This) {
    This->m_Unk7 = 0xA;
    func_80053EB4(This, 0, 0, 6, 1);
    This->m_Unk14->vtable->Unk78(This->m_Unk14, 2);
    This->m_Unk14->vtable->Unk60(This->m_Unk14, 2);
}

void func_80053E84(map_scene_t *This) {
    This->vtable->Notify(This, 11);
}

void func_80053EB4(map_scene_t *This, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *obj;
    void *created;

    obj = This->m_Unk5;
    created = (*(void *(**)(void *))(*(s32 *)obj + 0xAC))(obj);
    if (arg3 != 0) {
        (*(void (**)(void *, s32))(*(s32 *)created + 0xD0))(created, arg3);
    }
    if (arg4 != 0) {
        This->vtable->Attach(This, created);
    }
    (*(void (**)(void *, s32, s32, s32))(*(s32 *)created + 0xD8))(
        created, (s32)This->m_Unk3, arg1, arg2);
}

void func_80053F84(map_scene_t *This, dream_sys_t *arg1, s32 arg2) {
    s32 five;
    void *obj;
    s32 value;
    s32 state;

    five = 5;
    if (arg2 == five) {
        goto kind5;
    }
    if (arg2 == 6) {
        goto kind6;
    }
    return;
kind5:
    This->vtable->Detach(This, arg1);
    This->m_Unk14->vtable->Unk60(This->m_Unk14, 0);
    This->m_Unk7 = 0;
    return;
kind6:
    This->vtable->Detach(This, arg1);
    value = arg1->vtable->Unk56(arg1);
    obj = This->m_Unk5;
    ((void (*)(void *, s32))(*(u32 *)((u8 *)*(void **)obj + 0x64)))(obj, value);
    state = This->m_Unk7;
    if (state != five && state != 8 && state == 10) {
        This->m_Unk14->vtable->Unk94(This->m_Unk14, 1);
        This->m_Unk14->vtable->Unk60(This->m_Unk14, 0);
        This->m_Unk7 = 4;
    }
    This->vtable->Notify(This, This->m_Unk7);
}

void func_800540E8(map_scene_t *This, s32 Unk1, s32 Unk2) {
    if (Unk2 == 7) {
        This->vtable->Unk45(This, Unk1);
    }
}

s32 func_8005C7D4(s32, void *, s32);

s32 func_80054120(map_scene_t *This) {
    s32 sp10;
    void *obj;
    void *a;
    s32 v;
    s32 r;

    a = This->m_Unk4;
    obj = (*(void *(**)(void *, s32 *))(*(s32 *)a + 0x114))(a, &sp10);
    v = This->m_Unk14->vtable->get_day_number(This->m_Unk14, 0);
    r = func_8005C7D4(*(s32 *)(*(s32 *)((u8 *)obj + 4) + 0x34), &sp10, v);
    *(s32 *)((u8 *)obj + 0x14) = r;
    if (r != 0) {
        return 0;
    }
    a = *(void **)((u8 *)obj + 4);
    (*(void (**)(void *))(*(s32 *)a + 0x84))(a);
    return 1;
}

void func_800541CC(void) {
}

void func_800541D4(map_scene_t *This) {
    if (This->m_Unk31) {
        if (!This->m_Unk7) {
            This->m_Unk32 = 1;
        }
    }
}

void func_80054200(map_scene_t *This) {
    This->m_Unk32 = 0;
}

void func_80054208(map_scene_t *This) {
    if (This->m_Unk32) {
        This->vtable->Unk52(This);
        This->vtable->Notify(This, 0xD);
    }
}

void func_8005426C(map_scene_t *This) {
    if (This->m_Unk32) {
        This->vtable->Unk52(This);
        This->vtable->Notify(This, 0xC);
    }
}

void func_800542D0(map_scene_t *This) {
    s32 unk31;
    void *obj;

    unk31 = This->m_Unk31;
    if (unk31 == 0) {
        obj = func_800408CC(This->m_Unk28, 5, (s32)D_8008AB44);
        This->m_Unk30 = obj;
        (*(void (**)(void *, void *, s32 *))(*(s32 *)obj + 0x4C))(obj, This->m_Unk4, &D_8008AB38);
        obj = This->m_Unk30;
        (*(void (**)(void *, s32 *))(*(s32 *)obj + 0xB8))(obj, &D_8008AB40);
        This->m_Unk31 = 1;
        return;
    }
    This->m_Unk31 = unk31 + 1;
    if (unk31 == 4) {
        obj = This->m_Unk5;
        (*(void (**)(void *, s32))(*(s32 *)obj + 0xB4))(obj, 0);
        obj = This->m_Unk3;
        (*(void (**)(void *))(*(s32 *)obj + 0x4C))(obj);
        obj = This->m_Unk20;
        (*(void (**)(void *))(*(s32 *)obj + 0x4C))(obj);
        obj = This->m_Unk12;
        (*(void (**)(void *))(*(s32 *)obj + 0x88))(obj);
    }
}

void func_800543FC(map_scene_t *This) {
    void *obj;

    if (This->m_Unk31 != 0) {
        obj = This->m_Unk30;
        (*(void (**)(void *))(*(s32 *)obj + 4))(obj);
    }
    obj = This->m_Unk12;
    (*(void (**)(void *))(*(s32 *)obj + 0x8C))(obj);
    obj = This->m_Unk20;
    (*(void (**)(void *))(*(s32 *)obj + 0x50))(obj);
    obj = This->m_Unk3;
    (*(void (**)(void *))(*(s32 *)obj + 0x50))(obj);
    obj = This->m_Unk5;
    (*(void (**)(void *, s32))(*(s32 *)obj + 0xB4))(obj, 1);
    This->m_Unk31 = 0;
}

map_scene_vtable_t *func_800544D4(void) {
    return &D_80087034;
}
