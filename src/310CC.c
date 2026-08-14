#include "310CC.h"
#include "322B4.h"

extern class_310CC_vtable_t D_8006EB90;

class_310CC_t *func_800408CC(s32 Unk1, s32 Unk2, s32 Unk3) {
    class_310CC_t *allocated = (class_310CC_t *) memory_allocate_mem(0xB8);

    if (allocated) {
        func_80040FB0()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_80040948(class_310CC_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
    s32 i;
    s32 *arr;

    func_80041C3C()->Construct(This, Unk1, 0x20);
    This->vtable = func_80040FB0();
    This->m_Unk41_2 = Unk2;
    This->m_Unk41_4 = Unk2;
    This->m_Unk42_1 = 0;
    This->m_Unk41_3 = 0;
    arr = memory_allocate_mem(Unk2 * 4);
    if (arr != NULL) {
        This->m_Unk44 = arr;
        for (i = 0; i < Unk2; i++) {
            *arr = (s32)func_80041AB4(Unk1, 0x20);
            arr += 1;
        }
        This->vtable->Unk15(This, Unk3);
    }
}

void func_80040A30(class_310CC_t *This) {
    func_800183DC(This->m_Unk44, This->m_Unk41_2);
    This->m_Unk44 = memory_free_mem(This->m_Unk44);
    func_80041C3C()->Cleanup(This);
}

void func_80040A88(class_310CC_t *This, s32 Unk) {
    ((void (*)(void *, s32))This->vtable->Unk52)(This, 7);
    ((void (*)(void *, s32))This->vtable->Unk50)(This, Unk);
}

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040AE8);

void func_80040C00(class_310CC_t *This) {
    u8 start;
    void **p;
    s32 i;
    void *obj;

    if (This->m_Unk2 != 0) {
        if (This->m_Unk44 != 0) {
            start = (u8)This->m_Unk42_1;
            p = (void **)((u8 *)This->m_Unk44 + (start * 4));
            i = start;
            if (i < (s32)(start + (u8)This->m_Unk41_4)) {
                do {
                    obj = *p;
                    p++;
                    (*(void (**)(void *))(*(u32 *)obj + 0x50))(obj);
                    i++;
                } while (i < (s32)((u8)This->m_Unk42_1 + (u8)This->m_Unk41_4));
            }
        }
        ((void (*)(void *))func_80041C3C()->Unk19)(This);
    }
}

s32 func_80040CD0(class_310CC_t *This, s32 arg1, s32 arg2) {
    u8 start;
    void **p;
    s32 i;

    start = (u8)This->m_Unk42_1;
    p = (void **)((u8 *)This->m_Unk44 + (start * 4));
    i = start;
    if (i < (s32)(start + (u8)This->m_Unk41_4)) {
        do {
            void *obj = *p;
            p++;
            i++;
            arg2 = (*(s32 (**)(void *, s32))(*(u32 *)obj + 0x60))(obj, arg1);
        } while (i < (s32)((u8)This->m_Unk42_1 + (u8)This->m_Unk41_4));
    }
    return arg2;
}

void func_80040D74(class_310CC_t *This, s32 arg) {
    u8 start;
    void **p;
    s32 i;

    start = (u8)This->m_Unk42_1;
    p = (void **)((u8 *)This->m_Unk44 + (start * 4));
    i = start;
    if (i < (s32)(start + (u8)This->m_Unk41_4)) {
        do {
            void *obj = *p;
            p++;
            (*(void (**)(void *, s32))(*(u32 *)obj + 0xB8))(obj, arg);
            i++;
        } while (i < (s32)((u8)This->m_Unk42_1 + (u8)This->m_Unk41_4));
    }
}

INCLUDE_ASM("asm/nonmatchings/310CC", func_80040E14);

s32 func_80040EDC(class_310CC_t *This, u8 Unk2, s32 Unk3) {
    return (*(int ( **)(s32, s32))(**((s32 **)This->m_Unk44 + Unk3) + 196))(
           *((s32 *)This->m_Unk44 + Unk3),
           Unk2);
}

void func_80040F20(void) {
}

void func_80040F28(class_310CC_t *This, u8 *Str) {
    void **arr;

    arr = This->m_Unk44;
    if (Str != NULL && *Str != 0) {
        do {
            void **obj = *arr;
            (*(void (**)(void **, u8))(*(u32 *)obj + 0xC4))(obj, *Str);
            Str += 1;
            arr += 1;
        } while (*Str != 0);
    }
}

void func_80040FA0(void) {
}

void func_80040FA8(class_310CC_t *This, s32 Unk) {
    This->m_Unk43 = Unk;
}

class_310CC_vtable_t *func_80040FB0(void) {
    return &D_8006EB90;
}
