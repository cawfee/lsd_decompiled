#ifndef LSD_39094_H
#define LSD_39094_H

#include <common.h>

typedef struct class_39094_vtable {
    /* 0x000 80081940 */ u32 value;
    /* 0x004 80081944 */ void (*Destroy)(void *);
    /* 0x008 80081948 */ void (*Construct)(void *);
    /* 0x00C 8008194c */ void (*Cleanup)(void *);
    /* 0x010 80081950 */ void (*Unk3)(void *);
    /* 0x014 80081954 */ void (*Unk4)(void *);
    /* 0x018 80081958 */ void (*Unk5)(void *);
    /* 0x01C 8008195c */ void (*Unk6)(void *);
    /* 0x020 80081960 */ void (*Unk7)(void *);
    /* 0x024 80081964 */ void (*Unk8)(void *);
    /* 0x028 80081968 */ void (*Unk9)(void *);
    /* 0x02C 8008196c */ void (*Unk10)(void *);
    /* 0x030 80081970 */ void (*Unk11)(void *);
    /* 0x034 80081974 */ void (*Unk12)(void *);
    /* 0x038 80081978 */ void (*Unk13)(void *);
    /* 0x03C 8008197c */ void (*Unk14)(void *);
    /* 0x040 80081980 */ void (*Unk15)(void *);
    /* 0x044 80081984 */ void (*Unk16)(void *);
    /* 0x048 80081988 */ void (*Unk17)(void *);
    /* 0x04C 8008198c */ void (*Unk18)(void *);
    /* 0x050 80081990 */ void (*Unk19)(void *);
    /* 0x054 80081994 */ void (*Unk20)(void *);
    /* 0x058 80081998 */ void (*Unk21)(void *);
    /* 0x05C 8008199c */ void (*Unk22)(void *);
    /* 0x060 800819a0 */ void (*Unk23)(void *);
    /* 0x064 800819a4 */ void (*Unk24)(void *);
    /* 0x068 800819a8 */ void (*Unk25)(void *);
    /* 0x06C 800819ac */ void (*Unk26)(void *);
    /* 0x070 800819b0 */ void (*Unk27)(void *);
    /* 0x074 800819b4 */ void (*Unk28)(void *);
    /* 0x078 800819b8 */ void (*Unk29)(void *);
    /* 0x07C 800819bc */ void (*Unk30)(void *);
    /* 0x080 800819c0 */ void (*Unk31)(void *);
    /* 0x084 800819c4 */ void (*Unk32)(void *);
    /* 0x088 800819c8 */ void (*Unk33)(void *);
    /* 0x08C 800819cc */ void (*Unk34)(void *);
} class_39094_vtable_t;

typedef struct class_39094 {
    /* 0x00 */ class_39094_vtable_t *vtable;
    /* 0x04 */ s32 m_Unk0;
    /* 0x08 */ s32 m_Unk1;
    /* 0x0C */ s32 m_Unk2;
    /* 0x10 */ s32 m_Unk3;
    /* 0x14 */ s32 m_Unk4;
    /* 0x18 */ s32 m_Unk5;
    /* 0x1C */ s32 m_Unk6;
    /* 0x20 */ s32 m_Unk7;
    /* 0x24 */ s32 m_Unk8;
    /* 0x28 */ s16 m_Unk9_1;
    s16 m_Unk9_2;
    /* 0x2C */ s16 m_Unk10_1;
    s16 m_Unk10_2;
    /* 0x30 */ s16 m_Unk11_1;
    s16 m_Unk11_2;
    /* 0x34 */ s32 m_Unk12;
    /* 0x38 */ s32 m_Unk13;
    /* 0x3C */ s32 m_Unk14;
} class_39094_t;

class_39094_vtable_t *func_80048CE0(void);

#endif // LSD_39094_H