#include "base/frame_phase.h"
#include "base/base_class.h"

frame_phase_vtable_t g_FRAME_PHASE_VTABLE = {
    0x5,
    base_class_destructor,
    frame_phase_construct,
    frame_phase_cleanup,
    base_class_attach,
    base_class_detach,
    base_class_detach_all,
    base_class_iter_children,
    base_class_add_parent,
    frame_phase_remove_parent,
    base_class_clear_parents,
    base_class_iter_parents,
    frame_phase_notify,
    base_class_nop,
    base_class_on_notify,
    NULL,
    frame_phase_reset,
    frame_phase_advance,
    frame_phase_get_phase,
    frame_phase_set_waiting,
    frame_phase_clear_waiting,
    frame_phase_is_waiting,
    frame_phase_set_finished,
};

frame_phase_t *frame_phase_create(void) {
    frame_phase_t *allocated = (frame_phase_t *) memory_allocate_mem(0x1C);

    if (allocated) {
        frame_phase_get_vtable()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void frame_phase_construct(frame_phase_t *This) {
    base_class_get_vtable()->Construct(This);
    This->vtable = frame_phase_get_vtable();
    This->vtable->frame_phase_reset(This, 0);
}

void frame_phase_cleanup(frame_phase_t *This) {
    base_class_get_vtable()->Cleanup(This);
}

void frame_phase_remove_parent(frame_phase_t *This, base_class_t *Unk) {
    void **node;

    node = (void **) This->m_NotifyCursor;
    if (node != NULL && Unk == node[1]) {
        This->m_NotifyCursor = (s32) node[0];
    }
    base_class_get_vtable()->RemoveParent(This, Unk);
}

void frame_phase_notify(frame_phase_t *This, s32 Unk) {
    base_class_t *cur;

    This->m_NotifyCursor = This->m_Parents;
    linked_list_next(&cur, (linked_list_node_t **) &This->m_NotifyCursor);
    while (cur != NULL) {
        cur->vtable->OnNotify(cur, This, Unk);
        linked_list_next(&cur, (linked_list_node_t **) &This->m_NotifyCursor);
    }
    This->m_NotifyCursor = 0;
}

void frame_phase_reset(frame_phase_t *This, s32 Unk) {
    This->m_Phase = Unk;
    This->m_Finished = 0;
    This->m_Waiting = 0;
    This->m_NotifyCursor = 0;
}

void frame_phase_advance(frame_phase_t *This) {
    s32 value;

    value = 4;
    if (!This->m_Finished) {
        value = 3;
        if (!This->m_Waiting) {
            value = 2;
            ++This->m_Phase;
        }
    }
    This->vtable->Notify(This, value);
}

s32 frame_phase_get_phase(frame_phase_t *This) {
    return This->m_Phase;
}

void frame_phase_set_waiting(frame_phase_t *This) {
    This->m_Waiting = 1;
}

void frame_phase_clear_waiting(frame_phase_t *This) {
    This->m_Waiting = 0;
}

s32 frame_phase_is_waiting(frame_phase_t *This) {
    return This->m_Waiting;
}

void frame_phase_set_finished(frame_phase_t *This) {
    This->m_Finished = 1;
}

frame_phase_vtable_t *frame_phase_get_vtable(void) {
    return &g_FRAME_PHASE_VTABLE;
}
