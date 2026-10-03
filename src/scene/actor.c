#include "scene/actor.h"
#include "file/object_model.h"
#include "scene/scene_node.h"

// Entity object related class? constructed by entity.

/* Referenced by g_ACTOR_VTABLE. */
extern void func_8001CEB4();
extern void func_8001D008();
extern void func_8001D204();
extern void func_8001D280();
extern void func_8001D33C();
extern void func_8001D374();
extern void func_8001D3A0();
extern void func_8001D3CC();
extern void func_8001D424();
extern void func_8001D450();
extern void func_8001D480();
extern void func_8001D4AC();
extern void func_8001D4DC();
extern void func_8001D600();
extern void func_8001D624();
extern void func_8001D6A4();
extern void func_8001D714();
extern void func_8001D950();
extern void func_8001DA28();
extern void func_8001DDF4();
extern void func_8001E4A4();
extern void func_800570B4();
extern void func_80057130();
extern void func_800571A8();
extern void func_800571F8();
extern void func_80057320();
extern void func_80057384();
extern void func_800573A8();
extern void func_80057444();
extern void func_8005748C();
extern void func_800574C4();
extern void func_800574FC();
extern void func_800575B0();
extern void func_800575E0();
extern void func_80057610();
extern void func_80057B90();
extern void func_80057C14();
extern void func_80057C6C();
extern void func_80057C74();
extern void func_80057C7C();
extern void func_800660BC();
extern void func_8006613C();
extern void func_80066148();
extern void func_80066150();
extern void func_800661C4();
extern void func_800661CC();
extern void func_800661D4();
extern void func_80066214();
extern void func_800662A8();
extern void func_800662B4();
extern void func_800662BC();
extern void func_80066340();
extern void func_80066748();
extern void func_800667B0();

actor_t *actor_construct(actor_t *This, s32 Unk2, s32 Unk3);
void actor_cleanup(actor_t *This);
void func_80065790(actor_t *This, u16 **Unk2, s32 Unk3);
void func_80065830(actor_t *This);
void func_80065918(actor_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5);
void func_800659D0(actor_t *This);
void func_80065A5C(actor_t *This, s32 arg1);
void func_80065AE0(actor_t *This, s32 Unk2);
void func_80065B80(actor_t *This, s32 Unk2, s32 Unk3);
void func_80065BF4(actor_t *This, s32 Value);
s32 func_80065BFC(actor_t *This, void *Unk2);
void func_80065C2C(actor_t *This);
s32 func_80065C5C(actor_t *This, void *arg1);
void func_80065CEC(actor_t *This);
s32 func_80065D64(actor_t *This, u8 Value);
s32 func_80065DBC(actor_t *This);
void func_80065DEC(actor_t *This, s32 Unk2);
s32 func_80065E1C(actor_t *This);
void func_80065F2C(actor_t *This);
void func_80065FD8(actor_t *This);
void func_800660BC(actor_t *This, u8 Unk2);
void func_8006613C(actor_t *This);
void func_80066148(actor_t *This);
void func_80066150(actor_t *This);
void func_800661C4(void);
void func_800661CC(void);
void func_800661D4(actor_t *This, s32 Unk2);
void func_80066214(actor_t *this, s32 arg1);
void func_800662A8(actor_t *This);
void func_800662B4(actor_t *This);
void func_80066748(actor_t *This, s32 Unk2);
void func_800667B0(actor_t *This);

actor_vtable_t g_ACTOR_VTABLE = {
    0x00000234,
    (base_class_t * (*) (base_class_t *) ) base_class_destructor,
    (void *(*) (void *, s32, s32)) actor_construct,
    (void (*)(void *)) actor_cleanup,
    (void (*)(base_class_t *, base_class_t *)) func_800570B4,
    (void (*)(base_class_t *, base_class_t *)) func_80057130,
    (void (*)(base_class_t *)) func_800571A8,
    (void (*)(base_class_t *, void **, void **)) base_class_iter_children,
    (void (*)(base_class_t *, base_class_t *)) base_class_add_parent,
    (void (*)(base_class_t *, base_class_t *)) base_class_remove_parent,
    (void (*)(base_class_t *)) base_class_clear_parents,
    (void (*)(base_class_t *, void **, void **)) base_class_iter_parents,
    (void (*)(base_class_t *, s32)) base_class_notify,
    (void (*)(base_class_t *)) base_class_nop,
    (void (*)(base_class_t *, base_class_t *, s32)) func_80065790,
    0x00000000,
    (void (*)(void *)) func_80065830,
    (void (*)(void *)) func_8001CEB4,
    (void (*)(void *)) func_8001D008,
    (void (*)(void *, s32, s32, s32, s32)) func_80065918,
    (void (*)(void *)) func_800659D0,
    (void (*)(void *)) func_8001D204,
    (void (*)(void *)) func_8001D280,
    (void (*)(void *)) func_8001D33C,
    (void (*)(void *)) func_80065A5C,
    (void (*)(void *)) func_8001D374,
    (void (*)(void *)) func_8001D3A0,
    (void (*)(void *)) func_8001D3CC,
    (void (*)(void *)) func_80065AE0,
    (void (*)(void *)) func_8001D424,
    (void (*)(void *)) func_8001D450,
    (void (*)(void *)) func_8001D480,
    (void (*)(void *)) func_8001D4AC,
    (void (*)(void *)) func_8001D4DC,
    (void (*)(void *)) func_800571F8,
    (void (*)(void *)) func_8001D600,
    (void (*)(void *)) func_8001D624,
    (void (*)(void *)) func_8001D6A4,
    (void (*)(void *, s32, s32)) func_80065B80,
    (void (*)(void *)) func_80057320,
    (void (*)(void *)) func_8001D714,
    (void (*)(void *)) func_8001D950,
    (void (*)(void *)) func_8001DA28,
    (void (*)(void *)) func_8001DDF4,
    0x00000000,
    (void (*)(void *)) func_8001E4A4,
    (void (*)(void *)) func_80057384,
    (void (*)(void *)) func_800573A8,
    (void (*)(void *)) func_80057444,
    (void (*)(void *, s32, s32)) func_8005748C,
    (void (*)(void *)) func_800574C4,
    (void (*)(void *)) func_800574FC,
    (void (*)(void *)) func_800575B0,
    (void (*)(void *)) func_800575E0,
    (void (*)(void *)) func_80057610,
    (void (*)(void *, s32, s32)) func_80057B90,
    (void (*)(void *, s32, s32)) func_80057C14,
    (void (*)(void *, s32)) func_80057C6C,
    (void (*)(void *)) func_80057C74,
    (void (*)(void *)) func_80057C7C,
    (void (*)(void *, s32)) func_80065BF4,
    (s32(*)(void *, s32)) func_80065BFC,
    (void (*)(void *)) func_80065C2C,
    (void (*)(void *)) func_80065D64,
    (s32(*)(void *)) func_80065DBC,
    (void (*)(void *)) func_80065DEC,
    (void (*)(void *, s32)) func_80065FD8,
    (void (*)(void *, s32)) func_800660BC,
    (void (*)(void *)) func_8006613C,
    (void (*)(void *)) func_80066148,
    (void (*)(void *)) func_80066150,
    (void (*)(void *)) func_800661C4,
    (void (*)(void *)) func_800661CC,
    (void (*)(void *)) func_800661D4,
    (void (*)(void *, s32)) func_80066214,
    (void (*)(void *)) func_800662A8,
    (void (*)(void *)) func_800662B4,
    (void (*)(void *, s32, s32)) func_800662BC,
    (void *(*) (void *, void *, s32)) func_80066340,
    (void (*)(void *, s32)) func_80066748,
    (void (*)(void *)) func_800667B0,
};

actor_t *actor_create(s32 Unk1, s32 Unk2) {
    actor_t *allocated = ALLOCATE_STRUCT(actor_t);

    if (allocated) {
        if (actor_get_vtable()->actor_construct(allocated, Unk1, Unk2)) {
            return allocated;
        }

        memory_free_mem(allocated);
    }

    return NULL;
}

actor_t *actor_construct(actor_t *This, s32 Unk2, s32 Unk3) {
    if (scene_node_get_vtable()->Construct(This)) {
        This->vtable = actor_get_vtable();
        This->m_Unk21 = Unk3;
        This->m_Unk22 = 0;
        This->m_Unk25 = 0;
        This->m_Unk27 = 0;
        This->m_Unk36 = 0;

        if (!This->vtable->Unk60(This, Unk2)) {
            This->vtable->Attach(This, This->m_Unk22);
            This->vtable->Unk15(This);
            return This;
        }

        scene_node_get_vtable()->Cleanup(This);
    }

    return NULL;
}

void actor_cleanup(actor_t *This) {
    This->vtable->Unk61(This);
    scene_node_get_vtable()->Cleanup(This);
}

void func_80065790(actor_t *This, u16 **Unk2, s32 Unk3) {
    scene_node_get_vtable()->OnNotify(This, Unk2, Unk3);

    if (**Unk2 == 0x5F03 && Unk3 == 1 && !This->m_Unk23) {
        This->vtable->Destroy(This);
    }
}

void func_80065830(actor_t *This) {
    scene_node_get_vtable()->Unk23(This, 0);
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

void func_80065918(actor_t *This, s32 Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    if (!This->m_Unk2) {
        scene_node_get_vtable()->Unk18(This, Unk4, Unk5);

        if (Unk3 && !This->m_Unk19) {
            This->vtable->Attach(This, Unk3);
        }

        This->vtable->Unk78(This, Unk2);
    }
}

void func_800659D0(actor_t *This) {
    if (This->m_Unk2) {
        This->vtable->Unk79(This);

        if (This->m_Unk19) {
            This->vtable->Detach(This, This->m_Unk19);
        }

        scene_node_get_vtable()->Unk19(This);
    }
}

void func_80065A5C(actor_t *This, s32 arg1) {
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

void func_80065AE0(actor_t *This, s32 Unk2) {
    s32 i;
    void **obj_list;

    obj_list = This->m_Unk27;

    for (i = 0; i < This->m_Unk26; i++, obj_list++) {
        void *current_obj = *obj_list;
        void *vtable = *(void **) current_obj;

        ((void (*)(void *, s32))((void **) vtable)[28])(current_obj, Unk2);
    }

    scene_node_get_vtable()->Unk27(This, Unk2);
}

void func_80065B80(actor_t *This, s32 Unk2, s32 Unk3) {
    if (Unk3 == 2) {
        This->vtable->Unk65(This, Unk2);
    }

    if (Unk3 == 4) {
        This->vtable->Destroy(This);
    }
}

void func_80065BF4(actor_t *This, s32 Value) {
    This->m_Unk24 = Value;
}

s32 func_80065BFC(actor_t *This, void *Unk2) {
    if (!This->m_Unk22) {
        return func_80065C5C(This, Unk2);
    }

    return 0;
}

void func_80065C2C(actor_t *This) {
    if (This->m_Unk22) {
        func_80065CEC(This);
    }
}

s32 func_80065C5C(actor_t *This, void *arg1) {
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

void func_80065CEC(actor_t *This) {
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

s32 func_80065D64(actor_t *This, u8 Value) {
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

s32 func_80065DBC(actor_t *This) {
    if (!This->m_Unk27) {
        return func_80065E1C(This);
    }

    return 0;
}

void func_80065DEC(actor_t *This, s32 Unk2) {
    if (This->m_Unk27) {
        func_80065F2C(This, Unk2);
    }
}

extern scene_node_t *func_80056FE4(void);

s32 func_80065E1C(actor_t *This) {
    struct {
        s32 index;
        char dummy[12];
    } loc;
    class_object_model_t *obj;
    s32 i;
    s32 count;
    void **slot;
    void *mem;

    if (&loc.dummy[0] == &loc.dummy[11]) {
    }
    obj = (class_object_model_t *) This->m_Unk22;
    count = obj->vtable->Unk31(obj, NULL, &loc.index) & 0xFF;
    mem = memory_allocate_mem(count * 4);
    This->m_Unk27 = mem;
    if (mem == NULL) {
        goto alloc_fail;
    }
    mem = memory_allocate_mem(count);
    This->m_Unk28 = (u32) mem;
    if (mem == NULL) {
        goto alloc_fail;
    }
    obj = (class_object_model_t *) This->m_Unk22;
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
    This->m_Unk25 = (s32) This->m_Unk27[loc.index];
    return 0;
alloc_fail:
    This->m_Unk28 = 0;
loop_fail:
    func_80065F2C(This);
    return 1;
}

void func_80065F2C(actor_t *This) {
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
            (*(void (**)(void *))(*(u32 *) obj + 4))(obj);
            count = This->m_Unk26;
        loop_test:
            This->m_Unk26 = count - 1;
            if (count > 0) {
                goto loop_body;
            }
            This->m_Unk25 = 0;
        }
    }
    This->m_Unk28 = (u32) memory_free_mem((void *) This->m_Unk28);
    This->m_Unk27 = memory_free_mem(This->m_Unk27);
}

void func_80065FD8(actor_t *This) {
    s32 neu;

    This->m_Unk8 += 1;
    if (This->m_Unk34) {
        ((void (*)(void)) This->m_Unk29)();
    }
    if (This->m_Unk35 != 0) {
        if (This->m_Unk31 >= 2) {
            This->m_Unk33 = ((s32(*)(void *, s32, s32)) This->vtable->Unk76)(This, This->m_Unk33, 0);
            neu = This->m_Unk32 + 1;
            This->m_Unk32 = neu;
            if (neu >= This->m_Unk31) {
                This->m_Unk32 = 0;
                This->m_Unk33 =
                    (s32) (*(
                        void **) ((char *) (*(
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
    *(s32 *) This->m_Unk4 = 0;
}

void func_800660BC(actor_t *This, u8 Unk2) {
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

void func_8006613C(actor_t *This) {
    This->m_Unk34 = 1;
}

void func_80066148(actor_t *This) {
    This->m_Unk34 = 0;
}

void func_80066150(actor_t *This) {
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

void func_800661D4(actor_t *This, s32 Unk2) {
    if (This->m_Unk21) {
        (*(void (**)(s32, int, int, int))(*(s32 *) This->m_Unk21 + 128))(This->m_Unk21, Unk2, 110, 110);
    }
}

void func_80066214(actor_t *this, s32 arg1) {
    void (*pUnk76)(actor_t *, s32, s32);

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

void func_800662A8(actor_t *This) {
    This->m_Unk35 = 1;
}

void func_800662B4(actor_t *This) {
    This->m_Unk35 = 0;
}

/* vtable slot 0x134 (entity.h: tick_anim): walks an animation script,
 * issuing one set_motion per keyframe via slot 0x138. */
void *func_800662BC(actor_t *This, void *arg1, s32 arg2) {
    u32 count;
    u32 index;

    count = *(u16 *) ((u8 *) arg1 + 2);
    arg1 = (u8 *) arg1 + 8;
    for (index = 0; index < count; index++) {
        arg1 = This->vtable->Unk77(This, arg1, arg2);
    }
    return arg1;
}

INCLUDE_ASM("asm/nonmatchings/scene/actor", func_80066340);

void func_80066748(actor_t *This, s32 Unk2) {
    if (Unk2) {
        (*(void (**)(s32, actor_t *))(*(s32 *) Unk2 + 16))(Unk2, This);
        This->vtable->Attach(This, Unk2);
        This->m_Unk36 = Unk2;
    }
}

void func_800667B0(actor_t *This) {
    s32 m_Unk36;

    m_Unk36 = This->m_Unk36;
    if (m_Unk36) {
        (*(void (**)(s32, actor_t *))(*(s32 *) m_Unk36 + 20))(m_Unk36, This);
        This->vtable->Detach(This, This->m_Unk36);
        This->m_Unk36 = 0;
    }
}

actor_vtable_t *actor_get_vtable() {
    return &g_ACTOR_VTABLE;
}
