#include "3ACC8.h"
#include "D294.h"

extern class_3ACC8_vtable_t D_800866E8;

extern s32 D_800869CC[];

class_3ACC8_t *func_8004A4C8(u32 Unk1, u32 Unk2) {
    class_3ACC8_t *allocated = (class_3ACC8_t *) memory_allocate_mem(0x1E8);

    if (allocated) {
        func_8004D244()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004A534);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004A7C0);

void func_8004A984(class_3ACC8_t *This, s32 **Unk2, s32 Unk3) {
    func_8001E57C()->Unk13(This, Unk2, Unk3);

    if ((**Unk2 & 0xF) == 1) {
        This->vtable->Unk63(This, Unk2, Unk3);
    }
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004AA10);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004AA6C);

void func_8004AB24(class_3ACC8_t *This) {
    if (This->m_Unk27) {
        This->vtable->Unk60(This);
        This->vtable->Unk78(This);
    }
}

void func_8004AB88(class_3ACC8_t *This, u8 **Unk) {
    if (**Unk == 52) {
        This->vtable->Unk51(This);
    }
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004ABD0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004ACF8);

void func_8004ADC4(class_3ACC8_t *This, s32 Unk2, s32 Unk3) {
    This->m_Unk23 = Unk2;
    This->m_Unk24 = Unk3;
}

void func_8004ADD0(class_3ACC8_t *This, s32 Value) {
    This->m_Unk57 = Value;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004ADD8);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004AEA4);

void func_8004AFE0(class_3ACC8_t *This, s32 *Unk1, s32 Unk2) {
    s8 v3;

  This->m_Unk30_1 = *((s8 *)Unk1 + 2) - 1;
  v3 = *((s8 *)Unk1 + 3);
  This->m_Unk31 = Unk2;
  This->m_Unk32 = Unk2;
  This->m_Unk30_2 = v3 - 1;
  func_8004C93C(This);
}


INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B030);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B100);

void func_8004B2D4(class_3ACC8_t *This) {
    if (This && (This->m_Unk12_2 & 0x80) != 0) {
        This->vtable->Unk13(This);
    }
}

s32 *func_8004B31C(class_3ACC8_t *This) {
    return &This->m_Unk111;
}

void func_8004B324(void) {
}

void func_8004B32C(class_3ACC8_t *This, s32 Value) {
    This->m_Unk28 = Value;
    This->m_Unk29_2 = Value >> 11;
    This->m_Unk29_1 = Value >> 12;
}

void func_8004B344(class_3ACC8_t *This, s32 Unk) {
    This->vtable->Unk15(This);
  This->m_Unk25 = Unk;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B38C);

void func_8004B418(class_3ACC8_t *This, s32 Unk2, s32 Unk3) {
    s8 unk[16];

    func_8004B44C(Unk2, unk, This->m_Unk25, &This->m_Unk20, Unk3);
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B44C);

void func_8004B570(class_3ACC8_t *This) {
    This->m_Unk27 = 1;
}

void func_8004B57C(class_3ACC8_t *This) {
    This->vtable->Unk47(This);
    This->m_Unk27 = 0;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B5BC);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B700);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004B930);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BA40);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BB3C);

s32 func_8004BCE0(class_3ACC8_t *This) {
    s32 count = 0;
    s32 i = 0;

loop:
    if (This->m_Unk58_1 != 0) {
        count++;
    }
    This = (class_3ACC8_t *)((char *)This + 0x1C);
    i++;
    if (i < 7) {
        goto loop;
    }

    return count;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BD14);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004BE54);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C0AC);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C158);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C1C0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C368);

s32 func_8004C3F0(class_3ACC8_t *This, s8 *Unk) {
    func_8004C368(This, Unk, *(s16 *)(*(s32 *)(This->m_Unk110 + 4) + 48));
  return This->m_Unk110;
}

s32 func_8004C434(class_3ACC8_t *This, int Unk) {
    s32 i = 0;
    s32 offset = 0xEC;
    char *ptr;
    s32 result;

    do {
        ptr = (char *)This + offset;
        
        if (*(s16 *)(*(s32 *)(ptr + 4) + 0x32) == Unk) {
            result = (s32)ptr;
            goto exit;
        }

        i++;
        result = i < 7;
        offset += 0x1C;
    } while (result);

exit:
    return result;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C470);

s32 func_8004C588(class_3ACC8_t *This, s32 Unk) {
    s32 ret = 0;
    s32 i = 0;
    s32 offset = 0xEC;

    do {
        u8 *ptr = *(u8 **)((u8 *)This + offset + 4);

        if (*(s16 *)(ptr + 0x32) == Unk) {
            ret = i;
            break;
        }

        i++;
        offset += 0x1C;
    } while (i < 7);

    return ret;
}

s32 func_8004C5D0(class_3ACC8_t *This, s32 Unk) {
    s32 i;
    s32 offset;
    char *ptr;

    i = 0;
    offset = 0xEC;
    do {
        ptr = *(char**)((u8*)This + offset + 4);
        if (*(s16*)(ptr + 0x30) == Unk) {
            if (*(s16*)(ptr + 0x2C) != 0) {
                return i;
            }
        }
        i++;
        offset += 0x1C;
    } while (i < 7);

    return -1;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C620);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C6A8);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004C93C);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CAF0);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CC74);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CD38);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CDA4);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CE24);

void *func_8004CFA8(class_3ACC8_t *This) {
    return &This->m_Unk114;
}

void func_8004CFB0(class_3ACC8_t *This, s32 Unk) {
    This->m_Unk118 = Unk;
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004CFB8);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D028);

void func_8004D088(class_3ACC8_t *This) {
    if ( This->m_Unk119 )
  {
    func_8004D140(This, func_8004D108, 0);
    This->m_Unk119 = 0;
  }
}

void func_8004D0D0(class_3ACC8_t *This, s32 *Unk) {
    (*(void ( **)(s32 *, s32, s32))(*Unk + 72))(Unk, 0, This->m_Unk120);
}

// INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D108);
void func_8004D108(class_3ACC8_t *This, s32 *Unk) {
    (*(void ( **)(s32 *, s32, s32 *))(*Unk + 72))(Unk, 1, & D_800869CC);
}

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D140);

INCLUDE_ASM("asm/nonmatchings/3ACC8", func_8004D1D0);

class_3ACC8_vtable_t *func_8004D244(void) {
    return &D_800866E8;
}
