#include "pad.h"
#include "base_class.h"

extern s32 D_8008A848;
extern s32 D_8008B388[];
extern s32 D_80010764[];

extern pad_vtable_t D_8006D370;

pad_t *pad_create(s32 Unk1, s32 Unk2) {
    pad_t *allocated = (pad_t *) memory_allocate_mem(0x20);

    if (allocated) {
        func_80025E9C()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void func_80025BA0(pad_t *This, s32 arg1, s32 arg2) {
    base_class_get_vtable()->base_class_construct(This);
    This->vtable = func_80025E9C();
    if (D_8008A848++ == 0) {
        PadInit(arg1);
    }
    ((void (*)(void *, s32))This->vtable->Unk15)(This, arg2);
}

void func_80025C30(pad_t *This) {
    D_8008A848--;

    if (!D_8008A848) {
        PadStop();
    }

    base_class_get_vtable()->base_class_cleanup(This);
}

void func_80025C84(pad_t *This, s32 Unk) {
    This->m_Unk2_1 = Unk != 0;
    This->m_Unk3 = 0;
  This->m_Unk4 = 0;
  This->m_Unk5 = 0;
  This->vtable->Unk19();
}

void func_80025CC4(pad_t *This) {
    s32 v2; // $v0
  s32 m_Unk3; // $a0

  v2 = PadRead(This->m_Unk2_1);
  m_Unk3 = This->m_Unk3;
  This->m_Unk3 = v2;
  This->m_Unk4 = (v2 ^ m_Unk3) & m_Unk3;
  This->m_Unk5 = (v2 ^ m_Unk3) & v2;
}

INCLUDE_ASM("asm/nonmatchings/pad", func_80025D10);

void func_80025E14(void) {
}

void func_80025E1C(void) {
    s32 sp[0x10];
    s32 *out;
    s32 *src;
    s32 i;

    out = D_8008B388;
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

pad_vtable_t *func_80025E9C(void) {
    return &D_8006D370;
}
