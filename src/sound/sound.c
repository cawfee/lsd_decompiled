#include <psx/libsnd.h>

#include "memory/memory.h"
#include "scene/entity.h"
#include "sound/sound.h"
#include <psx/libspu.h>

extern sound_vtable_t g_SOUND_VTABLE;

extern s32 g_SoundInstanceCount;
extern s32 g_CrescendoTimeMod;
extern s32 g_SpuInitialized;
extern s32 g_SndEngineInitialized;
extern s32 g_MasterVolumeSet;
extern char g_VabHeaderExt[];
extern s32 g_VabHeaderPtr;
extern char g_VabBodyExt[];

void *get_file_driver(void);
s32 bgm_is_active(void);
s32 bgm_get_sequence_work(void);
void func_800329D8(void);
void func_80032A7C(void);
void func_800323A8(s32, s32, s32);
void func_80032588(s32);
void build_data_path(char *, char *, char *, char *);
extern char *strcpy(char *, char *);
extern s32 strlen(char *);
s16 func_80030E90(s16, s16, s16, s16, s32, s32, s32);
s16 SsUtGetDetVVol(s16, s16, s16, s16);
extern s16 SsUtGetVabHdr(s16, void *);
extern s16 SsUtGetProgAtr(s16, s32, u8 *);
extern s16 SsUtGetVagAtr(s16, s32, s16, s32);
extern void SsSetMVol(s16, s16);

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

    (*(void (**)(sound_t *))((s32) get_file_driver() + 8))(This);
    This->vtable = sound_get_vtable();
    This->unk19 = 0;
    This->unk20 = 0;
    This->unk21_1 = 0;
    This->m_IsMuted = 0;
    This->vtable->sound_set_volume_offset(This, 0);
    This->unk22_1 = 0;
    This->unk22_2 = 0;
    This->unk23 = 0;
    if (g_SpuInitialized == 0) {
        SpuInit();
        g_SpuInitialized = 1;
        func_800323A8(bgm_get_sequence_work(), 2, 1);
    }
    if (g_SndEngineInitialized == 0) {
        g_CrescendoTimeMod = 0x3C;
        func_80032588(1);
        g_SndEngineInitialized = 1;
    }
    g_SoundInstanceCount += 1;
    if (path != 0) {
        mem = (char *) memory_allocate_mem(strlen(path) + 1);
        if (mem != 0) {
            This->unk23 = (s32) mem;
            strcpy(mem, path);
            build_data_path(buf, mem, NULL, g_VabHeaderExt);
            This->unk10_2 = 1;
            This->vtable->Unk11(This, buf);
        }
    }
}

void sound_close(sound_t *This) {
    s32 count;

    SsVabClose(This->unk21_1);
    count = g_SoundInstanceCount - 1;
    g_SoundInstanceCount = count;
    if (count < 0) {
        g_SoundInstanceCount = 0;
    }
    if ((g_SoundInstanceCount == 0) && (bgm_is_active() == 0)) {
        g_SpuInitialized = 0;
        g_MasterVolumeSet = 0;
        g_SndEngineInitialized = 0;
        func_800329D8();
        func_80032A7C();
    }
    memory_free_mem((void *) This->unk19);
    memory_free_mem((void *) This->unk20);
    memory_free_mem((void *) This->unk23);
    (*(void (**)(sound_t *))((s32) get_file_driver() + 0xC))(This);
}

void sound_update_vab_load(sound_t *This) {
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
        This->unk21_1 = SsVabOpenHead((unsigned char *) This->unk4, -1);
        build_data_path(buffer, (char *) This->unk23, NULL, g_VabBodyExt);
        saved = This->unk4;
        This->unk10_2 = 6;
        This->unk4 = 0;
        g_VabHeaderPtr = saved;
        This->vtable->Unk6(This, buffer);
        if (This->unk23 != 0) {
            memory_free_mem((void *) This->unk23);
            This->unk23 = 0;
        }
    }
    goto done;
case6:
    if (This->m_FlagsUnk & 0x200) {
        vab_id = SsVabTransBody((unsigned char *) This->unk4, This->unk21_1);
        This->unk21_1 = vab_id;
        if (vab_id != -1) {
            This->unk22_2 = 1;
            This->vtable->sound_finish_vab_load(This, 1);
        }
    }
done:
    return;
}

s32 sound_finish_vab_load(sound_t *This, s32 Unk) {
    s32 return_value = 0;

    if (This->unk22_2) {

        if (Unk) {
            SsVabTransCompleted(1);
            This->unk22_2 = 0;
            This->unk22_1 = 1;

            This->vtable->sound_build_program_table(This);
            return_value = 1;
        }
    }

    return return_value;
}

/*
 * Near match (108/107 insns): frame, prologue, allocations, both loops and the
 * volume block all match. Three GCC 2.6.3 ties remain:
 *  - the entry guard is `blez` in the target (`0 < count` on a `for`/`while`
 *    form) but `beqz` here; while/for forms give `blez` but grow the frame to
 *    0x58 instead of 0x50.
 *  - target allocates outer=$s4 / innerOffset=$s5; gcc swaps them.
 *  - gcc duplicates the `lui v0,1` constant into the inner-entry `beqz` delay
 *    slot (target materialises it once at the shared tail).
 * Also needs short prototypes for the SsUtGet / SsSetMVol SDK calls (otherwise
 * implicit int returns skip the target's `sll/sra` sign-extension). The 0x20-byte
 * attr buffer reproduces the target's 0x50 frame (ProgAtr is 16 bytes).
 *
 * void sound_build_program_table(sound_t *This) {
 *     sound_prog_attr_t attr;
 *     u8 *cursor;
 *     u8 *table;
 *     u8 *prog;
 *     s32 outer;
 *     s32 inner;
 *     s32 offset;
 *     s32 innerOffset;
 *
 *     if (This->unk22_1 != 0) {
 *         This->vtable->file_buf_release(This);
 *         This->unk4 = g_VabHeaderPtr;
 *         if (SsUtGetVabHdr(This->unk21_1, (u8 *)This + 0x2C) != -1) {
 *             prog = (u8 *)memory_allocate_mem(*(u16 *)((u8 *)This + 0x40) << 5);
 *             This->unk19 = (s32)prog;
 *             if (prog != 0) {
 *                 table = (u8 *)memory_allocate_mem(*(u16 *)((u8 *)This + 0x3E) << 2);
 *                 This->unk20 = (s32)table;
 *                 if (table != 0) {
 *                     cursor = (u8 *)This->unk19;
 *                     outer = 0;
 *                     if (*(u16 *)((u8 *)This + 0x3E) > 0) {
 *                         offset = 0;
 *                         do {
 *                             *(u32 *)(This->unk20 + outer * 4) = (u32)cursor;
 *                             if (SsUtGetProgAtr(This->unk21_1, offset >> 16, &attr) == -1) {
 *                                 return;
 *                             }
 *                             if (attr.m_Attr > 0) {
 *                                 inner = 0;
 *                                 innerOffset = offset;
 *                                 do {
 *                                     if (SsUtGetVagAtr(This->unk21_1, innerOffset >> 16, (s16)inner, (s32)cursor) ==
 * -1) { return;
 *                                     }
 *                                     inner++;
 *                                     cursor += 0x20;
 *                                 } while (inner < (s32)attr.m_Attr);
 *                             }
 *                             offset += 0x10000;
 *                             outer++;
 *                         } while (outer < *(u16 *)((u8 *)This + 0x3E));
 *                     }
 *                     if (g_MasterVolumeSet == 0) {
 *                         func_80032998();
 *                         SsSetMVol(0x78, 0x78);
 *                         g_MasterVolumeSet = 1;
 *                     }
 *                 }
 *             }
 *         }
 *     }
 * }
 */
INCLUDE_ASM("asm/nonmatchings/sound/sound", sound_build_program_table);

s16 sound_play_note(sound_t *This, s32 arg1, s16 arg2, s16 arg3) {
    s32 vab;
    u8 *entry;
    s16 voice;

    if (arg1 >= 0) {
        vab = arg1 >> 4;
        entry = *(u8 **) (This->unk20 + vab * 4);
        entry += (arg1 - (vab << 4)) * 32;
        voice = func_80030E90(This->unk21_1, (s16) vab, (s16) (arg1 - (vab << 4)), (s16) (entry[4] + (u16) This->unk24),
                              entry[5], arg2, arg2);
        if (voice >= 0) {
            SsUtGetDetVVol(voice, arg2, arg3, 2);
            return voice;
        }
    }
    return -1;
}

s32 sound_stop_note(void *This, s32 arg1) {
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

void sound_nop_1(void) {
}

void sound_nop_2(void) {
}

void sound_nop_3(void) {
}

void sound_set_volume_offset(sound_t *This, s32 Unk) {
    This->unk24 = 12 * Unk - 24;
}

sound_vtable_t *sound_get_vtable(void) {
    return &g_SOUND_VTABLE;
}

s32 sound_get_instance_count(void) {
    return g_SoundInstanceCount;
}

s32 sound_get_crescendo_time_mod(void) {
    return g_CrescendoTimeMod;
}

s32 sound_entity_init(sound_t *This, s32 *Unk2, s32 Unk3, s32 Unk4, s32 Unk5) {
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

void sound_entity_stop(void **This, s32 *Unk2) {
    s32 *ptr;
    s32 i;
    s32 val;

    ptr = Unk2 + 6;
    i = 0;
    do {
        val = *ptr;
        i += 1;
        if (val >= 0) {
            *ptr = (*(s32(**)(void **, s32))(*(u32 *) This + 0x84))(This, val);
        }
        ptr += 5;
    } while (i < 3);
    *Unk2 = 0;
}

void sound_entity_update(sound_t *This, entity_context_t *Unk2) {
    entity_effect_slot_t *slot;
    entity_effect_slot_t *init;
    s32 i;

    if (Unk2->state > 0) {
        i = 0;
        init = Unk2->slots;
        do {
            i += 1;
            init->id = -1;
            init->param = 0;
            init->period = 0x7F;
            init->counter = 0x40;
            init += 1;
        } while (i < 3);

        Unk2->motion = 0;
        if (Unk2->callback != NULL) {
            Unk2->callback(Unk2->owner, (s32 *) Unk2);
        }

        if (Unk2->motion >= 0) {
            slot = Unk2->slots;
            i = 0;
            do {
                if (slot->id >= 0) {
                    if (slot->handle >= 0) {
                        This->vtable->sound_stop_note(This, slot->handle);
                    }
                    This->vtable->sound_set_volume_offset(This, slot->param);
                    slot->handle = This->vtable->sound_play_note(
                        This, slot->id << 4, slot->period - (slot->period / Unk2->divisor) * Unk2->motion,
                        slot->counter - (slot->counter / Unk2->divisor) * Unk2->motion);
                } else if (slot->id == -2) {
                    if (slot->handle >= 0) {
                        This->vtable->sound_stop_note(This, slot->handle);
                    }
                }
                i += 1;
                slot += 1;
            } while (i < 3);
        }
        Unk2->tick += 1;
    }
}
