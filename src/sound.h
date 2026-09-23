#ifndef LSD_SOUND_H
#define LSD_SOUND_H

#include <common.h>

typedef struct sound_vtable {
    /* 0x000 8006da34 */ u32 value;
    /* 0x004 8006da38 */ void (*init_800269F0)(void *);
    /* 0x008 8006da3c */ void (*sound_construct)(void *, s32);
    /* 0x00C 8006da40 */ void (*sound_close)(void *);
    /* 0x010 8006da44 */ void (*func_80017F98)(void *, void *);
    /* 0x014 8006da48 */ void (*func_80017FF0)(void *, void *);
    /* 0x018 8006da4c */ void (*func_80018040)(void *);
    /* 0x01C 8006da50 */ void (*func_800180BC)(void *, void *, void **);
    /* 0x020 8006da54 */ void (*func_800180FC)(void *, void *);
    /* 0x024 8006da58 */ void (*func_8001811C)(void *, void *);
    /* 0x028 8006da5c */ void (*func_8001813C)(void *);
    /* 0x02C 8006da60 */ void (*func_8001816C)(void *, void *, void **);
    /* 0x030 8006da64 */ void (*func_800182CC)(void *);
    /* 0x034 8006da68 */ void (*func_80018350)(void *);
    /* 0x038 8006da6c */ void (*func_80018358)(void *, void *, void *);
    /* 0x03C 8006da70 */ u32 _pad;
    /* 0x040 8006da74 */ u32 pad2;
    /* 0x044 8006da78 */ void (*Unk1)(void *);
    /* 0x048 8006da7c */ void (*Unk2)(void *);
    /* 0x04C 8006da80 */ void (*Unk3)(void *);
    /* 0x050 8006da84 */ void (*Unk4)(void *);
    /* 0x054 8006da88 */ void (*Unk5)(void *);
    /* 0x058 8006da8c */ void (*Unk6)(void *, char *);
    /* 0x05C 8006da90 */ void (*file_buf_release)(void *);
    /* 0x060 8006da94 */ void (*nullsub13)(void *);
    /* 0x064 8006da98 */ void (*func_8002C6FC)(void *);
    /* 0x068 8006da9c */ void (*Unk10)(void *);
    /* 0x06C 8006daa0 */ void (*Unk11)(void *, char *);
    /* 0x070 8006daa4 */ void (*Unk12)(void *);
    /* 0x074 8006daa8 */ void (*Unk13)(void *);
    /* 0x078 8006daac */ void (*func_8002C824)(void *, s32);
    /* 0x07C 8006dab0 */ void (*func_8002C890)(void *);
    /* 0x080 8006dab4 */ void (*func_8002CA3C)(void *, s32, s32, s32);
    /* 0x084 8006dab8 */ s32 (*func_8002CB18)(void *, s32);
    /* 0x088 8006dabc */ void (*sound_mute)(void *);
    /* 0x08C 8006dac0 */ void (*sound_unmute)(void *);
    /* 0x090 8006dac4 */ void (*func_8002CBDC)(void *);
    /* 0x094 8006dac8 */ void (*func_8002CBE4)(void *);
    /* 0x098 8006dacc */ void (*func_8002CBEC)(void *);
    /* 0x09C 8006dad0 */ void (*func_8002CBF4)(void *, s32);
} sound_vtable_t;

typedef struct sound {
    /* 0x00 */ sound_vtable_t *vtable;
    /* 0x04 */ s32 unk1;
    /* 0x08 */ s32 unk2;
    /* 0x0C */ s32 unk3;
    /* 0x10 */ s32 unk4;
    /* 0x14 */ s32 unk5;
    /* 0x18 */ s32 unk6;
    /* 0x1C */ s32 unk7;
    /* 0x20 */ s32 unk8;
    /* 0x24 */ s32 m_FlagsUnk;
    /* 0x28 */ s16 unk10_1;
    /* 0x2A */ u16 unk10_2;
    /* 0x2C */ s32 unk11;
    /* 0x30 */ s32 unk12;
    /* 0x34 */ s32 unk13;
    /* 0x38 */ s32 unk14;
    /* 0x3C */ s32 unk15;
    /* 0x40 */ s32 unk16;
    /* 0x44 */ s32 unk17;
    /* 0x48 */ s32 unk18;
    /* 0x4C */ s32 unk19;
    /* 0x50 */ s32 unk20;
    /* 0x54 */ s16 unk21_1;
    /* 0x56 */ s16 m_IsMuted;
    /* 0x58 */ u16 unk22_1;
    /* 0x5A */ u16 unk22_2;
    /* 0x5C */ s32 unk23;
    /* 0x60 */ s32 unk24;
    /* 0x64 */ s32 unk25;
} sound_t;

sound_t *sound_create(u32 Unk1);
sound_vtable_t *sound_get_vtable(void);

#endif
