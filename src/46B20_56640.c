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
