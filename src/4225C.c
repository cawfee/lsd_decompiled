#include "4225C.h"
#include "text_line.h"
#include "base_class.h"

extern class_4225C_vtable_t D_80086F88;

class_4225C_t *func_80051A5C(s32 Unk1, s32 Unk2) {
    class_4225C_t *allocated = (class_4225C_t *) memory_allocate_mem(0x54);

    if (allocated) {
        func_80052B60()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051AC8);

void func_80051C74(class_4225C_t *This) {
    This->m_Unk12 = 0;
    This->m_Unk13 = 0;
    This->m_Unk19 = 0;
}

void func_80051C84(class_4225C_t *This) {
    s32 temp_a0;
    s32 var_s0;
    s32 pad[2];

    var_s0 = 0;
    if (This->m_Unk3 > 0) {
        do {
            temp_a0 = ((s32 *)This->m_Unk5)[var_s0];
            var_s0 += 1;
            memory_free_mem((void *)temp_a0);
        } while (var_s0 < This->m_Unk3);
    }
    memory_free_mem((void *)This->m_Unk6);
    memory_free_mem((void *)This->m_Unk5);
    base_class_get_vtable()->base_class_cleanup(This);
}

void func_80051D1C(class_4225C_t *This, void **Unk) {
    s32 kind;

    if (Unk != NULL) {
        base_class_get_vtable()->Unk3(This, Unk);
        kind = *(u32 *)*Unk & 0xF;
        if (kind == 2) {
            This->m_Unk12 = (s32)Unk;
            return;
        }
        if (kind == 5) {
            This->m_Unk13 = (s32)Unk;
        }
    }
}

void func_80051DA0(class_4225C_t *This, void **Unk) {
    s32 kind;

    if (Unk != NULL) {
        kind = *(u32 *)*Unk & 0xF;
        if (kind == 2) {
            This->m_Unk12 = 0;
        } else if (kind == 5) {
            This->m_Unk13 = 0;
        }
        base_class_get_vtable()->Unk4(This, Unk);
    }
}

void func_80051E20(class_4225C_t *This) {
    This->m_Unk12 = 0;
  This->m_Unk13 = 0;
  This->m_Unk19 = 0;
  base_class_get_vtable()->Unk5(This);
}

void func_80051E64(class_4225C_t *This, void **Unk1, s32 Unk2) {
    s32 kind;

    ((void (*)(void *, void **, s32))base_class_get_vtable()->Unk13)(This, Unk1, Unk2);
    kind = *(u32 *)*Unk1 & 0xF;
    if (kind == 2) {
        ((void (*)(void *, void **, s32))This->vtable->Unk22)(This, Unk1, Unk2);
    } else if (kind == 5) {
        ((void (*)(void *, void **, s32))This->vtable->Unk21)(This, Unk1, Unk2);
    }
}

void func_80051F14(class_4225C_t *This) {
    This->m_Unk7 = 0;
    This->m_Unk8 = 0;
    This->m_Unk9 = 0;
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80051F24);

void func_800520A0(class_4225C_t *This) {
    if (This->m_Unk19) {
        ((void (*)(void *))This->vtable->Unk35)(This);
        This->m_Unk19 = (*(s32 (**)(s32))(*(s32 *)This->m_Unk19 + 4))(This->m_Unk19);
    }
}

void func_80052110(class_4225C_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    ((void (*)(void *, s32))This->vtable->Unk3)(This, Unk1);
    ((void (*)(void *, s32))This->vtable->Unk3)(This, Unk2);
    This->m_Unk14 = Unk3;
    This->m_Unk10 = 0;
}

void func_8005217C(class_4225C_t *This) {
    This->vtable->Unk4(This, This->m_Unk12);
  This->vtable->Unk4(This, This->m_Unk13);
  This->m_Unk14 = 0;
}

void func_800521D4(class_4225C_t *This, s32 arg1) {
    This->m_Unk11 = 0;
    if (arg1 < 2) {
        goto end;
    }
    if (arg1 < 4) {
        goto case_2_3;
    }
    if (arg1 == 4) {
        goto case_4;
    }
    goto end;
case_2_3:
    ((void (*)(void *, s32))This->vtable->Unk4)(This, This->m_Unk12);
    This->vtable->Unk17(This);
    This->m_Unk10 = arg1;
    goto end;
case_4:
    ((void (*)(void *, s32))This->vtable->Unk11)(This, This->m_Unk10);
end:
    ;
}

void func_8005227C(class_4225C_t *This) {
    s32 unk10;
    s32 unk11;

    unk10 = This->m_Unk10;
    if (unk10 < 4) {
        if (!(unk10 < 2)) {
            unk11 = This->m_Unk11;
            This->m_Unk11 = unk11 + 1;
            if (unk11) {
                ((void (*)(void *, s32))This->vtable->Unk20)(This, 4);
            }
        }
    }
}

void func_800522DC(class_4225C_t *This, s32 Unk2, s32 Unk3) {
    void (*fn)(void *);

    switch (Unk3) {
        case 25:
            ((void (*)(void *, s32))This->vtable->Unk23)(This, 0x10);
            ((void (*)(void *, s32))This->vtable->Unk20)(This, 2);
            break;
        case 23:
            ((void (*)(void *, s32))This->vtable->Unk23)(This, 0x10);
            ((void (*)(void *, s32))This->vtable->Unk20)(This, 3);
            break;
        case 5:
            fn = This->vtable->Unk30;
            goto do_call;
        case 4:
            fn = This->vtable->Unk31;
            goto do_call;
        case 18:
            fn = This->vtable->Unk32;
            goto do_call;
        case 19:
            fn = This->vtable->Unk33;
        do_call:
            fn(This);
            break;
    }
}

void func_800523F0(class_4225C_t *This, s32 Unk) {
    s32 m_Unk14; // $a0

  m_Unk14 = This->m_Unk14;
  if ( m_Unk14 ) {
    (*(void ( **)(s32, int, int, int))(*(s32 *)m_Unk14 + 128))(m_Unk14, Unk, 96, 96);
  }
}

void func_80052430(class_4225C_t *This) {
    s32 cur;
    s32 neu;
    s32 flag;

    if (This->m_Unk19) {
        cur = This->m_Unk8;
        if (cur + 0x1A < This->m_Unk4) {
            neu = cur + 1;
            flag = 1;
            This->m_Unk8 = neu;
            ((void (*)(void *, s32, s32, s32, s32))This->vtable->Unk36)(
                This, This->m_Unk7, neu, This->m_Unk9, flag);
        }
    }
}

void func_80052498(class_4225C_t *This) {
    s32 neu;

    if (This->m_Unk19) {
        neu = This->m_Unk8 - 1;
        if (neu >= 0) {
            This->m_Unk8 = neu;
            ((void (*)(void *, s32, s32, s32, s32))This->vtable->Unk36)(
                This, This->m_Unk7, neu, This->m_Unk9, 1);
        }
    }
}

void func_800524F8(class_4225C_t *This) {
    s32 unk9;
    s32 unk7;

    if (This->m_Unk19 != 0) {
        if (!((This->m_Unk9 - 1) < 0)) {
            unk7 = This->m_Unk7;
            if ((This->m_Unk9 - unk7) > 0) {
                ((void (*)(void *, s32, s32))This->vtable->Unk37)(This, 0, 1);
                return;
            }
            This->m_Unk7 = unk7 - 1;
            unk9 = This->m_Unk9;
            This->m_Unk9 = unk9 - 1;
            ((void (*)(void *, s32, s32, s32, s32))This->vtable->Unk36)(
                This, unk7 - 1, This->m_Unk8, unk9 - 1, 1);
        }
    }
}

void func_80052598(class_4225C_t *This) {
    s32 cur;
    s32 unk9;
    s32 unk7;
    s32 tmp;
    s32 flag;

    if (This->m_Unk19) {
        cur = This->m_Unk9;
        if (cur + 1 < This->m_Unk3) {
            unk7 = This->m_Unk7;
            tmp = unk7 - 1;
            if ((cur - tmp) < 4) {
                This->vtable->Unk37(This, 1, 1);
                return;
            }
            This->m_Unk7 = unk7 + 1;
            unk9 = This->m_Unk9;
            This->m_Unk9 = unk9 + 1;
            flag = 1;
            This->vtable->Unk36(This, unk7 + 1, This->m_Unk8, unk9 + 1, flag);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/4225C", func_80052644);

INCLUDE_ASM("asm/nonmatchings/4225C", func_8005278C);

void func_800529FC(class_4225C_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4);
char *func_8005292C(class_4225C_t *This, char *dest, s32 arg2, s32 arg3, char *base);

void func_8005281C(class_4225C_t *This, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 count;
    s32 index;
    text_line_t **slot;
    char text[0x28];

    if (This->m_Unk19 != 0) {
        count = This->m_Unk3;
        slot = (text_line_t **)&This->m_Unk15;
        if (count >= 5) {
            count = 4;
        }
        index = 0;
        if (count > 0) {
            do {
                func_8005292C(This, text, index, arg1, (char *)arg2);
                slot[0]->vtable->Unk50(slot[0], text);
                slot += 1;
                index += 1;
            } while (index < count);
        }
        func_800529FC(This, arg1, arg2, arg3, 0);
        if (arg4 != 0) {
            This->vtable->Unk23(This, 0);
        }
    }
}

extern s32 strlen(char *);
extern void *memcpy_c(void *, void *, s32);

char *func_8005292C(class_4225C_t *This, char *dest, s32 arg2, s32 arg3, char *base) {
    s32 index;
    s32 len;

    index = arg3 + arg2;
    len = strlen(base + ((s32 *)This->m_Unk5)[index]);
    if (len >= 0x1B) {
        len = 0x1A;
    }
    memcpy_c(dest, base + ((s32 *)This->m_Unk5)[index], len);
    {
        s32 n;
        s32 last;

        n = len;
        if (n < 0x1A) {
            s32 fill;

            fill = 0x20;
            n = (s32)dest + n;
            last = (s32)dest + 0x1A;
            do {
                *(u8 *)n = fill;
                n += 1;
            } while (n < last);
        }
    }
    dest[0x1A] = 0;
    return dest;
}

extern s32 D_8008AB0C;
extern s32 D_8008AB10;

void func_800529FC(class_4225C_t *This, s32 Unk1, s32 Unk2, s32 Unk3, s32 Unk4) {
    s32 flag;
    s32 obj;

    flag = Unk4;
    This->m_Unk7 = Unk1;
    This->m_Unk8 = Unk2;
    This->m_Unk9 = Unk3;
    if (flag != 0) {
        Unk3 = Unk3 - Unk1;
        obj = *(s32 *)((u8 *)This + 0x40 + (Unk3 * 4));
        (*(void (**)(s32, s32 *))(*(s32 *)obj + 0xB8))(obj, &D_8008AB10);
    }
}

void func_80052A58(class_4225C_t *This, s32 arg1, s32 arg2) {
    text_line_t **slot;

    if (This->m_Unk19 != 0) {
        slot = (text_line_t **)&This->m_Unk15 + (This->m_Unk9 - This->m_Unk7);
        slot[0]->vtable->Unk45(slot[0], (char *)&D_8008AB0C);
        if (arg1 != 0) {
            slot += 1;
            This->m_Unk9 += 1;
        } else {
            slot -= 1;
            This->m_Unk9 -= 1;
        }
        slot[0]->vtable->Unk45(slot[0], (char *)&D_8008AB10);
        if (arg2 != 0) {
            This->vtable->Unk23(This, 0);
        }
    }
}

s32 func_80052B54(class_4225C_t *This) {
    return This->m_Unk9;
}

class_4225C_vtable_t *func_80052B60(void) {
    return &D_80086F88;
}
