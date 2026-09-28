#include "46B20.h"
#include "477E4.h"

extern class_46B20_vtable_t D_800876FC;

class_46B20_t *func_80056320(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    class_46B20_t *allocated = (class_46B20_t *) memory_allocate_mem(0x98);

    if (allocated) {
        class_46B20_vtable_t *vtable = func_80056F4C();

        if (vtable->Construct(allocated, Unk1, Unk2, Unk3, Unk4)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

void *func_800563C0(class_46B20_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    class_46B20_vtable_t *vtable;

    if (func_80057C84()->Construct(This)) {
        This->vtable = func_80056F4C();

        This->m_Unk16 = 0;
        This->m_Unk20 = Unk1;
        This->vtable->Unk15(This, Unk2);

        func_80056520(This, Unk3, Unk4);
        return This;
    }

    return NULL;
}

void func_80056464(class_46B20_t *This) {
    func_80056718();
    func_80057C84()->Cleanup(This);
}

void func_800564A4(class_46B20_t *This, s32 *Unk) {
    __builtin_memcpy(&This->m_Unk21, Unk, 36);
    This->m_Unk8 = 0;
}

void func_800564F4(class_46B20_t *This, s32 Unk1) {
    ++This->m_Unk8;
    func_80056640(This, Unk1);
}

#include "46B20.h"

extern void *D_8008ACAC;
extern s32 D_8008ACB0;
extern void *D_8008ACA4;
extern s32 D_8008AB98[];

void func_80056794(class_46B20_t *This, s32 *Unk1, s32 *Unk2);
void func_800567D4(class_46B20_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4);
void func_80056858(class_46B20_t *This, s32 arg1);
void func_800569A8(class_46B20_t *This, s32 Unk1);
void func_80056BBC(class_46B20_t *This, s32 Unk1);
void func_80056DF0(void);
void func_80056E1C(class_46B20_t *This);
void func_80056E44(class_46B20_t *This);
void func_8001E770(void *obj, s32 arg);

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} func_80056640_vec_t;

void func_80056520(class_46B20_t *This, s32 Unk1, s32 Unk2) {
    func_80056640_vec_t local;
    s32 mode;
    void *obj;
    s32 (*method)(void *, s32);

    D_8008ACB0 = *(s32 *)((u8 *)D_8008ACAC + 0x18);
    func_80056794((class_46B20_t *)&local, (s32 *)Unk2, &This->m_Unk21);
    func_800567D4(This, Unk1, (s32)&local, This->m_Unk24, This->m_Unk25);
    mode = This->m_Unk20;
    if (mode < 2) {
        obj = D_8008ACA4;
        method = *(s32 (**)(void *, s32))((u8 *)*(void **)obj + 0x80);
        func_8001E770(This, method(obj, D_8008AB98[mode]));
        mode = This->m_Unk20;
    }
    switch (mode) {
    case 0:
        func_80056858(This, 0);
        return;
    case 2:
        func_80056BBC(This, 0);
        return;
    case 3:
        ((void (*)(class_46B20_t *, s32))func_80056E1C)(This, 0);
        return;
    }
}

void func_80056640(class_46B20_t *This, s32 Unk1) {
    func_80056640_vec_t local;
    s32 mode;

    func_80056794((class_46B20_t *)&local, (s32 *)Unk1, &This->m_Unk21);
    local.y += *(s32 *)((u8 *)D_8008ACAC + 0x18) - D_8008ACB0;
    This->vtable->Unk45(This, &local);
    mode = This->m_Unk20;
    switch (mode) {
    case 0:
        func_800569A8(This, Unk1);
        return;
    case 2:
        ((void (*)(class_46B20_t *, s32))func_80056DF0)(This, Unk1);
        return;
    case 3:
        ((void (*)(class_46B20_t *, s32))func_80056E44)(This, Unk1);
        return;
    }
}

#include "46B20.h"
#include "477E4.h"

#include <psx/rand.h>

extern s32 D_8008780C[4];
extern s32 D_8008782C[];
extern s32 D_80087838;

void func_80056718(class_46B20_t *This) {
    switch (This->m_Unk20) {
        case 0:
            func_80056B8C(This);
            break;

        case 2:
            func_80056DF8(This);
            return;

        case 3:
            func_80056F28(This);
            return;

        default:
            break;
    }
}

void func_80056794(class_46B20_t *This, s32 *Unk1, s32 *Unk2) {
    This->vtable = (class_46B20_vtable_t *) (*Unk1 + *Unk2);
    This->m_Unk0 = Unk1[1] + Unk2[1];
    This->m_Unk1 = Unk1[2] + Unk2[2];
}

void func_800567D4(class_46B20_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    This->vtable->Unk18(This, Unk1, Unk2);
    This->vtable->Unk16(This, 1, Unk3);
    This->vtable->Unk17(This, 1, Unk4);
}

extern s32 D_800877EC[];
extern s32 D_800877F8[];
void func_8001E770(void *obj, s32 arg);
class_477E4_t *func_80056FE4(void);

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} func_80056858_vec_t;

void func_80056858(class_46B20_t *This, s32 arg1) {
    func_80056858_vec_t local;
    class_477E4_t **slot;
    s32 mode;
    s32 *scale;
    s32 *table;
    s32 i;
    s16 *half;
    class_477E4_t *obj;

    mode = This->m_Unk26;
    if (mode == 0) {
        return;
    }
    local = *(func_80056858_vec_t *)D_800877EC;
    slot = (class_477E4_t **)&This->m_Unk30;
    i = 0;
    table = D_800877F8;
    scale = table + mode;
    do {
        if (mode < 3) {
            half = (s16 *)This->m_Unk25;
            local.x += half[0] * scale[0];
        } else {
            local.y += scale[0];
        }
        if (arg1 != 0) {
            obj = *slot;
            obj->vtable->Unk45(obj, &local);
        } else {
            *slot = func_80056FE4();
            func_8001E770(*slot, This->m_Unk7);
            func_800567D4((class_46B20_t *)*slot, (s32)This, (s32)&local, This->m_Unk24, This->m_Unk25);
        }
        i += 1;
        slot += 1;
    } while (i < 2);
}

INCLUDE_ASM("asm/nonmatchings/46B20", func_800569A8);

void func_80056B8C(class_46B20_t *This) {
    s32 m_Unk26;
    s32 *p_m_Unk30;

    m_Unk26 = This->m_Unk26;
    p_m_Unk30 = &This->m_Unk30;
    if (m_Unk26) {
        destroy_list(p_m_Unk30, 2);
    }
}

extern s32 D_80087844[];
extern s32 D_8008785C[];
extern s32 D_80087868[];
extern s32 D_80087874[];
extern s32 D_80087880[3];
void func_800573A8(class_477E4_t *This, void *Unk);

void func_80056BBC(class_46B20_t *This, s32 unused) {
    s32 parity;
    s32 *extra;
    class_477E4_t *obj;
    s32 mode;
    s32 arg;
    s32 *table;
    class_477E4_vtable_t *vt;

    parity = rand() % 2;
    extra = NULL;
    if (parity == 0) {
        extra = D_80087868;
    }
    func_80056D18(This, 0, 0, (s32)extra);
    mode = This->m_Unk27;
    arg = 1;
    if (mode < 2) {
        goto low;
    }
    obj = (class_477E4_t *)This->m_Unk33;
    {
        s32 *p = D_80087880;
        *p = D_80087844[mode];
        func_800573A8(obj, p);
    }
    arg = This->m_Unk29;
    vt = obj->vtable;
    if (arg == 0) {
        arg = This->m_Unk28;
    }
    vt->Unk45(obj, (void *)arg);
    goto end;
low:
    obj = (class_477E4_t *)This->m_Unk33;
    ((void (*)(void *, s32))obj->vtable->Unk24)(obj, arg);
    ((void (*)(void *, s32))obj->vtable->Unk25)(obj, 0);
    table = D_80087874;
    vt = obj->vtable;
    if (parity != 0) {
        table = D_8008785C;
    }
    ((void (*)(void *, s32, s32 *))vt->Unk17)(obj, 1, table);
end:
    ((class_477E4_t *)This->m_Unk34)->vtable->Unk23((class_477E4_t *)This->m_Unk34, 0);
}

#include "46B20.h"
#include "48494.h"

extern s32 D_8008ACA8;

void func_80056D18(class_46B20_t *This, s32 unused, s32 arg2, s32 arg3) {
    class_48494_t **slot;
    s32 i;

    slot = (class_48494_t **)&This->m_Unk32;
    i = 0;
    do {
        *slot = func_80057C94(arg2, 0, D_8008ACA8);
        ((void (*)(void *, void *, s32))(*slot)->vtable->Unk18)(*slot, This, 0);
        ((void (*)(void *, s32))(*slot)->vtable->Unk45)(*slot, This->m_Unk28);
        if (arg3 != 0) {
            ((void (*)(void *, s32, s32))(*slot)->vtable->Unk17)(*slot, 1, arg3);
        }
        i += 1;
        slot += 1;
    } while (i < 5);
}

#include "46B20.h"

#include <psx/rand.h>

extern class_46B20_vtable_t D_800876FC;

void func_80056DF0(void) {
}

void func_80056DF8(class_46B20_t *This) {
    destroy_list(&This->m_Unk32, 5);
}

void func_80056E1C(class_46B20_t *This) {
    func_80056D18(This, 0, 0, 0);
}

extern s32 D_8008788C[];

void func_80056E44(class_46B20_t *This) {
    class_46B20_t **slot;
    s32 i;
    s32 which;

    slot = (class_46B20_t **)&This->m_Unk33;
    i = 0;
    do {
        i++;
        which = (s32)&D_8008788C[((u32)rand() % 6) * 3];
        slot[0]->vtable->Unk17(slot[0], 1, which);
        slot[0]->m_Unk32 = (rand() % 360) << 12;
        slot++;
    } while (i < 4);
}

void func_80056F28(class_46B20_t *This) {
    destroy_list(&This->m_Unk32, 5);
}

class_46B20_vtable_t *func_80056F4C(void) {
    return &D_800876FC;
}
