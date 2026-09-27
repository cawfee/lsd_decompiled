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

INCLUDE_ASM("asm/nonmatchings/46B20_tail", func_800569A8);

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
extern s32 D_80087880;
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
        s32 *p = &D_80087880;
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
