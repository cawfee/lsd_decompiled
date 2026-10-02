#include "scene/notify_node.h"

#include "base/base.h"
#include "base/transform.h"

void func_8004D3DC(void *);
void func_8001CBA4(void *);
void func_8001CC48(void *);
void func_8001CCB4(void *);
void func_8001CD20(void *);
void func_8001CD60(void *);
void func_8004D42C(void *);
void func_8001CEB4(void *);
void func_8001D008(void *);
void func_8001D0EC(void *);
void func_8001D1A4(void *);
void func_8001D204(void *);
void func_8001D280(void *);
void func_8001D33C(void *);
void func_8001D344(void *);
void func_8001D374(void *);
void func_8001D3A0(void *);
void func_8001D3CC(void *);
void func_8001D3F8(void *);
void func_8001D424(void *);
void func_8001D450(void *);
void func_8001D480(void *);
void func_8001D4AC(void *);
void func_8001D4DC(void *);
void func_8001D568(void *);
void func_8001D600(void *);
void func_8001D624(void *);
void func_8001D6A4(void *);
void func_8001D6AC(void *);
void func_8004D434(void *);
void func_8001D714(void *);
void func_8001D950(void *);
void func_8001DA28(void *);
void func_8001DDF4(void *);
void func_8001E49C(void *);
void func_8001E4A4(void *);
void func_8004D47C(void *);
void func_8004D500(void *);

notify_node_vtable_t D_80086AA0 = {
    0x24,
    base_class_destructor,
    func_8004D3DC,
    func_8001CBA4,
    func_8001CC48,
    func_8001CCB4,
    func_8001CD20,
    base_class_iter_children,
    base_class_add_parent,
    base_class_remove_parent,
    base_class_clear_parents,
    base_class_iter_parents,
    base_class_notify,
    base_class_nop,
    func_8001CD60,
    NULL,
    func_8004D42C,
    func_8001CEB4,
    func_8001D008,
    func_8001D0EC,
    func_8001D1A4,
    func_8001D204,
    func_8001D280,
    func_8001D33C,
    func_8001D344,
    func_8001D374,
    func_8001D3A0,
    func_8001D3CC,
    func_8001D3F8,
    func_8001D424,
    func_8001D450,
    func_8001D480,
    func_8001D4AC,
    func_8001D4DC,
    func_8001D568,
    func_8001D600,
    func_8001D624,
    func_8001D6A4,
    func_8001D6AC,
    func_8004D434,
    func_8001D714,
    func_8001D950,
    func_8001DA28,
    func_8001DDF4,
    func_8001E49C,
    func_8001E4A4,
    func_8004D47C,
    func_8004D500,
};

notify_node_t *func_8004D38C() {
    notify_node_t *allocated = (notify_node_t *) memory_allocate_mem(0x3C);

    if (allocated) {
        func_8004D508()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_8004D3DC(notify_node_t *This) {
    func_8001E57C()->Construct(This);
    This->vtable = func_8004D508();
    This->m_Unk12_1 = 0;
    This->m_Unk12_2 = 0;
    This->m_Unk13 = 0;
}

void func_8004D42C(void *) {
}

void func_8004D434(notify_node_t *This, void **Unk) {
    if (*(u8 *) *Unk == 52) {
        This->vtable->Unk45(This);
    }
}

void func_8004D47C(notify_node_t *This, void **Unk2, s32 Unk3) {
    func_8001E57C()->Unk38(This, Unk2, Unk3);

    if (Unk3 < 9) {
        if (Unk3 >= 5) {
            This->vtable->Unk39(This, Unk2, Unk3);
        }
    }
}

notify_node_t *func_8004D500(notify_node_t *This) {
    return This;
}

notify_node_vtable_t *func_8004D508(void) {
    return &D_80086AA0;
}
