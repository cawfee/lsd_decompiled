#include "map_scene.h"
#include "scene.h"
#include "text_line.h"
#include "dream_sys.h"

extern map_scene_vtable_t **D_80087034;

extern s32 D_8008AB38;
extern s32 D_8008AB40;
extern char D_8008AB44[];
extern s32 D_80087118[];
extern s32 D_80087150[];
extern s32 D_8008715C[];
extern s32 D_80087168[];

void func_80053EB4(map_scene_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4);
void func_8005C76C(void);
void func_80054D30(void);
s32 func_80052E7C(map_scene_t *This, s32 Unk1, s32 Unk2, s32 Unk3);

const char *get_random_stage_texture_path(s32 arg0, s32 seed_arg, s32 count);
const char *get_stage_music_path(s32 arg0, s32 unused);
void *func_80043008(s32 Unk1, s32 Unk2);
s32 func_800544E4(void *a0, s32 a1, s32 *a2, s32 a3, s32 a4);
void func_8001EF60(s32 arg);

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

    func_8004A4B8()->OnNotify(This, Unk2, Unk3);
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
    This->vtable->Attach(This, (void *)arg2);
}

s32 func_80052E7C(map_scene_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    if (Unk1 < 0) {
        return get_stage_model_path_by_grid(This->m_Unk13, Unk2, Unk3);
    } else {
        return get_stage_model_path(This->m_Unk13, Unk1);
    }
}

void func_80052EBC(map_scene_t *This) {
    This->vtable->Detach(This, This->m_Unk14);
    func_8004A4B8()->Unk17(This);
}

void func_80052F10(map_scene_t *This, s32 arg1, s32 arg2, s32 arg3) {
    void *obj5;
    s32 flag;
    s32 stage;

    obj5 = This->m_Unk5;
    (*(void (**)(void *))(*(s32 *)obj5 + 0x74))(obj5);
    This->m_Unk23 = 1;
    (*(void (**)(void *, const char *))(*(s32 *)This->m_Unk20 + 0x5C))(
        This->m_Unk20, get_stage_music_path(This->m_Unk13, 0));
    This->m_Unk21 = (s32)((void *(*)(s32))func_80043008)((s32)get_random_stage_texture_path(
        This->m_Unk13, 0, This->m_Unk14->vtable->get_day_number(This->m_Unk14, 0)));
    (*(void (**)(void *, dream_sys_t *, s32 *, s32 *, s32))(*(s32 *)obj5 + 0x70))(
        obj5, This->m_Unk14, D_8008715C, D_80087168, 0);
    This->m_Unk29 = (s32)obj5;
    This->m_Unk19 = func_800544E4(
        This->m_Unk4, This->m_Unk13, &This->m_Unk26,
        This->m_Unk14->vtable->get_day_number(This->m_Unk14, 0), 0);
    if (arg2 != 0) {
        This->m_Unk19 = arg2;
    }
    This->m_Unk18 = arg3;
    if (This->m_Unk13 != 0) {
        This->m_Unk15 = 0x10;
        stage = This->m_Unk13;
        flag = stage == 5;
        This->m_Unk16 = 3;
        if (stage == 6) {
            flag = 1;
        }
        if (stage == 3) {
            flag = 1;
        }
        (*(void (**)(void *, s32 *))(*(s32 *)This->m_Unk4 + 0x134))(This->m_Unk4, NULL);
    } else {
        This->m_Unk15 = 0x10;
        This->m_Unk16 = 2;
        flag = 1;
        (*(void (**)(void *, s32 *))(*(s32 *)This->m_Unk4 + 0x134))(This->m_Unk4, D_80087150);
    }
    This->m_Unk17 = arg1;
    if (arg1 == 0) {
        This->m_Unk17 = 0xA000;
    }
    func_8001EF60(flag);
    This->m_Unk14->vtable->Unk58(This->m_Unk14, D_80087118[This->m_Unk13]);
    This->m_Unk7 = 5;
}

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
    arg1->vtable->Destroy(arg1);
    This->m_Unk23 = 0;
    This->vtable->Unk31(This);
    limit = This->m_Unk14->vtable->dream_sys_get_elapsed_seconds(This->m_Unk14);
    This->m_Unk14->vtable->dream_sys_get_set_dream_time_limit(This->m_Unk14, limit + 0x1E);
    goto check;
other:
    if (arg1->m_Unk14 == 0) {
        goto check;
    }
    two = 2;
    link = This->m_Unk19;
    vt = arg1->vtable;
    if (link[5] != two) {
        picked = link[6];
    } else {
        picked = link[3];
    }
    vt->Unk30(arg1, picked);
    arg1->vtable->Destroy(arg1);
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

#include "map_scene.h"
#include "dream_sys.h"
#include "stage_grid.h"

extern s32 D_8008AB34;
extern s32 D_8008715C[];
extern s32 D_80087168[];
extern s32 D_8008710C[];

void func_8005C650(s32, void *, dream_sys_t *, void *, void *);

void func_800534C8(map_scene_t *This) {
    void *obj5;
    s32 *link;
    void *inner;
    s32 *valp;
    s32 scaled;
    void *obj4;

    obj5 = This->m_Unk5;
    link = (s32 *)This->m_Unk19;
    (*(void (**)(void *))(*(s32 *)obj5 + 0x74))(obj5);
    inner = *(void **)(void *)This->m_Unk2;
    valp = (*(s32 * (**)(void *, s32))(*(s32 *)inner + 0x7C))(inner, 0);
    scaled = (((*valp / 2) * 5) / 3) + D_8008AB34;
    (*(void (**)(void *, s32))(*(s32 *)obj5 + 0x54))(obj5, scaled);
    (*(void (**)(void *, dream_sys_t *, s32 *, s32 *, s32))(*(s32 *)obj5 + 0x70))(
        obj5, This->m_Unk14, D_8008715C, D_80087168, 0);
    func_8005C650(This->m_Unk13, This->m_Unk4, This->m_Unk14, This->m_Unk12, This->m_Unk3);
    obj4 = This->m_Unk4;
    This->vtable->Attach(This, obj4);
    (*(void (**)(void *, s32, s32))(*(s32 *)obj4 + 0xBC))(obj4, link[2], 0);
    (*(void (**)(void *, s32, s32, s32))(*(s32 *)obj4 + 0xC4))(obj4, 3, link[0], link[1]);
    (*(void (**)(void *, void *))(*(s32 *)obj4 + 0xE0))(
        obj4, stage_grid_get_dimension(This->m_Unk13));
    This->m_Unk14->vtable->dream_sys_unk18(This->m_Unk14, obj4);
    (*(void (**)(void *, s32))(*(s32 *)obj4 + 0xDC))(obj4, This->m_Unk17);
    (*(void (**)(void *, s32 *))(*(s32 *)obj4 + 0xCC))(obj4, D_8008710C);
}
