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

map_scene_t *map_scene_create(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    map_scene_t *allocated = (map_scene_t *) memory_allocate_mem(0x88);

    if (allocated) {
        func_800544D4()->Construct(allocated, Unk1, Unk2, Unk3, Unk4, Unk5);
        return allocated;
    }

    return NULL;
}

void func_80052C10(map_scene_t *This, int Unk2, int Unk3, int Unk4, int Unk5, int Unk6) {
    func_8004A4B8()->Construct(This, 0, Unk2);
    This->vtable = func_800544D4();
    This->m_Unk24 = 0;
    This->m_Unk25 = 0;
    This->m_Unk23 = 1;
    This->m_Unk20 = (void *)Unk3;
    This->m_Unk13 = Unk6;
    This->m_Unk26 = Unk2;
    This->m_Unk28 = Unk4;
    This->m_Unk27 = Unk5;
    This->m_Unk31 = 0;
    This->m_Unk32 = 0;
    This->vtable->Unk15(This);
}

void func_80052CD8(map_scene_t *This) {
    func_8004A4B8()->Cleanup(This);
}

void func_80052D10(map_scene_t *This, void **Unk2, s32 Unk3) {
    s32 value;

    func_8004A4B8()->Unk13(This, Unk2, Unk3);
    value = *(s32 *) *Unk2;

    if ((value & 0xFFF) == 0x114) {
        This->vtable->Unk44(This, Unk2, Unk3);
    } else if ((value & 0xFFF) == 0x164) {
        This->vtable->Unk43(This, Unk2, Unk3);
    } else if ((value & 0xFFFF) == 0x1F34) {
        This->vtable->Unk35(This, Unk2, Unk3);
    }
}

void func_80052DE0(void) {
}

void func_80052DE8(map_scene_t *This, void *arg1, s32 arg2) {
    void *obj;

    obj = *(void **)((u8 *)arg1 + 0xC);
    (*(void (**)(void *, s32 (*)(map_scene_t *, s32, s32, s32), void *))(*(s32 *)obj + 0xC8))(
        obj, func_80052E7C, This);
    This->m_Unk14 = (dream_sys_t *)arg2;
    func_8004A4B8()->scene_run(This, arg1, 1);
    This->vtable->Unk3(This, (void *)arg2);
}

s32 func_80052E7C(map_scene_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    if (Unk1 < 0) {
        return func_80049098(This->m_Unk13, Unk2, Unk3);
    } else {
        return func_80049060(This->m_Unk13, Unk1);
    }
}

void func_80052EBC(map_scene_t *This) {
    This->vtable->Unk4(This, This->m_Unk14);
    func_8004A4B8()->Unk17(This);
}

INCLUDE_ASM("asm/nonmatchings/map_scene", func_80052F10);

void func_80053134(map_scene_t *This) {
    This->vtable->Unk32(This);
    func_8005C76C();
    func_80054D30();
    (*(void (**)(void *))(*(s32 *)This->m_Unk20 + 0x48))(This->m_Unk20);
}

void func_800531A0(map_scene_t *This, s32 Unk1, s32 Unk2) {
    if (Unk2 == 2) {
        func_800531CC(This, This->m_Unk21);
    }
}

void func_800531CC(map_scene_t *This, dream_sys_t *arg1) {
    s32 *link;
    s32 picked;
    s32 limit;
    s32 two;
    dream_sys_vtable_t *vt;

    if (This->m_Unk23 == 0) {
        goto tail;
    }
    if (arg1->m_Unk31 == 0) {
        goto other;
    }
    arg1->vtable->base_class_destructor(arg1);
    This->m_Unk23 = 0;
    This->vtable->Unk31(This);
    limit = This->m_Unk14->vtable->Unk65(This->m_Unk14);
    This->m_Unk14->vtable->dream_sys__get_set_dream_time_limit(This->m_Unk14, limit + 0x1E);
    goto check;
other:
    if (arg1->m_Unk14 == 0) {
        goto check;
    }
    two = 2;
    link = (s32 *)This->m_Unk19;
    vt = arg1->vtable;
    if (link[5] != two) {
        picked = link[6];
    } else {
        picked = link[3];
    }
    vt->Unk30(arg1, picked);
    arg1->vtable->base_class_destructor(arg1);
    This->m_Unk23 = 0;
    This->vtable->Unk31(This);
check:
    if (This->m_Unk23 != 0) {
        return;
    }
tail:
    if (*(u16 *)((u8 *)This->m_Unk4 + 0x1B4) != 0) {
        return;
    }
    if (This->m_Unk25 != 0) {
        return;
    }
    This->m_Unk24 = 1;
    This->vtable->Unk33(This);
}

void func_80053358(map_scene_t *This, s32 arg1, s32 arg2) {
    void (*callback)(void *);
    map_scene_vtable_t *vt;

    vt = This->vtable;
    if (This->m_Unk25 != 0) {
        switch (arg2) {
        case 0x21:
            callback = vt->Unk28;
            goto call;
        case 0xC:
            callback = vt->Unk47;
            goto call;
        case 0x16:
            callback = vt->Unk49;
            goto call;
        case 0x2C:
            callback = vt->Unk48;
        call:
            callback(This);
            break;
        }
    }
}

void func_800533F0(map_scene_t *This) {
    if (This->m_Unk25) {
        This->m_Unk6++;
        if (This->m_Unk31) {
            This->vtable->Unk51(This);
        } else {
            This->vtable->Unk34(This);
        }
    }
}

void func_80053458(map_scene_t *This) {
    map_scene_vtable_t *vt;

    vt = This->vtable;
    if (This->m_Unk31) {
        vt->Unk48(This);
        vt->Unk52(This);
    } else {
        vt->Unk51(This);
    }
}

void func_800534C0(void) {
}

INCLUDE_ASM("asm/nonmatchings/map_scene", func_800534C8);

void func_800536B0(map_scene_t *This) {
    dream_sys_t *dream_sys;

    This->vtable->Unk52(This);
    dream_sys = This->m_Unk14;
    dream_sys->vtable->Unk62(dream_sys);
    dream_sys = This->m_Unk14;
    dream_sys->vtable->Unk19(dream_sys);
    (*(void (**)(void *))(*(s32 *)This->m_Unk5 + 0x74))(This->m_Unk5);
    This->vtable->Unk4(This, This->m_Unk4);
}

INCLUDE_ASM("asm/nonmatchings/map_scene", func_80053764);


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

INCLUDE_ASM("asm/nonmatchings/map_scene", func_80053ACC);

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
    This->vtable->Unk11(This, 11);
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
        This->vtable->Unk3(This, created);
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
    This->vtable->Unk4(This, arg1);
    This->m_Unk14->vtable->Unk60(This->m_Unk14, 0);
    This->m_Unk7 = 0;
    return;
kind6:
    This->vtable->Unk4(This, arg1);
    value = arg1->vtable->Unk56(arg1);
    obj = This->m_Unk5;
    ((void (*)(void *, s32))(*(u32 *)((u8 *)*(void **)obj + 0x64)))(obj, value);
    state = This->m_Unk7;
    if (state != five && state != 8 && state == 10) {
        This->m_Unk14->vtable->Unk94(This->m_Unk14, 1);
        This->m_Unk14->vtable->Unk60(This->m_Unk14, 0);
        This->m_Unk7 = 4;
    }
    This->vtable->Unk11(This, This->m_Unk7);
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
        This->vtable->Unk11(This, 0xD);
    }
}

void func_8005426C(map_scene_t *This) {
    if (This->m_Unk32) {
        This->vtable->Unk52(This);
        This->vtable->Unk11(This, 0xC);
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
