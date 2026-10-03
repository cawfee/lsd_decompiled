#include "base/timer.h"
#include "base/base.h"
#include "base/frame_phase.h"
#include "graphics/light.h"
#include "graphics/renderer.h"

// not timer related but has timer seeming functions
// todo new name
// todo cleanup

static timer_vtable_t g_TIMER_VTABLE = {
    .type_id = 0x30,
    .Destroy = base_class_destructor,
    .Construct = timer_create,
    .Cleanup = base_class_cleanup,
    .Attach = base_class_attach,
    .Detach = base_class_detach,
    .DetachAll = base_class_detach_all,
    .IterChildren = base_class_iter_children,
    .AddParent = base_class_add_parent,
    .RemoveParent = base_class_remove_parent,
    .ClearParents = base_class_clear_parents,
    .IterParents = base_class_iter_parents,
    .Notify = base_class_notify,
    .Nop = base_class_nop,
    .OnNotify = timer_on_notify,
    .Unused1 = NULL,
    .Reset = timer_reset,
    .Unk16 = func_8003E10C,
    .Unk17 = func_8003E280,
    .Unk18 = NULL,
    .Unk19 = NULL,
    .Unk20 = func_8003E418,
    .Unk21 = NULL,
    .Increment = timer_increment,
    .Unk23 = func_8003E4B8,
    .Unk24 = timer_begin_frame,
    .Unk25 = timer_end_frame,
};

void timer_create(timer_t *This) {
    base_class_get_vtable()->Construct(This);

    This->vtable = timer_get_vtable();
    This->vtable->Reset(This);
}

// Use timer_t as large enough struct
// Sender is generic class?
void timer_on_notify(timer_t *This, base_class_t *Sender, s32 Code) {
    u32 type_id;
    base_class_get_vtable()->OnNotify(This, Sender, Code);

    // 0xF of the type id is ..?
    type_id = Sender->vtable->type_id & 0xF;

    // TODO check if on notify
    if (type_id == 1) {
        This->vtable->Unk20(This, Sender, Code);
    } else if (type_id == 2) {
        This->vtable->Unk21(This, Sender, Code);
    } else if (type_id == 5) {
        This->vtable->Increment(This, Sender, Code);
    }
}

void timer_reset(timer_t *This) {
    This->m_TicksPassed = 0;
    This->m_Unk7 = 0;
}

void func_8003E10C(timer_t *This, s32 *Unk2, s32 Unk3) {
    s32 value;
    timer_vtable_t *vtable;
    void *unk5;

    value = Unk2[2];
    vtable = This->vtable;
    if (value == 0) {
        value = (s32) frame_phase_create();
    }
    This->m_Unk3 = (void *) value;

    value = Unk2[3];
    if (value == 0) {
        value = (s32) func_80042694();
    }
    This->m_Unk4 = (void *) value;

    value = Unk2[4];
    if (value == 0) {
        value = (s32) renderer_create();
    }
    This->m_Unk5 = (void *) value;

    This->m_Unk2 = (s32) Unk2;
    unk5 = This->m_Unk5;
    vtable->Attach(This, Unk2[0]);
    vtable->Attach(This, Unk2[1]);
    vtable->Attach(This, (s32) This->m_Unk3);
    vtable->Unk18(This, 0, 0, 0);
    This->m_Unk8 = Unk3;
    if (Unk3 == 0) {
        (*(void (**)(void *, s32))(*(s32 *) unk5 + 0x10))(unk5, Unk2[0]);
        (*(void (**)(void *, s32))(*(s32 *) unk5 + 0x10))(unk5, (s32) This->m_Unk3);
        (*(void (**)(void *, s32))(*(s32 *) This->m_Unk4 + 0x10))(This->m_Unk4, (s32) This->m_Unk3);
        vtable->Unk23(This, 2);
        vtable->Unk17(This);
    }
}

void func_8003E280(timer_t *This) {
    timer_vtable_t *vtable;
    s32 m_Unk8;
    void *m_Unk5;
    void *m_Unk4;
    void *m_Unk3;

    vtable = This->vtable;
    vtable->Unk19(This);
    m_Unk8 = This->m_Unk8;
    m_Unk5 = This->m_Unk5;
    if (m_Unk8 == 0) {
        (*(void (**)(void *, s32))(*(s32 *) This->m_Unk4 + 0x14))(This->m_Unk4, (s32) This->m_Unk3);
        (*(void (**)(void *, s32))(*(s32 *) m_Unk5 + 0x14))(m_Unk5, (s32) This->m_Unk3);
        (*(void (**)(void *, s32))(*(s32 *) m_Unk5 + 0x14))(m_Unk5, *(s32 *) This->m_Unk2);
    }
    vtable->Detach(This, (s32) This->m_Unk3);
    vtable->Detach(This, *(s32 *) (This->m_Unk2 + 4));
    vtable->Detach(This, *(s32 *) This->m_Unk2);
    if (*(s32 *) (This->m_Unk2 + 0x10) != (s32) m_Unk5) {
        This->m_Unk5 = (void *) (*(s32(**)(void *))(*(s32 *) m_Unk5 + 4))(m_Unk5);
    }
    m_Unk4 = This->m_Unk4;
    if (*(s32 *) (This->m_Unk2 + 0xC) != (s32) m_Unk4) {
        This->m_Unk4 = (void *) (*(s32(**)(void *))(*(s32 *) m_Unk4 + 4))(m_Unk4);
    }
    m_Unk3 = This->m_Unk3;
    if (*(s32 *) (This->m_Unk2 + 8) != (s32) m_Unk3) {
        This->m_Unk3 = (void *) (*(s32(**)(void *))(*(s32 *) m_Unk3 + 4))(m_Unk3);
    }
}

void func_8003E418(timer_t *This, base_class_t *Sender, s32 Code) {
    s32 obj;

    if (Code == 2) {
        (*(void (**)(void *))(*(s32 *) This->m_Unk3 + 0x44))(This->m_Unk3);
        obj = *(s32 *) (This->m_Unk2 + 4);
        (*(void (**)(s32))(*(s32 *) obj + 0x44))(obj);
        (*(void (**)(s32))(*(s32 *) obj + 0x48))(obj);
    }
}

void timer_increment(timer_t *This, base_class_t *Sender, s32 Code) {
    This->m_TicksPassed++;
}

void func_8003E4B8(timer_t *This, s32 Unk2) {
    timer_vtable_t *vtable;
    void (*fn)(void *);

    vtable = This->vtable;
    This->m_Unk7 = Unk2;
    vtable->Notify(This, Unk2);
    if (Unk2 == 2) {
        fn = vtable->Unk24;
        goto do_call;
    }
    if (Unk2 == 3) {
        fn = vtable->Unk25;
    do_call:
        fn(This);
    }
}

void timer_begin_frame(timer_t *This) {
    u32 *m_Unk2;

    m_Unk2 = (u32 *) This->m_Unk2;
    This->m_TicksPassed = 0;
    (*(int (**)(u32))(*(u32 *) *m_Unk2 + 72))(*m_Unk2);
}

void timer_end_frame(timer_t *This) {
    (*(void (**)(u32))(**(u32 **) This->m_Unk2 + 76))(*(u32 *) This->m_Unk2);
    This->m_TicksPassed = 0;
}

timer_vtable_t *timer_get_vtable(void) {
    return &g_TIMER_VTABLE;
}
