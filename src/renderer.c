#include "renderer.h"

extern renderer_vtable_t *g_RENDERER_VTABLE;

void *renderer_create(void) {
    void *temp_v0;

    temp_v0 = memory_allocate_mem(0xBC);
    
    if (temp_v0 != 0) {
        (*(void (**)(void *))(renderer_get_vtable() + 8))(temp_v0);
        return temp_v0;
    }
    
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E628);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E6CC);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E770);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E7F4);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E874);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E8B8);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003E968);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EA0C);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EA24);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EA2C);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EA48);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EA64);

void func_8003EA6C(void) {
}

void func_8003EA74(void) {
}

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EA7C);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EA84);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EAA4);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EAC4);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EACC);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EB84);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EBC4);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EBF8);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EC2C);

void func_8003ECC0(void) {
}

void func_8003ECC8(void) {
}

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003ECD0);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EDF4);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EE40);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EE88);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003EEC0);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003F04C);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003F1A8);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003F230);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003F23C);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003F244);

renderer_vtable_t *renderer_get_vtable(void) {
    return &g_RENDERER_VTABLE;
}

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003F25C);

INCLUDE_ASM("asm/nonmatchings/renderer", func_8003F28C);
