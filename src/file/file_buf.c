#include "file/file_buf.h"

#include "base/base.h"
#include "file/debug_file_driver.h"

s32 file_buf_destroy(file_buf_t *);
void file_buf_construct(void *);
void file_buf_cleanup(void *);
void file_buf_load(void *);
void file_buf_release(void *);
void nullsub13(void *);
void file_buf_set_flag(void *);

void *class_1C92C_get_vtable(void);
void *tim_image_get_vtable(void);
void *func_800451A8(void);
void *func_80044F20(void);
void *func_80043E74(void);
void *func_80043830(void);
void *func_80043B78(void);
void *sound_get_vtable(void);
void *seq_file_get_vtable(void);
void *func_80048CE0(void);
void *func_800441A4(void);
void *func_80045428(void);
void *func_800449FC(void);
void *func_80044CC4(void);

file_buf_vtable_t g_FILE_BUF_VTABLE = {
    3,
    (void (*)(void *)) file_buf_destroy,
    file_buf_construct,
    file_buf_cleanup,
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
    file_buf_set_flag,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

void *g_FILE_DRIVER_CLASS_VTABLES[] = {
    class_1C92C_get_vtable, tim_image_get_vtable, func_800451A8,    func_80044F20,       func_80043E74,
    func_80043830,          func_80043B78,        sound_get_vtable, seq_file_get_vtable, func_80048CE0,
    func_800441A4,          func_80045428,        func_800449FC,    func_80044CC4,       NULL,
};

static s32 g_FileDriverClass = 0x13;
static s32 D_8008A850 = 0;
static const char *g_DataFolder = (const char *) 0x8006D4A8; // TODO fix
extern char *strcat(char *, char *);
s32 cd_file_driver_frame_setup(s32, s32, s32);
void cd_file_driver_set_disc_table(s32);
void cd_file_driver_set_disc_count(s32);
s32 cd_file_driver_get_disc_count(void);
s32 cd_file_driver_search_disc_files(s32, s32);
s32 debug_file_driver_frame_setup(s32, s32);

s32 file_buf_destroy(file_buf_t *This) {
    This->m_NoFree = 0;
    This->vtable->Cleanup();
    base_class_get_vtable()->Cleanup(This);
    memory_free_mem(This);
    return 0;
}

void file_buf_construct(file_buf_t *This) {
    base_class_get_vtable()->Construct(This);
    This->vtable = file_buf_get_vtable();
    This->m_Unk2 = 0;
    This->m_Buffer = NULL;
    This->m_Size = 0;
    This->m_NoFree = 0;
    This->m_Unk7_2 = 0;
    This->m_Flags = 0;
    This->m_Unk9 = 0;
    This->m_Unk10 = 0;
}

void file_buf_cleanup(file_buf_t *This) {
    This->vtable->Close(This);
    This->vtable->file_buf_release(This);
}

void file_buf_load(file_buf_t *This, s32 Unk) {
    s32 size;
    s32 old_unk;
    void *mem;

    if (!This->m_Buffer) {
        old_unk = This->m_Unk2;
        This->m_Unk2 = 0;

        This->vtable->Open(This, Unk, 1, 0);
        size = This->vtable->Seek(This, 0, 2);

        mem = memory_allocate_mem(size);

        if (mem) {
            This->vtable->Seek(This, 0, 0);
            This->vtable->Read(This, mem, size);
            This->vtable->Close(This);
            This->m_Buffer = mem;
            This->m_Size = size;
            This->m_Unk2 = old_unk;
        } else {
            memory_free_mem(NULL);
            This->vtable->Close(This);
        }
    }
}

void file_buf_release(file_buf_t *This) {
    if (This->m_Buffer && This->m_Size && !This->m_NoFree) {
        memory_free_mem(This->m_Buffer);
        This->m_Buffer = 0;
    }
}

void nullsub13(void *) {
}

void file_buf_set_flag(file_buf_t *This) {
    This->m_Flags |= 1;
}

file_buf_vtable_t *file_buf_get_vtable(void) {
    return &g_FILE_BUF_VTABLE;
}

void *get_file_driver() {
    if (g_FileDriverClass == 0x23) {
        return debug_file_driver_get_vtable();
    } else {
        return cd_file_driver_get_vtable();
    }
}

s32 *file_buf_set_triple(s32 *Data, s32 Unk1, s32 Unk2, s32 Unk3) {
    Data[0] = Unk1;
    Data[1] = Unk2;
    Data[2] = Unk3;
    return Data;
}

void file_driver_set_class(s32 arg0) {
    void *(**cursor)(void);
    void *vt;
    void *cur;
    void *(*fn)(void);

    cursor = (void *(**) (void) ) g_FILE_DRIVER_CLASS_VTABLES;
    g_FileDriverClass = arg0;
    if (arg0 == 0x13) {
        vt = (void *) cd_file_driver_get_vtable();
    } else {
        vt = (void *) debug_file_driver_get_vtable();
    }
    cur = (void *) file_buf_get_vtable();
    goto loop_test;
    do {
        fn = *cursor;
        cursor++;
        cur = fn();
    loop_test:
        file_driver_copy_vtable_slots(cur, vt);
        fn = *cursor;
    } while (fn != NULL);
}

void file_driver_copy_vtable_slots(s32 *Dest, s32 *Src) {
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

void file_driver_lock(void) {
    if (g_FileDriverClass == 0x13) {
        cd_file_driver_lock();
    }
}

void file_driver_unlock(void) {
    if (g_FileDriverClass == 0x13) {
        cd_file_driver_unlock();
    }
}

s32 file_driver_is_busy(void) {
    if (g_FileDriverClass == 0x13) {
        return cd_file_driver_is_busy();
    }

    return 0;
}

s32 file_driver_is_read_idle(void) {
    if (g_FileDriverClass == 0x13) {
        return cd_file_driver_is_read_idle();
    }

    return 1;
}

s32 file_driver_get_read_param(void) {
    if (g_FileDriverClass == 0x13) {
        return cd_file_driver_get_read_param();
    }

    return 0;
}

s32 file_driver_get_read_state(void) {
    if (g_FileDriverClass == 0x13) {
        return cd_file_driver_get_read_state();
    }

    return 0;
}

void frame_setup(s32 Unk1, s32 Unk2, s32 Unk3) {
    s32 (*fn)(s32, s32, s32);

    fn = (s32(*)(s32, s32, s32)) debug_file_driver_frame_setup;
    if (g_FileDriverClass == 0x13) {
        fn = (s32(*)(s32, s32, s32)) cd_file_driver_frame_setup;
    }
    do {
    } while (fn(Unk1, Unk2, Unk3) == 0);
}

s32 file_driver_get_frame_state(void) {
    if (g_FileDriverClass == 0x13) {
        return cd_file_driver_get_frame_state();
    }

    return debug_file_driver_get_frame_state();
}

s32 file_driver_get_frame_mode(void) {
    if (g_FileDriverClass == 0x13) {
        return cd_file_driver_get_frame_mode();
    }

    return debug_file_driver_get_frame_mode();
}

s32 file_driver_lookup_path(s32 arg0, s32 arg1) {
    s32 temp;

    if (g_FileDriverClass == 0x13) {
        D_8008A850 = 1;
        cd_file_driver_set_disc_table(arg0);
        temp = cd_file_driver_get_disc_count();
        cd_file_driver_set_disc_count(temp + arg1);
        return cd_file_driver_search_disc_files(arg0 + (temp * 0x1C), arg1);
    }
    return 1;
}

void set_data_folder(const char *Value) {
    g_DataFolder = Value;
}

const char *get_current_data_folder() {
    return g_DataFolder;
}

s8 *build_data_path(s8 *dest, s8 *arg1, s8 *arg2, s8 *arg3) {
    *dest = 0;
    if (arg2 != NULL) {
        strcat(dest, arg2);
    }
    strcat(dest, arg1);
    strcat(dest, arg3);
    return dest;
}
