#include "common.h"

#include "base_class.h"

extern base_class_vtable_t **g_BASE_CLASS_VTABLE;

s32 base_class_destructor(base_class_t *This) {
    This->vtable->base_class_cleanup(This);
    memory_free_mem(This);
    return 0;
}

void base_class_construct(base_class_t *This) {
    This->vtable = base_class_get_vtable();
    This->m_Unk1 = 0;
    This->m_Unk0 = 0;
}

void base_class_cleanup(base_class_t *This) {
    This->vtable->Unk11(This, 1);
    This->vtable->Unk5(This);
    This->vtable->Unk9(This);
}

void func_80017F98(base_class_t *This, base_class_t *Next) {
    if (func_800181AC(&This->m_Unk0, Next)) {
        Next->vtable->Unk7(Next, This);
    }
}

void func_80017FF0(base_class_t *This, base_class_t *Next) {
    func_80018208(&This->m_Unk0, Next);
    Next->vtable->Unk8(Next, This);
}

void func_80018040(base_class_t *This) {
    void *cur;
    void **curp;
    void *list;

    curp = &cur;
    list = This->m_Unk0;
    func_800183A0(curp, &list);
    while (cur != NULL) {
        This->vtable->Unk4(This, cur);
        func_800183A0(curp, &list);
    }
}

void func_800180BC(base_class_t *This, void **Unk2, void **Unk3) {
    if (!*Unk2) {
        *Unk3 = This->m_Unk0;
    }

    func_800183A0(Unk2, Unk3);
}

void func_800180FC(base_class_t *This, s32 Unk2) {
    func_800181AC(&This->m_Unk1, Unk2);
}

void func_8001811C(base_class_t *This, s32 Unk2) {
    func_80018208(&This->m_Unk1, Unk2);
}

void func_8001813C(base_class_t *This) {
    func_80018288(&This->m_Unk1);
    This->m_Unk1 = NULL;
}

void func_8001816C(base_class_t *This, void **Unk2, void **Unk3) {
    if (!*Unk2) {
        *Unk3 = This->m_Unk1;
    }

    func_800183A0(Unk2, Unk3);
}

s32 func_800181AC(void **Unk1, void *Unk2) {
    void *mem;

    mem = memory_allocate_mem(8);

    if (mem) {
        *((u32 *) mem + 0) = *(u32 *) Unk1;
        *((u32 *) mem + 1) = Unk2;
        *Unk1 = mem;
        return 1;
    }

    return 0;
}

void func_80018208(void **list, void *target) {
    void *node;
    void *prev;

    node = *list;
    prev = NULL;
    if (node != NULL) {
        do {
            if (*((void **)node + 1) == target) {
                if (prev != NULL) {
                    *(void **)prev = *(void **)node;
                } else {
                    *list = *(void **)node;
                }
                memory_free_mem(node);
                return;
            }
            prev = node;
            node = *(void **)node;
        } while (node != NULL);
    }
}

void func_80018288(base_class_t *This) {
    base_class_vtable_t *vtable_1;
  base_class_vtable_t *vtable_2;

  vtable_1 = This->vtable;
  vtable_2 = This->vtable;
  if ( vtable_2 )
  {
    do
    {
      vtable_1 = (base_class_vtable_t *)vtable_1->value;
      memory_free_mem(vtable_2);
      vtable_2 = vtable_1;
    }
    while ( vtable_1 );
  }
}

void func_800182CC(base_class_t *This, s32 Unk) {
    void *cur;
    void *list;

    list = (void *)This->m_Unk1;
    func_800183A0(&cur, &list);
    while (cur != NULL) {
        ((base_class_t *)cur)->vtable->Unk13(cur, This, Unk);
        func_800183A0(&cur, &list);
    }
}

void func_80018350(void) {
}

void func_80018358(base_class_t *This, void *Unk2, s32 Unk3) {
    if (Unk3 == 1) {
        This->vtable->Unk4(This, Unk2);
    }
}

base_class_vtable_t *base_class_get_vtable(void) {
    return &g_BASE_CLASS_VTABLE;
}

void func_800183A0(void *Unk1, void **Unk2) {
    if (*Unk2) {
        *(u32 *) Unk1 = *((u32 *) *Unk2 + 1);
        *Unk2 = *(void **) *Unk2;
    } else {
        *(u32 *) Unk1 = 0;
    }
}
