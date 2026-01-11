#include "2C694.h"

#include "timer.h"

// Unknown class
// Owns main_menu?

extern void **D_8006E854;
extern class_2C694_vtable_t **D_8006E730;

class_2C694_t *func_8003BE94(u32 Unk1, u32 Unk2, u32 Unk3) {
    class_2C694_t *allocated = (class_2C694_t *) memory_allocate_mem(0xA4);

    if (allocated) {
        func_8003DFBC()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_8003BF10(class_2C694_t *This, s32 Unk2, s32 Unk3, sound_engine_t *Unk4) {
    timer_get_vtable()->Construct(This);
    This->vtable = func_8003DFBC();
    This->vtable->Unk53(This, Unk2);

    if (Unk3) {
        This->m_Unk17 = sound_engine_create(Unk3);
    } else {
        This->m_Unk17 = Unk4;
    }

    This->m_Unk16 = Unk3;
    This->vtable->Unk52(This, 0, 0);
    This->m_Unk31 = func_80044F30(0);
    This->m_Unk30 = func_80044CD4(0, This->m_Unk31);
    This->m_Unk29 = func_800441B4(This->m_Unk30, 1);
    This->vtable->Unk15(This);
}

void func_8003C008(class_2C694_t *This) {
    This->m_Unk29->vtable->Destroy(This->m_Unk29);
  This->m_Unk30->vtable->Destroy(This->m_Unk30);
  This->m_Unk31->vtable->Destroy(This->m_Unk31);
  if ( This->m_Unk16 ) {
    This->m_Unk17->vtable->Destruct(This->m_Unk17);
  }
  if ( This->m_Unk27 ) {
    (*(void (**)(s32))(*(s32 *)This->m_Unk28 + 4))(This->m_Unk28);
  }
  This->vtable->Unk54(This);
  timer_get_vtable()->Cleanup(This);
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C11C);

s32 func_8003C1DC(class_2C694_t *This, s32 Unk2, s32 Unk3) {
    timer_get_vtable()->Unk16(This, Unk2, Unk3);
    return This->m_Unk13;
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C238);

void func_8003C3D0(class_2C694_t *This)
{
  s32 m_Unk5; // $s0

  m_Unk5 = This->m_Unk5;
  (*(void ( **)(s32))(*(s32 *)m_Unk5 + 144))(m_Unk5);
  (*(void ( **)(s32))(*(s32 *)m_Unk5 + 116))(m_Unk5);
  This->m_Unk29->vtable->Unk19(This->m_Unk29);
  if ( This->m_Unk12 )
    (*(void ( **)(s32, char *, s32))(**(s32 **)This->m_Unk2 + 120))(
      *(s32 *)This->m_Unk2,
      (char *)&This->m_Unk35 + 3,
      0);
}

// jump table
INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C48C);

void func_8003C51C(class_2C694_t *This, void **Unk2, s32 Unk3) {
    class_2C694_vtable_t *vtable;

    vtable = This->vtable;
    timer_get_vtable()->Increment(This, Unk2, Unk3);

    if (This->m_HasIdleTimeout && This->m_TicksPassed > This->m_TimeoutIdleTime) {
        vtable->Unk23(This, 6);
    }

    switch (This->m_Unk7) {
        case 2:
            vtable->Unk23(This, 4);
            break;

        case 4:
            vtable->Unk42(This);
            break;

        case 7:
            vtable->Unk47(This);
            break;

        case 8:
            vtable->Unk23(This, 3);
            break;

        default:
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003C63C);
// void func_8003C63C(class_2C694_t *This, s32 Unk2) {
//     class_2C694_vtable_t *vtable;

//     vtable = This->vtable;
//     timer_get_vtable()->Unk23(This, Unk2);

//     switch (Unk2) {
//         case 4:
//         case 7:
//             This->m_TicksPassed = 0;
//             This->m_HasIdleTimeout = 0;
//             break;

//         case 5:
//             vtable->Unk56(This, (char *)(This->m_Unk18 + 16));
//             vtable->Unk59(This, *(u32 *)(This->m_Unk18 + 8), 0);
//             This->m_TicksPassed = 0;
//             This->m_HasIdleTimeout = 1;
//             break;

//         case 6:
//             This->m_Unk13 = 1;
//             vtable->Unk36(This);
//             break;

//         case 8:
//             This->m_TicksPassed = 0;
//             break;

//         case 9:
//         case 10:
//         case 11:
//         case 14:
//         case 15:
//         case 16:
//         case 17:
//             This->m_Unk7 = 5;
//             This->m_TicksPassed = 0;

//             switch (Unk2) {
//                 case 11:
//                     vtable->Unk35(This);
//                     break;

//                 case 15:
//                     vtable->Unk66(This);
//                     break;

//                 case 17:
//                     vtable->Unk67(This);
//                     break;

//                 default:
//                     break;
//             }

//             break;

//         default:
//             break;
//     }
// }

void func_8003C794(class_2C694_t *This, s32 Unk2) {
    This->m_TimeoutIdleTime = Unk2;

    if (Unk2 >= 0) {
        This->m_TimeoutIdleTime = 20 * Unk2;
    }
}

void func_8003C7B4(class_2C694_t *This, int Unk2)
{
  if ( This->m_Unk17 ) {
    This->m_Unk17->vtable->Unk16(This->m_Unk17, Unk2, 96, 96);
  }
}

void func_8003C7F4(class_2C694_t *This) {
    if (This->m_Unk18) {
        This->vtable->Unk27(This, 16);
        This->vtable->Unk23(This, 10);
    }
}

void func_8003C858(class_2C694_t *This) {
    s32 value;

    if (This->m_Unk18) {
        This->vtable->Unk27(This, 16);

        value = 15;

        if (This->m_HasIdleTimeout == 1) {
            value = 11;
        }

        This->vtable->Unk23(This, value);
    }
}

void func_8003C8D0(class_2C694_t *This) {
    if (This->m_Unk18) {
        if (This->m_HasIdleTimeout != 1) {
            This->vtable->Unk27(This, 16);
            This->vtable->Unk23(This, 17);
        }
    }
}

void func_8003C944(class_2C694_t *This) {
    void (*callback)(void);

    if (This->m_Unk18) {
        if (This->m_HasIdleTimeout == 1) {
            callback = This->vtable->Unk58;
        } else {
            if (This->m_HasIdleTimeout != 2) {
                return;
            }

            callback = This->vtable->Unk69;
        }

        callback();
    }
}

void func_8003C9B0(class_2C694_t *This) {
    void (*callback)(void);

    if (This->m_Unk18) {
        if (This->m_HasIdleTimeout == 1) {
            callback = This->vtable->Unk57;
        } else {
            if (This->m_HasIdleTimeout != 2) {
                return;
            }

            callback = This->vtable->Unk68;
        }

        callback();
    }
}

void func_8003CA1C(class_2C694_t *This) {
    void *ptr1;
    s32 index;
    void (*func_to_call)(class_2C694_t *, void *, s32);

    ptr1 = This->m_Unk18;
    index = This->m_Unk21;

    if (*(int *)(*(char **)((char *)ptr1 + 0x24) + index * 4) != 0) {
        func_to_call = (void (*)(class_2C694_t *, void *, s32))This->vtable->Unk65;
    } else {
        if (index != *(s32 *)((char *)ptr1 + 0x0C)) {
            return;
        }
        func_to_call = (void (*)(class_2C694_t *, void *, s32))This->vtable->Unk36;
    }

    func_to_call(This, ptr1, index);
}

void func_8003CA94(class_2C694_t *This) {
    if (This->m_Unk38) {
        This->m_Unk38(This->m_Unk39);
    }

    This->vtable->Unk23(This, 7);
}

void func_8003CAEC(class_2C694_t *This, void (*Callback)(void *), s32 Arg) {
    This->m_Unk38 = Callback;
    This->m_Unk39 = Arg;
}

void func_8003CAF8(class_2C694_t *This, s32 Unk) {
    class_2C694_vtable_t *vtable = This->vtable;

    switch (Unk) {
        case 0:
            This->m_Unk33 = NULL;
            break;

        case 1:
            This->m_Unk33 = vtable->Unk43;
            break;
    }
}

void func_8003CB30(class_2C694_t *This, s32 Unk) {
    class_2C694_vtable_t *vtable = This->vtable;

    switch (Unk) {
        case 0:
            This->m_Unk34 = 0;
            break;

        case 1:
            This->m_Unk34 = vtable->Unk48;
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CB68);

void func_8003CBB8(class_2C694_t *This, s32 Unk) {
    This->m_Unk32 = Unk;
}

s32 func_8003CBC0(class_2C694_t *This)
{
  s32 (*callback)();
  s32 to_call;

  callback = This->m_Unk33;
  to_call = 1;
  if ( callback )
    to_call = callback();
  if ( to_call )
    This->vtable->Unk23(This, 5);
  return to_call;
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CC2C);

s32 func_8003CCDC(class_2C694_t *This) {
    s32 (*fp)(void);
    s32 v3;

    fp = This->m_Unk34;
    v3 = 1;

    if (fp == NULL || (v3 = fp(), v3 != 0)) {
        This->vtable->Unk23(This, 8);
    }

    return v3;
}

s32 func_8003CD48(class_2C694_t *This) {
    s32 v2;
    s8 v4[8];

    v2 = 128 - (This->m_TicksPassed * This->m_Unk32);

    v4[0] = v2;
    v4[1] = v2;
    v4[2] = v2;
    
    This->vtable->Unk56(This, v4);
    
    This->m_Unk29->vtable->Unk45(This->m_Unk29, 1, v4);
    
    return (u8)v2 >= 0x81;
}

void func_8003CDE0(class_2C694_t *This, s8 *Unk2, s32 Unk3) {
    if (Unk2 != NULL) {
        s32 new_texture_handle;

        if (This->m_Unk27 != NULL) {
            ((void (*)(s32)) (*(s32*)(*(s32*)(This->m_Unk28) + 4)))(This->m_Unk28);
        }

        new_texture_handle = (s32)texture_helper_create(Unk2);
        This->m_Unk28 = new_texture_handle;

        ((void (*)(s32)) (*(s32*)(*(s32*)new_texture_handle + 0x78)))(new_texture_handle);
        ((void (*)(s32)) (*(s32*)(*(s32*)(This->m_Unk28) + 0x5C)))(This->m_Unk28);
    } else {
        This->m_Unk28 = Unk3;
    }


    This->m_Unk27 = Unk2;
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003CE98);

void func_8003D050(class_2C694_t *This) {
    void *unk18;
    int s1;
    void **s2;
    int unk19;
    void *unk18_member0;
    void *unk18_member4_arg;
    void *unk25_arg;
    void *loop_arg;
    char unused_stack_padding[8];

    (void)unused_stack_padding;

    unk18 = (void*)This->m_Unk18;
    if (unk18) {
        unk18_member0 = *(void**)unk18;
        if (unk18_member0) {
            unk18_member4_arg = *(void**)((char*)unk18 + 4);
            (*(void(**)(void*))((char*)*(void**)unk18_member4_arg + 4))(unk18_member4_arg);
        }

        unk25_arg = (void*)This->m_Unk25;
        (*(void(**)(void*))((char*)*(void**)unk25_arg + 4))(unk25_arg);
        
        s1 = 0;
        
        unk19 = This->m_Unk19;
        s2 = (void**)This->m_Unk20;

        if (unk19 > 0) {
            do {
                if (*(void**)((char*)*(void**)((char*)(void*)This->m_Unk18 + 0x24) + s1 * 4)) {
                     This->m_Unk21 = s1;
                     This->vtable->Unk62(This);
                }

                loop_arg = *s2;
                (*(void(**)(void*))((char*)*(void**)loop_arg + 4))(loop_arg);

                s1++;
                s2++;
            } while (s1 < This->m_Unk19);
        }

        memory_free_mem(This->m_Unk24);
        memory_free_mem(This->m_Unk23);
        memory_free_mem(This->m_Unk22);
        memory_free_mem((void*)This->m_Unk20);
    }
}

void func_8003D194(void *this, s32 arg1) {
    char dummy_stack_padding[8];
    void *pUnk4C;
    s32 count;
    void **ppUnk54;
    s32 loop_var_s4;
    s32 i;
    int *pArray18;
    int *pArray24;
    void *pOther;
    void **vtable;

    if (&dummy_stack_padding[0] == &dummy_stack_padding[7]) {
    }

    pUnk4C = *(void**)((char*)this + 0x4C);
    if (pUnk4C == NULL) {
        return;
    }
    
    ppUnk54 = *(void***)((char*)this + 0x54);
    count = *(s32*)((char*)this + 0x50);
    loop_var_s4 = *(s32*)((char*)pUnk4C + 0x20);

    if (count <= 0) {
        return;
    }

    i = 0;

    do {
        pArray18 = *(int**)((char*)*(void**)((char*)this + 0x4C) + 0x18);
        if (pArray18[i] == 0) {
            pOther = *ppUnk54;
            vtable = *(void***)pOther;
            ((void (*)(void*, s32, s32))vtable[0x4C / 4])(pOther, arg1, loop_var_s4);

            pArray24 = *(int**)((char*)*(void**)((char*)this + 0x4C) + 0x24);
            if (pArray24[i] != 0) {
                *(s32*)((char*)this + 0x58) = i;
                vtable = *(void***)this;
                ((void (*)(void*, s32, s32))vtable[0x100 / 4])(this, arg1, 0);
                goto if_path_updates;
            }
        } else {
            pOther = *ppUnk54;
            vtable = *(void***)pOther;
            ((void (*)(void*))vtable[0x50 / 4])(pOther);
        }

if_path_updates:
        i++;
        ppUnk54++;
        loop_var_s4 += 8;

        count = *(s32*)((char*)this + 0x50);
    } while (i < count);
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D2CC);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D3B0);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D444);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D4DC);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D5C0);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D5CC);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D6D4);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D73C);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003D980);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003DA10);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003DAD4);

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003DCAC);

void func_8003DDC8(class_2C694_t *This) {
    s32 value;

    value = This->m_Unk23[This->m_Unk21];
    value++;

    if (value >= This->m_Unk22[This->m_Unk21]) {
        value = 0;
    }

    This->vtable->Unk70(This, value, 1);
}

void func_8003DE30(class_2C694_t *This) {
    s32 value;

    value = This->m_Unk23[This->m_Unk21];
    value--;

    if (value < 0) {
        value = This->m_Unk22[This->m_Unk21] - 1;
    }

    This->vtable->Unk70(This, value, 1);
}

INCLUDE_ASM("asm/nonmatchings/2C694", func_8003DE9C);

s32 func_8003DFA0(class_2C694_t *This) {
    return This->m_Unk23[This->m_Unk21];
}

class_2C694_vtable_t *func_8003DFBC(void) {
    return &D_8006E730;
}

void *func_8003DFCC(void) {
    return &D_8006E854;
}
