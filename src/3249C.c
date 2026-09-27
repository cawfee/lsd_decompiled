#include "3249C.h"

#include "326E8.h"

#include "base_class.h"

extern s32 D_8006EE10;

void func_8001CBA4(void);
void func_8001CC48(void);
void func_8001CCB4(void);
void func_8001CD20(void);
void func_8001CD60(void);
void func_80042170(void);
void func_8001D008(void);
void func_8001D1A4(void);
void func_8001D204(void);
void func_8001D280(void);
void func_8001D33C(void);
void func_8004220C(void);
void func_8004223C(void);
void func_80042268(void);
void func_8001D3CC(void);
void func_8001D3F8(void);
void func_8001D424(void);
void func_8001D450(void);
void func_8001D480(void);
void func_8001D4AC(void);
void func_8001D4DC(void);
void func_8001D568(void);
void func_8001D600(void);
void func_8001D624(void);
void func_8001D6A4(void);
void func_80042294(void);
void func_8001D6B4(void);
void func_8001D714(void);
void func_8001D950(void);
void func_8001DA28(void);
void func_8001DDF4(void);
void func_8001E49C(void);
void func_8001E4A4(void);
void func_8004229C(void);

void func_80041DAC(class_3249C_t *, s32, s32);
void func_80041E2C(class_3249C_t *, s32 *);
void func_80041E58(class_3249C_t *, u32);

void func_80041D18(class_3249C_t *, s32, s32, s32);
void func_80041DA4(void);

class_3249C_vtable_t D_8006ED4C = {
    0x00000144,
    base_class_destructor,
    (void (*)(void *, s32, s32, s32))func_80041D18,
    (void (*)(base_class_t *))func_8001CBA4,
    (void (*)(base_class_t *, base_class_t *))func_8001CC48,
    (void (*)(base_class_t *, base_class_t *))func_8001CCB4,
    (void (*)(base_class_t *))func_8001CD20,
    base_class_iter_children,
    base_class_add_parent,
    base_class_remove_parent,
    base_class_clear_parents,
    base_class_iter_parents,
    base_class_notify,
    base_class_nop,
    (void (*)(base_class_t *, base_class_t *, s32))func_8001CD60,
    NULL,
    (void (*)(void *))func_80041DA4,
    (void (*)(void *))func_80042170,
    (void (*)(void *))func_8001D008,
    (void (*)(void *, void *, void *))func_80041DAC,
    (void (*)(void *))func_8001D1A4,
    (void (*)(void *))func_8001D204,
    (void (*)(void *))func_8001D280,
    (void (*)(void *))func_8001D33C,
    (void (*)(void *))func_8004220C,
    (void (*)(void *))func_8004223C,
    (void (*)(void *))func_80042268,
    (void (*)(void *))func_8001D3CC,
    (void (*)(void *))func_8001D3F8,
    (void (*)(void *))func_8001D424,
    (void (*)(void *))func_8001D450,
    (void (*)(void *))func_8001D480,
    (void (*)(void *))func_8001D4AC,
    (void (*)(void *))func_8001D4DC,
    (void (*)(void *))func_8001D568,
    (void (*)(void *))func_8001D600,
    (void (*)(void *))func_8001D624,
    (void (*)(void *))func_8001D6A4,
    (void (*)(void *))func_80042294,
    (void (*)(void *))func_8001D6B4,
    (void (*)(void *))func_8001D714,
    (void (*)(void *))func_8001D950,
    (void (*)(void *))func_8001DA28,
    (void (*)(void *))func_8001DDF4,
    (void (*)(void *))func_8001E49C,
    (void (*)(void *))func_8001E4A4,
    (void (*)(void *))func_8004229C,
    (void (*)(void *))func_80041E2C,
    (void (*)(void *))func_80041E58,
};

class_3249C_t *func_80041C9C(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_3249C_t *allocated = (class_3249C_t *) memory_allocate_mem(0xA8);

    if (allocated) {
        func_80041ED8()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_80041D18(class_3249C_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    func_800422BC()->Construct(This, Unk1, 0, Unk2, 0, Unk3);
    This->vtable = func_80041ED8();
    This->vtable->Unk15(This);
}

void func_80041DA4(void) {
}

void func_80041DAC(class_3249C_t *This, s32 Unk1, s32 Unk2) {
    if (This->m_Unk2 == 0) {
        ((void (*)(void *, s32, s32 *))func_800422BC()->Unk18)(This, Unk1, &D_8006EE10);
        ((void (*)(void *, s32))This->vtable->Unk46)(This, Unk2);
    }
}

void func_80041E2C(class_3249C_t *This, s32 *Unk) {
    if (This->m_Unk2) {
        __builtin_memcpy(&This->m_Unk39, Unk, 8);
    }
}

void func_80041E58(class_3249C_t *This, u32 Unk) {
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

class_3249C_vtable_t *func_80041ED8(void) {
    return &D_8006ED4C;
}
