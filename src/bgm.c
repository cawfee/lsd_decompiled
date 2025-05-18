#include "bgm.h"

#include <psx/libsnd.h>

#include "32ACC.h"
#include "base_class.h"
#include "sound_engine.h"

// also sound related class

extern bgm_vtable_t **g_BGM_VTABLE;
// static s32 D_8008A8D8 = 0;

bgm_t *bgm_create(u32 Unk1, u32 Unk2, u32 Unk3) {
    bgm_t *allocated = (bgm_t *) memory_allocate_mem(0x24);

    if (allocated) {
        bgm_get_vtable()->Construct(allocated, Unk1, Unk2, Unk3);
        return allocated;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/bgm", bgm_construct);
// void func_8003995C(bgm_t *This, s32 Unk2, s32 Unk3, s32 Unk4) {
//     base_class_get_vtable()->Construct(This);
//     This->vtable = bgm_get_vtable();

//     This->m_SoundEngine = 0;
//     This->m_Unk3 = 0;
//     This->m_SeqAccess = 0;
//     This->m_IsOpened = 0;
//     This->m_Unk6_1 = 0;
//     This->m_Unk6_2 = 0;
//     This->m_Unk7 = Unk4;

//     D_8008A8D8 = 1;
//     This->vtable->Unk22(This, Unk3);
//     This->vtable->Unk23(This, Unk2);
//     This->vtable->Unk3(This, func_80020C5C());
// }

INCLUDE_ASM("asm/nonmatchings/bgm", bgm_cleanup);
// void func_80039A34(bgm_t *This) {
//     D_8008A8D8 = 0;
//     This->vtable->Unk17(This);
//     func_8003AE18(This->m_SeqAccess);

//     if (This->m_SoundEngine) {
//         (*(void ( **)(s32))(*(u32 *)This->m_SoundEngine + 4))(This->m_SoundEngine);
//     }

//     if (This->m_Unk3) {
//         (*(void ( **)(s32))(*(u32 *)This->m_Unk3 + 4))(This->m_Unk3);
//     }

//     This->vtable->Unk4(This, func_80020C5C());
//     base_class_get_vtable()->Cleanup(This);
// }

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

INCLUDE_ASM("asm/nonmatchings/bgm", bgm_handle_monitor_event);
// s32 bgm_handle_monitor_event(bgm_t *This) {
//     s32 unk1; // $a1
//   s32 v4; // $v1
//   s16 v5; // $v0

//   unk1 = This->m_SoundEngine;
//   if ( unk1 )
//   {
//     v4 = This->m_Unk3;
//     if ( v4 )
//     {
//       if ( *(u16 *)(unk1 + 88) )
//       {
//         if ( *(u32 *)(v4 + 44) )
//         {
//           v5 = SsSeqOpen(*(u32 *)(v4 + 16), *(s16 *)(unk1 + 84));
//           This->m_SeqAccess = v5;
//           if ( v5 == -1 )
//             printf("Seq Open error in WBgmHandleMonitorEvent\0");
//           SsSeqSetVol(This->m_SeqAccess, 52, 52);
//           This->m_IsOpened = 2;
//             return 1;
//         }
//       }
//     }
//   }
//   return 0;
// }

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

void func_80039E24(bgm_t *This, s16 arg1, s32 arg2) {
    SsSeqSetCrescendo(This->m_SeqAccess, arg1, func_8002CC28() * arg2);
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
