#include "1CBB8.h"

#include "base_class.h"
#include "file_buf.h"

s32 D_8008A8B0 = 0;
s32 D_8008A8B4 = 0;

s32 init_800269F0(file_buf_t *);
void file_buf_release(file_buf_t *);
void nullsub13(void);
void func_80026C88(file_buf_t *);

void class_1CBB8_construct(void);
void class_1CBB8_cleanup(void);
void class_1CBB8_unk15(void);
void class_1CBB8_unk16(void);
void class_1CBB8_unk17(void);
void class_1CBB8_unk18(void);
void class_1CBB8_unk19(void);
s32 class_1CBB8_unk20(void);
void class_1CBB8_unk21(void);
void class_1CBB8_unk25(void);
void class_1CBB8_unk26(void);
void class_1CBB8_unk27(void);
void class_1CBB8_unk28(void);

class_1CBB8_vtable_t g_CLASS_1CBB8_VTABLE = {
    0x23,
    (void (*)(void *))init_800269F0,
    (void (*)(void *))class_1CBB8_construct,
    (void (*)(void *))class_1CBB8_cleanup,
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
    (void (*)(void *))class_1CBB8_unk15,
    (void (*)(void *))class_1CBB8_unk16,
    (void (*)(void *))class_1CBB8_unk17,
    (void (*)(void *))class_1CBB8_unk18,
    (void (*)(void *))class_1CBB8_unk19,
    (void (*)(void *))class_1CBB8_unk20,
    (void (*)(void *))class_1CBB8_unk21,
    (void (*)(void *))file_buf_release,
    (void (*)(void *))nullsub13,
    (void (*)(void *))func_80026C88,
    (void (*)(void *))class_1CBB8_unk25,
    (void (*)(void *))class_1CBB8_unk26,
    (void (*)(void *))class_1CBB8_unk27,
    (void (*)(void *))class_1CBB8_unk28,
};

s32 func_8002C3B8(void) {
    return 0;
}

void class_1CBB8_construct(void) {
}

void class_1CBB8_cleanup(void) {
}

void class_1CBB8_unk15(void) {
    s8 pad[0x40];
}

void class_1CBB8_unk16(void) {
    s8 pad[0x40];
}

void class_1CBB8_unk17(void) {
}

void class_1CBB8_unk18(void) {
}

void class_1CBB8_unk19(void) {
}

s32 class_1CBB8_unk20(void) {
    return 0;
}

void class_1CBB8_unk21(void) {
}

void class_1CBB8_unk25(void) {
}

void class_1CBB8_unk26(void) {
}

void class_1CBB8_unk27(void) {
}

void class_1CBB8_unk28(void) {
}

class_1CBB8_vtable_t *class_1CBB8_get_vtable(void) {
    return &g_CLASS_1CBB8_VTABLE;
}

s32 func_8002C448(s32 *Out) {
    if (Out) {
        *Out = D_8008A8B4;
    }

    return D_8008A8B0;
}

s32 func_8002C468(s32 Unk1, s32 Unk2) {
    D_8008A8B0 = Unk1;
    D_8008A8B4 = Unk2;
    return 1;
}

s32 func_8002C478(void) {
    return 0;
}
