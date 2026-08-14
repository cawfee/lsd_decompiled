#include <psx/libsnd.h>

#include "sound_engine.h"
#include "memory.h"

// TODO vtable
// Related to sound?

extern sound_engine_vtable_t g_SOUND_ENGINE_VTABLE;

extern s32 D_8008A8C4;
extern s32 D_8008A8CC;
extern s32 D_8008A8B8;
extern s32 D_8008A8BC;
extern s32 D_8008A8C0;
extern char D_8008A8D0[];
extern s32 D_8008A8C8;
extern char D_8008A8D4[];

void *func_80026CAC(void);
s32 func_8003A05C(void);
s32 func_8003A068(void);
void func_800329D8(void);
void func_80032A7C(void);
void func_80032368(void);
void func_800323A8(s32, s32, s32);
void func_80032588(s32);
void func_800270C4(char *, char *, char *, char *);
extern char *strcpy(char *, char *);
extern s32 strlen(char *);
s16 func_80030E90(s16, s16, s16, s16, s32, s32, s32);
s16 SsUtGetDetVVol(s16, s16, s16, s16);

sound_engine_t *sound_engine_create(u32 Unk1) {
    sound_engine_t *allocated = (sound_engine_t *) memory_allocate_mem(0x64);

    if (allocated) {
        sound_engine_get_vtable()->Construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void func_8002C4E0(sound_engine_t *This, char *path) {
    char buf[0x20];
    char *mem;

    (*(void (**)(sound_engine_t *))((s32)func_80026CAC() + 8))(This);
    This->vtable = sound_engine_get_vtable();
    This->unk19 = 0;
    This->unk20 = 0;
    This->unk21_1 = 0;
    This->m_IsMuted = 0;
    (*(void (**)(sound_engine_t *, s32))((u8 *)This->vtable + 0x9C))(This, 0);
    This->unk22_1 = 0;
    This->unk22_2 = 0;
    This->unk23 = 0;
    if (D_8008A8B8 == 0) {
        func_80032368();
        D_8008A8B8 = 1;
        func_800323A8(func_8003A068(), 2, 1);
    }
    if (D_8008A8BC == 0) {
        D_8008A8CC = 0x3C;
        func_80032588(1);
        D_8008A8BC = 1;
    }
    D_8008A8C4 += 1;
    if (path != 0) {
        mem = (char *)memory_allocate_mem(strlen(path) + 1);
        if (mem != 0) {
            This->unk23 = (s32)mem;
            strcpy(mem, path);
            func_800270C4(buf, mem, NULL, D_8008A8D0);
            This->unk10_2 = 1;
            (*(void (**)(sound_engine_t *, char *))((u8 *)This->vtable + 0x6C))(This, buf);
        }
    }
}

void func_8002C638(sound_engine_t *This) {
    s32 count;

    SsVabClose(This->unk21_1);
    count = D_8008A8C4 - 1;
    D_8008A8C4 = count;
    if (count < 0) {
        D_8008A8C4 = 0;
    }
    if ((D_8008A8C4 == 0) && (func_8003A05C() == 0)) {
        D_8008A8B8 = 0;
        D_8008A8C0 = 0;
        D_8008A8BC = 0;
        func_800329D8();
        func_80032A7C();
    }
    memory_free_mem((void *)This->unk19);
    memory_free_mem((void *)This->unk20);
    memory_free_mem((void *)This->unk23);
    (*(void (**)(sound_engine_t *))((s32)func_80026CAC() + 0xC))(This);
}

INCLUDE_ASM("asm/nonmatchings/sound_engine", func_8002C6FC);

// 95%
// void func_8002C6FC(sound_engine_t *This) {
//     char buffer[32];
//     s32 temp_a2;
//
//     u16 mode = This->unk10_2;
//
//     switch (mode) {
//         case 1:
//             if (This->m_FlagsUnk & 0x200) {
//                 This->unk21_1 =  SsVabOpenHead(This->unk4, -1);
//                 func_800270C4(buffer, This->sound_path, NULL, &D_8008A8D4);
//
//                 temp_a2 = This->unk4;
//                 This->unk10_2 = 6;
//                 This->unk4 = 0;
//                 D_8008A8C8 = temp_a2;
//                 This->vtable->Unk7(This, buffer, temp_a2);
//
//                 if (This->sound_path != 0) {
//                     memory_free_mem((void *) This->sound_path);
//                     This->sound_path = 0;
//                     return;
//                 }
//             }
//             return;
//         case 6:
//             if (This->m_FlagsUnk & 0x200) {
//                 This->unk21_1 = SsVabTransBody(This->unk4, This->unk21_1);
//
//                 if (This->unk21_1 != -1) {
//                     This->unk22_2 = 1;
//                     This->vtable->Unk14(This, 1);
//                 }
//             }
//             break;
//     }
// }

s32 func_8002C824(sound_engine_t *This, s32 Unk) {
    s32 return_value = 0;

    if (This->unk22_2) {

        if (Unk) {
            SsVabTransCompleted(1);
            This->unk22_2 = 0;
            This->unk22_1 = 1;

            This->vtable->Unk15(This);
            return_value = 1;
        }
    }

    return return_value;
}

INCLUDE_ASM("asm/nonmatchings/sound_engine", func_8002C890);

INCLUDE_ASM("asm/nonmatchings/sound_engine", func_8002CA3C);

s32 func_8002CB18(void *This, s32 arg1) {
    // TODO unknown psyq functions
    if (arg1 < 24) {
        func_80031890((s16) arg1);
    } else {
        func_80031F3C((s16) 0);
    }
    return -1;
}

void sound_engine_mute(sound_engine_t *This) {
    if (!This->m_IsMuted) {
        SsSetMute(SS_MUTE_ON);
        This->m_IsMuted = 1;
    }
}

void sound_engine_unmute(sound_engine_t *This) {
    if (This->m_IsMuted) {
        SsSetMute(SS_MUTE_OFF);
        This->m_IsMuted = 0;
    }
}

void func_8002CBDC(void) {
}

void func_8002CBE4(void) {
}

void func_8002CBEC(void) {
}

void func_8002CBF4(sound_engine_t *This, s32 Unk) {
    This->unk24 = 12 * Unk - 24;
}

sound_engine_vtable_t *sound_engine_get_vtable(void) {
    return &g_SOUND_ENGINE_VTABLE;
}

s32 func_8002CC1C(void) {
    return D_8008A8C4;
}

s32 helper_1_get_crescendo_time_mod(void) {
    return D_8008A8CC;
}

s32 helper_1_set_entity(sound_engine_t *This, s32 *Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
    s32 *ptr;
    s32 val;
    s32 i;

    if (*Unk2 != 0) {
        return 0;
    }

    ptr = Unk2 + 6;
    val = -1;
    i = 2;

    Unk2[0] = Unk3;
    Unk2[2] = Unk4;
    Unk2[3] = Unk5;

    do {
        *ptr = val;
        i--;
        ptr += 5;
    } while (i >= 0);

    Unk2[1] = 0;
    Unk2[5] = 10;

    return 1;
}

void func_8002CC84(void **This, s32 *Unk2) {
    s32 *ptr;
    s32 i;
    s32 val;

    ptr = Unk2 + 6;
    i = 0;
    do {
        val = *ptr;
        i += 1;
        if (val >= 0) {
            *ptr = (*(s32 (**)(void **, s32))(*(u32 *)This + 0x84))(This, val);
        }
        ptr += 5;
    } while (i < 3);
    *Unk2 = 0;
}

INCLUDE_ASM("asm/nonmatchings/sound_engine", helper_1_update_entity);
