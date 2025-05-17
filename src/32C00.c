#include "32C00.h"
#include "base_class.h"

extern class_32C00_vtable_t **D_8006EF50;

class_32C00_t *func_80042400(void) {
    class_32C00_t *allocated = (class_32C00_t *) memory_allocate_mem(0x1C);

    if (allocated) {
        func_80042684()->Construct(allocated);
        return allocated;
    }

    return NULL;
}

void func_80042450(class_32C00_t *This) {
    base_class_get_vtable()->Construct(This);
    This->vtable = func_80042684();
    This->vtable->Unk15(This, 0);
}

void func_800424A8(class_32C00_t *This) {
    base_class_get_vtable()->Cleanup(This);
}

INCLUDE_ASM("asm/nonmatchings/32C00", func_800424E0);

INCLUDE_ASM("asm/nonmatchings/32C00", func_80042550);

void func_800425D8(class_32C00_t *This, s32 Unk) {
    This->m_Unk2 = Unk;
    This->m_Unk4 = 0;
    This->m_Unk3 = 0;
    This->m_Unk5 = 0;
}

void func_800425EC(class_32C00_t *This) {
    s32 value;

    value = 4;
    if (!This->m_Unk4) {
        value = 3;
        if (!This->m_Unk3) {
            value = 2;
            ++This->m_Unk2;
        }
    }
    This->vtable->Unk11(This, value);
}

s32 func_8004264C(class_32C00_t *This) {
    return This->m_Unk2;
}

void func_80042658(class_32C00_t *This) {
    This->m_Unk3 = 1;
}

void func_80042664(class_32C00_t *This) {
    This->m_Unk3 = 0;
}

s32 func_8004266C(class_32C00_t *This) {
    return This->m_Unk3;
}

void func_80042678(class_32C00_t *This) {
    This->m_Unk4 = 1;
}

class_32C00_vtable_t *func_80042684(void) {
    return &D_8006EF50;
}
