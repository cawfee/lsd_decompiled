#include "file/debug_file_driver.h"

#include "base/base_class.h"
#include "file/file_buf.h"

s32 g_DebugFrameState = 0;
s32 g_DebugFrameParam = 0;

s32 file_buf_destroy(file_buf_t *);
void file_buf_release(void *);
void nullsub13(void *);
void file_buf_set_flag(void *);

void debug_file_driver_construct(void *);
void debug_file_driver_cleanup(void *);
void debug_file_driver_unk15(void *);
void debug_file_driver_open(void *);
void debug_file_driver_close(void *);
void debug_file_driver_seek(void *);
void debug_file_driver_unk19(void *);
s32 debug_file_driver_read(void);
void debug_file_driver_unk21(void *);
void debug_file_driver_unk25(void *);
void debug_file_driver_unk26(void *);
void debug_file_driver_unk27(void *);
void debug_file_driver_unk28(void *);

debug_file_driver_vtable_t g_DEBUG_FILE_DRIVER_VTABLE = {
    0x23,
    (void (*)(void *))file_buf_destroy,
    debug_file_driver_construct,
    debug_file_driver_cleanup,
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
    debug_file_driver_unk15,
    debug_file_driver_open,
    debug_file_driver_close,
    debug_file_driver_seek,
    debug_file_driver_unk19,
    (void (*)(void *))debug_file_driver_read,
    debug_file_driver_unk21,
    file_buf_release,
    nullsub13,
    file_buf_set_flag,
    debug_file_driver_unk25,
    debug_file_driver_unk26,
    debug_file_driver_unk27,
    debug_file_driver_unk28,
};

s32 func_8002C3B8(void) {
    return 0;
}

void debug_file_driver_construct(void *) {
}

void debug_file_driver_cleanup(void *) {
}

void debug_file_driver_unk15(void *) {
    s8 pad[0x40];
}

void debug_file_driver_open(void *) {
    s8 pad[0x40];
}

void debug_file_driver_close(void *) {
}

void debug_file_driver_seek(void *) {
}

void debug_file_driver_unk19(void *) {
}

s32 debug_file_driver_read(void) {
    return 0;
}

void debug_file_driver_unk21(void *) {
}

void debug_file_driver_unk25(void *) {
}

void debug_file_driver_unk26(void *) {
}

void debug_file_driver_unk27(void *) {
}

void debug_file_driver_unk28(void *) {
}

debug_file_driver_vtable_t *debug_file_driver_get_vtable(void) {
    return &g_DEBUG_FILE_DRIVER_VTABLE;
}

s32 debug_file_driver_get_frame_state(s32 *Out) {
    if (Out) {
        *Out = g_DebugFrameParam;
    }

    return g_DebugFrameState;
}

s32 debug_file_driver_frame_setup(s32 State, s32 Param) {
    g_DebugFrameState = State;
    g_DebugFrameParam = Param;
    return 1;
}

s32 debug_file_driver_get_frame_mode(void) {
    return 0;
}
