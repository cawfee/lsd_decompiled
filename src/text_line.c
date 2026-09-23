#include "text_line.h"
#include "322B4.h"

extern text_line_vtable_t D_8006EB90;

text_line_t *func_800408CC(s32 Unk1, s32 Unk2, s32 Unk3) {
    text_line_t *allocated = (text_line_t *) memory_allocate_mem(0xB8);

    if (allocated) {
        func_80040FB0()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void func_80040948(text_line_t *This, s32 Unk1, s32 Unk2, s32 Unk3) {
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

void func_80040A30(text_line_t *This) {
    destroy_list(This->m_Unk44, This->m_Unk41_2);
    This->m_Unk44 = memory_free_mem(This->m_Unk44);
    func_80041C3C()->Cleanup(This);
}

void func_80040A88(text_line_t *This, s32 Unk) {
    ((void (*)(void *, s32))This->vtable->Unk52)(This, 7);
    ((void (*)(void *, s32))This->vtable->Unk50)(This, Unk);
}

void func_80040AE8(text_line_t *This, s32 arg1, s32 *arg2) {
    s32 pos[2];
    u8 start;
    class_322B4_t **p;
    s32 i;
    class_322B4_t *obj;

    if (This->m_Unk2 == 0) {
        ((void (*)(void *, s32, s32 *))func_80041C3C()->Unk18)(This, arg1, arg2);
        __builtin_memcpy(pos, arg2, 8);
        start = (u8)This->m_Unk42_1;
        p = (class_322B4_t **)((u8 *)This->m_Unk44 + (start * 4));
        i = start;
        if (i < (s32)(start + (u8)This->m_Unk41_4)) {
            do {
                if ((u8)This->m_Unk41_3 != 0 && i == (u8)This->m_Unk41_3) {
                    pos[0] += 0x10;
                }
                obj = *p;
                ((void (*)(void *, void *, s32 *))obj->vtable->Unk18)(obj, This, pos);
                pos[0] += This->m_Unk43;
                p++;
            } while (++i < (s32)((u8)This->m_Unk42_1 + (u8)This->m_Unk41_4));
        }
    }
}

void func_80040C00(text_line_t *This) {
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

s32 func_80040CD0(text_line_t *This, s32 arg1, s32 arg2) {
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

void func_80040D74(text_line_t *This, s32 arg) {
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

void func_80040E14(text_line_t *This, s32 *arg1) {
    s32 pos[2];
    class_322B4_t **p;
    s32 i;
    class_322B4_t *obj;

    if (This->m_Unk2 != 0) {
        i = 0;
        ((void (*)(void *, s32 *))func_80041C3C()->Unk46)(This, arg1);
        __builtin_memcpy(pos, arg1, 8);
        p = (class_322B4_t **)This->m_Unk44;
        if (i < (s32)This->m_Unk41_2) {
            do {
                obj = *p;
                ((void (*)(void *, s32 *))obj->vtable->Unk46)(obj, pos);
                pos[0] += This->m_Unk43;
                p++;
            } while (++i < (s32)This->m_Unk41_2);
        }
    }
}

s32 func_80040EDC(text_line_t *This, u8 Unk2, s32 Unk3) {
    return (*(int ( **)(s32, s32))(**((s32 **)This->m_Unk44 + Unk3) + 196))(
           *((s32 *)This->m_Unk44 + Unk3),
           Unk2);
}

void func_80040F20(void) {
}

void func_80040F28(text_line_t *This, u8 *Str) {
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

void func_80040FA8(text_line_t *This, s32 Unk) {
    This->m_Unk43 = Unk;
}

text_line_vtable_t *func_80040FB0(void) {
    return &D_8006EB90;
}
