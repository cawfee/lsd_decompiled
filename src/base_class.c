#include "common.h"

#include "base_class.h"

s32 D_8008A820 = 0;

base_class_vtable_t g_BASE_CLASS_VTABLE = {
    0,
    base_class_destructor,
    base_class_construct,
    base_class_cleanup,
    base_class_attach,
    base_class_detach,
    base_class_detach_all,
    base_class_iter_children,
    base_class_add_parent,
    base_class_remove_parent,
    base_class_clear_parents,
    base_class_iter_parents,
    base_class_notify,
    base_class_nop,
    base_class_on_notify,
    NULL,
};

base_class_t *base_class_destructor(base_class_t *This) {
    This->vtable->Cleanup(This);
    memory_free_mem(This);
    return NULL;
}

void base_class_construct(base_class_t *This) {
    This->vtable = base_class_get_vtable();
    This->m_Parents = NULL;
    This->m_Children = NULL;
}

void base_class_cleanup(base_class_t *This) {
    This->vtable->Notify(This, 1);
    This->vtable->DetachAll(This);
    This->vtable->ClearParents(This);
}

void base_class_attach(base_class_t *This, base_class_t *Child) {
    if (linked_list_prepend(&This->m_Children, Child)) {
        Child->vtable->AddParent(Child, This);
    }
}

void base_class_detach(base_class_t *This, base_class_t *Child) {
    linked_list_remove(&This->m_Children, Child);
    Child->vtable->RemoveParent(Child, This);
}

void base_class_detach_all(base_class_t *This) {
    void *cur;
    void **curp;
    void *list;

    curp = &cur;
    list = This->m_Children;
    linked_list_next(curp, (linked_list_node_t **)&list);
    while (cur != NULL) {
        This->vtable->Detach(This, (base_class_t *)cur);
        linked_list_next(curp, (linked_list_node_t **)&list);
    }
}

void base_class_iter_children(base_class_t *This, void **out_value, void **cursor) {
    if (!*out_value) {
        *cursor = This->m_Children;
    }

    linked_list_next(out_value, (linked_list_node_t **)cursor);
}

void base_class_add_parent(base_class_t *This, base_class_t *Parent) {
    linked_list_prepend(&This->m_Parents, Parent);
}

void base_class_remove_parent(base_class_t *This, base_class_t *Parent) {
    linked_list_remove(&This->m_Parents, Parent);
}

void base_class_clear_parents(base_class_t *This) {
    linked_list_clear(&This->m_Parents);
    This->m_Parents = NULL;
}

void base_class_iter_parents(base_class_t *This, void **out_value, void **cursor) {
    if (!*out_value) {
        *cursor = This->m_Parents;
    }

    linked_list_next(out_value, (linked_list_node_t **)cursor);
}

s32 linked_list_prepend(linked_list_node_t **list, void *value) {
    void *mem;

    mem = memory_allocate_mem(8);

    if (mem) {
        *((u32 *) mem + 0) = *(u32 *) list;
        *((u32 *) mem + 1) = (u32)value;
        *list = mem;
        return 1;
    }

    return 0;
}

void linked_list_remove(linked_list_node_t **list, void *target) {
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

void linked_list_clear(linked_list_node_t **list_head) {
    /* Arg is &m_Parents. Original typed this as base_class_t* and read
     * This->vtable as the head node (offset 0). */
    base_class_vtable_t *next;
    base_class_vtable_t *cur;

    next = ((base_class_t *)list_head)->vtable;
    cur = ((base_class_t *)list_head)->vtable;
    if (cur) {
        do {
            next = (base_class_vtable_t *)next->type_id;
            memory_free_mem(cur);
            cur = next;
        } while (next);
    }
}

void base_class_notify(base_class_t *This, s32 code) {
    void *cur;
    void *list;

    list = (void *)This->m_Parents;
    linked_list_next(&cur, (linked_list_node_t **)&list);
    while (cur != NULL) {
        ((base_class_t *)cur)->vtable->OnNotify((base_class_t *)cur, This, code);
        linked_list_next(&cur, (linked_list_node_t **)&list);
    }
}

void base_class_nop(base_class_t *This) {
}

void base_class_on_notify(base_class_t *This, base_class_t *Sender, s32 code) {
    if (code == 1) {
        This->vtable->Detach(This, Sender);
    }
}

base_class_vtable_t *base_class_get_vtable(void) {
    return &g_BASE_CLASS_VTABLE;
}

void linked_list_next(void *out_value, linked_list_node_t **cursor) {
    if (*cursor) {
        *(u32 *) out_value = *((u32 *) *cursor + 1);
        *cursor = *(void **) *cursor;
    } else {
        *(u32 *) out_value = 0;
    }
}

s32 destroy_list(base_class_t **arr, s32 n) {
    base_class_t *obj;

    if (n-- > 0) {
        do {
            obj = *arr;
            *arr = obj->vtable->Destroy(obj);
            arr++;
        } while (n-- > 0);
    }
}

void func_8001844C(s32 value) {
    D_8008A820 = value;
}

s32 func_80018458(void) {
    return D_8008A820;
}
