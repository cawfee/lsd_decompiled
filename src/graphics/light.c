#include "graphics/light.h"

#include <psx/libgs.h>

#include "base/transform.h"
#include "graphics/flat_light.h"

extern class_light_vtable_t **D_8006EFAC;
class_flat_light_t *func_8004291C(s32 Unk1);

void func_800426E4(void *);
void func_80042790(void *);
void func_80042814(void *);
void func_80042820(void *);
s32 func_80042828(class_light_t *, int);
void func_8004283C(void *);
void func_8001CC48(void *, void *);
void func_8001CCB4(void *);
void func_8001CD20(void *);
void func_8001CD60(void *);
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
void func_8001D714(void *);
void func_8001D950(void *);
void func_8001DA28(void *);
void func_8001DDF4(void *);
void func_8001E49C(void *);
void func_8001E4A4(void *);

class_light_vtable_t D_8006EFAC = {
    0x14,
    (void (*)(void *)) base_class_destructor,
    func_800426E4,
    func_80042790,
    func_8001CC48,
    func_8001CCB4,
    func_8001CD20,
    (void (*)(void *)) base_class_iter_children,
    (void (*)(void *)) base_class_add_parent,
    (void (*)(void *)) base_class_remove_parent,
    (void (*)(void *)) base_class_clear_parents,
    (void (*)(void *)) base_class_iter_parents,
    (void (*)(void *)) base_class_notify,
    (void (*)(void *)) base_class_nop,
    func_8001CD60,
    NULL,
    func_80042814,
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
    func_80042820,
    func_8001D714,
    func_8001D950,
    func_8001DA28,
    func_8001DDF4,
    func_8001E49C,
    func_8001E4A4,
    (void (*)(void *)) func_80042828,
    func_8004283C,
};

class_light_t *func_80042694() {
    class_light_t *allocated = (class_light_t *) memory_allocate_mem(0x54);

    if (allocated) {
        func_800428E4()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_800426E4(class_light_t *This) {
    s32 i;
    s32 *slot;
    class_flat_light_t *obj;

    func_8001E57C()->Construct(This);
    This->vtable = func_800428E4();
    i = 0;
    slot = &This->m_Unk16;
    do {
        obj = func_8004291C(i);
        *slot = (s32) obj;
        This->vtable->Unk3(This, obj);
        i += 1;
        slot += 1;
    } while (i < 3);
    This->vtable->Unk15(This);
}

void func_80042790(class_light_t *This) {
    s32 i;
    void *obj;

    i = 0;
    do {
        obj = This->vtable->Unk45(This, i);
        i += 1;
        (*(void (**)(void *))(*(s32 *) obj + 4))(obj);
    } while (i < 3);

    func_8001E57C()->Cleanup(This);
}

void func_80042814(class_light_t *This) {
    *This->m_Unk4 = 0;
}

void func_80042820(void) {
}

s32 func_80042828(class_light_t *This, int Unk) {
    return *(&This->m_Unk16 + Unk);
}

void func_8004283C(class_light_t *This, s8 *RGB, s32 Swap) {
    s8 tmp[3];

    if (Swap != 0) {
        __builtin_memcpy(tmp, (s8 *) (s32) This->m_Ambient, 3);
        __builtin_memcpy(This->m_Ambient, RGB, 3);
        __builtin_memcpy(RGB, tmp, 3);
    } else {
        __builtin_memcpy(This->m_Ambient, RGB, 3);
    }
    GsSetAmbient((u8) This->m_Ambient[0] << 4, (u8) This->m_Ambient[1] << 4, (u8) This->m_Ambient[2] << 4);
}

class_light_vtable_t *func_800428E4() {
    return &D_8006EFAC;
}
