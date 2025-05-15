#include "326E8.h"

#include "D294.h"

extern class_326E8_vtable_t **D_8006EE1C;

class_326E8_t *func_80041EE8(s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    class_326E8_t *allocated = (class_326E8_t *) memory_allocate_mem(0xA0);

    if (allocated) {
        func_800422BC()->Construct(allocated, Unk1, Unk2, Unk3, Unk4, Unk5);
        return allocated;
    }

    return NULL;
}

void func_80041F88(class_326E8_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5, s32 Unk6) {
    func_8001E57C()->Construct(This);
    This->vtable = func_800422BC();
    This->vtable->Unk15(This, Unk2, Unk3, Unk4, Unk5, Unk6);
}

INCLUDE_ASM("asm/nonmatchings/326E8", func_8004202C);

INCLUDE_ASM("asm/nonmatchings/326E8", func_8004208C);

INCLUDE_ASM("asm/nonmatchings/326E8", func_80042170);

INCLUDE_ASM("asm/nonmatchings/326E8", func_8004220C);

INCLUDE_ASM("asm/nonmatchings/326E8", func_8004223C);

INCLUDE_ASM("asm/nonmatchings/326E8", func_80042268);

void func_80042294(void) {
}

INCLUDE_ASM("asm/nonmatchings/326E8", func_8004229C);

class_326E8_vtable_t *func_800422BC(void) {
    return &D_8006EE1C;
}
