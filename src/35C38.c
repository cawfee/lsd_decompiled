#include "35C38.h"
#include "base_class.h"

extern class_35C38_vtable_t D_8006F614;

extern s32 D_8008A940;
extern s32 D_8008A948;

void DecDCTReset(s32 mode);
s32 DecDCToutCallback(void (*func)());
void func_8004575C(class_35C38_t *This);

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

void func_800455D4(class_35C38_t *This) {
    void **temp_a0;

    temp_a0 = (void **)This->m_Unk23;
    This->m_Unk23 = (s32)((void *(*)(void **))(*(void **)((s8 *)*temp_a0 + 4)))(temp_a0);
    DecDCToutCallback(0);
    DecDCTReset(0);
    func_8004575C(This);
    base_class_get_vtable()->Cleanup(This);
}

INCLUDE_ASM("asm/nonmatchings/35C38", func_8004564C);

void func_8004575C(class_35C38_t *This) {
    if (This->m_Unk2 == 0) {
        memory_free_mem(This->m_Unk4);
        memory_free_mem(This->m_Unk5);
        memory_free_mem(This->m_Unk3);
        memory_free_mem(This->m_Unk6);
    }
}

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

s32 func_80045C94(class_35C38_t *This) {
    if (This->m_Unk20 != 0) {
        s32 temp_v0;

        temp_v0 = D_8008A948 < 0x65;
        D_8008A948 += 1;
        if (temp_v0 == 0) {
            D_8008A948 = 1;
            This->vtable->Unk16(This);
        }
        return 0;
    }
    D_8008A940 = 0;
    return 1;
}

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
