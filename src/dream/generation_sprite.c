#include "dream/generation_sprite.h"

void *func_800422BC(void);

extern generation_sprite_vtable_t D_800879C4;

extern u8 D_80087A8C[];
extern s16 D_80087AA4[];
extern s32 D_80087AA6[];

generation_sprite_t *func_80057C94(s32 Unk1, s32 Unk2, s32 Unk3) {
    generation_sprite_t *allocated = (generation_sprite_t *) memory_allocate_mem(0xA8);

    if (allocated) {
        func_80057F58()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_80057D10(generation_sprite_t *This, s32 arg1, s32 arg2, s32 arg3) {
    (*(void (**)(void *, s32, s32, void *, s32, s32))((s32)func_800422BC() + 8))(
        This, arg3, 0, &D_80087A8C[arg1 * 0xC], arg2, 0);
    This->vtable = func_80057F58();
    This->m_Unk40 = 0;
    ((void (*)(void *, s32))This->vtable->Unk15)(This, arg1);
}

void func_80057DBC(generation_sprite_t *This, s32 Unk) {
    This->m_Unk39 = Unk;
    This->m_Unk28_1 = D_80087AA4[Unk * 2];
    This->m_Unk28_2 = D_80087AA6[Unk];
}

void func_80057DF4(generation_sprite_t *This, s32 arg1, s16 *arg2) {
    s16 x;
    s16 y;
    s32 q;
    s32 r;

    q = arg2[0] / arg2[1];
    r = arg2[0] % arg2[1];
    x = (q << 12) + ((r << 12) / arg2[1]);
    q = arg2[2] / arg2[3];
    r = arg2[2] % arg2[3];
    y = (q << 12) + ((r << 12) / arg2[3]);
    if (This->m_Unk21 != 0) {
        This->m_Unk22 = (x * This->m_Unk22) >> 12;
        This->m_Unk23 = (y * This->m_Unk23) >> 12;
    } else {
        *(s16 *)((u8 *)This + 0x80) = x;
        *(s16 *)((u8 *)This + 0x82) = y;
    }
}

void func_80057F38(void) {
}

void func_80057F40(void) {
}

void func_80057F48(void) {
}

void func_80057F50(void) {
}

generation_sprite_vtable_t *func_80057F58(void) {
    return &D_800879C4;
}
