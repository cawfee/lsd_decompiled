#include <psx/libcd.h>
#include <psx/libspu.h>

#include "file/str_stream.h"

extern long CdControlF(unsigned char, unsigned char *);
extern long CdRead2(long);
extern void StSetStream(unsigned long, unsigned long, unsigned long, void *, void *);
#include "base/base_class.h"

// CD related class?

extern str_stream_vtable_t g_STR_STREAM_VTABLE;

extern str_stream_t *g_StreamActive;
extern s32 g_StreamState;
extern char g_StreamFileSuffix[];

extern char *strcpy(char *, char *);
extern char *strcat(char *, char *);
extern s32 get_current_data_folder(void);
extern void *CdSearchFile(void *fp, char *name);

str_stream_t *str_stream_create(s32 Unk1, s32 Unk2, s32 Unk3) {
    str_stream_t *allocated = (str_stream_t *) memory_allocate_mem(0x5C);

    if (allocated) {
        str_stream_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void str_stream_construct(str_stream_t *This, u32 Unk2, s32 Unk3, s32 Unk4) {
    base_class_get_vtable()->Construct(This);
    This->vtable = str_stream_get_vtable();
    This->m_Unk12 = Unk2;

    This->m_Paused = 0;

    if (Unk2 < 4) {
        This->m_Unk13 = 2054 * (300 / Unk3 / 2);
    } else {
        This->m_Unk13 = 2054 * (150 / Unk3 / 2);
    }

    This->m_Unk14 = Unk4;
    This->m_RingSize = 0;
    This->m_Unk18 = 0;
    This->m_Unk17 = 0;
    This->m_Unk20 = 0;
    This->m_State = 0;
}

void str_stream_cleanup(str_stream_t *This) {
    This->vtable->Unk17(This);
    base_class_get_vtable()->Cleanup(This);
}

void str_stream_set_ring(str_stream_t *This, s32 Unk2, u32 Unk3) {
    if (!This->m_State) {
        StSetRing(Unk2, Unk3 >> 11);
        This->m_RingSize = Unk2;
    }
}

s32 str_stream_set_spu_volume(str_stream_t *This);

s32 str_stream_open(str_stream_t *This, char *name, s32 retries) {
    char path[0x20];
    s32 left;
    s32 orig;
    s32 pad;
    s32 *file;

    left = retries;
    orig = left;
    pad = 0;
    if (This->m_State == 0) {
        if (This->m_RingSize != 0) {
            if (g_StreamActive == NULL) {
                path[0] = 0x5C;
                strcpy(&path[1], (char *) get_current_data_folder());
                strcat(path, name);
                strcat(path, g_StreamFileSuffix);
                file = &This->m_Unk2;
                while (CdSearchFile(file, path) == 0) {
                    if (orig >= 0) {
                        left -= 1;
                        if (left < 0) {
                            return 1;
                        }
                    }
                }
                This->m_Unk15 = (s32) ((u32) This->m_Unk3 / This->m_Unk13);
                g_StreamState = str_stream_set_spu_volume(This);
                g_StreamActive = This;
                This->vtable->Unk18(This, file);
                return pad;
            }
            return pad;
        }
    }
    return 1;
}

s32 str_stream_set_spu_volume(str_stream_t *This) {
    spu_common_attr_t attributes;
    attributes.mask = (SPU_COMMON_MVOLL | SPU_COMMON_MVOLR | SPU_COMMON_CDVOLL | SPU_COMMON_CDVOLR | SPU_COMMON_CDMIX);

    attributes.m_vol.left = 0x3FFF;
    attributes.m_vol.right = 0x3FFF;

    attributes.cd.volume.left = 0x7FFF;
    attributes.cd.volume.right = 0x7FFF;

    attributes.cd.mix = SPU_ON;

    SpuSetCommonAttr(&attributes);
    return 1;
}

void str_stream_close(str_stream_t *This) {
    str_stream_t *cur;

    if (This->m_State != 0) {
        cur = g_StreamActive;
        if (cur == This) {
            cur->vtable->Unk20(cur);
            cur->m_State = 0;
            g_StreamActive = NULL;
        }
    }
}

// gp
void str_stream_sync_callback(str_stream_t *This);

void str_stream_start(str_stream_t *This, void *arg1) {
    if (This->m_State != 2) {
        if (g_StreamActive == This) {
            if (This->m_Unk20 != 0) {
                CdSyncCallback((void *) str_stream_sync_callback);
                CdControlF(0x15, arg1);
            } else {
                do {
                } while (CdControl(0x15, arg1, 0) == 0);
            }
            This->m_State = 1;
        }
    }
}

void str_stream_sync_callback(str_stream_t *This) {
    if ((g_StreamActive != NULL) && ((u8) This == 2)) {
        CdSyncCallback(0);

        if (g_StreamActive->m_Unk20) {
            ((void (*)(s32)) g_StreamActive->m_Unk20)(g_StreamActive->m_Unk16);
        }
    }
}

// gp
void str_stream_play(str_stream_t *This, s32 arg1, s32 arg2) {
    s32 mode;

    if (This->m_State == 1) {
        if (g_StreamActive == This) {
            mode = 0x140;
            if (This->m_Unk12 < 4) {
                mode = 0x1C0;
            }
            if (arg2 != 0) {
                This->m_Unk15 = arg2;
            }
            This->m_Unk21 = 0;
            StSetStream(0, arg1, -1, NULL, NULL);
            This->vtable->Unk24(This);
            do {
                while (CdControl(2, (unsigned char *) This + 0xC, 0) == 0) {
                }
            } while (CdRead2(mode) == 0);
            This->vtable->Unk25(This);
            This->m_State = 2;
        }
    }
}

// gp
void str_stream_stop(str_stream_t *This) {
    if (This->m_State == 2) {
        if (g_StreamActive == This) {
            This->vtable->Unk24(This);
            This->vtable->Unk29(This);
            This->vtable->Unk28(This);
            do {
            } while (CdControl(9, 0, 0) == 0);
            This->m_State = 4;
        }
    }
}

void str_stream_reset(str_stream_t *This) {
    if ((This->m_State == 4) && (g_StreamActive == This)) {
        g_StreamActive->m_State = 0;
        g_StreamActive->vtable->Unk18(g_StreamActive, &g_StreamActive->m_Unk2);
    }
}

void str_stream_nop_1(void) {
}

void str_stream_nop_2(void) {
}

void str_stream_pause(str_stream_t *This) {
    if (This->m_Paused == 0) {
        if (g_StreamActive == This) {
            do {
            } while (CdControl(0xB, 0, 0) == 0);
            This->m_Paused = 1;
        }
    }
}

void str_stream_resume(str_stream_t *This) {
    if ((This->m_Paused != 0) && (g_StreamActive == This)) {
        do {

        } while (CdControl(0xC, 0, 0) == 0);
        This->m_Paused = 0;
    }
}

extern int StGetNext(u32 *ring, u32 **header);
void str_stream_invoke_callback(str_stream_t *This, s32 Unk);
void str_stream_finish(str_stream_t *This);

s32 str_stream_get_next(str_stream_t *This, u32 *ring, s32 *out, s32 count) {
    u32 *header;
    s32 result;
    s32 value;

    if (count < 0) {
        count = 0x800000;
    }
    do {
        result = StGetNext(ring, &header);
        count -= 1;
    } while (result != 0 && count >= 0);
    if (result != 0) {
        This->vtable->Unk27(This, ring);
        return 0;
    }
    value = header[2];
    *out = value;
    if (This->m_Unk15 <= 0) {
        goto accept;
    }
    if ((u32) value >= (u32) This->m_Unk15) {
        goto reject;
    }
    if ((u32) value >= (u32) This->m_Unk21) {
        goto store;
    }
reject:
    if ((u32) value < (u32) This->m_Unk21) {
        *out = 0;
    }
    ((void (*)(str_stream_t *, s32, s32)) str_stream_invoke_callback)(This, ring[0], *out);
    str_stream_finish(This);
    return -1;
store:
    This->m_Unk21 = value;
accept:
    ((void (*)(str_stream_t *, s32, s32)) str_stream_invoke_callback)(This, ring[0], *out);
    return 1;
}

void str_stream_invoke_callback(str_stream_t *This, s32 Unk) {
    if (This->m_Unk17) {
        ((void (*)(s32)) This->m_Unk17)(This->m_Unk16);
        ((void (*)(void *, s32)) This->vtable->Unk27)(This, Unk);
    }
}

void str_stream_finish(str_stream_t *This) {
    if (This->m_Unk18) {
        ((void (*)(s32)) This->m_Unk17)(This->m_Unk16);
        This->vtable->Unk17(This);
    }
}

u32 str_stream_free_ring(str_stream_t *This, u32 Base) {
    return StFreeRing(Base);
}

void str_stream_unset_ring() {
    StUnSetRing();
}

void str_stream_clear_ring(void) {
    StClearRing();
}

s32 str_stream_sync(str_stream_t *This, s32 Mode) {
    return CdSync(Mode, &This->m_Unk8);
}

void str_stream_nop_3(void) {
}

str_stream_vtable_t *str_stream_get_vtable(void) {
    return &g_STR_STREAM_VTABLE;
}
