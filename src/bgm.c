#include "bgm.h"

#include <psx/libsnd.h>

#include "32ACC.h"
#include "base_class.h"
#include "sound_engine.h"

extern char D_80010FEC[];

// also sound related class

extern bgm_vtable_t **g_BGM_VTABLE;
extern s32 D_8008A8D8;

void *func_80020C5C(void);
void func_8003AE18(s16);

bgm_t *bgm_create(u32 Unk1, u32 Unk2, u32 Unk3) {
    bgm_t *allocated = (bgm_t *) memory_allocate_mem(0x24);

    if (allocated) {
        bgm_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

void bgm_construct(bgm_t *This, s32 Unk2, s32 Unk3, s32 Unk4) {
    base_class_get_vtable()->Construct(This);
    This->vtable = bgm_get_vtable();

    This->m_SoundEngine = 0;
    This->m_Unk3 = 0;
    This->m_SeqAccess = 0;
    *(u16 *)((u8 *)This + 0x1A) = 0;
    This->m_Unk6_1 = 0;
    This->m_Unk6_2 = 0;
    This->m_Unk7 = Unk4;

    D_8008A8D8 = 1;
    This->vtable->Unk22(This, Unk3);
    This->vtable->Unk23(This, Unk2);
    This->vtable->Unk3(This, func_80020C5C());
}

void bgm_cleanup(bgm_t *This) {
    D_8008A8D8 = 0;
    This->vtable->Unk17(This);
    func_8003AE18(This->m_SeqAccess);

    if (This->m_SoundEngine) {
        This->m_SoundEngine->vtable->Destruct(This->m_SoundEngine);
    }

    if (This->m_Unk3) {
        (*(void (**)(s32))(*(u32 *)This->m_Unk3 + 4))(This->m_Unk3);
    }

    This->vtable->Unk4(This, func_80020C5C());
    base_class_get_vtable()->Cleanup(This);
}

void bgm_unk13(bgm_t *This, s32 **Unk2, s32 Unk3) {
    base_class_get_vtable()->Unk13(This, Unk2, Unk3);

    if ((**(u32 **) Unk2 & 0xF) == 1) {
        This->vtable->Unk15(This, Unk2, Unk3);
    }
}

void bgm_unk15(bgm_t *This, s32 Unk2, s32 Unk3) {
    if (Unk3 == 2 && This->m_IsOpened == 1 && bgm_handle_monitor_event(This)) {
        if (This->m_Unk7) {
            This->vtable->Unk16(This);
        }
    }
}

s32 bgm_handle_monitor_event(bgm_t *This) {
    sound_engine_t *engine;
    s32 unk3;
    s16 seq;

    engine = This->m_SoundEngine;
    if (engine == NULL) {
        return 0;
    }
    unk3 = This->m_Unk3;
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

void bgm_unk16(bgm_t *This) {
    if (!This->m_Unk6_2) {
        SsSeqSetVol(This->m_SeqAccess, 52, 52);
        SsSeqPlay(This->m_SeqAccess, 1, 0);
        This->m_Unk6_2 = 1;
    }
}

void bgm_unk17(bgm_t *This) {
    if (This->m_Unk6_2) {
        SsSeqStop(This->m_SeqAccess);
        func_8003AE18(This->m_SeqAccess);
        This->m_Unk6_2 = 0;
        This->m_IsOpened = 0;
    }
}

void bgm_unk18(bgm_t *This) {
    if (!This->m_Unk6_1) {
        SsSeqPause(This->m_SeqAccess);
        This->m_Unk6_1 = 1;
    }
}

void bgm_unk19(bgm_t *This) {
    if (This->m_Unk6_1) {
        SsSeqReplay(This->m_SeqAccess);
        This->m_Unk6_1 = 0;
    }
}

void bgm_unk20(bgm_t *This, s16 Unk1, s16 Unk2) {
    SsSeqSetVol(This->m_SeqAccess, Unk1, Unk2);
}

void bgm_set_crescendo(bgm_t *This, s16 Volume, s32 Time) {
    SsSeqSetCrescendo(This->m_SeqAccess, Volume, helper_1_get_crescendo_time_mod() * Time);
}

void bgm_unk22(bgm_t *This, s32 Unk) {
    s32 unk;

    if (This->m_Unk6_2) {
        This->vtable->Unk17(This);
    }

    unk = This->m_Unk3;
    if (unk) {
        (*(void (**)(int))(*(u32 *) unk + 4))(unk);
        This->m_Unk3 = 0;
    }
    if (Unk) {
        This->m_Unk3 = func_800422CC(Unk);
        if (bgm_handle_monitor_event((int) This)) {
            if (This->m_Unk7) {
                This->vtable->Unk16(This);
            }
        } else if (!This->m_IsOpened) {
            This->m_IsOpened = 1;
        }
    }
}

void bgm_unk23(bgm_t *This, s32 Unk) {
    if (This->m_Unk6_2) {
        This->vtable->Unk17(This);
    }

    if (This->m_SoundEngine) {
        This->m_SoundEngine->vtable->Destruct(This->m_SoundEngine);
        This->m_SoundEngine = NULL;
    }

    if (Unk) {
        This->m_SoundEngine = sound_engine_create(Unk);
        if (bgm_handle_monitor_event(This)) {
            if (This->m_Unk7) {
                This->vtable->Unk16(This);
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
