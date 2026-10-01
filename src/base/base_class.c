#include "common.h"

#include "base/base_class.h"
#include "memory/memory.h"

static s32 g_MEMORY_LOCKED = 0;

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
    linked_list_next(curp, &list);
    while (cur != NULL) {
        This->vtable->Detach(This, cur);
        linked_list_next(curp, &list);
    }
}

void base_class_iter_children(base_class_t *This, void **OutValue, void **Cursor) {
    if (!*OutValue) {
        *Cursor = This->m_Children;
    }

    linked_list_next(OutValue, Cursor);
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

void base_class_iter_parents(base_class_t *This, void **OutValue, void **Cursor) {
    if (!*OutValue) {
        *Cursor = This->m_Parents;
    }

    linked_list_next(OutValue, Cursor);
}

s32 linked_list_prepend(linked_list_node_t **List, void *Value) {
    linked_list_node_t *mem;

    mem = memory_allocate_mem(sizeof(linked_list_node_t));

    if (mem) {
        mem->m_Next = *List;
        mem->m_Value = Value;
        *List = mem;
        return 1;
    }

    return 0;
}

void linked_list_remove(linked_list_node_t **List, void *Target) {
    linked_list_node_t *node;
    linked_list_node_t *prev;

    node = *List;
    prev = NULL;
    if (node != NULL) {
        do {
            if (node->m_Value == Target) {
                if (prev != NULL) {
                    prev->m_Next = node->m_Next;
                } else {
                    *List = node->m_Next;
                }
                memory_free_mem(node);
                return;
            }
            prev = node;
            node = node->m_Next;
        } while (node != NULL);
    }
}

void linked_list_clear(linked_list_node_t **ListHead) {
    linked_list_node_t *next;
    linked_list_node_t *cur;

    next = *ListHead;
    cur = *ListHead;
    if (cur) {
        do {
            next = next->m_Next;
            memory_free_mem(cur);
            cur = next;
        } while (next);
    }
}

void base_class_notify(base_class_t *This, s32 Code) {
    void *cur;
    void *list;

    list = This->m_Parents;
    linked_list_next(&cur, &list);
    while (cur != NULL) {
        base_class_t *obj;

        obj = cur;
        obj->vtable->OnNotify(obj, This, Code);
        linked_list_next(&cur, &list);
    }
}

void base_class_nop(base_class_t *This) {
}

void base_class_on_notify(base_class_t *This, base_class_t *Sender, s32 Code) {
    if (Code == 1) {
        This->vtable->Detach(This, Sender);
    }
}

base_class_vtable_t *base_class_get_vtable(void) {
    return &g_BASE_CLASS_VTABLE;
}

void linked_list_next(void **OutValue, void **Cursor) {
    linked_list_node_t *node;

    node = *Cursor;
    if (node) {
        *OutValue = node->m_Value;
        node = *Cursor;
        *Cursor = node->m_Next;
    } else {
        *OutValue = NULL;
    }
}

s32 destroy_list(base_class_t **Array, s32 Count) {
    base_class_t *object;

    if (Count-- > 0) {
        do {
            object = *Array;
            *Array = object->vtable->Destroy(object);
            Array++;
        } while (Count-- > 0);
    }
}

void memory_set_lock(s32 Value) {
    g_MEMORY_LOCKED = Value;
}

s32 memory_is_locked(void) {
    return g_MEMORY_LOCKED;
}
