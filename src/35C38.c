#include "35C38.h"

extern class_35C38_vtable_t D_8006F614;

extern s32 D_8008A940;

class_35C38_t *func_80045438(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_35C38_t *allocated = (class_35C38_t *) memory_allocate_mem(0x6C);

    if (allocated) {
        ;
        if (!func_80045E44()->Construct(allocated, Unk1, Unk2, Unk3)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/35C38", func_800454C4);

INCLUDE_ASM("asm/nonmatchings/35C38", func_800455D4);

INCLUDE_ASM("asm/nonmatchings/35C38", func_8004564C);

INCLUDE_ASM("asm/nonmatchings/35C38", func_8004575C);

INCLUDE_ASM("asm/nonmatchings/35C38", func_800457C0);

void func_800458AC(class_35C38_t *This) {
    This->m_Unk19 = 1;
}

INCLUDE_ASM("asm/nonmatchings/35C38", func_800458B8);

void func_8004593C(class_35C38_t *This) {
    This->m_Unk19 = -1;
}

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045948);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045A38);

void func_80045AC8(void) {
}

void func_80045AD0(void) {
}

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045AD8);

void func_80045BC0(void) {
}

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045BC8);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045C94);

INCLUDE_ASM("asm/nonmatchings/35C38", func_80045CFC);

void func_80045DE0(void) {
    if (D_8008A940 != NULL) {
        (*(void ( **)(int))(*(s32 *)D_8008A940 + 96))(D_8008A940);
    }
}

void func_80045E18(class_35C38_t *This) {
    while (!This->m_Unk18) {
    }
}

void func_80045E3C(class_35C38_t *This, s32 Unk) {
    This->m_Unk25 = Unk;
}

class_35C38_vtable_t *func_80045E44(void) {
    return &D_8006F614;
}
