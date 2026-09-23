#include "55DD4.h"
#include "477E4.h"
#include "34E8C.h"

// Entity object related class? constructed by entity.

extern class_55DD4_vtable_t g_CLASS_55DD4_VTABLE;

class_55DD4_t *class_55DD4_create(s32 Unk1, s32 Unk2) {
    class_55DD4_t *allocated = (class_55DD4_t *) memory_allocate_mem(0x98);

    if (allocated) {
        if (class_55DD4_get_vtable()->class_55DD4_construct(allocated, Unk1, Unk2)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

class_55DD4_t *class_55DD4_construct(class_55DD4_t *This, s32 Unk2, s32 Unk3) {
    if (func_80057C84()->Construct(This)) {
        This->vtable = class_55DD4_get_vtable();
        This->m_Unk21 = Unk3;
        This->m_Unk22 = 0;
        This->m_Unk25 = 0;
        This->m_Unk27 = 0;
        This->m_Unk36 = 0;

        if (!This->vtable->Unk60(This, Unk2)) {
            This->vtable->Unk3(This, This->m_Unk22);
            This->vtable->Unk15(This);
            return This;
        }

        func_80057C84()->Cleanup(This);
    }

    return NULL;
}

void class_55DD4_cleanup(class_55DD4_t *This) {
    This->vtable->Unk61(This);
    func_80057C84()->Cleanup(This);
}

void func_80065790(class_55DD4_t *This, u16 **Unk2, s32 Unk3) {
    func_80057C84()->Unk13(This, Unk2, Unk3);

    if (**Unk2 == 0x5F03 && Unk3 == 1 && !This->m_Unk23) {
        This->vtable->base_class_destructor(This);
    }
}

void func_80065830(class_55DD4_t *This) {
    func_80057C84()->Unk23(This, 0);
    This->vtable->Unk59(This, 1);
    This->vtable->Unk56(This, 300);
    This->vtable->Unk68(This);
    This->vtable->Unk66(This, 65);
    This->vtable->Unk75(This);
    This->vtable->Unk73(This, 0);

    if (This->m_Unk25) {
        func_8001E770(This, *(void **) (This->m_Unk25 + 32));
    }
}

void func_80065918(class_55DD4_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    if (!This->m_Unk2) {
        func_80057C84()->Unk18(This, Unk4, Unk5);

        if (Unk3 && !This->m_Unk19) {
            This->vtable->Unk3(This, Unk3);
        }

        This->vtable->Unk78(This, Unk2);
    }
}

void func_800659D0(class_55DD4_t *This) {
    if (This->m_Unk2) {
        This->vtable->Unk79(This);

        if (This->m_Unk19) {
            This->vtable->Unk4(This, This->m_Unk19);
        }

        func_80057C84()->Unk19(This);
    }
}

void func_80065A5C(class_55DD4_t *This, s32 arg1) {
    s32 i;
    void **obj_list;

    obj_list = This->m_Unk27;

    for (i = 0; i < This->m_Unk26; i++, obj_list++) {
        void *current_obj;
        void *vtable;

        current_obj = *obj_list;

        vtable = *(void **) current_obj;
        ((void (*)(void *, s32))((void **) vtable)[24])(current_obj, arg1);
    }
}

void func_80065AE0(class_55DD4_t *This, s32 Unk2) {
    s32 i;
    void **obj_list;

    obj_list = This->m_Unk27;

    for (i = 0; i < This->m_Unk26; i++, obj_list++) {
        void *current_obj = *obj_list;
        void *vtable = *(void **) current_obj;

        ((void (*)(void *, s32))((void **) vtable)[28])(current_obj, Unk2);
    }

    func_80057C84()->Unk27(This, Unk2);
}

void func_80065B80(class_55DD4_t *This, s32 Unk2, s32 Unk3) {
    if (Unk3 == 2) {
        This->vtable->Unk65(This, Unk2);
    }

    if (Unk3 == 4) {
        This->vtable->base_class_destructor(This);
    }
}

void func_80065BF4(class_55DD4_t *This, s32 Value) {
    This->m_Unk24 = Value;
}

s32 func_80065BFC(class_55DD4_t *This, void *Unk2) {
    if (!This->m_Unk22) {
        return func_80065C5C(This, Unk2);
    }

    return 0;
}

void func_80065C2C(class_55DD4_t *This) {
    if (This->m_Unk22) {
        func_80065CEC(This);
    }
}

s32 func_80065C5C(class_55DD4_t *This, void *arg1) {
    s32 temp;

    temp = *(s32 *) ((char *) arg1 + 0xC);

    if (temp != 0) {
        This->m_Unk22 = temp;
        This->m_Unk23 = 0;
    } else {
        This->m_Unk22 = func_8004468C(arg1);
        This->m_Unk23 = 1;
    }

    if (This->m_Unk22 != 0) {
        return This->vtable->Unk63(This);
    }

    func_80065CEC(This);
    return 1;
}

void func_80065CEC(class_55DD4_t *This) {
    void *result;

    This->vtable->Unk64(This);

    if (This->m_Unk23) {
        void *pUnk22 = This->m_Unk22;

        result = (void *) ((s32(*)(void *))(*(void ***) pUnk22)[1])(pUnk22);
    } else {
        result = NULL;
    }

    This->m_Unk22 = result;
}

s32 func_80065D64(class_55DD4_t *This, u8 Value) {
    void *temp_ptr;
    unsigned char *p;
    s32 len;
    s32 i;

    temp_ptr = (void *) This->m_Unk28;
    if (temp_ptr == NULL) {
        goto fail;
    }

    p = temp_ptr;
    len = This->m_Unk26;

    for (i = 0; i < len; i++) {
        if (*p == Value) {
            return i;
        }
        p++;
    }

fail:
    return -1;
}

s32 func_80065DBC(class_55DD4_t *This) {
    if (!This->m_Unk27) {
        return func_80065E1C(This);
    }

    return 0;
}

void func_80065DEC(class_55DD4_t *This, s32 Unk2) {
    if (This->m_Unk27) {
        func_80065F2C(This, Unk2);
    }
}

extern class_477E4_t *func_80056FE4(void);

s32 func_80065E1C(class_55DD4_t *This) {
    struct {
        s32 index;
        char dummy[12];
    } loc;
    class_34E8C_t *obj;
    s32 i;
    s32 count;
    void **slot;
    void *mem;

    if (&loc.dummy[0] == &loc.dummy[11]) {
    }
    obj = (class_34E8C_t *)This->m_Unk22;
    count = obj->vtable->Unk31(obj, NULL, &loc.index) & 0xFF;
    mem = memory_allocate_mem(count * 4);
    This->m_Unk27 = mem;
    if (mem == NULL) {
        goto alloc_fail;
    }
    mem = memory_allocate_mem(count);
    This->m_Unk28 = (u32)mem;
    if (mem == NULL) {
        goto alloc_fail;
    }
    obj = (class_34E8C_t *)This->m_Unk22;
    obj->vtable->Unk31(obj, mem, &loc.index);
    slot = This->m_Unk27;
    i = 0;
    This->m_Unk26 = 0;
    if (count != 0) {
        do {
            void *item;

            item = func_80056FE4();
            *slot = item;
            slot += 1;
            if (item == NULL) {
                goto loop_fail;
            }
            This->m_Unk26 += 1;
            i += 1;
        } while (i < count);
    }
    This->m_Unk25 = (s32)This->m_Unk27[loc.index];
    return 0;
alloc_fail:
    This->m_Unk28 = 0;
loop_fail:
    func_80065F2C(This);
    return 1;
}

void func_80065F2C(class_55DD4_t *This) {
    void **list;
    void **p;
    s32 count;
    void *obj;

    list = This->m_Unk27;
    if (list != NULL) {
        if (This->m_Unk28 != 0) {
            count = This->m_Unk26;
            p = list;
            goto loop_test;
loop_body:
            obj = *p;
            p++;
            (*(void (**)(void *))(*(u32 *)obj + 4))(obj);
            count = This->m_Unk26;
loop_test:
            This->m_Unk26 = count - 1;
            if (count > 0) {
                goto loop_body;
            }
            This->m_Unk25 = 0;
        }
    }
    This->m_Unk28 = (u32)memory_free_mem((void *)This->m_Unk28);
    This->m_Unk27 = memory_free_mem(This->m_Unk27);
}

void func_80065FD8(class_55DD4_t *This) {
    s32 neu;

    This->m_Unk8 += 1;
    if (This->m_Unk34) {
        ((void (*)(void))This->m_Unk29)();
    }
    if (This->m_Unk35 != 0) {
        if (This->m_Unk31 >= 2) {
            This->m_Unk33 = ((s32 (*)(void *, s32, s32))This->vtable->Unk76)(This, This->m_Unk33, 0);
            neu = This->m_Unk32 + 1;
            This->m_Unk32 = neu;
            if (neu >= This->m_Unk31) {
                This->m_Unk32 = 0;
                This->m_Unk33 =
                    (s32) (*(void **) ((char *) (*(
                                       void **) ((char *) ((char *) (*(
                                                               void **) ((char *) (*(void **) ((char *) This->m_Unk22 +
                                                                                               0x30)) +
                                                                         0x10)) +
                                                           This->m_Unk30 * 4) +
                                                 0x8)) +
                                       0x10)) +
                    8;
            }
        }
    }
    *(s32 *)This->m_Unk4 = 0;
}

void func_800660BC(class_55DD4_t *This, u8 Unk2) {
    switch (Unk2) {
        case 65:
            This->m_Unk29 = This->vtable->Unk69;
            break;

        case 66:
            This->m_Unk29 = This->vtable->Unk70;
            break;

        case 67:
            This->m_Unk29 = This->vtable->Unk71;
            break;

        default:
            break;
    }
}

void func_8006613C(class_55DD4_t *This) {
    This->m_Unk34 = 1;
}

void func_80066148(class_55DD4_t *This) {
    This->m_Unk34 = 0;
}

void func_80066150(class_55DD4_t *This) {
    This->vtable->Unk48(This, -30, 0);

    if (This->m_Unk24 == 1) {
        void *other = This->m_Unk25;

        if (other != NULL) {
            void **vtable_ptr = (void **) other;
            void *func_ptr = *(void **) ((char *) *vtable_ptr + 0x88);
            ((void (*)(void *, s32)) func_ptr)(other, 6);
        }
    }
}

void func_800661C4(void) {
}

void func_800661CC(void) {
}

void func_800661D4(class_55DD4_t *This, s32 Unk2) {
    if (This->m_Unk21) {
        (*(void (**)(s32, int, int, int))(*(s32 *) This->m_Unk21 + 128))(This->m_Unk21, Unk2, 110, 110);
    }
}

void func_80066214(class_55DD4_t *this, s32 arg1) {
    void (*pUnk76)(class_55DD4_t *, s32, s32);

    this->m_Unk30 = arg1;
    this->m_Unk31 =
        *(s32 *) ((char *) (*(
                      void **) ((char *) (*(
                                    void **) ((char *) ((char *) (*(
                                                            void **) ((char *) (*(void **) ((char *) this->m_Unk22 +
                                                                                            0x30)) +
                                                                      0x10)) +
                                                        arg1 * 4) +
                                              0x8)) +
                                0x10)) +
                  0x4);
    this->m_Unk33 =
        (s32) (*(void **) ((char *) (*(
                               void **) ((char *) ((char *) (*(
                                                       void **) ((char *) (*(void **) ((char *) this->m_Unk22 + 0x30)) +
                                                                 0x10)) +
                                                   this->m_Unk30 * 4) +
                                         0x8)) +
                           0x10)) +
        8;
    this->m_Unk32 = 0;

    pUnk76 = this->vtable->Unk76;
    pUnk76(this, this->m_Unk33, 0);
}

void func_800662A8(class_55DD4_t *This) {
    This->m_Unk35 = 1;
}

void func_800662B4(class_55DD4_t *This) {
    This->m_Unk35 = 0;
}

INCLUDE_ASM("asm/nonmatchings/55DD4", func_800662BC);
// vtable is missing from This
// void *func_800662BC(void *This, void *arg1, s32 Unk) {
//     register void *s1 asm("s1");
//     register void *a1_reg asm("a1");
//     register s32 s3 asm("s3");
//     register u16 s2 asm("s2");
//     register u32 s0 asm("s0");
//     void *(*fn)(void *, void *, s32);
//
//     s1 = This;
//     a1_reg = arg1;
//     s3 = Unk;
//     s2 = *(u16 *)((char *)a1_reg + 2);
//     a1_reg = (char *)a1_reg + 8;
//     s0 = 0;
//     if (s2 == 0) {
//         goto epilogue;
//     }
//     s0 = 1;
//     fn = (void *(*)(void *, void *, s32))(*(s32 *)((char *)(*(void **)s1) + 0x138));
// loop:
//     a1_reg = fn(s1, a1_reg, s3);
//     if (s0 < s2) {
//         s0 += 1;
//         goto loop;
//     }
//     s0 += 1;
//     s0 -= 1;
// epilogue:
//     return a1_reg;
// }

INCLUDE_ASM("asm/nonmatchings/55DD4", func_80066340);

void func_80066748(class_55DD4_t *This, s32 Unk2) {
    if (Unk2) {
        (*(void (**)(s32, class_55DD4_t *))(*(s32 *) Unk2 + 16))(Unk2, This);
        This->vtable->Unk3(This, Unk2);
        This->m_Unk36 = Unk2;
    }
}

void func_800667B0(class_55DD4_t *This) {
    s32 m_Unk36;

    m_Unk36 = This->m_Unk36;
    if (m_Unk36) {
        (*(void (**)(s32, class_55DD4_t *))(*(s32 *) m_Unk36 + 20))(m_Unk36, This);
        This->vtable->Unk4(This, This->m_Unk36);
        This->m_Unk36 = 0;
    }
}

class_55DD4_vtable_t *class_55DD4_get_vtable() {
    return &g_CLASS_55DD4_VTABLE;
}
