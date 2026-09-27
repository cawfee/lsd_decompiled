#include "frame_phase.h"
#include "base_class.h"

void func_80042450(frame_phase_t *);
void func_800424A8(frame_phase_t *);
void func_800424E0(frame_phase_t *, void *);
void func_80042550(frame_phase_t *, s32);
void func_800425D8(frame_phase_t *, s32);
void func_800425EC(frame_phase_t *);
s32 func_8004264C(frame_phase_t *);
void func_80042658(frame_phase_t *);
void func_80042664(frame_phase_t *);
s32 func_8004266C(frame_phase_t *);
void func_80042678(frame_phase_t *);

frame_phase_vtable_t D_8006EF50 = {
    0x00000005,
    base_class_destructor,
    (void (*)(void *))func_80042450,
    (void (*)(base_class_t *))func_800424A8,
    base_class_attach,
    base_class_detach,
    base_class_detach_all,
    base_class_iter_children,
    base_class_add_parent,
    (void (*)(base_class_t *, base_class_t *))func_800424E0,
    base_class_clear_parents,
    base_class_iter_parents,
    (void (*)(base_class_t *, s32))func_80042550,
    base_class_nop,
    base_class_on_notify,
    NULL,
    (void (*)(void *, s32))func_800425D8,
    (void (*)(void *))func_800425EC,
    (void (*)(void *))func_8004264C,
    (void (*)(void *))func_80042658,
    (void (*)(void *))func_80042664,
    (void (*)(void *))func_8004266C,
    (void (*)(void *))func_80042678,
};

frame_phase_t *func_80042400(void) {
    frame_phase_t *allocated = (frame_phase_t *) memory_allocate_mem(0x1C);

    if (allocated) {
        func_80042684()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_80042450(frame_phase_t *This) {
    base_class_get_vtable()->Construct(This);
    This->vtable = func_80042684();
    This->vtable->Unk15(This, 0);
}

void func_800424A8(frame_phase_t *This) {
    base_class_get_vtable()->Cleanup(This);
}

void func_800424E0(frame_phase_t *This, void *Unk) {
    void **node;

    node = (void **)This->m_Unk5;
    if (node != NULL && Unk == node[1]) {
        This->m_Unk5 = (s32)node[0];
    }
    base_class_get_vtable()->RemoveParent(This, Unk);
}

void func_80042550(frame_phase_t *This, s32 Unk) {
    base_class_t *cur;

    This->m_Unk5 = This->m_Unk1;
    linked_list_next(&cur, (linked_list_node_t **)&This->m_Unk5);
    while (cur != NULL) {
        cur->vtable->OnNotify(cur, This, Unk);
        linked_list_next(&cur, (linked_list_node_t **)&This->m_Unk5);
    }
    This->m_Unk5 = 0;
}

void func_800425D8(frame_phase_t *This, s32 Unk) {
    This->m_Unk2 = Unk;
    This->m_Unk4 = 0;
    This->m_Unk3 = 0;
    This->m_Unk5 = 0;
}

void func_800425EC(frame_phase_t *This) {
    s32 value;

    value = 4;
    if (!This->m_Unk4) {
        value = 3;
        if (!This->m_Unk3) {
            value = 2;
            ++This->m_Unk2;
        }
    }
    This->vtable->Notify(This, value);
}

s32 func_8004264C(frame_phase_t *This) {
    return This->m_Unk2;
}

void func_80042658(frame_phase_t *This) {
    This->m_Unk3 = 1;
}

void func_80042664(frame_phase_t *This) {
    This->m_Unk3 = 0;
}

s32 func_8004266C(frame_phase_t *This) {
    return This->m_Unk3;
}

void func_80042678(frame_phase_t *This) {
    This->m_Unk4 = 1;
}

frame_phase_vtable_t *func_80042684(void) {
    return &D_8006EF50;
}
