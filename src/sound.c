#include <psx/libsnd.h>

#include "sound.h"
#include "memory.h"
#include <psx/libspu.h>

extern sound_vtable_t g_SOUND_VTABLE;

extern s32 D_8008A8C4;
extern s32 D_8008A8CC;
extern s32 D_8008A8B8;
extern s32 D_8008A8BC;
extern s32 D_8008A8C0;
extern char D_8008A8D0[];
extern s32 D_8008A8C8;
extern char D_8008A8D4[];

void *get_file_driver(void);
s32 func_8003A05C(void);
s32 func_8003A068(void);
void func_800329D8(void);
void func_80032A7C(void);
void func_800323A8(s32, s32, s32);
void func_80032588(s32);
void build_data_path(char *, char *, char *, char *);
extern char *strcpy(char *, char *);
extern s32 strlen(char *);
s16 func_80030E90(s16, s16, s16, s16, s32, s32, s32);
s16 SsUtGetDetVVol(s16, s16, s16, s16);

sound_t *sound_create(u32 Unk1) {
    sound_t *allocated = (sound_t *) memory_allocate_mem(0x64);

    if (allocated) {
        sound_get_vtable()->sound_construct(allocated, Unk1);
        return allocated;
    }

    return NULL;
}

void sound_construct(sound_t *This, char *path) {
    char buf[0x20];
    char *mem;

    (*(void (**)(sound_t *))((s32)get_file_driver() + 8))(This);
    This->vtable = sound_get_vtable();
    This->unk19 = 0;
    This->unk20 = 0;
    This->unk21_1 = 0;
    This->m_IsMuted = 0;
    This->vtable->sound_set_volume_offset(This, 0);
    This->unk22_1 = 0;
    This->unk22_2 = 0;
    This->unk23 = 0;
    if (D_8008A8B8 == 0) {
        SpuInit();
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
            build_data_path(buf, mem, NULL, D_8008A8D0);
            This->unk10_2 = 1;
            This->vtable->Unk11(This, buf);
        }
    }
}

void sound_close(sound_t *This) {
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
    (*(void (**)(sound_t *))((s32)get_file_driver() + 0xC))(This);
}

void func_8002C6FC(sound_t *This) {
    char buffer[0x20];
    s32 saved;
    s16 vab_id;
    s32 mode;

    mode = This->unk10_2;
    if (mode == 1) {
        goto case1;
    }
    if (mode < 2) {
        goto done;
    }
    if (mode == 6) {
        goto case6;
    }
    goto done;

case1:
    if (This->m_FlagsUnk & 0x200) {
        This->unk21_1 = SsVabOpenHead((unsigned char *)This->unk4, -1);
        build_data_path(buffer, (char *)This->unk23, NULL, D_8008A8D4);
        saved = This->unk4;
        This->unk10_2 = 6;
        This->unk4 = 0;
        D_8008A8C8 = saved;
        This->vtable->Unk6(This, buffer);
        if (This->unk23 != 0) {
            memory_free_mem((void *)This->unk23);
            This->unk23 = 0;
        }
    }
    goto done;
case6:
    if (This->m_FlagsUnk & 0x200) {
        vab_id = SsVabTransBody((unsigned char *)This->unk4, This->unk21_1);
        This->unk21_1 = vab_id;
        if (vab_id != -1) {
            This->unk22_2 = 1;
            This->vtable->func_8002C824(This, 1);
        }
    }
done:
    return;
}

s32 func_8002C824(sound_t *This, s32 Unk) {
    s32 return_value = 0;

    if (This->unk22_2) {

        if (Unk) {
            SsVabTransCompleted(1);
            This->unk22_2 = 0;
            This->unk22_1 = 1;

            This->vtable->func_8002C890(This);
            return_value = 1;
        }
    }

    return return_value;
}

INCLUDE_ASM("asm/nonmatchings/sound", func_8002C890);

s16 func_8002CA3C(sound_t *This, s32 arg1, s16 arg2, s16 arg3) {
    s32 vab;
    u8 *entry;
    s16 voice;

    if (arg1 >= 0) {
        vab = arg1 >> 4;
        entry = *(u8 **)(This->unk20 + vab * 4);
        entry += (arg1 - (vab << 4)) * 32;
        voice = func_80030E90(
            This->unk21_1,
            (s16)vab,
            (s16)(arg1 - (vab << 4)),
            (s16)(entry[4] + (u16)This->unk24),
            entry[5],
            arg2,
            arg2);
        if (voice >= 0) {
            SsUtGetDetVVol(voice, arg2, arg3, 2);
            return voice;
        }
    }
    return -1;
}

s32 func_8002CB18(void *This, s32 arg1) {
    if (arg1 < 24) {
        func_80031890((s16) arg1);
    } else {
        func_80031F3C((s16) 0);
    }
    return -1;
}

void sound_mute(sound_t *This) {
    if (!This->m_IsMuted) {
        SsSetMute(SS_MUTE_ON);
        This->m_IsMuted = 1;
    }
}

void sound_unmute(sound_t *This) {
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

void sound_set_volume_offset(sound_t *This, s32 Unk) {
    This->unk24 = 12 * Unk - 24;
}

sound_vtable_t *sound_get_vtable(void) {
    return &g_SOUND_VTABLE;
}

s32 sound_get_instance_count(void) {
    return D_8008A8C4;
}

s32 helper_1_get_crescendo_time_mod(void) {
    return D_8008A8CC;
}

s32 helper_1_set_entity(sound_t *This, s32 *Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
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

void sound_update_entity(void **This, s32 *Unk2) {
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

INCLUDE_ASM("asm/nonmatchings/sound", helper_1_update_entity);
