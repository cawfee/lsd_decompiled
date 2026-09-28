#include "354D4.h"

void func_80044D40(void *, s32, void *);
void func_80044DC8(base_class_t *);
void func_80044E10(void *);
void func_80044E64(void *);
s32 file_buf_destroy(void *);
void file_buf_release(void *);
void nullsub13(void *);

class_354D4_vtable_t D_8006F498 = {
    0x203,
    (base_class_t *(*)(base_class_t *))file_buf_destroy,
    func_80044D40,
    func_80044DC8,
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
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    file_buf_release,
    nullsub13,
    func_80044E10,
    NULL,
    NULL,
    NULL,
    NULL,
    func_80044E64,
};

class_354D4_t *func_80044CD4(s32 Unk1, void *Unk2) {
    class_354D4_t *allocated = (class_354D4_t *) memory_allocate_mem(0x44);

    if (allocated) {
        func_80044F20()->Construct(allocated, Unk1, Unk2);
        return allocated;
    }

    return NULL;
}

void func_80044D40(class_354D4_t *arg0, s32 arg1, s32 arg2) {
    s32 pad[8];
    void **v5;

    v5 = (void **)get_file_driver();
    ((void (*)(class_354D4_t *))v5[2])(arg0);
    arg0->vtable = func_80044F20();
    arg0->m_Unk14 = arg2;
    arg0->m_Unk15_2 = 0;

    if (arg1 == 0) {
        arg0->m_Unk15_1 = 1;
        arg0->m_Unk9_2 = 0;
        arg0->vtable->Unk24(arg0);
    }
}

void func_80044DC8(class_354D4_t *This) {
    memory_free_mem(This->m_Unk13);
  (*(void ( **)(class_354D4_t *))((s32) get_file_driver() + 12))(This);
}

void func_80044E10(class_354D4_t *This) {
    if ( !This->m_Unk9_2 )
  {
    This->vtable->Unk29(This);
    This->m_Unk15_2 = 1;
  }
}

void func_80044E64(class_354D4_t *This) {
    s32 pad[2];
    s16 *mem;
    s32 count;
    s32 i;
    s32 fifteen;

    This->m_Unk12 = *(s32 *)(This->m_Unk14 + 0x2C);

    if (This->m_Unk15_1) {
        This->m_Unk10_2 = 0x14;
        fifteen = 0xF;
        count = *(volatile u16 *)&This->m_Unk10_2 * fifteen;
        This->m_Unk10_0 = 0x10;
        This->m_Unk10_1 = 0x10;
        This->m_Unk11_0 = 0xF;
        if ((This->m_Unk13 = (s32)memory_allocate_mem(count << 1)) != 0) {
            mem = This->m_Unk13;
            i = 0;
            if (count != 0) {
                do {
                    *mem++ = i++;
                } while (i < count);
            }
            return;
        }
    }
    This->vtable->file_buf_release(This);
}

class_354D4_vtable_t *func_80044F20(void) {
    return &D_8006F498;
}
