#include "bgm.h"

#include <psx/libsnd.h>

#include "seq_file.h"
#include "base_class.h"
#include "sound.h"

const char D_80010FEC[0x2C] = "Seq Open error in WBgmHandleMonitorEvent";

s32 g_BgmActive = 0;


void bgm_construct(bgm_t *, s32, s32, s32);
void bgm_cleanup(bgm_t *);
void bgm_on_notify(bgm_t *, s32 **, s32);
void bgm_handle_event(bgm_t *, s32, s32);
void seq_play(bgm_t *);
void seq_stop(bgm_t *);
void seq_pause(bgm_t *);
void seq_resume(bgm_t *);
void seq_set_vol(bgm_t *, s16, s16);
void bgm_set_crescendo(bgm_t *, s16, s32);
void bgm_set_sequence(bgm_t *, s32);
void bgm_set_sound(bgm_t *, s32);

bgm_vtable_t g_BGM_VTABLE = {
    0x50,
    base_class_destructor,
    (void (*)(void *, s32, s32, s32))bgm_construct,
    (void (*)(void *))bgm_cleanup,
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
    (void (*)(void *))bgm_on_notify,
    NULL,
    (void (*)(void *, void **, s32))bgm_handle_event,
    (void (*)(void *))seq_play,
    (void (*)(void *))seq_stop,
    (void (*)(void *))seq_pause,
    (void (*)(void *))seq_resume,
    (void (*)(void *))seq_set_vol,
    (void (*)(void *))bgm_set_crescendo,
    (void (*)(void *, s32))bgm_set_sequence,
    (void (*)(void *, s32))bgm_set_sound,
};

void *get_display(void);
void func_8003AE18(s16);

bgm_t *bgm_create(u32 Unk1, u32 Unk2, u32 Unk3) {
    bgm_t *allocated = (bgm_t *) memory_allocate_mem(0x24);

    if (allocated) {
        bgm_get_vtable()->bgm_construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void bgm_construct(bgm_t *This, s32 Unk2, s32 Unk3, s32 Unk4) {
    base_class_get_vtable()->Construct(This);
    This->vtable = bgm_get_vtable();

    This->m_Sound = 0;
    This->m_SeqFile = 0;
    This->m_SeqAccess = 0;
    *(u16 *)((u8 *)This + 0x1A) = 0;
    This->m_Paused = 0;
    This->m_Playing = 0;
    This->m_AutoPlay = Unk4;

    g_BgmActive = 1;
    This->vtable->bgm_set_sequence(This, Unk3);
    This->vtable->bgm_set_sound(This, Unk2);
    This->vtable->Attach(This, get_display());
}

void bgm_cleanup(bgm_t *This) {
    g_BgmActive = 0;
    This->vtable->seq_stop(This);
    func_8003AE18(This->m_SeqAccess);

    if (This->m_Sound) {
        This->m_Sound->vtable->Destroy(This->m_Sound);
    }

    if (This->m_SeqFile) {
        (*(void (**)(s32))(*(u32 *)This->m_SeqFile + 4))(This->m_SeqFile);
    }

    This->vtable->Detach(This, get_display());
    base_class_get_vtable()->Cleanup(This);
}

void bgm_on_notify(bgm_t *This, s32 **Unk2, s32 Unk3) {
    base_class_get_vtable()->OnNotify(This, Unk2, Unk3);

    if ((**(u32 **) Unk2 & 0xF) == 1) {
        This->vtable->bgm_handle_event(This, Unk2, Unk3);
    }
}

void bgm_handle_event(bgm_t *This, s32 Unk2, s32 Unk3) {
    if (Unk3 == 2 && This->m_IsOpened == 1 && seq_open(This)) {
        if (This->m_AutoPlay) {
            This->vtable->seq_play(This);
        }
    }
}

s32 seq_open(bgm_t *This) {
    sound_t *engine;
    s32 unk3;
    s16 seq;

    engine = This->m_Sound;
    if (engine == NULL) {
        return 0;
    }
    unk3 = This->m_SeqFile;
    if (unk3 == 0) {
        return 0;
    }
    if (*(u16 *)((u8 *)engine + 0x58) == 0) {
        return 0;
    }
    if (*(s32 *)(unk3 + 0x2C) == 0) {
        return 0;
    }
    seq = SsSeqOpen(*(u32 *)(unk3 + 0x10), *(s16 *)((u8 *)engine + 0x54));
    This->m_SeqAccess = seq;
    if (seq == -1) {
        printf(D_80010FEC);
    }
    SsSeqSetVol(This->m_SeqAccess, 0x34, 0x34);
    *(u16 *)((u8 *)This + 0x1A) = 2;
    return 1;
}

void seq_play(bgm_t *This) {
    if (!This->m_Playing) {
        SsSeqSetVol(This->m_SeqAccess, 52, 52);
        SsSeqPlay(This->m_SeqAccess, 1, 0);
        This->m_Playing = 1;
    }
}

void seq_stop(bgm_t *This) {
    if (This->m_Playing) {
        SsSeqStop(This->m_SeqAccess);
        func_8003AE18(This->m_SeqAccess);
        This->m_Playing = 0;
        This->m_IsOpened = 0;
    }
}

void seq_pause(bgm_t *This) {
    if (!This->m_Paused) {
        SsSeqPause(This->m_SeqAccess);
        This->m_Paused = 1;
    }
}

void seq_resume(bgm_t *This) {
    if (This->m_Paused) {
        SsSeqReplay(This->m_SeqAccess);
        This->m_Paused = 0;
    }
}

void seq_set_vol(bgm_t *This, s16 Unk1, s16 Unk2) {
    SsSeqSetVol(This->m_SeqAccess, Unk1, Unk2);
}

void bgm_set_crescendo(bgm_t *This, s16 Volume, s32 Time) {
    SsSeqSetCrescendo(This->m_SeqAccess, Volume, helper_1_get_crescendo_time_mod() * Time);
}

void bgm_set_sequence(bgm_t *This, s32 Unk) {
    s32 unk;

    if (This->m_Playing) {
        This->vtable->seq_stop(This);
    }

    unk = This->m_SeqFile;
    if (unk) {
        (*(void (**)(int))(*(u32 *) unk + 4))(unk);
        This->m_SeqFile = 0;
    }
    if (Unk) {
        This->m_SeqFile = seq_file_create(Unk);
        if (seq_open((int) This)) {
            if (This->m_AutoPlay) {
                This->vtable->seq_play(This);
            }
        } else if (!This->m_IsOpened) {
            This->m_IsOpened = 1;
        }
    }
}

void bgm_set_sound(bgm_t *This, s32 Unk) {
    if (This->m_Playing) {
        This->vtable->seq_stop(This);
    }

    if (This->m_Sound) {
        This->m_Sound->vtable->Destroy(This->m_Sound);
        This->m_Sound = NULL;
    }

    if (Unk) {
        This->m_Sound = sound_create(Unk);
        if (seq_open(This)) {
            if (This->m_AutoPlay) {
                This->vtable->seq_play(This);
            }
        } else if (!This->m_IsOpened) {
            This->m_IsOpened = 1;
        }
    }
}

bgm_vtable_t *bgm_get_vtable(void) {
#ifndef CCG8
    return &g_BGM_VTABLE;
#else
    // G8 hack
    bgm_vtable_t *result;

    __asm__("lui     %0, %%hi(%1)\n\t"
            "addiu   %0, %0, %%lo(%1)"
            : "=r"(result)
            : "i"(&g_BGM_VTABLE));

    return result;
#endif
}

INCLUDE_ASM("asm/nonmatchings/bgm", func_8003A05C);

INCLUDE_ASM("asm/nonmatchings/bgm", func_8003A068);
