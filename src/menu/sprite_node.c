#include "menu/sprite_node.h"

#include "menu/sprite.h"

#include "base/base.h"

extern s32 D_8006EE10[3];

void func_8001CBA4(base_class_t *);
void func_8001CC48(base_class_t *, base_class_t *);
void func_8001CCB4(base_class_t *, base_class_t *);
void func_8001CD20(base_class_t *);
void func_8001CD60(base_class_t *, base_class_t *, s32);
void func_80042170(void *);
void func_8001D008(void *);
void func_8001D1A4(void *);
void func_8001D204(void *);
void func_8001D280(void *);
void func_8001D33C(void *);
void func_8004220C(void *);
void func_8004223C(void *);
void func_80042268(void *);
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
void func_80042294(void *);
void func_8001D6B4(void *);
void func_8001D714(void *);
void func_8001D950(void *);
void func_8001DA28(void *);
void func_8001DDF4(void *);
void func_8001E49C(void *);
void func_8001E4A4(void *);
void func_8004229C(void *);

void sprite_node_run(void *, void *, void *);
void sprite_node_set_offset(void *);
void sprite_node_set_anchor(void *);

void sprite_node_construct(void *, s32, s32, s32);
void sprite_node_cleanup(void *);

sprite_node_vtable_t g_SPRITE_NODE_VTABLE = {
    0x144,
    base_class_destructor,
    sprite_node_construct,
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
    sprite_node_cleanup,
    func_80042170,
    func_8001D008,
    sprite_node_run,
    func_8001D1A4,
    func_8001D204,
    func_8001D280,
    func_8001D33C,
    func_8004220C,
    func_8004223C,
    func_80042268,
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
    func_80042294,
    func_8001D6B4,
    func_8001D714,
    func_8001D950,
    func_8001DA28,
    func_8001DDF4,
    func_8001E49C,
    func_8001E4A4,
    func_8004229C,
    sprite_node_set_offset,
    sprite_node_set_anchor,
};

sprite_node_t *sprite_node_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    sprite_node_t *allocated = (sprite_node_t *) memory_allocate_mem(0xA8);

    if (allocated) {
        sprite_node_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void sprite_node_construct(sprite_node_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    func_800422BC()->Construct(This, Unk1, 0, Unk2, 0, Unk3);
    This->vtable = sprite_node_get_vtable();
    This->vtable->Unk15(This);
}

void sprite_node_cleanup(void *) {
}

void sprite_node_run(sprite_node_t *This, s32 Unk1, s32 Unk2) {
    if (This->m_Unk2 == 0) {
        ((void (*)(void *, s32, s32 *)) func_800422BC()->Unk18)(This, Unk1, D_8006EE10);
        ((void (*)(void *, s32)) This->vtable->Unk46)(This, Unk2);
    }
}

void sprite_node_set_offset(sprite_node_t *This, s32 *Unk) {
    if (This->m_Unk2) {
        __builtin_memcpy(&This->m_Unk39, Unk, 8);
    }
}

void sprite_node_set_anchor(sprite_node_t *This, u32 Unk) {
    if (This->m_Unk2 != 0 && Unk < 5) {
        switch (Unk) {
            case 0:
                This->m_Unk30_0 = This->m_Unk26_0 >> 1;
                This->m_Unk30_1 = This->m_Unk26_1 >> 1;
                break;
            case 1:
                This->m_Unk30_0 = 0;
                break;
            case 2:
                This->m_Unk30_0 = This->m_Unk26_0;
                break;
            case 3:
                This->m_Unk30_1 = 0;
                break;
            case 4:
                This->m_Unk30_1 = This->m_Unk26_1;
                break;
        }
    }
}

sprite_node_vtable_t *sprite_node_get_vtable(void) {
    return &g_SPRITE_NODE_VTABLE;
}
