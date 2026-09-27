#include "file_buf.h"

#include "1CBB8.h"
#include "base_class.h"
#include "memory.h"


s32 init_800269F0(file_buf_t *);
void func_80026A50(void *);
void func_80026AB4(void *);
void file_buf_load(void *);
void file_buf_release(void *);
void nullsub13(void *);
void func_80026C88(void *);

void *class_1C92C_get_vtable(void);
void *tim_image_get_vtable(void);
void *func_800451A8(void);
void *func_80044F20(void);
void *func_80043E74(void);
void *func_80043830(void);
void *func_80043B78(void);
void *sound_get_vtable(void);
void *func_800423F0(void);
void *func_80048CE0(void);
void *func_800441A4(void);
void *func_80045428(void);
void *func_800449FC(void);
void *func_80044CC4(void);

file_buf_vtable_t D_8006D430 = {
    3,
    (void (*)(void *))init_800269F0,
    func_80026A50,
    func_80026AB4,
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
    file_buf_load,
    file_buf_release,
    nullsub13,
    func_80026C88,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

void *D_8006D4AC[] = {
    class_1C92C_get_vtable,
    tim_image_get_vtable,
    func_800451A8,
    func_80044F20,
    func_80043E74,
    func_80043830,
    func_80043B78,
    sound_get_vtable,
    func_800423F0,
    func_80048CE0,
    func_800441A4,
    func_80045428,
    func_800449FC,
    func_80044CC4,
    NULL,
};

static s32 D_8008A84C = 0x13;
static s32 D_8008A850 = 0;
static s32 D_8008A854 = 0x8006D4A8;
extern char *strcat(char *, char *);
s32 func_80027F18(s32, s32, s32);
void func_80027FD8(s32);
void func_80027FE4(s32);
s32 func_80027FF0(void);
s32 func_80027FFC(s32, s32);
s32 func_8002C468(s32, s32);

s32 init_800269F0(file_buf_t *This) {
    This->m_Unk7_1 = 0;
    This->vtable->Cleanup();
    base_class_get_vtable()->Cleanup(This);
    memory_free_mem(This);
    return 0;
}

void func_80026A50(file_buf_t *This) {
    base_class_get_vtable()->Construct(This);
    This->vtable = file_buf_get_vtable();
    This->m_Unk2 = 0;
    This->m_Buffer = NULL;
    This->m_Unk4 = 0;
    This->m_Unk7_1 = 0;
    This->m_Unk7_2 = 0;
    This->m_Unk8 = 0;
    This->m_Unk9 = 0;
    This->m_Unk10 = 0;
}

void func_80026AB4(file_buf_t *This) {
    This->vtable->Unk17(This);
    This->vtable->file_buf_release(This);
}

void file_buf_load(file_buf_t *This, s32 Unk) {
    s32 size;
    s32 old_unk;
    void *mem;

    if (!This->m_Buffer) {
        old_unk = This->m_Unk2;
        This->m_Unk2 = 0;

        This->vtable->Unk16(This, Unk, 1, 0);
        size = This->vtable->Unk18(This, 0, 2);

        mem = memory_allocate_mem(size);

        if (mem) {
            This->vtable->Unk18(This, 0, 0);
            This->vtable->Unk20(This, mem, size);
            This->vtable->Unk17(This);
            This->m_Buffer = mem;
            This->m_Unk4 = size;
            This->m_Unk2 = old_unk;
        } else {
            memory_free_mem(NULL);
            This->vtable->Unk17(This);
        }
    }
}

void file_buf_release(file_buf_t *This) {
    if (This->m_Buffer && This->m_Unk4 && !This->m_Unk7_1) {
        memory_free_mem(This->m_Buffer);
        This->m_Buffer = 0;
    }
}

void nullsub13(void *) {
}

void func_80026C88(file_buf_t *This) {
    This->m_Unk8 |= 1;
}

file_buf_vtable_t *file_buf_get_vtable(void) {
    return &D_8006D430;
}

void *get_file_driver() {
    if (D_8008A84C == 0x23) {
        return class_1CBB8_get_vtable();
    } else {
        return func_80027E68();
    }
}

s32 *func_80026CE8(s32 *Data, s32 Unk1, s32 Unk2, s32 Unk3) {
    Data[0] = Unk1;
    Data[1] = Unk2;
    Data[2] = Unk3;
    return Data;
}

void func_80026CFC(s32 arg0) {
    void *(**cursor)(void);
    void *vt;
    void *cur;
    void *(*fn)(void);

    cursor = (void *(**)(void))D_8006D4AC;
    D_8008A84C = arg0;
    if (arg0 == 0x13) {
        vt = (void *)func_80027E68();
    } else {
        vt = (void *)class_1CBB8_get_vtable();
    }
    cur = (void *)file_buf_get_vtable();
    goto loop_test;
    do {
        fn = *cursor;
        cursor++;
        cur = fn();
loop_test:
        func_80026D88(cur, vt);
        fn = *cursor;
    } while (fn != NULL);
}

void func_80026D88(s32 *Dest, s32 *Src) {
    Dest[16] = Src[16];
    Dest[17] = Src[17];
    Dest[18] = Src[18];
    Dest[19] = Src[19];
    Dest[20] = Src[20];
    Dest[21] = Src[21];
    Dest[22] = Src[22];
    Dest[26] = Src[26];
    Dest[27] = Src[27];
    Dest[28] = Src[28];
    Dest[29] = Src[29];
}

void func_80026E0C(void) {
    if (D_8008A84C == 0x13) {
        func_800280D0();
    }
}

void func_80026E38(void) {
    if (D_8008A84C == 0x13) {
        func_800280E0();
    }
}

s32 func_80026E64(void) {
    if (D_8008A84C == 0x13) {
        return func_80027EC8();
    }

    return 0;
}

s32 func_80026E98(void) {
    if (D_8008A84C == 0x13) {
        return func_80027ED4();
    }

    return 1;
}

s32 func_80026ECC(void) {
    if (D_8008A84C == 0x13) {
        return func_80027EE0();
    }

    return 0;
}

s32 func_80026F00(void) {
    if (D_8008A84C == 0x13) {
        return func_80027EEC();
    }

    return 0;
}

void frame_setup(s32 Unk1, s32 Unk2, s32 Unk3) {
    s32 (*fn)(s32, s32, s32);

    fn = (s32 (*)(s32, s32, s32))func_8002C468;
    if (D_8008A84C == 0x13) {
        fn = (s32 (*)(s32, s32, s32))func_80027F18;
    }
    do {
    } while (fn(Unk1, Unk2, Unk3) == 0);
}

s32 func_80026FAC(void) {
    if (D_8008A84C == 0x13) {
        return func_80027EF8();
    }

    return func_8002C448();
}

s32 func_80026FE8(void) {
    if (D_8008A84C == 0x13) {
        return func_80028B6C();
    }

    return func_8002C478();
}

s32 func_80027024(s32 arg0, s32 arg1) {
    s32 temp;

    if (D_8008A84C == 0x13) {
        D_8008A850 = 1;
        func_80027FD8(arg0);
        temp = func_80027FF0();
        func_80027FE4(temp + arg1);
        return func_80027FFC(arg0 + (temp * 0x1C), arg1);
    }
    return 1;
}

void set_data_folder(s32 Value) {
    D_8008A854 = Value;
}

s32 func_800270B8() {
    return D_8008A854;
}

s8 *func_800270C4(s8 *dest, s8 *arg1, s8 *arg2, s8 *arg3) {
    *dest = 0;
    if (arg2 != NULL) {
        strcat(dest, arg2);
    }
    strcat(dest, arg1);
    strcat(dest, arg3);
    return dest;
}
