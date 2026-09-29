#include "common.h"

#include "file_buf.h"
#include "memory.h"
#include "display.h"

typedef struct cd_file_request {
    /* 0x00 */ s32 m_Cancel;
    /* 0x04 */ s32 m_Unk1;
    /* 0x08 */ s32 m_Unk2;
    /* 0x0C */ s32 m_FileBuf;
    /* 0x10 */ s32 m_Unk4;
    /* 0x14 */ s32 m_Unk5;
    /* 0x18 */ s32 m_Unk6;
    /* 0x1C */ struct cd_file_request *m_Prev;
    /* 0x20 */ struct cd_file_request *m_Next;
} cd_file_request_t;

extern void VSyncCallback();
display_t *get_display(void);
extern s32 get_current_data_folder();
extern char *strcpy(char *, char *);
extern char *strcat(char *, char *);
extern char *strstr(char *, char *);
extern s32 CdSetDebug(s32);
extern s32 CdControlB(s32, u8 *, s32 *);

s32 cd_file_driver_tick(void);
void cd_file_driver_lock(void);
void cd_file_driver_unlock(void);
void cd_file_driver_stop_read(void);
void cd_file_driver_read_state1(void);
void cd_file_driver_read_state2(void);
s32 func_80018458(void);

extern s32 g_CdInitialized;
extern s32 g_CdCallbackInstalled;
extern char g_CdPathSuffix[];
extern s32 g_CdFrameActive;
extern s32 g_CdFrameParam;
extern s32 g_CdReadBusy;
extern s32 g_CdDiscTable;
extern s32 g_CdDiscCount;
extern s32 g_CdReadIdle;
extern s32 g_CdReadParam;
extern s32 g_CdReadState;
extern s32 g_CdReadPos;
extern s32 g_CdReadTarget;
extern s32 g_CdLocked;
extern s32 g_CdCallbackActive;
extern cd_file_request_t *g_CdRequestList;
extern s32 g_CdReadPhase;
extern s32 g_CdTimeoutCounter;
extern s32 g_CdFrameMode;
extern s32 g_CD_FILE_DRIVER_VTABLE[];

void *cd_file_driver_create(void) {
    void *mem = memory_allocate_mem(0x2C);

    if (mem != NULL) {
        ((file_buf_vtable_t *)cd_file_driver_get_vtable())->Construct(mem);
        return mem;
    }
    return NULL;
}

void cd_file_driver_construct(file_buf_t *This) {
    file_buf_get_vtable()->Construct(This);
    This->vtable = cd_file_driver_get_vtable();
    This->m_Unk9 = 0;
    cd_file_driver_init();
}

void cd_file_driver_cleanup(file_buf_t *This) {
    This->vtable->Unk28(This);
    This->vtable->file_buf_release(This);
}

void cd_file_driver_unk15(void) {
}

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_open);

void cd_file_driver_close(file_buf_t *arg0) {
    if (g_CdFrameActive == 0 && g_CdFrameParam == 0) {
        cd_file_driver_reset_cache();
    } else {
        cd_file_driver_lock();
        if (arg0->m_Unk9 != 0) {
            if (g_CdReadBusy == 0) {
                cd_file_driver_begin_read(0, 0);
                arg0->m_Unk2 = 0;
                cd_file_driver_end_read();
            }
        } else {
            cd_file_driver_queue_request(arg0, 0, 3, 0, 0);
        }
        cd_file_driver_unlock();
    }
}

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_seek);

void cd_file_driver_unk19(void) {
}

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_read);

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_unk21);

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_unk25);

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_unk26);

void cd_file_driver_unk27(void) {
    cd_file_driver_lock();
    cd_file_driver_stop_read();
    cd_file_driver_unlock();
}

void cd_file_driver_unk28(file_buf_t *arg0) {
    cd_file_request_t *node;
    cd_file_request_t *next;

    cd_file_driver_lock();
    if (g_CdRequestList != NULL && arg0->m_Unk7_2 != 0) {
        arg0->m_Flags = 0;
        if (g_CdRequestList->m_FileBuf == (s32)arg0 && g_CdRequestList->m_Cancel != 0 && g_CdReadIdle == 0) {
            CdFlush();
            cd_file_driver_end_read();
            g_CdReadPos = g_CdReadTarget;
            g_CdReadTarget = 0;
        }
        node = g_CdRequestList;
        if (node != NULL) {
            do {
                next = node->m_Next;
                if (node->m_FileBuf == (s32)arg0) {
                    cd_file_driver_free_request(node);
                    arg0->m_Unk7_2 = arg0->m_Unk7_2 - 1;
                }
                node = next;
            } while (node != NULL);
        }
    }
    cd_file_driver_unlock();
}

void *cd_file_driver_get_vtable(void) {
    return g_CD_FILE_DRIVER_VTABLE;
}

void cd_file_driver_init(void) {
    u8 param;

    if (g_CdInitialized == 0) {
        CdSetDebug(0);
        param = 0x80;
        do {
        } while (CdControlB(0xE, &param, 0) == 0);
        g_CdInitialized = 1;
    }
}

s32 cd_file_driver_is_busy(void) {
    return g_CdReadBusy;
}

s32 cd_file_driver_is_read_idle(void) {
    return g_CdReadIdle;
}

s32 cd_file_driver_get_read_param(void) {
    return g_CdReadParam;
}

s32 cd_file_driver_get_read_state(void) {
    return g_CdReadState;
}

s32 cd_file_driver_get_frame_state(s32 *arg0) {
    if (arg0 != NULL) {
        *arg0 = g_CdFrameParam;
    }
    return g_CdFrameActive;
}

s32 cd_file_driver_frame_setup(s32 arg0, s32 arg1, s32 arg2) {
    display_t *disp;

    if (g_CdReadBusy == 0) {
        if (arg2 == 0) {
            disp = get_display();
            if (g_CdFrameActive == 0) {
                if (arg0 != 0) {
                    disp->vtable->display_set_vsync_callback(disp, cd_file_driver_tick);
                }
            } else {
                if (arg0 == 0) {
                    disp->vtable->display_set_vsync_callback(disp, NULL);
                }
            }
        }
        g_CdFrameMode = arg2;
        g_CdFrameActive = arg0;
        g_CdFrameParam = arg1;
        return 1;
    }
    return 0;
}

void cd_file_driver_set_disc_table(s32 arg0) {
    g_CdDiscTable = arg0;
}

void cd_file_driver_set_disc_count(s32 arg0) {
    g_CdDiscCount = arg0;
}

s32 cd_file_driver_get_disc_count(void) {
    return g_CdDiscCount;
}

/*
 * Best match: 53/53 instructions, every opcode/operand identical except the
 * s1/s2 assignment. Target: rec=$s1, record-tail store base=$s2 (allocno
 * order = count, rec, tail, end). gcc 2.6.3 emits tail=$s1, rec=$s2 because
 * the tail allocno's priority (floor_log2(9)*9/22 = 1.227) beats rec's
 * (floor_log2(12)*12/30 = 1.20). Tried explicit and loop-derived tails,
 * struct-field forms, aliases, two-pointer forms, all store orders, for/while
 * shapes, and a gcc 2.5.7 rebuild (2.5.7 gets the register order right but a
 * different prologue/epilogue schedule, and the rest of cd_file_driver only
 * matches 2.6.3). Every source form that reproduces the target instruction stream
 * yields the same 2.6.3 allocno order.
 *
 * extern s32 CdSearchFile(void *, char *);
 * extern s32 printf(char *, ...);
 * extern char g_CdFileNotFoundFileFmt[];
 * typedef struct unk_disc_loc { u8 minute, second, sector, track; } unk_disc_loc_t;
 * typedef struct unk_disc_file { unk_disc_loc_t pos; s32 size; char name[16]; } unk_disc_file_t;
 * s32 cd_file_driver_search_disc_files(s32 arg0, s32 arg1) {
 *     s8 path[0x40];
 *     unk_disc_file_t file;
 *     u8 *rec;
 *     u8 *dst;
 *     u8 *end;
 *     s32 count;
 *     s32 result;
 *
 *     rec = (u8 *)arg0;
 *     end = (u8 *)(arg0 + arg1 * 0x1C);
 *     cd_file_driver_init();
 *     result = 1;
 *     if (rec < end) {
 *         dst = rec + 0x18;
 *         do {
 *             cd_file_driver_build_path(path, (s8 *)rec);
 *             count = 0;
 *             while (CdSearchFile(&file, (char *)path) == 0) {
 *                 count += 1;
 *                 if (count >= 0x65) {
 *                     printf(g_CdFileNotFoundFileFmt, path);
 *                     break;
 *                 }
 *             }
 *             *(unk_disc_loc_t *)(dst - 4) = file.m_Pos;
 *             rec += 0x1C;
 *             *(s32 *)dst = file.m_Size;
 *             dst += 0x1C;
 *         } while (rec < end);
 *         return 1;
 *     }
 *     return result;
 * }
 */
INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_search_disc_files);

void cd_file_driver_lock(void) {
    g_CdLocked = 1;
}

void cd_file_driver_unlock(void) {
    g_CdLocked = 0;
}

s32 cd_file_driver_tick(void) {
    if (g_CdLocked != 0) {
        return 0;
    }
    if (func_80018458() != 0) {
        return 0;
    }
    if (g_CdFrameMode != 0) {
        VSyncCallback(0);
    }
    if (g_CdReadPhase == 1) {
        cd_file_driver_read_state1();
    } else if (g_CdReadPhase == 2) {
        cd_file_driver_read_state2();
    }
    if (g_CdCallbackActive != 0) {
        ((void (*)(void))((void **)cd_file_driver_get_vtable())[26])();
    }
    if (g_CdFrameMode != 0) {
        VSyncCallback(cd_file_driver_tick);
    }
    return 0;
}

void cd_file_driver_start_read(void) {
    cd_file_driver_lock();
    if (g_CdCallbackInstalled == 0) {
        if (g_CdFrameMode != 0) {
            VSyncCallback(cd_file_driver_tick);
        }
        g_CdCallbackInstalled = 1;
    }
    g_CdCallbackActive = 1;
    cd_file_driver_unlock();
}

void cd_file_driver_stop_read(void) {
    cd_file_driver_lock();
    if (g_CdReadPhase == 0) {
        if (g_CdCallbackInstalled != 0) {
            if (g_CdFrameMode != 0) {
                VSyncCallback(0);
            }
            g_CdCallbackInstalled = 0;
            g_CdCallbackActive = 0;
        }
    }
    cd_file_driver_unlock();
}

void cd_file_driver_clear_callback(void) {
    cd_file_driver_lock();
    g_CdCallbackActive = 0;
    cd_file_driver_unlock();
}

void cd_file_driver_queue_request(file_buf_t *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    cd_file_request_t *node = cd_file_driver_alloc_request();

    node->m_Unk2 = arg2;
    node->m_Unk5 = arg3;
    node->m_FileBuf = (s32)arg0;
    node->m_Unk4 = arg1;
    node->m_Unk6 = arg4;
    arg0->m_Flags = 0;
    arg0->m_Unk7_2 = arg0->m_Unk7_2 + 1;
    cd_file_driver_start_read();
}

cd_file_request_t *cd_file_driver_alloc_request(void) {
    cd_file_request_t *node;
    cd_file_request_t *cur;

    cd_file_driver_lock();
    node = memory_allocate_mem(0x24);
    if (node != NULL) {
        node->m_Prev = NULL;
        node->m_Next = NULL;
        node->m_Cancel = 0;
        node->m_Unk1 = 0;
        if (g_CdRequestList != NULL) {
            cur = g_CdRequestList;
            if (cur->m_Next != NULL) {
                do {
                    cur = cur->m_Next;
                } while (cur->m_Next != NULL);
            }
            cur->m_Next = node;
            node->m_Prev = cur;
        } else {
            g_CdRequestList = node;
        }
    }
    cd_file_driver_unlock();
    return node;
}

void cd_file_driver_free_request(cd_file_request_t *node) {
    cd_file_driver_lock();
    if (node != NULL) {
        if (node->m_Prev != NULL) {
            node->m_Prev->m_Next = node->m_Next;
        } else {
            g_CdRequestList = node->m_Next;
        }
        if (node->m_Next != NULL) {
            node->m_Next->m_Prev = node->m_Prev;
        }
        memory_free_mem(node);
    }
    cd_file_driver_unlock();
}

s32 cd_file_driver_find_disc_record(s32 arg0) {
    s32 p = g_CdDiscTable;
    s32 i = 0;

    cd_file_driver_lock();
    while (1) {
        if (strstr((char *)p, (char *)arg0) != 0) {
            cd_file_driver_unlock();
            return p;
        }
        i++;
        p += 0x1C;
        if (i >= g_CdDiscCount) {
            return 0;
        }
    }
}

s32 cd_file_driver_find_disc_record_index(s32 arg0) {
    s32 p = g_CdDiscTable;
    s32 i = 0;

    cd_file_driver_lock();
    while (1) {
        if (strstr((char *)p, (char *)arg0) != 0) {
            break;
        }
        i++;
        if (i >= g_CdDiscCount) {
            return -1;
        }
        p += 0x1C;
    }
    cd_file_driver_unlock();
    return i;
}

s32 cd_file_driver_get_disc_record(s32 arg0) {
    s32 base = g_CdDiscTable;
    s32 result;

    cd_file_driver_lock();
    result = base + (arg0 * 0x1C);
    cd_file_driver_unlock();
    return result;
}

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_read_state1);

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_read_state2);

void cd_file_driver_begin_read(s32 arg0, s32 arg1) {
    g_CdReadBusy = 1;
    g_CdReadParam = arg0;
    g_CdReadState = arg1;
    g_CdReadIdle = 0;
    g_CdRequestList->m_Cancel = 1;
}

void cd_file_driver_end_read(void) {
    g_CdReadParam = 0;
    g_CdReadState = 0;
    g_CdReadPhase = 0;
    g_CdReadIdle = 1;
    g_CdTimeoutCounter = 0;
    g_CdReadBusy = 0;
}

void cd_file_driver_set_read_result(s32 arg0) {
    g_CdReadState = arg0;
    g_CdTimeoutCounter = 0;
}

void cd_file_driver_construct2(file_buf_t *This) {
    file_buf_get_vtable()->Construct(This);
    This->vtable = cd_file_driver_get_vtable();
    This->m_Unk2 = 0;
}

void cd_file_driver_cleanup2(file_buf_t *This) {
    file_buf_get_vtable()->Cleanup((base_class_t *)This);
}

void cd_file_driver_nullsub16(void) {
}

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_lookup_file);

/*
 * Best match: 43/43 instructions, structurally identical (block layout, the
 * unaligned CdlLOC copy, the missing-return result in $v0, loop shape). Only
 * the three callee-saved registers are rotated: target count=$s0, This=$s1,
 * path=$s2; gcc 2.6.3 emits count=$s0, path=$s1, This=$s2 (best of the tested
 * forms). Tried: separate vs single stacked buffers, declaration order, pointer
 * locals, distinct/aliased path expressions, register keyword, explicit result
 * locals, if/else, early returns, memcpy vs struct copy, CdSearchFile prototype
 * variants. The allocator tie-break does not move This ahead of path.
 *
 * extern char g_CdFileNotFoundPathFmt[];
 * extern void *CdSearchFile(void *, char *);
 * extern int printf(char *, ...);
 * typedef struct cd_file { cd_loc_t pos; s32 size; char name[16]; } cd_file_t;
 * s32 cd_file_driver_lookup_file(file_buf_t *This, s8 *arg1) {
 *     cd_file_t file;
 *     s8 path[0x40];
 *     s32 count;
 *     if (This->m_Unk2 == 0) {
 *         count = 0;
 *         cd_file_driver_build_path(path, arg1);
 *         while (CdSearchFile(&file, (char *)path) == 0) {
 *             if (count++ >= 0x64) {
 *                 return printf(g_CdFileNotFoundPathFmt, path);
 *             }
 *         }
 *         This->m_Unk5 = file.pos;
 *         This->m_Unk6 = file.size;
 *         This->m_Unk2 = 1;
 *     }
 * }
 */

s8 *cd_file_driver_build_path(s8 *arg0, s8 *arg1) {
    *arg0 = 0x5C;
    strcpy(arg0 + 1, (char *)get_current_data_folder());
    strcat(arg0, arg1);
    strcat(arg0, g_CdPathSuffix);
    return arg0;
}

void cd_file_driver_reset_cache(file_buf_t *This) {
    if (This->m_Unk2 != 0) {
        This->m_Unk2 = 0;
    }
}

s32 cd_file_driver_get_aligned_size(file_buf_t *This) {
    if (This->m_Unk2 != 0) {
        return (((u32)This->m_Unk6 >> 11) + 1) << 11;
    }
    return 0;
}

void cd_file_driver_nullsub17(void) {
}

INCLUDE_ASM("asm/nonmatchings/cd_file_driver", cd_file_driver_read_sectors);

void cd_file_driver_nullsub18(void) {
}

s32 cd_file_driver_get_frame_mode(void) {
    return g_CdFrameMode;
}
