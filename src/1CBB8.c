#include "1CBB8.h"

extern class_1CBB8_vtable_t g_CLASS_1CBB8_VTABLE;

extern s32 D_8008A8B0;
extern s32 D_8008A8B4;

s32 func_8002C3B8(void) {
    return 0;
}

void class_1CBB8_construct(void) {
}

void class_1CBB8_cleanup(void) {
}

void class_1CBB8_unk15(void) {
    s8 pad[0x40];
}

void class_1CBB8_unk16(void) {
    s8 pad[0x40];
}

void class_1CBB8_unk17(void) {
}

void class_1CBB8_unk18(void) {
}

void class_1CBB8_unk19(void) {
}

s32 class_1CBB8_unk20(void) {
    return 0;
}

void class_1CBB8_unk21(void) {
}

void class_1CBB8_unk25(void) {
}

void class_1CBB8_unk26(void) {
}

void class_1CBB8_unk27(void) {
}

void class_1CBB8_unk28(void) {
}

class_1CBB8_vtable_t *class_1CBB8_get_vtable(void) {
    return &g_CLASS_1CBB8_VTABLE;
}

s32 func_8002C448(s32 *Out) {
    if (Out) {
        *Out = D_8008A8B4;
    }

    return D_8008A8B0;
}

s32 func_8002C468(s32 Unk1, s32 Unk2) {
    D_8008A8B0 = Unk1;
    D_8008A8B4 = Unk2;
    return 1;
}

s32 func_8002C478(void) {
    return 0;
}
