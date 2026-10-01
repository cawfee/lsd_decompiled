#include "common.h"

s32 func_80020510(s32 arg0, s16 *arg1);

extern s16 D_8008AB94[];
extern s32 D_8008AB98[];
extern void *D_8008ACA4;
extern s32 D_8008ACA8;
extern void *D_8008ACAC;

void generation_apply_context(s32 Unk1, void *obj, s32 Unk2, s32 Unk3) {
    s32 i;
    s32 *src;

    D_8008ACA4 = obj;
    D_8008ACA8 = Unk2;
    D_8008ACAC = Unk3;
    i = 0;
    src = D_8008AB98;
    do {
        func_80020510((*(s32(**)(void *, s32))((u8 *) *(void **) obj + 0x80))(obj, *src), D_8008AB94);
        src++;
        i++;
    } while (i < 2);
}
